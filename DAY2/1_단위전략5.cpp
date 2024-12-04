#include <iostream>
#include <vector>

// STL 에 전달하기 위한 사용자 정의 allocator(메모리 할당기) 클래스
// #1. 반드시 템플릿일 필요는 없지만, 다양한 타입의 메모리 할당을 위해서
//     대부분 템플릿으로 작성

// #2. 반드시 약속된 함수를 만들어야 합니다.
//     (cppreference.com 에서 화면 왼쪽에 "Named Requirement" 선택)

template<typename T> class debug_alloc
{
public:
	inline T* allocate(std::size_t sz)
	{
		void* p = malloc(sizeof(T) * sz);

		printf("[debug_alloc] allocate %p, %zd cnts\n", p, sz);
		
		return static_cast<T*>(p);
	}

	inline void deallocate(T* p, std::size_t sz)
	{
		printf("[debug_alloc] deallocate %p, %zd cnts\n", p, sz);

		free(p);
	}

	// 위 2개가 핵심이고, 아래 3개가 더필요합니다. 관례적인 코드
	// 항상 복사해서 사용하면 됩니다.
	using value_type = T;
	debug_alloc() {}
	template<typename U> debug_alloc(const debug_alloc<U>&) {}
							// generic 생성자 개념. 
};


int main()
{
//	std::vector<int> v;			// 이 코드는
//	std::vector<int, std::allocator<int>> v; // 결국 이 코드입니다.

	std::vector<int, debug_alloc<int> > v;

	std::cout << "-----------------" << std::endl;

	v.resize(4);	// 4개 메모리 할당

	std::cout << "-----------------" << std::endl;

	v.resize(8);	// 1. 8개 메모리 할당
					// 2. 4개 버퍼 => 8개 버퍼에 복사
					// 3. 4개 버퍼(메모리)제거

	std::cout << "-----------------" << std::endl;
}
