#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

void fileProcess(std::string path){
    std::ifstream file(path);
    if(!file){
        std::cout << "Error Opening File. Please Check If The Path Is Correct." << std::endl; 
        return;
    }

    std::string line;

    while(std::getline(file, line))
        std::cout << line << std::endl;

    return;
}

int main(){
    std::cout << "enter code (q to quit)" << std::endl;

    std::string s;

    while(1){
        std::getline(std::cin, s);
        
        if(s.size() >= 4){
            if(s.substr(s.size()-3, 3) == ".bf"){
                fileProcess(s);
                continue;
            }
        }
        if(s == "q" || s == "Q")
            break;

        std::cout << s << std::endl;
    }

    return 0;
}
