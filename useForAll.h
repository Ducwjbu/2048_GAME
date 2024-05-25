#include<bits/stdc++.h>
#include<SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#ifndef USEFORALL_H
#define USEFORALL_H
SDL_Window *window=NULL;
const int SCREEN_HEIGHT=690;
const int SCREEN_WIDTH=590;
const int BOARD_EDGE=570;
const int BUTTON_HEIGHT=90;
const int BLOCK_EDGE=130;
const int GAP=10;
const int BLOCK_V=20;
SDL_Renderer* renderer;
int point=0;
bool lose=0;
bool win=0;
#endif // USEFORALL_H
