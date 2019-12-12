//
// Created by tal on 12.12.2019.
//

#ifndef SIMULATOR__VAR_H_
#define SIMULATOR__VAR_H_
#include <string>
#include "Command.h"
using namespace std;
class Var : public Command{
 public:
  int value;
  string sim;
  bool isInput;
  Data* data;
  Var(Data* data);

};

#endif //SIMULATOR__VAR_H_
