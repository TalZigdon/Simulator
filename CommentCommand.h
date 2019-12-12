//
// Created by tal on 10.12.2019.
//

#ifndef SIMULATOR_COMMANDS_COMMENTCOMMAND_H_
#define SIMULATOR_COMMANDS_COMMENTCOMMAND_H_

#include "Command.h"
class CommentCommand : public Command{
 public:
  int execute(vector<string> vector, int index) override;

};

#endif //SIMULATOR_COMMANDS_COMMENTCOMMAND_H_
