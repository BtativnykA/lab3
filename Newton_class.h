#ifndef NEWTON_CLASS_H
#define NEWTON_CLASS_H

class Newton {
private:
    double x0;
    double epsilon;

public:
    Newton(double initialGuess, double eps);
    double function(double x);     // нова функція f(x)
    double derivative(double x);   // її похідна f'(x)
    double solve();
};

#endif