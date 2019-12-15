//
// Created by tal on 10.12.2019.
//

#include "DefineVarCommand.h"
int DefineVarCommand::execute(vector<string> vector, int index) {
  bool flag = false;
  string name = vector[index + 1];
  double value;
  if(vector[index + 2] == "->")
    flag = true;
  //value = shuntingYard(vector[index + 3]);
  Var * v = new Var(value, name, flag);
  Variables::setVar(vector[index], *v);
  return (index + 4);
}
