//
// Created by lucasst on 08/09/2020.
//

#ifndef TURINGMACHINE_INSTRUCTIONSET_H
#define TURINGMACHINE_INSTRUCTIONSET_H


enum TapeMovement{

    LEFT,
    RIGHT,
    STAY

};

struct TuringInstruction{

    unsigned long currentState;
    unsigned long scanSymbol;
    unsigned long printSymbol;
    enum TapeMovement movement;
    unsigned long nextState;

};

struct InstructionSet{

    unsigned long initialState;
    unsigned long finalState;

    struct TuringInstruction *instructions;

    unsigned long size;
    unsigned long used;


};

int createInstructionSet(struct InstructionSet *is, unsigned long size, unsigned long initialState, unsigned long finalState);
int freeInstructionSet(struct InstructionSet is);
int addInstruction(struct InstructionSet *is, unsigned long state, unsigned long symbol, unsigned long print, enum TapeMovement movement, unsigned long new_state);

#endif //TURINGMACHINE_INSTRUCTIONSET_H
