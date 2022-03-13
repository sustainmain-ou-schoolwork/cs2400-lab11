/**
 *    @file: lab11.cc
 *  @author: Josh Marusek
 *    @date: 2021-11-05
 *   @brief: Converts a text file char-by-char.
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cctype>

using namespace std;


int main()
{
    char chIn;
    char chOut;

    ifstream inFile;
    inFile.open("text.txt");

    ofstream outFile;
    outFile.open("output.txt");

    if (inFile.fail() || outFile.fail()) {
        cout << "Failed to open file." << endl;
        exit(0);
    }

    while(!inFile.eof()) {
        chIn = inFile.get();

        if (islower(chIn)) {
            chOut = toupper(chIn);
        }
        else if (isdigit(chIn)) {
            chOut = '*';
        }
        else {
            chOut = chIn;
        }

        outFile << chOut;
    }

    inFile.close();
    outFile.close();

    return (EXIT_SUCCESS);
}
