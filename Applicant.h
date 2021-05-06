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
    vector<string> reqVect;

public:
    vector<string> & copyReqVect = reqVect; //Reference Variable
    Applicant();

    void setReq(string input);

    void getReq();

};

#endif //MAIN_CPP_APPLICANT_H