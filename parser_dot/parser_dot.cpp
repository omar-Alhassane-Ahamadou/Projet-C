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

  Input Input::operator=(Input f){
    this->setNom(f.getNom());
    this->setVal(f.getVal());
    return *this;}


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

  Output Output:: operator=( Output f){
    this->setNom(f.getNom());
    this->setVal(f.getVal());
    return *this; }

/******************************Fin Output****************************************/


/***************************************Debut Gate***************************************/

  Input Gate::getIn (string nom)
  {
    vector<Input>::iterator itr ;
    for(itr = in.begin() ; itr != in.end() ; ++itr)
     {
          Input X=*itr;
            if (X.getNom()==nom)
            {
              return X;
            }
     }
  }

   Output Gate::getOut (string nom)
   {
        vector<Output>::iterator itr ;
      for(itr = out.begin() ; itr != out.end() ; ++itr)
       {
            Output X=*itr;
              if (X.getNom()==nom)
              {
                return X;
              }
       }
  }
    string Gate::getLabel()
   {
     return this->label;
   }

/*void Gate::setIn (Input inX)
  {
    *this.Input::setNom();
    *this.Input::setVal();
  }
  void Gate::setOut (Output outX)
  {
    *this.Output::setVal();
    *this.Output::setNom();

  }*/
    void Gate::setLabel (string label)
    {
      this->label=label;
    }

  void Gate::addinput(Input & Nwinput)
  {
    std::cout << "add input class Gate :" << '\n';
      in.push_back(Nwinput);
  }
/**************************************Fin Gate******************************************/

/***************************Debut Circuit****************************************/
void Circuit::ajoutgate(Gate * gateX=NULL)
{
  std::cout << "add gate class Circuit" << '\n';
   gate.push_back(gateX);
}

void Circuit::ajoutinput(Input *inputX)
{
  std::cout << "add input class Circuit" << '\n';
  input.push_back(*inputX);
}

void Circuit::ajoutoutput(Output *outputX)
{
  std::cout << "add output class Circuit" << '\n';
  output.push_back(*outputX);
}

Input Circuit::getInput(string nom)
{
  if (this->input.size()==0) {
    std::cout << "LISTE INPUT VIDE" << '\n';
    exit(0);
  }
  list<Input>::iterator itr ;
  for(itr = input.begin() ; itr != input.end() ; ++itr)
   {
        Input X=*itr;
          if (X.getNom()==nom)
          {
            return X;
          }

   }
}

Output Circuit::getOutput(string nom)
{

  if (this->output.size()==0) {
    std::cout << "LISTE OUTPUT VIDE" << '\n';
    exit(0);
  }

  list<Output>::iterator itr ;
  for(itr = output.begin() ; itr != output.end() ; ++itr)
   {
     Output X=*itr;
          if (X.getNom()==nom)
          {
            return X;
          }

   }

}

Gate * Circuit::getGate(string nom)
{


  if (this->gate.size()==0) {
    std::cout << "LISTE GATE VIDE" << '\n';
    exit(0);
  }
  list<Gate*>::iterator itr ;
  for(itr = gate.begin() ; itr != gate.end() ; ++itr) {

      Gate* X=*itr;
         if (X->getLabel()==nom)
         {
           return X;
         }
}

}

/********************************************************/
/*vector<string> Circuit::getInput()
{
  vector<string> A(100);

  if (this->input.size()==0) {
    std::cout << "LISTE INPUT VIDE" << '\n';
    exit(0);
  }
  list<Input>::iterator itr ;
  for(itr = input.begin() ; itr != input.end() ; ++itr) {
  Input X=*itr;

   A.push_back(X.getNom());
}
return A;

*/
/*********************************************Fin Circuit*********************************/
