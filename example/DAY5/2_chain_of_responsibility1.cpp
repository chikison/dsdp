#include <iostream>

class Handler
{
	Handler* next = nullptr;
public:
	Handler* set_next(Handler* h)
	{
		next = h;
		return next;
	}
	void handle(int problem)
	{
		if (resolve(problem) == true)
			return;

		if (next != 0)
			next->handle(problem);
	}

	virtual bool resolve(int problem) = 0;
};

int main()
{
}
