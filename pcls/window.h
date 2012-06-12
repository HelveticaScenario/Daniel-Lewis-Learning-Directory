#ifndef window_akjerb
#define window_akjerb
#include <windows.h>
#include <GL\gl.h>

HDC hDC;

void ErrorBox(char* s){
  MessageBox(NULL, s, "ERROR", MB_ICONERROR);
}

HWND MakeWindow(char* title, int width, int height, void* WndProc, HINSTANCE hInstance){
  const char* className = "OpenGL Window";
  //Setup and register Window Class, return 0 if failure
  WNDCLASS wc;
  wc.style = 0;
  wc.lpfnWndProc = WndProc;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hInstance = hInstance;
  wc.hIcon = 0;
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = 0;
  wc.lpszMenuName = 0;
  wc.lpszClassName = className;
  if(!RegisterClass(&wc)) return 0;
  DWORD mode = WS_POPUP;
  /*
  DWORD mode = (fullscreen) ? WS_POPUP:WS_CAPTION;
  if(fullscreen){//Make window fullscreen
    width = GetSystemMetrics(SM_CXSCREEN);
    height = GetSystemMetrics(SM_CYSCREEN);
  }
  */
  RECT window = {0, 0, width, height};
  AdjustWindowRect(&window, mode, 0);
  width = window.right - window.left;
  height = window.bottom - window.top;
  HWND hWnd = CreateWindow(className, title, mode, (GetSystemMetrics(SM_CXSCREEN)-width)/2, (GetSystemMetrics(SM_CYSCREEN)-height)/2, width, height, 0, 0, hInstance, 0);
  if(!hWnd) return 0;
  //Choose pixel format
  PIXELFORMATDESCRIPTOR pfd = {0};
  pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
  pfd.nVersion = 1;
  pfd.dwFlags = PFD_DRAW_TO_WINDOW|PFD_SUPPORT_OPENGL|PFD_DOUBLEBUFFER;
  pfd.iPixelType = PFD_TYPE_RGBA;
  pfd.cColorBits = 24;
  pfd.cDepthBits = 16;
  pfd.iLayerType = PFD_MAIN_PLANE;
  //Set DC and RC, return 0 if failure
  if(!(hDC = GetDC(hWnd))) return 0;
  if(!SetPixelFormat(hDC, ChoosePixelFormat(hDC, &pfd), &pfd)) return 0;
  HGLRC hRC = wglCreateContext(hDC);
  if(!hRC) return 0;
  if(!wglMakeCurrent(hDC, hRC)) return 0;
  //Setup OpenGL
  glClearColor(0.0f, 0.0f, 0.0f, 0.5f);

  ShowWindow(hWnd, SW_SHOW);
  return hWnd;
}

void BreakWindow(HWND hWnd){
  
}

#endif