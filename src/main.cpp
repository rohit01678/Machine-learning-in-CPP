#include <iostream>
#include "datahandler.hpp"

int main(int argc, char *argv[]) {
    const std::string feature_path = argc > 1 ? argv[1] : "train-images.idx3-ubyte";
    const std::string label_path = argc > 2 ? argv[2] : "train-labels.idx1-ubyte";

    data_handler handler;
    handler.read_feature_vector(feature_path);
    handler.read_feature_labels(label_path);
    handler.split_data();

    return 0;
}
