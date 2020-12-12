/*-------------declaration des directives de préprocesseurs--------*/
#include <iostream>
#include <fstream>
#include <regex>
#include <iomanip>
#include <algorithm>
#include <string.h>
#include "parser_wavedrom.h"

Signal::Signal(const string & nom, vector<bool> entrees){
  Name=nom;
  In=entrees;
}
void const Signal::getName() const{
  cout<<"le nom du signal est : "<<Name;
}

void const Signal::getIn() const{
cout << " les stimuli sont : ";
  for(int l=0;l<In.size();l++){
    cout <<In[l];
  }
}

void Signal::setIn(const vector<bool> entrees){
  In = entrees;
}

void const Signal::toString() const{
getName();
cout<<" et ";
getIn();
};
