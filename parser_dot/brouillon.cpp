/************ recherche et check caractere ****
  do
        file.get(character);
        if(character == ' ')
        {
          std::cout <<endl;
        }
        if(character == '[')
        {
          std::cout <<endl;
        }
        if(character == ']')
        {
          std::cout <<endl;
        }
        if(character == '"')
        {
          std::cout <<endl;
        }
        if(character == ';')
        {
          std::cout <<endl;
        }

        std::cout <<character;

      } while (!file.eof());// tant que l'on a pas atteint la fin du fichier*/

      /*********technique ne malade*******
       while(getline(file,line))   {
            stringstream iss(line);
            getline(iss, name, '[');
            getline(iss, label, ':');

        }*/

      /****technique de lesture auto
      while(file >> word) {
                for (auto c : word)
                    if (ispunct(c) && c != '`')
                        word.erase(word.find_first_of(c));
                cout << word << endl;*/
/*****************************test*************************/
                //   test.get(character)
                //
                //       if (tempo)
                //       {
                //         tempo <<character;
                //         tempo.close();
                //       }
                //       else
                //
                //       {
                //         cerr<<"failure for openning tempo"<< endl;
                //
                //       }
                //
                // } while (character !=' ');

/******************************************Affiche MAP**************************************************/

                  /*for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
                          cout << itr->first
                               << '\t' << itr->second << '\n';
                      }*/
/***************************************NEW SPLIT FLECHE*****************************************************/
/*string traitedline = line;
string  keyword = "->";
 size_t x= 0;
string word;
while ((x = traitedline.find(keyword)) != std::string::npos) {
word = traitedline.substr(0, x );
std::cout << word<<endl;

 if (word==(circuit.getInput(word)).getNom()) {

 t1=circuit.getInput(word);

 } else if (word==(circuit.getOutput(word)).getNom()) {

 t2=circuit.getOutput(word);

} else if(word==((circuit.getGate(word))->getLabel())) {

   t3=circuit.getGate(word);
 }




traitedline.erase(0, x  + keyword.length());
}*/
  //cout << traitedline << std::endl;

  /**************************************/
  //   istringstream  linelikefile1(line);
  //   string line;
  //   getline(linelikefile,linetempo,' ');
    // std::cout <<linetempo<< '\n';
/************************************TOUS MON ANCIEN CODE POUR PARSING FLECHE***************************/
/*while(getline(file,line)){

  size_t size=line.size()+1;// recupération de la longeur de la ligne lu par le fichier ainsi que le caractere de fin de ligne
  char *test=new char[size];//  allocation dynamique d'un tableau de char en fontion de la longueur de la ligne lu
  strncpy(test,line.c_str(),size);
  if (strstr(test,fleche))
  {
/*      if (word==(circuit.getInput(word)).getNom()) {

    t1=circuit.getInput(word);

    } else if (word==(circuit.getOutput(word)).getNom()) {

    t2=circuit.getOutput(word);

  } else if(word==((circuit.getGate(word))->getLabel())) {

      t3=circuit.getGate(word);
    }*/

    istringstream  linearrow(line);
    string arrow;
    getline(linearrow,arrow,' ');
    std::cout <<arrow<< '\n';
    getline(linearrow,arrow,' ');
    getline(linearrow,arrow,' ');
    std::cout <<arrow<< '\n';











    i++;
  }

}*/
//std::cout <<i<< '\n';
