#pragma once
#include"Vector2D.h"
#include<vector>


class Collision
{
public:
	std::vector<int> collisionPlayerEnemy(Vector2D player, std::vector<Vector2D> enemy);
	std::vector<int> collisionShotEnemy(Vector2D shot, std::vector<Vector2D> enemy);

private:
	std::vector<int> res,res2;


};