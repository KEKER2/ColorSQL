#pragma once
#include <bits/stdc++.h>
#include <fstream>
#include <random>
#include <Windows.h>
#include "tools.h"
using namespace std;

class record {
    public:
    string UUID;
    string PLATFORM;
    string NAME;
    uint32_t FOLLOWERS;
    record(string uuid, string platform, string name, int followers) :
    UUID(uuid), PLATFORM(platform), NAME(name), FOLLOWERS(followers) {}
    record() = default;
    void set(string uuid, string platform, string name, int followers) {
        this -> UUID = uuid;
        this -> PLATFORM = platform;
        this -> NAME = name;
        this -> FOLLOWERS = followers;
    }
};
typedef vector<record> database;
string COMMAND, ARGUMENT, VALUE;
database baza, view; 