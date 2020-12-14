/*-------------declaration des directives de préprocesseurs--------*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string.h>
#include <map>
#include <sstream>
#include<list>
#include <vector>
#include "parser_dot.h"

/*-------------Utilisation de l'espace standard--------*/

using namespace std;

/*******************************Debut Input***************************************/

  string Input::getNom()
  {
    return this->nom;
  }
  void Input::setNom (string nom)
  {
     this->nom=nom;
  }
  bool Input::getVal()
  {
    return this->val;
  }
  void Input::setVal (bool val)
  {
      this->val=val;
  }


/******************************Fin Input*******************************************/


/*******************************Debut Output***************************************/

  string Output::getNom()
  {
    return this->nom;
  }
  void Output::setNom (string nom)
  {
     this->nom=nom;
  }
  bool Output::getVal()
  {
    return this->val;
  }
  void Output::setVal (bool val)
  {
      this->val=val;
  }


/******************************Fin Output****************************************/


/***************************************Debut Gate***************************************/

  Input Gate::getIn ()
  {
    return this->in;
  }
  Output Gate::getOut ()
  {
    return this->out;
  }
  string Gate::getLabel()
  {
    return this->label;
  }

  void Gate::setIn (string in_key,bool in_val)
  {
       (this->in).Input::setNom(in_key);
       (this->in).Input::setVal(in_val);
  }
  void Gate::setOut (string in_key,bool in_val)
  {
    (this->out).Output::setNom(in_key);
    (this->out).Output::setVal(in_val);
  }
  void Gate::setLabel (string label)
  {
    this->label=label;
  }

/**************************************Fin Gate******************************************/

/***************************Debut Circuit****************************************/
void Circuit::ajoutgate(Gate * gateX=NULL)
{

  //std::cout << "ajout gate:" << gateX->getLabel()<<'\n';
  //std::cout << "ajout porte dans la liste" << gate->getLabel() <<'\n';
   gate.push_back(gateX);



}

/*Gate * Circuit::getGate()
{
  cout << "Contenu de la liste: ";
  list<Gate >::iterator itr ;
  if (this->gate.size()==0) {
    std::cout << "LISTE VIDE" << '\n';
    return 0;
  }
  for(itr = gate.begin() ; itr != gate.end() ; ++itr) {
  // déréférencement de l'iterateur ;
  //cout << *itr << " " ; // affichage de l’élément
  return *itr;
}

}*/



void Circuit::ajoutinput(Input *inputX)
{
  //std::cout << "ajout porte dans la liste" << gate->getLabel() <<'\n';
  input.push_back(*inputX);

}

vector<string> Circuit::getInput()
{
  vector<string> A(100);

  if (this->input.size()==0) {
    std::cout << "LISTE INPUT VIDE" << '\n';
    exit(0);
  }
  list<Input>::iterator itr ;
  for(itr = input.begin() ; itr != input.end() ; ++itr) {
  // déréférencement de l'iterateur ;
  //cout << *itr << " " ; // affichage de l’élément
  Input X=*itr;

   A.push_back(X.getNom());
}
return A;
}



void Circuit::ajoutoutput(Output *outputX)
{
  //std::cout << "ajout porte dans la liste" << gate->getLabel() <<'\n';
  output.push_back(*outputX);
}

/*********************************************Fin Circuit*********************************/









/*void Modif_global(string in_key,bool in_val)
{
   in.insert({in_key,in_val});
}*/
/*
map <string, bool> Gate::GetIn ()
{
  //return this->in;
}
map <string, bool> Gate::GetOut ()
{
  return this->out;
}
map <string, Gate *> Gate::GetGate ()
{
  return this->gate;
}

 void Gate::SetIn (string in_key,bool in_val)
 {
   in.insert(string in_key,bool in_va);
 }

*/

/*
void Gate::SetOut (map<string,bool> out);
void Gate::SetGate (map<string,Gate> Gate);*/
