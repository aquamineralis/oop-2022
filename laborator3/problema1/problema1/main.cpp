#include <iostream>
#include "Math.h"

int main() {
    int x1 = 1, y1 = 2, z1 = 3;
    std::cout << x1 << " + " << y1 << " = " << Math::Add(x1, y1) << '\n';
    std::cout << x1 << " + " << y1 << " + " << z1 << " = " << Math::Add(x1, y1, z1) << '\n';
    std::cout << x1 << " * " << y1 << " = " << Math::Mul(x1, y1) << '\n';
    std::cout << x1 << " * " << y1 << " * " << z1 << " = " << Math::Mul(x1, y1, z1) << "\n\n";

    double x2 = 1.255, y2 = 2.79, z2 = 3.9805;
    std::cout << x2 << " + " << y2 << " = " << Math::Add(x2, y2) << '\n';
    std::cout << x2 << " + " << y2 << " + " << z2 << " = " << Math::Add(x2, y2, z2) << '\n';
    std::cout << x2 << " * " << y2 << " = " << Math::Mul(x2, y2) << '\n';
    std::cout << x2 << " * " << y2 << " * " << z2 << " = " << Math::Mul(x2, y2, z2) << "\n\n";

    std::cout << "1 + 2 + 3 + 4 + 5 = " << Math::Add(5, 1, 2, 3, 4, 5) << "\n\n";

    char first_name[] = "Ana", last_name[] = "Popescu";
    std::cout << Math::Add(first_name, last_name) << '\n';
    return 0;
}