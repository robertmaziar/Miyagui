#pragma once
#include "Widget.h"
#include <string>
#include <functional>

class Button : public Widget {
public:
    virtual void SetText(const wchar_t* text) = 0;
    virtual void SetOnClick(std::function<void()> callback) = 0;
};