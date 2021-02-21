#pragma once
#include "record.h"
using namespace std;

record cin_record(){
    string t1,t2;
    int t3;
    cin>>t1>>t2>>t3;
    return record(uuid(), toupper(t1), t2, t3);
}
void import_txt(){
    char t1[512],t2[512],t3[512];
    int t4;
    string s1;
    fstream plik("in.txt", ios::in);
    if(plik.good()) {
        char buffer[512];
        string line;
        while(getline(plik, line)) {
            strcpy(buffer,line.c_str());
            sscanf(buffer, "%s %s %s %d", t1, t2, t3, &t4);
            if(string(t1) == "NULL")
                s1 = uuid();
            else s1 = t1;
            baza.push_back(record( s1, t2, t3, t4));
        }
    }
    view = baza;
}