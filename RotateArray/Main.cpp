#include "Mino.h"

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main() {
	Mino mino;

	while (true)
	{
		system("cls");
		printf("l:左回転、r:右回転、その他のキー:終了\n");
		mino.Draw();

		Mino::Direction direction;
		switch (_getch())
		{
		case 'r':
			direction = Mino::Direction::Right;
			break;
		case 'l':
			direction = Mino::Direction::Left;
			break;
		default:
			return -1;
		}

		mino.Rotate(direction);
	}
}
