#ifndef MercuryH
#define MercuryH

#include "Sphere.h"	//Sphere 헤더파일 포함

class Mercury :
	public Sphere				//Sphere 클래스의 Public 멤버 호출
{

private: 			// 클래스의 Private 멤버
	GLuint textureID;	//텍스쳐ID를  나타냄
	void init();

public:
	Mercury();
	~Mercury();
	void draw();

};


#endif
