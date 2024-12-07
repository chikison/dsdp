#include <iostream>
#include <list>
#include <vector>

// visitor 패턴
// 
// 반복자(iterator) : 복합객체의 모든 요소를 동일한 방식으로 열거(순차적 접근)
// 방문자(visitor)  : 복합객체의 모든 요소를 동일한 방식으로 연산수행


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.

	// 방법 #1. for 문 사용
	// 아래 코드는
	// => list 외부(main) 에서 반복자를 꺼낸후에
	// => 반복자를 사용해서 각 요소에 순차적으로 접근해서
	// => 각요소에 주어진 연산을 수행하는 것
	for (auto& e : s)
	{
		e = e * 2;
	}

	// 방법 #2. 방문자 패턴 사용하기
	TwiceVisitor<int> tv;  // 방문하는 요소를 2배로 하는 연산을 가진 방문자
	s.accept(&tv);         // list(복합객체, 아파트)에 방문자가 방문. 

	ShowVisitor<int> sv; // 방문하는 모든 요소를 화면 출력
	s.accept(&sv);

	// accept 는 다양한 방문자를 받을수 있어야 한다.
	// => accept(?) ? 의 타입은 ? 
	// => IVisitor 가 필요 하다.

	// list 뿐 아니라 vector, set 등에도 accept 가 있어야 한다.
	// => 컨테이너의 인터페이스를 만들어서 약속.
}






