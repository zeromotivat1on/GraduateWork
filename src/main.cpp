#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "../inc/defines.h"
#include "../inc/setup.h"

int main(int argc, char** argv) {
  init_sdl();

  SDL_Window *window = NULL;
  SDL_Surface *surface = NULL;
  
  //* Set the SDL_Quit function to be called at the end of the program pipeline
  //  Note: SDL_Quit will be called the last as atexit called the first
  atexit(SDL_Quit);

  init_window(&window);
  init_surface(&surface, &window);

  SDL_Delay(2000);

  printf("Exiting program...");
  exit(0);
}