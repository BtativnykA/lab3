#include "Dyhotomia_class.h"
#include <cmath>

Dyhotomia::Dyhotomia(double left, double right, double eps) {
    a = left;
    b = right;
    epsilon = eps;
}

double Dyhotomia::function(double x) {
    double underRoot = 0.35 * x;
    if (underRoot < 0) return NAN;
    return 3 * sin(x) - sqrt(underRoot) - 3.8;
}

double Dyhotomia::solve() {
    double mid;
    while ((b - a) >= epsilon) {
        mid = (a + b) / 2;

        if (std::isnan(function(mid))) {
            return NAN;  // Якщо корінь з від’ємного
        }

        if (function(mid) == 0.0)
            break;
        else if (function(mid) * function(a) < 0)
            b = mid;
        else
            a = mid;
    }

    return (a + b) / 2;
}