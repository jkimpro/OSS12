
#include "Sun.h"
        
        /* Sphere 클래스를 상속 받는 Sun 클래스 생성자 정의 */
	Sun::Sun() : Sphere() 
        {
		//void
	}
        
        /* Sphere 클래스를 상속 받는 클래스 소멸자 정의 */
	Sun::~Sun(){
		Sphere::~Sphere();
	}
        
        /* 
	draw 함수 정의
	
	기능 : 태양의 재질 속성을 정의하고 태양의 객체를 그리는 프러시저
	인자 : void
	반환 : void 
	*/ 
	void Sun::draw(){		
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, sunOn);
		Sphere::draw();
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, sunOff);

	 /* 
	 glMaterialfv

         GL_FRONT_AND_BACK: 태양의 앞면, 뒷면 모두가 속성의 영향을 받음
         GL_EMISSION: 태양은 스스로 발광하는 행성이므로 재질의 속성은 EMISSION
         sunOn: EMISSION의 속성 값을 미리 지정한 상수 배열(노란색)의 포인터
         sunOff: 태양을 그린 후, EMISSION의 속성 값을 미리 설정한 상수 배열(검은색)의 포인터로 초기화
         */
	}
