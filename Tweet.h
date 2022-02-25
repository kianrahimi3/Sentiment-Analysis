//
// Created by kianr on 1/30/2021.
//

#ifndef INC_21S_PA01_TWEET_H
#define INC_21S_PA01_TWEET_H


//////change

#include <iostream>
#include <fstream>
#include <vector>
#include "DSString.h"


using namespace std;

class Tweet{
private:
    DSString sentiment;
    DSString id;
    DSString date;
    DSString query;
    DSString user;
    DSString tweet;

public:
    Tweet();
    Tweet(DSString mySentiment,DSString myId, DSString myDate, DSString myQuery, DSString myUser, DSString myTweet);
    void setSentiment(DSString mySentiment);
    DSString getSentiment();
    void setID(DSString myID);
    DSString getID();
    void setDate(DSString myDate);
    DSString getDate();
    void setQuery(DSString myQuery);
    DSString getQuery();
    void setUser(DSString myUser);
    DSString getUser();
    void setTweet(DSString myTweet);
    DSString getTweet();

};

#endif //INC_21S_PA01_TWEET_H
