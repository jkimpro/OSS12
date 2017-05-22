/********************************************************************************************
	파 일 명 : Group.h
	목    적 : Group 클래스의 선언부
	사용방식 : Header Files 내부에 위치
	제한사항 : Group 클래스가 Actor 클래스를 상속받기 때문에 클래스 내에서 draw 함수 선언 필요
*********************************************************************************************/

#include "Actor.h"
#include "vector"

#ifndef GroupH
#define GroupH

using namespace std;

/* Actor 클래스를 상속 받는 Group 클래스 */
class Group : public Actor                                
{                               
	/* Group 클래스의 private 멤버 */
	private:
		vector<Actor*> children;                           //children : Actor 객체들을 자유롭게 추가하거나 삭제할 수 있는 벡터

		/* vector는 표준 라이브러리에서 지원하는 std::vector의 멤버 변수
		   크기 변경 불가능한 배열 대신 사용 */
		void drawChildren();                               //children 벡터 안에 있는 모든 Actor 객체들을 화면에 그리는 함수 

	/* Group 클래스의 public 멤버 */
	public:
		Group();                                           //Group 객체 생성자
		~Group();                                          //Group 객체 소멸자
	
		void addChildren(Actor* actor);                    //children 벡터에 Actor 객체를 추가하는 함수
		void draw();	                                   //도형 객체를 화면에 그려주는 함수

};

#endif
