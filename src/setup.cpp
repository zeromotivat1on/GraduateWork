#include <stdio.h>
#include <SDL2/SDL.h>
#include "../inc/defines.h"
#include "../inc/setup.h"

bool try_init_sdl() {
  bool success = true;
  if(SDL_Init(SDL_INIT_VARS) < 0) {
    fprintf(stderr, "SDL Initialization Error: %s\n", SDL_GetError());
    success = false;
  }
  return success;
}

void init_sdl() {
  printf("Initializing SDL...\n");
  if(try_init_sdl()) {
    printf("SDL Initialization success\n");
  }
  else {
    printf("SDL Initialization fail\n");
    exit(-1);
  }
}

bool try_init_window(SDL_Window **window) {
  bool success = true;
  *window = SDL_CreateWindow(
    "Procedural Generation",                        // window title
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // window pos x and y
    SCREEN_W, SCREEN_H,                             // window width and height
    SDL_WINDOW_SHOWN);                              // additional flags
  if(*window == NULL) {
    fprintf(stderr, "SDL Window Creation Error: %s\n", SDL_GetError());
    success = false;
  }
  return success;
}

void init_window(SDL_Window **window) {
  printf("Creating SDL Window...\n");
  if(try_init_window(window)) {
    printf("SDL Window Creation success\n");
  }
  else {
    printf("SDL Window Creation fail\n");
    exit(-1);
  }
}

bool try_init_surface(SDL_Surface **surface, SDL_Window **window) {
  bool success = true;
  *surface = SDL_GetWindowSurface(*window);
  if(*surface == NULL) {
    fprintf(stderr, "SDL Surface Creation Error: %s\n", SDL_GetError());
    success = false;
  }
  return success;
}

void init_surface(SDL_Surface **surface, SDL_Window **window) {
  printf("Creating SDL Surface...\n");
  if(*window == NULL) {
    printf("Window was NULL\n");
    exit(-1);
  }
  if(try_init_surface(surface, window)) {
    printf("SDL Surface Creation success\n");
  }
  else {
    printf("SDL Surface Creation fail\n");
    exit(-1);
  }
}