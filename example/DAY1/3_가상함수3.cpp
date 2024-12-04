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

	virtual void foo() {}

	virtual void fooo() {}
	virtual void goo(double){}
};

int main()
{
}





