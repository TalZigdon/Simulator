//
// Created by tal on 12.12.2019.
//

#include "WhileCommand.h"
#include "Parser.h"
int WhileCommand::execute(vector<string> vector, int index) {

  //unordered_map<string,Command> map = Parser::getMap();
  int counter = index + 3;
  Command * c;
  int saveTheNumberOfTheLastIndexInWhile = index;
  flag = IsConditionIsTrue(vector[index + 1]);
  while (flag) {
      counter += c->execute(vector, counter);
    //initialize for the next for loop
    counter = index + 1;
    flag = IsConditionIsTrue(vector[index + 1]);
  }
  //check how much indexes are in the while!
  while(vector[saveTheNumberOfTheLastIndexInWhile] != "}"){
    saveTheNumberOfTheLastIndexInWhile++;
  }
  return saveTheNumberOfTheLastIndexInWhile - index + 1;
}
