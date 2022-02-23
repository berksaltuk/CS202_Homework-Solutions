using namespace std;
#include "simulator.h"
#include <string>
#include <sstream>
/*
* Title: Main Function
* Author: Berk Saltuk Yilmaz
* ID: 21903419
* Section: 3
* Assignment: 3
* Description: Main function provides reading the file name and avg waiting time as command line arguments
*/
int main(int argc, char **argv) // argument count and argument vector
{
    char *c = argv[1]; // taking the filename
    char *c2 = argv[2]; // taking the average time
    string s1 = c;
    string s2 = c2;

    stringstream avgtime(s2); // string to double
    double d = 0;
    avgtime >> d;

    simulator s(s1, d); // passing them to the simulation
    return 0;
}
