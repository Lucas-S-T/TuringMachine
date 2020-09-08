#include <zconf.h>
#include "machine.h"
#include "instructionSet.h"
#include <stdio.h>
int main() {

    struct TuringMachine tm;

    struct InstructionSet is;

    printf("Loading Instruction Set:\n");

    createInstructionSet(&is, 20, 1, 20);

    addInstruction(&is, 1, 1, 0, RIGHT, 2);
    addInstruction(&is, 2, 1, 1, RIGHT, 2);
    addInstruction(&is, 2, 0, 0, RIGHT, 3);
    addInstruction(&is, 3, 0, 1, LEFT, 4);
    addInstruction(&is, 3, 1, 1, RIGHT, 3);
    addInstruction(&is, 4, 1, 1, LEFT, 4);
    addInstruction(&is, 4, 0, 0, LEFT, 5);
    addInstruction(&is, 5, 1, 1, LEFT, 5);
    addInstruction(&is, 5, 0, 1, RIGHT, 1);
    addInstruction(&is, 1, 0, 0, STAY, 20);



    printf("\n");

    create_machine(7, &tm, &is, 0);

    setTapeValue(&tm, 0, 1);
    setTapeValue(&tm, 1, 1);
    setTapeValue(&tm, 2, 1);


    printTape(tm);

    printf("Running...\n");

    sleep(1);

    runUntilError(&tm, 0);

    sleep(1);

    printTape(tm);


    freeInstructionSet(is);
    shutdown(tm);

    printf("Machine Halt. Program Counter: %lu\n\nExiting... Goodbye.", tm.pc);

    return 0;

}
