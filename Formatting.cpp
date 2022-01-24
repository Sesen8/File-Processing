// Title: Lab 1 - Formatting.cpp
//
// Purpose: This file contains the program for three functions responsible for converting json line to cvs
//
// Class: CSC 2430 Winter 2022
// Author: Sesen Yonas

#include <cassert>
#include <iostream>

#include "Formatting.h"
#include "CalculationsForAges.h"

using std::cout;
using std::endl;

// Returns CSV header as a string
//
// Parameters:
//      None
// Returns:
//      CSV header
string CSVHeader() {
    string header;
    string first = "Firstname,";
    string last = "LastName,";
    string age = "Age,";
    string height = "Height,";
    string nationality = "Nationality";

    header =  first + last + age + height + nationality;

    return header;
}

// Converts one JSON formatted line to CSV, returning the CSV
// representation as a string
//
// Parameters:
//      json - JSON formatted line
// Returns:
//      CSV formatted line
string FormatAsCSV(const string& json) {
    string nowCSV;

    string comma= ",";

    //nowCSV = StringBetween(json, "\"FirstName\":\"", "\"") + comma + StringBetween(json, "\"LastName\":\"", "\"") + comma + GetAge(json) + comma + StringBetween(json, "\"Height\":", "\"") + comma +  StringBetween(json, "\"Nationality\":\"", "\"");

    nowCSV = GetFName(json) + comma + GetLName(json) + comma + GetAge(json) + comma +  GetHeight(json) + comma + GetNationality(json);
    return nowCSV;
}

// Return the age value stored in a JSON
// formatted line.  The return value is a string
// If age doesn't appear, returns empty string
//
// Parameters:
//      json - JSON formatted line
// Returns:
//      age as string, or empty if age doesn't appear
string GetAge(const string& json) {
    string ageCSV;

    size_t agePos;
    agePos = (json.find("Age\":"));
    if (agePos != string::npos){
        agePos = agePos+5;
        if (isspace(json.at(agePos))){
            agePos++;
        }
        while (isdigit(json.at(agePos))){
            ageCSV += json.at(agePos);
            agePos++;
        }
        AgeStringToInt(ageCSV);
        return ageCSV;
    }
    else{

        return "";
    }

}




string GetFName(const string &json) {
    string fName;
    size_t pos;

    pos = (json.find("FirstName"));
    if (pos != string::npos){
        pos = pos+12;
        while (json.at(pos) != '\"'){
            fName += json.at(pos);
            pos++;
        }
        return fName;
    }
    else {
        return "";
    }

}

string GetLName(const string& json){
    string lName;
    size_t pos;

    pos = json.find("LastName");
    if (pos != string::npos){
        pos = pos + 11;
        while (!ispunct(json.at(pos))){
            lName += json.at(pos);
            pos++;
        }
        return lName;
    }
    else {
        return "";
    }


}

string GetHeight(const string& json){
    string height;
    size_t pos;

    pos = json.find("Height");
    if(pos != string::npos){
        pos = pos +8;
        while (!ispunct(json.at(pos))){
            height += json.at(pos);
            pos++;
        }
        return height;
    }
    else {
        return "";
    }

}


string GetNationality(const string& json){
    string nat;
    size_t pos;

    pos = json.find("Nationality");

    if(pos!= string::npos){
        pos = pos +14;
        while (json.at(pos) != '\"'){
            nat += json.at(pos);
            pos++;
        }
        return nat;
    }
    else {
        return "";

    }


}

string StringBetween(const string& json, const string& startWord, const string& endWord) {
    size_t startPosition = json.find(startWord);

    if (startPosition != -1){

        size_t endPosition = json.find(endWord, startPosition+startWord.length());

        string between = json.substr(startPosition+startWord.length(), (endPosition)- startWord.length()-startPosition);

        return between;
    }

    return "";
}

