/*********************************************************************************************
파 일 명 : Disk.h
목    적 : Disk 클래스의 선언
사용방식 : Header Files 내부에 위치
제한사항 : Disk 클래스가 Actor 클래스를 상속받기 때문에 클래스 내에서 draw 함수 재정의 필요
**********************************************************************************************/

#ifndef DiskH
#define DiskH

#include "Actor.h"	

/* Actor 클래스를 상속받는 Disk 클래스 선언 */
class Disk : public Actor	
{
	/* Disk 클래스의 private 멤버 */
	private:				
		GLUquadric * quadric;		    //이차 곡면 객체(원판)의 주솟값을 저장하는 포인터 변수
		GLdouble innerRadius;           //안쪽 반지름
		GLdouble outerRadius;		    //바깥쪽 반지름
		GLint slices;					//슬라이스: z축 방향으로 나누는 갯수
		GLint loops;					//루프: 동심원 방향으로 나누는 갯수
		void init();				    //원판을 그릴 때 필요한 함수들이 정의된 초기화 함수

	/* Disk 클래스의 public 멤버 */
	public:		
		Disk();					        //Disk 객체 생성자
		~Disk();				        //Disk 객체 소멸자

		//매개 변수 innerRadius, outerRadius, slices, loops의 값을 인자로 하는 Disk 객체 생성자
		Disk(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint loops);	
		void draw();				    //원판을 화면에 그려주는 함수
};



#endif

