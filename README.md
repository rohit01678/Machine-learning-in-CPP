# Machine Learning in C++

A lightweight C++ project focused on learning the basics of machine-learning data handling and model preparation.

## Current Contents

- `include/data.hpp` defines the `Data` class for storing a feature vector, label, and enumerated label.
- `include/datahandler.hpp` declares the `data_handler` class for loading dataset files and preparing training/test/validation subsets.
- `src/data.cpp` implements the `Data` methods.
- `src/data_handler.cpp` contains the dataset handler logic and file parsing routines.
- `src/main.cpp` provides the program entry point.
- `Makefile` builds all `.cpp` files in `src/` into an executable under `build/`.

## Project Structure

```text
.
├── Makefile
├── README.md
├── include/
│   ├── data.hpp
│   └── datahandler.hpp
├── src/
│   ├── data.cpp
│   ├── data_handler.cpp
│   └── main.cpp
├── build/
│   └── generated during compilation
└── .gitignore
```

## Build and Run

From the project root, compile the project with:

```bash
g++ -std=c++17 -Wall -Wextra -Iinclude src/*.cpp -o build/ml_app
```

Then run it with:

```bash
./build/ml_app
```

## Notes

This project is still in the early scaffolding phase. The current focus is on correctly representing data, reading dataset headers, and creating the basic structure needed for future ML algorithms.
