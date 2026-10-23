#include <iostream>
#include "Printer.h"

int main() {

    //create a printer with a maximum of 5 jobs
    Printer printer(5);

    //add print jobs
    printer.AddJob(Job(101, "Matt", 5));
    printer.AddJob(Job(102, "John", 12));
    printer.AddJob(Job(103, "Gab", 8));
    printer.AddJob(Job(104, "Thomas", 15));
    printer.AddJob(Job(105, "Jappeth", 6));
    //process all print jobs
    printer.ProcessJobs();

    return 0;
}