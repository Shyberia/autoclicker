#include <future>
#include <string>
#include <windows.h>
#include <dwmapi.h>
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <d3d11.h>
#include <tchar.h>
#include <winuser.h>
#include "imgui.hpp"
#include "menu.hpp"
#include "autoclicker.hpp"


// Main code
int main(int, char**) {
    initWindow();
    if(!initD3D()) {
        return 1;
    }
    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);
    initImgui();
    // Our state
    bool show_demo_window    = true;
    bool show_another_window = false;

    // Main loop
    auto _    = std::async(std::launch::async, killswitch);
    auto __   = std::async(std::launch::async, toggle);
    bool done = false;
    while(!done) {
        // Poll and handle messages (inputs, window resize, etc.)
        // See the WndProc() function below for our to dispatch events to the Win32 backend.
        MSG msg;
        while(::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE)) {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if(msg.message == WM_QUIT) {
                done = true;
            }
        }
        if(done) {
            break;
        }

        if(!prerender()) {
            continue;
        }
        //drawing stuff here
        render();
        //transparent background
        overlay();

        postRender();
        if(active) {
            if(left) {
                clickleft();
            }
            if(right) {
                clickright();
            }
        }
    }
    cleanup();

    return 0;
}
