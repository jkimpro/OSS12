#ifndef UranusH
#define UranusH

#include "Sphere.h"		//Sphere 헤더파일 포함


class Uranus :

	public Sphere		//Sphere 클래스의 Public 멤버 호출
{

private: 				// Uranus 클래스의 Private 멤버
	GLuint textureID;	//텍스쳐ID를  나타냄
	void init();


public:					//Uranus 클래스의 Public 멤버
	Uranus();			//Uranus 객체 생성자
	~Uranus();			//Uranus 객체 소멸자
	void draw();		//화면에 그려주는 함수

};

#endif
