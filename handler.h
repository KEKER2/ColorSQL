#pragma once
#include "record.h"
#include "sort.h"
#include "find.h"
#include "save.h"
#include "read.h"
#include "delete.h"
#include "edit.h"
using namespace std;
void get_and_handle_input() {
    cin>>COMMAND;
    if(!strcasecmp(COMMAND.c_str(), "END")) {
        exit(0);
    } else if(!strcasecmp(COMMAND.c_str(), "SORT")) {
        cin>>ARGUMENT;
        sort();
    } else if(!strcasecmp(COMMAND.c_str(), "FIND")) {
        cin>>ARGUMENT;
        find();
    } else if(!strcasecmp(COMMAND.c_str(), "MAKE")) {
        baza.push_back(cin_record()),
        view = baza;
    } else if(!strcasecmp(COMMAND.c_str(), "EDIT")) {
        edit_record();
    } else if(!strcasecmp(COMMAND.c_str(), "DELETE")) {
        delete_record();
    } else if(!strcasecmp(COMMAND.c_str(), "IMPORT")) {
        import_txt();
    } else if(!strcasecmp(COMMAND.c_str(), "EXPORT")) {
        export_txt();
    } else if(!strcasecmp(COMMAND.c_str(), "XML")) {
        export_xml();
    } else if(!strcasecmp(COMMAND.c_str(), "CLS")) {
        view = baza;
    }

}   