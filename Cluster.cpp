//
// Created by Travis Milton on 9/13/15.
//

#include "Cluster.h"

namespace Clustering {
    typedef Point * PointPtr;
    Cluster::Cluster() {

    }

    Cluster::Cluster(const Cluster &other) {



        size = other.size;
        if (size == 0)
            new Cluster();
        else {
            points = new LNode;



            LNode *ptr = other.points->next;
            while (ptr != NULL)
            {
                points->p = other.points->p;
                points -> next = new LNode ;
                points ->p = other.points->p;
                points->next = new LNode;
                ptr = ptr->next;
            }
        }
    }

/*
    Cluster &Cluster::operator=(const ::Cluster &oldCluster) {
        if (this == &oldCluster) { // check for self-assignment (like c1 = c1;)
            return *this; // return the current object
        } else {
            for (int i = 0; i < size; i++)
                delete points[i];
            delete[] points;
        }

        return *this; // return the current object
    }
*/
    Cluster::~Cluster() {

    }

    Cluster &Cluster::operator=(const Cluster &other) {
        size = other.size;


        return this;
    }
}