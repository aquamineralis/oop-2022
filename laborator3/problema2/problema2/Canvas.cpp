#include "Canvas.h"
#include <iostream>
#include <cstring>

Canvas::Canvas(int width, int height) {
    this->width  = width;
    this->height = height;
    Clear();
}

void Canvas::DrawSymmetricPoints(int x, int y, int i, int j, char ch) {
    SetPoint(i + x, j + y, ch);
    SetPoint(i + x, -j + y, ch);
    SetPoint(-i + x, j + y, ch);
    SetPoint(-i + x, -j + y, ch);
    SetPoint(j + x, i + y, ch);
    SetPoint(j + x, -i + y, ch);
    SetPoint(-j + x, i + y, ch);
    SetPoint(-j + x, -i + y, ch);
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    int i = 0;
    int j = ray;
    int d = 5 - 4 * ray;
    DrawSymmetricPoints(x, y, i, j, ch);

    while (i <= j) {
        if (d > 0) {
            d -= 8 * j;
            j--;
        }
        i++;
        d += 8 * i + 4;
        DrawSymmetricPoints(x, y, i, j, ch);
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    int i = 0;
    int j = ray;
    int d = 5 - 4 * ray;

    while (i <= j) {
        for (int xx = x - j; xx <= x + j; xx++) {
            SetPoint(xx, y - i, ch);
            SetPoint(xx, y + i, ch);
        }

        if (d > 0) {
            for (int xx = x - i; xx <= x + i; xx++) {
                SetPoint(xx, y - j, ch);
                SetPoint(xx, y + j, ch);
            }

            j--;
            d -= 8 * j;
        }

        i++;
        d += 8 * i + 4;
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    DrawLine(top, left, top, right, ch);
    DrawLine(bottom, left, bottom, right, ch);
    DrawLine(top, left, bottom, left, ch);
    DrawLine(top, right, bottom, right, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; i++)
        for (int j = left; j <= right; j++)
            SetPoint(i, j, ch);
}

void Canvas::SetPoint(int x, int y, char ch) {
    canvas[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx    = abs(x2 - x1);
    int sx    = x1 < x2 ? 1 : -1;
    int dy    = -abs(y2 - y1);
    int sy    = y1 < y2 ? 1 : -1;
    int error = dx + dy;
    while (true) {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2)
            break;
        if (2 * error >= dy) {
            if (x1 == x2)
                break;
            error += dy;
            x1 += sx;
        }
        if (2 * error <= dx) {
            if (y1 == y2)
                break;
            error += dx;
            y1 += sy;
        }
    }
}

void Canvas::Print() const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            std::cout << canvas[i][j];
        std::cout << '\n';
    }
}

void Canvas::Clear() {
    memset(canvas, '.', sizeof(canvas));
}
