#include<bits/stdc++.h>
#include<SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "useForAll.h"
using namespace std;
#ifndef CLASS_H
#define CLASS_H

TTF_Font* gFont;
SDL_Texture *value[11];
class lBlock
{
    public:
        lBlock()
        {
            cur=NULL;
            val=0;
        }
        ~lBlock(){ free(); }
        void free()
        {
            if(cur!=NULL)
            {
                SDL_DestroyTexture(cur);
                cur=NULL;
            }
            val=0;
        }
        void render(int x,int y,SDL_Rect* clip=NULL)
        {
            SDL_Rect pos={x,y,BLOCK_EDGE,BLOCK_EDGE};
            if(clip!=NULL) pos.w=clip->w,pos.h=clip->h;
            SDL_RenderCopy(renderer,cur,clip,&pos);
        }
        void update()
        {
            cur=value[val];
        }
        int val;
        int i,j,ni,nj;
    private:
        SDL_Texture* cur;


};

lBlock block[4][4];
void shortenVector(vector<int> v[2])
{
    for(int j=0;j<(int) v[0].size();j++)
    {
        if(j<(int)v[0].size()-1&&v[0][j]==v[0][j+1])
        {
            v[1].push_back(v[0][j]+1);
            j++;
        }
        else v[1].push_back(v[0][j]);
    }
}
void moveDown()
{
    for(int i=0;i<4;i++)
    {
        vector<int> v[2];
        for(int j=3;j>=0;j--)
        {
            if(block[i][j].val>0) v[0].push_back(block[i][j].val);
        }
        shortenVector(v);
        for(int j=3,z=0;j>=0;j--,z++) block[i][j].val=(z<(int)v[1].size()?v[1][z]:0);
    }
}
void moveUp()
{
    for(int i=0;i<4;i++)
    {
        vector<int> v[2];
        for(int j=0;j<4;j++)
        {
            if(block[i][j].val>0) v[0].push_back(block[i][j].val);
        }
        shortenVector(v);
        for(int j=0,z=0;j<4;j++,z++) block[i][j].val=(z<(int)v[1].size()?v[1][z]:0);
    }
}

void moveLeft()
{
    for(int j=0;j<4;j++)
    {
        vector<int> v[2];
        for(int i=0;i<4;i++)
        {
            if(block[i][j].val>0) v[0].push_back(block[i][j].val);
        }
        shortenVector(v);
        for(int i=0,z=0;i<4;i++,z++) block[i][j].val=(z<(int)v[1].size()?v[1][z]:0);
    }
}

void moveRight()
{
    for(int j=0;j<4;j++)
    {
        vector<int> v[2];
        for(int i=3;i>=0;i--)
        {
            if(block[i][j].val>0) v[0].push_back(block[i][j].val);
        }
        shortenVector(v);
        for(int i=3,z=0;i>=0;i--,z++) block[i][j].val=(z<(int)v[1].size()?v[1][z]:0);
    }
}
bool nextStep()
{
    int cnt=0;
//    block[0][0].val=1;
//    return 1;
    for(int i=0;i<4;i++) for(int j=0;j<4;j++) if(block[i][j].val==0) cnt++;
    if(cnt==0) return 0;
    int pos=rand()%cnt+1;
    int z=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(block[i][j].val==0)
            {
                z++;
                if(z==pos)
                {
                    block[i][j].val=1;
//                    cout<<i<<" "<<j<<" "<<block[i][j].val<<"\n";
                    return 1;
                }

            }
        }
    }
    return 0;
}


#endif // CLASS_H
