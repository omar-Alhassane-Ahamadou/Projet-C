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
  string lineVerif;
  string line;
  Circuit circuit;
  Input *X=NULL;
  char fleche[]="->";
  int i=0,j=1;
  vector<string> linetempo(100);
  string linetempo1;
  vector<string> linetempo2(100);

 //   std::cout << "GESTION DES ERREURS DE SYNTAXE DU FICHIER" << '\n'<< '\n' ;
 // /***************************GESTION DES ERREURS**********************/
 //  if(file)
 //  {
 //
 //    typedef enum
 //    {
 //      DIGRAPH,INTERCO,END
 //    }Stat;
 //  Stat state=DIGRAPH;
 //
 //
 //  while (state!= END)
 //  {
 //    switch (state) {
 //
 //      case DIGRAPH:// gestion des erreurs digraph , accolade, espace en debut de ligne pour digraph
 //       while(getline(file,lineVerif)){
 //         if(lineVerif.find("//")!=string::npos || lineVerif.find("/*")!=string::npos )
 //         {
 //           std::cout <<"commentaire "<<j<<" :"<<lineVerif<<'\n';
 //           j++;
 //         }
 //         else
 //         {
 //                if (lineVerif.find("digraph")!=string::npos && lineVerif.find("{{")!=string::npos) {
 //                  std::cout << "veuillez verifier la syntaxe votre fichier dot" << '\n';
 //                  exit(0);
 //                }
 //                 else if (lineVerif.find("digraph")!=string::npos)
 //                {
 //                      istringstream  linelikeX(lineVerif);
 //                      string verif;
 //                      getline(linelikeX,verif,' ');
 //                      size_t size=verif.size()+1;// recupération de la longeur de la ligne lu par le fichier ainsi que le caractere de fin de ligne
 //                     char *verifX=new char[size];//  allocation dynamique d'un tableau de char en fontion de la longueur de la ligne lu
 //                     strncpy(verifX,verif.c_str(),size);// conversion string vers char
 //                      if (strcmp("digraph",verifX)==0)
 //                      {
 //                        std::cout << "VOTRE FICHIER COMMENCE PAR DIGRAPH ! :-) " << '\n';
 //                        state = INTERCO;
 //
 //                      }
 //                      else
 //                      {
 //                        std::cout << "Votre fichier dot ne commence pas par digraph veuillez verifier la syntaxe de celui ci(il ne doit y avoir '\n' aucun espace avant le mot digraph) ! :-(" << '\n';
 //                        exit(0);
 //                      }
 //
 //                }
 //                else if(lineVerif.find("digraph")==string::npos)
 //                {
 //                  std::cout << "Votre fichier dot ne commence pas par digraph veuillez verifier la syntaxe de celui ci ! :-(" << '\n';
 //                  exit(0);
 //                }
 //                break;// test uniquement des premieres lignes
 //
 //         }
 //
 //       }
 //        break;
 //
 //      case INTERCO : //detection de la position d'un point virgule par rapport à une fleche ->;
 //      while(getline(file,lineVerif)){
 //
 //        size_t size=lineVerif.size()+1;// recupération de la longeur de la ligne lu par le fichier ainsi que le caractere de fin de ligne
 //        char *test=new char[size];//  allocation dynamique d'un tableau de char en fontion de la longueur de la ligne lu
 //        strncpy(test,lineVerif.c_str(),size);
 //
 //        if (strstr(test,fleche))
 //        {
 //            std::cout <<'\n'<< "PRESENCE A PRIORI DE LIENS DE CONNEXIONS VERIFIONS LA SYNTAXE" << '\n';
 //            size_t position1=0;
 //            size_t position2=0;
 //            size_t  find_fleche=0;
 //            size_t  find_virgule=0;
 //            size_t find_last_fleche;
 //                find_last_fleche=lineVerif.find_last_of("->");
 //                 std::cout << find_last_fleche << '\n';
 //              do {
 //                find_fleche=lineVerif.find("->",position1);
 //                find_virgule=lineVerif.find(";",position1);
 //                std::cout <<"*********"<< find_fleche<< '\n';
 //                std::cout <<"****************"<< find_virgule << '\n';
 //
 //                if(find_virgule<find_fleche)
 //                {
 //                  std::cout << '\n'<< "Verifiez la postion de vos délimiteurs ( ; ou -> )" << '\n';
 //                  exit(0);
 //                }
 //                 position1++;
 //
 //             }while(position1!=find_last_fleche-1);
 //        }
 //
 //      }
 //      std::cout << '\n'<<"VERIFICATION DES INTERCONNEXIONS TERMINEE AVEC SUCCES :-) " << '\n'<< '\n';
 //      state=END;
 //      break;
 //
 //       case END:
 //         file.close();// fermer le fichier
 //         std::cout << "Fermeture du fichier pour la gestion des ERREURS " << '\n'<< '\n';
 //
 //       break;
 //
 //    }
 //   }
 //  }
 //  else
 //  {
 //      cerr<<" failure for openning file operating point 1"<< endl;
 //  }
