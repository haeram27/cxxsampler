#include <chrono>
#include <iostream>
#include <sstream>

#include "gtest/gtest.h"


namespace {

/***** DO NOT REMOVE *****/
#define STARTTIME ElapsedTime et;
#define ENDTIME et.elpased();
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

class Reftypetest: public ::testing::Test {
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    Reftypetest() {
        // You can do set-up work for each test here.
        // No exception handling allowed here.
    }

    virtual ~Reftypetest() {
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

TEST_F(Reftypetest, test)
{STARTTIME

    int i = 1;
    std::clog << i << std::endl;
    std::clog << &i << std::endl;

    int& lv = i;
    std::clog << lv << std::endl;
    std::clog << &lv << std::endl;

    int&& rv = 2;
    std::clog << rv << std::endl;
    std::clog << &rv << std::endl;

    int* rp = &rv;
    std::clog << rp << std::endl;
    std::clog << *rp << std::endl;

    int* p = &i;
    std::clog << *p << std::endl;
    std::clog << p << std::endl;
    std::clog << &p << std::endl;


ENDTIME}

} ///namespace
