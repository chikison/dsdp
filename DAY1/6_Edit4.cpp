// 변하는 것을 분리하는 2가지 기술

// Edit2.cpp
// => 변하는 것을 가상함수로
// => template method
// => 상속을 사용하는 패턴
// 
// 중요 특징 : NumEdit 가 Edit 기능과 Validation 정책을
//            모두 포함하게 된다.(정책의 소유자)




// Edit3.cpp
// => 변하는 것을 다른 클래스로
// => strategy 패턴

// 특징 :  Edit 기능과 Validation 정책이 완전히 분리되어있다.
// => LimitDigitValidator 는 다른 입력도구에서도 사용가능하다.

// => 실행시간 validation 정책 변경도 가능
//    e.set_validator(&v1);
//    e.set_validator(&v2);

// 단점 : Validator 에서 Edit 멤버 데이타 접근 안됩니다.
//        그래서 validate()함수로 인자로 필요한 데이타 전달

// Edit 예제는 edit2 보다 edit3이 좋습니다.
//====================
// 그런데, 도형편집기를 생각해 봅시다.
// => template method 패턴의 전형적인 모양
// => 사각형을 어떻게 그릴지는 실행 시간 변경 필요 없고,
//    다른 클래스에서 사용될 필요도 없습니다.
//    또한, draw_imp() 가 멤버함수이므로 멤버 데이타 접근도 가능

// 그래서 이경우는 변하는 것을 "가상함수로 분리" 하는것이 좋습니다.
class Shape
{
public:
	void draw() 
	{
		draw_imp();
	} 
	virtual void draw_imp() {}
};
class Rect : public Shape
{
	virtual void draw_imp() {}
};

// C++ GUI 라이브러리중 QT, MFC 라는 것이 있습니다

// MFC 의 CEdit 클래스 - Edit2.cpp 처럼 되어 있습다.
// QT  의 QEdit 클래스 - Edit3.cpp  