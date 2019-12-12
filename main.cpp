#include <iostream>
#include <fstream>
#include "Command.h"
#include "map"
#include "unordered_map"
#include "vector"

vector<string> lexer(string fileName);

int main(int argc, char **argv) {
  // create symbol map
  // create map of commands
  lexer(argv[1]);

  return 0;
}

vector<string> lexer(string fileName) {
  // create array of strings
  int i = 0;
  string line, temp = "";
  vector<string> vec;
  fstream file;
  file.open(fileName, ios::in);
  if (!file) {
    cout << "bad file" << endl;
  }
  //cross on the file line-line
  while (!file.eof()) {
    getline(file, line);
    //insert a string and split the strings by ' ', '(', ')', ','
    while (i < line.size()) {
      // if the sign is "equal", we reaced a mathematical ass
      if (line[i] == '=') {

      }
      while (i< line.size() && line[i] != '(' && line[i] != ')' && line[i] != ',') {

        temp += line[i];
        i++;
      }
      //insert the strings to the vector.
      vec.insert(vec.end(), temp);
      //initialize the parameters.
      temp = "";
      i++;
    }
    //initialize i for the next line.(if there is more line)
    i = 0;
  }

  for(i=0; i< vec.size(); i++) {
    cout << vec[i] << endl;
  }
}

void parser(vector<string> array, map<string, Command> map) {
  // parse vector and execute through map
  int index = 0;

  // executing every command
  while (index < array.size()) {
    if (map.count(array[index]) != 0) {
      Command c = map[array[index]];
      index += c.execute(array, index);
    }
  }
}