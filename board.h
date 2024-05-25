#include<bits/stdc++.h>
#include<SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "useForAll.h"
#include "class.h"
using namespace std;
#ifndef BOARD_H

#define BOARD_H

SDL_Point pos[4][4];


void drawBoard()
{
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_Rect rect={GAP,GAP+BUTTON_HEIGHT+GAP,BOARD_EDGE,BOARD_EDGE};
    SDL_RenderFillRect(renderer,&rect);

  //  rect={GAP,GAP,(SCREEN_WIDTH-GAP*4)/3,BUTTON_HEIGHT};
   // SDL_RenderFillRect(renderer,&rect);

 //   rect={GAP*2+(SCREEN_WIDTH-GAP*4)/3,GAP,(SCREEN_WIDTH-GAP*4)/3,BUTTON_HEIGHT};
 //   SDL_RenderFillRect(renderer,&rect);

 //   rect={SCREEN_WIDTH-GAP-(SCREEN_WIDTH-GAP*4)/3,GAP,(SCREEN_WIDTH-GAP*4)/3,BUTTON_HEIGHT};
 //   SDL_RenderFillRect(renderer,&rect);
}


void updateBoard()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            block[i][j].update();
            block[i][j].render(pos[i][j].x,pos[i][j].y);
   //        cout<<i<<" "<<j<<" "<<" "<<block[i][j].i<<" "<<block[i][j].j<<" "<<pos[i][j].x<<" "<<pos[i][j].y<<" "<<block[i][j].val<<"\n";
        }
    }
}
#endif // BOARD_H
