#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> getInput(string filename)
{
    vector<int> inputs;
    ifstream inFile;
    inFile.open(filename.c_str());
    string line;

    while (getline(inFile, line))
    {
        inputs.push_back(stoi(line));
    }

    return inputs;
}

int calcRequiredFuel(int mass)
{
    // base case
    if (mass <= 0)
    {
        return 0;
    }

    // Calculate required fuel
    int reqFuel = ((int)floor(mass / 3) - 2);

    // Treat negative fuel requirement as 0
    reqFuel = reqFuel <= 0 ? 0 : reqFuel;
        
    // Call recursively (part 2)
    return reqFuel + calcRequiredFuel(reqFuel);
}

int main()
{
    vector<int> masses = getInput("../../input/day01.txt");

    int totalFuel = 0;
    for (int mass : masses)
    {
        totalFuel += calcRequiredFuel(mass);
    }

    // Part 2 answer
    cout << totalFuel;

    return 0;
}