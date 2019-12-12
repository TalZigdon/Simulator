//
// Created by tal on 12.12.2019.
//

#ifndef SIMULATOR__DATA_H_
#define SIMULATOR__DATA_H_
#include "string"
#include "unordered_map"
#include "Command.h"
class Data {
 public:
  unordered_map<string, double> shuntingMap;
  unordered_map<string, *Command> commands;
  void insertCommandsToMap();

};

#endif //SIMULATOR__DATA_H_
