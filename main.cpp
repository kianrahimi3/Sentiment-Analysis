#define CATCH_CONFIG_RUNNER
#include "catch.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include "Tweet.h"
#include "DSString.h"
#include "Analyzer.h"

using namespace std;

int main(int argc, char** argv) {

    if (argc == 1)
        Catch::Session().run();

    else if (argc > 1) {
        Analyzer analyze;
        analyze.Go(argv[1], argv[2], argv[3], argv[4]);
    }
}