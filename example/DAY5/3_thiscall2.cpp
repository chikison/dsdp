class Dialog
{
public:
	void close(int code) {}
};

void foo(int a) {}

int main()
{
	void(*f1)(int) = &foo;			 // ok 	
	void(*f1)(int) = &Dialog::close; // ??
}