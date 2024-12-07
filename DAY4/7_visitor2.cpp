#include <iostream>
#include <list>
#include <vector>

// 모든 방문자 클래스가 지켜야 하는 규칙
template<typename T> struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};


// 방문자(visitor) : 결국 "요소 한개에 대한 연산을 정의 하는 클래스"
template<typename T> class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { e = e * 2; }
};

template<typename T> class ShowVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { std::cout << e << std::endl; }
};



// 모든 컨테이너는 accept 가 있어야 한다.
template<typename T> struct IAcceptor
{
	virtual void accept(IVisitor<T>* v) = 0;
	virtual ~IAcceptor() {}
};

// std::list 를 확장에서 방문자 기능을 제공해 봅시다
template<typename T> 
class MyList : public std::list<T>,	public IAcceptor<T>
{
public:
	// 생성자 상속 문법
	// using 클래스이름::생성자 이름;
	using std::list<T>::list; // list 의 모든 생성자를 
							  // MyList 도 그대로 사용할수 있게 해달라.

	void accept(IVisitor<T>* visitor)
	{
		for (auto& e : *this)  // *this 를 잘생각해보세요
		{						// MyList 는 결국 std::list 로 상속 받으므로
								// *this 는 list 라고 생각하면 됩니다.
			visitor->visit(e);
		}
	}
};

int main()
{
//	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;  
	s.accept(&tv);         

	ShowVisitor<int> sv; 
	s.accept(&sv);

	ZeroVisitor<int> zv;  
	s.accept(&zv);

	s.accept(&sv); // 0, 0,0 ,0 ... 나오게 위 ZeroVisitor 만드세요
}






