
#include "Sun.h"
#include "TextureLoader.h"

/* Sphere 클래스를 상속 받는 Sun 클래스 생성자 정의 */
Sun::Sun() : Sphere(30, 45, 45)
{
	init();
}

/* Sphere 클래스를 상속 받는 클래스 소멸자 정의 */
Sun::~Sun() {
	Sphere::~Sphere();
}

/*
draw 함수 정의

기능 : 태양의 재질 속성을 정의하고 태양의 객체를 그리는 프러시저
인자 : void
반환 : void
*/
/*void Sun::draw(){
glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, sunOn);
Sphere::draw();
glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, sunOff);*/

/*
glMaterialfv

GL_FRONT_AND_BACK: 태양의 앞면, 뒷면 모두가 속성의 영향을 받음
GL_EMISSION: 태양은 스스로 발광하는 행성이므로 재질의 속성은 EMISSION
sunOn: EMISSION의 속성 값을 미리 지정한 상수 배열(노란색)의 포인터
sunOff: 태양을 그린 후, EMISSION의 속성 값을 미리 설정한 상수 배열(검은색)의 포인터로 초기화
*/

void Sun::init()
{

	unsigned int width, height;						//너비와 높이 생성
	unsigned char * data = loadBMPRaw("sun.bmp", width, height, false);	//"earth.bmp"파일을 불러온다

	glGenTextures(1, &textureID);						//OpenGL 텍스쳐를 만든다
	glBindTexture(GL_TEXTURE_2D, textureID);				//사용할 텍스쳐 오브젝트. 이후의 텍스쳐는 이 텍스쳐로 수정한다.


															//OpenGL에 이미지 정보를 전달한다.	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


	//좌표 필터링
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);		//어드레싱
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);		//어드레싱
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	//확대 필터링
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 	//축소 필터링
	delete[] data;

}

void Sun::draw()	//화면에 Earth를 그린다
{

	glBindTexture(GL_TEXTURE_2D, textureID);	//사용할 텍스쳐 오브젝트
	gluQuadricTexture(quadric, GL_TRUE);		//이후의 모든 텍스쳐들은 이 텍스쳐를 사용한다.
	Sphere::draw();					//화면에 Sphere를 그린다

}