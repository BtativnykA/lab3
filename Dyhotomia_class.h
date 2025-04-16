#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

class Dyhotomia {
private:
    double a, b;
    double epsilon;

public:
    Dyhotomia(double left, double right, double eps);
    double function(double x);
    double solve();
};

#endif