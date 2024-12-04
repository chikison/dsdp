#include <cstdlib>
#include <memory> // std::allocator 가 여기에 있습니다.

// 방법 #3. 단위전략 디자인(Policy Base Design)

// 변하는 것(메모리 할당 방식) 을 다른 클래스로 분리!!

// 어떻게 교체 가능하게 할것인가 ?
// strategy : 인터페이스를 만들어서 교체 가능하게 하자.
//			  Edit/IValidator 예제
//			  대부분의 객체지향 언어가 사용
//			  => 디자인 패턴 23개중 한개

// policy base design : template 인자로 교체 가능하게 하자.
//			  C++ 진영에서만 사용되는 디자인 기술
//			=> C++ IDioms 에 있는 용어. 디자인 패턴 아님.



// 디자인 패턴 : 대부분에 객체지향 언어에 적용 가능한 기술, 23개

// IDioms : 언어의 특징을 고려한 디자인 기술
//          C++ IDioms, Java Idioms, C# IDioms 등... 
// 구글에서 "C++ IDioms" 검색, 1번째 링크




// std::allocator<T> : C++ 표준에 이미 있는 메모리 할당기
//					   내부적으로 new, delete 사용
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	T* buff = nullptr;
	int size;

//	MallocAllocator<T> ax; // 이렇게 하면 강한 결합이므로 교체 안됨

	Alloc ax; // 템플릿 인자로 전달된 타입 사용

public:
	vector(int sz ) : size(sz)
	{
		buff = ax.allocate(sz);
	}
	~vector()
	{
		ax.deallocate(buff, size);
	}
};

template<typename T> class MallocAllocator 
{
public:
	inline T* allocate(int sz)
	{
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}
	inline void deallocate(T* p, int sz)
	{
		free(p);
	}
};

int main()
{
//	vector<int, MallocAllocator<int>> v(4); 
	vector<int> v(4); // 표준 할당기 사용
}


