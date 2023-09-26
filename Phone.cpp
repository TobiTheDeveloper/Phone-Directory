/*****************************************************************************
                        Workshop 1 - Part 2
Full Name  : Yusuff Oyediran
Student ID#: 142813203
Email      : yooyediran@myseneca.ca
Section    : ZEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Phone.h"
using namespace std;

namespace sdds {

    // Function to convert a string to uppercase
    void toUpper(char* str) {
        for (int i = 0; str[i] != '\0'; i++) {
            str[i] = toupper(str[i]);
        }
    }

    void phoneDir(const char* programTitle, const char* fileName) {
        cout << programTitle << " phone direcotry search\n";
        cout << "-------------------------------------------------------\n";
        string partialName;

        FILE* file = fopen(fileName, "r");
        if (!file) {
            cerr << fileName << " file not found!" << endl;
            cout << "Thank you for using " << programTitle << " directory." << endl;
            return;
        }

        bool shouldPrompt = true; // Flag to control the prompt

        while (true) {
            if (shouldPrompt) {
                cout << "Enter a partial name to search (no spaces) or enter '!' to exit\n";
                cout << "> ";
                cin >> partialName;
            }

            if (partialName == "!") {
                cout << "Thank you for using " << programTitle << " directory." << endl;
                break;
            }

            // Convert partialName to uppercase for case-insensitive search
            toUpper(&partialName[0]);

            bool found = false;
            char name[100], areaCode[4], prefix[4], number[5];

            while (fscanf(file, "%[^\t]\t%s\t%s\t%s\n", name, areaCode, prefix, number) == 4) {
                string nameStr(name), nameUpper(nameStr);
                transform(nameUpper.begin(), nameUpper.end(), nameUpper.begin(), ::toupper);

                if (nameUpper.find(partialName) != string::npos) {
                    cout << name << ": (" << areaCode << ") " << prefix << "-" << number << endl;
                    found = true;
                }
            }

            // Rewind the file to the beginning for the next search
            rewind(file);

            if (!found) {
            }
            else {
                shouldPrompt = true; // Prompt for the next search
            }
        }

        fclose(file);
    }
}
