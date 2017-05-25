/*******************************************************************************************
 파 일 명: Sphere.cpp
 목    적: Sphere 클래스 정의
 사용방식: Sphere Files 내부의 Objects에 위치
 제한사항: Sphere 클래스가 Actor 클래스를 상속받기 때문에 클래스 내에서 draw 함수 재정의 필요
********************************************************************************************/

#include "Sphere.h"

 	/* Sphere 객체 생성자 정의*/
	Sphere::Sphere()
   	{
		radius = 45.0;                 //멤버 변수 radius의 값, 45.0으로 초기화
		slices = 60;                   //멤버 변수 slices의 값, 60으로 초기화
		stacks = 60;                   //멤버 변수 stacks의 값, 60으로 초기화
		init();                        //초기화 함수 호출
	}

	/* 매개 변수 radius, slices, stacks의 값을 인자로 하는 Sphere 객체 생성자 정의*/
	Sphere::Sphere(GLdouble radius, GLint slices, GLint stacks)
 	{
		Sphere::radius = radius;       //매개 밴수 radius 값을 멤버 변수 radius에 대입
		Sphere::slices = slices;       //매개 변수 slices 값을 멤버 변수 slices에 대입
		Sphere::stacks = stacks;       //매개 변수 stacks 값을 멤버 변수 stacks에 대입
		init();                        //초기화 함수 호출
	}
	
	/*
	init 함수 정의

	기능 : 이차 곡면 객체를 생성하고 객체의 속성을 설정하는 함수
	인자 : void
	반환 : void 
	*/
	void Sphere::init()
	{		
	    quadric=gluNewQuadric();                          //새로운 이차곡면 객체 생성
	    gluQuadricDrawStyle(quadric, GLU_FILL);           //GLU_FILL : 객체의 내부를 채움
	    gluQuadricOrientation (quadric, GLU_OUTSIDE);     //GLU_OUTSIDE : 법선 벡터가 바깥쪽을 향하게 함
	    gluQuadricNormals(quadric, GLU_SMOOTH);           //GLU_FLAT : 면이 깎인 것 처럼 보이게 하는 법선 벡터 지정
	}

	/* Sphere 클래스 소멸자 정의 */
	Sphere::~Sphere()
	{
		//gluDeleteQuadric(quadric);                    //이차곡면 객체 삭제
	}
		
	/*
	draw 함수 정의
	
	기능 : 이차 곡면 객체, 반지름, 슬라이스, 스택의 값을 가지고 구를 화면에 그리는 프로시저
	인자 : void
	반환 : void
	*/

	void Sphere::draw()
	{
		gluSphere(quadric, radius, slices, stacks);   //구를 그리는 OpenGL 라이브러리 함수
	}

