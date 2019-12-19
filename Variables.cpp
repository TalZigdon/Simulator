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
    symbolsDirections["airspeed-indicator_indicated-speed-kt"] =
            new Var(0, "/instrumentation/airspeed-indicator/indicated-speed-kt", false);

    symbolsDirections["time_warp"] =
            new Var(0, "/sim/time/warp", false);

    symbolsDirections["switches_magnetos"] =
            new Var(0, "/controls/switches/magnetos", false);

    symbolsDirections["heading-indicator_offset-deg"] =
            new Var(0, "/instrumentation/heading-indicator/offset-deg", false);

    symbolsDirections["altimeter_indicated-altitude-ft"] =
            new Var(0, "/instrumentation/altimeter/indicated-altitude-ft", false);

    symbolsDirections["altimeter_pressure-alt-ft"] =
            new Var(0, "/instrumentation/altimeter/pressure-alt-ft", false);

    symbolsDirections["attitude-indicator_indicated-pitch-deg"] =
            new Var(0, "/instrumentation/attitude-indicator/indicated-pitch-deg", false);

    symbolsDirections["attitude-indicator_indicated-roll-deg"] =
            new Var(0, "/instrumentation/attitude-indicator/indicated-roll-deg", false);

    symbolsDirections["attitude-indicator_internal-pitch-deg"] =
            new Var(0, "/instrumentation/attitude-indicator/internal-pitch-deg", false);

    symbolsDirections["attitude-indicator_internal-roll-deg"] =
            new Var(0, "/instrumentation/attitude-indicator/internal-roll-deg", false);

    symbolsDirections["encoder_indicated-altitude-ft"] =
            new Var(0, "/instrumentation/encoder/indicated-altitude-ft", false);

    symbolsDirections["encoder_pressure-alt-ft"] =
            new Var(0, "/instrumentation/encoder/pressure-alt-ft", false);

    symbolsDirections["gps_indicated-altitude-ft"] =
            new Var(0, "/instrumentation/gps/indicated-altitude-ft", false);

    symbolsDirections["gps_indicated-ground-speed-kt"] =
            new Var(0, "/instrumentation/gps/indicated-ground-speed-kt", false);

    symbolsDirections["gps_indicated-vertical-speed"] =
            new Var(0, "/instrumentation/gps/indicated-vertical-speed", false);

    symbolsDirections["indicated-heading-deg"] =
            new Var(0, "/instrumentation/heading-indicator/indicated-heading-deg", false);

    symbolsDirections["magnetic-compass_indicated-heading-deg"] =
            new Var(0, "/instrumentation/magnetic-compass/indicated-heading-deg", false);

    symbolsDirections["slip-skid-ball_indicated-slip-skid"] =
            new Var(0, "/instrumentation/slip-skid-ball/indicated-slip-skid", false);

    symbolsDirections["turn-indicator_indicated-turn-rate"] =
            new Var(0, "/instrumentation/turn-indicator/indicated-turn-rate", false);

    symbolsDirections["vertical-speed-indicator_indicated-speed-fpm"] =
            new Var(0, "/instrumentation/vertical-speed-indicator/indicated-speed-fpm", false);

    symbolsDirections["flight_aileron"] =
            new Var(0, "/controls/flight/aileron", false);

    symbolsDirections["flight_elevator"] =
            new Var(0, "/controls/flight/elevator", false);

    symbolsDirections["flight_rudder"] =
            new Var(0, "/controls/flight/rudder", false);

    symbolsDirections["flight_flaps"] =
            new Var(0, "/controls/flight/flaps", false);

    symbolsDirections["engine_throttle"] =
            new Var(0, "/controls/engines/engine/throttle", false);

    symbolsDirections["current-engine_throttle"] =
            new Var(0, "/controls/engines/current-engine/throttle", false);

    symbolsDirections["switches_master-avionics"] =
            new Var(0, "/controls/switches/master-avionics", false);

    symbolsDirections["switches_starter"] =
            new Var(0, "/controls/switches/starter", false);

    symbolsDirections["active-engine_auto-start"] =
            new Var(0, "/engines/active-engine/auto-start", false);

    symbolsDirections["flight_speedbrake"] =
            new Var(0, "/controls/flight/speedbrake", false);

    symbolsDirections["c172p_brake-parking"] =
            new Var(0, "/sim/model/c172p/brake-parking", false);

    symbolsDirections["engine_primer"] =
            new Var(0, "/controls/engines/engine/primer", false);

    symbolsDirections["current-engine_mixture"] =
            new Var(0, "/controls/engines/current-engine/mixture", false);

    symbolsDirections["switches_master-bat"] =
            new Var(0, "/controls/switches/master-bat", false);

    symbolsDirections["switches_master-alt"] =
            new Var(0, ">/controls/switches/master-alt", false);

    symbolsDirections["engine_rpm"] =
            new Var(0, "/engines/engine/rpm", false);
}
// a function that update the symbols value from the server!
void Variables::UpdateSymbolsValueFromServer(vector<double> vec) {
    symbolsDirections["airspeed-indicator_indicated-speed-kt"]->setValue(vec[0]);

    symbolsDirections["time_warp"]->setValue((vec[1]));

    symbolsDirections["switches_magnetos"]->setValue(vec[2]);

    symbolsDirections["heading-indicator_offset-deg"]->setValue(vec[3]);

    symbolsDirections["altimeter_indicated-altitude-ft"]->setValue(vec[4]);

    symbolsDirections["altimeter_pressure-alt-ft"]->setValue(vec[5]);

    symbolsDirections["attitude-indicator_indicated-pitch-deg"]->setValue(vec[6]);

    symbolsDirections["attitude-indicator_indicated-roll-deg"]->setValue(vec[7]);

    symbolsDirections["attitude-indicator_internal-pitch-deg"]->setValue(vec[8]);

    symbolsDirections["attitude-indicator_internal-roll-deg"]->setValue(vec[9]);

    symbolsDirections["encoder_indicated-altitude-ft"]->setValue(vec[10]);

    symbolsDirections["encoder_pressure-alt-ft"]->setValue(vec[11]);

    symbolsDirections["gps_indicated-altitude-ft"]->setValue(vec[12]);

    symbolsDirections["gps_indicated-ground-speed-kt"]->setValue(vec[13]);

    symbolsDirections["gps_indicated-vertical-speed"]->setValue(vec[14]);

    symbolsDirections["indicated-heading-deg"]->setValue(vec[15]);

    symbolsDirections["magnetic-compass_indicated-heading-deg"]->setValue(vec[16]);

    symbolsDirections["slip-skid-ball_indicated-slip-skid"]->setValue(vec[17]);

    symbolsDirections["turn-indicator_indicated-turn-rate"]->setValue(vec[18]);

    symbolsDirections["vertical-speed-indicator_indicated-speed-fpm"]->setValue(vec[19]);

    symbolsDirections["flight_aileron"]->setValue(vec[20]);

    symbolsDirections["flight_elevator"]->setValue(vec[21]);

    symbolsDirections["flight_rudder"]->setValue(vec[22]);

    symbolsDirections["flight_flaps"]->setValue(vec[23]);

    symbolsDirections["engine_throttle"]->setValue(vec[24]);

    symbolsDirections["current-engine_throttle"]->setValue(vec[25]);

    symbolsDirections["switches_master-avionics"]->setValue(vec[26]);

    symbolsDirections["switches_starter"]->setValue(vec[27]);

    symbolsDirections["active-engine_auto-start"]->setValue(vec[28]);

    symbolsDirections["flight_speedbrake"]->setValue(vec[29]);

    symbolsDirections["c172p_brake-parking"]->setValue(vec[30]);

    symbolsDirections["engine_primer"]->setValue(vec[31]);

    symbolsDirections["current-engine_mixture"]->setValue(vec[32]);

    symbolsDirections["switches_master-bat"]->setValue(vec[33]);

    symbolsDirections["switches_master-alt"]->setValue(vec[34]);

    symbolsDirections["engine_rpm"]->setValue(vec[35]);
    for (int i = 0; i < vec.size(); i++) {
        symbolsValues[i] = vec[i];
    }
}