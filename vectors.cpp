#include "vectors.h"
#include <math.h>

vector3d::vector3d(float setup) : x(setup), y(setup), z(setup) { }

vector3d::vector3d(float x, float y, float z) : x(x), y(y), z(z) { }

std::ostream &operator<<(std::ostream& stream, vector3d vec) {
    stream << vec.x << " " << vec.y << " " << vec.z;
    return stream;
}

vector3d operator+(vector3d left, vector3d right) {
    return {left.x + right.x, left.y + right.y, left.z+ right.z};
}

vector3d operator-(vector3d left, vector3d right) {
    return {left.x - right.x, left.y - right.y, left.z - right.z};
}

vector3d operator*(vector3d left, vector3d right) {
    return {left.x * right.x, left.y * right.y, left.z * right.z};
}

void vector3d::normalize() {
    float len = sqrtf(dot(*this, *this));
    x /= len;
    y /= len;
    z /= len;
}


vector2d::vector2d(float setup) : x(setup), y(setup) { }

vector2d::vector2d(float x, float y) : x(x), y(y) {}

vector2d operator+(vector2d left, vector2d right) {
    return {left.x + right.x, left.y + right.y};
}

vector2d operator-(vector2d left, vector2d right) {
    return {left.x - right.x, left.y - right.y};
}

vector2d operator*(vector2d left, vector2d right) {
    return {left.x * right.x, left.y * right.y};
}

std::ostream &operator<<(std::ostream& stream, vector2d vec) {
    stream << vec.x << " " << vec.y;
    return stream;
}

void vector2d::normalize() {
    float len = sqrtf(dot(*this, *this));
    x /= len;
    y /= len;
}


float dot(vector3d left, vector3d right){
    return (left.x * right.x) + (left.y * right.y) + (left.z * right.z);
}

vector3d scale(vector3d left, float k){
    return {left.x * k, left.y * k, left.z * k};
}

float dot(vector2d left, vector2d right){
    return (left.x * right.x) + (left.y * right.y);
}

vector2d scale(vector2d left, float k){
    return {left.x * k, left.y * k};
}