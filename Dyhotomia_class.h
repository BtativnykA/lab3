#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

class Dyhotomia {
private:
    double a, b;       // межі проміжку
    double epsilon;    // точність

public:
    Dyhotomia(double left, double right, double eps); // конструктор

    double function(double x);  // функція f(x)
    double solve();             // метод дихотомії
};

#endif