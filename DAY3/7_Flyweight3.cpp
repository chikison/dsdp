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

	friend class ImageFactory;	// 이 클래스에서는
								// Image 의 private 접근 가능
};



// Image : 그림을 다운로드후 그리는 기능만 가지게 하고
// ImageFactory : Image  객체의 생성과 공유를 담당

class ImageFactory
{
	std::map<std::string, Image*> image_map;
public:
	Image* create(const std::string& url)
	{
		Image* img = nullptr;

		auto it = image_map.find(url);

		if (it == image_map.end())
		{
			img = new Image(url);
			image_map[url] = img;
		}
		else
			img = it->second;
		return img;
	}

};


int main()
{
	// 공장은 한개만 만들게 하는것이 좋을때가 있습니다.
	// => 싱글톤 패턴 사용. (내일 많이 나옵니다.)
	ImageFactory factory;

	Image* img1 = factory.create("www.naver.com/a.png");
	img1->draw();

	Image* img2 = factory.create("www.naver.com/a.png");
	img2->draw();

}



