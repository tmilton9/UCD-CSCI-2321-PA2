
#include "Point.h"
#include "Cluster.h"
#include "K-means.h"
//#include <cassert>



//double computeArea(Point a, Point b, Point c);
int main() {
    using namespace Clustering;
Point p1(3);
bool b1,b2;
    std::cout << "loded /n";

    p1.setValue();
    Point p2(3);
    p2.setValue();
    Point p3(p1);
    p1*=2;
    p2/=2;
    b1 =  p1<p2;
    b2 =  p1>p2;
    Cluster c1;
    c1.add(&p1);
    c1.add(&p2);


    std::cout << p1;
    return 0;

}


/*double computeArea(Point a, Point b, Point c){

    double sideA = a.distanceTo(a,b);

    double sideB = a.distanceTo(a,c);

    double sideC = b.distanceTo(b,c);

    double s = (sideA + sideB + sideC)/2;

    double ca;

    ca = sqrt(s * (s - sideA)*(s-sideB)*(s-sideC));

    return ca;

}*/