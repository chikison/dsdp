// 5_Flyweight - 167
#include <iostream>
#include <string>
#include <map>


class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:

	void draw() { std::cout << "Draw " << image_url << std::endl; }

	// 자신의 객체를 만드는 static 멤버 함수
	static Image* create(const std::string& url)
	{
		Image* img = nullptr;

		auto it = image_map.find(url); // map 에서 먼저 검색

		if (it == image_map.end()) // 없을때
		{
			img = new Image(url);
			image_map[url] = img;
		}
		else
			img = it->second; // map 의 반복자는 pair 인데
							  // second 가 value(Image*) 입니다.
		return img;
	}

	// C++17 inline static 문법
	// => static 멤버 데이타 만들때 외부 선언 없어도 됩니다.
	inline static std::map<std::string, Image*> image_map;
};



int main()
{
	// IOS 용 라이브러리인 Cocoa Touch 라이브러리가 아래 처럼 
	// Image 객체를 생성합니다.
	Image* img1 = Image::create("www.naver.com/a.png");
	img1->draw();

	Image* img2 = Image::create("www.naver.com/a.png");
	img2->draw();

}



