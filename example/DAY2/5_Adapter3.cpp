#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter
// 1. C++ 표준 라이브러리인 STL 에는 이미 list가 있습니다.
// 2. 그런데, stack 이 필요합니다.

int main()
{
	stack<int> s;
	s.push(10);
}
