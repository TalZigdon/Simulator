//
// Created by yoelsh on 10/12/2019.
//

#ifndef SIMULATOR__COMMAND_H_
#define SIMULATOR__COMMAND_H_
#include "string"
#include "unordered_map"

using namespace std;

class Command {
 public:
  virtual int execute(string string) = 0;
};

#endif //SIMULATOR__COMMAND_H_
