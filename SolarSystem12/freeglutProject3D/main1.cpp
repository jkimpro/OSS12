/*
---------------------------------------------------------------------------
 Copied from Dan Cristia, Rotaru
 https://github.com/RotaruDan/SolarSystem
---------------------------------------------------------------------------
 OpenSource Software Project (https://github.com/okjcd123/OSS12)
 Department of Digital Contents
 김준혁 문희호 이상협 정지혜

 Date of preparation (작성일):						2017년 5월 12일
 Date of final modification (최종 수정일):			2017년 5월 16일
*/
//-------------------------------------------------------------------------
// 헤더
//-------------------------------------------------------------------------
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include "Mesh.h"
#include "Sun.h"
#include "Axis.h" 
#include "Sphere.h" 
#include "Earth.h"
#include "Mars.h"
#include "Disk.h" 
#include "Satelite.h" 
#include "Group.h"
#include <stdio.h>

//-------------------------------------------------------------------------
// 구조체 및 지역변수
//-------------------------------------------------------------------------
// 뷰포트, 현재 화면의 사각형의 크기
struct viewPort{GLsizei w; GLsizei h;} Vp = {700, 700};

// 카메라 구조체, 카메라의 위치, 보는 지점, 윗방향을 정의
// upX, upY, upZ 는 업벡터이며 어느 방향이 위쪽인가를 정의
struct viewCamera{GLdouble eyeX, eyeY, eyeZ;
        GLdouble lookX, lookY, lookZ;
        GLdouble upX, upY, upZ;} 
			initial = {350, 350, 350, 0, 0, 0, 0, 1, 0}, 
			front = {0, 0, 550, 0,0,0, 0,1,0},
			topView = {0, 450, 0, 0,0,0, 1,0,1}, 
			lateral = {550, 0, 0, 0,0,0, 0,1,0};

// 투영할 공간을 정의
// zNear - 공간의 시작지점
// zFar  - 공간의 끝지점
// others- 공간의 상하좌우 크기를 설정
struct viewVolume{GLdouble xRight, xLeft;
        GLdouble yTop, yBot;
        GLdouble zNear, zFar;} Pj = {350, -350, 350,-350, 1, 1000};

		typedef struct randomStar
		{
			float x;
			float y;
			float z;
		}RandomStar;

		RandomStar star[8];


GLdouble scale = 1;
bool ortho = false;
int bpx, bpy;
viewCamera * currentView = &initial;
GLfloat light_position1[] = {0, 0, 0, 1.0f};

int random(int n)//맵 범위 좌표를 위한 랜덤함수
{
	int num = rand();
	if (n == 1)
	{
		if (num % 2 == 1) //num 숫자가 홀수일경우 -를 붙이고
			return -rand()%350;
		else
			return rand()%350;
	}
}


// 화면에 표시할 개체들을 구조체 형태로 표현
Mesh plane("f-16.obj", 20);
Group root;
Sun sun;

Group earthSystem;
Group marsSystem;

Earth* earthRef;
Mars* marsRef;

Satelite satelite;
Sphere moon(8, 20, 20);

//-------------------------------------------------------------------------
// 상수
//-------------------------------------------------------------------------
static const unsigned int UP = 0;
static const unsigned int DOWN = 1;
static const unsigned int LEFT = 2;
static const unsigned int RIGHT = 3;
static const unsigned int _IN = 4;
static const unsigned int _OUT = 5;
static const unsigned int CLOCKWISE = 6;
static const unsigned int CCLOCKWISE = 7;
//-------------------------------------------------------------------------
// 함수
//-------------------------------------------------------------------------
void updateProjection();
void updateCamera();
void rotate(double &vx, double &vy, double &vz, double ax, double ay, double az, double angle);
void moveCamera(unsigned int direction);
void initScene();
void initGL();
void resize(int wW, int wH);
void display();
void mouseFunc(int b1, int b2, int x, int y);
void motionFunc(int x,int y);
void keyPres(unsigned char key, int mX, int mY);
void keySp(int key, int mX, int mY);
void setCamera(GLdouble x, GLdouble y, GLdouble z);
void rotateCamera(unsigned int direction);
//---------------------------------------------------------------------------
// programa principal
//-------------------------------------------------------------------------

