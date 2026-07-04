struct Game {
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *background;
	TTF_Font *text_font;
	SDL_Color text_color;
	SDL_Rect text_rect;
	SDL_Texture *text_image;
};

void sdlclose(struct Game *game, int exit_status);
bool sdlinit(struct Game *game);
bool load_media(struct Game *game);
