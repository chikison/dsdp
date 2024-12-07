#include <iostream>
#include <vector>
#include <list>

int main()
{
	slist<int>  s = { 1,2,3 };
	vector<int> v = { 1,2,3 };

	// java style iterator 코드
	// => 실행되는 코드 아닙니다. java style 반복자의 이해를 위해서 만든 코드

	// #1. 모든 컨테이너(컬렉션)은 iterator() 멤버 함수가 있어야 한다.
	// => ICollection 이라는 인터페이스로 약속되어 있습니다.
	auto it1 = s.iterator();
	auto it2 = s.iterator();

	
	// #2. 모든 iterator 는 사용법이 같아야 한다.
	// => hasNext(), next() 멤버 함수가 있어야 한다.
	// => IIterator 라는 인터페이스로 약속

	// 참고. java 반복자는 아래 처럼 사용합니다.
	while (it1.hasNext())
	{
		std::cout << it1.next() << std::endl;
	}

	while (it2.hasNext())
	{
		std::cout << it2.next() << std::endl;
	}
}
