//
// Created by tal on 10.12.2019.
//

#ifndef SIMULATOR_COMMANDS_DEFINEVARCOMMAND_H_
#define SIMULATOR_COMMANDS_DEFINEVARCOMMAND_H_

#include "Command.h"
#include "list"
class DefineVarCommand : public Command {
 public:
  list<Command> lst;
  int execute(vector<string> vector) override;
};

#endif //SIMULATOR_COMMANDS_DEFINEVARCOMMAND_H_
