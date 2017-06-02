/*********************************************************************************************
파 일 명 : Mesh.h
목    적 : Mesh 클래스의 선언
사용방식 : Header Files 내부에 위치
제한사항 : Mesh 클래스가 Actor 클래스를 상속받기 때문에 클래스 내에서 draw 함수 재정의 필요
**********************************************************************************************/

#ifndef MeshH
#define MeshH

#include "Actor.h"	
#include "glm.h"

/* Actor 클래스를 상속받는 Mesh 클래스 선언 */
class Mesh : public Actor			
{
	/* Mesh 클래스의 private 멤버 */
	private:			
		GLMmodel* model;	        //Obj 파일에서 모델을 불러와 저장하는 변수

	/* Mesh 클래스의 public 멤버 */
	public:						
		Mesh(char* filename);					//매개 변수 filename을 인자로 하는 Mesh 객체 생성자
		Mesh(char* filename, GLfloat scale);	//매개 변수 filename, scale 을 인자로 하는 Mesh 객체 생성자
		~Mesh();		           				//Mesh 객체 소멸자 
		void draw();							//모델 객체를 그려주는 함수
};

#endif

