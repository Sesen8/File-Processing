// Title: Lab 1 - FileProcessing.cpp
//
// Purpose: This program is used to open and close a json file to format it into CSV,
//          as well as computing the maximum, minimum and average ages found in the json file.
//
// Class: CSC 2430 Winter 2022
// Author: Sesen Yonas
// The following code is from my authorship with the exception of the
// code provided by the instructors of this course.


#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>



using namespace std;
using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::ifstream;
using std::fstream;
using std::vector;



#include "Formatting.h"
#include "FileProcessing.h"
#include "CalculationsForAges.h"


// - Reads the JSON File and calls FormatAsCSV() for each of the lines found in the file.
// - From there it outputs each of those lines to a CSV file
//
// Parameters:
//      jsonIn : the input file stream
//      csvOut : the output file stream
//      json   : line in json format
// Returns:
//      nothing
void FormattingTheFiles(ifstream& jsonIn, ofstream& csvOut, string& json) {
    csvOut << CSVHeader() << endl;

    do {
        getline(jsonIn, json);
        if (json.empty()) {
            break;
        }
        else {
        csvOut << FormatAsCSV(json) << endl;
        }

    } while (!json.empty());

}

// Operates in a loop so multiple files can be processed.
// On each iteration, reads name of input and output files from user and opens them
// Then calls ProcessFile to do the actual file processing
// - If user enters a blank line for the input file, loop ends
// - If either file cannot be opened, loop restarts
//
// Parameters:
//      none
// Returns:
//      nothing
void ProcessFiles() {

    RestartAges();
    string inFilename;
    string outFilename;
    string json;

    do {
        if (inFilename == " "){
            break;
        }

        cout << "Input File Name: ";
        cin >> inFilename;
        ifstream jsonIn(inFilename);

        string jsonFormat = ".json";
        if (inFilename.find(jsonFormat) == string::npos){
            cout << "ERROR: Incorrect file format, please provide a JSON file" << endl;
            continue;
        }
        jsonIn.open("../" + inFilename);
        if (!jsonIn.is_open()){
            cout  << "ERROR: " << inFilename << " not found" << endl;
            continue;
        }

        cout << "Output File Name: ";
        cin >> outFilename;
        ofstream csvOut(outFilename);

        string csvFormat = ".csv";
        if (outFilename.find(csvFormat) == string::npos){
            cout << "ERROR: Incorrect file format, please provide a CSV file" << endl;
            jsonIn.close();
            continue;
        }

        csvOut.open("../" + outFilename);
        if (!csvOut.is_open()){
            cout  << "ERROR: " << inFilename << " not found" << endl;
            jsonIn.close();
            continue;
        }

        FormattingTheFiles(jsonIn,csvOut,json);
        AgesCalculations();
        jsonIn.close();
        csvOut.close();

    } while (inFilename != " ");

}

