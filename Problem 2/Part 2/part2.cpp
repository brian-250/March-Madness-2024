// importing standard C++ input/output stream library, allowing for usage of commands like std::cout or std::cin
#include <iostream>
// importing standard C++ file stream library, allowing for input and output operations to different files
#include <fstream>

#include <stack>
// importing the standard C++ string library, allowing for the creation and maipulation of strings
#include <string>

int findingArea(std::string& line, int period_counter, int fifteen_area_counter, std::stack<int>& a_stack) {
    for (int index = 0; index < line.size(); index++) {
        if (line[index] == '.') {
            period_counter++;
        } else {
            period_counter = 0;
        }   
        if (period_counter == 15) {
            if (a_stack.size() != 15) {
                a_stack.push(15);
                if (a_stack.size() == 15) {
                    fifteen_area_counter++;
                }
                } else {
                    a_stack.pop();
                    a_stack.push(15);
                    fifteen_area_counter++;
                }
            }
        }
        return fifteen_area_counter;
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
    int period_counter = 0;
    int fifteen_area_counter = 0;
    std::stack<int> a_stack;

    // Reading each line of text from inputFile
    while (std::getline(inputFile, line)) {
        fifteen_area_counter = findingArea(line, period_counter, fifteen_area_counter, a_stack);
    }

    // Writing the modified text from fullText to outputFile and concatenating ACM at CSUF's cross-platform promotion links
    outputFile << "We have " << fifteen_area_counter << " places that can fit 15 meters squared" << std::endl;

    // Closing inputFile after reading it
    inputFile.close();
    // Closing outputFile after writing to it
    outputFile.close();

    // Message printed when exceutable file is run
    std::cout << "output.txt has been updated" << std::endl;

    // Returning 0 signifies successful run of the program
    return 0;
}