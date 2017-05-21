/*
---------------------------------------------------------------------------
 Copied from Dan Cristia, Rotaru
 https://github.com/RotaruDan/SolarSystem
---------------------------------------------------------------------------
 OpenSource Software Project (https://github.com/okjcd123/OSS12)
 Digital Contents 김준혁 문희호 이상협 정지혜
 Date of preparation (작성일):					2017년 5월 12일
 Date of final modification (최종 수정일):			2017년 5월 16일
*/

#include "Earth.h"
#include "TextureLoader.h"


	Earth::Earth()		//Earth의 생성자
	: Sphere(30, 45, 45)	//Sphere(구)의 중심 좌표 설정
	
		{

		  init();

		}

	Earth::~Earth()			//Earth의 소멸자
		{

		Sphere::~Sphere();

		}



	void Earth::init()
		{	

		unsigned int width, height;						//너비와 높이 생성
		unsigned char * data = loadBMPRaw("earth.bmp", width, height, false);	//"earth.bmp"파일을 불러온다

		glGenTextures(1, &textureID);						//OpenGL 텍스쳐를 만든다
		glBindTexture(GL_TEXTURE_2D, textureID);				//사용할 텍스쳐 오브젝트. 이후의 텍스쳐는 이 텍스쳐로 수정한다.

	
		//OpenGL에 이미지 정보를 전달한다.	
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
		glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


		//좌표 필터링
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);		//어드레싱
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);		//어드레싱
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	//확대 필터링
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 	//축소 필터링
		delete[] data;
	
		}


	void Earth::draw()	//화면에 Earth를 그린다
		{		

		glBindTexture(GL_TEXTURE_2D, textureID);	//사용할 텍스쳐 오브젝트
		gluQuadricTexture(quadric, GL_TRUE);		//이후의 모든 텍스쳐들은 이 텍스쳐를 사용한다.
		Sphere::draw();					//화면에 Sphere를 그린다

		}

