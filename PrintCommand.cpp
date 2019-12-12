//
// Created by tal on 12.12.2019.
//

#include "PrintCommand.h"
int PrintCommand::execute(vector<string> vector, int index) {
  return Command::execute(vector, index);
}
PrintCommand::PrintCommand(Data *data) {
  this->data = data;
}
