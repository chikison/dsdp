// 2_가상함수재정의
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// #1. 가상함수 재정의시 virtual 은 있어도 되고 없어도 됩니다.
//		    void foo() {}  // 이 코드는 아래 와 동일
//	virtual void foo() {}


	// #2. 가상함수 재정의시 실수(오타)가 있어도.
	// => 에러가 아닙니다.
	// => 새로운 가상함수를 만든것으로 생각..
	// => 이런 현상이 버그의 원인이 되었습니다.
//	virtual void fooo() {}
//	virtual void goo(double){}

	// #3. 위 문제를 해결하기 위해서 C++11 부터 override 키워드 제공
	// => 컴파일러에게 새로운 함수가 아니라 override 하는 것이라고
	//    알리는 것
	virtual void fooo()      override {}
	virtual void goo(double) override {}
};

int main()
{
}





