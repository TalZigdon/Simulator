//
// Created by tal on 12.12.2019.
//

#ifndef SIMULATOR__VARIABLES_H_
#define SIMULATOR__VARIABLES_H_
#include <unordered_map>
#include <mutex>
#include "string"
#include "Var.h"
#include "ShuntingYard.h"
#include "thread"
#include <queue>
// a singleton class
class Variables {
 private:
  Interpreter *i1;
  unordered_map<string, Var*> programMap;
  unordered_map<string, Var*> simMap;
  vector<double> symbolsValues;
  mutex mapLock;
  static Variables *instance;
  Variables();
 public:
  queue<Var*> queOfVarsToPushToTheServer;
  thread thr1;
  thread thr2;
  //check if the object is already exists, if not,make a new one, else return the last one.
  double doShuntingYard(string str);
  void addVarToMap(string str);
  bool UpdateValueOfProgramVar(string str, double newVal);
  void UpdateSymbolsValueFromServer(vector<double> vec);

  void InitializeSymbols();

  static Variables *getInstance() {
    if (!instance)
      instance = new Variables();
    return instance;
  }
  void InsertToQueOfVarsToPushToTheServer(Var* var){
    queOfVarsToPushToTheServer.push(var);
  }
  void setVar(string v, Var* var) {
    programMap[v] = var;
  }

  unordered_map<string, Var*> getProgramMap() {
    return programMap;
  }

  unordered_map<string, Var*> getSimMap(){
    return simMap;
  }

  Var *getVar(string v) {
    return programMap[v];
  }

 protected:
  virtual ~Variables() {};
};





#endif //SIMULATOR__VARIABLES_H_
