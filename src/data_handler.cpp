#include<datahandler.hpp>
using namespace std;

data_handler::data_handler() {
    data_array = vector<Data *>();
    test_data = vector<Data *>();
    training_data = vector<Data *>();
    validation_data = vector<Data *>();
}

data_handler::~data_handler() {
    //FREE dynamically Allocating STUFF
}

void data_handler::read_feature_vector(string path) {
    uint32_t header[4]; //|Magic|NUM images|Rowsize|Colsize
    unsigned char bytes[4];
    FILE *f = fopen(path.c_str(), "r");
    if (f) {
        for (int i = 0; i < 4; i++) {
            if (fread(bytes, sizeof(bytes), 1, f)) {
                header[i] = convert_to_little_endian(bytes);
            }
        }
        printf("Done getting file header!\n");

        const uint32_t image_size = header[2] * header[3];
        (void)image_size;

        for (uint32_t i = 0; i < header[1]; ++i) {
            Data *d = new Data();
            data_array.push_back(d);
        }
    }
}

void data_handler::read_feature_labels(string path) {
    (void)path;
}

void data_handler::split_data() {
}

void data_handler::count_classes() {
}

uint32_t data_handler::convert_to_little_endian(const unsigned char* bytes) {
    return static_cast<uint32_t>(bytes[0]) |
           (static_cast<uint32_t>(bytes[1]) << 8) |
           (static_cast<uint32_t>(bytes[2]) << 16) |
           (static_cast<uint32_t>(bytes[3]) << 24);
}

vector<Data *> * data_handler::get_training_data() {
    return &training_data;
}

vector<Data *> * data_handler::get_test_data() {
    return &test_data;
}

vector<Data *> * data_handler::get_validation_data() {
    return &validation_data;
}


