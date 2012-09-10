#!/usr/local/bin/python3

import pygame, sys
from pygame.locals import *
pygame.init()
DISPLAYSURF = pygame.display.set_mode((640, 480))
pygame.display.set_caption('Hi')
while True:
     DISPLAYSURF.fill((0,0,0))
     for event in pygame.event.get():
         if event.type == QUIT:
             pygame.quit()
             sys.exit()
         if event.type == MOUSEMOTION:
             pygame.draw.circle(DISPLAYSURF, (192,192,192), pygame.mouse.get_pos(), 5, 1)
     pygame.draw.circle(DISPLAYSURF, (192,192,192), pygame.mouse.get_pos(), 10, 1)
     pygame.display.update()