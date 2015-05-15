#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

namespace Localization {
    //Define the structure of the file line - order of elements and data types
    #define FILE_DATA_TYPES FileValue<string, string>

    template<class A, class B>
    struct FileValue
    {
        A name;
        B value;
    };

    struct LanguageStringMissing : public exception
    {
        string s;
        LanguageStringMissing(string ss) : s(ss) {}
        ~LanguageStringMissing() throw () {}
        const char* what() const throw() {
            return s.c_str();
        }
    };

    class Localize {
    public:
        //We will open file in constructor
        Localize(const std::string filename);
        ~Localize();


        string get(string name);
    private:
        //Read the actual data from the file
        void ReadLanguage();
        void setValue(string name, string value);
        ifstream _file;
        map<string, string> mapping;
    };

};
