//
// Created by Travis Milton on 9/13/15.
//

#ifndef TRAVIS_MILTON_PA2_POINT_H
#define TRAVIS_MILTON_PA2_POINT_H

#include <iostream>
namespace Clustering{

class Point {

private:
    int dim;  //sets number of dimentions
    double *values;
public:
    // Constructors
    Point(int);                      // default constructor

    Point(int, double *); // array inputed with dimentionallity

    Point(const Point &);
    Point &operator =(const Point&);
    // Destructor
    ~Point();
    static Point origin;

    // Mutator methods
    void setValue(int, double);


    // Accessor methods
    double getValue()const;
    int getDims() const { return dim; }
    double &operator[](int index) const { return values[index - 1]; } // TODO out-of-bds?

    // Member function
    double distanceTo(const Point &)const;

    // overloads

    Point &operator *=(double d);
    Point &operator /=(double d);
    const Point operator *(double d);
    const Point operator /(double d);

    //friends
    friend bool operator ==(const Point& lhs, const Point&rhs);
    friend bool operator !=(const Point& lhs,const Point&rhs);
    friend Point &operator +=(Point &lhs , const Point &rhs);
    friend Point &operator -=(Point &lhs , const Point &rhs);
    friend const Point operator -(Point &lhs, const Point &rhs);
    friend const Point operator+(Point &lhs, const Point &rhs);

    friend bool operator <(Point &lhs, const Point &rhs);
    friend bool operator >(Point &lhs, const Point &rhs);
    friend bool operator <=(Point &lhs, const Point &rhs);
    friend bool operator >=(Point &lhs, const Point &rhs);

    friend std::ostream operator <<(std::ostream&, const Point &lhs);
    friend std::istream operator >>(std::istream&,Point &lhs);
};
}

#endif //TRAVIS_MILTON_PA2_POINT_H
