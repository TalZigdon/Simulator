//
// Created by tal on 12.12.2019.
//

#ifndef SIMULATOR_VARIABLES_H
#define SIMULATOR_VARIABLES_H
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
  unordered_map<string, Var *> simMap;
  vector<double> symbolsValues;
  mutex mapLock;
  static Variables *instance;
  Variables();
 public:
  Interpreter *i1;
  unordered_map<string, string> fromPathToVar;
  unordered_map<string, Var *> programMap;
  queue<Var *> queOfVarsToPushToTheServer;
  thread thr1;
  thread thr2;
  bool threadFlag = true;
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
  void InsertToQueOfVarsToPushToTheServer(Var *var) {
    mapLock.try_lock();
    string str = var->GetSim();
    double val = var->GetValue();
    Var *temp = new Var(val, str, false);
    queOfVarsToPushToTheServer.push(temp);
    mapLock.unlock();
  }
  void setVar(string const v, Var *var) {
    programMap[v] = var;
  }

  unordered_map<string, Var *> getProgramMap() {
    return programMap;
  }

  unordered_map<string, Var *> getSimMap() {
    return simMap;
  }

  Var *getVar(string const v) {
    return programMap[v];
  }

 protected:
  virtual ~Variables() {
    for (pair<string, Var *> element: programMap) {
      delete (element.second);
    }
    for (pair<string, Var *> element: simMap) {
      delete (element.second);
    }
    while (!queOfVarsToPushToTheServer.empty()) {
      delete queOfVarsToPushToTheServer.front();
      queOfVarsToPushToTheServer.pop();
    }
    delete (i1);
  };
};
#endif //SIMULATOR_VARIABLES_H