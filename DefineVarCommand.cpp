//
// Created by tal on 10.12.2019.
//

#include "DefineVarCommand.h"
int DefineVarCommand::execute(vector<string> vector, int index) {
  bool simIsEffectedByVar = false;
  string pathInSim = vector[index + 4];
  double value;
  if(vector[index + 2] == "->")
    simIsEffectedByVar = true;
//initialize the value to 0
  Var *v = new Var(0, pathInSim, simIsEffectedByVar);
  Variables::getInstance()->setVar(vector[index + 1], v);
  return 5;
}
