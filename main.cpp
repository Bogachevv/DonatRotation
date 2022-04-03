#include <iostream>
#include <cmath>
#include <stdio.h>
#include <windows.h>

#include "vectors.h"


using namespace std;

void set_window(int width, int height){
    _COORD coord;
    coord.X = width;
    coord.Y = height;
    _SMALL_RECT rect;
    rect.Top = 0;
    rect.Bottom = height - 1;
    rect.Left = 0;
    rect.Right = width - 1;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(handle, coord);
    SetConsoleWindowInfo(handle, TRUE, &rect);
}

int pack_in(int val, int min_v, int max_v){
    return max(min(val, max_v), min_v);
}

vector2d sphere_intersect(vector3d ray_origin, vector3d direction, vector3d sphere, float rad){
    vector3d oc = ray_origin - sphere;
    float b = dot(oc, direction );
    float c = dot(oc, oc) - rad*rad;
    float h = b*b - c;
    if (h < 0.0f) return {-1.0f};
    h = sqrtf(h);
    return {-b - h, -b + h};
}

bool castRay(vector3d ray_origin, vector3d ray_direction){
    const float R = 1.0f;
    const vector3d sphere_center = {0.0f};
    vector2d intersect = sphere_intersect(ray_origin, ray_direction, sphere_center , R);
    return intersect.x > 0.0f;
}


int main(int argc, char** argv) {
    SetConsoleTitle("Donat");
    const int width = 200;
    const int height = 30 * 2;
    set_window(width, height);

    char buffer[width*height];

    const float aspect_char = 5.0f / 10.0f;
    const float aspect = aspect_char * (float)width / height;

    char gradient[] = " .:!/r(l1Z4H9W8$@";
    int gradientSize = 17;

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD lpNumberOfCharsWritten;

    vector3d ray_origin = {-5, 0, 0};

    for (int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){
            vector2d uv = {(float)j / width - 0.5f, (float)i / height - 0.5f};
            uv.x *= aspect;
            vector3d ray_direction = vector3d(1.0, uv.x, uv.y);
            ray_direction.normalize();
            char pixel = ' ';
            if (castRay(ray_origin, ray_direction)) pixel = '@';
            buffer[j + i*width] = pixel;
        }
    }

    int ret = WriteConsoleOutputCharacterA(handle, buffer, width*height, {0, 0}, &lpNumberOfCharsWritten);
    if (ret == 0){
        exit(0x100);
    }




    system("pause");
    return 0;
}
