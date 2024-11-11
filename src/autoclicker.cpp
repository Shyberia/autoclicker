#include "autoclicker.hpp"
#include <cstdio>
#include <windows.h>
#include <winuser.h>

int  sleep_time = 1000;
bool active     = true;

void clickleft() {
    INPUT input = {};

    input.type       = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
    Sleep(sleep_time);
}

void clickright() {
    INPUT input = {};

    input.type       = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    SendInput(1, &input, sizeof(INPUT));
    input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    SendInput(1, &input, sizeof(INPUT));
    Sleep(sleep_time);
}

void killswitch() {
    while(true) {
        if(GetAsyncKeyState(VK_END)) {
            active = false;
        }
    }
}

void toggle() {
    while(true) {
        if(GetAsyncKeyState(VK_INSERT)) {
            active = !active;
        }
    }
}
