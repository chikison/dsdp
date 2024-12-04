#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 상속을 사용한 어답터 : list 의 모든 기능을 stack 도 노출하겠다는 것

// 포함을 사용한 어답터 : list 의 모든 기능을 stack 내부적으로만 사용하겠다는것

// 참고 : java 의 stack 이 vector 에서 상속 받아서 만들어졌습니다.
//		 => 잘못된 디자인의 대표적인 예로 알려져 있습니다.
//		 => 그래서 java 는 stack 을 사용하지 말고 deque 를 사용해라 라고 합니다.

template<typename T>
class stack 
{
	std::list<T> c;
public:
	inline void push(const T& e) { c.push_back(e); }
	inline void pop()			 { c.pop_back(); }
	inline T& top()				 { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

//	s.push_front(20); // 이제 이런 멤버 함수는 없다.


}
