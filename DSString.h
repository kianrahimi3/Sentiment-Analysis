//
// Created by kianr on 2/3/2021.
//

#ifndef INC_21S_PA01_DSSTRING_H
#define INC_21S_PA01_DSSTRING_H

#ifndef STRING
#define STRING

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class DSString : public basic_string<char> {

private:
    char* data;
    int length;

public:
    DSString();
    DSString(const char*);
    DSString(const DSString&);
    ~DSString();

    DSString& operator= (const char*);
    DSString& operator= (const DSString&);
    DSString operator+ (const DSString&);
    bool operator== (const char* word) const;
    bool operator== (const DSString& string) const;
    bool operator> (const DSString&) const ;
    bool operator< (const DSString&) const;
    char& operator[] (const int);

    int getLength();
    char* getData();
    DSString substring(int start, int numChars);
    char* c_str();
    friend ostream& operator<< (ostream&, const DSString&);
};

#endif
#endif //INC_21S_PA01_DSSTRING_H
