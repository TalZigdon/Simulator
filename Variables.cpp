//
// Created by tal on 12.12.2019.
//

#include "Variables.h"
double Variables::doShuntingYard(string str) {
 i1.shuntingYard(str);
 return i1.createExp()->calculate();
}

void Variables::addVarToMap(string str) {
  i1.generateVarAndVal(str);
}


