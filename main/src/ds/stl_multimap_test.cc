#include <chrono>
#include <iostream>
#include <map>
#include <sstream>

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

class StlMmapTest: public ::testing::Test {
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    StlMmapTest() {
        // You can do set-up work for each test here.
        // No exception handling allowed here.
    }

    virtual ~StlMmapTest() {
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

TEST_F(StlMmapTest, multimap)
{TESTBEGIN

    std::multimap<int, std::string> mm;

    mm.insert(std::make_pair(50, "fifty"));
    mm.insert(std::make_pair(30, "thirty_two"));
    mm.insert(std::make_pair(20, "twenty"));
    mm.insert(std::make_pair(30, "thirty_three"));
    mm.insert(std::make_pair(40, "forty"));
    mm.insert(std::make_pair(30, "thirty_one"));
    mm.insert(std::make_pair(10, "ten"));

    for (auto i = mm.begin(); i != mm.end(); ++i) {
        std::cout <<  "[" << i->first << " " << i->second << "]" << std::endl;
    }
    std::cout << std::endl;

    // iterator of values in has same key 
    // from lower_bounder(begin) to from upper_bound(end)
    std::cout <<  "using bound: " << std::endl;
    auto lo_bo = mm.lower_bound(30);
    auto up_bo = mm.upper_bound(30);
    for (auto i = lo_bo; i != up_bo; ++i) {
        std::cout << i->second << " ";
    }
    std::cout << std::endl;

    // iterator of values in has same key 
    // from equal_range.first(begin) to from equal_range.second(end)
    std::cout <<  "using range: " << std::endl;
    auto eq_ra = mm.equal_range(30);
    for (auto i = eq_ra.first; i != eq_ra.second; ++i) {
        std::cout << i->second << " ";
    }
    std::cout << std::endl;

TESTEND}

} ///namespace
