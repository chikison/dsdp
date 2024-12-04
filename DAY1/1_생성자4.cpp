// protected 생성자의 의도 : 자신의 객체를 생성할수 없지만 (추상적 존재)
//							파생 클래스 객체는 생성할수 있게(구체적 존재)
//							하겠다는 의도

class Animal
{
//public:		// A, B 모두 에러 아님
//private:		// A, B 모두 에러
protected:
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {}	// Dog() : Animal() {}
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
	Animal a;	// A	Error
	Dog    d;	// B	OK
}



