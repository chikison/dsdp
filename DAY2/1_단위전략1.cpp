﻿// 42 page ~ 
// C++ 표준라이브러리(STL) 의 vector 를 만드는 것을 생각해 봅시다.
template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
public:
	vector(int sz) : size(sz)
	{
		buff = new T[size];
		//....
	}
	~vector()
	{
		delete[] buff;
		//....
	}
};

int main()
{
	vector<int> v(4);
}

// vector 를 만들때 위 코드 처럼 만들면
// vector 의 사용자가 "메모리 할당 방식을 변경할수 없게 됩니다."
// => 사용자가 메모리 할당 방식을 변경할수 있게 하려면 어떻게 하는 것이 좋을까요 ?



