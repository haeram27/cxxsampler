#include <cstdlib>
#include <iostream>
#include <fstream>

// JSON header
#include "json/json.h"

// #define WINDOWS  /* uncomment this line to use it for windows.*/ 
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include "gtest/gtest.h"
#include "exam/jsoncpp_test.h"



std::string GetCurrentWorkingDir( void ) {
    char buff[FILENAME_MAX];
    GetCurrentDir( buff, FILENAME_MAX );
    std::string current_working_dir{buff};
    return current_working_dir;
}

void jsoncpp_exam() {
    std::cout << "[jsoncpp_exam]" << std::endl;

//READ Json from file
    Json::CharReaderBuilder rbuilder;

    std::ifstream ifs("./external/jsoncpp/exam/example.json");
    Json::Value iroot;  // will contains the root value after parsing.
    Json::String err;

    // read from stream
    // <example.json>
    // {
    //     "encoding" : "UTF-8",
    //     "plug-ins" : [
    //         "python",
    //         "c++",
    //         "ruby"
    //         ],
    //     "indent" : { "length" : 3, "use_space": true }
    // }

    // read from stream :: file >> stream >> parseFromStream() >> jsonvalue 
    std::cout << std::endl << ">>>> read from stream <<<<" << std::endl;
    if (ifs.is_open()) {
        if (!Json::parseFromStream(rbuilder, ifs, &iroot, &err)) {
            std::cout << "[Error] parseFromStream: " << err << std::endl;
        }
    } else {
        std::cout << "[Error] Json File NOT Found: " << GetCurrentWorkingDir() << std::endl;
    }

    std::string encoding = iroot.get("encoding", "UTF-X" ).asString();
    std::cout << "encoding: " << encoding << std::endl;
      //read "plug-ins" sub-tree
    const Json::Value plugins = iroot["plug-ins"];
    std::cout << "plug-ins : ";
      // Iterates over the sequence elements.
    for ( int index = 0; index < plugins.size(); ++index )
        std::cout << plugins[index].asString() << ", ";
    std::cout << std::endl;


    const std::string rawJson = R"({"Age": 20, "Name": "soonwoo"})";
    // read from (c)string :: (c)string >> stringstream >> jsonvalue
    std::cout << std::endl << ">>>> read from cstring by stringstream <<<<" << std::endl;
    std::stringstream {rawJson} >> iroot;
    std::cout << "rawjson: " << std::endl << iroot.toStyledString() << std::endl;

    // read from (c)string :: string >> cstring >> CharReader >> jsonvalue
    std::cout << std::endl << ">>>> read from cstring by CharReader <<<<" << std::endl;
    const int rawJsonLength = static_cast<int>(rawJson.length());
    std::unique_ptr<Json::CharReader> const reader(rbuilder.newCharReader());
    if (!reader->parse(rawJson.c_str(), rawJson.c_str() + rawJsonLength, &iroot, &err)) {
        std::cout << "[Error] reader: " << err << std::endl;
    }
    const std::string name = iroot["Name"].asString();
    const int age = iroot["Age"].asInt();
    std::cout << "name: " << name << std::endl;
    std::cout << "age: " << age << std::endl << std::endl;




// write example
// {
//     1key1 : valueAA,
//     1key2 : {
//                 2key1 : valueBA,
//                 2key2 : valueBB,
//                 2key3 : valueBC,
//             },
//     1key3 : [ valueCA, valueCB, valueCC] }
// }


// KEY can be specified as      ["key"]
// VALUE can assigned as        = "value"
// ARRAY-VALUE can be appended  [].append("array-value")
    Json::Value oroot; 
    oroot["1key1"] = "valueAA";
    oroot["1key2"]["2key1"] = "valueBA";
    oroot["1key2"]["2key2"] = "valueBB";
    oroot["1key2"]["2key3"] = "valueBC";
    oroot["1key3"].append("valueCA");
    oroot["1key3"].append("valueCA");
    oroot["1key3"].append("valueCA");

    std::cout << std::endl << "WRITE [Jason::value]" << std::endl;

    // write to stream directly
    std::cout << std::endl << ">>>> write to stream <<<<" << std::endl;
    std::cout << oroot << std::endl;

    // write to string directly
    std::cout << std::endl << ">>>> write to string <<<<" << std::endl;
    //std::cout << oroot.toStyledString() << std::endl;
    std::string styledString = oroot.toStyledString();
    std::cout << styledString << std::endl;


    // write as customized style :: using StreamWriterBuilder
    std::cout << std::endl << "[StreamWriterBuilder]";
    Json::StreamWriterBuilder wbuilder;
    //wbuilder.setDefaults();  //write builder has settings, refer Default settings
    //! [StreamWriterBuilderDefaults]
    // (*settings)["commentStyle"] = "All";
    // (*settings)["indentation"] = "\t";
    // (*settings)["enableYAMLCompatibility"] = false;
    // (*settings)["dropNullPlaceholders"] = false;
    // (*settings)["useSpecialFloats"] = false;
    // (*settings)["precision"] = 17;
    // (*settings)["precisionType"] = "significant";
    //! [StreamWriterBuilderDefaults]

    // write to stream as customized style
    wbuilder["indentation"] = "....";  // indentation default is \t
    std::cout << std::endl << ">>>> write to stream with customized style <<<<" << std::endl;
    const std::unique_ptr<Json::StreamWriter> writer(wbuilder.newStreamWriter());
    writer->write(oroot, &std::cout);


    // write to string as customized style
    wbuilder["indentation"] = ",,,,";  // indentation default is \t
    std::cout << std::endl << ">>>> write to string with customized style <<<<" << std::endl;
    const std::string json_file = Json::writeString(wbuilder, oroot);
    std::cout << json_file << std::endl;
}


