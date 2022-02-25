#ifndef DSSTRING
#define DSSTRING

#include <iostream>
#include <cstring>
#include "DSString.h"

using namespace std;

DSString::DSString(){
    data = nullptr;
    length = 0;
}

DSString::DSString(const char* myData){
    data = new char[strlen(myData) + 1];
    strcpy(data, myData);
    length = strlen(myData);
    data[length] = '\0';

}

DSString::DSString(const DSString& myString){
    data = new char[strlen(myString.data) + 1];
    strcpy(data, myString.data);
    length = strlen(myString.data);
    data[length] = '\0';
}

//destructor
DSString::~DSString(){
    delete [] data;
}

//operator =
DSString& DSString::operator=(const char* myData){
    delete [] data;
    data = new char[strlen(myData) + 1];
    strcpy(data, myData);
    length = strlen(myData);
    return *this;
}

//operator =
DSString& DSString::operator= (const DSString &myString){
    delete [] data;
    data = new char[strlen(myString.data) + 1];
    strcpy(data, myString.data);
    length = strlen(myString.data);
    return *this;
}

//operator +
DSString DSString::operator+(const DSString &myString)
{
    DSString s;
    s.data = new char[strlen(data) + strlen(myString.data) + 1];
    strcpy(s.data, data);
    strcat(s.data,myString.data);
    return s;
}

//operator ==
bool DSString::operator==(const char *myData) const {
    if(strcmp(data, myData) == 0) {
        return true;
    } else
        return false;
}

//operator ==
bool DSString::operator==(const DSString &myString) const {
    if(strcmp(data, myString.data) == 0) {
        return true;
    } else
        return false;
}


//operator >
bool DSString::operator> (const DSString& myString) const {
    return strcmp(data, myString.data) > 0;
}

bool DSString::operator<(const DSString &myString) const {
    return strcmp(data, myString.data) < 0;
}

//operator []
char& DSString::operator[] (const int index){
    return data[index];
}

//substring
DSString DSString::substring(int beg, int end){

    DSString newString;
    char* temp = new char[end - beg + 1];

    int j = 0;
    for(int i = beg; i < end+1; i++) {
        temp[j] = data[i];
        j++;
    }

    temp[j] = '\0';
    newString = temp;
    return newString;

}

//c string
char* DSString::c_str(){
    return data;
}

//return length
int DSString::getLength() {
    return strlen(data);
}

ostream& operator<< (ostream& out, const DSString& myString){
    out << myString.data;
    return out;
}

#endif