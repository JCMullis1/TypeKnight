#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "tkSDL.h"

#define IMAGE_FLAGS IMG_INIT_PNG
#define TEXT_SIZE 80



struct Game;



void sdlclose(struct Game *game, int exit_status) {
        SDL_DestroyTexture(game->text_image);
        TTF_CloseFont(game->text_font);
        SDL_DestroyTexture(game->background);
        SDL_DestroyWindow(game->window);
        SDL_DestroyRenderer(game->renderer);
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        exit(exit_status);
}



bool sdlinit(struct Game *game) {
        if ( SDL_Init( SDL_INIT_EVERYTHING ) != 0) {
                fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
                return true;
        }

        int img_init = IMG_Init(IMAGE_FLAGS);
        if ((img_init & IMAGE_FLAGS) != IMAGE_FLAGS) {
                fprintf(stderr, "Error initializing SDL_Image: %s\n", IMG_GetError());
                return true;
        }

        if (TTF_Init()) {
                fprintf(stderr, "Error initializing SDL_ttf: %s\n", TTF_GetError());
                return true;
        }

        game->window = SDL_CreateWindow(
                "TypeKnight",
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                800,
                600,
                SDL_WINDOW_SHOWN
        );
        if (!game->window) {
                fprintf(stderr, "Error creating window %s\n", SDL_GetError());
                return true;
        }

        game->renderer = SDL_CreateRenderer(
                        game->window,
                        -1,
                        SDL_RENDERER_ACCELERATED
        );
        if (!game->renderer) {
                fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
                return true;
        }

        srand((unsigned)time(NULL));

        return false;
}



bool load_media(struct Game *game) {
        game->background = IMG_LoadTexture(game->renderer, "images/skeleton.png");
        if (!game->background) {
                fprintf(stderr, "Error creating Texture: %s\n", IMG_GetError());
                return true;
        }

        game->text_font = TTF_OpenFont("fonts/GothicPixel.ttf", TEXT_SIZE);
        if (!game->text_font) {
                fprintf(stderr, "Error creating TTF font: %s\n", TTF_GetError());
                return true;
        }

        SDL_Surface *surface = TTF_RenderText_Blended(game->text_font, "SDL", game->text_color);
        if (!surface) {
                fprintf(stderr, "Error creating Surface: %s\n", SDL_GetError());
                return true;
        }
        game->text_rect.w = surface->w;
        game->text_rect.h = surface->h;
        game->text_image = SDL_CreateTextureFromSurface(game->renderer, surface);
        SDL_FreeSurface(surface);
        if (!game->text_image) {
                fprintf(stderr, "Error creating Texture: %s\n", SDL_GetError());
                return true;
        }
        return false;
}

