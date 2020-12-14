/*-------------declaration des directives de préprocesseurs--------*/
#include <iostream>
#include <fstream>
#include <regex>
#include <iomanip>
#include <iomanip>
#include <algorithm>
#include <string.h>
#include <map>
#include <sstream>
#include <vector>
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
  //map<string,int> inout;
  int i=0;
  if (file)
  {
    //ofstream tempo("tempo.txt",ios::out|ios::app);// Constructeur pour crée un flux d'ouverture pour le fichier en ecriture ;
    //if (tempo)
    while(getline(file,line)){
      size_t size=line.size()+1;// recupération de la longeur de la ligne lu par le fichier ainsi que le caractere de fin de ligne
      char *test=new char[size];//  allocation dynamique d'un tableau de char en fontion de la longueur de la ligne lu
      strncpy(test,line.c_str(),size);// conversion string vers char
      //bool match= regex_search(test,pattern);

              if (strstr(test,pattern))
              {
                istringstream  linelikefile(line);
                string linetempo;
                getline(linelikefile,linetempo,' ');
                std::cout <<linetempo<< '\n';

                i++;
              }

      //cout<<line<<endl;
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
