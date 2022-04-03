#include <iostream>
#include <cmath>
#include <stdio.h>
#include <windows.h>


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

int main(int argc, char** argv) {
    SetConsoleTitle("Donat");
    const int width = 200;
    const int height = 30 * 2;
    set_window(width, height);

    char buffer[width*height];

    const float aspect_char = 5.0f / 10.0f;
    const float aspect = aspect_char * (float)width / height;

    char gradient[] = ".:!/r(l1Z4H9W8$@";
    int gradientSize = 16;

//    getchar();

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD lpNumberOfCharsWritten;
    for (int angle = -360; angle < 360; ++angle){
        for (int i = 0; i < height; ++i){
            for (int j = 0; j < width; ++j){
                float x = (float) j / width * 2.0f - 1.0f;
                float y = (float) i / height * 2.0f - 1.0f;
                x *= aspect;
                x /= cosf(((float)angle / 360.0f) * 2.0f * (float)M_PI);
                char pixel = ' ';
                if (((x*x + y*y) < 0.5f) and ((x*x + y*y) > 0.25f)) {
                    float z = sqrtf(0.4f - x*x - y*y);
                    z = z * 2.5f * (float)gradientSize;
                    pixel = gradient[pack_in((int) fabs(floor(z)), 0, gradientSize-1)];
                }
                buffer[j + i*width] = pixel;
            }
        }
        int ret = WriteConsoleOutputCharacterA(handle, buffer, width*height, {0, 0}, &lpNumberOfCharsWritten);
        if (ret == 0){
            exit(0x100);
        }
        Sleep(12);

    }

    system("pause");
    return 0;
}
