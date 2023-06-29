#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <fstream>
#include "rpg.h"
#include <iostream>

// VARIABLE NOTATION, foo_foo for variables fooFoo for functions and FooFoo for classes.

using namespace std;

bool game_over = false;

int main(int argc, char *argv[]) {
        Entity player1 = Entity(30, 20, 18, "Jon Caleb", true);
        Entity player2 = Entity(30, 20, 15, "Noj Belac", true);
        Entity player3 = Entity(30, 30, 17, "Jomboo", true);
        Entity player4 = Entity(40, 20, 14, "Chuck", true);
        Entity monster1 = Entity();
        Battle new_battle = Battle("map");

        auto endInd = objArr.size();

        quickSort(objArr, 0, endInd-1);
        bool menu = true;

/*
        for (int i = 0; i < endInd; i++) {
                cout << objArr[i]->speed << endl;
        } // good for logging out the result of quickSort algo and such
*/

        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;

        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_CreateWindowAndRenderer(400*4,300*4, 0, &window, &renderer);
        SDL_RenderSetScale(renderer,4,4);

        while(menu) {
        }
        while(!game_over) {
        }

        return 0;
}

/*
int main(int argv, char** args)
{
        using namespace std::this_thread;
        using namespace std::chrono_literals;
        using std::chrono::system_clock;

        int WIDTH = 100;
        int HEIGHT = 100;
        SDL_Event e;

        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_CreateWindowAndRenderer(WIDTH*10,HEIGHT*10, 0, &window, &renderer);
        SDL_RenderSetScale(renderer,10,10);

        // initializing player
        Snake player1;
        player1.reset_matrix();
        player1.addSeg(50,50);
        player1.addSeg(101,101);
        player1.addSeg(101,102);
        player1.addSeg(101,103);

        player1.apple.appear();

        cout << "player initialized" << endl;

        while(!game_over)
        {
            while(SDL_PollEvent(&e)) {
                if(e.type == SDL_QUIT) {
                     game_over = true;
                }
                if(e.type == SDL_KEYDOWN)
                {
                    switch(e.key.keysym.sym)
                    {
                        case SDLK_w:
                            player1.direction = "up";
                            break;
                        case SDLK_s:
                            player1.direction = "down";
                            break;
                        case SDLK_d:
                            player1.direction = "right";
                            break;
                        case SDLK_a:
                            player1.direction = "left";
                            break;
                        case SDLK_ESCAPE:
                            game_over = true;
                            break;
                    }
                    // cout << player1.direction  << endl;
                }
            }
            player1.render();
            sleep_for(10ms);
            sleep_until(system_clock::now() + chrono::milliseconds(player1.speed));
        }
        player1.game_over_func();

        return 0;
};
*/
