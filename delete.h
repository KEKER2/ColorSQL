#pragma once
#include "record.h"
using namespace std;
void delete_record() {
    cin>>VALUE;
    int32_t index = stoi(VALUE);
    VALUE = view[index].UUID;
    auto p = std::find_if(view.begin(), view.end(), is_same_uuid);
    if(p != view.end()) 
        baza.erase(p),
        view.erase(p);
}