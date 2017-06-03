/*******************************************************************************************
파 일 명: main1.h
목    적: 모든 .cpp 에 필요한 모든 함수, 상수, 변수, 구조체 정의 및 .h 선언 종함
사용방식: Header Files 내부에 위치
제한사항: 없음
********************************************************************************************/

#pragma once

/*헤더*/
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
#include "Background.h"
#include "Mercury.h"
#include "Venus.h"
#include "Uranus.h"
#include "Naptune.h"
#include "Saturn.h"
#include "Sphere.h" 
#include "Earth.h"
#include "Mars.h"
#include "Jupiter.h"
#include "Disk.h" 
#include "Satellite.h" 
#include "Group.h"
#include <stdio.h>
/*
구조체 및 지역변수 선언
뷰포트, 현재 화면의 사각형의 크기 손온
*/
struct viewPort { GLsizei w; GLsizei h; } Vp = { 700, 700 };

/*카메라 구조체, 카메라의 위치, 보는 지점, 윗방향을 정의
upX, upY, upZ 는 업벡터이며 어느 방향이 위쪽인가를 정의*/
struct viewCamera {
	GLdouble eyeX, eyeY, eyeZ;
	GLdouble lookX, lookY, lookZ;
	GLdouble upX, upY, upZ;
}
initial = { 350, 350, 350, 0, 0, 0, 0, 1, 0 },
front = { 0, 0, 550, 0,0,0, 0,1,0 },
topView = { 0, 450, 0, 0,0,0, 1,0,1 },
lateral = { 550, 0, 0, 0,0,0, 0,1,0 };

/* 투영할 공간을 정의
 zNear - 공간의 시작지점
 zFar  - 공간의 끝지점
 others- 공간의 상하좌우 크기를 설정*/
struct viewVolume {
	GLdouble xRight, xLeft;
	GLdouble yTop, yBot;
	GLdouble zNear, zFar;
} Pj = { 350, -350, 350,-350, 1, 5000 };

/* 외계 행성 좌표 구조체 정의*/
typedef struct randomStar
{
	float x;
	float y;
	float z;
}RandomStar;
RandomStar star[1000];

GLdouble scale = 1;

/* 날짜 출력과 관련된 변수들*/
int year = 1982;
int month = 3;
double date = 69;
int leapyearArr[14] = {0, 0,31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};			//윤년일때 월별 일수 누적
int normalyearArr[14] = { 0, 0,31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};		//윤년이 아닐때 월별 일수 누적

bool orbit = false;
bool ortho = false;
bool automatic = false;
bool Presskey[9] = { 0, };
int bpx, bpy;

bool leftButton = false;                                                 //마우스 왼쪽 버튼이 눌려진 경우에 true

/*현재 시점 좌표 구조체*/
viewCamera * currentView = &initial;
GLfloat light_position1[] = { 0, 0, 0, 1.0f };

/*
random 함수 정의

기능 : 화면상의 좌표를 무작위로 반환하는 함수
인자 : n  = 함수 호출 확인 유무
반환 : -rand()%700
반환 : rand()%700

*/
int random(int n)						
{
	int num = rand();
	if (n == 1)
	{
		if (num % 2 == 1)				
			return -rand() % 700;				//num 숫자가 홀수일경우 -를 붙여 반환
		else
			return rand() % 700;				//num 숫자가 짝수일경우 그대로 반환
	}
}


Mesh plane("f-16.obj", 20);			// 화면에 표시할 개체들을 구조체 형태로 표현
Group root;


/*
행성별 System(Group) 선언
*/
Group sunSystem;
Group backgroundSystem;
Group mercurySystem;
Group venusSystem;
Group earthSystem;
Group marsSystem;
Group jupiterSystem;
Group saturnSystem;
Group uranusSystem;
Group naptuneSystem;

/*
궤도 선언
*/
Disk mercuryOrbit(40, 40.5, 100, 10);
Disk venusOrbit(70, 70.5, 100, 10);
Disk earthOrbit(100, 100.5, 200, 10);
Disk marsOrbit(150, 150.5, 200, 10);
Disk jupiterOrbit(520, 522, 200, 10);
Disk saturnOrbit(950, 952, 200, 10);
Disk ringOfSaturn(30, 45, 200, 10);
Disk uranusOrbit(1920, 1922, 200, 10);
Disk naptuneOrbit(3010, 3012, 200, 10);
Disk moonOrbit(3, 3.2, 60, 1);

/*
행성  선언
*/
Sun* sunRef;
Background* backgroundRef;
Mercury* mercuryRef;
Venus* venusRef;
Earth* earthRef;
Mars* marsRef;
Jupiter* jupiterRef;
Saturn* saturnRef;
Uranus* uranusRef;
Naptune* naptuneRef;

Satellite satellite;
Sphere moon(0.2, 20, 20);

/*
상수 선언
*/
static const unsigned int UP = 0;
static const unsigned int DOWN = 1;
static const unsigned int LEFT = 2;
static const unsigned int RIGHT = 3;
static const unsigned int _IN = 4;
static const unsigned int _OUT = 5;
static const unsigned int CLOCKWISE = 6;
static const unsigned int CCLOCKWISE = 7;

/*
 함수 선언
 */
void updateProjection();
void updateCamera();
void rotate(double &vx, double &vy, double &vz, double ax, double ay, double az, double angle);
void moveCamera(unsigned int direction);
void initScene();
void initGL();
void resize(int wW, int wH);
void idle();
void display();
void SetAngle();
void setCamera(GLdouble x, GLdouble y, GLdouble z);
void rotateCamera(unsigned int direction);
void myMenu(int id);
void mouseFunc(int b1, int b2, int x, int y);
void motionFunc(int x, int y);
void keySpUp(int key, int mX, int mY);
void keyUp(unsigned char key, int mX, int mY);
void keyPres(unsigned char key, int mX, int mY);
void keySp(int key, int mX, int mY);
