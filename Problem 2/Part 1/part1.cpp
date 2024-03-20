// importing standard C++ input/output stream library, allowing for usage of commands like std::cout or std::cin
#include <iostream>
// importing standard C++ file stream library, allowing for input and output operations to different files
#include <fstream>
// importing the standard C++ string library, allowing for the creation and maipulation of strings
#include <string>

int countOpenSpace(std::string& line, int counter) {
    for (int index = 0; index < line.size(); index++) {
        if (line[index] == '.') {
            counter++;
        }
    }
    return counter;
}

int main() {
    // Creating an ifstream object called inputFile and opening file1.txt for reading file1.txt
    std::ifstream inputFile("input.txt");

    // Creating an ofstream object called outputFile and opening file2.txt for writing to file2.txt
    std::ofstream outputFile("output.txt");

    // Checking if inputFile was opened successfully
    if (!inputFile.is_open()) {
        // Priting out error message if inputFile could not be opened
        std::cerr << "Error opening input file." << std::endl;
        // Returning 1 to main to signify unsuccessful run of the program
        return 1;
    }

    // Checking if outputFile was opened successfully
    if (!outputFile.is_open()) {
        // Printing out error message if outputFile could not be opened
        std::cerr << "Error opening output file." << std::endl;
        // Returning 1 to signify unsuccessful run of the program
        return 1;
    }

    // Declaring a string variable to hold each line of text from inputFile
    std::string line;
    // Create counter to count the amount of services we need to boot up
    int counter = 0;

    // Reading each line of text from inputFile
    while (std::getline(inputFile, line)) {
        counter = countOpenSpace(line, counter);
    }

    // Writing the modified text from fullText to outputFile and concatenating ACM at CSUF's cross-platform promotion links
    outputFile << "We have " << counter << " m2 of open space!" << std::endl;

    // Closing inputFile after reading it
    inputFile.close();
    // Closing outputFile after writing to it
    outputFile.close();

    // Message printed when exceutable file is run
    std::cout << "output.txt has been updated" << std::endl;

    // Returning 0 signifies successful run of the program
    return 0;
}