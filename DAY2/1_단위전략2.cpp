#include <cstdlib> // malloc/free

// github.com/codenuri/day2.zip
// 
// vector 의 동작 방식은 변하지 않습니다.
// vector 가 사용하는 메모리 할당 방식을 교체 가능해야 합니다.

// 방법 #1. template method 사용
// => 변하는 것을 가상함수로
// => 메모리 할당 방식을 변경할수 있어야 하므로
// => 메모리 할당/해지 함수를 가상함수로!   

// 특징 : MallocVector 가 "메모리 할당 방식을 소유" 하게 된다
//       List, Set, Map 등도 메모리 할당 방식을 변경하려면
//       파생 클래스를 만들어서 "메모리 할당 방식을 다시 작성" 해야 한다.

// 메모리 할당 방식을 공유 할수 없을까?





template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
public:
	vector(int sz) : size(sz)
	{
		buff = allocate(size);
	}
	~vector()
	{
		deallocate(buff, size);
	}

	// vector의 모든 멤버함수에서 메모리 할당/해지가 필요하면
	// 아래 가상함수 사용
	virtual T* allocate(int sz)           { return new T[sz]; }
	virtual void deallocate(T* p, int sz) { delete[] p; }
};
//----------------------------------
// 메모리 할당/해지 방법을 변경하려면 파생 클래스를 만들어서
// 약속된 가상함수를 override 하면 됩니다.
template<typename T> class MallocVector : public vector<T>
{
public:
	MallocVector( int sz ) : vector<T>(sz) {}

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
//	vector<int> v(4);
	MallocVector<int> v(4);
}

