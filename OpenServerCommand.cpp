//
// Created by yoelsh on 10/12/2019.
//

#include "OpenServerCommand.h"
int OpenServerCommand::execute(vector<string> vector, int index) {
  int port = stoi(vector[index + 1]);
  int socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd == -1) {
    //error
    std::cerr << "Could not create a socket"<<std::endl;
    return -1;
  }
  //bind socket to IP address
  // we first need to create the sockaddr obj.
  sockaddr_in address; //in means IP4
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
  address.sin_port = htons(port);
  //we need to convert our number
  // to a number that the network understands.
}
