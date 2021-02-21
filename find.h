#pragma once
#include "record.h"
#include "comp.h"
using namespace std;
void find() {
    bool (*ptr)(record, record);
    record tmp;
    cin>>VALUE;
    if(!strcasecmp(ARGUMENT.c_str(), "PLATFORM")) 
        ptr = cmp_platform,
        tmp.set("", VALUE, "", 0);
    else if(!strcasecmp(ARGUMENT.c_str(), "NAME")) 
        ptr = cmp_name,
        tmp.set("", "", VALUE, 0);
    else if(!strcasecmp(ARGUMENT.c_str(), "FOLLOWERS")) 
        ptr = cmp_followers,
        tmp.set("", "", "", stoi(VALUE));
    database cpy;
    sort(view.begin(), view.end(), ptr);
    auto p = std::equal_range(view.begin(), view.end(), tmp, ptr);
    for ( auto i = p.first; i != p.second; ++i ) 
        cpy.push_back(*i);
    view = cpy;
}

