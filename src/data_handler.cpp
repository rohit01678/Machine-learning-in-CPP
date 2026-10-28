#include "datahandler.hpp"
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
    FILE *f = fopen(path.c_str(), "rb");
    if (f) {
        for (int i = 0; i < 4; i++) {
            if (fread(bytes, sizeof(bytes), 1, f)) {
                header[i] = convert_to_little_endian(bytes);
            }
        }
        printf("Done getting Input file Header!\n");

        int image_size = header[2] * header[3];
        for (uint32_t i = 0; i < header[1]; ++i) {
            Data *d = new Data();
            uint8_t element[1];
            for (int j = 0; j < image_size; ++j) {
                if (fread(element, sizeof(element), 1, f)) {
                    d->append_to_feature_vector(element[0]);
                } else {
                    printf("Error Reading from file.\n");
                    exit(1);
                }
            }
            data_array.push_back(d);
        }
        printf("Successfully read and stored %zu feature vectors.\n", data_array.size());
        fclose(f);
    }else{
        printf("Could not find the file.\n");
        exit(1);
    }
}

void data_handler::read_feature_labels(string path) {
    uint32_t header[2]; //|Magic|NUM images
    unsigned char bytes[4];
    FILE *f = fopen(path.c_str(), "rb");
    if (f) {
        for (int i = 0; i < 2; ++i) {
            if (fread(bytes, sizeof(bytes), 1, f)) {
                header[i] = convert_to_little_endian(bytes);
            }
        }
        printf("Done getting LABEL file header!\n");

        for (uint32_t i = 0; i < header[1]; ++i) {
            uint8_t element[1];
            if (fread(element, sizeof(element), 1, f)) {
                if (i < data_array.size()) {
                    data_array.at(i)->set_label(element[0]);
                } else {
                    printf("Error: label index out of range.\n");
                    exit(1);
                }
            } else {
                printf("Error Reading from file.\n");
                exit(1);
            }
        }
        printf("Successfully read and stored %zu labels.\n", data_array.size());
        fclose(f);
    } else {
        printf("Could not find the file.\n");
        exit(1);
    }
}

void data_handler::split_data() {
    unordered_set<int> used_indexes;
    int train_size = static_cast<int>(data_array.size() * TRAIN_SET_PERCENT);
    int test_size = static_cast<int>(data_array.size() * TEST_SET_PERCENT);
    int valid_size = static_cast<int>(data_array.size() * VALIDATION_PERCENT);

    (void)test_size;
    (void)valid_size;

    int count = 0;
    while (count < train_size) {
        int rand_index = rand() % static_cast<int>(data_array.size());
        if (used_indexes.find(rand_index) == used_indexes.end()) {
            training_data.push_back(data_array.at(rand_index));
            used_indexes.insert(rand_index);
            count++;
        }
    }
    //Test Data
     count = 0;
    while (count < test_size) {
        int rand_index = rand() % static_cast<int>(data_array.size());
        if (used_indexes.find(rand_index) == used_indexes.end()) {
            test_data.push_back(data_array.at(rand_index));
            used_indexes.insert(rand_index);
            count++;
        }
    }
    //Validation Data
     count = 0;
    while (count < valid_size) {
        int rand_index = rand() % static_cast<int>(data_array.size());
        if (used_indexes.find(rand_index) == used_indexes.end()) {
            validation_data.push_back(data_array.at(rand_index));
            used_indexes.insert(rand_index);
            count++;
        }
    }
    printf("Training Data Size: %zu.\n", training_data.size());
    printf("Test Data Size: %zu.\n", test_data.size());
    printf("Validation Data Size: %zu.\n", validation_data.size());
}


void data_handler::count_classes() {
}

uint32_t data_handler::convert_to_little_endian(const unsigned char* bytes) {
    return (static_cast<uint32_t>(bytes[0]) << 24) |
           (static_cast<uint32_t>(bytes[1]) << 16) |
           (static_cast<uint32_t>(bytes[2]) << 8) |
           static_cast<uint32_t>(bytes[3]);
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


