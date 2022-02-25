//
// Created by kianr on 2/8/2021.
//

#include "Analyzer.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>



void Analyzer::Training(char *trainFile, vector<Tweet>& posTweeters, vector<Tweet>& negTweeters) {
    ifstream myFile(trainFile);

    char header[1000];
    myFile.getline(header, 1000, '\n');

    char buffering[1000];
    vector<Tweet> tweeters;

    while (!myFile.eof()) {
        Tweet tweets;

        for (int j = 0; j < 6; j++) {
            if (j == 0) { //sentiment
                myFile.getline(buffering, 1000, ',');
                DSString temp(buffering);

                //       cout << "Sentiment = " << temp << endl;
                tweets.setSentiment(temp);
            }
            else if (j == 1) { //id
                myFile.getline(buffering, 1000, ',');
                DSString temp(buffering);

                //         cout << "ID = " << temp << endl;
                tweets.setID(temp);
            }
            else if (j == 2) { //date
                myFile.getline(buffering, 1000, ',');
                DSString temp(buffering);

                //         cout << "Date = " << temp << endl;
                tweets.setDate(temp);

            }
            else if (j == 3) { //query
                myFile.getline(buffering, 1000, ',');
                DSString temp(buffering);

                //         cout << "Query = " <<  temp << endl;
                tweets.setQuery(temp);
            }
            else if (j == 4) { //user
                myFile.getline(buffering, 1000, ',');
                DSString temp(buffering);

                //         cout << "User = " << temp << endl;
                tweets.setUser(temp);
            }
            else if (j == 5) { //message
                myFile.getline(buffering, 1000, '\n');
                DSString temp(buffering);

                //     cout << "Message = " <<  temp << endl;
                tweets.setTweet(temp);
                //    tweetsForAnalyze.push_back(temp.getData());
            }
        }
        //  tweeters.push_back(tweets);
        if(tweets.getSentiment() == "4") {
            posTweeters.push_back(tweets);
        }
        else
            negTweeters.push_back(tweets);
    }


    if (posTweeters[posTweeters.size() - 1].getTweet() == "") {
        tweeters.pop_back();
    }
    if (negTweeters[negTweeters.size() - 1].getTweet() == "") {
        negTweeters.pop_back();
    }
    myFile.close();

    //  return tweeters;
}

vector<Tweet> Analyzer::Testing(char *testFile) {
    ifstream tesFile(testFile);
    char testBuffer[1000];

    char TestFileheader[1000];
    tesFile.getline(TestFileheader, 1000, '\n');

    vector<Tweet> testTweeters;

    while (!tesFile.eof()) {
        Tweet tweets;

        for (int j = 0; j < 6; j++) {
            if (j == 0) { //sentiment
                //    tesFile.getline(testBuffer, 500, ',');
                DSString temp("0");

                //    cout << "Sentiment = " << temp << endl;
                tweets.setSentiment(temp);
            }
            else if (j == 1) { //id
                tesFile.getline(testBuffer, 1000, ',');
                DSString temp(testBuffer);

                //    cout << "ID = " << temp << endl;
                tweets.setID(temp);
            }
            else if (j == 2) { //date
                tesFile.getline(testBuffer, 1000, ',');
                DSString temp(testBuffer);

                //   cout << "Date = " << temp << endl;
                tweets.setDate(temp);

            }
            else if (j == 3) { //query
                tesFile.getline(testBuffer, 1000, ',');
                DSString temp(testBuffer);

                //    cout << "Query = " <<  temp << endl;
                tweets.setQuery(temp);
            }
            else if (j == 4) { //user
                tesFile.getline(testBuffer, 1000, ',');
                DSString temp(testBuffer);

                //    cout << "User = " << temp << endl;
                tweets.setUser(temp);
            }
            else if (j == 5) { //message
                tesFile.getline(testBuffer, 1000, '\n');
                DSString temp(testBuffer);

                //   cout << "Message = " <<  temp << endl;
                tweets.setTweet(temp);
                //    tweetsForAnalyze.push_back(temp.getData());
            }

        }
        testTweeters.push_back(tweets);
    }

    if (testTweeters[testTweeters.size() - 1].getTweet() == "") {
        testTweeters.pop_back();
    }

    tesFile.close();

    return testTweeters;
}

vector<Tweet> Analyzer::Checking(char *checkFile) {
    ifstream checking(checkFile);

    char checkBuffer[1000];
    char checkingHeaders[1000];
    checking.getline(checkingHeaders,1000,'\n');

    vector<Tweet> checkVector;


    while(!checking.eof()) {

        Tweet tweets;

        for (int j = 0; j < 2; j++) {
            if(j == 0) {
                checking.getline(checkBuffer, 1000, ',');
                tweets.setSentiment(checkBuffer);

            }
            else if(j == 1) {
                checking.getline(checkBuffer, 1000, '\n');
                tweets.setID(checkBuffer);

                tweets.setDate("N/A");
                tweets.setQuery("N/A");
                tweets.setUser("N/A");
                tweets.setTweet("N/A");
            }
        }
        checkVector.push_back(tweets);
    }

    if(strcmp(checkVector[checkVector.size() - 1].getID().c_str(), "") == 0){
        checkVector.pop_back();
    }
    checking.close();

    return checkVector;
}

