#include <iostream>
#include <fstream>

using namespace std;
// The struct is used to represent a student's credentials 
struct Student {
    string name;
    string SID;
    int grades[6]; // A fixed array for the number of course each student is taking 
}
// We assume that the maximum number of students is 10
const int MAX_STUDENTS = 10;


// Function to read student records from file
void readStudentRecords() {
    // Displays an error when the program fails to open the fails 
    ifstream file("sample.txt");
    if (!file.is_open()) {
        cerr << " Error: Unable to open file " << endl;
        exit(EXIT_FAILURE);
    }

    // Reads the file line by line 
    string line;
    Student students[MAX_STUDENTS]; // Array to store student records

    for (int i = 0, j = 0; i < MAX_STUDENTS && getline(file, line); ++i) {
    // Initialize variables to store the indices of commas
    int pos = -1, next_pos = -1;
    
    // Iterate through each character of the line
    for (int k = 0; k < line.length(); ++k) {
        // If a comma is found, update pos and next_pos accordingly
        if (line[k] == ',') {
            if (pos == -1) {
                pos = k;
            } else {
                next_pos = k;
                break; // Stop searching once next_pos is found
            }
        }
    }
    
    // Extract student's name and SID using the indices of commas
    if (pos != -1 && next_pos != -1) {
        students[i].name = line.substr(0, pos);
        students[i].SID = line.substr(pos + 1, next_pos - pos - 1);
    }
    
    // Read grades
    pos = next_pos;
    for (int k = 0; k < 6; ++k) {
        // Find the position of the next comma
        next_pos = line.find(',', pos + 1);
        
        // Extract the grade
        if (next_pos != string::npos) {
            students[i].grades[k] = stoi(line.substr(pos + 1, next_pos - pos - 1));
            pos = next_pos;
        }
    }
}

    file.close();

}

int main(){

    
    return 0;
}