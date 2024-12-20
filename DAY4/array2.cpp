#include <stdio.h>

int main()
{
	int x[3] = { 1,2,3 };

	// 배열의 주소와 배열의 1번째 요소의 주소
	// x    : 배열, 타입은 int[3]
	// x[0] : 배열의 1번째 요소, 타입 int

	int(*p1)[3] = &x;	

	int* p2 = &x[0];

	// p1, p2 는 결국 같은 주소 입니다.
	// => 그런데, 타입이 다르므로 연산의 결과가 달라 집니다.
	printf("%p, %p\n", p1, p1 + 1); // 12 바이트 증가(int[3] 만큼 증가)
	printf("%p, %p\n", p2, p2 + 1); // 4바이트(int 크기 만큼 증가)

	
	*p2 = 0; // *(int*) => int = 0.  ok. 

//	*p1 = 0; // *(배열*) => 배열 = 0 error

	(*p1)[0] = 0; // *(배열*)[0] => 배열[0] = 0; ok


	// 결론 1차배열에 대해서
	// 배열의 1번째 요소의 주소를 알면 
	p2[0] = 0; // 이렇게 사용가능. x 대신 p1 사용 가능

	// 배열 자체의주소를 사용하면
	p1[0][0] = 0; //마치 2차 배열 처럼 사용하게 됩니다.

	// 따라서, 1차 배열을 포인터로 접근할때는
	// => 배열의 주소가 아닌, 배열의 1번째 요소의 주소를구하는것이
	//   편리합니다.
}