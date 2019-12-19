//
// Created by tal on 14.12.2019.
//

#include "EqualCommand.h"
int EqualCommand::execute(vector<string> vector, int index) {
    //insert to the map of the interpreter.
  Variables::getInstance()->addVarToMap(vector[index]);
}

