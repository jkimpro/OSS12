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


/* Earth 헤더파일 */

#ifndef EarthH
#define EarthH

#include "Sphere.h"	//Sphere 헤더파일 포함


class Earth :
	
	 public Sphere				//Sphere 클래스의 Public 멤버 호출
	 {

		private: 			// Earth 클래스의 Private 멤버
			GLuint textureID;	//텍스쳐ID를  나타냄
			void init();	

		public:				//Earth 클래스의 Public 멤버
			Earth();		//Earth 객체 생성자
			~Earth();		//Earth 객체 소멸자
			void draw();		//화면에 그려주는 함수

	 };


#endif
