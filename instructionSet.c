//
// Created by lucasst on 08/09/2020.
//

#include <stdio.h>
#include "instructionSet.h"
#include "stdlib.h"

int createInstructionSet(struct InstructionSet *is, unsigned long size, unsigned long initialState, unsigned long finalState){

    is->finalState = finalState;
    is->initialState = initialState;
    is->instructions = (struct TuringInstruction *) malloc(sizeof(struct TuringInstruction)* size);
    is->size = size;
    is->used = 0;

    return 0;
}

int addInstruction(struct InstructionSet *is, unsigned long state, unsigned long symbol, unsigned long print, enum TapeMovement movement, unsigned long new_state){

    if(is->used < is->size){

        for(int x = 0; x<is->used; x++){
            if(state == is->instructions[x].currentState && symbol == is->instructions[x].scanSymbol){
                perror("Duplicated Instruction");
                return 1;
            }
        }

        struct TuringInstruction ts;

        ts.currentState = state;
        ts.scanSymbol = symbol;
        ts.printSymbol = print;
        ts.movement = movement;
        ts.nextState = new_state;

        is->instructions[is->used] = ts;

        is->used++;
        printf("Instruction Loaded: State: %lu, Scan: %lu, Print: %lu, Movement: %u, New State: %lu.\n", state, symbol, print, movement, new_state);
        return 0;
    }

    perror("Instruction overflow");
    return 1;
}


int freeInstructionSet(const struct  InstructionSet is){

    free(is.instructions);

    return 0;
}