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
  // locking map
  mapLock.lock();

  simMap["airspeed-indicator_indicated-speed-kt"] =
      new Var(0, "/instrumentation/airspeed-indicator/indicated-speed-kt", false);

  simMap["time_warp"] =
      new Var(0, "/sim/time/warp", false);

  simMap["switches_magnetos"] =
      new Var(0, "/controls/switches/magnetos", false);

  simMap["heading-indicator_offset-deg"] =
      new Var(0, "/instrumentation/heading-indicator/offset-deg", false);

  simMap["altimeter_indicated-altitude-ft"] =
      new Var(0, "/instrumentation/altimeter/indicated-altitude-ft", false);

  simMap["altimeter_pressure-alt-ft"] =
      new Var(0, "/instrumentation/altimeter/pressure-alt-ft", false);

  simMap["attitude-indicator_indicated-pitch-deg"] =
      new Var(0, "/instrumentation/attitude-indicator/indicated-pitch-deg", false);

  simMap["attitude-indicator_indicated-roll-deg"] =
      new Var(0, "/instrumentation/attitude-indicator/indicated-roll-deg", false);

  simMap["attitude-indicator_internal-pitch-deg"] =
      new Var(0, "/instrumentation/attitude-indicator/internal-pitch-deg", false);

  simMap["attitude-indicator_internal-roll-deg"] =
      new Var(0, "/instrumentation/attitude-indicator/internal-roll-deg", false);

  simMap["encoder_indicated-altitude-ft"] =
      new Var(0, "/instrumentation/encoder/indicated-altitude-ft", false);

  simMap["encoder_pressure-alt-ft"] =
      new Var(0, "/instrumentation/encoder/pressure-alt-ft", false);

  simMap["gps_indicated-altitude-ft"] =
      new Var(0, "/instrumentation/gps/indicated-altitude-ft", false);

  simMap["gps_indicated-ground-speed-kt"] =
      new Var(0, "/instrumentation/gps/indicated-ground-speed-kt", false);

  simMap["gps_indicated-vertical-speed"] =
      new Var(0, "/instrumentation/gps/indicated-vertical-speed", false);

  simMap["indicated-heading-deg"] =
      new Var(0, "/instrumentation/heading-indicator/indicated-heading-deg", false);

  simMap["magnetic-compass_indicated-heading-deg"] =
      new Var(0, "/instrumentation/magnetic-compass/indicated-heading-deg", false);

  simMap["slip-skid-ball_indicated-slip-skid"] =
      new Var(0, "/instrumentation/slip-skid-ball/indicated-slip-skid", false);

  simMap["turn-indicator_indicated-turn-rate"] =
      new Var(0, "/instrumentation/turn-indicator/indicated-turn-rate", false);

  simMap["vertical-speed-indicator_indicated-speed-fpm"] =
      new Var(0, "/instrumentation/vertical-speed-indicator/indicated-speed-fpm", false);

  simMap["flight_aileron"] =
      new Var(0, "/controls/flight/aileron", false);

  simMap["flight_elevator"] =
      new Var(0, "/controls/flight/elevator", false);

  simMap["flight_rudder"] =
      new Var(0, "/controls/flight/rudder", false);

  simMap["flight_flaps"] =
      new Var(0, "/controls/flight/flaps", false);

  simMap["engine_throttle"] =
      new Var(0, "/controls/engines/engine/throttle", false);

  simMap["current-engine_throttle"] =
      new Var(0, "/controls/engines/current-engine/throttle", false);

  simMap["switches_master-avionics"] =
      new Var(0, "/controls/switches/master-avionics", false);

  simMap["switches_starter"] =
      new Var(0, "/controls/switches/starter", false);

  simMap["active-engine_auto-start"] =
      new Var(0, "/engines/active-engine/auto-start", false);

  simMap["flight_speedbrake"] =
      new Var(0, "/controls/flight/speedbrake", false);

  simMap["c172p_brake-parking"] =
      new Var(0, "/sim/model/c172p/brake-parking", false);

  simMap["engine_primer"] =
      new Var(0, "/controls/engines/engine/primer", false);

  simMap["current-engine_mixture"] =
      new Var(0, "/controls/engines/current-engine/mixture", false);

  simMap["switches_master-bat"] =
      new Var(0, "/controls/switches/master-bat", false);

  simMap["switches_master-alt"] =
      new Var(0, ">/controls/switches/master-alt", false);

  simMap["engine_rpm"] =
      new Var(0, "/engines/engine/rpm", false);

  // unlocking map
  mapLock.unlock();
}
// a function that update the symbols value from the server!
void Variables::UpdateSymbolsValueFromServer(vector<double> vec) {
  // lock map
  mapLock.lock();

  simMap["airspeed-indicator_indicated-speed-kt"]->setValue(vec[0]);

  simMap["time_warp"]->setValue((vec[1]));

  simMap["switches_magnetos"]->setValue(vec[2]);

  simMap["heading-indicator_offset-deg"]->setValue(vec[3]);

  simMap["altimeter_indicated-altitude-ft"]->setValue(vec[4]);

  simMap["altimeter_pressure-alt-ft"]->setValue(vec[5]);

  simMap["attitude-indicator_indicated-pitch-deg"]->setValue(vec[6]);

  simMap["attitude-indicator_indicated-roll-deg"]->setValue(vec[7]);

  simMap["attitude-indicator_internal-pitch-deg"]->setValue(vec[8]);

  simMap["attitude-indicator_internal-roll-deg"]->setValue(vec[9]);

  simMap["encoder_indicated-altitude-ft"]->setValue(vec[10]);

  simMap["encoder_pressure-alt-ft"]->setValue(vec[11]);

  simMap["gps_indicated-altitude-ft"]->setValue(vec[12]);

  simMap["gps_indicated-ground-speed-kt"]->setValue(vec[13]);

  simMap["gps_indicated-vertical-speed"]->setValue(vec[14]);

  simMap["indicated-heading-deg"]->setValue(vec[15]);

  simMap["magnetic-compass_indicated-heading-deg"]->setValue(vec[16]);

  simMap["slip-skid-ball_indicated-slip-skid"]->setValue(vec[17]);

  simMap["turn-indicator_indicated-turn-rate"]->setValue(vec[18]);

  simMap["vertical-speed-indicator_indicated-speed-fpm"]->setValue(vec[19]);

  simMap["flight_aileron"]->setValue(vec[20]);

  simMap["flight_elevator"]->setValue(vec[21]);

  simMap["flight_rudder"]->setValue(vec[22]);

  simMap["flight_flaps"]->setValue(vec[23]);

  simMap["engine_throttle"]->setValue(vec[24]);

  simMap["current-engine_throttle"]->setValue(vec[25]);

  simMap["switches_master-avionics"]->setValue(vec[26]);

  simMap["switches_starter"]->setValue(vec[27]);

  simMap["active-engine_auto-start"]->setValue(vec[28]);

  simMap["flight_speedbrake"]->setValue(vec[29]);

  simMap["c172p_brake-parking"]->setValue(vec[30]);

  simMap["engine_primer"]->setValue(vec[31]);

  simMap["current-engine_mixture"]->setValue(vec[32]);

  simMap["switches_master-bat"]->setValue(vec[33]);

  simMap["switches_master-alt"]->setValue(vec[34]);

  simMap["engine_rpm"]->setValue(vec[35]);

  // unlock map
  mapLock.unlock();

  //  for (int i = 0; i < vec.size(); i++) {
//    symbolsValues[i] = vec[i];
//  }
}
bool Variables::UpdateValueOfProgramVar(string str, double newVal) {
  if(programMap.count(str)){
    programMap[str]->setValue(newVal);
    return true;
  }
  return false;
}
