#pragma once
#include <windows.h>
#include <map>
#include "ButtonWin32.h"

class Window
{
public:
    Window(const wchar_t* title, int width, int height);
    ~Window();
    void Show();
    HWND GetHandle();
    void RegisterButton(ButtonWin32* button);

private:
	HWND hwnd;
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static std::map<HWND, ButtonWin32*> buttonMap;
};