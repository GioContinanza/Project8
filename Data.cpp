//
// Created by Gio on 4/29/20.
//

#include "Data.h"

using namespace std;

Data::Data (string o, int y, string r, string dj, string c) {
    order = o;
    year = y;
    rank = r;
    dj_name = dj;
    change = c;
    next = NULL;
}


//Overloads the output stream operator
ostream &operator<<(ostream &os, const Data &x) {
    return os << "order: " << x.order;
}


//Overloads the comparison operators
bool Data::operator<(Data a) {
    if (a.rank != "1") {
        return false;
    }
    else {
        return true;
    }

}