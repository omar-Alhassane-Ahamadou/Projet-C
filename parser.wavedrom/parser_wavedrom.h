#ifndef PARSER_WAVEDROM_H
# define PARSER_WAVEDROM_H
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <map>
#include <list>
#include <vector>
/*************************************************************/
/*************************************************************/
/*************************************************************/
/****BY OMAR ALHASSANE-AHAMADOU & ANTHONY KY******************/
/*******************SIMULATEUR DE NETLIST**********************/
/*************************************************************/
/*************************************************************/
using namespace std;

class Signal {
private:
  string Name;
  vector<bool> In;
  vector<Signal> ListeSignaux;
public:
  Signal(const string & nom, vector<bool> entrees);
  virtual ~Signal(){};
  void const getName() const;
  void const getIn() const;
  void const toStringSignal() const;
  void  AddSignal(Signal *I) ;
  void const toStringListeSignaux() const;
};



# endif
