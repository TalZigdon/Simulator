//
// Created by tal on 12.12.2019.
//

#include "PrintCommand.h"
int PrintCommand::execute(vector<string> vector, int index) {
  cout<< vector[index + 1] << endl;
  return (index + 2);
}
