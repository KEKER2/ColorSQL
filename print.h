#pragma once
#include "record.h"
#include "colors.h"
using namespace std;
int iter = 0;
int riter = 0;

void colour_selected(string s);
void print_platform(string s);

void print_help() {
  cout<<"if u want to see commands u need to see source code sorry :/ \n";
};

void print_data() {
    int n = 0; 
    if(!strcasecmp(COMMAND.c_str(), "SORT")) {
        if(!strcasecmp(ARGUMENT.c_str(), "PLATFORM")) {
            n = 0;
        } else if(!strcasecmp(ARGUMENT.c_str(), "NAME")) {
            n = 1;
        } else if(!strcasecmp(ARGUMENT.c_str(), "FOLLOWERS")) {
            n = 2;
        }
    }
  for(int i=0; i<view.size(); ++i ) {
      iter = i;
    switch(n) {
        case 0:
            cout<< "["
            << i
            << "] [";
            print_platform(view[i].PLATFORM);
            cout<< "] ["
            << view[i].NAME
            << "] ["
            << view[i].FOLLOWERS
            << "]\n";
            break;
        case 1:
            cout<< "["
            << i
            << "] [";
            print_platform(view[i].PLATFORM);
            cout<< "] [";
            colour_selected(view[i].NAME);
            cout<< "] ["
            << view[i].FOLLOWERS
            << "]\n";
            break;
        case 2:
            cout<< "["
            << i
            << "] [";
            print_platform(view[i].PLATFORM);
            cout<< "] ["
            << view[i].NAME
            << "] [";
            colour_selected(to_string(view[i].FOLLOWERS));
            cout<< "]\n";
            break;
        }
        
    }
    if(false) {
        system("cls");
        for(;;)
        RainbowPrint("https://youtu.be/i3bv1nm-HZE\n", BLACK, RAINBOW);
    }
    iter = 0;
    riter = 0;
};


void colour_selected(string s) {
    int grad;
    int extr;
    if(view.size() < 11) 
        grad = view.size(),
        extr = 0;
    else
        grad = ceil((float)view.size()/(11)),
        extr = view.size()%11;
    if(extr != 0 && iter > view.size() - extr) {
        SetColour((_colour)rainbowcolors[10], BLACK);
        cout << s << " grad:" << grad << " " << "extr:" << extr<<" " << "i:" << iter;
        SetDefaultColour();
    } else {
        SetColour((_colour)rainbowcolors[riter], BLACK);
        cout << s << " grad:" << grad << " " << "extr:" << extr << "i:" << iter;
        SetDefaultColour();
        
    }
    if((iter+1)%grad == 0 && riter != 10)
            ++riter;
}

void print_platform(string s) {
    if(!strcasecmp(s.c_str(), "YOUTUBE")) 
        SetColour(WHITE, LIGHTRED),
        cout<<toupper(s),
        SetDefaultColour();
    else if(!strcasecmp(s.c_str(), "TWITCH"))
        SetColour(WHITE, MAGENTA),
        cout<<toupper(s),
        SetDefaultColour();
    else if(!strcasecmp(s.c_str(), "FACEBOOK"))
        SetColour(WHITE, BLUE),
        cout<<toupper(s),
        SetDefaultColour();
    else if(!strcasecmp(s.c_str(), "TWITTER"))
        SetColour(LIGHTBLUE, WHITE),
        cout<<toupper(s),
        SetDefaultColour();
    else if(!strcasecmp(s.c_str(), "REDDIT"))
        SetColour(WHITE, RED),
        cout<<toupper(s),
        SetDefaultColour();
    else if(!strcasecmp(s.c_str(), "4CHAN"))
        SetColour(RED, GREEN),
        cout<<toupper(s),
        SetDefaultColour();
    else 
        cout<<toupper(s);
}
