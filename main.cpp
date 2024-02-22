#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct student{
    string name;
    int student_id;
    string grade_ma110, grade_ph110, grade_cs110, grade_la111, grade_ch110, grade_ch131;

};


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


void printSlip(){
    
    //INITIALISING THE STRUCT WITH STUDENT DATA
    student mystudent;
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


      //DRAW LINES 
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