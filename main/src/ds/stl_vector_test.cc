#include <chrono>
#include <iostream>
#include <vector>
#include <typeinfo>

#include "gtest/gtest.h"

using namespace std;


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


class StlVecTest: public ::testing::Test {
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    StlVecTest() {
        // You can do set-up work for each test here.
        // No exception handling allowed here.
    }

    virtual ~StlVecTest() {
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


// vector, array, deque, list, set, map, multimap, unorderedmap, stack, queue, priority_queue
TEST_F(StlVecTest, vector)
{TESTBEGIN

    std::vector<int> vi{};

    int i1 = 1;
    int i2 = 2;

    vi.push_back(i1); //copy of value
    vi.push_back(i2); //copy of value

    std::clog << vi[0] <<std::endl;
    vi[0] = 3;
    std::clog << vi[0] <<std::endl;
    std::clog << i1 <<std::endl;

TESTEND}


} ///namespace