vector<Tweet> Analyzer::CheckIfRightOrWrong(vector<Tweet> checkVector, vector<Tweet> testTweeters, vector<DSString>& onesIGotWrong) {
    for(int i = 0; i < checkVector.size(); i++) {
        if( (checkVector[i].getSentiment() == "0" && testTweeters[i].getSentiment() == "4")    ){
            onesIGotWrong.push_back(checkVector[i].getID().c_str());

        }
        else if( (checkVector[i].getSentiment() == "4" && testTweeters[i].getSentiment() == "0") )
            onesIGotWrong.push_back(checkVector[i].getID().c_str());
        else
            posCount++;

        count++;
    }

    return checkVector;
}

void Analyzer::Output(char *output, vector<DSString>& onesIGotWrong) {

    ////
    ///Train File Time
    ////

    ofstream fout(output);
    //fout << tweeters.size() << endl;

    // fout << "POS COUNT == " << posCount << endl;
    // fout << "COUNT == " << count << endl;

    fout << fixed << setprecision(3) << (double) posCount / count << endl;

    for(int i = 0; i < onesIGotWrong.size(); i++) {
        fout << onesIGotWrong[i] << endl;
    }
}



void Analyzer::Go(char* train, char* test, char* check, char* output) {



    ///put positive tweets in one vector
    ///put negative tweets in another vector
    vector<Tweet> posTweeters;
    vector<Tweet> negTweeters;

    ///take in train file and put in tweeters
    // Training(train);
    Training(train, posTweeters, negTweeters);


    map<DSString, int> l;
    ///tokenize negative vector and put each word in negWords vector
       vector<DSString> negWords;
    for(int i = 0; i < negTweeters.size(); i++) {
        DSString toBreak = negTweeters[i].getTweet();
        char *something = toBreak.c_str();

        char *tok = strtok(something, "- !\\\"#$%& ()*+,./:;?@[]\\\\^_`{}|~");
        while (tok != nullptr) {
            if(strlen(tok) > 2) {
                DSString tempString(tok);
                            negWords.push_back(tempString);
                //l.insert(pair<DSString, int>(tempString, 1));


                if(l.find(tempString) != l.end())
                    l.find(tempString)->second++;
                else
                    l.insert(pair<DSString, int>(tempString, 1));


            }
            tok = strtok(nullptr, "- !\\\"#$%& ()*+,./:;?@[]\\\\^_`{}|~");
        }
    }


    ///map for word frequency
    map<DSString, int> w;
    map<DSString, int>::iterator itw = w.begin();
    vector<DSString> positives;

    ///tokenize positive vector and put each word in posWords vector
    vector<DSString> posWords;
    for(int i = 0; i < posTweeters.size(); i++) {
        DSString toBreak = posTweeters[i].getTweet();
        char *something = toBreak.c_str();

        char *tok = strtok(something, "- !\\\"#$%& ()*+,./:;?@[]\\\\^_`{}|~");
        while (tok != nullptr) {
            if(strlen(tok) > 2) {
                DSString tempString(tok);
                posWords.push_back(tempString);

                if(w.find(tempString) != w.end())
                    w.find(tempString)->second++;
                else
                    w.insert(pair<DSString, int>(tempString, 1));


                //if the number of existence in positive map is greater than the negative map one...
                //add to positive vector
                if(itw->second > l.find(itw->first)->second) {
                    positives.push_back(tempString);
                }
            }
            tok = strtok(nullptr, "- !\\\"#$%& ()*+,./:;?@[]\\\\^_`{}|~");
        }
    }


    //////
    ///Test File Time
    /////

    vector<Tweet> testTweeters = Testing(test);
//cout << testTweeters.size() << endl;

    ///find if a positive word exists in the test Tweets
    ///if so....set the sentiment to positive
    for(int i = 0; i < testTweeters.size(); i++) {
        for(int j = 0; j < positives.size(); j++) {
            if(strstr(testTweeters[i].getTweet().c_str(), positives[j].c_str())) {
                //DSString positive("4");
                testTweeters[i].setSentiment("4");
                break;
            }
        }
    }

    ////
    ///Check Time
    ////

    ///sentiment checking
    vector<Tweet> checkVector = Checking(check);

    /// vector for the ones i got wrong
    vector<DSString> onesIGotWrong;
    CheckIfRightOrWrong(checkVector, testTweeters, onesIGotWrong);

    ///output results
    Output(output, onesIGotWrong);

}