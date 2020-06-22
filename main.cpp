#include <iostream>
using namespace std;

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <vector>
using namespace std;

#include "CBall.h"
#include "CFly.h"
#include "CKomar.h"



int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* pWindow = NULL;
    SDL_Renderer* pRendered = NULL;
    SDL_Surface* pTmp = NULL;
    SDL_Texture* pBGR = NULL;

    /// create window + rendered
    pWindow = SDL_CreateWindow("Moving Object", 10, 20, WIDTH, HEIGHT, 0);
    pRendered = SDL_CreateRenderer(pWindow, 0, SDL_RENDERER_ACCELERATED);

    /// load background image
    pTmp = SDL_LoadBMP("img\\background_room.bmp");
    pBGR = SDL_CreateTextureFromSurface(pRendered, pTmp);
    SDL_FreeSurface(pTmp);

    /// all moving objects
    CMovingObject* pNewObject = NULL;
    vector<CMovingObject*> vAll;


    for (int i = 0; i < 10; i++) {
        pNewObject = new CBall();
        pNewObject->init(pRendered, "img\\ball_small.bmp", i*50, i*50, 30, 30, i);
        vAll.push_back(pNewObject);
    }
//     pNewObject = NULL;


    for (int i = 0; i < 28; i++) {
        pNewObject = new CFly();
        pNewObject->init(pRendered, "img\\FlyTr.bmp", i*100, i*100, 34, 30, 1);
        vAll.push_back(pNewObject);
    }

    for (int i = 0; i < 6; i++) {
        pNewObject = new CKomar();
        pNewObject->init(pRendered, "img\\komar.bmp", i*20+500, i*20+500, 200, 142, 0.3);
        vAll.push_back(pNewObject);
    }


    int sz=vAll.size();
    while (1) {
        /// clear the scene
        SDL_RenderClear(pRendered);

        /// copy all images - build the scene
        SDL_RenderCopy(pRendered, pBGR, NULL, NULL);
        /// all other images come here

        for (int i = 0; i < sz; i++) {
            vAll[i]->draw();

        }

        /// show the scene
        SDL_RenderPresent(pRendered);

        /// move all object
        for (int i = 0; i < sz; i++) {
            vAll[i]->update();
        }

        SDL_Delay(100);
    }


    ///SDL_DestroyTexture(pMovingObject);
    for (int i = 0; i < sz; i++) {
           /// Destroy textures!!!
    }
    SDL_DestroyTexture(pBGR);
    SDL_DestroyRenderer(pRendered);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();

    return 0;
}
