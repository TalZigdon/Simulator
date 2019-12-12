//
// Created by tal on 12.12.2019.
//

#ifndef SIMULATOR__SLEEPCONDITION_H_
#define SIMULATOR__SLEEPCONDITION_H_

#include "Command.h"
class SleepCondition : public Command {
 public:
  int execute(vector<string> vector, int index) override;

};

#endif //SIMULATOR__SLEEPCONDITION_H_
