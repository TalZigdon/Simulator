//
// Created by tal on 12.12.2019.
//

#include "Parser.h"
Parser::Parser(vector<string> array) {
  // parse vector and execute through map
  addCommandsToMap();
  int index = 0;
  Command* c;

  // executing every command
  while (index < array.size()) {
    // if it is an equal command line
    if (array[index].find("=") != string::npos) {
      c = commands["="];
    }
    else{
      if (commands.count(array[index]) > 0) {
        c = commands[array[index]];
      }
    }
    index += c->execute(array, index);
    cout<<"after first execute" << index<< endl;
  }
}
