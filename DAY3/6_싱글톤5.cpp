#include <iostream>
#include <mutex>

// RAII 기술
// => Resource Acquision Is (관리객체의) Initialization
// => 자원의 획득은 "관리객체" 의 초기화 과정(생성자)에서 이루어 진다.
// => 자원의 할당/해지 는 반드시 생성자/소멸자에 의존하라는 기술

template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
};

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* instance;
	static std::mutex mtx;
public:
	static Cursor& get_instance()
	{
		std::lock_guard<std::mutex> g(mtx);
//		lock_guard<std::mutex> g(mtx);	// #1. g 의 생성자에서 mtx.lock()
										// #2. g 의 소멸자에서 mtx.unlock()
//		mtx.lock();						// #3. 예외 발생시 지역변수는
										//     안전하게 파괴 됩니다.
										//     소멸자가 호출된다는것(자원반납됨)


			if (instance == nullptr)
				instance = new Cursor;

//		if (...) return;		// #4. 이런 코드가 있어도 g 의 소멸자는 호출
//								//     안전하게 mtx.unlock() 수행.
//		mtx.unlock();

		return *instance;
	}
};
Cursor* Cursor::instance = nullptr;
std::mutex Cursor::mtx;




int main()
{
	Cursor& c1 = Cursor::get_instance();

}