/****************************************************************Fin gestion erreur***********************/

     std::cout << "PASSONS A L'ETAPE D'INSTANCIATION DE NOS INPUT OUTPUT ET PORTES (SANS CONNEXION)" << '\n'<<'\n'<<'\n';
//     if (file)
//   {
//     //ofstream tempo("tempo.txt",ios::out|ios::app);// Constructeur pour crée un flux d'ouverture pour le fichier en ecriture ;
//     //if (tempo)
//     while(getline(file,line)){
//       size_t size=line.size()+1;// recupération de la longeur de la ligne lu par le fichier ainsi que le caractere de fin de ligne
//       char *test=new char[size];//  allocation dynamique d'un tableau de char en fontion de la longueur de la ligne lu
//       strncpy(test,line.c_str(),size);// conversion string vers char
//       //bool match= regex_search(test,pattern);
//
//   /*************Detection des entrées***************/
//   i=0;
//   vector<string> :: const_iterator it;
//     for (it=pattern.begin();it !=pattern.end();++it)
//     {
//       string tempo_pattern = *it;
//       size_t taille= tempo_pattern.size()+1;
//       char *test_pattern=new char[taille];
//       strncpy(test_pattern,tempo_pattern.c_str(),taille);
//
//                 if (strstr(test,test_pattern))// fermer le fichiert)
//                 {
//                   istringstream  linelikefile(line);
//                   getline(linelikefile,linetempo[i],' ');
//                   circuit.ajoutinput(new Input(linetempo[i],0));
//                   //std::cout <<linetempo<< '\n';
//                   i++;
//                 }
//
//     }
//
//     /*************Detection des sorties***************/
//      i=0;
//      vector<string> :: const_iterator itr2;
//       for (itr2=pattern2.begin();itr2 !=pattern2.end();++itr2)
//       {
//         string tempo_pattern2 = *itr2;
//         size_t taille2= tempo_pattern2.size()+1;
//         char *test_pattern2=new char[taille2];
//         strncpy(test_pattern2,tempo_pattern2.c_str(),taille2);
//
//                   if (strstr(test,test_pattern2))
//                   {
//                     istringstream  linelikefile2(line);
//                     getline(linelikefile2,linetempo2[i],' ');
//                     circuit.ajoutoutput(new Output(linetempo2[i],0));
//                     //std::cout <<linetempo2<< '\n';
//                     i++;
//                   }
//
//       }
//
//   /*************Detection des portes***************/
//    i=0;
//    vector<string> :: const_iterator itr1;
//     for (itr1=pattern1.begin();itr1 !=pattern1.end();++itr1)
//     {
//       string tempo_pattern1 = *itr1;
//       size_t taille1= tempo_pattern1.size()+1;
//       char *test_pattern1=new char[taille1];
//       strncpy(test_pattern1,tempo_pattern1.c_str(),taille1);
//
//                 if (strstr(test,test_pattern1))
//                 {
//                   istringstream  linelikefile1(line);
//                   getline(linelikefile1,linetempo1,' ');
//                 //  std::cout <<test_pattern1 << '\n';
//                   if(tempo_pattern1 =="AND2")
//                   {
//                   circuit.ajoutgate(new And(linetempo1));
//                   }
//                   else if(tempo_pattern1 =="XOR2")
//                   {
//                    circuit.ajoutgate(new Xor(linetempo1));
//                   }
//                   else if(tempo_pattern1 =="FF")
//                   {
//                    circuit.ajoutgate(new Flipflop(linetempo1));
//                   }
//                   else if(tempo_pattern1 =="INVERSOR")
//                   {
//                    circuit.ajoutgate(new Inversor(linetempo1));
//                   }
//                   else if(tempo_pattern1 =="LATCH")
//                   {
//                    circuit.ajoutgate(new Latch(linetempo1));
//                   }
//                   else if(tempo_pattern1 =="MUX2")
//                   {
//                    circuit.ajoutgate(new Mux(linetempo1));
//                   }
//                   else if(tempo_pattern1 =="OR2")
//                   {
//                    circuit.ajoutgate(new Or(linetempo1));
//                   }
//                   //std::cout <<linetempo1<< '\n';
//                   i++;
//                 }
//
//     }
//       //cout<<line<<endl;
//       delete [] test;
//       }
// file.close();// fermer le fichier
//      }
//   else
//   {
//     cerr<<" failure for openning file operating point 1"<< endl;
//   }
////////////////////////////////////////////////


