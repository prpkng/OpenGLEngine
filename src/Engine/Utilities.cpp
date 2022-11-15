#include "Utilities.h"


double Utilities::Lerp(double a, double b, double t) {
    return a + (b - a) * t;
}

float Utilities::Lerp(float a, float b, float t){
    return a + (b - a) * t;
}


vec2i::operator string() const {
    return "( " + to_string(x) + ", " + to_string(y) + " )";
}

vec2::operator string() const {
    return "( " + to_string(x) + ", " + to_string(y) + " )";
}