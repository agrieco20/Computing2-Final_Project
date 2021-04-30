/**
 * Filename: main.cpp
 * Authors: Anthony Grieco and Matthew O'Hara
 * Description: This is the main program that searches through the resume files and returns their match score based on the information the user supplied the program with
 */

#include <iostream>
#include <vector>
#include <fstream>
#include "Applicant.h"

using namespace std;

vector<string> split(string, char); //Distinguishes in the Resumes individual words
void requirementSet(string, Applicant*); //This is a menu that activates the same number of times the user indicates to the program how many skills they are looking for in their applicants' resumes
vector<vector<string>> allResumes; //Multidimensional Vector used to store all the resume files

//int main () {
//    cout << "Test" << endl;
//    ifstream infile;
//    infile.open ("Abhishek.txt");
//    if (infile.is_open()) {
//        cout << "works" << endl;
//    }
//
//    infile.close();
//    return 0;
//}
int counter = 0; //Acts as a counter that is used to increase the current requirement number (only in console output)
bool status; //Acts as a flag used throughout the program
string userInput; //Used to store all the information passed by the user to the program (ex: skills being looked for in a resume)
int placeHold; //Used for exception
string::size_type sz;
int main(){

    Applicant applicant; //Temporary
    vector<string> myVect;
    //cout << "test" << endl;
    string line; //Used to extract each line from file

    ifstream infile;
    infile.open ("Abhishek.txt", ios::in);
//    infile.open ("Smith Resume.txt", ios::in);
//    infile.open ("resume v6.txt", ios::in);

    if (infile.is_open()){
        while(getline(infile, line)){
            allResumes.push_back(split(line, ' '));
        }
    }

    cout<<endl<<endl;


    do{
        try {
            cout<<"How many skills are you looking for your applicants to have? ";
            getline(cin, userInput);
            cout << endl;
            placeHold=stoi(userInput,&sz);
            status=true;
        }
        catch (exception e) {
            cout<<"Please enter a number";
            cout<<endl;
            cout << e.what();
            cin.ignore();
            status=false;
        }
    }
    while(status == false);

//        //cout<<"What is your first requirement? ";
//        counter++;
//        cout << "What is requirement Number " << counter << "? ";
//        getline(cin, userInput);
//        cout << endl;
//        applicant.setReq(userInput);
//
//
//    do {
//        try {
//            cout<<"On a scale of 1-10 how important is this skill? ";
//            getline(cin, userInput);
//            cout << endl;
//            placeHold=stoi(userInput,&sz);
//            status=true;
//            if (placeHold<1 or placeHold>10) {
//                status = false;
//            }
//        }
//        catch (exception e) {
//            cout<<"Please enter a number between 1 and 10";
//            cout<<endl;
//            cout << e.what();
//            cin.ignore();
//            status=false;
//
//        }
//    }while(!status);

    for (int i = 0; i< stoi(userInput); i++) {
        requirementSet(userInput, &applicant);

    }

    applicant.getReq();

    // applicant.setReq(userInput);

    infile.close();
    return 0;
}



//Applicant applicant;
//Applicant * ptr_applicant = &applicant;








vector<string> split(string line, char delimiter) { //May need to make this a void function instead and add "vect" to the allResumes multi-dimensional vector at the end of this function instead
    vector<string> vect;
    string word;
    for (int i=0; i<line.size();i++) {
        if (((line[i]) != delimiter) and (i != line.size() - 1)) {
            word+=line[i];
        }
        else{
            if(i==line.size()-1)
                word+=line[i];
            vect.push_back(word);
//            cout << vect[vect.size()-1] << endl; //NOT PERMANENT, NEW

            word="";
        }
    }
    return vect;
}

void requirementSet(string userInput, Applicant* applicant){ //Sends pointer
    counter++;
    cout << "What is requirement Number " << counter << "? ";
    getline(cin, userInput);
    cout << endl;
//    applicant.setReq(userInput);
    applicant->setReq(userInput);

    do {
        try {
            cout<<"On a scale of 1-10 how important is this skill? ";
            getline(cin, userInput);
            cout << endl;
            placeHold=stoi(userInput,&sz);
            status=true;
            if (placeHold<1 or placeHold>10) {
                status = false;
            }else{
//                applicant.setReq(userInput);
                applicant->setReq(userInput);
            }
        }
        catch (exception e) {
            cout<<"Please enter a number between 1 and 10";
            cout<<endl;
            cout << e.what();
            cin.ignore();
            status=false;
        }
    }
    while(!status);
}