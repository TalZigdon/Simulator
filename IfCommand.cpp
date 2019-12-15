//
// Created by tal on 12.12.2019.
//

#include "IfCommand.h"
int IfCommand::execute(vector<string> vector, int index) {
  ////there is a problem here, because if the flag is false we need to
  /// jump over the next indexes and we dont know how much we need to jump
  if (flag) {
    index = command.execute(vector, index);
  }
  return index;
}