int main(int argc, char* argv[]){ 
	srand((unsigned)time(NULL));
	// Initialization 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(Vp.w, Vp.h); 
	glutInitWindowPosition(100,100);
	glutInit(&argc,argv);
	// Window construction
	int win=glutCreateWindow("Solar System OSS12");

	//창에 관련된 함수  
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMouseFunc(mouseFunc);
	glutMotionFunc(motionFunc);
	glutKeyboardFunc(keyPres);
	glutSpecialFunc(keySp);
	// OpenGL basic setting
	initGL();

	// X Y Z 축 생성하기
	Axis axis;
	root.addChildren(&axis);
	
	//Solar System Group 생성
	Group solarSystem;
	root.addChildren(&solarSystem);
	solarSystem.setAngleVector(0, 1, 0);			//y축을 기준으로 회전

	sun.setAngleVector(0, 1, 0);
	sun.setColor(1.0, 1.0, 0.0, 1.0);
	solarSystem.addChildren(&sun);

	//지구 궤도 생성
	Disk earthOrbit;
	earthOrbit.setColor(1.0, 1.0, 0.0, 1.0);
	earthOrbit.setAngle(90);					
	earthOrbit.setAngleVector(1, 0, 0);
	solarSystem.addChildren(&earthOrbit);

	// Earth system//
	solarSystem.addChildren(&earthSystem);
	earthSystem.setX(130);
	earthSystem.setAngleVector(0, 1, 0);

	//지구 생성//
	Earth earth;
	earthRef = &earth;
	earth.setColor(1, 1, 1, 1);
	earth.setAngleVector(0, 0, 1);

	/*
	innerRadius = 128;	//안쪽 반지름 값을 128로 초기화
	outerRadius = 132;	//바깥쪽 반지름 값을 132로 초기화
	slices = 180;		//슬라이스 값을 180로 초기화
	loops = 1;		//루프(스택) 값을 1로 초기화
	*/

	//화성 궤도 생성 FIX//
	Disk marsOrbit(80,84,200,1);
	marsOrbit.setColor(1.0, 0.0, 0.0, 1.0);
	marsOrbit.setAngle(90);
	marsOrbit.setAngleVector(1, 0, 0);
	solarSystem.addChildren(&marsOrbit);
	
	// Mars system FIX//
	solarSystem.addChildren(&marsSystem);
	marsSystem.setX(130);
	marsSystem.setAngleVector(0, 1, 0);
	
	//화성 생성 FIX//
	Mars mars;
	marsRef = &mars;
	mars.setColor(1, 1, 1, 1);
	mars.setAngleVector(0, 0, 1);







	// 지구 자전을 위한 earthContainer Group 생성
	Group earthContainer;
	earthContainer.addChildren(&earth);
	earthContainer.setAngle(-90);
	earthContainer.setAngleVector(1, 0, 0);
	earthSystem.addChildren(&earthContainer);

	//달궤도 생성
	Disk moonOrbit(52, 54, 60, 1);
	moonOrbit.setColor(1, 1, 1, 1);
	moonOrbit.setAngle(90);					
	moonOrbit.setAngleVector(1, 0, 0);
	earthSystem.addChildren(&moonOrbit);

	//달 생성
	moon.setColor(1, 1, 1, 1);
	moon.setAngleVector(0, 1, 0);
	moon.setX(53);
	earthSystem.addChildren(&moon);

	//인공위성 궤도 생성
	Disk sateliteOrbit(52, 54, 60, 1);
	sateliteOrbit.setColor(0, 1, 0, 1);
	earthSystem.addChildren(&sateliteOrbit);

	//인공위성 생성
	satelite.setColor(0, 1, 0, 1);
	satelite.setAngleVector(0, 0, 1);
	satelite.setY(53);
	earthSystem.addChildren(&satelite);

	//비행기 궤도 생성
	Disk planeOrbit(52, 54, 60, 1);
	planeOrbit.setColor(0, 1, 1, 1);
	planeOrbit.setAngle(90);
	planeOrbit.setAngleVector(0, 1, 0);
	earthSystem.addChildren(&planeOrbit);

	//비행기 생성
	plane.setColor(0, 1, 1, 1);
	plane.setAngleVector(1, 0, 0);
	plane.setY(53);
	earthSystem.addChildren(&plane);
  
	initScene();				//카메라 시점에 관한 부분 초기화
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION) ;
	glutMainLoop();  //glutMainLoopEvent(); 내장함수에 따라서 진행
	glutDestroyWindow(win);
	return 0;
}
//-------------------------------------------------------------------------

