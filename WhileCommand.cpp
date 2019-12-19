//
// Created by tal on 12.12.2019.
//

#include "WhileCommand.h"
int WhileCommand::execute(vector<string> vector, int index) {
    int counter = index;
    bool signThatItsTheFirstLoop = true;
    int saveTheNumberOfTheLastIndexInWhile = 0;

    while (flag) {
        for (Command c : lst) {
            counter = c.execute(vector, counter);
        }
        if (signThatItsTheFirstLoop) {
            signThatItsTheFirstLoop = false;
            saveTheNumberOfTheLastIndexInWhile = counter;
        }
        //initialize for the next for loop
        counter = index;
    }
    return saveTheNumberOfTheLastIndexInWhile;
}
