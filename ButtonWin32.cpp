#include "ButtonWin32.h"

ButtonWin32::ButtonWin32(HWND parent, const wchar_t* text, int x, int y, int width, int height) {
    nativeHandle = CreateWindow(L"BUTTON", text, WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        x, y, width, height, parent, (HMENU)1, GetModuleHandle(nullptr), nullptr);
}

void ButtonWin32::Show() {
    ShowWindow(nativeHandle, SW_SHOW);
}

void ButtonWin32::Hide() {
    ShowWindow(nativeHandle, SW_HIDE);
}

void ButtonWin32::SetText(const wchar_t* text) {
    SetWindowText(nativeHandle, text);
}

void ButtonWin32::SetOnClick(std::function<void()> callback) {
    onClick = callback;
}

void ButtonWin32::SetOnClick(const wchar_t* text, const wchar_t* caption)
{
    onClick = [text, caption]() {
        MessageBox(nullptr, text, caption, MB_OK);
        };
}
