/*
#define MAKE_SINGLETON(classname)			\
private:									\
	classname() {}							\
	classname(const classname&) = delete;	\
	classname& operator=(const classname&) = delete;	\
public:									\
	static classname& get_instance()	\
	{									\
		static classname instance;		\
		return instance;				\
	}
*/
#include "helper.h" // 이 헤더에 위 코드가 이미 있습니다.

class Cursor
{
	MAKE_SINGLETON(Cursor)
};

int main()
{
	Cursor& c = Cursor::get_instance();
}