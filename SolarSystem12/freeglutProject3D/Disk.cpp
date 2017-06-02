/*********************************************************************************************
파 일 명 : Disk.cpp
목    적 : Disk 클래스의 정의
사용방식 : Source Files 내부에 위치
제한사항 : Disk 클래스가 Actor 클래스를 상속받기 때문에 클래스 내에서 draw 함수 재정의 필요
**********************************************************************************************/

#include "Disk.h"


/* Disk 클래스 생성자 정의 */
Disk::Disk()	
{
	innerRadius = 128;			//멤버 변수 innerRadius의 값, 128 로 초기화
	outerRadius = 132;			//멤버 변수 outerRadius의 값, 60로 초기화
	slices = 180;				//멤버 변수 slices의 값, 180로 초기화
	loops = 1;					//멤버 변수 loops의 값, 1로 초기화
	init();						//초기화 함수 호출
}

/* 매개 변수 innerRadius, outerRadius, slices, loops를 인자로하는 Disk 클래스 생성자 정의 */
Disk::Disk(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint loops)	
{
	//안쪽 반지름 값 대입
	Disk::innerRadius = innerRadius;	 //매개 밴수 innerRadius의 값을 멤버 변수 innerRadius에 대입
	//바깥쪽 반지름 값 대입
	Disk::outerRadius = outerRadius;	 //매개 밴수 outerRadius의 값을 멤버 변수 outerRadius에 대입
	//슬라이스 값 대입
	Disk::slices = slices;			     //매개 밴수 slices의 값을 멤버 변수 slices에 대입
	//스택 값 대입
	Disk::loops = loops;			     //매개 밴수 loops의 값을 멤버 변수 loops에 대입
	init();                              //초기화 함수 호출
}

/*
init 함수 정의

기능 : 이차 곡면 객체를 생성하고 객체의 속성을 설정하는 함수
인자 : void
반환 : void
*/
void Disk::init()	
{		
	//새로운 이차곡면 객체 생성
	quadric = gluNewQuadric();
	//GLU_FILL : 객체의 내부를 채움
	gluQuadricDrawStyle(quadric, GLU_FILL);	
	//GLU_OUTSIDE : 법선 벡터가 안쪽을 향하게 함
	gluQuadricOrientation (quadric, GLU_INSIDE);
	//GLU_FLAT : 면이 깎인 것 처럼 보이게 하는 법선 벡터 지정
	gluQuadricNormals(quadric, GLU_FLAT);
}

/* Disk 클래스 소멸자 정의 */
Disk::~Disk()	
{
	//이차곡면 객체 삭제
	gluDeleteQuadric(quadric);
}

/*
draw 함수 정의

기능 : 이차 곡면 객체, 안쪽 반지름, 바깥 반지름, 슬라이스, 스택의 값을 가지고 원반을 화면에 그리는 프로시저
인자 : void
반환 : void
*/
void Disk::draw()	
{		 
	//판을 그리는 OpenGL 라이브러리 함수
	gluDisk(quadric, innerRadius, outerRadius, slices, loops); 
}




