//
// Created by tal on 12.12.2019.
//

#include <algorithm>
#include "Lexer.h"
Lexer::Lexer(string fileName) {
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
      // if the sign is "equal", we reached a mathematical ass
      while (i < line.size() && line[i] != '(' && line[i] != ')' && line[i] != ',') {
//        // if reached an assignment - split to var andd value
//        if (line[i] == '=' && !(line[i-1] == '<' || line[i+1] == '>')) {
//          if (temp != "") {
//            temp.erase(std::remove(temp.begin(), temp.end(), '\t'), temp.end());
//            vec.insert(vec.end(), temp);
//            temp = "";
//            equalInserted = true;
//          }
//          vec.insert(vec.end() ,"=");
//          i++;
//          // skip space if exist
//          if (line[i] == ' ') {
//            i++;
//          }
//          // insert var
//          if (!equalInserted) {
//            temp.erase(std::remove(temp.begin(), temp.end(), '\t'), temp.end());
//            vec.insert(vec.end(), temp);
//          }
//          // create and insert value
//          temp = line.substr(i, line.size()-1);
//          temp.erase(std::remove(temp.begin(), temp.end(), '\t'), temp.end());
//          vec.insert(vec.end(), temp);
//          i = line.size();
//          insertedLine = true;
//          temp = "";
//          break;
//        }
        temp += line[i];
        i++;
      }

      if (!insertedLine) {
        //insert the strings to the vector.
        temp.erase(std::remove(temp.begin(), temp.end(), '\t'), temp.end());
        auto check = temp.find("while");
        auto check1 = temp.find("var");
        // if it is a while command - split correctly
        if (check != string::npos) {
          // insert while
          string temp1 = temp.substr(check, 5);
          vec.insert(vec.end(), temp1);
          // insert condition
          auto check2 = temp.size() - temp1.size();
          temp1 = temp.substr(check + 6, check2);
          temp1 = temp1.substr(0, temp1.size() - 2);
          temp1.erase(std::remove_if(temp1.begin(), temp1.end(), ::isspace), temp1.end());
          vec.insert(vec.end(), temp1);
          // insert the {
          temp1 = temp.substr(temp.size() - 1, 1);
          vec.insert(vec.end(), temp1);
        }
          // if it is a var command - split correctly
        else if (check1 != string::npos) {
          // insert "val"
          string temp1 = temp.substr(check1, 3);
          vec.insert(vec.end(), temp1);
          // insert name of val
          auto check2 = temp.find("<-");
          if (check2 == string::npos) {
            check2 = temp.find("->");
          }
          if (check2 != string::npos) {
            temp1 = temp.substr(check1 + 4, check2 - (check1 + 4));
            temp1.erase(std::remove_if(temp1.begin(), temp1.end(), ::isspace), temp1.end());
            vec.insert(vec.end(), temp1);
            // insert arrow
            temp1 = temp.substr(check2, 2);
            vec.insert(vec.end(), temp1);
            // insert sim
            check2 = temp.find("sim");
            temp1 = temp.substr(check2, 3);
            vec.insert(vec.end(), temp1);
          }
        } else {
          vec.insert(vec.end(), temp);
        }
        //initialize the parameters.
        temp = "";
        i++;
      }
    }
    //initialize i for the next line.(if there is more line)
    i = 0;
  }


  for (i = 0; i < vec.size(); i++) {
    cout << vec[i] << endl;
  }


  this->array = vec;
}
