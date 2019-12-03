#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

enum Opcode
{
    ADD = 1,
    MULT = 2,
    EXIT = 99
};

vector<int> getInput(string filename)
{
    vector<int> inputs;
    ifstream inFile;
    string number;

    inFile.open(filename.c_str());
    if (!inFile.is_open())
    {
        cout << "error opening file";
        exit(1);
    }

    while (getline(inFile, number, ','))
    {
        inputs.push_back(stoi(number));
    }

    inFile.close();

    return inputs;
}

int main()
{
    vector<int> inputs = getInput("../../input/day02.txt");
    vector<int> temp = inputs;
    // Set 1202 Program Alarm state

    for (int noun = 0; noun < 100; noun++)
    {
        for (int verb = 0; verb < 100; verb++)
        {
            inputs = temp;
            inputs[1] = noun;
            inputs[2] = verb;
            for (int k = 0; k < inputs.size(); k += 4)
            {
                int opcode = inputs[k];
                int pos_val1 = inputs[k + 1];
                int pos_val2 = inputs[k + 2];
                int pos_out = inputs[k + 3];
                switch (opcode)
                {
                case ADD:
                    inputs[pos_out] = inputs[pos_val1] + inputs[pos_val2];
                    break;
                case MULT:
                    inputs[pos_out] = inputs[pos_val1] * inputs[pos_val2];
                    break;
                case EXIT:
                    // End iterations
                    k = inputs.size();
                    break;
                }
            }
            if (noun == 12 && verb == 2)
            {
                cout << "PART 1 FOUND:" << endl;
                cout << inputs[0] << endl;
            }

            if (inputs[0] == 19690720)
            {
                cout << "PART 2 FOUND:" << endl;
                cout << 100 * noun + verb << endl;
            }
        }
    }

    return 0;
}