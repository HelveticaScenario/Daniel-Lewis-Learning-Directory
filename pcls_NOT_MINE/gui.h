#ifndef gui_akjerb
#define gui_akjerb
#include "window.h"
#include <stdlib.h>
#include <stdio.h>
#include "geometry.h"
#include "list.h"
#include "draw.h"
#include <GL\gl.h>
#include <GL\glext.h>

double xCam, yCam, hCam, wCam;
int winWidth, winHeight;

point WIN2OGL(LPARAM lParam){
  point p;
  p.y =  ((2*hCam)*(winHeight-(lParam>>16))/(double)winHeight) - hCam + yCam;
  p.x = ((2*wCam)*(lParam&0xFFFF)/(double)winWidth) - wCam + xCam;
  return p;
}

typedef struct button{
  int (*hitTest)(point);
  void (*callback)();
}button;

void CheckButtons(point mouse, node* buttons){
  while(buttons){
    int i = (*((button*)(buttons->d))->hitTest)(mouse);
    if(i) (*((button*)(buttons->d))->callback)();
    buttons = buttons->n;
  }
}

GLubyte* ReadBMP(char* filename, GLint* width, GLint* height){
  FILE* f = fopen(filename, "rb");
  if(!f) return 0;
  int offset;
  fseek(f, 0xA, SEEK_SET);
  fread(&offset, 4, 1, f);
  fseek(f, 0x12, SEEK_SET);
  fread(width, 4, 1, f);
  fread(height, 4, 1, f);
  fseek(f, offset, SEEK_SET);
  GLubyte* data = malloc((*width)*(*height)*4);
  if(!fread(data, (*width)*(*height)*4, 1, f)) return 0;
  fclose(f);
  return data;
}

GLuint LoadTexture(char* filename){
  static GLint width, height;
  GLubyte* data = ReadBMP(filename, &width, &height);
  if(!data) return 0;
  GLuint texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, data);
  free(data);
  return texture;
}

GLuint LoadPointSprite(char* filename){
  static GLint width, height;
  GLubyte* data = ReadBMP(filename, &width, &height);
  if(!data) return 0;
  GLuint texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexEnvf(GL_POINT_SPRITE_NV, GL_COORD_REPLACE_NV, GL_TRUE);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, data);
  free(data);
  return texture;
}



#endif