#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "tkSDL.h"


int randword(int arrsize) {
	int result = (rand() % arrsize);

	return result;
}

void typingtest(int strlen, char A[][strlen], size_t size) {
	printf("\033[H\033[2J");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < strlen; j++) {
			printf("%c", A[i][j]);
		}	
		printf(" ");
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	struct Game game = {
		.window = NULL,
		.renderer = NULL,
		.background = NULL,
		.text_font = NULL,
		.text_color = {255, 255, 255, 255},
		.text_rect = {0, 0, 0, 0},
		.text_image = NULL,
	};

	if (sdlinit(&game)) {
		sdlclose(&game, EXIT_FAILURE);
	}	
	
	if (load_media(&game)) {
		sdlclose(&game, EXIT_FAILURE);
	}	
	
	char word[][7] = {
		{"the"},
		{"quick"},
		{"brown"},
		{"fox"},
		{"jumped"},
		{"over"},
		{"the"},
		{"lazy"},
		{"dog"}
	}; // size in bytes is 63	



// 	typingtest(sizeof(*word), word, sizeof(word)/sizeof(*word));

	bool running = true;
	SDL_Event event;	
	
	SDL_RenderClear(game.renderer);
	SDL_RenderPresent(game.renderer);	
	

	// main game loop
	while (running) {		
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					running = false;
					break;
				case SDL_KEYDOWN:
					printf("a key has been pressed\n");
					switch (event.key.keysym.sym) {
						case SDLK_ESCAPE:
							running = false;	
							break;	
						case SDLK_t:
							typingtest(
								sizeof(*word),
								word,
							  	sizeof(word)/sizeof(*word)
							);
						default:
							break;
					}		
				default:
					break;
			}	
		}
		SDL_RenderClear(game.renderer);  		

		//SDL_RenderCopy(game.renderer, game.background, NULL, NULL);

		SDL_RenderCopy(game.renderer, game.text_image, NULL, &game.text_rect);

		SDL_RenderPresent(game.renderer);

		//SDL_Delay(16);
	}
	sdlclose(&game, EXIT_SUCCESS);
	return 0;

}
