#ifndef PARSER_WAVEDROM_H
# define PARSER_WAVEDROM_H
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;

class Signal {
private:
  string Name;
  vector<bool> In;
public:
  Signal(const string & nom, vector<bool> entrees);
  virtual ~Signal(){};
  void const getName() const;
  void const getIn() const;
  void setIn(const vector<bool> entrees);
  void const toString() const;

};



# endif
