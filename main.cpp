/**
 * Filename: main.cpp
 * Authors: Anthony Grieco and Matthew O'Hara
 * Description: This is the main program that searches through the resume files and returns their match score based on the information the user supplied the program with
 */

#include <iostream>
#include <vector>
#include <fstream>
#include "Applicant.h"
#include <dirent.h> //Special Library used so that file directories can be manipulated and all resumes within a folder can be read

using namespace std;

vector<string> split(string, char); //Distinguishes the Resumes individual words
void requirementSet(string, Applicant*); //This is a menu that activates the same number of times the user indicates to the program how many skills they are looking for in their applicants' resumes
vector<vector<string>> allResumes; //Multidimensional Vector used to store all the resume files
vector <string> indivResume; //Used to load each individual resume into a vector containing every resume
string strip(string); //Used to strip non-essential punctuation from each word in every resume [excluding "+" and "#"]

int counter = 0; //Acts as a counter that is used to increase the current requirement number (only in console output)
int totalNumPoints = 0; //Used to determine the total number of points possible to be earned by the applicants and used to calculate the percentage match
bool status; //Acts as a flag used throughout the program
string userInput; //Used to store all the information passed by the user to the program (ex: skills being looked for in a resume)
int placeHold; //Used for exceptions
string::size_type sz;
vector<string> experience; //Used to store the experience (number of years) corresponding to a person's skill as specified by the user of the program
vector<string> foundReq; //Used to store the name of the skill being searched for by the user

