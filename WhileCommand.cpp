//
// Created by tal on 12.12.2019.
//

#include "WhileCommand.h"
int WhileCommand::execute(vector<string> vector) {
  while (flag){
    for(Command c : lst) {
      c.execute();
    }
  }
}
