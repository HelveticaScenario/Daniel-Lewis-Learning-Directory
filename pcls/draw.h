#ifndef draw_akjerb
#define draw_akjerb
#include <GL\gl.h>
#include "list.h"
#include "geometry.h"
#include <stdio.h>

void DrawLine(line* rect){
  glBegin(GL_LINES);
  glVertex2f(rect->x1, rect->y1);
  glVertex2f(rect->x2, rect->y2);
  glEnd();
}

void DrawLines(node* lines){
  glBegin(GL_LINES);
  while(lines){
    glVertex2f(((line*)lines->d)->x1, ((line*)lines->d)->y1);
    glVertex2f(((line*)lines->d)->x2, ((line*)lines->d)->y2);
    lines = lines->n;
  }
  glEnd();
}

void DrawRect(line* rect){
  glBegin(GL_QUADS);
  glVertex2f(rect->x1, rect->y1);
  glVertex2f(rect->x1, rect->y2);
  glVertex2f(rect->x2, rect->y2);
  glVertex2f(rect->x2, rect->y1);
  glEnd();
}

void DrawRects(node* rects){
  glBegin(GL_QUADS);
  while(rects){
    glVertex2f(((line*)rects->d)->x1, ((line*)rects->d)->y1);
    glVertex2f(((line*)rects->d)->x1, ((line*)rects->d)->y2);
    glVertex2f(((line*)rects->d)->x2, ((line*)rects->d)->y2);
    glVertex2f(((line*)rects->d)->x2, ((line*)rects->d)->y1);
    rects = rects->n;
  }
  glEnd();
}

void Write(char* text, GLint font){
  int i = 0, space = 0;
  const double xspacing = 1.0d/16.0d, yspacing = 1.0d/8.0d;
  double x, y;
  glBindTexture(GL_TEXTURE_2D, font);
  glPushMatrix();
  while(text[i]){
    switch(text[i]){
      case '\n':
        glTranslated(0.0d, -1.0d, 0.0d);
        space = 0;
        i++;
        break;
      default:
        y = (1.0d-yspacing) - (((int)text[i]) / 16)*yspacing;
        x =((int)text[i] % 16) * xspacing;
        glBegin(GL_QUADS);
        glTexCoord2d(x, y); glVertex2i(space, 0);
        glTexCoord2d(x, y+yspacing); glVertex2i(space, 1);
        glTexCoord2d(x+xspacing, y+yspacing); glVertex2i(space+1, 1);
        glTexCoord2d(x+xspacing, y); glVertex2i(space+1, 0);
        glEnd();
        space++;
        i++;
    }
  }
  glPopMatrix();
}
#endif