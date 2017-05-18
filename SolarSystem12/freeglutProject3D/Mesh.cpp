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



#include "Mesh.h"	//Mesh 헤더파일을 포함

	Mesh::Mesh(char* charname)	//Mesh 생성자
	 {

		model = glmReadOBJ(charname);	//obj 파일을 불러온다

	 }


	Mesh::Mesh(char* charname, GLfloat scale)
	 {

		model = glmReadOBJ(charname);	//OBJ 파일에서 Model의 정보를 불러온다
		glmUnitize(model);		//Model 원형에 맞게 크기 조절
		glmFacetNormals(model);		//Model의 Facet 법선을 생성
		glmScale(model, scale);		//주어진 크기만큼 Model 크기 조절

	 }


	Mesh::~Mesh()		//Mesh 소멸자
	{

		glmDelete(model);	//Model 객체의 구조를 지운다

	}

	void Mesh::draw()	//Mesh를 화면에 그린다
	{

		glmDraw(model, GL_SMOOTH);	//정점 법선을 사용하여 렌더링한다

	}
