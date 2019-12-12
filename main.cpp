#include <iostream>
#include <fstream>
#include "Command.h"
#include "map"
#include "unordered_map"
#include "vector"

int main(int argc, char **argv) {
  //create map here

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
    throw "bad file";
  }
  //cross on the file line-line
  while (!file.eof()) {
    getline(file, line);
    //insert a string and split the strings by ' ', '(', ')', ','
    while (i < line.size()) {
      while (line[i] != ' ' && line[i] != '(' && line[i] != ')' && line[i] != ',' ) {
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
}

void parser(vector<string> array, map <string, Command> map ) {
  // parse vector and execute through map
  int index = 0;

  // executing every command
  while (index < array.size()) {
    Command c = map[array[index]];
    if (c != NULL) {
      index += c.execute();
    }
  }
}