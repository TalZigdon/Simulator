//
// Created by tal on 12.12.2019.
//

#include "WhileCommand.h"
#include "Parser.h"
int WhileCommand::execute(vector<string> vector1, int index) {
  vector<string> tempStringToParsInWhile;
  Command *c;
  int saveTheNumberOfTheLastIndexInWhile = index + 2;
  while (vector1[saveTheNumberOfTheLastIndexInWhile] != "}") {
    saveTheNumberOfTheLastIndexInWhile++;
    tempStringToParsInWhile.push_back(vector1[saveTheNumberOfTheLastIndexInWhile]);
  }
  flag = IsConditionIsTrue(vector1[index + 1]);
  while (flag) {
    new Parser(tempStringToParsInWhile);
    flag = IsConditionIsTrue(vector1[index + 1]);
  }
  //check how much indexes are in the while!
  return saveTheNumberOfTheLastIndexInWhile - index + 1;
}
