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
};


int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	// 이렇게 해도 되지만, 반복자 이름은 컨테이너마다 다를수 있습니다.
	// auto 권장
	//slist_iterator<int> it = s.begin(); 

	auto it = s.begin();

	// 이제 it 는 포인터는 아니지만 포인터와 동일한 사용법을 제공합니다.
	++it;

	std::cout << *it << std::endl;
}




// 그런데, STL 방식으로 만든 위 반복자는 

// #1. 반복자를 꺼내는 s.iterator() 가 반환하는 반복자는 "new" 로 만들게 됩니다.
//     => 위 코드는 new 사용안함!!! delete 필요 없음.

// #2. 요소를 순회 할때 사용하는 next()/hasNext() 가 가상함수 입니다.
//    => 위 코드는 ++, * 가 inline 치환 됩니다. 성능저하 없습니다.


// #3. 배열은 진짜 포인터를 사용해서 모든 요소에 순차적으로 접근합니다.
//    => 진짜 포인터는 next() 함수가 아닌 "++" 로 이동합니다.
//    => "모든 컬렉션"을 동일하게 열거!!! 의 규칙에 위배 됩니다.

//	=> 위 반복자는 Raw Pointer 와 동일한 사용법입니다.