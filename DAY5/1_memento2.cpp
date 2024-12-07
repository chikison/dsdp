// 8_메멘토 - 178
#include <iostream>
#include <vector>
#include <map>


class Graphics
{
	int penWidth = 1;
	int penColor = 0;
	int temporary_data;

	// 저장할 필요가 있는 것만 별도의 구조체로 설계
	struct Memento
	{
		int penWidth;
		int penColor;

		Memento(int w, int c) : penWidth(w), penColor(c) {}
	};

	std::map<int, Memento*> memento_map;

public:
	int Save()
	{
		static int key = 0;

		Memento* m = new Memento(penWidth, penColor);

		++key;
		memento_map[key] = m;

		return key;
	}

	void Restore(int key)
	{
		auto it = memento_map.find(key);

		if (it != memento_map.end())
		{
			penColor = it->second->penColor;
			penWidth = it->second->penWidth;
		}
	}


	void DrawLine(int x1, int y1, int x2, int y2)
	{
	}
	void SetStrokeColor(int c) { penColor = c; }
	void SetStrokeWidth(int w) { penWidth = w; }
};


int main()
{
	Graphics g;

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200); 

	int token = g.Save();	// 메멘토(memento) 패턴
							// => 객체가 자신의 상태를 스스로 저장/복구할수 있게한다
							// => 캡슐화를 위배하지 않고(위부에서 꺼낼필요 없이)
							//    객체가 자신을 스스로 저장


	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// 처음에 그렸던 선의 속성과 동일하게 그리고 싶다.
	g.Restore(token); // 복구
}

// Undo 를 할때 사용할수 있는 패턴
// Memento : 상태 저장 방식의 undo, 메모리 사용량 커질수 있다.
// Command : 동작의 취소에 의한 undo, 사용자가 어떻게 undo 할지를 코드로 작성







