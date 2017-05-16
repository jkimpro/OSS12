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


---------------------------------------------------------------------------

/* AxisH 헤더파일 */

#ifndef AxisH
#define AxisH

#include "Actor.h"	//Actor 헤더파일 포함


class Axis :

	 public Actor	//Actor 클래스의 Public 멤버  호출
	 {

		public:
			Axis();		//Axis 생성자
			~Axis();	//Axis 소멸자
			void draw();	//객체 그리는 함수

	 };

#endif
