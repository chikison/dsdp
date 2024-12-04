#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Stream
{
	virtual void write(const std::string& s) = 0;
	virtual ~Stream() {}
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
		printf("%s 쓰기\n", s.c_str());
	}
};

int main()
{
	// 파일에 쓸때 암호화 하는 기능을 사용자들이 요구 합니다
	// 라이브러리 설계자로서 최선의 방식을 생각해 봅시다.

	// #1. FileStream 클래스에 암호화 하는 기능 추가하자
	// => 요구사항이 있을때 마다 기존 클래스를 계속 수정할수는 없다.!!!
	// => 그리고, FileStream 뿐 아니라, NetworkStream, PipeStream 도 수정되어야한다.

	// #2. FileStream 의 파생 클래스(EncrpytFileStream)를 만들어서 추가 하자.
	// => NetworkStream, PipeStream 모두 파생 클래스 필요
	// => 암호화, 압축 각각 필요 하고, 또 모두 지원하려면 다중 상속도 필요

	// #3. 기반 클래스인 Stream 에 기능 추가
	// => OCP 위반
	// => 기존 코드의 수정


	// #4. Decorator를 사용하면 어떨까요 ??

	FileStream fs("a.txt");
	fs.write("Hello");		

	EncrpytDecorator ed(&fs);
	ed.write("Hello");  // #1. 암호화 기능 수행
						// #2. fs.write(암호화된 데이타) 

	ZipDecorator zd(&ed );
	zd.write("Hello");	// #1. 압축 기능 수행
						// #2. ed.write(압축된 데이타)
}
