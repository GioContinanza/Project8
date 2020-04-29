//
// Created by Gio on 4/29/20.
//
#include <iostream>
#include <fstream>
#include "Project8.h"

using namespace std;

int main () {
    cout << "Project 8" << endl;

    /*
     * Enter path for .cvs here
     */
    string fileName = ("/Users/Gio/CLionProjects/project7-continanza-p7/DJ_Mag.csv");

    ifstream DJ_MAG(fileName);
    string line, firstLine;
    int start, commaCount, position, year;
    string temp, DJ_Name, Change, order, rank;

    if(DJ_MAG.is_open()){
        getline(DJ_MAG, firstLine); //first line is not data, this is to read over the first line


        while (!DJ_MAG.eof()){
            getline(DJ_MAG, line);
            commaCount = 0;
            while (line.find (",")){
                start = 0;
                position = line.find(",");
                if (position == -1){
                    if (line != "NA"){
                        Change = line.substr(1, line.size()-2);
                    }
                    else {
                        Change = line;
                    }
                    cout << Change << " ";
                    break;
                }
                temp = line.substr (start, position);
                if (commaCount == 0){
                    temp = temp.substr(1,temp.size()-2);
                    order = temp;
                    cout << order << " ";
                }
                else if (commaCount == 1){
                    year = stoi(temp);
                    cout << year << " ";
                }
                else if (commaCount == 2){
                    rank = temp;
                    cout << rank << " ";
                }
                else if (commaCount == 3){
                    if (temp != "NA"){
                        DJ_Name = temp.substr(1, temp.size()-2);
                    }
                    else {
                        DJ_Name = temp;
                    }
                    cout << DJ_Name << " ";
                }
                start = position + 1;
                commaCount++;
                line = line.substr(start, line.size()-position);
            }
            cout << endl;
        }
    }

    cout << "\n\n- - - - - - - -\n\n" << endl;
}