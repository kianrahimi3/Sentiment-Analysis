//
// Created by kianr on 2/8/2021.
//

#ifndef INC_21S_PA01_ANALYZER_H
#define INC_21S_PA01_ANALYZER_H

#include "DSString.h"
#include "Tweet.h"
#include <iostream>
#include <cstring>
#include <vector>


class Analyzer {
private:
    int posCount = 0;
    int count = 0;

    vector<DSString> posTweeters;
    vector<DSString> negTweeters;

public:
   void PrintResults(int posCount, int count);
   void Training(char* trainFile, vector<Tweet>& posTweeters, vector<Tweet>& negTweeters);
   vector<Tweet> Testing(char* testFile);
   vector<Tweet> Checking(char* checkFile);
   void Output(char* output, vector<DSString>& onesIGotWrong);
   void Go(char* train, char* test, char* check, char* output);

   vector<Tweet> CheckIfRightOrWrong(vector<Tweet> checkVector, vector<Tweet> testTweeters, vector<DSString>& onesIGotWrong);
private:
    vector<Tweet> tweetVector;
};


#endif //INC_21S_PA01_ANALYZER_H
