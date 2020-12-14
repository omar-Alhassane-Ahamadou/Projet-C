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
/********************************************************************************************/
