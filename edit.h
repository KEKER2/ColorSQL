#pragma once
#include "record.h"
void edit_record() {
    cin>>VALUE;
    int32_t index = stoi(VALUE);
    VALUE = view[index].UUID;
    auto p = std::find_if(baza.begin(), baza.end(), is_same_uuid);
    if(p != view.end()) {
        record b = cin_record();
        b.UUID = p->UUID;
        *p = b;
    }
    view = baza;
}