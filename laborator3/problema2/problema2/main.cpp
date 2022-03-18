#include <iostream>
#include "Canvas.h"

int main() {
    int width = 15, height = 16;
    Canvas canvas(width, height);
    canvas.DrawRect(0, 0, width - 1, height - 1, '*');
    canvas.SetPoint(13, 2, '#');
    canvas.DrawLine(10, 3, 14, 5, 'L');
    canvas.DrawRect(2, 1, 5, 3, 'R');
    canvas.FillRect(10, 2, 13, 5, 'F');
    canvas.DrawCircle(7, 7, 2, 'C');
    canvas.FillCircle(12, 10, 2, 'F');
    canvas.Print();

    /*
    ***************
    *.RRRR........*
    *.R..R....FFFF*
    *.RRRR....FFFF*
    *.........FFFF*
    *.....CCC.FFFF*
    *....C...C....*
    *....C...C....*
    *....C...C....*
    *.....CCC.....*
    *..L.....FFF..*
    *...L...FFFFF.*
    *....L..FFFFF.*
    *.#..L..FFFFF.*
    *........FFF..*
    ***************
    */
    return 0;
}