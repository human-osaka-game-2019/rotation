/// <summary>
/// テトリミノみたいなもの(Z型のみ)
/// </summary>
class Mino
{
public:
	/// <summary>
	/// 回転方向
	/// </summary>
	enum Direction {
		/// <summary>
		/// 左回転
		/// </summary>
		Left,

		/// <summary>
		/// 右回転
		/// </summary>
		Right
	};

	/// <summary>
	/// 回転
	/// </summary>
	/// <param name="direction">回転方向</param>
	void Rotate(Direction direction);

	/// <summary>
	/// テトリミノを描画する
	/// </summary>
	void Draw();

private:
	/// <summary>
	/// 幅
	/// </summary>
	static const int WIDTH = 5;

	/// <summary>
	/// 高さ
	/// </summary>
	static const int HEIGHT = 5;

	/// <summary>
	/// ブロックの二次元配列
	/// </summary>
	int Blocks[HEIGHT][WIDTH] = {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
	};

	void CopyBlocks(Mino* source);
	int GetOldX(int x, int y, Direction direction);
	int GetOldY(int x, int y, Direction direction);
};
