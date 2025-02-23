#include "WidgetWin32.h"

WidgetWin32::WidgetWin32(HWND parent, const wchar_t* className, const wchar_t* text, int x, int y, int width, int height)
{
	nativeHandle = CreateWindow(className, text, WS_VISIBLE | WS_CHILD, x, y, width, height, parent, nullptr, GetModuleHandle(nullptr), nullptr);
}

void WidgetWin32::Show()
{
	ShowWindow((HWND)nativeHandle, SW_SHOW);
}

void WidgetWin32::Hide()
{
	ShowWindow((HWND)nativeHandle, SW_HIDE);
}
