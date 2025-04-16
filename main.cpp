#include <iostream>
#include <cmath>
#include "Dyhotomia_class.h"
#include "Newton_class.h"

int main() {
    double left = 11.0;           // Ліва межа
    double right = 13.0;          // Права межа
    double epsilon = 0.001;       // Точність
    double initialGuess = 12.0;   // Старт для методу Ньютона (усередині проміжку)

    //  Метод дихотомії
    Dyhotomia method1(left, right, epsilon);
    double result1 = method1.solve();
    std::cout << "Розв'язок рівняння методом ділення навпіл: " << result1 << std::endl;

    //  Метод Ньютона
    Newton method2(initialGuess, epsilon);
    double result2 = method2.solve();

    if (std::isnan(result2)) {
        std::cout << "Метод Ньютона не зміг знайти розв’язок." << std::endl;
    } else {
        std::cout << "Розв'язок рівняння методом Ньютона: " << result2 << std::endl;
    }

    return 0;
}