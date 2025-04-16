#include "Newton_class.h"
#include <cmath>
#include <iostream>

// Конструктор
Newton::Newton(double initialGuess, double eps) {
    x0 = initialGuess;
    epsilon = eps;
}

// Функція f(x) = 3sin(x) - sqrt(0.35x - 3.8)
double Newton::function(double x) {
    return 3 * sin(x) - sqrt(0.35 * x - 3.8);
}

//Похідна f'(x) = 3cos(x) - 0.35 / (2 * sqrt(0.35x - 3.8))
double Newton::derivative(double x) {
    return 3 * cos(x) - (0.35 / (2 * sqrt(0.35 * x - 3.8)));
}

// Метод Ньютона
double Newton::solve() {
    double x = x0;
    double h;
    int maxIterations = 1000;
    int iteration = 0;

    do {
        double deriv = derivative(x);

        if (deriv == 0.0) {
            std::cerr << "ПОМИЛКА: Похідна = 0. Метод Ньютона не може продовжити.\n";
            return NAN;
        }

        h = function(x) / deriv;
        x = x - h;
        iteration++;

        if (iteration >= maxIterations) {
            std::cerr << "ПОМИЛКА: Метод Ньютона не зійшовся за " << maxIterations << " ітерацій.\n";
            return NAN;
        }

    } while (std::abs(h) >= epsilon);

    return x;
}