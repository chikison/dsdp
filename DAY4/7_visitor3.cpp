#include <iostream>
#include <list>
#include <vector>


template<typename T>
class MyList : public std::list<T>
{
public:
	using std::list<T>::list; 

//	void accept(TwiceVisitor<T>* visitor) // 한가지 종류의 방문자만 받을수 있습니다 강한결합
//	void accept(IVisitor<T>* visitor)	  // IVisitor<T> 를 구현한 모든 방문자 받습니다. 약한결합
	template<typename V>
	void accept(V visitor)	// 모든 타입 가능
	{
		for (auto& e : *this)  
		{						
			visitor(e); // 단, visitor 는 () 연산가능해야 합니다.
		}
	}
};

void Zero(int& e) { e = 0; }

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	
	// 모든 요소에 적용할 연산을 람다표현식으로 만들어서
	// accept 에 보내세요
	// 람다표현식은 () 연산됩니다.

	// 아래 스타일이 Java 에 있습니다.(accept 가 아닌 ForEach)
	s.accept([](int& e) { e *= 2; }); // s.accept( e => e *= 2)
	s.accept([](int e) { std::cout << e << std::endl; });

	s.accept(Zero);
}






