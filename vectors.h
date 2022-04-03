#pragma once
#include <iostream>


struct vector3d{
    float x, y, z;

    vector3d(float setup = 0.0f); // TODO: should it be explicit?
    vector3d(float x, float y, float z);

    void normalize();

    friend vector3d operator+(vector3d left, vector3d right);
    friend vector3d operator-(vector3d left, vector3d right);
    friend vector3d operator*(vector3d left, vector3d right);
    friend std::ostream& operator<<(std::ostream& , vector3d vec);


};

float dot(vector3d left, vector3d right);

vector3d scale(vector3d left, float k);

struct vector2d{
    float x, y;

    vector2d(float setup = 0.0f); // TODO: should it be explicit?
    vector2d(float x, float y);

    void normalize();

    friend vector2d operator+(vector2d left, vector2d right);
    friend vector2d operator-(vector2d left, vector2d right);
    friend vector2d operator*(vector2d left, vector2d right);
    friend std::ostream& operator<<(std::ostream& , vector2d vec);


};

float dot(vector2d left, vector2d right);

vector2d scale(vector2d left, float k);