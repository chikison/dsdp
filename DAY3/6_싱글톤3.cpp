﻿#include <iostream>

// 오직 한개의 객체를 "힙" 에 만드는 모델

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* instance;
public:
	static Cursor& get_instance()
	{
		if (instance == nullptr)
			instance = new Cursor;

		return *instance;
	}
};
Cursor* Cursor::instance = nullptr;



int main()
{
	Cursor& c1 = Cursor::get_instance();

}









