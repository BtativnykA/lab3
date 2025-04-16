#ifndef NEWTON_CLASS_H
#define NEWTON_CLASS_H

class Newton {
private:
    double x0;        // початкове наближення
    double epsilon;   // точність

public:
    Newton(double initialGuess, double eps);  // конструктор

    double function(double x);       // функція f(x)
    double derivative(double x);     // похідна f'(x)
    double solve();                  // метод Ньютона для пошуку кореня
};

#endif