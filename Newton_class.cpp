#include "Newton_class.h"
#include <cmath>
#include <iostream>

Newton::Newton(double initialGuess, double eps) {
    x0 = initialGuess;
    epsilon = eps;
}

// Нова функція
double Newton::function(double x) {
    return sqrt(3 * sin(x)) + 0.35 * x - 3.8;
}

// Похідна нової функції
double Newton::derivative(double x) {
    double cosx = cos(x);
    double sinx = sin(x);

    // похідна: (3*cos(x)) / (2*sqrt(3*sin(x))) + 0.35
    if (sinx <= 0) return 0; // щоб не було кореня з від’ємного

    return (3 * cosx) / (2 * sqrt(3 * sinx)) + 0.35;
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