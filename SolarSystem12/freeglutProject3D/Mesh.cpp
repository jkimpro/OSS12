/*********************************************************************************************
파 일 명 : Mesh.cpp
목    적 : Mesh 클래스의 정의
사용방식 : Source Files 내부에 위치
제한사항 : Mesh 클래스가 Actor 클래스를 상속받기 때문에 클래스 내에서 draw 함수 재정의 필요
**********************************************************************************************/

#include "Mesh.h"	

/* Mesh 클래스 생성자 정의 */
Mesh::Mesh(char* charname)	
{
	//obj 파일을 불러옴
	model = glmReadOBJ(charname);	
}

/* 매개 변수 charname, scale을 인자로 하는 Mesh 클래스 생성자 정의 */
Mesh::Mesh(char* charname, GLfloat scale)
{
	//OBJ 파일에서 model의 정보를 불러옴
	model = glmReadOBJ(charname);	
	//model 원형에 맞게 크기 조절
	glmUnitize(model);	
	//model의 facet 법선을 생성
	glmFacetNormals(model);		
	//scale 만큼 model 크기 조절
	glmScale(model, scale);		
}

/* Mesh 클래스 소멸자 정의 */
Mesh::~Mesh()		
{
	//model 객체의 구조 지움
	glmDelete(model);	
}

/*
draw 함수 정의

기능 : model 객체를 화면에 그려주는 프로시저
인자 : void
반환 : void
*/
void Mesh::draw()	
{
	//모델 객체를 GL_SMOOTH 옵션 적용하여 렌더링
	glmDraw(model, GL_SMOOTH);	
}

