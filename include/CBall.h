#ifndef CBALL_H
#define CBALL_H

#include <CMovingObject.h>


class CBall : public CMovingObject
{
    public:
        CBall();
        virtual ~CBall();

        virtual void init(SDL_Renderer* pRenderer, string file_name, int x, int y, int w_animation, int h_animation, double scale);
        virtual void update();
        virtual void draw();

    protected:
        int m_nDir = 1;
        int m_nSpeed = 10;

    private:
};

#endif // CBALL_H
