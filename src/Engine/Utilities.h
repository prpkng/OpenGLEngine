#pragma once

#ifndef OPENGLENGINE_UTILITIES_H
#define OPENGLENGINE_UTILITIES_H

#include <cmath>
#include <string>

using namespace std;

class Utilities{
public:
    static double Lerp(double a, double b, double t);

    static float Lerp(float a, float b, float t);
};

struct vec2;
typedef struct vec2i{
public:
    vec2i() : vec2i(0, 0) {}
    vec2i(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int x;
    int y;

    static vec2i* zero(){
        return new vec2i(0, 0);
    }
    static vec2i* one(){
        return new vec2i(1, 1);
    }
    static vec2i* up(){
        return new vec2i(0, 1);
    }
    static vec2i* right(){
        return new vec2i(1, 0);
    }
    static vec2i* left(){
        return new vec2i(-1, 0);
    }
    static vec2i* down(){
        return new vec2i(0, -1);
    }

    operator string() const;

} vec2i;

typedef struct vec2{
public:
    vec2() : vec2(0, 0){}
    vec2(float x, float y) {
        this->x = x;
        this->y = y;
    }
    float x;
    float y;


    static vec2* Lerp(vec2 a, vec2 b, float t){
        return new vec2(Utilities::Lerp(a.x, b.x, t), Utilities::Lerp(a.y, b.y, t));
    }

    static vec2* zero(){
        return new vec2(0, 0);
    }
    static vec2* one(){
        return new vec2(1, 1);
    }
    static vec2* up(){
        return new vec2(0, 1);
    }
    static vec2* right(){
        return new vec2(1, 0);
    }
    static vec2* left(){
        return new vec2(-1, 0);
    }
    static vec2* down(){
        return new vec2(0, -1);
    }



    operator string() const;

} vec2;

typedef struct vec3{
public:
    vec3() : vec3(0, 0, 0){}
    vec3(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    float x;
    float y;
    float z;


    static vec3* Lerp(vec3 a, vec3 b, float t){
        return new vec3(Utilities::Lerp(a.x, b.x, t),
                        Utilities::Lerp(a.y, b.y, t),
                        Utilities::Lerp(a.x, b.x, t));
    }

    static vec3* zero(){
        return new vec3(0, 0, 0);
    }
    static vec3* one(){
        return new vec3(1, 1, 1);
    }
    static vec3* forward(){
        return new vec3(0, 0, 1);
    }
    static vec3* back(){
        return new vec3(0, 0, -1);
    }
    static vec3* up(){
        return new vec3(0, 1, 0);
    }
    static vec3* right(){
        return new vec3(1, 0, 0);
    }
    static vec3* left(){
        return new vec3(-1, 0, 0);
    }
    static vec3* down(){
        return new vec3(0, -1, 0);
    }

    operator string() const;

} vec3;

typedef struct color{
public:
    color() : color(1.0f, 1.0f, 1.0f, 1.0f) {}
    color(float r, float g, float b) : color(r, g, b, 1.0f) {}
    color(float r, float g, float b, float a){
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }

    float r;
    float g;
    float b;
    float a;

    static color* white(){
        return new color(1,1,1);
    }
    static color* red(){
        return new color(1,0,0);
    }
    static color* blue(){
        return new color(0,0,1);
    }
    static color* green(){
        return new color(0,1,0);
    }
    static color* pink(){
        return new color(1,0,1);
    }
    static color* purple(){
        return new color(0.5f,0,1);
    }
    static color* lime(){
        return new color(0.5f,1,0);
    }


}color;
#endif //OPENGLENGINE_UTILITIES_H
