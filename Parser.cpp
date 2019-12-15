//
// Created by tal on 12.12.2019.
//

#include "Parser.h"
Parser::Parser(vector<string> array) {
  // parse vector and execute through map
  int index = 0;
  Command c;

  // executing every command
  while (index < array.size()) {
    // if it is an equal command line
    if (array[index].find("=") != string::npos) {
      c = map["="];
    }
    else{
      if (map.count(array[index]) != 0) {
        c = map[array[index]];
      }
    }
    index += c.execute(array, index);
  }
}
