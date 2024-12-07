// 참고
class Sample
{
	inline static int value = 10;
	using DWORD = int;
};
int p = 0;

template<typename T>
void foo()
{
	// 아래 코드에서 * 의 의미를 생각해 보세요
//	Sample::value* p;		// 곱하기 의미
//	Sample::DWORD* p;		// 포인터 변수의 선언

	// "클래스이름::이름" 에서 "이름" 은
	// 1. 값 일수 있다 : static 멤버 데이타, enum 상수등..
	// 2. 타입일수 있다 : 별명(typedef, using)
	// => 이름의 의미에 따라 * 등의 연산자의 의미가 달라진다.

	// 아래 코드를 컴파일러가 어떻게 해석해야 할까요 ?
	// dependent name : 템플릿 인자 T 에 의존해서 얻는 이름!!
	//				    => 컴파일러가 무조건 값으로 해석
	T::value* p;
//	T::DWORD* p2;	// error. 곱하기로 해석해야 하는데, p2 라는 변수가 없다
	typename T::DWORD* p2; // ok. dependent name 을 값이 아닌
							//    타입으로 해석해 달라.
							//    p2를 포인터 변수의 선언으로 해석
}

int main()
{

}