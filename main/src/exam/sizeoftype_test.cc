#include <bits/stdint-intn.h>
#include <bits/stdint-uintn.h>
#include <iostream>

#include "gtest/gtest.h"

using namespace std;

void sizeoftype() {
    cout << "pointer \t: " << sizeof(char*) << " bytes" << endl;
    cout << "char \t\t: " << sizeof(char) << " bytes" << endl;
    cout << "unsigned char \t: " << sizeof(unsigned char) << " bytes" << endl;
    cout << "wchar_t \t: " << sizeof(wchar_t) << " bytes" << endl;
    cout << "bool \t\t: " << sizeof(bool) << " bytes" << endl;
    cout << "short \t\t: " << sizeof(short) << " bytes" << endl;
    cout << "unsigned short \t: " << sizeof(unsigned short) << " bytes" << endl;
    cout << "int \t\t: " << sizeof(int) << " bytes" << endl;
    cout << "unsigned int \t: " << sizeof(unsigned int) << " bytes" << endl;
    cout << "long  \t\t: " << sizeof(long) << " bytes" << endl;
    cout << "unsigned long \t: " << sizeof(unsigned long) << " bytes" << endl;
    cout << "long long  \t: " << sizeof(long long) << " bytes" << endl;
    cout << "__int8_t \t: " << sizeof(__int8_t) << " bytes" << endl;
    cout << "__int16_t \t: " << sizeof(__int16_t) << " bytes" << endl;
    cout << "__int32_t \t: " << sizeof(__int32_t) << " bytes" << endl;
    cout << "__int64_t \t: " << sizeof(__int64_t) << " bytes" << endl;
    cout << "float \t\t: " << sizeof(float) << " bytes" << endl;
    cout << "double \t\t: " << sizeof(double) << " bytes" << endl;
    cout << "long double \t: " << sizeof(long double) << " bytes" << endl;

    char c[15];
    cout << "\nchar c[15]; " << endl;
    cout << "sizeof(c) \t: " << sizeof(c) << " bytes" << endl;
    cout << "sizeof(c[0]) \t: " << sizeof(c[0]) << " bytes" << endl;
    cout << "sizeof(char) \t: " << sizeof(char) << " bytes" << endl;
    cout << "sizeof(decltype(c)) \t: " << sizeof(decltype(c)) << " bytes" << endl;
    cout << "sizeof(decltype(c[0])) \t: " << sizeof(decltype(c[0])) << " bytes" << endl;

    uint32_t i[15];
    cout << "\nuint32_t i[15]; " << endl;
    cout << "sizeof(i) \t: " << sizeof(i) << " bytes" << endl;
    cout << "sizeof(i[0]) \t: " << sizeof(i[0]) << " bytes" << endl;
    cout << "sizeof(uint32_t) \t: " << sizeof(uint32_t) << " bytes" << endl;
    cout << "sizeof(decltype(i)) \t: " << sizeof(decltype(i)) << " bytes" << endl;
    cout << "sizeof(decltype(i[0])) \t: " << sizeof(decltype(i[0])) << " bytes" << endl;
}


class SizeoftypeTest: public ::testing::Test {
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    SizeoftypeTest() {
        // You can do set-up work for each test here.
        // No exception handling allowed here.
    }

    virtual ~SizeoftypeTest() {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    virtual void SetUp() override {
        // Code here will be called immediately after each test (right
        // before each test).
    }

    virtual void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
        // No exception handling allowed here.
    }
};


TEST_F(SizeoftypeTest, sizeoftypetest) {
    sizeoftype();
}
