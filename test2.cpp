/**
 * Filename: test2.cpp
 * Authors: Anthony Grieco and Matthew O'Hara
 * Description: This is a TEST program that searches through the resume files and returns their match score based on the information the user supplied the program with
 */

#include <iostream>
#include <vector>
#include <fstream>
#include "Applicant.h"
//#include <string>

using namespace std;

vector<string> split(string, char); //Distinguishes in the Resumes individual words
void requirementSet(string, Applicant*); //This is a menu that activates the same number of times the user indicates to the program how many skills they are looking for in their applicants' resumes
//vector<vector<string>> allResumes; //NOT USED, Multidimensional Vector used to store all the resume files
vector <string> indivResume;

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
int totalNumPoints = 0; //Used to determine the total number of points possible to be earned by the applicants and used to calculate the percentage match
int applicantPoints=0;
bool status; //Acts as a flag used throughout the program
string userInput; //Used to store all the information passed by the user to the program (ex: skills being looked for in a resume)
int placeHold; //Used for exception
string::size_type sz;

int main(){

    Applicant applicant; //Temporary
//    vector<string> myVect;
    //cout << "test" << endl;
    string line; //Used to extract each line from file

    ifstream infile;
//    infile.open ("Abhishek.txt", ios::in);
    infile.open ("Smith Resume.txt", ios::in);
//    infile.open ("resume v6.txt", ios::in);

    if (infile.is_open()){ //Opens the individual resume and assigns it to its own
        while(getline(infile, line)){
//            allResumes.push_back(split(line, ' '))
            vector<string> myvect=split(line, ' ');
            for(auto elem : myvect) {
                indivResume.push_back(elem);
            }
        }
    }

    cout<<endl<<endl;


    do{ //Asks the user for how many points
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
    } while(status == false);

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

//    applicant.getReq();

//    for(auto elem :allResumes){
//        for(auto req : applicant.copyReqVect){
//
//        }
//    }
//
//    cout << applicant.copyReqVect[0] << endl;

//    int counter2=0;
//    for(auto elem : indivResume) { //Used to see whether the allResumes vector was receiving the vector sent to it (printed out values within it)
//       // for (auto word : elem) {
//            if (elem == applicant.copyReqVect[counter2]) {
//                cout << elem << endl;
//                counter2++;
//            } else {
//                counter2++;
//            }
//        //}
//    }

//    if (applicant.copyReqVect.empty()){
    if (applicant.copyReqVect.empty()){ //NOT PERMANENT
        cout << "Empty" << endl;
    }

//    for (int i = 0; i < applicant.copyReqVect.size(); i++){
//        cout << applicant.copyReqVect[i] << endl;
//    }

//    for (int i = 0; i<applicant.copyReqVect.size(); i+=2){ //TEST
//        for (int j = 0; j<indivResume.size(); j++){
//            for (int k = 0; k<allResumes[j].size(); k++) {
//                    //cout << j << endl;
//                if (applicant.copyReqVect[i] == indivResume[j]) {
//                    cout << "Found" << endl;
//                }
//            }
//        }
//    }

    vector<string> multiWord;

    for (int i = 0; i<applicant.copyReqVect.size(); i+=2){//TEST
        for(auto elem : applicant.copyReqVect[i]){ //Checks to see if the user inputted multiple words and splits them up accordingly
            if(isspace(elem)){
                multiWord=split(applicant.copyReqVect[i],' ');
            }
        }
//        if(applicant.copyReqVect[i] ==)
        for (int j = 0; j<indivResume.size(); j++){
             if(applicant.copyReqVect[i] == indivResume[j]){
                //cout << "Found Single Word" << endl; //cout Not Permanent
                //cout<<applicant.copyReqVect[i+1]<<endl;
                applicantPoints+=stoi(applicant.copyReqVect[i+1]);
            }
            for (int k = 0; k<multiWord.size(); k++){
//            if (applicant.copyReqVect[i] == indivResume[j]) {

                if(multiWord[k] == indivResume[j] && multiWord[k+1] == indivResume[j+1]){ //Searches for multiple words sent by a user
                    //cout << "Found Multiple Words" << endl; //cout Not Permanent
//                    cout<<applicant.copyReqVect[i+1]<<endl;
                    applicantPoints+=stoi(applicant.copyReqVect[i+1]);
                    //cout<<applicantPoints<<endl;
                    multiWord.clear();
                    break;
                }

//                //else if(multiWord[k] == indivResume[j]){ //Searches for a single word sent by a user
//                else if(applicant.copyReqVect[i] == indivResume[j]){
//                    cout << "Found Single Word" << endl; //cout Not Permanent
//                    cout<<applicant.copyReqVect[i+1]<<endl;
//                    applicantPoints+=stoi(applicant.copyReqVect[i+1]);
//                    multiWord.clear();
//                }

//                cout << "Found" << endl; //cout Not Permanent
//                cout<<applicant.copyReqVect[i+1]<<endl;
//                applicantPoints+=stoi(applicant.copyReqVect[i+1]);
            }
        }
    }



    //CALCULATIONS

    int divide=100/totalNumPoints;
    int mult=divide*applicantPoints;
    cout<<mult<<"% Chance of Being Hired"<<endl;




   // applicant.setReq(userInput);

//    for(auto elem : allResumes){ //Used to see whether the allResumes vector was receiving the vector sent to it (printed out values within it)
//        for(auto word : elem){
//            cout<<word+" ";
//        }
//    }

//    for (int i = 0; i < applicant.copyReqVect.size(); i++){ //NOT PERMANENT
//        cout << applicant.copyReqVect[i] << endl;
//    }

//    cout << applicant.copyReqVect[1] << endl; //NOT PERMANENT

    infile.close();
    return 0;
}









vector<string> split(string line, char delimiter) { //May need to make this a void function instead and add "vect" to the allResumes multi-dimensional vector at the end of this function instead
    vector<string> vect;
    string word;
    for (int i=0; i<line.size();i++) {
        if (((line[i]) != delimiter) and (i != line.size() - 1)) {
            word+=tolower(line[i]); //Sets everything being placed in the resume vector to lowercase (error control)
        }
        else{
            if(i==line.size()-1)
                word+=tolower(line[i]); //Sets everything being placed in the resume vector to lowercase (error control)
            vect.push_back(word);
//            cout << vect[vect.size()-1] << endl; //NOT PERMANENT, NEW

            word="";
        }
    }
    return vect;
}

void requirementSet(string userInput, Applicant* applicant){ //Sends pointer of the Applicant object
    counter++;
    cout << "What is requirement Number " << counter << "? ";
    getline(cin, userInput);
//    vector<string> splitPut=split(userInput,' ');
    cout << endl;
//    applicant.setReq(userInput);

//    for(auto elem : splitPut){
//        applicant->setReq(elem);
//    }
    string tempInput;
    for (int i = 0; i<userInput.size(); i++){ //Sets the input taken from the user to lower case to help with error control
        tempInput += tolower(userInput[i]);
    }

    userInput = tempInput;
    tempInput="";

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
                totalNumPoints += stoi(userInput);
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