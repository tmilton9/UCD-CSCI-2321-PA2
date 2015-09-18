//
// Created by Travis Milton on 9/13/15.
//

#include "Cluster.h"

namespace Clustering {
    typedef Point *PointPtr;

    Cluster::Cluster() {

    }

    Cluster::Cluster(const Cluster &other) {
        size = other.size;
        if (size == 0)
            new Cluster();
        else {

            LNode **dst = &points;
            LNode *ptr = other.points;
            while (ptr);
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
    }

    const PointPtr &Cluster::remove(PointPtr const &ptr) {
        PointPtr temp;
        temp = ptr;
        points->next = nullptr;
        points->p = nullptr;
        delete[] points;

        return temp;
    }

    Cluster &Cluster::operator+=(const Cluster &rhs) {//combine clusters a+b
        for (int j = 0; j < size; ++j) {
            points = points->next;
        }
        if (points->next == NULL) {
            for (int i = 0; i < rhs.size; ++i) {
                points->next = rhs.points->next;
            }
        }
        return *this;
    }


    Cluster &Cluster::operator+=(const Point &rhs) {
        PointPtr temp;
        temp = &rhs;

        Cluster Tempc(*this);
        Tempc.add(temp);
        return Tempc;
    }


    Cluster &Cluster::operator-=(const Cluster &rhs) {
        return <#initializer#>;
    }

    Cluster &Cluster::operator-=(const Point &rhs) {
        return <#initializer#>;
    }

    const Cluster operator+(const Cluster &lhs, const Cluster &rhs) {

        return Cluster();
    }

    const Cluster operator-(const Cluster &lhs, const Cluster &rhs) {
        return Cluster();
    }

    const Cluster operator+(const Cluster &lhs, const PointPtr &rhs) {
        return Cluster();
    }

    const Cluster operator-(const Cluster &lhs, const PointPtr &rhs) {
        return Cluster();
    }
    bool operator==(const Cluster &lhs, const Cluster &rhs){
        return true;
    }
    std::ostream &operator<<(std::ostream &ostream, const Cluster &cluster) {
        return <#initializer#>;
    }

    std::istream &operator>>(std::istream &istream, Cluster &cluster) {
        return <#initializer#>;
    }
}




