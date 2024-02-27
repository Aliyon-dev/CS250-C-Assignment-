<<<<<<< HEAD
=======
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For exit (EXIT FAILURE)

using namespace std;

struct Student{
    string name;
    int student_id;
    // A FIXED ARRAY FOR THE NUMBER OF COURSES EACH STUDENT IS TAKING 
    int grades[6]; 

};
// ASSUMING THE NUMBER OF STUDENT IN THE FILE WAS 10
const int MAX_STUDENTS = 10;

// FUNCTION TO READ STUDENT INFORMATION FROM THE FILE 
void readStudentRecords() {
    // THIS DISPLAYS A ERROR WHEN THE FILE FAILS TO OPEN 
    ifstream file("grades.txt");
    if (!file.is_open()) {
        cerr << " Error: Unable to open file " << endl;
        exit(EXIT_FAILURE);
    }

    // THI WILL READ THE FILE LINE BY LINE 
    string line;
    Student student[MAX_STUDENTS]; // THIS ARRAY IS USED TO STORE STUDENT INFORMATION 

    for (int i = 0, j = 0; i < MAX_STUDENTS && getline(file, line); ++i) {
    // INITIALIZING THE VARIABLE TO STORE THE INDICES OF A COMMA
    int pos = -1, next_pos = -1;
    
    // THIS WILL ITERATE THROUGH EACH LINE 
    for (int k = 0; k < line.length(); ++k) {
        // IF A COMMA IS FOUND, UPDATE, POS AND NEXT_POS WILL BE UPDATED ACCORDINGLY
        if (line[k] == ',') {
            if (pos == -1) {
                pos = k;
            } else {
                next_pos = k;
                break; // STOPE SEARCHING ONCE NEXT_POS IS FOUND 
            }
        }
    }
    
    // EXTRACT STUDENT'S NAME AND SID USING THE INDICES OF COMMAS
    if (pos != -1 && next_pos != -1) {
        student[i].name = line.substr(0, pos);
        student[i].student_id = line.substr(pos + 1, next_pos - pos - 1);
    }
    
    // READ GRADE
    pos = next_pos;
    for (int k = 0; k < 6; ++k) {
        // THIS WILL FIND THE NEXT POSITION OF THE COMMA 
        next_pos = line.find(',', pos + 1);
        
        // THIS WILL EXTRACT THE GRADES
        if (next_pos != string::npos) {
            student[i].grades[k] = stoi(line.substr(pos + 1, next_pos - pos - 1));
            pos = next_pos;
        }
    }
}
    file.close();
}

void menu(){
    int state; 
    cout<<"Choose an action below: "<<endl;
    cout<<"1. Print results slip"<<endl;
    cout<<"2. Exit "<<endl;
    cin>>state;

    switch (state)
    {
    case 1:
        break;
    
    case 2:

    default:
        break;
    }
}

////// FUNCTION TO PRINT THE RESULT SLIP ///////
void printSlip(){
    
    /// INITIALISING THE STRUCT WITH STUDENT DATA

    /* THIS PART REQUIRES THE FUNCTION TO DETERMINE THE GRADES, THE GRADE FUNCTION SHOULD RETURN A STRING e.g
    "A+" WHICH CAN BE PASSED TO THE STUDENT STRUCT BELOW  */
    student mystudent;

    // eg mystudent.ma110 = grades(40); this should return a "D"
    mystudent.name = "Aliyon Tembo";
    mystudent.grade_ma110 = "A+";
    mystudent.grade_ph110 = "B";
    mystudent.grade_cs110 = "C";
    mystudent.grade_la111 = "D";
    mystudent.grade_ch110 = "D";
    mystudent.grade_ch131 = "C+";
    
    
    // CREATING ARRAY FOR GRADES
    string grades[6][2] = {
        {"MA110", mystudent.grade_ma110},
        {"PH110", mystudent.grade_ph110},
        {"CS110", mystudent.grade_cs110},
        {"LA111", mystudent.grade_la111},
        {"CH110", mystudent.grade_ch110},
        {"CH131", mystudent.grade_ch131},
    };


      /// DRAW LINES 
    int line_size = 55;
    for(int i=0; i<line_size; i++){
        cout<<"-";
    }cout<<endl;
    cout<<"\t"<<"\t\t\t"<<"COPPERBELT UNIVERSITY"<<endl;
    cout<<"SCHOOL OF INFORMATION & COMMUNICATION TECHNOLOGY"<<endl;
    
    //DRAW LINES 
    for(int i=0; i<line_size; i++){
        cout<<"-";
    }cout<<endl;
    cout<<"\t\t\t\t"<<"RESULTS FOR 2024"<<endl;
    cout<<" "<<endl;
    cout<<"NAME: "<<"\t\t\t\t\t\t\t\t\t"<<mystudent.name<<endl;
    cout<<"STUDENT NO:"<<"\t\t\t\t\t\t\t\t\t"<<mystudent.student_id<<endl;
    cout<<" "<<endl;
    
    //DRAW LINES
    for(int i=0; i<line_size; i++){
        cout<<"=";
    }cout<<endl;
    
    //CREATING THE HEADER FOR THE TABLE
    cout<<"COURSE"<<"\t\t\t\t\t\t\t\t\t\t\t"<<"GRADE"<<endl;
    
    for(int i=0; i<line_size; i++){
        cout<<"=";
    }cout<<endl;
    
    
    //CREATING AND RENDERING ROWS AND COLUMNS
    for(int i = 0; i<6; i++){
        cout<<grades[i][0];
        for(int j =0; j < 12; j++){
            cout<<"\t";
        }
        cout<<grades[i][1];
        cout<<endl;
        
        for(int i=0; i<line_size; i++){
        cout<<"-";
    }cout<<endl;
    
        
    }
    
}

int main(){

//    fstream infile;
//    infile.open("grades.txt");
//    string file;
//    string grades[10];
//
//    if(infile.is_open()){
//        int i = 0;
//        while(!infile.eof()){
//            infile>>grades[i];
//            cout<<grades[i]<<endl;
//            i +=1;
//    }
//    cout<<endl;
//    menu();
//    return 0;
//}
printSlip();

}
>>>>>>> 652ce555a97d15094264d9239e24641eff6ccbd8
