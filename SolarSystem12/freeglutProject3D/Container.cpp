/***************************************************************************************************
파 일 명 : Container.cpp
목    적 : Container 클래스 정의
사용방식 : Source Files 내부에 위치
***************************************************************************************************/

#include "Container.h"
#include<iostream>


/* Container 객체 생성자 정의 */
Container::Container()
{
	setAngle(-90);
	setAngleVector(1, 0, 0);
}

/* Container 객체 소멸자 정의 */
Container::~Container()
{
	//void
}

/*
drawChildren 함수 정의

기능 : children vector 안에 있는 모든 Actor 객체들을 화면에 그려주는 프로시저
인자 : void
반환 : void
*/
void Container::drawChildren()
{
	unsigned int i;                                            //i : for문에서 사용되는 정수형 변수
	unsigned int size = children.size();                       //size : children vector의 크기(객체의 갯수)

	for (i = 0; i < size; ++i)
	{
		try                                                     //vector 범위 벗어나게 되면 예외를 날림 
		{
			children.at(i);                                     //i번째가 vector 범위 벗어 났는지 검사 
		}
		catch (exception &e)
		{
			cout << "drawChildren 함수의 vector 범위 벗어남" << endl;
		}
		Actor* child = children[i];                            //Actor 포인터 변수 child 선언 후에 children vector의 i번째 원소 대입
		(*child).render();                                     //child에 저장된 Actor 객체를 render 함수를 사용하여 객체 생성
	}
}

/*
addChildren 함수 정의

기능 : children vector에 Actor 객체를 추가 하는 프러시저
인자 : Actor* actor
반환 : void
*/
void Container::addChildren(Actor* actor)
{
	children.push_back(actor);                                   // Actor 객체를 children 백터에 추가

																 /* push_back 함수는 표준 라이브러리에서 지원하는 std::vector의 멤버 함수 vector의 끝에 요소를 추가할 때 사용 */
}


/*
draw 함수 정의

기능 : drawChildren 함수를 호출 하는 프러시저
인자 : void
반환 : void
*/
void Container::draw()
{
	drawChildren();
}


