/*-------------declaration des directives de préprocesseurs--------*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include "parser_wavedrom.h"
/*************************************************************/
/*************************************************************/
/*************************************************************/
/****BY OMAR ALHASSANE-AHAMADOU & ANTHONY KY******************/
/*******************SIMULATEUR DE NETLIST**********************/
/*************************************************************/
/*************************************************************/
Signal::Signal(const string & nom, vector<bool> entrees){

  std::cout << "Construction signal" <<'\n';
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

void const Signal::toStringSignal() const{
getName();
cout<<" et ";
getIn();
};

 void  Signal::AddSignal(Signal *I) {
   ListeSignaux.push_back(*I);
   //cout<<"signal a été ajouté";
 };

void const Signal::toStringListeSignaux() const{
  for(int k=0;k<ListeSignaux.size();k++){
    ListeSignaux[k].toStringSignal();
    cout<<'\n';
  }
};
