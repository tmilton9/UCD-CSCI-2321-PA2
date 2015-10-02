//
//  cluster.cpp
//  UCD-CSCI-2321-PA2
//
//  Created by Travis Milton on 9/29/15.
//  Copyright © 2015 Travis Milton. All rights reserved.
//

#include "cluster.h"


namespace Clustering {




    Cluster::Cluster(const Cluster &other) {            // copy constructor
        size = other.size;
        if (size == 0)
            points=nullptr;
        else {

            cpy(other.points);
        }
    }

    Cluster::~Cluster() {                                 //destructor
        //del();
    }

    Cluster &Cluster::operator=(Cluster &other) {         // overloaded =
        if (this != &other) {
            del();
            cpy(other.points);
        }
        return *this;
    }

    void Cluster::add(PointPtr const &ptr) {              // add function
        if(size == 0){
            points = new LNode(ptr, nullptr);
        } else {
            LNodePtr c = points,n=points->next,
                    a = new LNode(ptr, nullptr);
            while (*(c->p)<= *ptr) {
                if (n == nullptr || *(n->p)> *ptr) {
                    break;
                }else {
                    c=n;
                    n=n->next;
                }
            }
            ins(c,a,n);
        }
        size ++;
    }

    void Cluster::cpy(LNodePtr pts){
        LNodePtr reached = pts;
        LNodePtr curr = new LNode(reached->p,nullptr);
        points=curr;
        LNodePtr prev = curr;
        reached = reached->next;

        for (;reached != nullptr; reached=reached->next) {
            curr= new LNode(reached->p,nullptr);
            prev->next = curr;
            prev = curr;
        }
    }
    void Cluster::del(){
        if (size!=0){
            LNodePtr c = points,n = points->next;
            delete c->p;
            delete c;

            while (n!= nullptr) {
                c=n;
                n=n->next;
                delete c->p;
                delete c;
            }
        }
        points=nullptr;
        size =0;
    }
    void Cluster::ins(LNodePtr before, LNodePtr add, LNodePtr after){
        before->next = add;
        add->next = after;

    }

    const PointPtr &Cluster::remove(PointPtr const &ptr) {//remove function
        PointPtr *temp;
        *temp = ptr;
        points->next = nullptr;
        points->p = nullptr;
        delete[] points;
        size--;

        return *temp;
    }

    Cluster &Cluster::operator+=(const Cluster &rhs) {//combine clusters a+b
        for (int j = 0; j < size; ++j) {
            points = points->next;

            if (points->next == nullptr) {
                for (int i = 0; i < rhs.size; ++i) {
                    points->next = rhs.points->next;
                    size++;
                }
            }
        }
        return *this;
    }


    Cluster &Cluster::operator+=(const Point &rhs) {
        Point P = rhs;
        this->add(&P);
        /*
        PointPtr P1 = &P;
        LNode *temp;
        temp = points->next;
        points = new LNode(P1, nullptr);

        points->next = temp;
        delete[]temp;
        */
        size++;

        return *this;

    }


    Cluster &Cluster::operator-=(const Cluster &rhs) {

        for (int j = 0; j < size; ++j) {
            points = points->next;

            if (points->p == rhs.points->p) {
                remove(points->p);
                size--;
            }
        }
        return *this;
    }

    Cluster &Cluster::operator-=(const Point &rhs) {
        //Point temp = rhs;

        //Cluster Tempc(*this);
        for (int i = 0; i < this->size; ++i) {

            if (this->points->p == &rhs) {
                remove(this->points->p);
                this->size--;

            }
        }
        return *this;


    }

    const Cluster operator+(const Cluster &lhs, const Cluster &rhs) {
        Cluster tempL(lhs);
        Cluster tempR(rhs);

        return (tempL += tempR);
    }

    const Cluster operator-(const Cluster &lhs, const Cluster &rhs) {
        Cluster tempL(lhs);
        Cluster tempR(rhs);
        return (tempL-=tempR);
    }

    const Cluster operator+(const Cluster &lhs, const PointPtr &rhs) {
        PointPtr temp;
        temp = rhs;

        Cluster Tempc(lhs);
        Tempc.add(temp);
        return Tempc;
    }

    const Cluster operator-(const Cluster &lhs, const PointPtr &rhs) {
        PointPtr temp;
        temp = rhs;

        Cluster Tempc(lhs);

        Tempc.remove(temp);

        return Tempc;
    }
    bool operator==(const Cluster &lhs, const Cluster &rhs){
        Cluster tempL(lhs);
        Cluster tempR(rhs);

        while (tempL.points->next != NULL)
        {
            if (tempL.points->p != tempR.points->p){
                return false;
            }
            tempL.points = tempL.points->next;
            tempR.points = tempR.points->next;
        }
        return true;
    }
    std::ostream &operator<<(std::ostream &ostream, const Cluster &cluster) {
        Cluster TempC(cluster);


        while(TempC.points->next != NULL) {
            int j = 1;
            std::cout << j  << ": ";
            TempC.points->p->disPnt();

            TempC.points = TempC.points->next;
            std::cout <<"\n";
            j++;
        }
        std::cout <<"\n";



        return ostream;
    }

    std::istream &operator>>(std::istream &istream, Cluster &cluster) {
        PointPtr temp;
        int num;
        std::cout << "Enter the number of points to add ";
        std::cin >> num;
        for (int i = 0; i < num; ++i) {
            std::cout << "Enter the point you want to add: ";

            std::cin >> *temp;
            cluster.add(temp);
        }
        return istream;
    }
}





