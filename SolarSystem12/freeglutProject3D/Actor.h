/********************************************************************************************
파 일 명 : Actor.h
목    적 : Actor 클래스의 선언부
사용방식 : Header Files 내부에 위치
제한사항 : virtual 키워드를 사용한 draw 함수가 존재
*********************************************************************************************/
#ifndef ActorH
#define ActorH

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/glut.h>

class Actor
{
	/* Actor 클래스의 private 멤버 */
	private:
		GLdouble angle;                       //각도: 도형 객체를 회전하는 각도의 크기를 나타냄, 0에서 360까지의 값 
		GLdouble angleX, angleY, angleZ;      //기준축: x, y, z축 중에 어떤 축을 기준으로 객체를 회전하는지 나타냄, 기준축의 값은 1.0이고 나머지는 0.0 
		GLdouble x, y, z;                     //이동거리: 도형 객체를 원점에서 x축 방향으로 x 만큼, y축 방향으로 y만큼, z축 방향으로 z만큼 이동을 나타냄

	/* Actor 클래스의 protected 멤버 */
	protected:
		GLfloat r, g, b, a;                    //색 : 도형 객체의 색 정보를 나타냄, r : 빨간색 g : 초록색 b : 파란색 a : 알파값(투명도), 모든 값이 0.0에서 1.0까지의 값 
	
	/* Actor 클래스의 public 멤버 */
	public:
		Actor();                                //Actor 객체 생성자
		~Actor();                               //Actor 객체 소멸자

		GLdouble getAngle();                    //멤버 변수 angle의 값을 반환하는 함수 
		GLdouble getAngleX();                   //멤버 변수 angleX의 값을 반환해주는 함수 
		GLdouble getAngleY();                   //멤버 변수 angleY의 값을 반환해주는 함수 
		GLdouble getAngleZ();                   //멤버 변수 angleZ의 값을 반환해주는 함수
		GLdouble getX();                        //멤버 변수 x의 값을 반환해주는 함수
		GLdouble getY();                        //멤버 변수 y의 값을 반환해주는 함수
		GLdouble getZ();                        //멤버 변수 z의 값을 반환해주는 함수

		//멤버 변수 angleX, angleY, angleZ에 매개 변수 angX,angY, angX의 값을 각 각 대입하는 함수 
		void setAngleVector(GLdouble angX, GLdouble angY, GLdouble angZ); 	

		//멤버 변수 angle에 매개 변수 ang값을 대입하는 함수
		void setAngle(GLdouble ang); 	

		//멤버 변수 r, g, b, a에  매개 변수 r, g, b, a의 값을 각 각 대입 하는 함수
		void setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a); 	                    

		void setX(GLdouble x);                   //멤버 변수 x에 매개 변수 x의 값을 대입 하는 함수 
		void setY(GLdouble y); 					 //멤버 변수 y에 매개 변수 y의 값을 대입 하는 함수 
		void setZ(GLdouble z); 	                 //멤버 변수 z에 매개 변수 z의 값을 대입 하는 함수 

		void render();                           //Actor클래스의 모든 멤버 변수의 값을 사용하여 도형 객체를 만드는 함수 
		virtual void draw();                     //도형 객체를 화면에 그려주는 함수 

};

#endif

