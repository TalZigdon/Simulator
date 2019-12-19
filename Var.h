//
// Created by tal on 12.12.2019.
//

#ifndef SIMULATOR__VAR_H_
#define SIMULATOR__VAR_H_
#include <string>
using namespace std;
class Var {
  int value;
  string simPath;
  bool isInput;
 public:
  Var(int value, const string &sim, bool is_input);
  const string &GetSim() const;
  int GetValue() const;
  bool IsInput() const;

};

#endif //SIMULATOR__VAR_H_
