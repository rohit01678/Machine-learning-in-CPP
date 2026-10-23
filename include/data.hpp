#ifndef _DATA_H_
#define _DATA_H_

#include<vector>
#include<stdint.h>
#include<stdio.h>
using namespace std;

class Data{
vector<uint8_t> * feature_vector; //No class at End.
uint8_t label;
int enum_label;// A-> 1,B ->2

public:
void set_feature_vector(vector<uint8_t> *);
void append_to_feature_vector(uint8_t);
void set_label(uint8_t);
void set_enumerated_label(int);

int get_feature_vector_size();
uint8_t get_label();
uint8_t get_enumerated_label();

vector<uint8_t> * get_feature_vector();

};

#endif