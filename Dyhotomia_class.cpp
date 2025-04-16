#include "Dyhotomia_class.h"
#include <cmath>

// 🔸 Конструктор
Dyhotomia::Dyhotomia(double left, double right, double eps) {
    a = left;
    b = right;
    epsilon = eps;
}

// 🔸 Функція f(x) = 3sin(x) - sqrt(0.35x - 3.8)
double Dyhotomia::function(double x) {
    return 3 * sin(x) - sqrt(0.35 * x - 3.8);
}

// 🔸 Метод дихотомії
double Dyhotomia::solve() {
    double mid;
    while ((b - a) >= epsilon) {
        mid = (a + b) / 2;

        if (function(mid) == 0.0)
            break;
        else if (function(mid) * function(a) < 0)
            b = mid;
        else
            a = mid;
    }

    return (a + b) / 2;
}