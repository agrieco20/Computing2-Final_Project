/**
 * Filename: Applicant.cpp
 * Description: This is the cpp file used to initialize all of the attributes used in the Applicant Class
 */

#include "Applicant.h"

Applicant::Applicant(){
//    this->appName=appName;
//    this->req1 = req1;
//    this->req2 = req2;
//    this->req3 = req3;
//    this->req4 = req4;
}

//void Applicant::setReq1(string input){
//    req1=input;
//}
//
//void Applicant::setReq2(string input){
//    req1=input;
//}
//
//void Applicant::setReq3(string input){
//    req1=input;
//}
//
//void Applicant::setReq4(string input){
//    req1=input;
//}

//void Applicant::setReq1Value(string input){
//    req1Value=stoi(input);
//}
//
//void Applicant::setReq2Value(string input){
//    req2Value=stoi(input);
//}
//
//void Applicant::setReq3Value(string input){
//    req3Value=stoi(input);
//}
//
//void Applicant::setReq4Value(string input){
//    req4Value=stoi(input);
//}

void Applicant::setReq(string input){
    reqVect.push_back(input);
}

void Applicant::getReq(){ //Was used to test to see whether the program was receiving the skill requirements it needed from the user
//    for(auto elem : reqVect){
//        cout<<elem<<endl;
//    }

//    for (int i = 0; i < reqVect.size();i++){
//        copyReqVect.push_back(reqVect[i]);
//        //cout << reqVect[i] << endl;
//    }

//    cout<<reqVect;
    for (int i = 0; i < reqVect.size();i++){
        cout << reqVect[i] << endl;
    }
}