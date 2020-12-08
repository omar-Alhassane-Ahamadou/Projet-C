/*-------------declaration des directives de préprocesseurs--------*/
#include <iostream>
#include <fstream>
#include <regex>
#include <iomanip>
#include <algorithm>
#include <string.h>
#include "parser_dot.h"

/*-------------Utilisation de l'espace standard--------*/

using namespace std;

/*-------------Lecture fichier--------*/
int main (int argc, char *argv[])
{
  ifstream file("/home/phelma/Desktop/Projet_C/test/and_xor.dot",ios::in); // Constrcteur pour crée un flux d'ouverture pour le fichier en lecture; chemmin absolu (se rappeler relatif)
  char character;
  char pattern []  ="INPUT";
  string line;
  map<string,int> inout;
  int i=0;
  if (file)
  {
    ofstream tempo("tempo.txt",ios::out|ios::app);// Constrcteur pour crée un flux d'ouverture pour le fichier en ecriture ;

    while(getline(file,line)){
      size_t size=line.size()+1;// recupération de la longeur de la ligne lu par le fichier
      char *test=new char[size];//  allocation dynamique d'un tableau de char en fontion de la longueur de la ligne lu
      strncpy(test,line.c_str(),size);// conversion string vers char
      //bool match= regex_search(test,pattern);
              if (strstr(test,pattern))
              {
                if (tempo)
              //  i++;
              }

      cout<<line<<endl;
      delete [] test;
      }

//std::cout << i << '\n';
file.close();// fermer le fichier
  }
  else
  {
    cerr<<" failure for openning file"<< endl;
  }
}
