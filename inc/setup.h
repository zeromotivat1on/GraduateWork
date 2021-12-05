#ifndef SETUP_H
#define SETUP_H

void init_sdl();
void init_window(SDL_Window **window);
void init_surface(SDL_Surface **surface, SDL_Window **window);

bool try_init_sdl();
bool try_init_window(SDL_Window **window);
bool try_init_surface(SDL_Surface **surface, SDL_Window **window);

#endif