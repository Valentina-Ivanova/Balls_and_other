#ifndef CMOVINGOBJECT_H
#define CMOVINGOBJECT_H

#include <string>
using namespace std;

#include <SDL2/SDL.h>

const int WIDTH = 1200;
const int HEIGHT = 800;

class CMovingObject
{
    public:
        CMovingObject(){};
        virtual ~CMovingObject(){};

        virtual void init(SDL_Renderer* rRenderer, string file_name, int x, int y, int w_animation, int h_animation, double scale) = 0;
        virtual void update() = 0;
        virtual void draw() = 0;

    protected:
        SDL_Renderer*   m_pRenderer;
        SDL_Texture*    m_pTexture;
        SDL_Rect        m_rPosition;
        SDL_Rect        m_rAnimation;
};

#endif // CMOVINGOBJECT_H
