/*******************************************************************************************
파 일 명 : Satellite.h
목    적 : Satellite 클래스의 선언부
사용방식 : Header Files 내부 Objects에 위치
제한사항 :	Satellite 클래스가 Actor 클래스를 상속받기 때문에 클래스 내에서 draw 함수 선언 필요
********************************************************************************************/

#ifndef satelliteH
#define satelliteH

#include "Actor.h"

/* Actor 클래스를 상속받는 Satellite 클래스 선언 */
class Satellite : public Actor 
{
	/* Satellite 클래스의 private 멤버 */
	private:
		GLdouble scale;                       //크기 : 인공위성의 높이의 반을 나타냄

	/* Satellite 클래스의 public 멤버 */
	public:
		Satellite();                           //Satellite 객체 생성자
		Satellite(GLdouble scale);             //매개 변수 scale의 값을 인자로 하는 Satellite 생성자
		~Satellite();                          //Satellite 객체 소멸자
		void draw();                          //객체를 화면에 그려주는 함수
		void drawTriangle();                  //삼각형 도형 그려주는 함수
		void drawPiramid();                   //사각뿔 도형 그려주는 함수
		void drawSquare();                    //사각형 도형 그려주는 함수
};

#endif
