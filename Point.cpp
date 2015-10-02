//
//  Point.cpp
//  UCD-CSCI-2321-PA2
//
//  Created by Travis Milton on 9/29/15.
//  Copyright © 2015 Travis Milton. All rights reserved.
//

#include "point.h"
#include "cluster.h"

#include <cmath>


namespace Clustering {

    //Default constructor
    Point::Point(int dimensions) {
        if (dimensions == 0)                //TODO throw exception
            dimensions = 2;

        dim = dimensions;
        values = new double[dim];
    }

    Point::Point(int size, double * other) {

        values = new double[size];

        for (int i = 0; i < size; i++)
            values [i]= other[i];
    }
    // Copy Constructor

    Point::Point(const Point &other) {
        dim = other.dim;
        values = new double[dim];
        for (int i = 0; i < dim; i++) {
            values[i] = other.values[i];
        }
    }
    // Destructor
    Point::~Point() {

        delete[] values;
    }

    // Mutator methods
    // Change the values of private member variables

    void Point::setValue() {
        double temp;
        //dim = x;
        for (int i = 0; i < dim; ++i) {
            std::cout << "Enter a value: ";
            std::cin >> temp;
            values[i] = temp;
        }


    }

    // Accessors
    // Return the current values of private member variables

    double Point::getValue() const {


        return *values;
    }
    void Point::disPnt(){
        for (int i =0; i< dim; i++)
        {
            std::cout << values[i] << ", ";
        }
    }

    //Member function
    double Point::distanceTo(const Point &Other) const {
        double sum = 0.0;

        if (Other.dim == dim)
            sum = 0;
        for (int i = 0; i < dim; ++i) {
            double diff = values[i] - Other.values[i];
            sum += diff * diff;
        }
        return sqrt(sum);
    }

    //overloaded operators

    Point &Point::operator=(const Point *Other) {
        if (this == Other) {
            return *this;
        } else {
            if (values != nullptr) {
                //for (int i = 0; i < dim; i++)
                //  delete[] values[i];
                delete[] values;
            }
            this->dim = Other->dim;

            values = new double [dim];
            for (int i = 0; i < dim; i++)
                this->values = nullptr;
            for (int i = 0; i < dim; i++)
                values[i] = Other->values[i];
        }
        return *this;
    }

    Point &Point::operator*=(double d) {
        for (int i = 0; i < dim; ++i) {
            values[i] *= d;
        }
        return *this;
    }

    Point &Point::operator/=(double d) {
        for (int i = 0; i < dim; ++i) {
            values[i] /= d;
        }
        return *this;
    }

    const Point Point::operator/(double d) {
        return Point(dim) *= d;
    }

    const Point Point::operator*(double d) {
        return Point(dim) /= d;
    }

    Point &operator-=(Point &lhs, const Point &rhs) {
        if (&lhs == &rhs)
            return lhs /= 2;
        else if (lhs.dim == rhs.dim) {
            for (int i = 0; i < lhs.dim; ++i) {
                lhs.values[i] -= rhs.values[i];
            }
            return lhs;
        }
        else {
            std::cout << "Unable to compute, points of different dimentions\n";
            return lhs;//TODO check how to error this
        }

    }

    Point &operator+=(Point &lhs, const Point &rhs) {//TODO check syntax
        if (&lhs == &rhs)
            return lhs *= 2;
        else if (lhs.dim == rhs.dim) {
            for (int i = 0; i < lhs.dim; ++i) {
                lhs.values[i] += rhs.values[i];
            }
            return lhs;
        }
        else {
            std::cout << "Unable to compute, points of different dimentions\n";
            return lhs;//TODO check how to error this
        }

    }

    const Point operator-(Point &lhs, const Point &rhs) {
        return lhs -= rhs;
    }

    const Point operator+(Point &lhs, const Point &rhs) {
        return lhs += rhs;
    }

    std::ostream &operator<<(std::ostream &os, const Point &lhs) {

        for (int i = 0; i < lhs.dim; ++i) {
            os  << lhs.values[i] << ", ";
        }
        os << "\n";
        return os;
    }

    std::istream &operator>>(std::istream &is, Point &lhs) {

        for (int i = 0; i < lhs.dim; ++i) {
            std::cout << "Enter  numeric value ";
            is >> lhs.values[i];
        }
        return is;

    }

    bool operator<(Point &lhs, const Point &rhs) {
        bool ifTrue = false;
        if (lhs.dim == rhs.dim) {

            for (int i = 0; i < lhs.dim; ++i) {
                if (lhs.values[i] > rhs.values[i])
                    return false;
                else
                    ifTrue = true;
            }
            return ifTrue;
        }
        else {
            std::cout << "Unable to compute, points of different dimentions\n";
            return false;
        }
    }


    bool operator>(Point &lhs, const Point &rhs) {
        bool ifTrue = false;
        if (lhs.dim == rhs.dim) {
            for (int i = 0; i < lhs.dim; ++i) {
                if (lhs.values[i] < rhs.values[i])

                    return false;
                else
                    ifTrue = true;
            }
            return ifTrue;
        }
        else {
            std::cout << "Unable to compute, points of different dimentions\n";
            return false;
        }

    }

    bool operator<=(Point &lhs, const Point &rhs) {
        bool ifTrue = false;

        if (lhs.dim == rhs.dim) {
            for (int i = 0; i < lhs.dim; ++i) {
                if (lhs.values[i] > rhs.values[i]) {
                    if (lhs.values[i] != rhs.values[i]) {
                        return false;
                    }
                }
                else
                    ifTrue = true;
            }
            return false;
        }

        else {
            std::cout << "Unable to compute, points of different dimentions\n";
            return false;
        }
    }

    bool operator>=(Point &lhs, const Point &rhs) {
        bool ifTrue;

        if (lhs.dim == rhs.dim) {

            for (int i = 0; i < lhs.dim; ++i) {
                if (lhs.values[i] < rhs.values[i]) {
                    if (lhs.values[i] != rhs.values[i]) {
                        return false;
                    }
                }
                else
                    ifTrue = true;
            }
            return ifTrue;

        }
        else {
            std::cout << "Unable to compute, points of different dimentions\n";
            return false;
        }
    }

    bool operator==(const Point &lhs, const Point &rhs) {
        bool ifTrue = false;
        if (lhs.dim == rhs.dim) {
            for (int i = 0; i < lhs.dim; ++i) {
                if (lhs.values[i] != rhs.values[i])
                    return false;
                else
                    ifTrue = true;
            }
        }
        else {
            //std::cout << "Unable to compute, points of different dimentions\n";
            return false;
        }
        return ifTrue;
    }

    bool operator!=(const Point &lhs, const Point &rhs) {
        bool ifFalse = true;
        if (lhs.dim == rhs.dim) {
            for (int i = 0; i < lhs.dim; ++i) {
                if (lhs.values[i] != rhs.values[i])
                    return true;
                else
                    ifFalse = false;
            }
        }
        else {
            std::cout << "Unable to compute, points of different dimentions\n";
            return false;
        }
        return ifFalse;
    }
    std::ostream& operator <<(std::ostream &, const Cluster &);
}
