#include "simulator.h"

simulator::simulator(const string logfile, const double avgwaitingtime)
{
    string fileName = logfile; // Taking the filename
    string name;
    ifstream inputFile;

    //Open the stream for the input file
    inputFile.open( fileName.c_str(), ios_base::in );


    KeyType id, priority, createdAgo, time;


    //Taking the first line as number of requests.
    inputFile >> numOfRequests;

    // I keep the requests in a "Print Request Object" based array, before inserting them to priority queue.
    PQItemType *requests = new PQItemType[numOfRequests];

    int index = 0;

    while (  inputFile >> id >> priority >> createdAgo >> time) {
        // Reading from the file and saving to array
        PQItemType item(id, priority, createdAgo, time);
        requests[index++] = item;

    }


    int printerNo;
    estimateNumOfPrinters( printerNo, requests, avgwaitingtime); // Estimation and calculation done in constructor.
    // It is enough for one to just create an instance of this class to calculate what he wants. (OH WAIT THIS WORKS BY A COMMAND LINE ARGUMENT :)) )

    cout << "Minimum number of printers required: " << printerNo << endl;
    cout <<endl;
    cout << "Simulation with 4 printers:" << endl;
    cout <<endl;

    double avg = calculateAvgWaiting(requests, printerNo, true);
    cout << endl;
    cout << "Average waiting time: " << avg << " minutes." << endl;
    delete[] requests; // I definitely hate memory leaks...
}

void simulator::estimateNumOfPrinters(int &OptimumNumOfPrinters, PQItemType *requestArr, const double avgwaitingtime)
{
    double curAvg = 0;
    // Starting from the one printer I calculate the average waiting times
    for( int i = 1; i < numOfRequests; i++)
    {
        curAvg = calculateAvgWaiting( requestArr, i, false);
        // When I find an optimum waiting time I exit the loop and saving the optimum number of printers since I have passed it by reference.
        if( curAvg <= avgwaitingtime)
        {
            OptimumNumOfPrinters = i;
            return;
        }
    }


}

double simulator::calculateAvgWaiting( PQItemType *requestArr, int curNumOfPrinters, bool simulate)
{
    Printer *printers = new Printer[curNumOfPrinters]; // Printer array to keep all printers

    int requestsDone = 0;
    int totalTimePassed = 0;
    int waitTimeForOne;
    double totalWaitTime = 0;

    for(int i = 0; i < curNumOfPrinters; i++)
    {
        Printer p(i, true, 0); // Setting all printers as I needed.

        printers[i] = p;
    }


    while( requestsDone != numOfRequests) // If all requests are not done I will keep going.
    {
        for(int i = 0; i < numOfRequests; i++ )
        {   // If a print request is arrived just now, I will insert it to the priority queue.
            if(totalTimePassed == requestArr[i].getWhenRequested())
            {
                pq.pqInsert(requestArr[i]);
            }
        }
        for( int j = 0; j < curNumOfPrinters; j++)
        {   // Checking if a printer gets empty.
            if( printers[j].getAvailableAtTime() == totalTimePassed)
            {
                printers[j].setAvailable(true);
            }

            if(!pq.pqEmpty()) // If there are requests waits for to be processed...
            {
                PQItemType temp;
                pq.pqDelete(temp); // I am deleting the root...
                                   //                          ...
                if(printers[j].getIsAvailable() // I am checking if this printer is empty (by the for loop if more than one printer is empty I process with the one with lower id)
                   &&  temp.getWhenRequested() <= totalTimePassed) // ...and checking if I can process it.
                {
                    printers[j].setAvailableAtWhichTime(totalTimePassed + temp.getTimetoProcess());
                    printers[j].setAvailable(false); // If I can process it, I am passing it to an available printer and make this printer unavailable.

                    requestsDone++; // I am saying that I am done with processing this
                    waitTimeForOne = totalTimePassed - temp.getWhenRequested(); // For example if one request has been arrived at minute 14 and total time passed is 21, Waiting time for this request is 21-14 = 7 minutes.

                    if(simulate) // If I call this with knowing the optimum printer number I start the simulation
                    {
                        cout << "Printer " << printers[j].getID() << " prints prints request " << temp.getID() << " at minute " << totalTimePassed << " (wait: " << waitTimeForOne << " mins)" <<endl;
                    }
                    totalWaitTime += (double)waitTimeForOne; // I am adding the waiting number for single request to the total waiting time.
                }
                else
                {
                    pq.pqInsert(temp); // If I am not able to process this request now (due to availability of the printer of time) I am adding the request back to the queue.
                }
            }
        }

        totalTimePassed++; // I am increasing the total time, in a way simulating the time...
    }

    delete [] printers; // as I said, I hate memory leaks :)
    return (totalWaitTime/numOfRequests); // Finding the average waiting time.
}
