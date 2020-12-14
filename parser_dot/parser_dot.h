 #ifndef PARSER_DOT_H
# define PARSER_DOT_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string.h>
#include <map>
#include <sstream>
#include <vector>
#include<list>

using namespace std;

class Input {

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

};

class Output {

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



};



class Gate {

  //   friend void Modif_global(string in_key,bool in_val);

private :
          // map<string,bool> in;
         //map<string,bool> out;
        //vector<Gate *> gate;
        Input in;
        Output out;
        string label;
public :
  Gate (string label)
  {

    std::cout << "constructeur Gate" << '\n';
  }
  ~Gate ()
  {
    std::cout << "Destruction Gate" << '\n';
  //  delete [];
  }
  Input getIn ();
  Output getOut ();
  string getLabel();
  void setIn (string in_key,bool in_val);
  void setOut (string in_key,bool in_val);
  void setLabel (string label);
//  void setGate (vector<Gate *> gate);
//  string GetLabel ();
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
        std::cout << "constructeur Circuit" << '\n';
      }
      ~Circuit  ()
      {
        std::cout << "Destruction Circuit" << '\n';
      }

       void ajoutgate(Gate * gateX);
       void ajoutinput(Input *inputX);
       void ajoutoutput(Output *outputX);
       Gate * getGate();
       vector<string> getInput();
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



# endif
