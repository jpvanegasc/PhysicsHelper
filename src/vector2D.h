#ifndef __VECTOR2D_H
#define __VECTOR2D_H
/**
 * 2D Vector helper class.
 * Author : Juan Vanegas. Git: jpvanegasc
 */
#include <iostream>
#include <cmath>

class Vector2D;

Vector2D operator* (double a, Vector2D v);

namespace vec2d{
    Vector2D unit_vector(Vector2D v);
    double norm2(Vector2D v);
    double norm(Vector2D v);
}

class Vector2D{
    double v[2];
    public:
        Vector2D(double =0.0, double =0.0);
        void load(double x0, double y0){v[0] = x0; v[1] = y0;}
        void show(void);
        /* @return x component*/
        double x(void){return v[0];};
        /* @return y component*/
        double y(void){return v[1];};
        /* @return nth component*/
        double & operator[](int n){return v[n];};
        Vector2D operator= (Vector2D v2);
        Vector2D operator+ (Vector2D v2);
        Vector2D operator+=(Vector2D v2);
        Vector2D operator- (Vector2D v2);
        Vector2D operator-=(Vector2D v2);
        Vector2D operator* (double a);
        Vector2D operator*=(double a);
        Vector2D operator/ (double a);
        double operator* (Vector2D v2);

        friend Vector2D operator* (double a, Vector2D v);
        friend Vector2D vec2d::unit_vector(Vector2D v);
        friend double vec2d::norm2(Vector2D v);
        friend double vec2d::norm(Vector2D v);
};

#endif
