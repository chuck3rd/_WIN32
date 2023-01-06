#ifndef WIN32_H
#define WIN32_H

// Active Preprocessor Block
#ifdef _WIN32

#include<Windows.h>

LRESULT CALLBACK window_procedure(HWND window, UINT message, WPARAM w_param, LPARAM l_param);




struct Window
{
    const char* NAME   = "Window";
    MSG msg            = {};
    HINSTANCE instance = GetModuleHandle(NULL);

    //struct
    WNDCLASS window_class =
    {
        0,                      //UINT      style;
        window_procedure,       //WNDPROC   lpfnWndProc;
        0,                      //int       cbClsExtra;
        0,                      //int       cbWndExtra;
        instance,               //HINSTANCE hInstance;
        0,                      //HICON     hIcon;
        0,                      //HCURSOR   hCursor;
        0,                      //HBRUSH    hbrBackground;
        0,                      //LPCWSTR   lpszMenuName;
        (LPCWSTR)NAME           //LPCWSTR   lpszClassName;
    };
};



// function prototypes
void create_window(Window&);
bool message_loop (Window&);




#endif // _WIN32

#endif // !WIN32_H