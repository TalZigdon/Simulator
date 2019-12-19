//
// Created by tal on 19/12/2019.
//

#include "ConditionCommand.h"

bool ConditionCommand::isConditionIsTrue(std::string stringOfCondition) {
    char* tempToSplitString;
    if(stringOfCondition.find("==") != string::npos)
      //tempToSplitString = std::strtok(stringOfCondition.c_str(), " =")
      // if()
      return false;
}

