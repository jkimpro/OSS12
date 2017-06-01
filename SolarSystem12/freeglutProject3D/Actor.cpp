/************************************************************************************
파 일 명 : Actor.cpp
작 성 자 : Dan Cristian, Rotaru (https://github.com/RotaruDan/SolarSystem)
목    적 : Actor 클래스의 정의
사용방식 : Source Files 내부에 위치
제한사항 : virtual 키워드를 사용한 draw 함수가 존재
오류처리 : 없음

이력 사항
수  정  자 : Moon, Heeho (heeho9307@naver.com)
수정 날짜 : 28/04/2017
수정 내용 : 저작권 내용 추가, 오픈 소스 라이선스 추가

수  정  자 : Moon, Heeho (heeho9307@naver.com)
수정 날짜 : 03/05/2017
수정 내용 : 모든 함수 정보 추가, 모든 변수 설명 추가
************************************************************************************/

#include "Actor.h"

/* Actor 객체 생성자 정의 */
Actor::Actor()
{
	r = 0.0;                                   //r : 빨간색을 나타내는 값, 0.0으로 초기화 
	g = 0.0;                                   //g : 초록색을 나타내는 값, 0.0으로 초기화
	b = 0.0;                                   //b : 파란색을 나타내는 값, 0.0으로 초기화 
	a = 1.0;                                   //a : 알파값(투명도)를 나타내는 값, 1.0으로 초기화 
	x = 0.0;                                   //x : x축 방향으로 이동할 값, 0.0으로 초기화 
	y = 0.0;                                   //y : y축 방향으로 이동할 값, 0.0으로 초기화 
	z = 0.0;                                   //z : z축 방향으로 이동할 값, 0.0으로 초기화                
	angle = 0;                                 //angle : 회전할 각도를 나타내는 값, 0으로 초기화 
	angleX = 0.0;                              //angleX : 기준축이 x축임을 나타내는 값, 0.0으로 초기화 
	angleY = 0.0;                              //angleY : 기준축이 y축임을 나타내는 값, 0.0으로 초기화 
	angleZ = 0.0;                              //angleZ : 기준축이 z축임을 나타내는 값, 0.0으로 초기화 
}

/* Actor 객체 소멸자 정의 */
Actor::~Actor()
{
	//void
}

/*
getAngle 함수 정의

기능 : 객체 멤버 변수 angle의 값을 반환하는 함수
인자 : void
반환 : GLdouble angle
*/
GLdouble Actor::getAngle()
{
	return angle;
}

/*
getAngleX 함수 정의   //getAngleY, getAngleZ 함수 동일

기능 : 객체 멤버 변수 angleX의 값을 반환하는 함수
인자 : void
반환 : GLdouble angleX
*/
GLdouble Actor::getAngleX()
{
	return angleX;
}

GLdouble Actor::getAngleY()
{
	return angleY;
}

GLdouble Actor::getAngleZ()
{
	return angleZ;
}

/*
getX 함수 정의 //getY, getZ 함수 동일

기능 : 객체 멤버 변수 x값을 반환하는 함수
인자 : void
반환 : GLdouble x
*/
GLdouble Actor::getX()
{
	return x;
}

GLdouble Actor::getY()
{
	return y;
}

GLdouble Actor::getZ()
{
	return z;
}


/*
setAngleVector 함수 정의

기능 : 객체 멤버 변수 angleX, angleY, angleZ에 매개 변수 angX, angY, angZ의 값을 각 각 대입하는 프러시저
인자 : GLdouble angX, GLdouble angY, GLdouble angZ
반환 : void
*/
void Actor::setAngleVector(GLdouble angX, GLdouble angY, GLdouble angZ)
{
	angleX = angX;
	angleY = angY;
	angleZ = angZ;
}

/*
setAngle 함수 정의

기능 : 객체 멤버 변수 angle에 매개 변수 ang의 값을 대입하는 프러시저
인자 : GLint ang
반환 : void
*/
void Actor::setAngle(GLdouble ang)
{
	angle = ang;
}

/*
setColor 함수 정의

기능 : 객체 멤버 변수 r, g, d, a에  매개 변수 r, g, b, a 의 값을 대입하는 함수
인자 : GLfloat r, GLfloat g, GLfloat b, GLfloat a
반환 : void
*/
void Actor::setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	Actor::r = r;
	Actor::g = g;
	Actor::b = b;
	Actor::a = a;
}

/*
setX 함수 정의 (setY, setZ 함수 동일)

기능 : 객체 멤버 변수 x에  매개 변수 x의 값을 대입하는 함수
인자 : GLdouble x
반환 : void
*/
void Actor::setX(GLdouble x)
{
	Actor::x = x;
}

void Actor::setY(GLdouble y) {
	Actor::y = y;
}

void Actor::setZ(GLdouble z)
{
	Actor::z = z;
}

/*
render 함수 정의

기능 : 객체를 그리는데 필요한 정보(각도, 위치, 색)를 가지고 객체를 생성하는 프러시저
인자 : GLdouble z
반환 : void
*/
void Actor::render()
{
	glPushMatrix();                                          //현재 모델뷰 행렬을 행렬 스택에 저장
	if (a == 0)												//Orbit 에 관련된 컬러는 반드시 a 값을 0으로 초기화 시킬 것!!
	{
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
	}
	glColor4f(r, g, b, a);                                   //r : 빨간색, g : 초록색, b : 파란색, a : 알파값(투명도) 값을 사용하여 색을 지정
	glRotated(angle, angleX, angleY, angleZ);    //angleX or angleY or angleZ의 값이 1.0인 축을 기준으로 angle의 값 만큼 회전
	glTranslated(x, y, z);                                  //원점으로 부터 x축은 x만큼, y축은 y만큼, z축은 z만큼 이동  
	draw();                                                     //도형 객체를 화면에 그려주는 함수 
	if( a==0)
	{
		glPopAttrib();
	}
	glPopMatrix();                                           //행렬 스택에 저장된 마지막 모델 뷰 행렬 반환 
}

/*
draw 함수 정의

기능 : 도형 객체를 화면에 그려주는 프러시저
인자 : void
반환 : void

draw 함수는 선언될 때 virtual 키워드가 사용되므로 Actor 클래스를 상속 받는 클래스는 draw 재 정의 필요
*/
void Actor::draw()
{
	//void 
}
