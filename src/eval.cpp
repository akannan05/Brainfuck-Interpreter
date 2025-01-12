#include "eval.h"

int* init_brainfuck_system(size_t size){
    return new int[size];
}

char eval_bf(int* arr, size_t size, int idx){
    if(idx >= size){
        std::cerr << "Out Of Bounds Error." << std::endl;
        return '\0';
    }

    if(idx >= 255 || idx <= 0){
        std::cerr << "Invalid Byte Value." << std::endl;
        return '\0';
    }

    int byte = arr[idx];
    char ch = byte;

    return ch;
}
