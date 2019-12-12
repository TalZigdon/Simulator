//
// Created by tal on 12.12.2019.
//

#ifndef SIMULATOR__PARSER_H_
#define SIMULATOR__PARSER_H_
using namespace std;
#include "unordered_map"
#include "Command.h"
#include "vector"

class Parser {
 public:
  Parser(vector<string> array, unordered_map<string, Command> map);
 private:
  unordered_map <string,Command> map;

};

#endif //SIMULATOR__PARSER_H_
