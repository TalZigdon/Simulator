#include "Command.h"
#include "map"
#include "vector"
#include "Lexer.h"
#include "Parser.h"
#include "Variables.h"

vector<string> lexer(string fileName);

int main(int argc, char **argv) {
  if (argc <= 1) {
    cout << "not enough arguments!" << endl;
  } else {
    Lexer lex = Lexer(argv[1]);
    Parser *parser1 = new Parser(lex.array);
    delete parser1;
    Variables::getInstance()->threadFlag = false;
    if(Variables::getInstance()->thr1.joinable())
      Variables::getInstance()->thr1.join();
    if(Variables::getInstance()->thr2.joinable())
      Variables::getInstance()->thr2.join();
    delete (Variables::getInstance());
  }
  return 0;
}
