#pragma once

class Canvas {
  private:
    char canvas[101][101];
    int width;
    int height;

  public:
    Canvas(int width, int height);

    void DrawSymmetricPoints(int x, int y, int i, int j, char ch);
    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);

    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);

    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);

    void Print() const; // shows what was printed
    void Clear();       // clears the canvas
};