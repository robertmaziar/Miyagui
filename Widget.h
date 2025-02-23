#pragma once
#include <wtypes.h>

class Widget {
public:
    virtual void Show() = 0;
    virtual void Hide() = 0;
protected:
    HWND nativeHandle; // OS handle (HWND in Windows)
};