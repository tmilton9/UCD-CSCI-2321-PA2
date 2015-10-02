//
//  Point.h
//  UCD-CSCI-2321-PA2
//
//  Created by Travis Milton on 9/29/15.
//  Copyright © 2015 Travis Milton. All rights reserved.
//

#ifndef TRAVIS_MILTON_PA2_POINT_H
#define TRAVIS_MILTON_PA2_POINT_H

#include <iostream>


namespace Clustering {

    class Point {

    private:
        int dim;  //sets number of dimentions
        double *values;
    public:
        // Constructors
        Point(int);                      // default constructor

        Point(int, double *); // array inputed with dimentionallity

        Point(const Point &);
        Point &operator =(const Point*);
        // Destructor
        ~Point();
        //static Point origin;

        // Mutator methods
        void setValue();


        // Accessor methods
        double getValue()const;
        int getDims() const { return dim; }
        double &operator[](int index) const { return values[index - 1]; } // TODO out-of-bds?
        void disPnt();
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

        friend std::ostream& operator <<(std::ostream&, const Point &lhs);
        friend std::istream& operator >>(std::istream&,Point &lhs);
        //friend std::ostream& operator <<(std::ostream &, const Cluster &);
    };
}

#endif //TRAVIS_MILTON_PA2_POINT_H
