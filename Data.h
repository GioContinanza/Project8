//
// Created by Gio on 4/29/20.
//

#ifndef PROJECT8_DATA_H
#define PROJECT8_DATA_H

#include <iostream>

class Data {
    friend std::ostream &operator << (std::ostream& os, const Data& x);

public:
    Data(std::string order = "NA", int year = 0, std::string rank = "NA", std::string dj_name = "NA", std::string change = "NA");
    bool operator < (Data a);

private:
    std::string order = "NA";
    int year = 0;
    std::string rank = "NA";
    std::string dj_name = "NA";
    std::string change = "NA";
    Data* next;
};


#endif //PROJECT8_DATA_H
