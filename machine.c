//
// Created by lucasst on 08/09/2020.
//

#include "machine.h"
#include <stdlib.h>
#include <stdio.h>
#include "instructionSet.h"


int create_machine(int tape_size, struct TuringMachine *m, struct InstructionSet *is, unsigned long initial_tape_position) {

    m->tape = (unsigned long *) malloc(sizeof(long)*tape_size);

    for(int x = 0; x< tape_size; x++){
        m->tape[x] = 0;
    }

    m->is = is;
    m->state = is->initialState;
    m->pc = 0;
    m->tape_size = tape_size;

    setTapePosition(m, initial_tape_position);

    printf("Turing Machine created.\n\nTape size: %d\nInitial Tape position: %lu\nInitial State: %lu\nFinal State: %lu\n\n", tape_size, initial_tape_position, is->initialState, is->finalState);

    return 0;
}


int runUntilError(struct TuringMachine *m, int print_tape){

    int s = 0;

   do{
       s = runOnce(m);
       if(print_tape){
           printTape(*m);
       }
   }while (s == 0);

   return s;

}

int runOnce(struct TuringMachine *m){

    for(int x = 0; x< m->is->used; x++){

        struct TuringInstruction i = m->is->instructions[x];

        if(i.currentState == m->state && i.scanSymbol == m->tape[m->tape_position]){

            setTapeValue(m, m->tape_position, i.printSymbol);
            moveTape(m, i.movement);
            setMachineState(m, i.nextState);
            m->pc++;
            return 0;
        }

    }

    if(m->state == m->is->finalState){
        perror("Final State reached");
        return 1;
    }

    perror("No Instruction for this situation");
    return 2;
}

int printTape(const struct TuringMachine m){


    printf("Tape: \n");

    for(int x = 0; x<m.tape_size; x++){

        printf("%lu\t", m.tape[x]);

    }

    printf("\n");

    for(int x = 0; x<m.tape_position; x++){
        printf("\t");
    }

    printf("^\n");

    return 0;
}

int setTapeValue(struct TuringMachine *m, unsigned long pos, unsigned long value){

    if(pos < m->tape_size){
        m->tape[pos] = value;
        return 0;
    }

    perror("Invalid Tape position");
    return 1;
}

int setMachineState(struct TuringMachine *m, unsigned long state){

    m->state = state;

    return 0;
}

int moveTape(struct TuringMachine *m, enum TapeMovement movement) {

    switch (movement) {

        case STAY:
            return 0;
        case LEFT:
            return setTapePosition(m, m->tape_position-1);
        case RIGHT:
            return setTapePosition(m, m->tape_position+1);

        default: perror("Invalid Tape movement");

    }

}

int setTapePosition(struct TuringMachine *m, unsigned long pos){

    if(pos < m->tape_size){
        m->tape_position = pos;
        return 0;
    }

    perror("Invalid Tape position!");

    return 1;
}


int shutdown(const struct TuringMachine m){

    free(m.tape);



    return 0;
}