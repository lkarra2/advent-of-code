#include<iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace Day1 {

    void getFirstNumber(string line, int& first, int& firstPos) 
    {
        int numberFirstPos[9];
        int lowestIndex = line.length();

        numberFirstPos[0] = line.find("one");
        numberFirstPos[1] = line.find("two");
        numberFirstPos[2] = line.find("three");
        numberFirstPos[3] = line.find("four");
        numberFirstPos[4] = line.find("five");
        numberFirstPos[5] = line.find("six");
        numberFirstPos[6] = line.find("seven");
        numberFirstPos[7] = line.find("eight");
        numberFirstPos[8] = line.find("nine");

        for (int i = 0; i < 9; i++) 
        {
            if (numberFirstPos[i] > -1 && numberFirstPos[i] < lowestIndex) 
            {
                first = i + 1;
                firstPos = numberFirstPos[i];
                lowestIndex = firstPos;
            }
        }
    }

    void getLastNumber(string line, int& last, int& lastPos) 
    {
        int numberLastPos[9];
        int highestIndex = -1;

        numberLastPos[0] = line.rfind("one");
        numberLastPos[1] = line.rfind("two");
        numberLastPos[2] = line.rfind("three");
        numberLastPos[3] = line.rfind("four");
        numberLastPos[4] = line.rfind("five");
        numberLastPos[5] = line.rfind("six");
        numberLastPos[6] = line.rfind("seven");
        numberLastPos[7] = line.rfind("eight");
        numberLastPos[8] = line.rfind("nine");

        for (int i = 0; i < 9; i++) 
        {
            if (numberLastPos[i] > -1 && numberLastPos[i] > highestIndex) 
            {
                last = i + 1;
                lastPos = numberLastPos[i];
                highestIndex = lastPos;
            }

        }
    }
    
    int getNumber(string line) {
        char c;
        string result;

        int first = 0;
        int& ref_first {first};
        int firstPos = -1;
        int& ref_firstPos {firstPos};
        int last = 0;
        int& ref_last {last};
        int lastPos = -1;
        int& ref_lastPos {lastPos};

        getFirstNumber(line, ref_first, ref_firstPos);
        getLastNumber(line, ref_last, ref_lastPos);

        // Finding first number
        for (int i = 0; i < line.length(); i++) {
            c = line[i];
            if (c > 48 && c < 58 && (i <= firstPos || firstPos == -1)) {
                result += c;
                break;
            }

        }
        if (result.length() == 0) {
            result += to_string(first);
        }

            
        // Finding last number
        for (int j = line.length() - 1; j >= 0; j--) {
            c = line[j];
            if (c > 47 && c < 58 && (j > lastPos || lastPos == -1)) {
                result += c;
                break;
            }
        }
        if (result.length() == 1) {
            result += to_string(last);
        }

        return stoi(result);
    }

    extern void Run() {
        int totalCalibration = 0;
        string line;

        ifstream inputFile;
        inputFile.open("day1_input.txt");
        while (inputFile.peek() != EOF) {
            getline(inputFile, line);
            totalCalibration += getNumber(line);
        }
        cout << "\nTotal Caliberation: " << totalCalibration << "\n";
    }

}