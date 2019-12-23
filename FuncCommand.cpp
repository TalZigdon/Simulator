//
// Created by tal on 23/12/2019.
//

#include "FuncCommand.h"
#include "Parser.h"
int FuncCommand::execute(vector<string> vector, int index) {
  double val = Variables::getInstance()->doShuntingYard(vector[index + 1]);
  string temp = this->var + "=" + to_string(val);
  Variables::getInstance()->addVarToMap(temp);
  new Parser(funcVec);
  return 2;
}
FuncCommand::FuncCommand(vector<string> vector, string var) {
  funcVec = vector;
  this->var = var;
}
