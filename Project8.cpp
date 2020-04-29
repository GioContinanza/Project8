//
// Created by Gio on 4/29/20.
//
#include <iostream>
#include <fstream>
#include "Project8.h"
#include <vector>

using namespace std;

/*
 * Merge Sort Template
 */
template< typename MS > void merge(MS l, MS farLeft, MS r, MS farRight, MS m) {

    while (l != farLeft && r != farRight) {
        if (*l < *r) {
            *m++ = *l++;
        }
        else {
            *m++ = *r++;
        }
    }

    while (l != farLeft) {
        *m++ = *l++;
    }

    while (r != farRight) {
        *m++ = *r++;
    }
}

template < typename MS > void merge_sort (MS first, MS last) {
    if (last - first > 1) {
        typedef typename std::iterator_traits<MS>::value_type value_type;
        MS middle = first + (last - first) / 2;
        std::vector<value_type> left_table(first, middle);
        std::vector<value_type> right_table(middle, last);

        // sort half
        merge_sort(left_table.begin(), left_table.end());
        merge_sort(right_table.begin(), right_table.end());

        // merge to original
        merge(left_table.begin(), left_table.end(), right_table.begin(), right_table.end(),first);
    }
}


/*
 * Bubble Sort Template
 */
template < typename BS > void Bubble_Sort(BS *A, int N ) {
    for(int i = 0 ; i < N ; i++ )
    {
        for(int j=i+1 ; j < N ; j++ ) {
            if(A[j] < A[i] ) {
                int temp = A[i] ;
                A[i] = A[j] ;
                A[j] = temp ;
            }
        }
    }
}


int main () {
    cout << "Project 8! \n" << endl;

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


    vector<int> intV;

    

    vector<int> intV_B, intV_S, intV_M;



}