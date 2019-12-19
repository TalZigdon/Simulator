//
// Created by tal on 10.12.2019.
//

#include "DefineVarCommand.h"
int DefineVarCommand::execute(vector<string> vector, int index) {
  string name = vector[index+1];
  bool bindedToRight = false;
  if (vector[index+2] == "->")
    bindedToRight= true;
  string simLocation = vector[index + 4];

  // iterate over map of vars of sim to find the correct var.
  // after var is found, insert var with the var name to program map
  for (std::pair<std::string, Var*> element : Variables::getInstance()->getSimMap()) {
    if (element.second->GetSim() == simLocation) {
      Variables::getInstance()->getProgramMap()[name] = element.second;
    }
  }
  //  bool simIsEffectedByVar = false;
//  string name = vector[index + 1];
//  double value;
//  if(vector[index + 2] == "->")
//    simIsEffectedByVar = true;
////initialize the value to 0
//  Var *v = new Var(0, name, simIsEffectedByVar);
//  Variables::getInstance()->setVar(vector[index], v);
  return 5;
}
