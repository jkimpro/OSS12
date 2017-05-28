#ifndef NaptuneH
#define NaptuneH

#include "Sphere.h"	//Sphere 헤더파일 포함


class Naptune :

	public Sphere				//Sphere 클래스의 Public 멤버 호출
{

private: 				// Naptune 클래스의 Private 멤버
	GLuint textureID;	//텍스쳐ID를  나타냄
	void init();


public:				//Naptune 클래스의 Public 멤버
	Naptune();			//Naptune 객체 생성자
	~Naptune();		//Naptune 객체 소멸자
	void draw();		//화면에 그려주는 함수

};


#endif
