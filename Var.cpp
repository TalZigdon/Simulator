//
// Created by tal on 12.12.2019.
//

#include "Var.h"
#include "Variables.h"
Var::Var(int value1, const string &sim1, bool is_input) {
    value = value1;
    simPath = sim1;
    bindedFromRightToLeft = is_input;
    Variables::getInstance();
}
int Var::GetValue() const {
    return value;
}

const string &Var::GetSim() const {
    return simPath;

}

void Var::setValue(double value) {
    Var::value = value;
}
//
void Var::setSim(const string &sim) {
    Var::simPath = sim;
}

void Var::setBindedFromRightToLeft(bool bindedFromRightToLeft) {
    Var::bindedFromRightToLeft = bindedFromRightToLeft;
}

bool Var::isBindedFromRightToLeft() const {
    return bindedFromRightToLeft;
}
