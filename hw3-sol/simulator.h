#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <iostream>
#include "PriorityQueue.h"
#include "Printer.h"
#include <sstream>
#include <fstream>
#include <climits>

/*
* Title: Simulator's Interface
* Author: Berk Saltuk Yilmaz
* ID: 21903419
* Section: 3
* Assignment: 3
* Description: This interface provides function prototypes and data members for simulation.
*/

using namespace std;

class simulator
{
    public:
        simulator(const string filename, const double avgwaitingtime);
        void estimateNumOfPrinters(int &OptimumNumOfPrinters, PQItemType *requestArr, const double avgwaitingtime);
        double calculateAvgWaiting( PQItemType *requestArr, int curNumOfPrinters, bool simulate);
    private:
        PriorityQueue pq;
        int numOfRequests;
        int cur;

};

#endif // SIMULATOR_H