//
// Input t1;
// Output t2;
// Gate* t3;
// int nbligne=0;
// i=0;
//  std::cout << "ENFIN REALISONS LES INTERCONNEXIONS ENTRE LES PORTES,ENTREES ET SORTIES" << '\n'<<'\n'<<'\n';
//
// if (file)
// {
//   while(getline(file,line)){
//
//     size_t size=line.size()+1;// recupération de la longeur de la ligne lu par le fichier ainsi que le caractere de fin de ligne
//     char *test=new char[size];//  allocation dynamique d'un tableau de char en fontion de la longueur de la ligne lu
//     strncpy(test,line.c_str(),size);
//     if (strstr(test,fleche))
//     {
//         std::cout <<'\n'<< "EDITION DES LIENS " << '\n';
//         size_t position1=0;
//         size_t position2=0;
//         size_t  find_fleche=0;
//         size_t  find_virgule=0;
//         size_t find_last_fleche;
//             find_last_fleche=lineVerif.find_last_of("->");
//              std::cout << find_last_fleche << '\n';
//           do {
//             find_fleche=lineVerif.find("->",position1);
//             find_virgule=lineVerif.find(";",position1);
//             std::cout <<"*********"<< find_fleche<< '\n';
//             std::cout <<"****************"<< find_virgule << '\n';
//
//             if(find_virgule<find_fleche)
//             {
//               std::cout << '\n'<< "Verifiez la postion de vos délimiteurs ( ; ou -> )" << '\n';
//               exit(0);
//             }
//              position1++;
//
//          }while(position1!=find_last_fleche-1);
//     }
//
//
//   /*  int n=line.find("->");
//       int p=0;
//     if (word==(circuit.getInput(word)).getNom()) {
//
//       t1=circuit.getInput(word);
//
//       } else if (word==(circuit.getOutput(word)).getNom()) {
//
//       t2=circuit.getOutput(word);
//
//     } else if(word==((circuit.getGate(word))->getLabel())) {
//
//         t3=circuit.getGate(word);
//       }
//
//
//       istringstream  linearrow(line);
//       string arrow;*/
//
//
//
//
//   }
//
//
// }
// else
// {
//   cerr<<" failure for openning file operating point 2"<< endl;
// }

  return 0;
}
