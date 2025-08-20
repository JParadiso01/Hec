#include "WinEasy.h"
#include <stdio.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

    switch(msg)
    {   
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        case WM_KEYDOWN:
            switch (wParam)
            {
                //R
                case 0x52:
                    //printf("R");
                    break;
                default:
                    break;
            }
        break;

        case WM_PAINT:
            WinEasyPaint p = {0};
            WinEasyStartPaint(&p, &hwnd);

            WinEasyDrawBackground(p.backHDC, colors[DARK_GRAY], p.windowRect);
            WinEasyDrawCircle(p.backHDC, colors[GREEN], 200, 400, 10);

            WinEasyEndPaint(&p, hwnd);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;
    char ClassName[] = "myWindowClass";

    WinEasyCreateWindowClass(&wc, hInstance, &WndProc, ClassName, (HBRUSH)(COLOR_WINDOW-1));

    WinEasyCreateWindow(&hwnd, "WinEasy Test", ClassName, hInstance, 800, 600, 500, 200);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    WinEasyStartMsgLoop(Msg);

    return Msg.wParam;
}