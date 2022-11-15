#pragma once

#ifndef OPENGLENGINE_RECT_H
#define OPENGLENGINE_RECT_H

#include "Utilities.h"

class Rect {
public:
    Rect(vec2* pos, vec2* size) : Rect(pos->x, pos->y, size->x, size->y){}
    Rect(float x, float y, float sizeX, float sizeY){
        this->x = x;
        this->y = y;
        this->sizeX = sizeX;
        this->sizeY = sizeY;
    }

    float x, y, sizeX, sizeY;

    vec2 topLeft(){
        return vec2(x, y + sizeY);
    }

    vec2 topRight(){
        return vec2(x + sizeX, y + sizeY);
    }

    vec2 bottomLeft(){
        return vec2(x, y);
    }

    vec2 bottomRight(){
        return vec2(x + sizeX, y);
    }

};


#endif //OPENGLENGINE_RECT_H
