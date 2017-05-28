/*******************************************************************************************
파 일 명 : Satellite.cpp
목    적 : Satellite 클래스의 정의
사용방식 : Source Files 내부의 Objects에 위치
제한사항 : Satellite 클래스가 Actor 클래스를 상속받기 때문에 클래스 내에서 draw 함수 재정의 필요
********************************************************************************************/

#include "Satellite.h"

	/* Satellite 객체 생성자 정의 */
	Satellite::Satellite()
	{
		scale = 20;                               //멤버 변수 scale의 값 20으로 초기화 
	}
	
	/* 매개 변수 scale의 값을 인자로 하는 Satellite 생성자 */
	Satellite::Satellite(GLdouble scale)
	{
		Satellite::scale = scale;                  //매개 변수 scale의 값을 멤버 변수 scale에 대입
	}

	/* Satellite 클래스 소멸자 정의 */
	Satellite::~Satellite()
	{
		//void
	}

	/* 
	draw 함수 정의

	기능 : 정육면체 중심 몸체에 양쪽으로 태양 열 반사판이 위치한 형태의 인공위성 그리기
	인자 : void
	반환 : void
	*/
	void Satellite::draw()
	{
		glColor3f(0.0, 0.29, 0.29);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glScalef(0.5, 0.5, 0.5);
		glutSolidCube(10.0);                               //큐브 모양의 정육면체

		glColor3f(0.0, 0.5, 0.5);
		glScalef(3.0, 0.1, 0.1);
		glutSolidCube(10.0);
		glScalef(1 / 3.0, 1 / 0.1, 1 / 0.1);              //긴 막대 모양으로 변형

		glColor3f(0.4, 0.9, 0.9);                         //태양 반사판 그리기
		glPushMatrix();
		glTranslatef(23.0, 0.0, 0.0);
		glRotatef(40, 1.0, 0.0, 0.0);
		glScalef(1.8, 1.0, 0.05);
		glutSolidCube(10.0);
		glPopMatrix();                                    //납작한 직육면체 객체 한쪽으로 이동

		glTranslatef(-23.0, 0.0, 0.0);                    //태양 반사판 그리기
		glRotatef(40, 1.0, 0.0, 0.0);
		glScalef(1.8, 1.0, 0.05);
		glutSolidCube(10.0);                              //납작한 직육면체 객체 한쪽으로 이동
	}
	

