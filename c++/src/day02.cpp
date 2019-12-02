#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

enum Opcode { ADD = 1, MULT = 2, EXIT = 99 };

vector<int> getInput(string filename) {
  vector<int> inputs;
  ifstream inFile;
  string number;
  
  inFile.open(filename.c_str());
  if (!inFile.is_open()) {
    cout << "error opening file";
    exit(1);
  }
  
  while (getline(inFile, number, ',')) {
    inputs.push_back(stoi(number));
  }
  
  inFile.close();

  return inputs;
}

int main() {
  vector<int> inputs = getInput("../../input/day02.txt");

  // Set 1202 Program Alarm state
  inputs[1] = 12;
  inputs[2] = 2;

  for (int i = 0; i < inputs.size(); i += 4) {
    int opcode   = inputs[i];
    int pos_val1 = inputs[i + 1];
    int pos_val2 = inputs[i + 2];
    int pos_out  = inputs[i + 3];
    switch (opcode) {
      case ADD:
        inputs[pos_out] = inputs[pos_val1] + inputs[pos_val2];
        break;
      case MULT:
        inputs[pos_out] = inputs[pos_val1] * inputs[pos_val2];
        break;
      case EXIT:
        // Get solution
        cout << inputs[0];
        exit(0);
        break;
    }
  }

  return 0;
}