#include"win32.h"




int main()
{
    Window window;
    
    create_window(window);

    while (message_loop(window))
    {

    }    

    return 0;
}



int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
    Window window;

    create_window(window);

    while (message_loop(window))
    {

    }

    return 0;
}




LRESULT CALLBACK window_procedure(HWND window, UINT message, WPARAM w_param, LPARAM l_param)
{
    if (message == WM_DESTROY)
    {
        PostQuitMessage(0);
        return 0;
    }
    else if (message == WM_PAINT)
    {
        PAINTSTRUCT paint_struct;

        HDC handle_device_context = BeginPaint(window, &paint_struct);

        FillRect(handle_device_context, &paint_struct.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(window, &paint_struct);

        return 0;
    }

    return DefWindowProc(window, message, w_param, l_param);
}




void create_window(Window &window)
{
    RegisterClass(&window.window_class);

    //create window function.
    HWND hwnd = CreateWindowEx
    (
        0,                      //DWORD     dwExStyle,
        (LPCWSTR)window.NAME,   //LPCWSTR   lpClassName,
        L"Window Name",         //LPCWSTR   lpWindowName,
        WS_OVERLAPPEDWINDOW,    //DWORD     dwStyle,
        CW_USEDEFAULT,          //int       X,
        CW_USEDEFAULT,          //int       Y,
        CW_USEDEFAULT,          //int       nWidth,
        CW_USEDEFAULT,          //int       nHeight,
        NULL,                   //HWND      hWndParent,
        NULL,                   //HMENU     hMenu,
        window.instance,        //HINSTANCE hInstance,
        NULL                    //LPVOID    lpParam
    );

    ShowWindow(hwnd, SW_SHOW);
}




bool message_loop(Window &window)
{      
    while (PeekMessage(&window.msg, NULL, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&window.msg);
        DispatchMessage (&window.msg);
    }
    
    if (window.msg.message == WM_QUIT)
    {
        return false;
    }   
        
    return true;
}