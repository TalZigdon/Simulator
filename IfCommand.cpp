//
// Created by tal on 12.12.2019.
//

#include "IfCommand.h"
int IfCommand::execute(vector<string> vector, int index) {
  if (flag) {
    command.execute(vector, index);
  }
}
