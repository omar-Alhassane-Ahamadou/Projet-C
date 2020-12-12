/*-------------declaration des directives de préprocesseurs--------*/
#include <iostream>
#include <fstream>
#include <regex>
#include <iomanip>
#include <algorithm>
#include <string.h>
#include "parser_wavedrom.h"
#include <sstream>
#include <map>
#include <list>
#include <vector>
/*-------------Utilisation de l'espace standard--------*/

using namespace std;

/*-------------Lecture fichier--------*/
int main (int argc, char *argv[])
{
  ifstream file("Inputs.json",ios::in); // Constrcteur pour crée un flux d'ouverture pour le fichier en lecture; chemmin absolu (se rappeler relatif)
  char character;
  char pattern []  ="wave: '";
  string line;
  int i=0;
  int j=0;//ligne rajoutée
  vector<bool> In;
  vector<Signal> ListeSignaux;
  string Name;


  if (file)
  {
    //cout << "Nos entrees et leur stimuli respectifs sont : ";
    while(getline(file,line)){
      size_t size=line.size()+1;// recupération de la longeur de la ligne lu par le fichier
      char *test=new char[size];//  allocation dynamique d'un tableau de char en fontion de la longueur de la ligne lu
      strncpy(test,line.c_str(),size);// conversion string vers char
      if (strstr(test,pattern))
      {
        istringstream  linelikefile(line);
        string linetempo;
        getline(linelikefile,linetempo,'\'');
        getline(linelikefile,linetempo,'\'');
        Name=linetempo;

        //cout <<Name ;
        //    cout<<linetempo;//afficher
        //cout <<" et son stimuli est ";
        getline(linelikefile,linetempo,'\'');
        getline(linelikefile,linetempo,'\'');
        size_t size=linetempo.size();
        for(j=0;j<size;j++){
          if (linetempo[j]=='.'){
            linetempo[j]=linetempo[j-1];
          }
        }

        //cout<<"good value : ";
        //remplissage des cases de mon vecteur de booléens
        for(int k=0;k<linetempo.size();k++){
        //   cout<<linetempo[k];
          if(linetempo[k] == '0'){
            In.push_back(false);
          }else{
            In.push_back(true);
          }
        }
        //*******************************************************************************
        //affichage de In, le vecteur de booléens
        //cout <<" Values of In : ";
        //for(int l=0;l<In.size();l++){
        //  cout <<In[l] ;
        //}
        Signal I(Name,In);
        ListeSignaux.push_back(I);
        //cout<<I.getName();
        //I.getIn();
        //I.toString();
        //vidange du vecteur de booléens In
        for(int k=0;k<linetempo.size();k++){
          In.pop_back();
        }
        //*******************************************************************************
        //    cout<<linetempo;
        //cout <<", ";
        i++;
      }
      j=0;
    }
    cout <<""<<endl;
    std::cout <<"le nombre d'entrées est de : ";
    std::cout << i << '\n';
    file.close();// fermer le fichier
    for(int k=0;k<ListeSignaux.size();k++){
      ListeSignaux[k].toString();
      cout<<'\n';
    }
  }
  else
  {
    cerr<<" failure for openning file"<< endl;
  }
}
