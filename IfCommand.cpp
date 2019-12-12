//
// Created by tal on 12.12.2019.
//

#include "IfCommand.h"
int IfCommand::execute(vector<string> vector) {
  if (flag){
    command.execute();
  }
}
