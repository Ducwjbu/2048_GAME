#include<bits/stdc++.h>
#include<SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "class.h"
#include "board.h"
#include "useForAll.h"
#include "loseAndWinScreen.h"
using namespace std;

void setPosition()
{
    int x=GAP+GAP;
    for(int i=0;i<4;i++)
    {
        int y=GAP+BUTTON_HEIGHT+GAP+GAP;
        for(int j=0;j<4;j++)
        {
            block[i][j].i=i;
            block[i][j].j=j;
            pos[i][j]={x,y};
            y+=GAP+BLOCK_EDGE;
        }
        x+=GAP+BLOCK_EDGE;
    }
}
void blockMovement(SDL_Event &e)
{
    if(e.type==SDL_KEYDOWN&&(e.key.keysym.sym==SDLK_DOWN||e.key.keysym.sym==SDLK_UP||e.key.keysym.sym==SDLK_LEFT||e.key.keysym.sym==SDLK_RIGHT))
    {
        switch (e.key.keysym.sym)
        {
            case SDLK_DOWN:
                moveDown();
                break;
            case SDLK_UP:
                moveUp();
                break;
            case SDLK_LEFT:
                moveLeft();
                break;
            case SDLK_RIGHT:
                moveRight();
                break;
        }
        if(!nextStep())
        {
            lose=1;
        }
        updateBoard();
    }
}
void isGameWon(){
    for(int i = 0;i<4;i++){
        for(int j = 0; j<4;j++){
            if(block[i][j].val == 2){
                printWinScreen();
            }
        }
    }

}
void start()
{
    SDL_Event e;
    bool quit=0;
    nextStep();
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);
    setPosition();
    drawBoard();
    updateBoard();
    while(!quit)
    {
        while(SDL_PollEvent(&e))
        {
            isGameWon();
            if( e.type == SDL_QUIT) quit=1;
            blockMovement(e);

            if(!lose)
            {

                SDL_RenderPresent(renderer);
            }
            else
            {
                printLoseScreen();

           }
        }

    }
}
void init()
{
    window=SDL_CreateWindow("2048",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
}
void loadMedia()
{
    SDL_Surface* tmpSurface=NULL;
    for(int i=0;i<=10;i++)
    {
        stringstream s("");
        s<<"stuff/"<<(1<<i)<<".png";
        tmpSurface=IMG_Load(s.str().c_str());
        value[i]=SDL_CreateTextureFromSurface(renderer,tmpSurface);
    }
    SDL_FreeSurface(tmpSurface);
    loadLoseAndWinScreen();
}
int main(int argv,char* argc[])
{
    srand(time(0));
    init();
    loadMedia();
    bool endGame=0;

    start();

}
