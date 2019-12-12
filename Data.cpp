//
// Created by tal on 12.12.2019.
//

#include "Data.h"
#include "DefineVarCommand.h"
#include "PrintCommand.h"
#include "OpenServerCommand.h"
#include "SleepCommand.h"
#include "WhileCommand.h"
#include "ConnectControlClientCommand.h"
#include "IfCommand.h"
#include "Var.h"
void Data::insertCommandsToMap() {
  commands["var"] = new DefineVarCommand(this);
  commands["print"] = new PrintCommand(this);
  commands["openDataServer"] = new OpenServerCommand(this);
  commands["connectControlClient"] = new ConnectControlClientCommand(this);
  commands["if"] = new IfCommand(this);
  commands["sleep"] = new SleepCommand(this);
  commands["var"] = new

}
