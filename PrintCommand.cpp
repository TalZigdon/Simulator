//
// Created by tal on 12.12.2019.
//

#include "PrintCommand.h"
int PrintCommand::execute(vector<string> vector, int index) {
  //check if there "" in the string or its a number.
  char ch = 34;
  if (vector[index + 1].find(ch) != string::npos)
    cout << vector[index + 1] << endl;
  else
    cout << Variables::getInstance()->programMap[vector[index+1]]->GetValue() << endl;
  return 2;
}
