#include <iostream>
#include <cmath>
using namespace std;

#include "CStar.h"



void CStar :: update(){

    m_rPosition.x += m_step*sin(m_angle);
    m_rPosition.y += m_step*cos(m_angle);

    m_angle+=5;
    m_step+=5;
    return;
}


void CStar :: init(SDL_Renderer* rRenderer, string file_name, int x, int y, int w_animation, int h_animation, double scale)
{
            CFly::init(rRenderer, file_name, x, y, w_animation, h_animation, scale);


}
