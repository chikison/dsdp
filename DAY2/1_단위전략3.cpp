#include <cstdlib>
// 방법 #2. strategy 패턴 적용
// => 변하는 것(메모리 할당/해지 방법)을 별도의 클래스로 설계하자.

// 특징 : vector 코드와 메모리 할당 방법이 완전히 분리되어있다.
//       메모리 할당 방법을 담은 "메모리 할당기" 클래스를
//		 다른 컨테이너 (list, set, map등)에서도 사용가능하다.

// 단점 : 메모리 할당/해지를 가상함수를 사용하게 된다.
//        가상함수는 약간의 오버헤드가 있다.
//        빠르게 할수 없을까 ???



// 교체해야 하므로 인터페이스를 먼저 설계

template<typename T>
struct IAllocator
{
	virtual T* allocate(int sz) = 0;
	virtual void deallocate(T* p, int sz) = 0;
	virtual ~IAllocator() {}
};



template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
	IAllocator<T>* alloc = nullptr;

public:
	// 이제 vector 의 모든 멤버 함수에서는
	// 메모리 할당이 필요할때 마다
	// "allocator(메모리 할당기)" 객체에 의존해야 합니다.
	vector(int sz, IAllocator<T>* p) : size(sz), alloc(p)
	{
		buff = alloc->allocate(sz);
	}
	~vector()
	{
		alloc->deallocate(buff, size);
	}
};

// 이제 다양한 방식의 "메모리 할당기" 클래스를 제공하면 됩니다.
// => IAllocator<T> 인터페이스를 구현해서 만들면 됩니다.
template<typename T> class MallocAllocator : public IAllocator<T>
{
public:
	virtual T* allocate(int sz)
	{
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}
	virtual void deallocate(T* p, int sz)
	{
		free(p);
	}
};

int main()
{
	MallocAllocator<int> ax;
	vector<int> v(4, &ax); // ax 를 사용해서 메모리 관리해 달라.
}


