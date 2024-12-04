#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// 모든 Stream 의 사용법을 약속하기 위한 인터페이스
struct Stream
{
	virtual void write(const std::string& s) = 0;
	virtual ~Stream() { }

	// 이 외에 read(), flush(), open() 등의 함수를 약속
};

class FileStream : public Stream 
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void write(const std::string& s) 
	{
		printf("%s 쓰기\n", s.c_str() );
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("Hello");		// 파일에 쓰기
	
	// 아래 같은 클래스도 있다고 가정해 봅시다.
	NetworkStream ns("127.0.0.1", 4000);
	ns.write("Hello");

	PipeStream ps("named pipe");
	ps.write("Hello");
}
