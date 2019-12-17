//
// Created by tal on 12.12.2019.
//

#ifndef SIMULATOR__PARSER_H_
#define SIMULATOR__PARSER_H_
using namespace std;
#include "unordered_map"
#include "Command.h"
#include "vector"
#include "DefineVarCommand.h"
#include "PrintCommand.h"
#include "OpenServerCommand.h"
#include "ConnectControlClientCommand.h"
#include "IfCommand.h"
#include "SleepCommand.h"
#include "ShuntingYard.h"
#include "EqualCommand.h"
#include "WhileCommand.h"
class Parser {
  unordered_map <string, Command*> commands;
 public:
  Parser(vector<string> array);
 private:
  unordered_map <string,Command> map;
  void addCommandsToMap(){
    commands["var"] = new DefineVarCommand();
    commands["print"] = new PrintCommand();
    commands["openDataServer"] = new OpenServerCommand();
    commands["connectControlClient"] = new ConnectControlClientCommand();
    commands["if"] = new IfCommand();
    commands["sleep"] = new SleepCommand();
    commands["="] = new EqualCommand();
    commands["while"] = new WhileCommand();
  /*  //map["var"] = DefineVarCommand();
    map["print"] = PrintCommand();
    map["openDataServer"] = OpenServerCommand();
    map["if"] = IfCommand();
    map["sleep"] = SleepCommand();
    map["="] = *(commands["="]);
    map["while"] = *(commands["while"]);*/
  }
};

#endif //SIMULATOR__PARSER_H_
