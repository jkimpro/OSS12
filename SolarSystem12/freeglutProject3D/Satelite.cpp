/*******************************************************************************************
파 일 명 : Satellite.cpp
목    적 : Satellite 클래스의 정의
사용방식 : Source Files 내부의 Objects에 위치
제한사항 : Satellite 클래스가 Actor 클래스를 상속받기 때문에 클래스 내에서 draw 함수 재정의 필요
********************************************************************************************/

#include "Satelite.h"

	/* Satellite 객체 생성자 정의 */
	Satelite::Satelite()
	{
		scale = 20;                               //멤버 변수 scale의 값 20으로 초기화 
	}
	
	/* 매개 변수 scale의 값을 인자로 하는 Satellite 생성자 */
	Satelite::Satelite(GLdouble scale)
	{
		Satelite::scale = scale;                  //매개 변수 scale의 값을 멤버 변수 scale에 대입
	}

	/* Satellite 클래스 소멸자 정의 */
	Satelite::~Satelite()
	{
		//void
	}

	/* 
	draw 함수 정의

	기능 : 사각뿔 두 개가 꼭짓점을 마주보는 형태이고, 그 사이에 사각형이 존재하는 인공 위성을 그리는 프러시저
	인자 : void
	반환 : void
	*/
	void Satelite::draw()
	{
		//인공 위성의 모든 도형에 기본으로 적용되는 상태 행렬
		glRotated(90, 0, 0, 1);                                       //z축을 기준으로 90도 만큼 회전

		//1번째 사각뿔에 적용할 상태 행렬 설정
		glTranslated(0, -scale, 0);                                   //y축 방향으로 -scale 만큼 이동
		drawPiramid();                                                //첫 번째 사각뿔 형태 객체 생성하기 

		//2번째 사각뿔에 적용할 상태 행렬 설정, 1번째 사각뿔에 적용된 상태 행렬 그대로 유지됨
		glTranslated(0, 2*scale, 0);                                  //y축 방향으로 2*scale 만큼 이동
		glScaled(1, -1, 1);                                           //xz면을 기준으로 대칭
		drawPiramid();                                                //두 번째 사각뿔 형태 객체 생성하기
		
		//사각뿔에만 적용되는 상태 행렬을 없애는 과정
		glScaled(1, -1, 1);                                           //xz면을 기준으로 다시 대칭
		glTranslated(0, -scale, 0);                                   //y축 방향으로 -scale 만큼 이동

		//사각형에만 적용되는 상태 행렬 설정
		glRotated(90, 1,  0,  0);                                     //x축을 기준으로 90도 회전, 사각뿔 사이의 사각형은 x축을 기준으로 90도 회전
		
		//사각형의 크기 조절
		GLdouble quarterScale = scale *.25f;                          //사각형의 scale은 현재 scale의 4분의 1
		glScaled(quarterScale, quarterScale, 0);

		drawSquare();                                                 //두 개의 사각뿔 사이에 존재하는 사각형 그리기
	}
	
	/* 
	drawTriangle 함수 정의

	기능 : 사각뿔의 한 면인 삼각형을 그리는 프로시저
	인자 : void
	반환 : void 
	*/
	void Satelite::drawTriangle()
	{
		glScaled(scale, scale, scale);                         //원점에서 x, y, z축의 방향으로 거리에 각 각 scale 곱해줌, 삼각형의 크기 변경
		glBegin(GL_TRIANGLES);                                 //삼각형을 나타냄
		glNormal3f(1.0, 1.0, 1.0);                             //그려지는 삼각형의 법선 벡터는 원점에서 (1, 1, 1)을 가리키는 벡터

		glColor3f(1.0, 0.0, 0.0);                              //색 상태머신 - 빨간색(빨강 : 1.0. 초록 : 0.0, 파랑 : 0.0)
		glVertex3f(0.5, 0.0, 0.0);                             //첫 번째 정점의 위치
		glColor3f(0.0, 1.0, 0.0);                              //색 상태머신 - 초록색(빨강 : 0.0. 초록 : 1.0, 파랑 : 0.0)
		glVertex3f(0.0, 1.0, 0.0);                             //두 번째 정점의 위치
		glColor3f(0.0, 0.0, 1.0);                              //색 상태머신 - 파란색(빨강 : 0.0. 초록 : 0.0, 파랑 : 1.0)
		glVertex3f(0.0, 0.0, 0.5);                             //세번 째 정점의 위치
		glEnd();

		GLdouble invScale = 1.0/scale;                         //scale의 역수
		glScaled(invScale, invScale, invScale);                //원점에서 x, y, z축의 방향으로 거리에 각 각 1.0/ scale 곱해주면 다시 원래 scale로 복귀
	}

	/* 
	drawPiramid 함수 정의

	기능 : 삼각형을 그리고 회전하는 반복을 통해 사각뿔을 그려주는 프러시저 
	인자 : void
	반환 : void
	*/
	void Satelite::drawPiramid()
	{
		for(int i = 0; i < 4; ++i)                              //for문 4번 반복, 사각뿔 옆면의 갯수는 4개 
		{
			glRotated(90, 0, 1, 0);                             //y축을 기준으로 90도 회전
			drawTriangle();                                     //삼각형을 그려주는 함수 호출
		}
	}

	/*
	drawSquare 함수 정의

	기능 : 사각형을 그려주는 프로시저
	인자 : void
	반환 : void 
	*/
	void Satelite::drawSquare()
	{
		glBegin(GL_QUADS);                                    //사각형을 나타냄
		glNormal3f(0.5, 0.5, 0.5);                            //그려지는 사각형의 법선 벡터는 원점에서 (1, 1, 1)을 가리키는 벡터

		glColor3f(1.0, 0.0, 0.0);                             //색 상태머신 - 빨간색(빨강 : 1.0. 초록 : 0.0, 파랑 : 0.0)
		glVertex3f(1, 1, 0.0);                                //첫 번째 정점의 위치

		glColor3f(0.0, 1.0, 0.0);                             //색 상태머신 - 초록색(빨강 : 0.0. 초록 : 1.0, 파랑 : 0.0)
		glVertex3f(1, -1, 0.0);                               //두번째 정점의 위치

		glColor3f(0.0, 0.0, 1.0);                             //색 상태머신 - 파란색(빨강 : 0.0. 초록 : 0.0, 파랑 : 1.0)
		glVertex3f(-1, -1, 0);                                //세 번째 정점의 위치

		glColor3f(0.0, 0.0, 0.0);                             //색 상태머신 - 검은색(빨강 : 0.0. 초록 : 0.0, 파랑 : 0.0)
		glVertex3f(-1, 1, 0);                                 //네 번째 정점의 위치
		glEnd();
	}
