#include <zconf.h>
#include "machine.h"
#include "instructionSet.h"
#include <stdio.h>
int main() {

    struct TuringMachine tm;

    struct InstructionSet is;

    printf("Loading Instruction Set:\n");

    createInstructionSet(&is, 20, 0, 3);

    addInstruction(&is, 0, 2, 2, RIGHT, 1);
    addInstruction(&is, 1, 0, 1, RIGHT, 1);
    addInstruction(&is, 1, 2, 2, LEFT, 2);
    addInstruction(&is, 2, 1, 1, LEFT, 2);
    addInstruction(&is, 2, 2, 2, STAY, 3);


    printf("\n");

    create_machine(20, &tm, &is, 0);

    setTapeValue(&tm, 0, 2);
    setTapeValue(&tm, 13, 2);

    printTape(tm);

    printf("Running...\n");

    sleep(1);

    runUntilError(&tm);

    sleep(1);

    printTape(tm);

    freeInstructionSet(is);
    shutdown(tm);

    printf("Machine Halt. Program Counter: %lu\n\nExiting... Goodbye.", tm.pc);

    return 0;

}
