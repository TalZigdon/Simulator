//
// Created by tal on 14.12.2019.
//

#include "EqualCommand.h"
int EqualCommand::execute(vector<string> vector, int index) {
  Variables::getInstance()->addVarToMap(vector[index]);
}

