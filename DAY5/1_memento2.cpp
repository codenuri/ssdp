// 8_메멘토 - 178
#include <iostream>
#include <vector>
#include <map>

class Graphics
{
	int penWidth = 1;
	int penColor = 0;
	int temporary_data;

	// #1. 저장할데이타만 별도의 구조체로 설계
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
		penWidth = memento_map[key]->penWidth;
		penColor = memento_map[key]->penColor;
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

	int token = g.Save(); // 메멘토(memento) 패턴
						  // 객체가 자신의 상태를 스스로 저장했다가
						  // 복구할수 있게 한다.
						  // 캡슐화를 위배 하지 않고 객체의 저장/복구
						  // (외부에서 멤버 데이타 접근하지 않는다는 것)

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// 처음에 그렸던 선과 동일하게 그리고 싶다.
	g.Restore(token);  // 이전에 저장했던 상태로 복구
}


// Undo 기능을 만들때 사용 가능한 패턴

// command 패턴 : 동작의 취소
//				  execute() 해서 수행한 작업을
//				  undo() 에서 취소 방법 제공

// memento 패턴 : 상태를 보관..
//				  객체의 크기가 크다면 메모리 사용량 많아 질수 있다.






