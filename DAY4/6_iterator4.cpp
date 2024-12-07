#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// 모든 반복자가 지켜야 하는 규칙 설계
// 반복자의 인터페이스
template<typename T> struct IIterator
{
	virtual bool hasNext() = 0;
	virtual T& next() = 0;

	virtual ~IIterator() {}
};

// 모든 컬렉션(컨테이너)가 지켜야 하는 규칙
template<typename T> struct ICollection
{
	virtual IIterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};

//------------------------------------------------
// 싱글리스트 반복자
template<typename T> 
class slist_iterator : public IIterator<T>
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr)
		: current(p) {}

	T& next() override
	{
		T& tmp = current->data;
		current = current->next;
		return tmp;
	}
	bool hasNext() override
	{
		return current != nullptr;
	}
};










// 모든 컬렉션에서는 iterator 를 꺼낼수 있어야 한다.
template<typename T> struct slist : public ICollection<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }




	IIterator<T>* iterator() override
	{
		return new slist_iterator<T>(head); // 1번재 노드로 초기화된 반복자
	}
};




int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	IIterator<int>* it = s.iterator();

	while (it->hasNext())
	{
		std::cout << it->next() << std::endl;
					// #1. it 가 가리키는 값 반환
					// #2. it 는 다음으로 이동
	}

	delete it;
}

// 위 코드는 전통적인 디자인 패턴에서 사용하는 iterator 구현 입니다.
// => Java, C#, Python, Swift 등 대부분의 언어는 위코드와 유사하게 구현합니다.

// 그런데, C++ 진영에서 이야기 하는 위 코드의 단점

// #1. 반복자를 꺼내는 s.iterator() 가 반환하는 반복자는 "new" 로 만들게 됩니다.
//     => delete 가 필요하지 않을까요 ?

// #2. 요소를 순회 할때 사용하는 next()/hasNext() 가 가상함수 입니다.
//    => 수천 ~ 수만번 호출되는 경우 오버헤드가 상당히 많습니다.

// #3. 배열은 진짜 포인터를 사용해서 모든 요소에 순차적으로 접근합니다.
//    => 진짜 포인터는 next() 함수가 아닌 "++" 로 이동합니다.
//    => "모든 컬렉션"을 동일하게 열거!!! 의 규칙에 위배 됩니다.
//    => 배열도 컬렉션(컨테이너)입니다.