//
// Created by tal on 12.12.2019.
//

#include "Parser.h"
Parser::Parser(vector<string> array) {
  // parse vector and execute through map
  int index = 0;

  // executing every command
  while (index < array.size()) {
    if (map.count(array[index]) != 0) {
      Command c = map[array[index]];
      index += c.execute(array, index);
    }
  }
}
