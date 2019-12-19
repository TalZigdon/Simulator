//
// Created by tal on 12.12.2019.
//

#include "Var.h"
Var::Var(int value1, const string &sim1, bool is_input){
  value = value1;
    simPath = sim1;
  bindedFromRightToLeft = is_input;
}
int Var::GetValue() const {
    return value;
}

const string &Var::GetSim() const {
    return simPath;

}

void Var::setValue(int value) {
    Var::value = value;
}

void Var::setSim(const string &sim) {
    Var::simPath = sim;
}

void Var::setBindedFromRightToLeft(bool bindedFromRightToLeft) {
    Var::bindedFromRightToLeft = bindedFromRightToLeft;
}

bool Var::isBindedFromRightToLeft() const {
    return bindedFromRightToLeft;
}
