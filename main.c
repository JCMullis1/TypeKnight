#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>

int randword(int arrsize) {
	int result = (rand() % arrsize);

	return result;
}

void typingtest(int strlen, char A[][strlen], size_t size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < strlen; j++) {
			printf("%c", A[i][j]);
		}	
		printf(" ");
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_AUDIO) != 0) {
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

//	printf("%s\n", word[randword(sizeof(word)/sizeof(*word))]);

	typingtest(sizeof(*word), word, sizeof(word)/sizeof(*word));

	return 0;

}
