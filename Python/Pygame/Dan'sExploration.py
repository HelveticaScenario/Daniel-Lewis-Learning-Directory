"""
This is my (Dan) little testing script that I
am using to explore working with Pygame. Feel free to 
use it as a starting point for whatever, but i would prefer
you not alter it. thanks guys :)
"""


from __future__ import division
import pygame, sys
from pygame.locals import *
pygame.init()
fpsClock = pygame.time.Clock()

DISPLAYSURF = pygame.display.set_mode((640, 480))
pygame.display.set_caption('Hi')

custColor = pygame.Color(0,0,0)
normalizedX = 0.0
normalizedY = 0.0
newR = 255
newG = 0
newB = 0
mousex, mousey = 0.0, 0.0
once = 0

class movable:
    def __init__(self, x=0, y=0):
        """
        BLAH
        """
        self.x = x
        self.y = y
        print self.x, self.y
    def movX(self, value):
        """
        Add or subtract from the X coordinate value.
        """
        self.x = self.x + value
    def movY(self, value):
        """
        Add or subtract from the Y coordinate value.
        """
        self.y = self.y + value
start = movable()


while True:
    
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()
        if event.type == MOUSEMOTION:
            mousex, mousey = event.pos
            normalizedX = (mousex/DISPLAYSURF.get_width())
            normalizedY = (mousey/DISPLAYSURF.get_height())
            newR = normalizedX*255
            newG = normalizedY*255
            custColor = (newR,newG,newB)
    while once==0:
        print custColor
        print mousex, mousey
        print normalizedX, normalizedY
        once = 1
    
    DISPLAYSURF.fill(custColor)
    pygame.draw.aaline(DISPLAYSURF, (192,192,192), (DISPLAYSURF.get_width(),DISPLAYSURF.get_height()), pygame.mouse.get_pos(), 1)
    pygame.draw.aaline(DISPLAYSURF, (192,192,192), (DISPLAYSURF.get_width(),0), pygame.mouse.get_pos(), 1)
    pygame.draw.aaline(DISPLAYSURF, (192,192,192), (0,DISPLAYSURF.get_height()), pygame.mouse.get_pos(), 1)
    pygame.draw.aaline(DISPLAYSURF, (192,192,192), (0,0), pygame.mouse.get_pos(), 1)
    pygame.draw.circle(DISPLAYSURF, (192,192,192), pygame.mouse.get_pos(), 10, 1)
    pygame.display.update()