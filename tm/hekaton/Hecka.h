#ifndef HECKADBMS_HECKA_H
#define HECKADBMS_HECKA_H

#include "Record.h"
#include "Timestamp.h"
#include "DataManager.h"
#include "Transaction.h"
#include <vector>

using namespace std;

class Hecka
{
public:
    // Default Constructor
    Hecka();

    // Destructor
    ~Hecka();
    
	//sets phase to active and acquire begin timestamp
    void beginTransaction(DataManager *db, vector<Transaction *> *transactions);
	
	//see section 2.5, scan db for correct RT and add pointer to readset, call registerCommitDep if applicable
	void read(DataManager *db, vector<Record *> *reads, vector<Transaction *> *transactions);
	
	//registerCommitDep(T1, T2) - increment T2’s commitDepCounter and update T1’s commitDepSet with T2
	void registerCommitDep(int transaction, vector<Transaction *> *transactions);

	//Write- see section 2.6, add pointers to writeset, may need to call abort (if so set to postprocessing phase)
	void write(DataManager *db);
	
	
	//endNormalProcessing - acquire end timestamp, switch state to preparing, call validate
	void endNormalProcessing(DataManager *db, vector<Transaction *> *transactions);
	
	//reread read objects from db and check if versions are the same as pointers in readset, 
	//if valid wait for CommitDepCounter = 0 or AbortNow = 1 (infinite loop), switch to postprocessing phase, may need to call abort
	void validate(vector<Transaction *> *transactions);
	
	//change respective timestamps in writeset to inifinity, call abortCommitDep
	void abort(vector<Transaction *> *transactions);

	//go through commitDepSet and set respective transactions’ AbortNow flag
	void abortCommitDep(vector<Transaction *> *transactions);
	
	//go through writeset and update begin and end timestamps to end timestamp
	void commit(vector<Transaction *> *transactions);
	
	//go through commitDepSet and decrement respective transactions' commitDepCounter
	void committedCommitDep(vector<Transaction *> *transactions);
 private:
    int _ID;
    Timestamp _begin;
    vector<Record *> _readSet;
    vector<Record *> _writeSet;
};

#endif
