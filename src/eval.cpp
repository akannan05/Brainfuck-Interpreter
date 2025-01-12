#include "headers/eval.h"

int* init_brainfuck_system(size_t size){
    return new int[size];
}

std::string clean_bf(std::string s){
    std::string cleaned;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '.' || s[i] == '<' || s[i] == '>' || s[i] == ',' || s[i] == '[' || s[i] == ']')
            cleaned += s[i];
    }

    return cleaned;
}

std::string iter_eval(int* arr, size_t size, std::string s){
    int idx = 0;
    std::string output;
    char c;

    for(int i = 0; i < s.size(); i++){
        switch(s[i]){
            case '.':
                c = eval_bf(arr, size, idx);
                output += c;
                break;
            case '+':
                if(arr[idx] >= 255)
                    std::cerr << "WARNING: A Memory Cell Has a Value Over 255. Ignore if this is intentional." << std::endl;
                arr[idx]++;
                break;
            case '-':
                if(arr[idx] <= 0)
                    std::cerr << "WARNING: A Memory Cell Has a Value Under 0. Ignore if this is intentional." << std::endl;
                arr[idx]--;
                break;
            case '>':
                if(idx >= size){
                    std::cerr << "Out of Bounds Memory Access." << std::endl;
                    break;
                }    
                idx++;
                break;
            case '<':
                if(idx <= 0){
                    std::cerr << "Out of Bounds Memory Access." << std::endl;
                    break;
                }
                idx--;
                break;
            case '[':
                if(arr[idx] != 0)
                    break;
                while(s[i] != ']')
                    i++;
                i++;
                break;
            case ']':
                if(arr[idx] == 0)
                    break;
                while(s[i] != '[')
                    i--;
                i++;
                break;
        }
    }

    return output;
}

char eval_bf(int* arr, size_t size, int idx){
    if(idx >= size){
        std::cerr << "Out Of Bounds Error." << std::endl;
        return '\0';
    }

    if(arr[idx] >= 255 || arr[idx] <= 0){
        std::cerr << "Invalid Byte Value." << std::endl;
        return '\0';
    }

    int byte = arr[idx];
    char ch = byte;

    return ch;
}
