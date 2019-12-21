//
// Created by tal on 14.12.2019.
//

#include <algorithm>
#include "EqualCommand.h"
int EqualCommand::execute(vector<string> vector, int index) {
    //insert to the map of the interpreter.
  vector[index].erase(std::remove_if(vector[index].begin(), vector[index].end(), ::isspace), vector[index].end());
  Variables::getInstance()->addVarToMap(vector[index]);

  return 1;
}