/** \brief Represents a <a HREF="http://www.json.org">JSON</a> value.
 *
 * This class is a discriminated union wrapper that can represents a:
 * - signed integer [range: Value::minInt - Value::maxInt]
 * - unsigned integer (range: 0 - Value::maxUInt)
 * - double
 * - UTF-8 string
 * - boolean
 * - 'null'
 * - an ordered list of Value
 * - collection of name/value pairs (javascript object)
 *
 * The type of the held value is represented by a #ValueType and
 * can be obtained using type().
 *
 * Values of an #objectValue or #arrayValue can be accessed using operator[]()
 * methods.
 * Non-const methods will automatically create the a #nullValue element
 * if it does not exist.
 * The sequence of an #arrayValue will be automatically resized and initialized
 * with #nullValue. resize() can be used to enlarge or truncate an #arrayValue.
 *
 * The get() methods can be used to obtain default value in the case the
 * required element does not exist.
 *
 * It is possible to iterate over the list of member keys of an object using
 * the getMemberNames() method.
 
enum ValueType {
  nullValue = 0, ///< 'null' value
  intValue,      ///< signed integer value
  uintValue,     ///< unsigned integer value
  realValue,     ///< double value
  stringValue,   ///< UTF-8 string value
  booleanValue,  ///< bool value
  arrayValue,    ///< array value (ordered list)
  objectValue    ///< object value (collection of name/value pairs).
};
*/



void jsontype() {

    Json::Value tjson; 
    tjson["int"] = 1;
    tjson["uint"] = -1;
    tjson["double"] = 3.21;
    tjson["string"] = "help";
    tjson["boolean"] = false;
    tjson["array"].append(1);
    tjson["array"].append("a2");
//    tjson["obje"].append({"key","val"});
    std::cout << tjson << std::endl;

    std::cout << std::endl << ">>>> Members: " << std::endl; 
    Json::Value::Members m = tjson.getMemberNames();
    for (auto i : m) {
        std::cout << i << " isMember? " << tjson.isMember(i) << std::endl;
        std::cout << i << ":: type = " << tjson[i].type() << std::endl;
    }
}
/*
static void checkTypeAndPrint(const value &v)
{
    switch(v.type())
    {
    case Json::Value::ValueType.nullValue:
            if(v.is_double())
            printOneValue(key, v.as_double());
        else
            printOneValue(key, v.as_integer());
        break;
    case value::value_type::Boolean:
        printOneValue(key, v.as_bool());
        break;
    case value::value_type::String:
        printOneValue(key, v.as_string());
        break;
    case value::value_type::Object:
        for(auto iter : v.as_object())
        {
            const wstring &k = iter.first;
            const value &val = iter.second;
            printOne(k, val, level+1);
        }
        break;
    case value::value_type::Array:
        for(auto it : v.as_array())
        {
            printOne(key, it, level+1);
        }
        break;
    case value::value_type::Null:
    default:
        break;
    }
}
*/


class Jsoncpptest: public ::testing::Test {
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    Jsoncpptest() {
        // You can do set-up work for each test here.
        // No exception handling allowed here.
    }

    virtual ~Jsoncpptest() {
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

TEST_F(Jsoncpptest, jsoncpptest) {
    jsoncpp_exam();
}