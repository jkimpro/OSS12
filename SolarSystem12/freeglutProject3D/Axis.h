/*********************************************************************************************
파 일 명 : Axis.h
목    적 : Axis 클래스의 선언
사용방식 : Header Files 내부에 위치
제한사항 : Axis 클래스가 Actor 클래스를 상속받기 때문에 클래스 내에서 draw 함수 재정의 필요
**********************************************************************************************/

#ifndef AxisH
#define AxisH

#include "Actor.h"	

/* Actor 클래스를 상속받는 Axis 클래스 선언 */
class Axis:public Actor	
{
	/* Axis 클래스의 public 멤버 */
	public:
		Axis();				//Axis 객체 생성자
		~Axis();			//Axis 객체 소멸자
		void draw();		//축을 화면에 그려주는 함수

};

#endif

