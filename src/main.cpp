#include <iostream>
#include "datahandler.hpp"
using namespace std;

int main(int argc, char *argv[]) {
    const string feature_path = argc > 1 ? argv[1] : "train-images.idx3-ubyte";
    const string label_path = argc > 2 ? argv[2] : "train-labels.idx1-ubyte";

    data_handler handler;
    handler.read_feature_vector(feature_path);
    handler.read_feature_labels(label_path);
    handler.split_data();

    return 0;
}
