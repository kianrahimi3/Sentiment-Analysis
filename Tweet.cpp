//
// Created by kianr on 1/30/2021.
//

#include "Tweet.h"

//default constructor
Tweet::Tweet(){


}


Tweet::Tweet(DSString mySentiment,DSString myId, DSString myDate, DSString myQuery, DSString myUser, DSString myTweet){
    sentiment = mySentiment;
    id = myId;
    date = myDate;
    query = myQuery;
    user = myUser;
    tweet = myTweet;

}

//return sentiment
void Tweet::setSentiment(DSString mySentiment) {
    sentiment = mySentiment;
}
//get Sentiment
DSString Tweet::getSentiment() {
    return sentiment;
}
//get ID
void Tweet::setID(DSString myID) {
    id = myID;
}
DSString Tweet::getID() {
    return id;
}
//get Date
void Tweet::setDate(DSString myDate) {
    date = myDate;
}
DSString Tweet::getDate() {
    return date;
}
//get Query
void Tweet::setQuery(DSString myQuery) {
    query = myQuery;
}
DSString Tweet::getQuery() {
    return query;
}
//get User
void Tweet::setUser(DSString myUser) {
    user = myUser;
}
DSString Tweet::getUser() {
    return user;
}
//get Tweet
void Tweet::setTweet(DSString myTweet) {
    tweet = myTweet;
}
DSString Tweet::getTweet() {
    return tweet;
}
