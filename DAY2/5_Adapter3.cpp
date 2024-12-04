#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter
// 1. C++ 표준 라이브러리인 STL 에는 이미 list가 있습니다.
// 2. 그런데, stack 이 필요합니다. (stack 도 이미 있지만, 없다고 가정해 봅시다.)

// list 의 함수 이름만 변경해서 stack 처럼 보이게 하자.
template<typename T> 
class stack : public std::list<T>
{
public:
	inline void push(const T& e)	{ std::list<T>::push_back(e); }
	inline void pop()				{ std::list<T>::pop_back(); }
	inline T& top()                { return std::list<T>::back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(20); // 사용자가 실수했다.
				      // 스택은 한쪽으로만 입출력되어야 한다.
					  // 해결책은 다음소스에서
}
