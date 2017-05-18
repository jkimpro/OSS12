/*
---------------------------------------------------------------------------
 Copied from Dan Cristia, Rotaru
 https://github.com/RotaruDan/SolarSystem
---------------------------------------------------------------------------
 OpenSource Software Project (https://github.com/okjcd123/OSS12)
 Digital Contents 김준혁 문희호 이상협 정지혜
 Date of preparation (작성일):					2017년 5월 12일
 Date of final modification (최종 수정일):			2017년 5월 16일
*/


//---------------------------------------------------------------------------

#include "Axis.h"	//헤더파일 선언


	//X Y Z축 그리기
	Axis::Axis()	//Axis  객체 생성자
	{

	}

	Axis::~Axis()	//Axis 객체 소멸자
	{

	}

	void Axis::draw()	//X Y Z축(선) 그리기
	{
		glBegin( GL_LINES );
		glVertex3f(0, 0, 0);      // origin
		glVertex3f(200, 0, 0);    // X좌표
 
		glVertex3f(0, 0, 0);      // center
		glVertex3f(0, 200, 0);	  // Y좌표

		glVertex3f(0, 0, 0);      // origin
		glVertex3f(0, 0, 200);	  // Z좌표   
		glEnd();
	}


