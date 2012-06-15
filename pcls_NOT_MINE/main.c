//#include "window.h"
#include "gui.h"
#include <math.h>
#include <stdio.h>

//Globals
float bigG = -0.001;
int i, ii, numParticles;
point* xy, *xyp, *accel, *t;
BOOL keys[256];
float xview = 30, yview = 30;
long long start, end, total;
double num = 0;
GLint tex;

void Input(){
  static MSG msg;
  while(PeekMessage(&msg, 0, 0, 0, PM_REMOVE)){
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
}

void Crunch(){
  QueryPerformanceCounter((LARGE_INTEGER*)&start);
  static float d, e, f, a, b, c;
  memset(accel, 0, numParticles*sizeof(*accel));
  for(i = 0; i < numParticles-1; i++){
    for(ii = i+1; ii < numParticles; ii++){
      a = xy[i].x - xy[ii].x;
      b = xy[i].y - xy[ii].y;
      d = a*a;
      e = b*b;
      f = d+e;
      f *= sqrt(f);
      f = bigG/f;
      a *= f;
      b *= f;
      accel[i].x += a;
      accel[i].y += b;
      accel[ii].x -= a;
      accel[ii].y -= b;
    }
  }
  for(i = 0; i < numParticles; i++){
    xyp[i].x = 2*xy[i].x - xyp[i].x + accel[i].x;
    xyp[i].y = 2*xy[i].y - xyp[i].y + accel[i].y;
  }
  t = xyp;
  xyp = xy;
  xy = t;
  QueryPerformanceCounter((LARGE_INTEGER*)&end);
  total += end-start;
  num++;
}

void Draw(){
  glClear(GL_COLOR_BUFFER_BIT);
  //Single points
  glBindTexture(GL_TEXTURE_2D, tex);
  glBegin(GL_POINTS);
  for(i = 0; i < numParticles; i++){
    glVertex2f(xy[i].x, xy[i].y);
  }
  glEnd();
  
  /*//Alpha lines
  glBegin(GL_LINES);
  for(i = 0; i < numParticles; i++){
    glColor4d(1.0d, 1.0d, 1.0d, 1.0d); glVertex2f(xy[i].x, xy[i].y);
    glColor4d(1.0d, 1.0d, 1.0d, 0.0d); glVertex2f(xyp[i].x, xyp[i].y);
  }
  glEnd();
  */
  SwapBuffers(hDC);
}

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

int main(HINSTANCE hInstance){
  printf("How many particles? ");
  scanf("%i", &numParticles);
  xy = malloc(numParticles*sizeof(*xy));
  xyp = malloc(numParticles*sizeof(*xyp));
  accel = malloc(numParticles*sizeof(*accel));
  for(i = 0; i < numParticles; i++){
    xy[i].x = xview * (rand() / (float)RAND_MAX);
    xy[i].y = yview * (rand() / (float)RAND_MAX);
    xyp[i].x = xy[i].x;
    xyp[i].y = xy[i].y;
  }
  MakeWindow("Particles", 600, 600, &WndProc, hInstance);
  glOrtho(0, xview, 0, yview, -1, 1);
  glPointSize(10);
  glLineWidth(5);
  glEnable(GL_POINT_SMOOTH);
  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_POINT_SPRITE_NV);
  tex = LoadPointSprite("point.bmp");
  while(!keys[VK_ESCAPE]){
    Input();
    Crunch();
    Draw();
    Sleep(10);
  }
  QueryPerformanceFrequency((LARGE_INTEGER*)&start);
  num = total/num;
  printf("Average ticks per Crunch(): %f (%f seconds)", num, num/start);
  return 0;
}