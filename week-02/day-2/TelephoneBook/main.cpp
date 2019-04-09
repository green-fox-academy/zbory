#include <iostream>
#include <map>

int main() {
//Create a map with the following key-value pairs.
////Name (key)	Phone number (value)
////William A. Lathan	405-709-1865
////John K. Miller	402-247-8568
////Hortensia E. Foster	606-481-6467
////Amanda D. Newland	319-243-5613
////Brooke P. Askew	307-687-2982

    std::map<std::string, std::string> telBook = {{"William A. Lathan",   "405-709-1865"},
                                                  {"John K. Miller",      "402-247-8568"},
                                                  {"Hortensia E. Foster", "606-481-6467"},
                                                  {"Amanda D. Newland",   "319-243-5613"},
                                                  {"Brooke P. Askew",     "307-687-2982"}};

//    Create an application which solves the following problems.
//    What is John K. Miller's phone number?
    std::cout << "John K. Miller's number: " << telBook.at("John K. Miller") << std::endl;

//    Whose phone number is 307-687-2982?
    std::map<std::string, std::string>::iterator iterator;

    for(iterator = telBook.begin(); iterator != telBook.end(); iterator++){
        if(iterator->second.compare("307-687-2982") == 0){
            std::cout << iterator->first;
        }
    }
    std::cout << std::endl;
//    Do we know Chris E. Myers' phone number?
    if(telBook.count("Chris E. Myers") == 0){
        std::cout << "Chris E. Myers's number is not known! " <<  std::endl;
    }
    return 0;
}