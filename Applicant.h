/**
 * Filename: Applicant.h
 * Description: This is the header file used to declare all of the attributes used in the Applicant Class
 */

#ifndef MAIN_CPP_APPLICANT_H
#define MAIN_CPP_APPLICANT_H

#include <iostream>
#include <vector>

using namespace std;

class Applicant {
private:
//    string req1;
//    string req2;
//    string req3;
//    string req4;
    vector<string> reqVect;

//    int req1Value;
//    int req2Value;
//    int req3Value;
//    int req4Value;

public:

    vector<string> & copyReqVect = reqVect; //Reference Variable
    Applicant();

//    void setReq1(string input);
//
//    void setReq2(string input);
//
//    void setReq3(string input);
//
//    void setReq4(string input);
//
//    void setReq1Value(string input);
//
//    void setReq2Value(string input);
//
//    void setReq3Value(string input);
//
//    void setReq4Value(string input);

    void setReq(string input);

    void getReq();

};

#endif //MAIN_CPP_APPLICANT_H