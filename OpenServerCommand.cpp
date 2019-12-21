//
// Created by yoelsh on 10/12/2019.
//

#include <cstring>
#include <mutex>
#include "OpenServerCommand.h"

std::mutex mutex_lock;

//vector<double> splitIntoVectorFirstTime(string buffer) {
//  vector<double> vec1;
//
//  auto index = buffer.find_first_of('\n');
//  string delimiterOfAllText = ",";
//  size_t posOfAllText = 0;
//  string tokenOfAllText;
//  size_t endOfLine;
//
//  while ((posOfAllText = buffer.find(delimiterOfAllText)) != string::npos) {
//    tokenOfAllText = buffer.substr(0, posOfAllText);
//    buffer.erase(0, posOfAllText + delimiterOfAllText.length());
//    vec1.push_back(stoi(tokenOfAllText));
//  }
//
//  ///inserting last token of buffer
//  endOfLine = buffer.find('\n');
//  if (endOfLine != string :: npos)
//    buffer.erase(endOfLine, 1);
//  if(buffer != "")
//    vec1.push_back(stoi(buffer));
//  return vec1;
//}

vector<double> splitIntoVector(string buffer) {
//  auto index1 = buffer.find_first_of('\n');
//  auto index2 = buffer.find_first_of('\n', index1 + 1);
//
//  // if there is enough data before the first \n, insert it.
//  if (index2 == string::npos && index1 >= 325)
//    return splitIntoVectorFirstTime(buffer);
//
//  //auto x = buffer.length();
//  buffer.erase(index2+1, buffer.length()-index2);
//  buffer.erase(0, index1);

  vector<double> vec1;

  string delimiterOfAllText = ",";
  size_t posOfAllText = 0;
  string tokenOfAllText;
  size_t endOfLine;

  while ((posOfAllText = buffer.find(delimiterOfAllText)) != string::npos) {
    tokenOfAllText = buffer.substr(0, posOfAllText);
    buffer.erase(0, posOfAllText + delimiterOfAllText.length());
    vec1.push_back(stoi(tokenOfAllText));
  }
  return vec1;
}

string copyToString(string remainingChunk, char* buffer, size_t numberOfCharsToCopy) {
  string str = "";
  for (int i = 0; i < numberOfCharsToCopy; ++i) {
    str += buffer[i];
  }
  return str;
}

//fuct to read from server
void readFromServer(int client_socket) {
  bool firstTimeRecievedBufferFromServer = true;
  vector<double> vectorOfValuesFromServer;
  string remainingChunk = "";
  string temp = "";
  size_t indexOfFirstEndOfLine;
  while (true) {
    mutex_lock.lock();
    bool firstIteration = true;
    char buffer[1024] = {0};
    int valread = read(client_socket, buffer, 1024);
    string str(buffer);
    /*
    if (firstTimeRecievedBufferFromServer) {
      firstTimeRecievedBufferFromServer = false;
      vectorOfValuesFromServer = splitIntoVectorFirstTime(buffer);
    } else {
      vectorOfValuesFromServer = splitIntoVector(buffer);
    }
     */

    indexOfFirstEndOfLine = str.find_first_of('\n');
    while (indexOfFirstEndOfLine != string::npos) {
      if (firstIteration) {
        firstIteration = false;
        temp = remainingChunk + str.substr(0, indexOfFirstEndOfLine);
      }
      else {
        temp = str.substr(0, indexOfFirstEndOfLine);
      }
      vectorOfValuesFromServer = splitIntoVector(temp);
      str.erase(0, indexOfFirstEndOfLine+1);
      Variables::getInstance()->UpdateSymbolsValueFromServer(vectorOfValuesFromServer);
      indexOfFirstEndOfLine = str.find_first_of('\n');
    }
    remainingChunk = str;
    mutex_lock.unlock();
  }
}

int OpenServerCommand::execute(vector<string> vector, int index) {
  {
    Variables::getInstance()->InitializeSymbols();
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
      //error
      std::cerr << "Could not create a socket" << std::endl;
      return -1;
    }

    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    /////shunting yard need here!!!
    address.sin_port = htons(Variables::getInstance()->doShuntingYard(vector[index + 1]));
    //we need to convert our number
    // to a number that the network understands.

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
      std::cerr << "Could not bind the socket to an IP" << std::endl;
      return -2;
    }

    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
      std::cerr << "Error during listening command" << std::endl;
      return -3;
    } else {
      std::cout << "Server is now listening ..." << std::endl;
    }

    // accepting a client
    int client_socket = accept(socketfd, (struct sockaddr *) &address,
                               (socklen_t *) &address);

    if (client_socket == -1) {
      std::cerr << "Error accepting client" << std::endl;
      return -4;
    }

    close(socketfd); //closing the listening socket
    //thread thread1(readFromServer, client_socket);
    //Variables::getInstance()->thr1 = thread(readFromServer, client_socket);
    //thread1.detach();
    return 2;
  }
}
