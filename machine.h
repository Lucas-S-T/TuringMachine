//
// Created by lucasst on 08/09/2020.
//

#ifndef TURINGMACHINE_MACHINE_H
#define TURINGMACHINE_MACHINE_H

#include "instructionSet.h"

struct TuringMachine{

    unsigned long *tape;
    unsigned long tape_size;
    unsigned long tape_position;

    unsigned long pc;
    unsigned long state;

    struct InstructionSet *is;

};

int create_machine(int tape_size, struct TuringMachine *m, struct InstructionSet *is, unsigned long initial_tape_position);
int shutdown(struct TuringMachine m);
int setTapePosition(struct TuringMachine *m, unsigned long pos);
int moveTape(struct TuringMachine *m, enum TapeMovement movement);
int setMachineState(struct TuringMachine *m, unsigned long state);
int setTapeValue(struct TuringMachine *m, unsigned long pos, unsigned long value);
int printTape(struct TuringMachine m);
int runOnce(struct TuringMachine *m);
int runUntilError(struct TuringMachine *m);

#endif //TURINGMACHINE_MACHINE_H
