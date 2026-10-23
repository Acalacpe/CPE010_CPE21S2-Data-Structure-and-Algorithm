#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include "QueueArr.h"
#include "Job.h"

class Printer {

private:

    //queue that stores the print jobs
    QueueArr<Job> printer_queue;

public:

    //constructor
    Printer(int capacity = 10);

    //add a new print job
    void AddJob(Job job);

    //process all print jobs
    void ProcessJobs();
};

//constructor

Printer::Printer(int capacity)
    : printer_queue(capacity) {
}

//add a new print job

void Printer::AddJob(Job job) {

    std::cout << "Adding Print Job...\n";

    job.Display();

    printer_queue.Enqueue(job);

    std::cout << std::endl;
}

//process all print jobs

void Printer::ProcessJobs() {

    std::cout << "\nProcessing Print Jobs...\n\n";

    while (!printer_queue.Empty()) {

        Job current = printer_queue.Dequeue();

        std::cout << "Printing...\n";

        current.Display();

        std::cout << "Job Completed.\n\n";
    }

    std::cout << "No more pending jobs.\n";
}

#endif