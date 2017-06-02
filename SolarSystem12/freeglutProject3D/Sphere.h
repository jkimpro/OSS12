/*******************************************************************************************
 파 일 명: Sphere.h
 목    적: Sphere 클래스 선언부
 사용방식: Header Files 내부에 위치
 제한사항: Sphere 클래스가 Actor 클래스를 상속받기 때문에 클래스 내에서 draw 함수 재정의 필요
********************************************************************************************/

#ifndef SphereH
#define SphereH

#include "Actor.h"

/* Actor 클래스를 상속받는 Sphere 클래스 선언 */
class Sphere : public Actor {
 	
	/* Sphere 클래스의 private 멤버 */
	private:
		GLdouble radius;                //반지름: 구의 반지름 길이를 나타냄
		GLint slices;                   //슬라이스: 구를 그릴 때 경도선의 방향으로 구역을 나누는 갯수
		GLint stacks;                   //스택: 구를 그릴 때 위도선의 방향으로 구역을 나누는 갯수 
		void init();                    //구를 그릴 때 필요한 함수들이 정의된 초기화 함수
	
	/* Sphere 클래스의 protected 멤버 */
	protected:	
		GLUquadric * quadric;           //이차 곡면 객체(구)의 주솟값을 저장하는 포인터 변수
	
	/* Sphere 클래스의 public 멤버 */
	public:
		Sphere();                       //Sphere 객체 생성자  
		~Sphere();                      //Sphere 객체 소멸자

		//매개 변수 radius, slices, stacks의 값을 인자로 하는 Sphere 객체 생성자
		Sphere(GLdouble radius, GLint slices, GLint stacks); 

		void draw();                    //도형 객체를 화면에 그려주는 함수
};

#endif


