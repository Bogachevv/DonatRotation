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

    char gradient[] = " .:!/r(l1Z4H9W8$@";
    int gradientSize = 17;

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD lpNumberOfCharsWritten;


    system("pause");
    return 0;
}
