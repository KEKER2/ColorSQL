#pragma once
#include "record.h"
#include "comp.h"
using namespace std;
void sort() {
    bool (*ptr)(record, record);
    if(!strcasecmp(ARGUMENT.c_str(), "PLATFORM")) {
        ptr = cmp_platform;
    } else if(!strcasecmp(ARGUMENT.c_str(), "NAME")) {
        ptr = cmp_name;
    } else if(!strcasecmp(ARGUMENT.c_str(), "FOLLOWERS")) {
        ptr = cmp_followers;
    }
    sort(view.begin(), view.end(), ptr);
}
