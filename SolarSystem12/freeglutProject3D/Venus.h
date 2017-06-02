/*********************************************************************************************
파 일 명 : Venus.h
목    적 : Venus 클래스의 선언
사용방식 : Header Files 내부에 위치
제한사항 : Venus 클래스가 Sphere 클래스를 상속받기 때문에 클래스 내에서 draw 함수 재정의 필요
**********************************************************************************************/

#ifndef VenusH
#define VenusH

#include "Sphere.h"	

/* Sphere 클래스를 상속받는 Venus 클래스 선언 */
class Venus : public Sphere			
{
	/* Venus 클래스의 private 멤버 */
	private: 			
		GLuint textureID;	//텍스처 번호가 저장되는 텍스쳐ID
		void init();		//금성을 그릴 때 필요한 함수들이 정의된 초기화 함수

	/* Venus 클래스의 public 멤버 */
	public:				
		Venus();			//Venus 객체 생성자
		~Venus();			//Venus 객체 생성자
		void draw();		//금성을 화면에 그려주는 함수
};	

#endif

