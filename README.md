# Machine Learning in C++

A lightweight machine-learning project written in C++. The repository is currently in an early development stage and is intended to grow into a collection of machine-learning algorithms and data utilities.

## Current Contents

- `include/data.hpp` defines the `Data` class for storing a feature vector, label, and enum label.
- `include/datahandler.hpp` declares the `data_handler` class for loading data and splitting it into training, testing, and validation sets.
- `src/data.cpp` contains the implementation for the `Data` methods.
- `Makefile` provides a basic build target for compiling C++ source files in `src/`.

## Project Structure

```text
.
├── Makefile
├── README.md
├── include/
│   ├── data.hpp
│   └── datahandler.hpp
├── src/
│   └── data.cpp
└── build/
    └── generated during compilation
```

## Build and Run

From the project root, run:

```bash
make
make run
```

This will build any `.cpp` files found in `src/` into a program under `build/`.

## Development Status

The project is still in its early scaffolding phase. The core data representation is being implemented, and the next steps include completing the dataset handler, adding an application entry point, and expanding the machine-learning functionality.
