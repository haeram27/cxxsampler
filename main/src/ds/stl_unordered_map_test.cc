#include <chrono>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

#include "gtest/gtest.h"

namespace {

/***** DO NOT REMOVE *****/
#define TESTBEGIN ElapsedTime et;
#define TESTEND et.elpased();
using namespace std::chrono;
class ElapsedTime {
public:
    ElapsedTime() { steadyclk_start = steady_clock::now(); }
    void elpased() {
        steadyclk_end = steady_clock::now();
        std::cout << "[**********] Elapsed time: "
            << duration_cast<microseconds>(steadyclk_end - steadyclk_start).count()
            << " us.\n";
    }

private:
    steady_clock::time_point steadyclk_start;
    steady_clock::time_point steadyclk_end;
};


/***** GLOBAL UNIT CONTEXT UNDER HERE *****/

class StlUmapTest: public ::testing::Test {
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    StlUmapTest() {
        // You can do set-up work for each test here.
        // No exception handling allowed here.
    }

    virtual ~StlUmapTest() {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    virtual void SetUp() override {
        // Code here will be called immediately after each test
        // (right before each test).
    }

    virtual void TearDown() override {
        // Code here will be called immediately after each test
        // (right before the destructor).
        // No exception handling allowed here.
    }
};


/***** TEST UNIT CONTEXT UNDER HERE *****/

TEST_F(StlUmapTest, test1)
{TESTBEGIN

    // Create an unordered_map of three strings (that map to strings)
    std::unordered_map<std::string, std::string> u = {
        {"RED","#FF0000"},
        {"GREEN","#00FF00"},
        {"BLUE","#0000FF"}
    };
 
    // Iterate and print keys and values of unordered_map
    for( const auto& n : u ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
 
    // Add two new entries to the unordered_map
    u["BLACK"] = "#000000";
    u["WHITE"] = "#FFFFFF";
 
    // Output values by key
    std::cout << "The HEX of color RED is:[" << u["RED"] << "]\n";
    std::cout << "The HEX of color BLACK is:[" << u["BLACK"] << "]\n";

TESTEND}


TEST_F(StlUmapTest, test2)
{TESTBEGIN

    // Create an unordered_map of three strings (that map to strings)
    std::unordered_map<std::string, int> u = {
        {"k", 11}, {"l", 12}, {"m", 13}, {"n", 14}, {"o", 15},
        {"f", 6}, {"g", 7}, {"h", 8}, {"i", 9}, {"j", 10},
        {"a", 1}, {"b", 2}, {"c", 3}, {"d", 4}, {"e", 5},
    };

    // Iterate and print keys and values of unordered_map
    for( const auto& n : u ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
 
    // Add two new entries to the unordered_map
    u["x"] = 16;
    u["y"] = 17;
    u["z"] = 18;

    // Output values by key
    std::cout << "Key:[x] Value:[" << u["x"] << "]\n";
    std::cout << "Key:[y] Value:[" << u["y"] << "]\n";
    std::cout << "Key:[z] Value:[" << u["z"] << "]\n";


    // Find index
    int index = std::distance(u.begin(), u.find("k"));
    std::cout << "index of u.find(k) is [" << index << "]\n";

    // Erase
    u.erase(u.find("y"));
    u.erase("z");

    // Iterate and print keys and values of unordered_map
    for( const auto& n : u ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }

TESTEND}


} ///namespace
