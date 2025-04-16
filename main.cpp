#include <iostream>
#include <cmath>
#include "Dyhotomia_class.h"
#include "Newton_class.h"

int main() {
    double left = 2.0;          // ліва межа
    double right = 3.0;         // права межа
    double epsilon = 0.000001;     // точність
    double initialGuess = 2.5;  // початкове наближення для Ньютона

    // Метод дихотомії
    Dyhotomia method1(left, right, epsilon);
    double result1 = method1.solve();
    std::cout << "Розв'язок рівняння методом ділення навпіл: " << result1 << std::endl;

    // Метод Ньютона
    Newton method2(initialGuess, epsilon);
    double result2 = method2.solve();

    if (std::isnan(result2)) {
        std::cout << "Метод Ньютона не зміг знайти розв’язок." << std::endl;
    } else {
        std::cout << "Розв'язок рівняння методом Ньютона: " << result2 << std::endl;
    }

    return 0;
}