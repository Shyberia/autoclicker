#include <string>
#include <windows.h>
#include <dwmapi.h>
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <d3d11.h>
#include <tchar.h>
#include <winuser.h>
// Data
extern ID3D11Device*        g_pd3dDevice;
extern ID3D11DeviceContext* g_pd3dDeviceContext;
extern IDXGISwapChain*      g_pSwapChain;
extern bool g_SwapChainOccluded;
extern UINT g_ResizeWidth, g_ResizeHeight;
extern ID3D11RenderTargetView* g_mainRenderTargetView;
extern WNDCLASSEXW             wc;
extern HWND hwnd;

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//code split functions
void initWindow();
bool initD3D();
void initImgui();
bool prerender();
void overlay();
void postRender();
void cleanup();
