#ifndef HEART_H
#define HEART_H

#include "CStar.h"

class CHeart : public CStar{
public:
    CHeart(){};
    virtual ~CHeart(){};

    virtual void update();

private:
    double m_angle = 5;
    int m_step = 100;

};
#endif // HEART_H

