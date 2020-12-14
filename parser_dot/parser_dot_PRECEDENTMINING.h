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

class Gate {

  //   friend void Modif_global(string in_key,bool in_val);

public :
         //map<string,bool> in;
         //map<string,bool> out;
         //vector<Gate *> gate;
         Gate * in;
         string label;
public :
  Gate (string label,map<string,bool> in, map<string,bool> out)
  {

    std::cout << "constructeur Gate" << '\n';
  }
  ~Gate ()
  {
    std::cout << "Destruction Gate" << '\n';
  }
  map <string, bool> GetIn ();
  map <string, bool> GetOut ();
   string getLabel();
  void SetIn (string in_key,bool in_val);
  void SetOut (map<string,bool> out);
  void SetGate (vector<Gate *> gate);
//  string GetLabel ();
  virtual bool  EvalOutput () = 0;
};

/*********************************Class Intermediaire*********************************/
class Circuit
{
    private:
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

       bool ajoutgate(Gate * gateX);


};

/************************************************************************************/

/***********************************AND***************************************/
class And : public Gate
{

public :
 And (string label,map<string,bool> in, map<string,bool> out) : Gate (label,in,out)
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
class Or : public Gate
{

public :
  Or (string label,map<string,bool> in, map<string,bool> out) : Gate (label,in,out)
  {
    std::cout << "construction Or" << '\n';
  }
 ~Or ()
 {
   std::cout << "Destruction Or" << '\n';
 }

 bool EvalOutput ();

};


/***********************************XOR***************************************/

// class Xor : public Gate
// {
//
// public :
//   Xor (map<string,bool> in, map<string,bool> out,  vector<Gate *> gate) : Gate (in,out,gate)
//   {
//     std::cout << "Construction Xor" << '\n';
//   }
//
//  ~Xor ()
//  {
//    std::cout << "Destruction Xor" << '\n';
//  }
//
//  bool EvalOutput ();
//
// };
//
// /***********************************MUX***************************************/
// class Mux : public Gate
// {
//
// public :
//   Mux (map<string,bool> in, map<string,bool> out,  vector<Gate *> gate) : Gate (in,out,gate)
//   {
//     std::cout << "Construction Mux" << '\n';
//   }
//  ~Mux ()
//  {
//    std::cout << "Destruction Mux" << '\n';
//  }
// bool EvalOutput ();
//
// };
//
// /***********************************LATCH***************************************/
// class Latch : public Gate
// {
//
// public :
//   Latch (map<string,bool> in, map<string,bool> out,  vector<Gate *> gate) : Gate (in,out,gate)
//   {
//     std::cout << "Construction Latch" << '\n';
//   }
//  ~Latch ()
//  {
//    std::cout << "Destruction Latch" << '\n';
//  }
// bool EvalOutput ();
//
// };
//
//
// /***********************************INVERSOR***************************************/
// class Inversor : public Gate
// {
//
// public :
//   Inversor (map<string,bool> in, map<string,bool> out,  vector<Gate *> gate) : Gate (in,out,gate)
//   {
//     std::cout << "Construction Inversor" << '\n';
//   }
//  ~Inversor ()
//  {
//    std::cout << "Destruction Inversor" << '\n';
//  }
// bool EvalOutput ();
//
// };
//
// /***********************************FLIPFLOP***************************************/
// class Flipflop : public Gate
// {
//
// public :
//   Flipflop (map<string,bool> in, map<string,bool> out, vector<Gate *> gate) : Gate (in,out,gate)
//   {
//     std::cout << "Construction Flipflop" << '\n';
//   }
//  ~Flipflop ()
//  {
//    std::cout << "Destruction Flipflop" << '\n';
//  }
// bool EvalOutput ();
//
// };



# endif
