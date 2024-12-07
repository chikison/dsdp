class Dialog
{
public:
	void close(int code) {}

	static void close2(int code) {}
};

void foo(int a) {}

int main()
{
	void(*f1)(int) = &foo;			 // ok 	
	void(*f2)(int) = &Dialog::close; // error. close 는 멤버 함수이므로
									// this 가 추가되는 함수(thiscall)
									// 인자가 한개가 아니다.

	void(*f3)(int) = &Dialog::close2; // ok. static 멤버함수는
										// this 추가 안됨.

	// #1. 일반 함수 포인터에, 멤버 함수의 주소를 담을수 없습니다.
	// #2. 일반 함수 포인터에, static 멤버 함수의 주소를 담을수 있습니다.
	// => 이유는 this 때문에 
}