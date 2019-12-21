#include "Command.h"
#include "map"
#include "vector"
#include "Lexer.h"
#include "Parser.h"

vector<string> lexer(string fileName);

int main(int argc, char **argv) {
  // create symbol map
  // create map of commands
  Lexer lex = Lexer(argv[1]);
  Parser *parser1 = new Parser(lex.array);
  Variables::getInstance()->thr1.join();
  Variables::getInstance()->thr2.join();
  return 0;
}

void parser(vector<string> array, map<string, Command> map) {
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