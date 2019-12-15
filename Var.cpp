//
// Created by tal on 12.12.2019.
//

#include "Var.h"
Var::Var(int value, const string &sim, bool is_input) : value(value), sim(sim), isInput(is_input) {}
int Var::GetValue() const {
  return value;
}
bool Var::IsInput() const {
  return isInput;
}
const string &Var::GetSim() const {
  return sim;

}
