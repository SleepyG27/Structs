/* Rewrite the Program 1 so that it uses structs rather than parallel arrays for the underlying data
structure. */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;

struct Runner {
    string name;
    int miles[NUM_DAYS];
    int totalMiles;
    double averageMiles;
};

void readDataFromFile(const string& filename, Runner runners[]) {
    ifstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < NUM_RUNNERS; ++i) {
            file >> runners[i].name;
            runners[i].totalMiles = 0;
            for (int j = 0; j < NUM_DAYS; ++j) {
                file >> runners[i].miles[j];
                runners[i].totalMiles += runners[i].miles[j];
            }
            runners[i].averageMiles = static_cast<double>(runners[i].totalMiles) / NUM_DAYS;
        }
        file.close();
    }
    else {
        cout << "Unable to open file." << endl;
    }
}

void outputResults(const Runner runners[]) {
    cout << setw(10) << left << "Runner";
    for (int i = 1; i <= NUM_DAYS; ++i) {
        cout << setw(7) << "Day " + to_string(i);
    }
    cout << setw(8) << "Total" << setw(10) << "Average" << endl;

    for (int i = 0; i < NUM_RUNNERS; ++i) {
        cout << setw(10) << left << runners[i].name;
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << setw(7) << runners[i].miles[j];
        }
        cout << setw(8) << runners[i].totalMiles << setw(10) << fixed << setprecision(2) << runners[i].averageMiles << endl;
    }
}

int main() {
    Runner runners[NUM_RUNNERS];

    // Read data from the file
    readDataFromFile("runners.txt", runners);

    // Output the results
    outputResults(runners);

    return 0;
}
