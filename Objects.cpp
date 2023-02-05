#include "cometstrike.h"

struct comet
{
	Vector2 position;
	unsigned int radius;

	void Draw()
	{
		DrawCircleV(position, (float) radius, RED);
	}
};