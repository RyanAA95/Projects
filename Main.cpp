#include "cometstrike.h"

struct comet
{
	Vector2 position;
	unsigned int radius;

	void Draw()
	{
		DrawCircleV(this->position, (float) this->radius, RED);
	}
};

int main()
{
	unsigned int windowWidth = 800;
	unsigned int windowHeight = 600;
	bool gameStart = false;

	// Create Player comet
	comet* mainComet = new comet;
	mainComet->radius = 50;
	mainComet->position = { (float)windowWidth / 2, (float)windowHeight / 2 };
	
	// Enable VSync, Initialize Window

	InitWindow(windowWidth, windowHeight, "Comet Strike");

	SetWindowState(FLAG_VSYNC_HINT);

	// Font

	Font font = LoadFontEx("Resources Files/gooddog.otf", 96, 0, 0);

	while (!WindowShouldClose())
	{
      	// MENU SECTION

		if (!gameStart && IsKeyDown(KEY_ENTER))
		{
			gameStart = true;
		}

		// FULLSCREEN
		
		if (IsKeyDown(KEY_TAB))
		{
			ToggleFullScreenWindow(GetDisplayWidth(), GetDisplayHeight());
			windowWidth = GetMonitorWidth(GetCurrentMonitor());
			windowHeight = GetMonitorHeight(GetCurrentMonitor());
		}

		// INPUT SECTION

		if (IsKeyDown(KEY_UP) && mainComet->position.y > (0 + mainComet->radius))
		{
			mainComet->position.y -= 200.0f * GetFrameTime();
		}
		if (IsKeyDown(KEY_DOWN) && mainComet->position.y < (windowHeight - mainComet->radius))
		{
			mainComet->position.y += 200.0f * GetFrameTime();
		}
		if (IsKeyDown(KEY_LEFT) && mainComet->position.x > (0 + mainComet->radius))
		{
			mainComet->position.x -= 200.0f * GetFrameTime();
		}
		if (IsKeyDown(KEY_RIGHT) && mainComet->position.x < (windowWidth - mainComet->radius))
		{
			mainComet->position.x += 200.0f * GetFrameTime();
		}

		// PHYSICS



		// GRAPHICS
		
		BeginDrawing();

			//MENU SECTION

			if (!gameStart)
			{
				DrawText("COMET STRIKE", windowWidth / 2 - MeasureText("COMET STRIKE", 80) / 2, windowHeight / 5, 80, YELLOW);
				DrawText("Press enter to play", windowWidth / 2 - MeasureText("press enter to play", 30) / 2, windowHeight / 1.5, 30, YELLOW);
			}

			ClearBackground(BLACK);
			mainComet->Draw();
		EndDrawing();
	}

	CloseWindow();
	delete mainComet;
	return 0;
}