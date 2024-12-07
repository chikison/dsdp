#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};


// C++ 관점
// => 반복자가 지켜야 하는 규칙을 "인터페이스로 약속" 하지말고 
// => "Raw Pointer 과 동일한 방법" 으로 하자.

template<typename T>
class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr) : current(p) {}

	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}

	inline T& operator*()
	{
		return current->data;
	}

	// 반복자를 raw pointer 처럼 사용하려면 == 와 != 연산이 되어야 합니다.
	inline bool operator==(const slist_iterator& other)
	{
		return current == other.current;
	}

	inline bool operator!=(const slist_iterator& other)
	{
		return current != other.current;
	}
};







// 반복자를 꺼내는 멤버 함수를 "begin" 이라는 이름으로 약속(문서)하자.
template<typename T> struct slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	// 함수이름만 약속되었고, 반환 타입을 자유롭게 할수 있으므로
	// 자신의 반복자 타입을 정확히 사용가능. new 만들 필요 없다.
	slist_iterator<T> begin()
	{
		slist_iterator<T> it(head);
		return it;
	}

	slist_iterator<T> end()
	{
		slist_iterator<T> it( nullptr );
		return it;
	}
};


int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	// C++ STL 의 전형적인 반복자를 사용하는 코드
	auto first = s.begin();
	auto last = s.end();

	while (first != last)
	{
		std::cout << *first << std::endl;
		++first;
	}
}

