#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

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
	// NEED** Condition to switch game to headless
	// mode in the case of no graphics driver

//	if ( SDL_Init(SDL_INIT_VIDEO ) != 0) {
//		SDL_Log("Unable to initialize SDL Video: %s", SDL_GetError());
//		printf("Attempting headless mode...\n");
//		putenv("SDL_VIDEODIRVER=dummy");
//		if ( SDL_Init(SDL_INIT_VIDEO ) != 0) {
//			SDL_Log("Unable to run in initialize in headless mode: %s", SDL_GetError());
//			return 1;
//		}	
//	} 

	putenv("SDL_VIDEODRIVER=dummy");
	if ( SDL_Init(SDL_INIT_VIDEO ) != 0) {
		SDL_Log("Couldn't run in headless mode: %s", SDL_GetError());
		return 1;
	}	

	if ( SDL_Init( SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER ) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return 1;
	}
	srand(time(NULL));
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
						default:
							break;
					}		
				default:
					break;
			}	
		}
	}

	return 0;

}
