#include <iostream>
#include <cmath>
using namespace std;

#include "CHeart.h"



void CHeart :: update(){

    if(m_step>0){
        m_rPosition.x += m_step*sin(m_angle);
        m_rPosition.y += m_step*cos(m_angle);

        m_angle+=5;
        m_step-=5;
    }

    return;
}


