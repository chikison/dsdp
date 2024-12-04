#include <iostream>
#include <mutex>

// CRTP
// => Curiously Recurring Template Pattern
// => 신기하게도 언급될수 있는 템플릿 패턴
// => 기반 클래스 만들때 미래에 만들어질 파생 클래스 이름을 사용할수 있게
//    하는 기법 ( C++ IDioms )

template<typename T>
class Singleton
{
protected:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static T* instance;
	static std::mutex mtx;
public:
	static T& get_instance()
	{
		std::lock_guard<std::mutex> g(mtx);

		if (instance == nullptr)
			instance = new T;

		return *instance;
	}
};

template<typename T> T* Singleton<T>::instance = nullptr;
template<typename T> std::mutex Singleton<T>::mtx;

// Mouse 도 위처럼 힙에 만드는 싱글톤을 사용하고 싶다.

class Mouse : public Singleton< Mouse  >
{
};

class Keyboard : public Singleton< Keyboard  >
{
};

int main()
{
	Mouse& c1 = Mouse::get_instance();

}

// github.com/aosp-mirror		안드로이드 OS 소스 코드 입니다.
// platform system core         리포지토리 선택

// libutils/include/utils/ Singleton.h 열어 보세요

