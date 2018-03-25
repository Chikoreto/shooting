#include"Collision.h"
#include"ComonConstant.h"

std::vector<int> Collision::collisionPlayerEnemy(Vector2D player, std::vector<Vector2D> enemy)
{
	//クリアする
	res.clear();

	for (Vector2D &ene : enemy)
	{
		if (player.distanceFrom(ene) <= (32))
		{

			res.push_back(1);
		}
		else
		{
			res.push_back(0);
		}
	}

	return res;
}

//ショットと敵の当たり判定
std::vector<int> Collision::collisionShotEnemy(Vector2D shot, std::vector<Vector2D> enemy)
{
	//クリアする
	res2.clear();

	for (Vector2D &ene : enemy)
	{
		if (shot.distanceFrom(ene) <= (32))
		{

			res2.push_back(1);
		}
		else
		{
			res2.push_back(0);
		}
	}

	return res2;
}
