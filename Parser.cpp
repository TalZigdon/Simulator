//
// Created by tal on 12.12.2019.
//

#include <mutex>
#include "Parser.h"
#include "FuncCommand.h"

/*std::mutex mutex_lock;


void splitIntoVector(string buffer, vector<double> vec) {
    string delimiterOfAllText = ",";
    size_t posOfAllText = 0;
    string tokenOfAllText;
    while ((posOfAllText = buffer.find(delimiterOfAllText)) != string::npos) {
        tokenOfAllText = buffer.substr(0, posOfAllText);
        buffer.erase(0, posOfAllText + delimiterOfAllText.length());
        vec.push_back(stoi(tokenOfAllText));
    }
}

void readFromServer(int client_socket) {
    vector<double> vectorOfValuesFromServer;
    while (true) {
        mutex_lock.lock();
        //char *hello = "Hello, I can hear you! \n";
        //send(client_socket, hello, strlen(hello), 0);
        //std::cout << "Hello message sent\n" << std::endl;
        char buffer[1024] = {0};
        int valread = read(client_socket, buffer, 1024);
        std::cout << buffer << std::endl;
        splitIntoVector(buffer, vectorOfValuesFromServer);
        Variables::getInstance()->UpdateSymbolsValueFromServer(vectorOfValuesFromServer);
        mutex_lock.unlock();
    }
}*/

Parser::Parser(vector<string> array) {
  // parse vector and execute through map
  addCommandsToMap();
  int index = 0;
  Command *c;
  // executing every command
  while (index < array.size()) {
    // if it is an equal command line
    //  if(Variables::getInstance()->getMap().count(array[index]) > 0) {
    //    Variables::getInstance().
    // }
//    if (array[index] == "autostart = 1")
//      int x = 0;
    if (array[index].find("=") != string::npos) {
      c = commands["="];
      index += c->execute(array, index);
    } else {
      if (commands.count(array[index]) > 0) {
        c = commands[array[index]];
        index += c->execute(array, index);
      } else {
        index += createFuncCommand(array, index);
      }
    }
    //cout << "after index" << index << endl;
  }
}
unordered_map<string, Command *> Parser::getMap() {
  return this->commands;
}
Parser::~Parser() {
  for (pair<string, Command *> element: commands) {
    delete element.second;
  }

}
int Parser::createFuncCommand(vector<string> vector1, int index) {
  vector<string> funcVec;
  int countParent = 1;
  int countIndex = index + 4;
  while (countParent) {
    funcVec.push_back(vector1[countIndex]);
    countIndex++;
    if (vector1[countIndex] == "{")
      countParent++;
    if (vector1[countIndex] == "}")
      countParent--;
  }
  commands[vector1[index]] = new FuncCommand(funcVec, vector1[index + 2]);
  return countIndex - index + 1;
}

