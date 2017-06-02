/*********************************************************************************************
파 일 명 : Earth.h
목    적 : Earth 클래스의 선언
사용방식 : Header Files 내부에 위치
제한사항 : Earth 클래스가 Sphere 클래스를 상속받기 때문에 클래스 내에서 draw 함수 재정의 필요
**********************************************************************************************/

#ifndef EarthH
#define EarthH

#include "Sphere.h"	

/* Sphere 클래스를 상속받는 Earth 클래스 선언 */
class Earth :public Sphere				
{
	/* Earth 클래스의 private 멤버 */
	private: 			
		GLuint textureID;	//텍스처 번호가 저장되는 텍스쳐ID
		void init();	    //지구를 그릴 때 필요한 함수들이 정의된 초기화 함수

	/* Earth 클래스의 public 멤버 */
	public:			
		Earth();			//Earth 객체 생성자
		~Earth();			//Earth 객체 소멸자
		void draw();		//지구를 화면에 그려주는 함수

};


#endif

