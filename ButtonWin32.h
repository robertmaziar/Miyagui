#pragma once
#include "Button.h"
#include <windows.h>
#include <functional>

class ButtonWin32 : public Button {
public:
    ButtonWin32(HWND parent, const wchar_t* text, int x, int y, int width, int height);
    std::function<void()> onClick;
    void Show();
    void Hide();
    void SetText(const wchar_t* text) override;
    void SetOnClick(std::function<void()> callback) override;
    void SetOnClick(const wchar_t* text, const wchar_t* caption);
    HWND GetHandle() { return nativeHandle; } // Getter for HWND
};


