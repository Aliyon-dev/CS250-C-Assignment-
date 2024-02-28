#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>







using namespace std;


/// STRUCT TO STORE STUDENT DETAILS ///
struct Student{
    string name;
    string sin;
    string MA_110, CS_131, CH_110, LA_111, PH_110, CS_110;

};

/// FUNCTION DECLARATION ///

void printSlip(string sin);
void menu();

void menu(){
    string SID;
    int state;
    cout<<"Choose an action below: "<<endl;
    cout<<"1. Print results slip"<<endl;
    cout<<"2. Exit "<<endl;
    cin>>state;

    switch (state)
    {
    case 1:
    cout<<"enter the SID to print the result slip: ";
    cin>>SID;
    system("cls");
    printSlip(SID);

    case 2:
        system("cls");
        cout<<"Thank you using the system, exiting system"<<endl;
        break;

    default:
        break;
    }
}



////////// FUNCTION TO GET THE GRADE FOR A STUDENT //////////

string gradeConventer(int score){
    string grade;
        if(score<40 && score>=0 ){
            grade="D";
    }
        else if(score<50 && score>=0){
            grade="D+";
        }
            else if(score<56 && score>=0 ){
                grade="C";
        }
                else if(score<62 && score>=0 ){
                    grade="C+";
    }
                    else if(score<68 && score>=0 ){
                        grade="B";}

                        else if(score<76 && score>=0 ){
                            grade="B+";
}
                            else if(score<86 && score>=0 ){
                                grade="A";
}
                                else if(score<101 && score>=0){
                                grade="A+";

}

return grade;
}

////// FUNCTION TO PRINT THE RESULT SLIP ///////
void printSlip(string sin){
    /* THIS PART REQUIRES THE FUNCTION TO DETERMINE THE GRADES, THE GRADE FUNCTION SHOULD RETURN A STRING e.g
    "A+" WHICH CAN BE PASSED TO THE STUDENT STRUCT BELOW  */
    // eg mystudent.ma110 = grades(40); this should return a "D"


    string line = "";
    ifstream infile;
    Student mystudent[11];
    infile.open("grades.txt");
    int i = 0;
    while(getline(infile, line)){

        stringstream inputString(line);
        getline(inputString, mystudent[i].name, ',');
        getline(inputString, mystudent[i].sin, ',');
        getline(inputString, mystudent[i].CS_110, ',');
        getline(inputString, mystudent[i].MA_110, ',');
        getline(inputString, mystudent[i].CS_131, ',');
        getline(inputString, mystudent[i].CH_110, ',');
        getline(inputString, mystudent[i].LA_111, ',');
        getline(inputString, mystudent[i].PH_110, ',');
        i += 1;
    }

    int index=0;
    for(int i=0; i<11; i++){
        if(mystudent[i].sin == sin){
            index = i;
        }
    }

    if(index>=1){
    string grade_ma = gradeConventer(stoi(mystudent[index].MA_110));
    string grade_la = gradeConventer(stoi(mystudent[index].LA_111));
    string grade_cs = gradeConventer(stoi(mystudent[index].CS_110));
    string grade_ch = gradeConventer(stoi(mystudent[index].CH_110));
    string grade_cl = gradeConventer(stoi(mystudent[index].CS_131));
    string grade_ph = gradeConventer(stoi(mystudent[index].PH_110));


    //ARRAY USED FOR PRINTING THE GRADES
    string grades[6][2] = {
        {"CS110", grade_cs},
        {"MA110", grade_ma},
        {"CH131", grade_cl},
        {"CH110", grade_ch},
        {"LA111", grade_la},
        {"PH110", grade_ph},

    };


      /// DRAW LINES
    int line_size = 57;
    for(int i=0; i<line_size; i++){
        cout<<"-";
    }cout<<endl;
    cout<<"\t\t"<<"COPPERBELT UNIVERSITY"<<endl;
    cout<<"SCHOOL OF INFORMATION & COMMUNICATION TECHNOLOGY"<<endl;

    //DRAW LINES
    for(int i=0; i<line_size; i++){
        cout<<"-";
    }cout<<endl;
    cout<<"\t\t"<<"RESULTS FOR 2024"<<endl;
    cout<<" "<<endl;
    cout<<"NAME: "<<"\t\t\t\t\t\t"<<mystudent[index].name<<endl;
    cout<<"STUDENT NO:"<<"\t\t\t\t\t"<<mystudent[index].sin<<endl;
    cout<<" "<<endl;

    //DRAW LINES
    for(int i=0; i<line_size; i++){
        cout<<"=";
    }cout<<endl;

    //CREATING THE HEADER FOR THE TABLE
    cout<<"COURSE"<<"\t\t\t\t\t"<<"            "<<"GRADE"<<endl;

    for(int i=0; i<line_size; i++){
        cout<<"=";
    }cout<<endl;


    //CREATING AND RENDERING ROWS AND COLUMNS
    for(int i = 0; i<6; i++){
        cout<<grades[i][0];
        for(int j =0; j < 7; j++){
            cout<<"\t";
        }
        cout<<grades[i][1];
        cout<<endl;

        for(int i=0; i<line_size; i++){
        cout<<"-";
    }cout<<endl;


    }
    menu();
}

    else{
        cout<<"Invalid SID"<<endl;
        menu();
}

}

int main(){

    ifstream infile;
    string input, name, sin;
    infile.open("grades.txt");

    if(infile.is_open()){
        while(getline(infile, input)){
            stringstream row(input);
            getline(row, name, ',');
            getline(row, sin, ',');
            cout<<name<<"\t"<<sin<<endl;
            //cout<<input<<endl;
            }
            infile.close();
            cout<<endl;
            menu();
            }

    else{
        cout<<"File not found. Make sure sure the file is the saved in the directory";
    }

    return 0;
}
