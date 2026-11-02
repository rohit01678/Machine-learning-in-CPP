#ifndef __KNN_H
#define __KNN_H
using namespace std;
#include <vector>
#include "data.hpp"
class Knn {
int k;
vector<Data *> *neighbors;
vector<Data *> *training_data;
vector<Data *> *test_data;
vector<Data *> *validation_data;

public:
Knn(int);
~Knn();
};
#endif 