#ifndef HECKADBMS_MANUALTEST_H
#define HECKADBMS_MANUALTEST_H

#include <string>
#include <unordered_map>
#include <random>
#include <iostream>
#include <sstream>
#include <fstream>

#include "Utility.h"

using namespace std;

class ManualTest {
public:
    // Default constructor
    ManualTest();

    // Finite state machine for processing user input
    void FSM(int dbSize);

    // State definition for a manual testflow
    enum ManualState {
        ENTER,
        RO_TRANSACTIONS,
        RW_TRANSACTIONS,
        THREAD_COUNT,
        DATA_SELECT,
        DATA_SPECIFY,
        BEGIN_TRANSACTION,
        END_TRANSACTION,
        EXIT};

private:
    ManualState _state;
};

#endif