int main(){
    bool realFileVerify = true;

    //Reads as many resume files into the allResumes vector as there are in the "Resumes" sub-folder
    vector<string> fileVector;
    DIR *dr;
    struct dirent *en;
    dr = opendir("./Resumes"); //open all or present directory
    if (dr) {
        while ((en = readdir(dr)) != NULL) {
            if (fileVector.size() > 1 && realFileVerify == true){ //Removes the files named "." and ".." from the vector to not mess with the actual resume files
                fileVector.clear();
                realFileVerify = false;
            }
            fileVector.push_back(en->d_name);
        }
        closedir(dr); //closes all directories
    }

    string line; //Used to extract each line from file
    ifstream infile; //Used to read each individual resume file from the "Resumes" directory
    string infileName = ""; //Used as a string to concatenate the sub-folder "Resumes" and the current file about to be parsed

    for (int i = 0; i < fileVector.size(); i++){
        infileName = "";
        infileName += "./Resumes/" + fileVector[i]; //Relative URL to the resume file being read into program
        infile.open(infileName, ios::in);
        if (infile.is_open()) { //Opens each individual resume
            while (getline(infile, line)) {
                vector<string> myvect = split(line, ' ');
                for (auto elem : myvect) {
                    indivResume.push_back(elem);
                }
            }
        }
        allResumes.push_back(indivResume);
        indivResume.clear();
        infile.close();
    }

    cout<<endl<<endl;

    Applicant applicant; //Creates an Applicant object named applicant

    do{ //Asks the user for how many skills they are looking for
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

    //Opens a file named "resumeSearchResults.txt" that will be written to
    ofstream outfile;
    outfile.open ("resumeSearchResults.txt");

    for (int i = 0; i< stoi(userInput); i++) {
        requirementSet(userInput, &applicant);
    }

    //The following prints the requirements given by the user to both the console and the outfile "resumeSearchResults"
    cout << "Requirements: " << endl;
    outfile << "Requirements:" << endl;

    //Formatting so that the first letter of each word is capitalized
    for (int i = 0; i<applicant.copyReqVect.size(); i+=2){
        cout << (char) toupper(applicant.copyReqVect[i][0]);
        outfile << (char) toupper(applicant.copyReqVect[i][0]);
        for (int j = 1; j<applicant.copyReqVect[i].size(); j++){
            cout << applicant.copyReqVect[i][j];
            outfile << applicant.copyReqVect[i][j];
        }
        cout << endl;
        outfile << endl;
    }
    cout << "***********************************" << endl;
    outfile << "***********************************" << endl;

    vector<string> multiWord;

    //Searches through every resume for the information the user of the program sends and evaluates that information for each of the applicants
    for(auto applicants : allResumes) {
        string tempName;
        int applicantPoints = 0;
        for (int i = 0; i < applicant.copyReqVect.size(); i += 2) {
            for (auto elem : applicant.copyReqVect[i]) { //Checks to see if the user inputted multiple words and splits them up accordingly
                if (isspace(elem)) {
                    multiWord = split(applicant.copyReqVect[i], ' ');
                }
            }

            for (int j = 0; j < applicants.size(); j++) {

                //Searches for a single word requirement sent by a user
                if (applicant.copyReqVect[i] == applicants[j]) {
                    applicantPoints += stoi(applicant.copyReqVect[i + 1]); //The value after the required skill is the total possible point value associated with it
                    foundReq.push_back(applicant.copyReqVect[i]);

                    //Searching for the number of years associated with the skill being searched for
                    for (int m = 0; m < 5; m++) {
                        if (applicants[j + m] == "year") { //Works
                            experience.push_back(applicants[j + m -1]);
                        }

                        else if(applicants[j + m] !="year"){
                            for(int n = 0; n < j; n++){
                                if(applicants[j - n] =="years"){
                                    experience.push_back(applicants[j-n-1]);
                                }
                            }
                        }
                    }
                    if(experience.empty()){
                        experience.push_back("1");
                    }

                    break;
                }
                for (int k = 0; k < multiWord.size(); k++) {

                    //Searches for a multiple word requirement sent by a user
                    if (multiWord[k] == applicants[j] && multiWord[k + 1] == applicants[j + 1]) {
                        applicantPoints += stoi(applicant.copyReqVect[i + 1]); //The value after the required skill is the total possible point value associated with it
                        foundReq.push_back(applicant.copyReqVect[i]);

                        for (int m = 0; m < 5; m++) {
                            if (applicants[j + m] == "year") { //Works
                                experience.push_back(applicants[j + m -1]);
                            }

                            else if(applicants[j + m] !="year"){
                                for(int n = 0; n < j; n++){
                                    if(applicants[j - n] =="years"){
                                        experience.push_back(applicants[j-n-1]);
                                    }
                                }
                            }
                        }
                        if(experience.empty()){
                            experience.push_back("1");
                        }

                        multiWord.clear();
                        break;
                    }
                }
            }

            if (applicants[0] != "phone" && applicants[0] != "email" && applicants[1]!="number"){//||applicants[1]!="number"){
                tempName=applicants[0]+" "+applicants[1];
            }
            else if (applicants[0] == "phone" || applicants[1]=="number"){
                tempName=applicants[4]+" "+applicants[5];
            }

            else if (applicants[0] == "email"){
                tempName=applicants[2]+" "+applicants[3];
            }

            else if (applicants[0] == "email" || applicants[1] == "address"){
                tempName=applicants[3]+" "+applicants[4];
            }
        }

        //Calculates the Percent Match between what the user has inputted and the values in each resume
        int divide = 100 / totalNumPoints;
        int mult = divide * applicantPoints;

        for (int i = 0; i<tempName.size(); i++){ //Formatting so that the first letter of each name is capitalized
            if (i == 0 || tempName[i-1] == ' ' || tempName[i-1] == '\n') {
                cout << (char) toupper(tempName[i]);
                outfile << (char) toupper(tempName[i]);

            }
            else {
                cout << tempName[i];
                outfile << tempName[i];
            }
        }
        cout << endl;
        outfile << endl;
        cout << "Skills Match: " << mult << "%" << endl;
        outfile << "Skills Match: " << mult << "%" << endl;

        cout<< "Number of Years in ";
        outfile << "Number of Years in ";
        for(auto elem : foundReq){
            cout << elem << " ";
            outfile << elem << " ";
        }
        cout << ": " << endl;
        outfile << ": " << endl;
        for(auto elem : experience){
            cout<<elem<<" years, ";
            outfile<<elem<<" years, ";
        }
        cout << endl << endl << endl;
        outfile << endl << endl << endl;
        experience.clear();
        foundReq.clear();
    }
    cout << "***The above values have also been outputted to the .txt file named 'resumeSearchResults.txt' for your convenience.***" << endl;

    outfile.close();
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
            vect.push_back(strip(word));//Removes punctuation [excluding the "+" and "#" signs]
            word="";
        }
    }
    return vect;
}

void requirementSet(string userInput, Applicant* applicant){ //Sends pointer of the Applicant obje
    counter++;
    cout << "What is requirement Number " << counter << "? ";
    getline(cin, userInput);
    cout << endl;

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
            }
            else {
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

string strip(string word){
    string tempWord;
    for(auto letter : word){
        if(!ispunct(letter) or letter=='+' or letter=='#'){
            tempWord+=letter;
        }
    }
    return tempWord;
}