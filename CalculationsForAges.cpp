//
// Created by Sesen Yonas on 1/23/22.
//

#include "CalculationsForAges.h"


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

vector <int> agesList;

// - Converts the age found in one json line into an integer.
// - Then that age is added to the ageList[] vector
//
// Parameters:
//      ageCSV : the age found in one string from json file collected from the function GetAge();
// Returns:
//      nothing
void AgeStringToInt(string& ageCSV) {
    stringstream agesAsNums(ageCSV);
    int x;
    agesAsNums >> x;
    agesList.push_back(x);

}

// - Restarts the vector ageList[] for a new file.
//
// Parameters:
//      nothing
// Returns:
//      nothing
void RestartAges(){
    agesList.clear();
}


// - Calculates the Maximum, minimum and average of the list of ages created in AgeStringToInt()
// - Prints out the max, min and average.
//
// Parameters:
//      nothing
// Returns:
//      nothing
void AgesCalculations(){
    int max = agesList[0];
    int min = agesList[0];
    double averageAge = 0;

    for (int i = 0; i <agesList.size(); ++i ) {
        if (agesList[i] > max) {
            max = agesList[i];
        }
    }
    for (int i = 0; i <agesList.size(); ++i ) {
        if (agesList[i] < min) {
            min = agesList[i];
        }
    }
    for (int i = 0; i <agesList.size(); ++i ) {
        averageAge += agesList[i];
    }

    averageAge = averageAge/static_cast<double>(agesList.size());

    cout << "Minimum Age: " << min << endl;
    cout << "Maximum Age: " << max << endl;
    cout << setprecision(3) << averageAge << endl;
}