/************************************************************************************
파 일 명 : Sun.cpp
목    적 : Sun 클래스의 정의
사용방식 : Source Files 내부에 위치
제한사항 : Sun 클래스가 Sphere 클래스를 상속받기 때문에 클래스 내에서 draw 함수 재정의 필요
***********************************************************************************/

#include "Sun.h"
#include "TextureLoader.h"

/* Sphere 클래스를 상속 받는 Sun 클래스 생성자 정의 */
Sun::Sun() : Sphere(30, 45, 45) //구의 중심 좌표 설정
{
	init();
}

/* Sphere 클래스를 상속 받는 Sun 클래스 소멸자 정의 */
Sun::~Sun() {
	Sphere::~Sphere();
}

/*
init 함수 정의

기능 : 태양 이미지를 구에 매핑해주기 위한 초기화 함수
인자 : void
반환 : void
*/
void Sun::init()
{
	unsigned int width, height;						                        //너비와 높이 생성
	unsigned char * data = loadBMPRaw("Sun.bmp", width, height, false);		//"Sun.bmp" 파일을 불러옴

	//OpenGL 텍스처 이름 생성
	glGenTextures(1, &textureID);

	//생성한 텍스처 ID 연결
	glBindTexture(GL_TEXTURE_2D, textureID);

	//이미지를 텍스처로 선언
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);

	//텍스처 적용 방식 설정 
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);        //texture와 shading 혼합 방식 설정
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);		//Wrapping Mode 설정
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);		//Wrapping Mode 설정
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	//확대 필터링 설정 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 	//축소 필터링 설정 

	delete[] data; //동적 할당 해제

}

/*
draw 함수 정의

기능 : 태양 이미지가 매핑된 구를 그려주는 프러시저
인자 : void
반환 : void
*/
void Sun::draw()
{
	//생성한 텍스처 ID 연결
	glBindTexture(GL_TEXTURE_2D, textureID);
	//현재 텍스처를 이후의 모든 텍스처에 적용
	gluQuadricTexture(quadric, GL_TRUE);
	//화면에 태양을 그린다
	Sphere::draw();
}





