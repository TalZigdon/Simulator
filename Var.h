//
// Created by tal on 12.12.2019.
//

#ifndef SIMULATOR__VAR_H_
#define SIMULATOR__VAR_H_
#include <string>
using namespace std;
class Var {
 public:
  Var(int value, const string &sim, bool is_input);
  int value;
  string sim;
  bool isInput;

};

#endif //SIMULATOR__VAR_H_
