#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//struct student{
//    string name;
//    int student_id;
//
//};


void menu(){
    cout<<"Choose an action below: "<<endl;

    cout<<"1. Print results slip"<<endl;
    cout<<"2. Exit "<<endl;
}

int main(){

    fstream infile;
    infile.open("grades.txt");
    string file;
    string grades[10];


    if(infile.is_open()){
        int i = 0;
        while(!infile.eof()){
            infile>>grades[i];
            cout<<grades[i]<<endl;
            i +=1;
        
    }
    cout<<endl;
    menu();
    return 0;
}

}