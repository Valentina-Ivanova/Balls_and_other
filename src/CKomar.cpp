#include <iostream>
#include <cmath>
using namespace std;

#include "CKomar.h"

void CKomar :: update(){

     int x = rand()%30;
     int y = rand()%50;

     switch (rand()%2) {
         case 0: x *= -1;break;
         case 1: y *= -1;break;
     }

     m_rPosition.x += x;
     m_rPosition.y += y;
/*
    m_rPosition.x /= originX + cos(30)*radius;
//        m_rPosition.x %= WIDTH;

    m_rPosition.y /= originY + cos(30)*radius;
//        m_rPosition.y %= HEIGHT;

    if(m_rPosition.x==0 ){originX+=radius*2;}
*/
    return;
}


void CKomar :: init(SDL_Renderer* rRenderer, string file_name, int x, int y, int w_animation, int h_animation, double scale)
{
    CFly::init(rRenderer, file_name, x, y, w_animation, h_animation, scale);

    radius=rand()%100+40;
    originX=0;
    originY=HEIGHT/2;
}
