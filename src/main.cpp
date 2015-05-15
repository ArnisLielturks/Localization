#include <iostream>
#include "../include/Localize.h"

using namespace std;

int main(int i, char *args[])
{
    if (args[1]) {
        ostringstream oss;
        oss << "localize_" << args[1] << ".dat";
        Localization::Localize language(oss.str());
        try {
            cout << "greeting --" << language.get("GREETING") << "--" << endl;
        } catch(Localization::LanguageStringMissing& ex) {
            cout << ex.what() << endl;
        }
        try {
            cout << "goodbye --" << language.get("GOODBYE") << "--" << endl;
        } catch(Localization::LanguageStringMissing& ex) {
            cout << ex.what() << endl;
        }
        try {
            cout << "none --" << language.get("none") << "--" << endl;
        } catch(Localization::LanguageStringMissing& ex) {
            cout << ex.what() << endl;
        }
    }

}
