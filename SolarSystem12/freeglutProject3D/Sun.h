/************************************************************************************
파 일 명 : Sun.h
목    적 : Sun 클래스의 선언
사용방식 : Header Files 내부에 위치
제한사항 : Sun 클래스가 Sphere 클래스를 상속받기 때문에 클래스 내에서 draw 함수 재정의 필요
***********************************************************************************/

#ifndef SunH
#define SunH

#include "Sphere.h"

/* Sphere 클래스를 상속받는 Sun 클래스 선언 */
class Sun : public Sphere				
{
	/* Sun 클래스의 private 멤버 */
	private: 				
		GLuint textureID;	//텍스처 번호가 저장되는 텍스쳐ID
		void init();		//태양을 그릴 때 필요한 함수들이 정의된 초기화 함수

	/* Sun 클래스의 public 멤버 */
	public:				
		Sun();				//Sun 객체 생성자
		~Sun();				//Sun 객체 소멸자
		void draw();		//태양을 화면에 그려주는 함수

};


#endif


