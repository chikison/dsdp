#include <iostream>
#include <list>
#include <vector>
#include <deque>

// adapter 패턴과 policy base design 의 결합

template<typename T, typename C = std::deque<T> >
class stack
{
	C c;
public:
	inline void push(const T& e) { c.push_back(e); }
	inline void pop() { c.pop_back(); }
	inline T& top() { return c.back(); }
};
#include <stack> // 이안에 코드가 위와 거의 동일 합니다.
				 // stack adapter 라고 부릅니다.
				 // cppreference.com 에서 Container Library 선택

int main()
{
	std::stack<int, std::list<int>> s3;
	

	stack<int, std::list<int>> s1;  
	stack<int, std::vector<int>> s2; // vector 를 stack 처럼 사용하겠다는
									// 의도. 

	stack<int> s; // 내부 자료구조는 deque
	s.push(10);

}
