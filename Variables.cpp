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
    symbolsDirections["/instrumentation/altimeter/indicated-altitude-ft"] = 1;
    symbolsDirections["/instrumentation/altimeter/pressure-alt-ft"] = 2;
    symbolsDirections["/instrumentation/attitude-indicator/indicated-pitch-deg"] = 3;
    symbolsDirections["/instrumentation/attitude-indicator/indicated-roll-deg"] = 4;
    symbolsDirections["/instrumentation/attitude-indicator/internal-pitch-deg"] = 5;
    symbolsDirections["/instrumentation/attitude-indicator/internal-roll-deg"] = 6;
    symbolsDirections["/instrumentation/encoder/indicated-altitude-ft"] = 7;
    symbolsDirections["/instrumentation/encoder/pressure-alt-ft"] = 8;
    symbolsDirections["/instrumentation/gps/indicated-altitude-ft"] = 9;
    symbolsDirections["/instrumentation/gps/indicated-ground-speed-kt"] = 10;
    symbolsDirections["/instrumentation/gps/indicated-vertical-speed"] = 11;
    symbolsDirections["/instrumentation/heading-indicator/indicated-heading-deg"] = 12;
    symbolsDirections["/instrumentation/magnetic-compass/indicated-heading-deg"] = 13;
    symbolsDirections["/instrumentation/slip-skid-ball/indicated-slip-skid"] = 14;
    symbolsDirections["/instrumentation/turn-indicator/indicated-turn-rate"] = 15;
    symbolsDirections["/instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = 16;
    symbolsDirections["/controls/flight/aileron"] = 17;
    symbolsDirections["/controls/flight/elevator"] = 18;
    symbolsDirections["/controls/flight/rudder"] = 19;
    symbolsDirections["/controls/flight/flaps"] = 20;
    symbolsDirections["/controls/engines/engine/throttle"] = 21;
    symbolsDirections["/engines/engine/rpm"] = 22;
}


