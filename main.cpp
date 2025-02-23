#include <iostream>
#include "Window.h"
#include "Application.h"
#include "ButtonWin32.h"

int main()
{
    Window mainWindow(L"Miyagui Library", 400, 300);
    mainWindow.Show();

    ButtonWin32 button1(mainWindow.GetHandle(), L"Test One", 50, 50, 100, 50);

    button1.SetOnClick([]() { MessageBox(nullptr, L"Test from Button One!", L"Test", MB_OKCANCEL); });
    mainWindow.RegisterButton(&button1);

    ButtonWin32 button2(mainWindow.GetHandle(), L"Test Two", 180, 50, 100, 50);
    button2.SetOnClick(L"Test from Button Two!", L"Test");

    mainWindow.RegisterButton(&button2);

    return Application::Run();
}