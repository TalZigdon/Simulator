//
// Created by tal on 12.12.2019.
//

#include "Variables.h"
Variables *Variables::instance = 0;

double Variables::doShuntingYard(string str) {
 i1->shuntingYard(str);
 return i1->createExp()->calculate();
}

void Variables::addVarToMap(string str) {
  i1->generateVarAndVal(str);
}

Variables::Variables() {
  this->i1 = new Interpreter();
}

void Variables::InitializeSymbols() {
    symbolsDirections["/instrumentation/airspeed-indicator/indicated-speed-kt"] = 0;
    symbolsDirections["/instrumentation/heading-indicator/offset-deg"] = 1;
    symbolsDirections["/instrumentation/altimeter/indicated-altitude-ft"] = 2;
    symbolsDirections["/instrumentation/altimeter/pressure-alt-ft"] = 3;
    symbolsDirections["/instrumentation/attitude-indicator/indicated-pitch-deg"] = 4;
    symbolsDirections["/instrumentation/attitude-indicator/indicated-roll-deg"] = 5;
    symbolsDirections["/instrumentation/attitude-indicator/internal-pitch-deg"] = 6;
    symbolsDirections["/instrumentation/attitude-indicator/internal-roll-deg"] = 7;
    symbolsDirections["/instrumentation/encoder/indicated-altitude-ft"] = 8;
    symbolsDirections["/instrumentation/encoder/pressure-alt-ft"] = 9;
    symbolsDirections["/instrumentation/gps/indicated-altitude-ft"] = 10;
    symbolsDirections["/instrumentation/gps/indicated-ground-speed-kt"] = 11;
    symbolsDirections["/instrumentation/gps/indicated-vertical-speed"] = 12;
    symbolsDirections["/instrumentation/heading-indicator/indicated-heading-deg"] = 13;
    symbolsDirections["/instrumentation/magnetic-compass/indicated-heading-deg"] = 14;
    symbolsDirections["/instrumentation/slip-skid-ball/indicated-slip-skid"] = 15;
    symbolsDirections["/instrumentation/turn-indicator/indicated-turn-rate"] = 16;
    symbolsDirections["/instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = 17;
    symbolsDirections["/controls/flight/aileron"] = 18;
    symbolsDirections["/controls/flight/elevator"] = 19;
    symbolsDirections["/controls/flight/rudder"] = 20;
    symbolsDirections["/controls/flight/flaps"] = 21;
    symbolsDirections["/controls/engines/engine/throttle"] = 22;
    symbolsDirections["/engines/engine/rpm"] = 23;
}
// a function that update the symbols value from the server!
void Variables::UpdateSymbolsValueFromServer(vector<double> vec) {
    for(int i = 0; i< vec.size(); i++) {
        symbolsValues[i] = vec[i];
    }
}

Interpreter *Variables::getI1() const {
    return i1;
}


