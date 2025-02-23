#include "Window.h"

std::map<HWND, ButtonWin32*> Window::buttonMap;

// Static window procedure for handling messages
LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    {
        if (uMsg == WM_COMMAND) {
            HWND buttonHandle = (HWND)lParam;
            if (buttonMap.find(buttonHandle) != buttonMap.end()) {
                buttonMap[buttonHandle]->onClick(); // Call the button’s function
            }
        }
        else if (uMsg == WM_DESTROY) {
            PostQuitMessage(0);
            return 0;
        }

        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

Window::Window(const wchar_t* title, int width, int height) {
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.lpszClassName = L"SimpleWindow";
    RegisterClass(&wc);

    hwnd = CreateWindow(L"SimpleWindow", title, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, width, height, nullptr, nullptr, wc.hInstance, nullptr);
}

Window::~Window() {
    DestroyWindow(hwnd);
}

void Window::Show() {
    ShowWindow(hwnd, SW_SHOW);
}

HWND Window::GetHandle() {
    return hwnd;
}

void Window::RegisterButton(ButtonWin32* button) {
    buttonMap[button->GetHandle()] = button; // Store the button handle
}