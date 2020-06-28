#include <iostream>
using namespace std;


#include "CBall.h"

CBall::CBall()
{
    //ctor
}

CBall::~CBall()
{
    //dtor
}


void CBall::init(SDL_Renderer* pRenderer, string file_name, int x, int y, int w_animation, int h_animation, double scale) {

    ///cout << "init ball " << file_name << " " << endl;
    m_pRenderer = pRenderer;

    SDL_Surface* pTmp = NULL;

    pTmp = SDL_LoadBMP(file_name.c_str());
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTmp);
    SDL_SetTextureColorMod(m_pTexture, x*25, 255-y*2, x/5 + y*3     );
    SDL_FreeSurface(pTmp);

    m_rPosition.x = x + rand()%20;
    m_rPosition.y = y + rand()%30;
    m_rPosition.h = 30 + rand()%10;
    m_rPosition.w = m_rPosition.h;

    /// to use scale

    m_nSpeed = rand() % 30;

    return;
}

void CBall::update(){
    ///cout << "update ball" << endl;
    m_rPosition.y += m_nSpeed * m_nDir;

    if ((m_rPosition.y < 0) || (m_rPosition.y > HEIGHT - m_rPosition.h*4)) {
        m_nDir *= -1;
    }

    return;
}

void CBall::draw(){
    ///cout << "draw ball" << endl;
    SDL_RenderCopy(m_pRenderer, m_pTexture, NULL, &m_rPosition);
}
