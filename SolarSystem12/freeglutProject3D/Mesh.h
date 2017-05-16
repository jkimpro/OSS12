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



/* Mesh 헤더파일 */

#ifndef MeshH
#define MeshH

#include "Actor.h"	//Actor 헤더파일 포함
#include "glm.h"

class Mesh :

	 public Actor				//Actor 클래스의 Public 멤버 호출
	 {

		private:			//Mesh 클래스의 Private 멤버
			GLMmodel* model;	



		public:						//Mesh 클래스의 Public 멤버
			Mesh(char* filename);			//Mesh 객체 생성자
			Mesh(char* filename, GLfloat scale);	//Mesh파일명과 띄울 Scale을 나타냄
			~Mesh();				//Mesh 객체 소멸자
			void draw();				//도형을 그려주는 함수

	  };


#endif
