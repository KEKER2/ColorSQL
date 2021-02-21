#pragma once
#include "record.h"
void export_txt() {
    fstream plik( "out.txt", ios::out );
    if( plik.good() ) {
        for(auto& x : baza) {
            ostringstream oss;
            oss << x.UUID <<' '<< x.PLATFORM <<' '<< x.NAME <<' '<<x.FOLLOWERS <<'\n';
            plik << oss.str();
        }
    }
}

void export_xml() {
    fstream plik( "out.xml", ios::out );
    if( plik.good() ) {
        ostringstream oss;
        oss <<"<DATABASE>\n";
        for(auto& x : baza) {
            oss<<"\t<RECORD>\n"
            <<"\t\t<UUID>"<< x.UUID <<"</UUID>\n"
            <<"\t\t<PLATFORM>"<< x.PLATFORM<< "</PLATFORM>\n"
            << "\t\t<NAME>" << x.NAME<< "</NAME>\n" 
            << "\t\t<FOLLOWERS>" << x.FOLLOWERS<< "</FOLLOWERS>\n"
            <<"\t</RECORD>\n";
        }
        oss<< "</DATABASE>";
        plik << oss.str();
    }
}