#include "../include/Localize.h"

namespace Localization {
    //Ctor
    Localize::Localize(const std::string filename)
    {
        _file.open(filename.c_str());
        ReadLanguage();
    }

    //Dtor
    Localize::~Localize()
    {
        _file.close();
    }

    //Read the data from the file
    void Localize::ReadLanguage()
    {
        std::string line;

        while(getline(_file, line)) {
            //Clear the previously set values

            FILE_DATA_TYPES parse;
            parse.name.clear();
            parse.value.clear();
            parse.name = "";
            parse.value = "";


            std::stringstream ss(line);

            //Read the first value from the line
            ss >> parse.name;
            // If the line starts with '#' or if it's an empty line, skip that line
            if (parse.name.compare(0, 1, "#") == 0 || parse.name.empty()) {
                continue;
            }
            // cout << "line : " << line << endl;
            string val;
            ostringstream oss;
            while (ss >> val) {
                oss << val << " ";
            }
            parse.value = oss.str();

            //store key,value pair
            setValue(parse.name, parse.value);
        }
    }

    string Localize::get(string name)
    {
        //Check if specific string exists
        if ( mapping.count(name) != 0) {
            return mapping[name];
        } else {
            //throw exception
            ostringstream oss;
            oss << "Exception: Language string (" << name << ") is missing";
            throw LanguageStringMissing(oss.str());
        }
    }

    void Localize::setValue(string name, string value)
    {
        mapping[name] = value;
    }

};
