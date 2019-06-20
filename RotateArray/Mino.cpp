#include "Mino.h"

#include <stdio.h>


//////////////////////////////////////////////////////////////////////////////
// Public Methods
//////////////////////////////////////////////////////////////////////////////

void Mino::Rotate(Direction direction) {
	// 現在のブロックの状態を一時変数にコピーして退避
	Mino old;
	old.CopyBlocks(this);

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			int oldX = GetOldX(x, y, direction);
			int oldY = GetOldY(x, y, direction);
			Blocks[y][x] = old.Blocks[oldY][oldX];
		}
	}
}

void Mino::Draw() {
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			const char* string = (Blocks[y][x] == 0 ? "■" : "□");
			printf("%s", string);
		}

		printf("\n");
	}
}


//////////////////////////////////////////////////////////////////////////////
// Private Methods
//////////////////////////////////////////////////////////////////////////////

/// <summary>
/// ブロックデータを複製する
/// </summary>
/// <param name="source">コピー元のテトリミノ</param>
void Mino::CopyBlocks(Mino* source) {
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			Blocks[y][x] = source->Blocks[y][x];
		}
	}
}

/// <summary>
/// 回転前のX座標を取得する
/// </summary>
/// <param name="x">回転後のX座標</param>
/// <param name="y">回転後のY座標</param>
/// <param name="direction">回転方向</param>
/// <returns>回転前のX座標</returns>
int Mino::GetOldX(int x, int y, Direction direction) {
	return (direction == Direction::Left ? -y + WIDTH - 1 : y);
}

/// <summary>
/// 回転前のY座標を取得する
/// </summary>
/// <param name="x">回転後のX座標</param>
/// <param name="y">回転後のY座標</param>
/// <param name="direction">回転方向</param>
/// <returns>回転前のY座標</returns>
int Mino::GetOldY(int x, int y, Direction direction) {
	return (direction == Direction::Left ? x : -x + HEIGHT - 1);
}

