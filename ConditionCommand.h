//
// Created by tal on 12.12.2019.
//

#ifndef SIMULATOR__CONDITIONCOMMAND_H_
#define SIMULATOR__CONDITIONCOMMAND_H_

#include "Command.h"
#include "string"
using namespace std;
class ConditionCommand : public Command{
 public:
  bool flag;
//  string string;
  //bool isConditionIsTrue(std::string stringOfCondition);

};

/*bool ConditionCommand::isConditionIsTrue(std::string stringOfCondition) {
    char* tempToSplitString;
    if(stringOfCondition.find("==") != string::npos)
        tempToSplitString = std::strtok(stringOfCondition.c_str(), " =")
        if()
    return false;
}*/

#endif //SIMULATOR__CONDITIONCOMMAND_H_
