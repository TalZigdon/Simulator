//
// Created by tal on 12.12.2019.
//

#include "IfCommand.h"
int IfCommand::execute(vector<string> vector, int index) {
  ////there is a problem here, because if the flag is false we need to
  /// jump over the next indexes and we dont know how much we need to jump
  flag = IsConditionIsTrue(vector[index + 1]);
  int count = index;
  if (flag) {
    return command.execute(vector, index) + 2;
  }
  ////there is a problem here, we need to jump over all the indexes in the if.
  while(vector[count] != "}"){
    count++;
  }
  return count - index + 1;
}
