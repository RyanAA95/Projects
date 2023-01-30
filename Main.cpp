#include "Header.h"

int main()
{
	// Enable VSync, Initianlize Window

	SetWindowState(FLAG_VSYNC_HINT);

	InitWindow(800, 600, "Comet Strike");
	

	while (!WindowShouldClose)
	{
		if (IsKeyPressed(KEY_TAB))
		{
			ToggleFullScreenWindow(GetDisplayWidth(), GetDisplayHeight());
		}
		
		BeginDrawing();
		
		EndDrawing();
	}

	return 0;
}