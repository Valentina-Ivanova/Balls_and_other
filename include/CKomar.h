#ifndef KMR_H
#define KMR_H

#include "CFly.h"

class CKomar : public CFly{
public:
    CKomar(){};
    virtual ~CKomar(){};

    virtual void update();
    virtual void init(SDL_Renderer* rRenderer, string file_name, int x, int y, int w_animation, int h_animation, double scale);

private:
    int radius;
    int originX;
    int originY;

};
#endif // KMR_H
