#include "Newton_class.h"
#include <cmath>
#include <iostream>

Newton::Newton(double initialGuess, double eps) {
    x0 = initialGuess;
    epsilon = eps;
}

double Newton::function(double x) {
    double underRoot = 0.35 * x;
    if (underRoot < 0) return NAN;
    return 3 * sin(x) - sqrt(underRoot) - 3.8;
}

double Newton::derivative(double x) {
    double underRoot = 0.35 * x;
    if (underRoot <= 0) return 0;

    return 3 * cos(x) - (0.35 * 0.5) / sqrt(underRoot);
}

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
            std::cerr << "ПОМИЛКА: Метод Ньютона не зійшовся.\n";
            return NAN;
        }

    } while (std::abs(h) >= epsilon);

    return x;
}