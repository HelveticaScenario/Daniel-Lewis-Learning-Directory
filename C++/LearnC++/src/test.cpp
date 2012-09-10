
// * test.cpp
// *
// *  Created on: Aug 24, 2012
// *      Author: contrarian

#include <iostream>
#include "SDL2/SDL.h"
#include "unistd.h"
//#include "Box2D/Box2D.h"
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define SCREEN_DEPTH 8


using namespace std;

// void main_loop() {
// 	SDL_Surface *screen;
// 	SDL_Surface *bmp;
// 	SDL_Rect 	targetarea;

// 	// Uint8 		*p;
// 	// int 		x = 10;
// 	// int 		y = 20;

// 	SDL_Init(SDL_INIT_VIDEO);

// 	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH, SDL_SWSURFACE);

// 	bmp = SDL_LoadBMP("man.bmp");

// 	targetarea.x = 10;
// 	targetarea.y = 20;
// 	targetarea.w = bmp->w;
// 	targetarea.h = bmp->h;
// 	SDL_FillRect(SDL_GetVideoSurface(), NULL, 1);

// 	SDL_BlitSurface(bmp, NULL, screen, &targetarea);

// 	// p = (Uint8 *)screen->pixels + y * screen->pitch + x * screen->format->BytesPerPixel;

// 	// *p=0xff;

// 	SDL_Flip(screen);        

//         int quit = 0;
//         SDL_Event event;

//         while (!quit) {
//                 while(SDL_PollEvent(&event)) {  /* Loop until there are no events left on the queue */
//                   switch(event.type) { /* Process the appropiate event type */
//                     case SDL_ACTIVEEVENT:
//                         if (event.active.state & SDL_APPMOUSEFOCUS) {
//                                 if (event.active.gain) {
//                                         printf("Mouse focus gained\n");
//                                 } else {
//                                         printf("Mouse focus lost\n");
//                                 }
//                         }
//                         if (event.active.state & SDL_APPINPUTFOCUS) {
//                                 if (event.active.gain) {
//                                         printf("Input focus gained\n");
//                                 } else {
//                                         printf("Input focus lost\n");
//                                 }
//                         }
//                         if (event.active.state & SDL_APPACTIVE) {
//                                 if (event.active.gain) {
//                                         printf("Application restored\n");
//                                 } else {
//                                         printf("Application iconified\n");
//                                 }
//                         }
//                         break;
//                     case SDL_KEYDOWN:  /* Handle a KEYDOWN event */
//                         printf ("Key pressed:\n");
//                         printf ("       SDL sim: %i\n",event.key.keysym.sym);
//                         printf ("       modifiers: %i\n",event.key.keysym.mod);
//                         printf ("       unicode: %i (if enabled with SDL_EnableUNICODE)\n",\
//                                         event.key.keysym.unicode);
//                         break;
//                     case SDL_KEYUP:
//                         printf ("Key released:\n");
//                         printf ("       SDL sim: %i\n",event.key.keysym.sym);
//                         printf ("       modifiers: %i\n",event.key.keysym.mod);
//                         printf ("       unicode: %i (if enabled with SDL_EnableUNICODE)\n",\
//                                         event.key.keysym.unicode);
//                         break;
//                     case SDL_MOUSEMOTION:
//                         // printf ("Mouse moved to: (%i,%i) ", event.motion.x, event.motion.y);
//                         // printf ("change: (%i,%i)\n", event.motion.xrel, event.motion.yrel);
//                         SDL_FillRect( SDL_GetVideoSurface(), &targetarea, 0 );
//                         // printf ("       button state: %i\n",event.motion.state);
//                         targetarea.x = event.motion.x;
//                         // cout << targetarea.x << endl;
//                         targetarea.y = event.motion.y;
//                         // cout << targetarea.y << endl;
//                         SDL_BlitSurface(bmp, NULL, screen, &targetarea);
//                         SDL_Flip(screen);
//                         break;
//                     case SDL_MOUSEBUTTONDOWN:
//                         printf ("Mouse button %i ",event.button.button);
//                         printf ("pressed with mouse at (%i,%i)\n",event.button.x,event.button.y);
//                         break;
//                     case SDL_MOUSEBUTTONUP:
//                         printf ("Mouse button %i ",event.button.button);
//                         printf ("released with mouse at (%i,%i)\n",event.button.x,event.button.y);
//                         break;
//                     case SDL_JOYAXISMOTION:
//                         printf ("Joystick axis %i ",event.jaxis.axis);
//                         printf ("on joystick %i ", event.jaxis.which);
//                         printf ("moved to %i\n", event.jaxis.value);
//                         break;
//                     case SDL_JOYBALLMOTION:
//                         printf ("Trackball axis %i ",event.jball.ball);
//                         printf ("on joystick %i ", event.jball.which);
//                         printf ("moved to (%i,%i)\n", event.jball.xrel, event.jball.yrel);
//                         break;
//                     case SDL_JOYHATMOTION:
//                         printf ("Hat axis %i ",event.jhat.hat);
//                         printf ("on joystick %i ", event.jhat.which);
//                         printf ("moved to %i\n", event.jhat.value);
//                         break;
//                     case SDL_JOYBUTTONDOWN:
//                         printf ("Joystick button %i ",event.jbutton.button);
//                         printf ("on joystick %i ", event.jbutton.which);
//                         printf ("pressed\n");
//                         break;
//                     case SDL_JOYBUTTONUP:
//                         printf ("Joystick button %i ",event.jbutton.button);
//                         printf ("on joystick %i ", event.jbutton.which);
//                         printf ("released\n");
//                         break;
//                     case SDL_VIDEORESIZE:
//                         printf ("Window resized to: (%i,%i)\n",event.resize.w, event.resize.h);
//                         break;
//                     case SDL_VIDEOEXPOSE:
//                         printf ("Window exposed\n");
//                         break;
//                     case SDL_QUIT:
//                         printf ("Request to quit\n");
//                         quit = 1;
//                         break;
//                     case SDL_USEREVENT:
//                         printf ("User event:\n");
//                         printf ("       code:  %i\n",event.user.code);
//                         printf ("       data1: %p\n",event.user.data1);
//                         printf ("       data2: %p\n",event.user.data2);
//                         break;
//                     case SDL_SYSWMEVENT:
//                         printf ("Window manager event\n");
//                         break;
//                     default: /* Report an unhandled event */
//                         printf("I don't know what this event is!\n");
//                   }
//                 }
//         }
// }

// int main(int argc, char *argv[]){
	

	
// 	main_loop();

// 	return 0;
// }

int main(int argc, char* argv[])
{
        SDL_Window* window;
        SDL_Renderer* renderer;

        // Initialize SDL.
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
                return 1;

        // Create the window where we will draw.
        window = SDL_CreateWindow("SDL_RenderClear",
                        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                        512, 512,
                        SDL_WINDOW_SHOWN);

        // We must call SDL_CreateRenderer in order for draw calls to affect this window.
        renderer = SDL_CreateRenderer(window, -1, 0);

        // Select the color for drawing. It is set to red here.
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        // Clear the entire screen to our selected color.
        SDL_RenderClear(renderer);

        // Up until now everything was drawn behind the scenes.
        // This will show the new, red contents of the window.
        SDL_RenderPresent(renderer);

        // Give us time to see the window.
        SDL_Delay(5000);

        // Always be sure to clean up
        SDL_Quit();
        return 0;
}



