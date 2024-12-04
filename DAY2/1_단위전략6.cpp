#include <string>
#include <iostream>

/*
// C++ 표준의 문자열 클래스는 아래와 같습니다.
template<typename T,  // char, wchar_t, char16 등의 문자열 종류(유니코드 고려)
		 typename Traits = std::char_traits<T>, // 비교 정책
		 typename Alloc = std::allocator<T>>    //  메모리 할당
class basic_string
{
	T* buff;
	Alloc ax; // 메모리 할당이 필요할때 ax 사용

public:
	// 문자열 비교
	bool operator==(const std::basic_string& other)
	{
		return Traits::compare(buff, other.buff); 
	}

};
using string = std::basic_string<char>;
*/

// 문자열 비교 정책을 담은 클래스
// C++표준문서에 있는 요구 조건대로 만들어야 합니다.
// (cppreference.com 에서 string 검색)

struct MyTraits : public std::char_traits<char>
{
    static char to_upper(char ch)
    {
        return std::toupper((unsigned char)ch);
    }

    static bool eq(char c1, char c2)
    {
        return to_upper(c1) == to_upper(c2);
    }

    static bool lt(char c1, char c2)
    {
        return to_upper(c1) < to_upper(c2);
    }

    static int compare(const char* s1, const char* s2, std::size_t n)
    {
        while (n-- != 0)
        {
            if (to_upper(*s1) < to_upper(*s2))
                return -1;
            if (to_upper(*s1) > to_upper(*s2))
                return 1;
            ++s1;
            ++s2;
        }
        return 0;
    }

    static const char* find(const char* s, std::size_t n, char a)
    {
        const auto ua{ to_upper(a) };
        while (n-- != 0)
        {
            if (to_upper(*s) == ua)
                return s;
            s++;
        }
        return nullptr;
    }
};

// 문자열 비교정책을 변경하는 코드
using ci_string = std::basic_string<char, MyTraits>;

int main()
{
//  std::string s1 = "ABCD";
//  std::string s2 = "abcd";

	ci_string s1 = "ABCD";
	ci_string s2 = "abcd";

	// 결과 예측해 보세요

	if (s1 == s2)
		std::cout << "same\n";
	else 
		std::cout << "not same\n";
}