// Title: Lab 1 - Formatting.h
//
// Purpose: Declares the functions that understand the JSON format and can reformat a line of
// JSON to a line of CSV
//
// Class: CSC 2430 Winter 2022
// Author: Max Benson

#ifndef FORMATTING_H
#define FORMATTING_H

#include <string>
using std::string;

string CSVHeader();
string FormatAsCSV(const string& json);
string StringBetween(const string& json, const string& startWord, const string& endWord);
string GetAge(const string& json);
string GetFName(const string& json);
string GetLName(const string& json);
string GetHeight(const string& json);
string GetNationality(const string& json);


#endif //FORMATTING_H
