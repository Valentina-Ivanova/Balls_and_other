#ifndef STAR_H
#define STAR_H

#include "CFly.h"

class CStar : public CFly{
public:
    CStar(){};
    virtual ~CStar(){};

    virtual void update();
    virtual void init(SDL_Renderer* rRenderer, string file_name, int x, int y, int w_animation, int h_animation, double scale);

private:
    int radius;
    int originX;
    int originY;

};
#endif // STAR_H

