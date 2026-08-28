// 8_메멘토 - 178
#include <iostream>
#include <vector>
#include <map>

class Graphics
{
	int penWidth = 1;
	int penColor = 0;
	int temporary_data;

	// 저장될 데이타만 나타내는 타입
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
		++key;

		Memento* m = new Memento(penWidth, penColor);
		memento_map[key] = m;
		return key;
	}

	void Restore(int key)
	{
		auto it = memento_map.find(key);
		
		if (it != memento_map.end())
		{
			penWidth = it->second->penWidth;
			penColor = it->second->penColor;
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

	// memento1.cpp 의 "방법 #2" 를 사용하는 코드

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200); 

	int token = g.Save(); // 현재 설정값을 "내부에 저장"해 놓고
						  // 복구할 때 사용할 토큰을 반환
						  // g의 상태값을 외부에서 꺼내서 보관하지 않고(정보은닉보장)
						  // => 자신이 스스로 보관하는 것


	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// 처음에 그렸던 선과 동일하게 그리고 싶다.
	// 방법 #1. 아래 처럼 다시 세팅하자
	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	
	// 방법 #2. memento 패턴을 사용하자
	g.Restore(token);	// token 발행 시점의 상태로 복구
}

// Memento 패턴
// => 캡슐화를 위배하지 않고
// => 객체의 상태를 스스로 저장 했다가 복구할수 있게 한다


// Undo/Redo 를 만들때 사용할수 있는 패턴

// Command : 일반적으로 "동작의 취소" 를 구현
// Memento : 상태의 저장을 통한 "undo" 구현

// 2개를 모두 사용해서 구현도 가능
// Command 패턴의 "undo" 함수 안에서
// Memento 의 Restore() 를 호출해서 구현하기도 함





