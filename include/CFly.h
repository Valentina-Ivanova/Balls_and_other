#ifndef CFL_H
#define CFL_H

#include "CMovingObject.h"

class CFly : public CMovingObject{
public:
    CFly(){};
    virtual ~CFly(){};

    virtual void init(SDL_Renderer* rRenderer, string file_name, int x, int y, int w_animation, int h_animation, double scale);
    virtual void update();
    virtual void draw();

protected:
    int m_nSpeed;

};
#endif // CFL_H
