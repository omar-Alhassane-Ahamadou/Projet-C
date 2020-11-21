#include<iostream>
#include<fstream>
using namespace std;
int main(){
  fstream Lecture_file("MUX2-1.gv", ios::in);
  string line ;
  while(getline(Lecture_file, line)){
    cout<<line<<endl;
  }
  cout<<"Fin de la Lecture des données du fichier"<<endl;
  Lecture_file.close();
  return 0;
}
