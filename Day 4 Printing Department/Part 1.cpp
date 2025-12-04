#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream file("input.txt");
    
    // Check that the file was found correctly
    if (!file.is_open()) {
        cout << "ERROR: Failed to open file." << endl;
        return 1;
    }
        
    string line;
    string padding = "";
    vector <string> input;

    while (getline(file, line)) {
        if (padding == "") {
            padding = string(line.length() + 2, '#');
        }

        input.push_back("#" + line + "#");
    }

    input.insert(input.begin(), padding);
    input.insert(input.end(), padding);

    int accessedRolls = 0;

    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[0].length(); j++) {
            if (input[i][j] == '@') {
                int adjacentRolls = 0;

                if (input[i - 1][j - 1] == '@') {
                    adjacentRolls += 1;
                }
                                
                if (input[i - 1][j] == '@') {
                    adjacentRolls += 1;
                }

                if (input[i - 1][j + 1] == '@') {
                    adjacentRolls += 1;
                }

                if (input[i][j - 1] == '@') {
                    adjacentRolls += 1;
                }

                if (input[i][j + 1] == '@') {
                    adjacentRolls += 1;
                }

                if (input[i + 1][j - 1] == '@') {
                    adjacentRolls += 1;
                }

                if (input[i + 1][j] == '@') {
                    adjacentRolls += 1;
                }

                if (input[i + 1][j + 1] == '@') {
                    adjacentRolls += 1;
                }

                if (adjacentRolls < 4) {
                    accessedRolls += 1;
                }
            }
        }
    }

    cout << accessedRolls << " rolls can be accessed by a forklift"<< endl;

    file.close();

    return 0;
}