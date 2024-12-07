// 7_객체생성정리 - 118 page
class Rect
{
};

// 객체를 만드는 방법

// 1. Rect rc;		=> 지역변수, 전역변수
//					=> 수명이 정해져 있다.
//					=> {} 을 벗어나면 파괴


// 2. Rect* rc = new Rect;		=> 가장 자유로운 방법
//								=> 개발자가 원하는 시점에 파괴 가능.
//								=> 하지만 자유로운것이 항상 좋다는 것은 아님

// 개발시에 객체를 생성할때 위 2가지 방법만 생각하지 말고
// 아래 3가지 방법도 고려해 보세요

// 3. Rect* rc = Rect::create()		=> static 멤버 함수 사용
//									=> 다양한 제약을 사용할수 있다.
//				A. 오직 한개만 만들수 있게 => 싱글톤
//				B. 속성이 동일하면 공유    => 플라이 웨이트
//			    C. 생성함수주소를 함수 인자로 전달하거나
//				   자료구조에 보관
//				자바에서는 이 기술을 "static factory method" 라는 이름으로 부릅니다.
//				=> 구글 검색
// 
// 4. Rect* rc = 견본->clone();  : 복사본을 사용한 객체 생성 - Prototype

// 5. Rect* rc = factory.create() : 공장을 통한 객체 생성




Car c = new Car(blue); // 이 코드 보다
Car c = Car.BlueCar(); // 이렇게 하면 가독성이 좋지 않을까 ?
Car c = Car.RedCar(); // 이렇게 하면 가독성이 좋지 않을까 ?


//std::chrono::system_clock c = std::chrono::system_clock::now()

// RUST 의 객체 생성 방법
/*
let s = String::new("hello"); // 여기서 new 는 키워드가 아닙니다.
								// static 멤버 함수 이름 입니다.
								// RUST 의 대부분의  타입은
								// new 라는 static 멤버 함수가 있습니다.
*/