void initGL(){
	for (int i = 0; i < 8; i++)			//태양계 장식 임의 좌표 저장
	{
		star[i].x = random(1);
		star[i].y = random(1);
		star[i].z = random(1);
	}
	//glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);		// z buffer enable
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);   
	glEnable(GL_TEXTURE_2D); 

	GLfloat mat_diffuse[] = {1.0f, 0.0f, 0.0f, 1.0f};
	GLfloat mat_specular[] = {0.0f, 0.0f, 1.0f, 1.0f};
	GLfloat mat_ambient[] = {0.0f, 1.0f, 0.0f, 1.0f};
	GLfloat mat_shininess[] = {100.0f};

	GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat light_ambient[] = {0.0f, 0.0f, 0.0f, 1.0f};
	GLfloat light_position[] = {0, 0, 0, 1.0f};
	
	// enable lighting
	glEnable(GL_LIGHTING);
	// set light property
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);


	// 빛 퐁셰이딩 초기화
	glEnable(GL_LIGHT1);	
	GLfloat light_specular1[] = {0.4f, 0.4f, 0.4f, 1.0f};
	GLfloat light_diffuse1[] = {0.4f, 0.4f, 0.4f, 1.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	

	// 물질 퐁셰이딩 초기화
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);

	glShadeModel(GL_SMOOTH);

	//glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);			//검은색 배경으로 임시 변경

	// 기본적인 카메라 세팅
	updateCamera();
	updateProjection();
}

void initScene(){

	sun.setAngle(0);
	earthSystem.setAngle(0);
	satelite.setAngle(0);
	moon.setAngle(0);
	currentView = &initial;

	initial.eyeX = 350;
	initial.eyeY = 350;
	initial.eyeZ = 350;
	initial.lookX = 0;
	initial.lookY = 0;
	initial.lookZ = 0;
	initial.upX = 0;
	initial.upY = 1;
	initial.upZ = 0;

	front.eyeX = 0;
	front.eyeY = 0;
	front.eyeZ = 550;
	front.lookX = 0;
	front.lookY = 0;
	front.lookZ = 0;
	front.upX = 0;
	front.upY = 1;
	front.upZ = 0;

	topView.eyeX = 0;
	topView.eyeY = 450;
	topView.eyeZ = 0;
	topView.lookX = 0;
	topView.lookY = 0;
	topView.lookZ = 0;
	topView.upX = 1;
	topView.upY = 0;
	topView.upZ = 1;

	lateral.eyeX = 550;
	lateral.eyeY = 0;
	lateral.eyeZ = 0;
	lateral.lookX = 0;
	lateral.lookY = 0;
	lateral.lookZ = 0;
	lateral.upX = 0;
	lateral.upY = 1;
	lateral.upZ = 0;

	updateCamera();
	ortho = false;
	updateProjection();
}

void updateCamera(){
	glMatrixMode(GL_MODELVIEW);   // VIEW
	glLoadIdentity();
	gluLookAt((*currentView).eyeX, (*currentView).eyeY, (*currentView).eyeZ,
		(*currentView).lookX,	(*currentView).lookY,	(*currentView).lookZ, 
		(*currentView).upX, (*currentView).upY, (*currentView).upZ);

}
//-------------------------------------------------------------------------

void resize(int wW, int wH){
	// Viewport set up     
	Vp.w = wW; Vp.h = wH; 

	// Frustum set up
	updateProjection();

	glutPostRedisplay();
}

