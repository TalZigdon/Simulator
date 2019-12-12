//
// Created by yoelsh on 10/12/2019.
//

#ifndef SIMULATOR_COMMANDS_OPENSERVERCOMMAND_H_
#define SIMULATOR_COMMANDS_OPENSERVERCOMMAND_H_

#include "Command.h"


class OpenServerCommand : public Command {
 public:
  int execute(vector<string> vector, int index) override;

};

#endif //SIMULATOR_COMMANDS_OPENSERVERCOMMAND_H_
