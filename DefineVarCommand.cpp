//
// Created by tal on 10.12.2019.
//

#include "DefineVarCommand.h"
int DefineVarCommand::execute(vector<string> vector, int index) {
  bool simIsEffectedByVar = false;
  string name = vector[index + 1];
  double value;
  if(vector[index + 2] == "->")
    simIsEffectedByVar = true;
  // define value through client-server from sim
  Var *v = new Var(value, name, simIsEffectedByVar);
  Variables::setVar(vector[index], *v);
  return (index + 4);
}
