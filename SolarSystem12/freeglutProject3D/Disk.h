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



/* AxisH 헤더파일 */

#ifndef DiskH
#define DiskH

#include "Actor.h"	//Actor 헤더파일 포함


class Disk :

	 public Actor	//Actor 클래스의 Public 멤버 호출
	 {


		private:					//Disk 클래스의 Private 멤버
		    GLUquadric * quadric;			
		    GLdouble innerRadius, outerRadius;		//안쪽 반지름 값과 바깥쪽 반지름 값을 나타냄
		    GLint slices, loops;			//슬라이스 값과 루프 값을 나타냄
		    void init();				


		public:						//Disk 클래스의 Public 멤버
			Disk();					//Disk 객체 생성자
			Disk(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint loops);	//안쪽과 바깥쪽 반지름, 슬라이스, 루프 값을 대입하는 함수
			~Disk();				//Disk 객체 소멸자
			void draw();				//화면에 그려주는 함수
	  };



#endif
