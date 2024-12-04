// 42 page ~ 
// C++ 에는 다양한 메모리 할당 방법이 있습니다.
// => new, malloc, calloc, system call, pooling...

// vector 를 만들때 아래 처럼 만들면
// vector 의 사용자가 메모리 할당 방식을 변경할수 없게 됩니다.
// => 사용자가 메모리 할당 방식을 변경할수 있게 하려면 어떻게 하는 것이 좋을까요 ?
template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
public:
	vector(int sz) : size(sz)
	{
		buff = new T[size];			
	}
	~vector()
	{
		delete[] buff;
	}
};

int main()
{

}
