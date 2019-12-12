//
// Created by tal on 12.12.2019.
//

#include <algorithm>
#include "Lexer.h"
Lexer::Lexer( string fileName) {
  int i = 0;
  string line, temp = "";
  vector<string> vec;
  fstream file;
  bool insertedLine = false;

  file.open(fileName, ios::in);
  if (!file) {
    cout << "bad file" << endl;
  }

  //cross on the file line-line
  while (!file.eof()) {
    insertedLine = false;
    getline(file, line);
    //insert a string and split the strings by ' ', '(', ')', ','
    while (i < line.size()) {
      // if the sign is "equal", we reaced a mathematical ass
      while (i< line.size() && line[i] != '(' && line[i] != ')' && line[i] != ',') {
        if (line[i] == '=') {
          i++;
          if (line[i] == ' ') {
            i++;
          }
          temp.erase(remove_if(temp.begin(), temp.end(), ::isspace));
          vec.insert(vec.end(), temp);
          temp = line.substr(i, line.size()-1);
          temp.erase(remove_if(temp.begin(), temp.end(), ::isspace));
          vec.insert(vec.end(), temp);
          i = line.size();
          insertedLine = true;
          temp = "";
          break;
        }
        temp += line[i];
        i++;
      }

      if (!insertedLine) {
        //insert the strings to the vector.
        temp.erase(remove_if(temp.begin(), temp.end(), ::isspace));
        vec.insert(vec.end(), temp);
        //initialize the parameters.
        temp = "";
        i++;
      }
    }
    //initialize i for the next line.(if there is more line)
    i = 0;
  }

  for (i = 0; i < vec.size() ; i++) {
    cout << vec[i] << endl;
  }

  this->array = vec;
}
