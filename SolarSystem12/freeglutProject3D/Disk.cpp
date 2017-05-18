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


#include "Disk.h"

using namespace std;	//std 함수들을 범위 지정 없이 사용가능


	Disk::Disk()	//Disk 객체 생성자 정의
	{
		innerRadius = 128;	//안쪽 반지름 값을 128로 초기화
		outerRadius = 132;	//바깥쪽 반지름 값을 132로 초기화
		slices = 180;		//슬라이스 값을 180로 초기화
		loops = 1;		//루프(스택) 값을 1로 초기화
		init();
	}


	Disk::Disk(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint loops)	//Disk객체에  값을 대입하는 함수
	{
		Disk::innerRadius = innerRadius;	//안쪽 반지름 값 대입
		Disk::outerRadius = outerRadius;	//바깥쪽 반지름 값 대입
		Disk::slices = slices;			//슬라이스 값 대입
		Disk::loops = loops;			//스택 값 대입
		init();
	}


	void Disk::init()	//Quadric 객체로 도형 그리기
	{		
	    quadric = gluNewQuadric();
	    gluQuadricDrawStyle(quadric, GLU_FILL);			//와이어 프레임으로 그리고, 가득 채운다
	    gluQuadricOrientation (quadric, GLU_INSIDE);	//법선벡터를 안쪽방향으로 지정한다
		gluQuadricNormals(quadric, GLU_FLAT);			// 면이 깎인것 처럼 보이도록 법선벡터 생성
	}


	Disk::~Disk()	//Disk 객체 소멸자 정의
	{
		gluDeleteQuadric(quadric);
	}


	void Disk::draw()	//화면에 Disk를 그린다
	{		 
		gluDisk(quadric, innerRadius, outerRadius, slices, loops);
	}


