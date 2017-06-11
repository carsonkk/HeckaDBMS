#include <iostream>

#include "DataManager.h"
#include "TransactionManager.h"
#include "Utility.h"
#include "Client.h"

using namespace std;

int main(int argc, char *argv[])
{
    string protocolType;
    Client client = Client();

    DataManager *dataManager = new DataManager();
    TransactionManager *transactionManager = new TransactionManager();

    cout << "==================================================" << endl;
    cout << "||             WELCOME TO HeckaDBMS             ||" << endl;
    cout << "==================================================\n" << endl;

    // Launch client
    if (strncmp(argv[2],"twopl", 5) == 0) {
    	client.FSM(dataManager, transactionManager, false);
    }
    else if (strncmp(argv[2],"hekaton", 7) == 0) {
    	client.FSM(dataManager, transactionManager, true);
    }

    cout << "==================================================" << endl;
    cout << "||               EXITING HeckaDBMS              ||" << endl;
    cout << "==================================================\n" << endl;

    exit(0);
}
