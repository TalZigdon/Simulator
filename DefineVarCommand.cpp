//
// Created by tal on 10.12.2019.
//

#include "DefineVarCommand.h"
int DefineVarCommand::execute(vector<string> vector, int index) {
    bool simIsEffectedByVar = false;
    string name = vector[index + 1];
    if (vector[index + 2] == "->")
        simIsEffectedByVar = true;
//initialize the value to 0
    Var *v = new Var(0, name, simIsEffectedByVar);
    Variables::getInstance()->setVar(vector[index], v);
    return (index + 4);
}
