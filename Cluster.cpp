//
// Created by Travis Milton on 9/13/15.
//

#include "Cluster.h"

namespace Clustering {

    typedef Point *PointPtr;



    Cluster::Cluster(const Cluster &other) {
        size = other.size;
        if (size == 0)
            new Cluster();
        else {

            LNode **dst = &points;
            LNode *ptr = other.points;
            while (ptr)
            {
                *dst = new LNode(*ptr);
                dst = &(*dst)->next;
                ptr = ptr->next;
            }
        }
    }

    Cluster::~Cluster() {

    }

    Cluster &Cluster::operator=(Cluster &other) {
        std::swap(points, other.points); // we get his list; he gets ours
        return *this;
    }

    void Cluster::add(PointPtr const &ptr) {
        LNode *temp;
        temp = points;
        points = new LNode(ptr);
        points->next = temp->next;
        delete[]temp;
        size++;
    }

    const PointPtr &Cluster::remove(PointPtr const &ptr) {
        PointPtr temp;
        temp = ptr;
        points->next = nullptr;
        points->p = nullptr;
        delete[] points;
        size--;

        return temp;
    }

    Cluster &Cluster::operator+=(const Cluster &rhs) {//combine clusters a+b
        for (int j = 0; j < size; ++j) {
            points = points->next;

        if (points->next == NULL) {
            for (int i = 0; i < rhs.size; ++i) {
                points->next = rhs.points->next;
                size++;
            }
        }
        }
        return *this;
    }


    Cluster &Cluster::operator+=(const Point &rhs) {
        Point Ptemp = rhs;

        LNode *temp;
        temp = points;
        points = new LNode(&Ptemp);
        points->next = temp->next;
        delete[]temp;
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

        Cluster Tempc(*this);
        for (int i = 0; i < Tempc.size; ++i) {

            if (Tempc.points->p == &rhs) {
                remove(Tempc.points->p);
                Tempc.size--;

            }
        }
        return Tempc;


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


        while(cluster.points->next != NULL) {
            std::cout << TempC.points->p->getValue() << ", ";
            TempC.points = TempC.points->next;
        }
        std::cout <<"/n";



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




