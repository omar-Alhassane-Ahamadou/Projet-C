 #ifndef PARSER_DOT_H
# define PARSER_DOT_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstddef>
#include <map>
#include <sstream>
#include <vector>
#include <cstring>
#include<list>


/*************************************************************/
/*************************************************************/
/*************************************************************/
/****BY OMAR ALHASSANE-AHAMADOU & ANTHONY KY******************/
/*******************SIMULATEUR DE NETLIST**********************/
/*************************************************************/
/*************************************************************/



using namespace std;


/***********************************************/

class Input {

//  friend Input& operator=( Input const & out,  Input const & f) ;

private :
  string nom;
  bool   val;
public :
   Input(){};
   Input(string nom, bool val):
   nom(nom),
   val(val)
   {
       std::cout << "constructeur d'Input" << '\n';
   }
   ~Input()
   {
       std::cout << "Destructeur d'Input" << '\n';
   }
   string getNom();
   void setNom (string nom);
   bool getVal();
   void setVal (bool val);
   Input operator=(Input f) ;
};

class Output {

//friend Output& operator=(Output& out, const Output &f) ;

  private :
    string nom;
    bool   val;
  public :
     Output(){};
     Output(string nom, bool val):
     nom(nom),
     val(val)
     {
         std::cout << "constructeur d'Output" << '\n';
     }
     ~Output()
     {
         std::cout << "Destructeur d'Output" << '\n';
     }
     string getNom();
     void setNom (string nom);
     bool getVal();
     void setVal (bool val);
     Output operator=(Output f);


};



class Gate {

  //   friend void Modif_global(string in_key,bool in_val);

private :
          // map<string,bool> in;
         //map<string,bool> out;
        //vector<Gate *> gate;
         vector<Input> in;
      //  Input in3;
        vector<Output> out;
        string label;
public :
  Gate (string label)
  {

    std::cout << "constructeur Gate" << '\n';
  }
  ~Gate ()
  {
    std::cout << "Destruction Gate" << '\n';
  }
  Input getIn (string nom);
  Output getOut (string nom);
  string getLabel();
   //void setIn (Input inX);
   //  void setOut (Output outX);
  void addinput(Input&);
  void setLabel (string label);

//  virtual bool  EvalOutput () = 0;
};

/***********************************Class Intermediaire*********************************/
class Circuit
{

    private:
     list<Input> input;
     list<Output> output;
     list <Gate*> gate;
    public :
    Circuit ()
      {
        std::cout << "construction Circuit" << '\n'<< '\n';
      }
      ~Circuit  ()
      {
        std::cout << "Destruction Circuit" << '\n'<< '\n';
      }

       void ajoutgate(Gate * gateX);
       void ajoutinput(Input *inputX);
       void ajoutoutput(Output *outputX);
    //  vector<string> getInput();
       Input getInput(string nom);
       Output getOutput(string nom);
       Gate * getGate(string nom);


};
/**************************************************************************************/

/***********************************AND***************************************/
class And : public Gate
{

public :
 And (string label) : Gate (label)
 {
   std::cout << "construction And" << '\n';
 }
 ~And ()
 {
   std::cout << "Destruction And" << '\n';
 }
bool EvalOutput ();
/* And operator=( And f){
  this->setIn(f.getIn());
  this->setIn2(f.getIn2());
  this->setOut(f.getOut());
  return *this;}*/

};

/***********************************OR***************************************/
class Xor : public Gate
{

public :
  Xor (string label) : Gate (label)
  {
    std::cout << "construction Xor" << '\n';
  }
 ~Xor ()
 {
   std::cout << "Destruction Xor" << '\n';
 }

 bool EvalOutput ();

};


/***********************************XOR***************************************/

class Or : public Gate
{

public :
  Or (string label) : Gate (label)
  {
    std::cout << "Construction Or" << '\n';
  }

 ~Or ()
 {
   std::cout << "Destruction Or" << '\n';
 }

 bool EvalOutput ();

};

/***********************************MUX***************************************/
class Mux : public Gate
{

public :
  Mux (string label) : Gate (label)
  {
    std::cout << "Construction Mux" << '\n';
  }
 ~Mux ()
 {
   std::cout << "Destruction Mux" << '\n';
 }
bool EvalOutput ();

};

/***********************************LATCH***************************************/
class Latch : public Gate
{

public :
  Latch (string label) : Gate (label)
  {
    std::cout << "Construction Latch" << '\n';
  }
 ~Latch ()
 {
   std::cout << "Destruction Latch" << '\n';
 }
bool EvalOutput ();

};


/***********************************INVERSOR***************************************/
class Inversor : public Gate
{

public :
  Inversor (string label) : Gate (label)
  {
    std::cout << "Construction Inversor" << '\n';
  }
 ~Inversor ()
 {
   std::cout << "Destruction Inversor" << '\n';
 }
bool EvalOutput ();

};

/***********************************FLIPFLOP***************************************/
class Flipflop : public Gate
{

public :
  Flipflop (string label) : Gate (label)
  {
    std::cout << "Construction Flipflop" << '\n';
  }
 ~Flipflop ()
 {
   std::cout << "Destruction Flipflop" << '\n';
 }
bool EvalOutput ();

};
/***********************************NAND2***************************************/
class Nand : public Gate
{

public :
  Nand (string label) : Gate (label)
  {
    std::cout << "Construction Nand" << '\n';
  }
 ~Nand ()
 {
   std::cout << "Destruction Nand" << '\n';
 }
bool EvalOutput ();

};
/***********************************NOR2***************************************/
class Nor : public Gate
{

public :
  Nor (string label) : Gate (label)
  {
    std::cout << "Construction Nor" << '\n';
  }
 ~Nor ()
 {
   std::cout << "Destruction Nor" << '\n';
 }
bool EvalOutput ();

};
/***********************************NOT***************************************/
class Not : public Gate
{

public :
  Not(string label) : Gate (label)
  {
    std::cout << "Construction Not" << '\n';
  }
 ~Not ()
 {
   std::cout << "Destruction Not" << '\n';
 }
bool EvalOutput ();

};
/***********************************NOT2***************************************/
class Xnor: public Gate
{

public :
  Xnor(string label) : Gate (label)
  {
    std::cout << "Construction Xnor" << '\n';
  }
 ~Xnor ()
 {
   std::cout << "Destruction Xnor" << '\n';
 }
bool EvalOutput ();

};



# endif
