/*-------------declaration des directives de préprocesseurs--------*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string.h>
#include <map>
#include <sstream>
#include <vector>
#include<list>
#include "parser_dot.h"


/*-------------Utilisation de l'espace standard--------*/

using namespace std;

/*-------------Lecture fichier--------*/
int main (int argc, char *argv[])
{
  ifstream file("/home/phelma/Desktop/Projet_C/test/and_xor.dot",ios::in); // Constrcteur pour crée un flux d'ouverture pour le fichier en lecture; chemmin absolu (se rappeler relatif)
  //char pattern []  ="OR2";
  vector<string> pattern;
  vector<string> pattern1;
  vector<string> pattern2;
  /******IN****/
  pattern.push_back("INPUT");
  /******OUT****/
  pattern2.push_back("OUTPUT");
  /******GATE****/
  pattern1.push_back("AND2");
  pattern1.push_back("AND3");
  pattern1.push_back("FF");
  pattern1.push_back("INVERSOR");
  pattern1.push_back("LATCH");
  pattern1.push_back("MUX2");
  pattern1.push_back("MUX3");
  pattern1.push_back("XOR2");
  pattern1.push_back("XOR3");
  //pattern1.push_back("OR2");
  pattern1.push_back("OR3");
  /*************/
  string line;
  Circuit circuit;
  Input *X=NULL;
  string fleche("->");
  int i=0;
  vector<string> linetempo(100);
  string linetempo1;
  vector<string> linetempo2(100);
  if (file)
  {
    //ofstream tempo("tempo.txt",ios::out|ios::app);// Constructeur pour crée un flux d'ouverture pour le fichier en ecriture ;
    //if (tempo)
    while(getline(file,line)){
      size_t size=line.size()+1;// recupération de la longeur de la ligne lu par le fichier ainsi que le caractere de fin de ligne
      char *test=new char[size];//  allocation dynamique d'un tableau de char en fontion de la longueur de la ligne lu
      strncpy(test,line.c_str(),size);// conversion string vers char
      //bool match= regex_search(test,pattern);

  /*************Detection des entrées***************/
  i=0;
  vector<string> :: const_iterator it;
    for (it=pattern.begin();it !=pattern.end();++it)
    {
      string tempo_pattern = *it;
      size_t taille= tempo_pattern.size()+1;
      char *test_pattern=new char[taille];
      strncpy(test_pattern,tempo_pattern.c_str(),taille);

                if (strstr(test,test_pattern))
                {
                  istringstream  linelikefile(line);
                  getline(linelikefile,linetempo[i],' ');
                  circuit.ajoutinput(new Input(linetempo[i],0));
                  //std::cout <<linetempo<< '\n';
                  i++;
                }
    }

    /*************Detection des sorties***************/
     i=0;
     vector<string> :: const_iterator itr2;
      for (itr2=pattern2.begin();itr2 !=pattern2.end();++itr2)
      {
        string tempo_pattern2 = *itr2;
        size_t taille2= tempo_pattern2.size()+1;
        char *test_pattern2=new char[taille2];
        strncpy(test_pattern2,tempo_pattern2.c_str(),taille2);

                  if (strstr(test,test_pattern2))
                  {
                    istringstream  linelikefile2(line);
                    getline(linelikefile2,linetempo2[i],' ');
                    circuit.ajoutoutput(new Output(linetempo2[i],0));
                    //std::cout <<linetempo2<< '\n';
                    i++;
                  }
      }

  /*************Detection des portes***************/
   i=0;
   vector<string> :: const_iterator itr1;
    for (itr1=pattern1.begin();itr1 !=pattern1.end();++itr1)
    {
      string tempo_pattern1 = *itr1;
      size_t taille1= tempo_pattern1.size()+1;
      char *test_pattern1=new char[taille1];
      strncpy(test_pattern1,tempo_pattern1.c_str(),taille1);

                if (strstr(test,test_pattern1))
                {
                  istringstream  linelikefile1(line);
                  getline(linelikefile1,linetempo1,' ');
                //  std::cout <<test_pattern1 << '\n';
                  if(tempo_pattern1 =="AND2")
                  {
                  circuit.ajoutgate(new And(linetempo1));
                  }
                  else if(tempo_pattern1 =="XOR2")
                  {
                   circuit.ajoutgate(new Xor(linetempo1));
                  }
                  else if(tempo_pattern1 =="FF")
                  {
                   circuit.ajoutgate(new Flipflop(linetempo1));
                  }
                  else if(tempo_pattern1 =="INVERSOR")
                  {
                   circuit.ajoutgate(new Inversor(linetempo1));
                  }
                  else if(tempo_pattern1 =="LATCH")
                  {
                   circuit.ajoutgate(new Latch(linetempo1));
                  }
                  else if(tempo_pattern1 =="MUX2")
                  {
                   circuit.ajoutgate(new Mux(linetempo1));
                  }
                  else if(tempo_pattern1 =="OR2")
                  {
                   circuit.ajoutgate(new Or(linetempo1));
                  }
                  //std::cout <<linetempo1<< '\n';
                  i++;
                }

    }
      //cout<<line<<endl;
      delete [] test;
      }
file.close();// fermer le fichier
     }
  else
  {
    cerr<<" failure for openning file"<< endl;
  }

/*
i=0;
if (file)
{
    while(getline(file,line)){

      size_t size=line.size()+1;// recupération de la longeur de la ligne lu par le fichier ainsi que le caractere de fin de ligne
      char *test=new char[size];//  allocation dynamique d'un tableau de char en fontion de la longueur de la ligne lu
      strncpy(test,line.c_str(),size);
      if (strstr(test,fleche))
      {
        istringstream  linelikefile(line);
        string lien;
        getline(linelikefile,linetempo,' ');
        std::cout <<linetempo<< '\n';

        i++;
      }

    }
    std::cout <<i<< '\n';

}
else
{
  cerr<<" failure for openning file operating point 2"<< endl;
}

*/

  return 0;
}
