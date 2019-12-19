//
// Created by tal on 12.12.2019.
//

#include "Var.h"
Var::Var(int value1, const string &sim1, bool is_input) {
    value = value1;
    simPath = sim1;
    isInput = is_input;
}
int Var::GetValue() const {
    return value;
}
bool Var::IsInput() const {
    return isInput;
}
const string &Var::GetSim() const {
    return simPath;

}
