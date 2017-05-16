#ifndef SunH
#define SunH

#include "Sphere.h"

const GLfloat sunOn[]  = {1.0, 0.75, 0.0};  //노란색,{빨강1.0, 초록0.75, 파랑0.0}
const GLfloat sunOff[] = {0.0, 0.0, 0.0};   //검은색,{빨강0.0, 초록0.0, 파랑0.0} 

/* SunOn[] : 태양 객체의 재질 색상 상태를 노란색으로 설정하는 상수 배열 */
/* SunOff[] : 태양 객체의의 재질 색상 상태를 검은색으로 설정하는 상수 배열 */

/* Sphere 클래스를 상속받는 Sun 클래스 */
class Sun : public Sphere
{
        /* Sun 클래스의 public 멤버 */
	public:
		Sun();               //Sun 객체 생성자
		~Sun();              //Sun 객체 소멸자
		void draw();         //도형 객체를 화면에 그려주는 함수
};

#endif
