#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SortingAlgo.h"

// case function to get candidate name
std::string name(int choice) {
    switch(choice) {
        case 1: return "Bo Dalton Capistrano";
        case 2: return "Cornelius Raymon Agustin";
        case 3: return "Deja Jayla Banaga";
        case 4: return "Lalla Brielle Yabut";
        case 5: return "Franklin Relano Castro";
        default: return "Unknown";
    }
}

int main() {
    const int MAX_SIZE = 100;
    int votes[MAX_SIZE];
    srand(time(0)); 

    for (int i = 0; i < MAX_SIZE; i++) {
        votes[i] = (std::rand() % 5) + 1; // Random votes between 1 and 5
    }

    insertionSort(votes, MAX_SIZE);

    int currentName = votes[0];
    int currentCount = 1;
    
    int winningName = currentName;
    int maxVotes = 1;

    for (int i = 1; i < MAX_SIZE; i++) {
        if (votes[i] == currentName) {
            currentCount++;
        } else {
            // check if previous candidate has the most votes so far
            if (currentCount > maxVotes) {
                maxVotes = currentCount;
                winningName = currentName;
            }
            // reset for the new candidate
            currentName = votes[i];
            currentCount = 1;
        }
    }
    
    // final check for the last candidate in the array
    if (currentCount > maxVotes) {
        maxVotes = currentCount;
        winningName = currentName;
    }

    std::cout << "--- ELECTION RESULTS ---" << std::endl;
    std::cout << "Total votes cast: " << MAX_SIZE << std::endl;
    std::cout << "Winning Candidate: " << winningName << std::endl;
    std::cout << "Winning Candidate Name: " << name(winningName) << std::endl;
    std::cout << "Total Votes Received: " << maxVotes << std::endl;

    return 0;
}