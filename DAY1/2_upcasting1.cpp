// 7 page

class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;

	Dog* p1 = &d;	// ok
	
//	int* p2 = &d;	// error
	
	// 핵심 #1. 기반 클래스 포인터로 파생 클래스 객체의 주소를 담을수 
	//          있습니다.
	// => upcasting 이라고 합니다.
	// => 메모리 그림을 생각해 보면 됩니다
	Animal* p3 = &d;// ok


	// 핵심 #2. Animal* 인 p3 로는 Dog 의 고유멤버에는 접근할수 없다.
	// => 이유는 컴파일러가 p3가 가리키는 곳이 Dog 라는 것을 알수없다.
	// => 아래 코드와 같은 것이 있다면 실행시간에 변경될수 있으므로
	 
	// if (사용자 입력 == 1) p3 = new Animal;

	// 컴파일러는 컴파일 시간에 p3가 가리키는 곳을 알수 없다는 것이 핵심
	p3->age   = 10; // ok
//	p3->color = 10; // error



	// 핵심#3. Animal* 인 p3로 Dog 고유멤버에 접근하려면
	//         캐스팅 해야 합니다.(개발자가 알려주는 의도)
	static_cast<Dog*>(p3)->color = 10;
			// 단, 이경우 p3가 가리키는 곳이 Dog 객체가 아니면
			// 미정의 동작 발생!!
			// 반드시, Dog 일때만 사용해야 합니다.

}











