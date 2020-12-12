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
string const& Signal::getName() const{
  return Name;
}

vector<bool> const& Signal::getIn() const{
  return In;
}

void Signal::setIn(const vector<bool> entrees){
  In = entrees;
}
