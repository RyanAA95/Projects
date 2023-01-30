#include "Header.h"

// Fullscreen sans resize tous les élements sur l'écran

void ToggleFullScreenWindow(const unsigned int& windowWidth, const unsigned int& windowHeight)
{
	if (IsWindowFullscreen)
	{
		ToggleFullscreen();
		SetWindowSize(windowWidth, windowHeight);
	}
	else
	{
		int monitor = GetCurrentMonitor();
		SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
	}
}

// Trouver la résolution de l'écran de l'utilisateur

int GetDisplayWidth()
{
	if (IsWindowFullscreen)
	{
		return GetScreenWidth();
	}
	else
	{
		return GetMonitorWidth(GetCurrentMonitor());
	}
}

// Trouver la résolution de l'écran de l'utilisateur

int GetDisplayHeight()
{
	if (IsWindowFullscreen)
	{
		return GetScreenHeight();
	}
	else
	{
		return GetMonitorHeight(GetCurrentMonitor());
	}
}
