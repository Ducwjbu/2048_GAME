#include<bits/stdc++.h>
#include<SDL.h>
#include <SDL_image.h>
#include "useForAll.h"
using namespace std;
SDL_Texture* loseScreen;
SDL_Texture* winScreen;
SDL_Rect rectLoseWin={SCREEN_WIDTH/4,SCREEN_HEIGHT/4,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
void loadLoseAndWinScreen()
{
    SDL_Surface* tmpSurface;
    tmpSurface=IMG_Load("stuff/win.png");
    winScreen=SDL_CreateTextureFromSurface(renderer,tmpSurface);
    tmpSurface=IMG_Load("stuff/lose.png");
    loseScreen=SDL_CreateTextureFromSurface(renderer,tmpSurface);
}
void printWinScreen()
{
    SDL_RenderCopy(renderer,winScreen,NULL,&rectLoseWin);
    SDL_RenderPresent(renderer);
}
void printLoseScreen()
{
    SDL_RenderCopy(renderer,loseScreen,NULL,&rectLoseWin);
    SDL_RenderPresent(renderer);
}
