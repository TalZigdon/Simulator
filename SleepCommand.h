//
// Created by tal on 12.12.2019.
//

#ifndef SIMULATOR__SLEEPCOMMAND_H_
#define SIMULATOR__SLEEPCOMMAND_H_

#include "Command.h"
class SleepCommand : public Command {
 public:
  Data* data;
  SleepCommand(Data* data);
  int execute(vector<string> vector, int index) override;

};

#endif //SIMULATOR__SLEEPCOMMAND_H_
