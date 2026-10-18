# Machine Learning in C++

A lightweight machine-learning project written in C++. The repository is currently at an early scaffolding stage and is intended to grow into a collection of machine-learning algorithms and supporting data utilities.

## Current Contents

- `include/data.hpp` declares the `Data` class, which represents a feature vector and its label.
- `include/datahandler.hpp` declares the `data_handler` class, which is intended to load feature data and labels and divide the data into training, test, and validation sets.

The class methods are declarations only; their implementations and an executable entry point have not been added yet.

## Project Structure

```text
.
├── include/
│   ├── data.hpp
│   └── datahandler.hpp
├── src/
└── README.md
```

## Build and Run

There is not yet a build configuration (such as CMake or Make) or a runnable program in the repository. Build and run instructions will be added when those pieces are available.

## Development Status

The current focus is defining the data representation and dataset-handling interfaces. Next steps include implementing these interfaces, adding a build system, and adding tests and machine-learning algorithms.
