#include <iostream>
using namespace std;

#include "CFly.h"


//CFly :: CFly(){
//
//
//}
//
//CFly  :: ~CFly(){
//
//
//
//}


void CFly :: init(SDL_Renderer* pRenderer, string file_name, int x, int y, int w_animation, int h_animation, double scale){
    m_pRenderer = pRenderer;

    SDL_Surface* pTmp = NULL;

    pTmp = SDL_LoadBMP(file_name.c_str());
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTmp);
    SDL_FreeSurface(pTmp);

    m_rAnimation.x = 0;
    m_rAnimation.y = 0;
    m_rAnimation.w = w_animation;
    m_rAnimation.h = h_animation;

    m_rPosition.x=x;
    m_rPosition.y=y;
    m_rPosition.w= m_rAnimation.w * scale;
    m_rPosition.h= m_rAnimation.h * scale;

    m_nSpeed = rand() % 20;
}

void CFly :: update(){
        m_rPosition.x += m_nSpeed;
        m_rPosition.x %= WIDTH;

        m_rPosition.y += m_nSpeed;
        m_rPosition.y %= HEIGHT;
    return;
}

void CFly :: draw(){
SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_rAnimation, &m_rPosition, NULL, NULL, SDL_FLIP_NONE);
}
