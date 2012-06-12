#include "gui.h"

//Globals
float x = 5;//x position
BOOL keys[256];//keyboard state

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
  switch(uMsg){
    case WM_KEYDOWN:
      keys[wParam] = 1;
      return 0;
    case WM_KEYUP:
      keys[wParam] = 0;
      return 0;
    default:
      return DefWindowProc(hWnd, uMsg, wParam, lParam);
  }
}

void HandleInput(){
  static MSG msg;
  while(PeekMessage(&msg, 0, 0, 0, PM_REMOVE)){
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
}

void DoStuff(){
  if(keys[VK_RIGHT]) x+=0.1;
  if(keys[VK_LEFT]) x-=0.1;
}

void Draw(){
  glClear(GL_COLOR_BUFFER_BIT);
  
  glBegin(GL_QUADS);
  glColor3f(1.0f, 1.0f, 0.0f);
  glVertex2f(x, 0.25f);
  glVertex2f(x+1, 0.25f);
  glVertex2f(x+1, 0.75f);
  glVertex2f(x, 0.75f);
  glEnd();
  
  SwapBuffers(hDC);//One buffer is drawn while the other is displayed, so swap when done drawing the frame
}

void Setup(HINSTANCE h){
  winWidth = 600;//declared in gui.h
  winHeight = 600;//declared in gui.h
  MakeWindow("GRAPHICS", winWidth, winHeight, &WndProc, h);
  glOrtho(0.0f, 10.0f, 0.0f, 1.0f, -1.0f, 1.0f);//Set left, right, bottom, top, back, front coords of screen
}

int main(HINSTANCE hInstance){
  Setup(hInstance);
  while(!keys[VK_ESCAPE]){
    HandleInput();
    DoStuff();
    Draw();
    Sleep(10);
  }
  return 0;
}