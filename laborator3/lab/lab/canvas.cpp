#include "canvas.h"
#include <cstdio>
#include <cstring>
#include <cstdarg>

Canvas::Canvas(int lines, int columns) {
    this->lines   = lines;
    this->columns = columns;
    clear();
}

void Canvas::set_pixel(int x, int y, char value) {
    canvas[x][y] = value;
}

void Canvas::set_pixels(int count, ...) {
    /*int* p = &count;
    int x, y;
    char value;
    for (int i = 0; i < count; i++) {
        p = p + 2;
        x = *p;
        p = p + 2;
        y = *p;
        p = p + 2;
        value = *p;
        set_pixel(x, y, value);
    }*/

    int x, y;
    char value;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        x     = va_arg(args, int);
        y     = va_arg(args, int);
        value = va_arg(args, char);
        set_pixel(x, y, value);
    }
    va_end(args);
}

void Canvas::clear() {
    memset(canvas, ' ', sizeof(canvas));
}

void Canvas::print() const {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}
