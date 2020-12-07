#include"vector2D.h"


/* Initialize vector. Defaults to zero */
Vector2D::Vector2D(double x0, double y0){
    v[0] = x0; v[1] = y0;
}

void Vector2D::show(void){
    std::cout << "(" << v[0]<< "," << v[1] << ")" << std::endl;
}

Vector2D Vector2D::operator=(Vector2D v2){
    v[0] = v2.v[0];
    v[1] = v2.v[1];

    return *this;
}

Vector2D Vector2D::operator+(Vector2D v2){
    Vector2D result(
        v[0]+v2.v[0],
        v[1]+v2.v[1]
    );

    return result;
}

Vector2D Vector2D::operator+=(Vector2D v2){
    *this = *this + v2;
    return *this;
}

Vector2D Vector2D::operator-(Vector2D v2){
    Vector2D result(
        v[0]-v2.v[0],
        v[1]-v2.v[1]
    );

    return result;
}

Vector2D Vector2D::operator-=(Vector2D v2){
    *this = *this - v2;
    return *this;
}

/* Vector times scalar */
Vector2D Vector2D::operator*(double a){
    Vector2D result(
        v[0]*a,
        v[1]*a
    );

    return result;
}

/* Vector times scalar */
Vector2D Vector2D::operator*=(double a){
    *this = (*this)*a;
    return *this;
}

/* Vector divided by scalar */
Vector2D Vector2D::operator/(double a){
    double inverse = 1.0/a;
    Vector2D result(
        v[0]*inverse,
        v[1]*inverse
    );

    return result;
}

/* Dot product */
double Vector2D::operator*(Vector2D v2){
    return v[0]*v2.v[0] + v[1]*v2.v[1];
}


Vector2D operator*(double a, Vector2D v){
    return v*a;
}

namespace vec2d{
    /* @return : unit vector with the same direction as v */
    Vector2D unit_vector(Vector2D v){
        return v/vec2d::norm(v);
    }

    /* @return vector norm squared */
    double norm2(Vector2D v){
        return v.v[0]*v.v[0] + v.v[1]*v.v[1];
    }
    /* @return vector norm */
    double norm(Vector2D v){
        return std::sqrt(v.v[0]*v.v[0] + v.v[1]*v.v[1]);
    }
}
