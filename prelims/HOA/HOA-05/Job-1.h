#ifndef JOB_H
#define JOB_H

#include <iostream>
#include <string>

class Job {
private:

    //job identification number
    int job_id;

    //name of the user who submitted the job
    std::string user_name;

    //number of pages to print
    int pages;

public:

    //constructor
    Job();

    //parameterized constructor
    Job(int id, std::string name, int page_count);

    //return the job id
    int GetID();

    //return the user name
    std::string GetUser();

    //return the number of pages
    int GetPages();

    //display the job information
    void Display();
};

//constructor

Job::Job() {
    job_id = 0;
    user_name = "";
    pages = 0;
}

//parameterized constructor

Job::Job(int id, std::string name, int page_count) {
    job_id = id;
    user_name = name;
    pages = page_count;
}

//return the job id

int Job::GetID() {
    return job_id;
}

//return the user name

std::string Job::GetUser() {
    return user_name;
}

//return the number of pages

int Job::GetPages() {
    return pages;
}

//display the job information

void Job::Display() {
    std::cout << "Job ID: " << job_id << std::endl;
    std::cout << "User: " << user_name << std::endl;
    std::cout << "Pages: " << pages << std::endl;
}

#endif