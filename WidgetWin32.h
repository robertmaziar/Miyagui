#pragma once
#include "Widget.h"
#include <windows.h>
#include <string>

class WidgetWin32 : public Widget {
public:
    WidgetWin32(HWND parent, const wchar_t* className, const wchar_t* text, int x, int y, int width, int height);
    void Show() override;
    void Hide() override;
};