void updateProjection(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	Pj.xRight = Vp.w/ 2.0 / scale; Pj.xLeft = -Pj.xRight; 
	Pj.yTop = Vp.h/2.0 / scale;  Pj.yBot = -Pj.yTop; 
	if(ortho){
		glOrtho(Pj.xLeft,Pj.xRight, Pj.yBot,Pj.yTop, Pj.zNear, Pj.zFar);
	} else {
		gluPerspective(80, Vp.w / Vp.h, Pj.zNear, Pj.zFar );
	}
}
//-------------------------------------------------------------------------

void display(void) {
	
	light_position1[0] = static_cast<GLfloat>((*currentView).eyeX);
	light_position1[1] = static_cast<GLfloat>((*currentView).eyeY);
	light_position1[2] = static_cast<GLfloat>((*currentView).eyeZ);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
	glMatrixMode(GL_MODELVIEW);
	
	for(int i =0; i<8; i++)			//임의 장식별 출력
	{
		glPushMatrix();
		glTranslatef(star[i].x, star[i].y, star[i].z);
//		printf("%f %f %f \n", star[i].x, 0.0, star[i].z);
		glColor3f(0.5, 0.5, 0.5);
		glutSolidSphere(10.0, 8, 8);
		glPopMatrix();
	}
	glViewport(0,0, Vp.w, Vp.h); 
	root.render();

	glutSwapBuffers(); 
}
//-------------------------------------------------------------------------
// setCamera
// 설명 : 주어진 벡터를 받아 카메라와 카메라 시점을 이동시킴
// 인수 : 3차원 벡터값 x,y,z
// 반환 : void
//-------------------------------------------------------------------------
void setCamera(GLdouble x, GLdouble y, GLdouble z)
{
	GLdouble length = sqrt((x * x) + (y * y) + (z * z));
	x /= length;
	y /= length;
	z /= length;

	// 카메라 위치에 더해줌
	currentView->eyeX += x;
	currentView->eyeY += y;
	currentView->eyeZ += z;

	// 카메라와 카메라가 보는 지점은 평행이동
	currentView->lookX += x;
	currentView->lookY += y;
	currentView->lookZ += z;
}
//-------------------------------------------------------------------------
// moveCamera 
// 설명 : 카메라와 카메라 시점을 옮기는 함수
// 인수 : direction - 카메라가 이동할 방향
// 반환 : void
//-------------------------------------------------------------------------
void moveCamera(unsigned int direction){
	GLdouble eX, eY, eZ;
	GLdouble lX, lY, lZ;
	GLdouble uX, uY, uZ;
	GLdouble vX, vY, vZ;
	GLdouble wX, wY, wZ;
	GLdouble hX, hY, hZ;

	// e 벡터 - 카메라 위치
	eX = currentView->eyeX;
	eY = currentView->eyeY;
	eZ = currentView->eyeZ;

	// l 벡터 - 카메라가 보는 지점
	lX = currentView->lookX;
	lY = currentView->lookY;
	lZ = currentView->lookZ;

	// u 벡터 - e와 l 두 점을 잇는 벡터
	uX = eX - lX;
	uY = eY - lY;
	uZ = eZ - lZ;

	// v 벡터 - 업벡터
	vX = -currentView->upX;
	vY = -currentView->upY;
	vZ = -currentView->upZ;

	// w = u x v
	wX = uY * vZ - uZ * vY;
	wY = uZ * vX - uX * vZ;
	wZ = uX * vY - uY * vX;

	// w = u x v. w 벡터는 윗방향을 가르킴
	hX = uY * wZ - uZ * wY;
	hY = uZ * wX - uX * wZ;
	hZ = uX * wY - uY * wX;

	switch (direction)
	{
	case UP:
		setCamera(hX, hY, hZ);
		break;
	case DOWN:
		setCamera(-hX, -hY, -hZ);
		break;
	case LEFT:
		setCamera(-wX, -wY, -wZ);
		break;
	case RIGHT:
		setCamera(wX, wY, wZ);
		break;
	case _IN:
		setCamera(-uX, -uY, -uZ);
		break;
	case _OUT:
		setCamera(uX, uY, uZ);
		break;
	 default:
		break;
	}
}
//-------------------------------------------------------------------------
// rotateCamera
// 설명 : 시계방향, 또는 시계반대방향을 받아 그에 맞게 카메라를 회전
// 인수 : direction - 카메라를 회전시킬 방향
// 반환 : void
//-------------------------------------------------------------------------
void rotateCamera(unsigned int direction) {
	GLdouble uX = currentView->upX;
	GLdouble uY = currentView->upY;
	GLdouble uZ = currentView->upZ;

	if (direction == CLOCKWISE)
	{
		uX = -uX;
		uY = -uY;
		uZ = -uZ;
	}

	GLdouble length = sqrt((uX*uX) + (uY*uY) + (uZ*uZ));
	uX /= length;
	uY /= length;
	uZ /= length;
	rotate(currentView->eyeX, currentView->eyeY, currentView->eyeZ, uX, uY, uZ, 0.1);
}
//-------------------------------------------------------------------------
// rotateView
// 설명 : 카메라 시점을 방향에 따라 이동시켜줌
// 인수 : direction - 카메라를 회전시킬 방향
// 반환 : void
//-------------------------------------------------------------------------
void rotateView(int x, int y) {
	GLdouble eX, eY, eZ;
	GLdouble lX, lY, lZ;
	GLdouble uX, uY, uZ;
	GLdouble vX, vY, vZ;
	GLdouble wX, wY, wZ;
	GLdouble hX, hY, hZ;

	// e 벡터 - 카메라 위치
	eX = currentView->eyeX;
	eY = currentView->eyeY;
	eZ = currentView->eyeZ;

	// l 벡터 - 카메라가 보는 지점
	lX = currentView->lookX;
	lY = currentView->lookY;
	lZ = currentView->lookZ;

	// u 벡터 - e와 l 두 점을 잇는 벡터
	uX = lX - eX;
	uY = lY - eY;
	uZ = lZ - eZ;

	// v 벡터 - 업벡터
	vX = currentView->upX;
	vY = currentView->upY;
	vZ = currentView->upZ;

	// w = u x v
	wX = uY * vZ - uZ * vY;
	wY = uZ * vX - uX * vZ;
	wZ = uX * vY - uY * vX;

	// h = u x v. w 벡터는 윗방향을 가르킴
	hX = uY * wZ - uZ * wY;
	hY = uZ * wX - uX * wZ;
	hZ = uX * wY - uY * wX;

	GLdouble length = sqrt((wX*wX) + (wY*wY) + (wZ*wZ));
	wX /= length;
	wY /= length;
	wZ /= length;

	length = sqrt((hX*hX) + (hY*hY) + (hZ*hZ));
	hX /= length;
	hY /= length;
	hZ /= length;

	rotate(uX, uY, uZ, hX, hY, hZ, float(x)/-360*3.141592);
	rotate(uX, uY, uZ, wX, wY, wZ, float(y)/360*3.141592);
	currentView->lookX = uX - eX;
	currentView->lookY = uY - eY;
	currentView->lookZ = uZ - eZ;
	updateCamera();
}
//-------------------------------------------------------------------------
// rotate
// 설명 : v 벡터를 a벡터를 축으로 하여 회전
// 인수 : vector v - 회전할 벡터
// 인수 : point a  - 회전 축
// 인수 : angle    - 회전시킬 각도
// 반환 : void
//-------------------------------------------------------------------------
void rotate(double &vx, double &vy, double &vz, double ax, double ay, double az, double angle) {
	double ca = cos(angle);
	double sa = sin(angle);
	double crossx = -vy*az + vz*ay;
	double crossy = -vz*ax + vx*az;
	double crossz = -vx*ay + vy*ax;
	double dot = ax*vx + ay*vy + az*vz;
	double rx = vx*ca + crossx*sa + dot*ax*(1-ca);
	double ry = vy*ca + crossy*sa + dot*ay*(1-ca);
	double rz = vz*ca + crossz*sa + dot*az*(1-ca);
	vx = rx; 
	vy = ry; 
	vz = rz;
}

