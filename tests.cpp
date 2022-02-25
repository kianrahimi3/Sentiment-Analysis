//#define CATCH_CONFIG_MAIN
#include "catch.h"

#include <cstring>
#include "DSString.h"


TEST_CASE("String class", "[DSString]"){

    DSString s[10];
    s[0] = DSString("Kian");
    s[1] = DSString("Rahimi");
    s[2] = DSString("");
    s[3] = DSString("SMU");
    s[4] = DSString("Mustangs");
    s[5] = DSString("\n");
    s[6] = DSString("Kian");


    SECTION("Equality operators"){
        REQUIRE(s[0] == DSString("Kian"));
        REQUIRE(s[0] == s[6]);
        REQUIRE(s[2] == "");
        REQUIRE(s[1] == "Rahimi");
        REQUIRE(!(s[3] == s[4]));
    }

    SECTION("Assignment operators"){
        DSString str;
        str = "Rahimi";
        REQUIRE(str == s[1]);
        str = DSString("Kian");
        REQUIRE(str == s[0]);
        str = "";
        REQUIRE(str == s[2]);
        str = DSString("\n");
        REQUIRE(str == s[5]);
    }

    SECTION("Addition operator"){
        REQUIRE(DSString("KianRahimi") == s[0]+s[1]);
        REQUIRE(s[2] + s[2] == "");
        REQUIRE(s[5] + s[2] == DSString("\n"));
        REQUIRE(s[0] + s[1] + s[6] == "KianRahimiKian");
    }


    SECTION("Greater than operator"){
        REQUIRE(s[0] < s[1]);
        REQUIRE(s[4] < s[3]);
        REQUIRE(s[1] > s[6]);
        REQUIRE(s[3] > s[1]);
    }


    SECTION("[] Operator"){
        REQUIRE(s[0][1] == 'i');
        REQUIRE(s[4][4] == 'a');
        REQUIRE(s[6][0] == 'K');
    }


    SECTION("getLength function"){
        REQUIRE(s[0].getLength() == 4);
        REQUIRE(s[2].getLength() == 0);
        REQUIRE(s[1].getLength() == 6);
        REQUIRE(s[4].getLength() == 8);
    }


    SECTION("Substring function"){
        REQUIRE(s[0].substring(0, 3) == "Kian");
        REQUIRE(s[4].substring(1, 2) == "us");
        REQUIRE(s[4].substring(1, 3) == "ust");
    }

    SECTION("c_str function"){
        REQUIRE(strcmp(s[0].c_str(), "Kian") == 0);
        REQUIRE(strcmp(s[0].c_str(), s[6].c_str()) == 0);
        REQUIRE(strcmp(s[2].c_str(), "") == 0);
    }

}


