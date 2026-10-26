 #ifndef _DATA_HANDLER_H
#define _DATA_HANDLER_H

#include <fstream>
#include <cstdint>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include<iostream>
#include "data.hpp"

using namespace std;
class data_handler
{
    vector<Data *> data_array;
    vector<Data *> training_data;
    vector<Data *> test_data;
    vector<Data *> validation_data;

    int num_Classes;
    int features_vector_size;
    map<uint8_t, int> class_map;

    const double TRAIN_SET_PERCENT = 0.75;
    const double TEST_SET_PERCENT = 0.20;
    const double VALIDATION_PERCENT = 0.05;

    public:
    data_handler();
    ~data_handler();

    void read_feature_vector(string path);
     void read_feature_labels(string path);
     void split_data();
     void count_classes();

     uint32_t convert_to_little_endian(const unsigned char* bytes);

    vector<Data *> * get_training_data();
    vector<Data *> * get_test_data();
    vector<Data *> * get_validation_data();

};


#endif
 