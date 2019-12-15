//
// Created by tal on 12.12.2019.
//

#ifndef SIMULATOR__VARIABLES_H_
#define SIMULATOR__VARIABLES_H_
#include <unordered_map>
#include "string"
#include "Var.h"
#include "ShuntingYard.h"
// a singleton class
class Variables {
 private:
  static Interpreter i1;
  static unordered_map<string, Var> map;
  static Variables *instance;
 public:
  //check if the object is already exists, if not,make a new one, else return the last one.
  static double doShuntingYard(string str);
  static void addVarToInterpreter(string name, string val);
  static Variables *getInstance() {
    if (!instance)
      instance = new Variables;
    return instance;
  }
  static void setVar(string v, Var var) {
    map[v] = var;
  }
  static unordered_map<string, Var> getMap() {
    return map;
  }
  static Var &getVar(string v) {
    return map[v];
  }
 protected:
  virtual ~Variables() {};
};

#endif //SIMULATOR__VARIABLES_H_
