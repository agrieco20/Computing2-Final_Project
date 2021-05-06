/**
 * Filename: Applicant.cpp
 * Description: This is the cpp file used to initialize all of the attributes used in the Applicant Class
 */

#include "Applicant.h"

Applicant::Applicant(){

}

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