//
// Created by yoelsh on 10/12/2019.
//

#ifndef SIMULATOR__COMMAND_H_
#define SIMULATOR__COMMAND_H_
#include "string"
#include "unordered_map"
#include "vector"
using namespace std;

class Command {
 public:
  virtual int execute(vector<string> vector, int index);
};

#endif //SIMULATOR__COMMAND_H_
