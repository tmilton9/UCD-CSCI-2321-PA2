//
//  cluster.h
//  UCD-CSCI-2321-PA2
//
//  Created by Travis Milton on 9/29/15.
//  Copyright © 2015 Travis Milton. All rights reserved.
//

#ifndef TRAVIS_MILTON_PA2_CLUSTER_H
#define TRAVIS_MILTON_PA2_CLUSTER_H


#include "Point.h"



namespace Clustering {

    typedef Point *PointPtr;
    typedef struct LNode *LNodePtr;

    struct LNode { // linked-list node
    public:
        PointPtr p;
        LNodePtr next;
        LNode(){}
        // LNode(Point arg): p(&arg), next(nullptr){}
        LNode(const PointPtr & arg, PointPtr): p(arg), next(nullptr) {}
        LNode(LNode& arg) : p(arg.p), next() {}

    };


    class Cluster {
        int size;
        LNodePtr points;// linked-list head

    public:
        Cluster() : size(0), points(nullptr) {};

        // The big three: cpy ctor, overloaded operator=, dtor
        Cluster(const Cluster &);
        Cluster &operator=( Cluster &);
        ~Cluster();

        // Set functions: They allow calling c1.add(c2.remove(p));
        void ins(LNodePtr,LNodePtr,LNodePtr);
        void del();
        void add(const PointPtr &);//add a point
        void cpy(LNodePtr);
        const PointPtr &remove(const PointPtr &);// remove a point and return its pointer

        // Overloaded operators
        // Set-preserving operators (do not duplicate points in the space)
        // Friends
        friend bool operator==(const Cluster &lhs, const Cluster &rhs);

        // Members
        Cluster &operator+=(const Cluster &rhs); // union //combine clusters
        Cluster &operator-=(const Cluster &rhs); // (asymmetric) difference //

        Cluster &operator+=(const Point &rhs); // add point
        Cluster &operator-=(const Point &rhs); // remove point

        // Set-destructive operators (duplicate points in the space)
        // Friends
        friend const Cluster operator+(const Cluster &lhs, const Cluster &rhs);
        friend const Cluster operator-(const Cluster &lhs, const Cluster &rhs);

        friend const Cluster operator+(const Cluster &lhs, const PointPtr &rhs);// creates new cluster of a+b without duplicates
        friend const Cluster operator-(const Cluster &lhs, const PointPtr &rhs);//

        // IO
        friend std::ostream &operator<<(std::ostream &, const Cluster &);
        friend std::istream &operator>>(std::istream &, Cluster &);


    };
}

#endif //TRAVIS_MILTON_PA2_CLUSTER_H