//-------------------------------------------------------------------------
// keyPres
// 설명 : 키를 이용하여 행동을 결정
// 인수 : key - 입력받은 키값
// 인수 : mX  - 사용안함
// 인수 : mY  - 사용안함
// 반환 : void
//-------------------------------------------------------------------------
void keyPres(unsigned char key, int mX, int mY){
	bool need_redisplay = true;
	if(key == 27) {  /* Esc key */  //continue_in_main_loop = false; (**)
		glutLeaveMainLoop (); //glut 루프를 멈추는 Freeglut함수
	} else if(key == '+') { 
		if(scale < 10.) {
			scale +=0.25; resize(Vp.w, Vp.h);
		} 
	} else if(key == '-') { 
		if(scale > 0.3) {
			scale -=0.25; resize(Vp.w, Vp.h);
		} 
	} else if(key == 'q') { 
		sun.setAngle(sun.getAngle() + 5); 
		earthSystem.setAngle(earthSystem.getAngle() + 4); 
		(*earthRef).setAngle((*earthRef).getAngle() + 6); 
		satelite.setAngle(satelite.getAngle() + 2); 
		plane.setAngle(plane.getAngle() + 1); 
		moon.setAngle(moon.getAngle() + 3); 
	} else if(key == 'i') {
		initScene(); 
	} else if(key == 'x') {
		currentView = &lateral;
		updateCamera();
	} else if(key == 'y') {
		currentView = &front;
		updateCamera();
	} else if(key == 'z') {
		currentView = &topView;
		updateCamera();
	} else if(key == 'p') {
		ortho = !ortho;
		updateProjection();
	} else if(key == 'm') {
		scale += 0.05;
		updateProjection();
	} else if(key == 'M') {
		scale -= 0.05;
		updateProjection();
	} else if(key == 'w') {
		moveCamera(_IN);
		updateCamera();
	} else if(key == 's') {
		moveCamera(_OUT);
		updateCamera();
	} else if(key == 'd') {
		moveCamera(RIGHT);
		updateCamera();
	} else if(key == 'a') {
		moveCamera(LEFT);
		updateCamera();
	} else if(key == 'v') {
		moveCamera(UP);
		updateCamera();
	} else if(key == 'V') {
		moveCamera(DOWN);
		updateCamera();
	} else if(key == 'r') {
		rotateCamera(CLOCKWISE);
		updateCamera();
	} else if(key == 'R') {
		rotateCamera(CCLOCKWISE);
		updateCamera();
	} else {		
		need_redisplay = false;
	}

	// 현재창의 업데이트가 필요할 경우 다시 디스플레이
	if (need_redisplay) { 
		glutPostRedisplay();
	}
}
//-------------------------------------------------------------------------
// keySp
// 설명 : 화살표 키를 이용하여 행동을 결정
// 인수 : key - 입력받은 키값
// 인수 : mX  - 사용안함
// 인수 : mY  - 사용안함
// 반환 : void
//-------------------------------------------------------------------------
void keySp(int key, int mX, int mY){
  bool need_redisplay = true;
  if(key == GLUT_KEY_UP) glRotatef(5.0, 1.0,0.0,0.0);   
  else if (key == GLUT_KEY_DOWN) glRotatef(-5.0, 1.0,0.0,0.0);  
  else if (key == GLUT_KEY_RIGHT) glTranslatef(5.0, 0.0,0.0); 
  else if(key == GLUT_KEY_LEFT) glTranslatef(-5.0, 0.0,0.0); 
  else need_redisplay = false;

  // 현재창의 업데이트가 필요할 경우 다시 디스플레이
  if (need_redisplay) glutPostRedisplay();
}
void mouseFunc(int button1, int button2,int x, int y)
{
	bpx = x;
	bpy = y;
}
void motionFunc(int x, int y)
{
	int bx = bpx - x;
	int by = bpy - y;
	bpx = x;
	bpy = y;
	rotateView(bx, by);
	printf("%d  %d\n", bx,by);
	
	glutPostRedisplay();
}
//-------------------------------------------------------------------------
