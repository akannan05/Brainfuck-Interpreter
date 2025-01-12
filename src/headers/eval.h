#include<cstddef>
#include<string>
#include<iostream>

#ifndef EVAL_H
#define EVAL_H

int* init_brainfuck_system(size_t size);

std::string clean_bf(std::string s);

std::string iter_eval(int* arr, size_t size, std::string s);

char eval_bf(int* arr, size_t size, int idx);

#endif
