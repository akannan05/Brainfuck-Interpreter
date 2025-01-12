#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

#include "headers/eval.h"

void fileProcess(std::string path){
    std::ifstream file(path);
    if(!file){
        std::cout << "Error Opening File. Please Check If The Path Is Correct." << std::endl; 
        return;
    }

    int* arr = init_brainfuck_system(30000);

    std::string fullcode, line;

    while(std::getline(file, line)){
        std::string s = clean_bf(line);
        fullcode += s;
    }

    std::string output = iter_eval(arr, 30000, fullcode);
    std::cout << output << std::endl;

    delete[] arr;

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
