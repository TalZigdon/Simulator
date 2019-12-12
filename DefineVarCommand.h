//
// Created by tal on 10.12.2019.
//

#ifndef SIMULATOR_COMMANDS_DEFINEVARCOMMAND_H_
#define SIMULATOR_COMMANDS_DEFINEVARCOMMAND_H_

#include "Command.h"
#include "list"
#include "Data.h"

class DefineVarCommand : public Command {
 public:
  list<Command> lst;
  Data * data;
  DefineVarCommand(Data * data);
  int execute(vector<string> vector, int index) override;
};

#endif //SIMULATOR_COMMANDS_DEFINEVARCOMMAND_H_
