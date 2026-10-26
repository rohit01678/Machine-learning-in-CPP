# Machine Learning in C++

A lightweight C++ project for learning how to load, organize, and prepare machine-learning datasets before training a model.

## Overview

This project currently focuses on:

- representing each dataset sample as a `Data` object
- reading feature vectors and labels from binary dataset files
- preparing a basic train/test/validation split structure
- building a clean C++ project foundation for future ML algorithms

## Current Project Files

- [include/data.hpp](include/data.hpp): defines the `Data` class for feature vectors, labels, and enumerated labels.
- [include/datahandler.hpp](include/datahandler.hpp): declares the `data_handler` class for dataset loading and splitting.
- [src/data.cpp](src/data.cpp): implements `Data` methods.
- [src/data_handler.cpp](src/data_handler.cpp): handles dataset file reading and basic split logic.
- [src/main.cpp](src/main.cpp): program entry point.
- [Makefile](Makefile): builds the executable in the `build/` folder.

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

## Build

From the project root, compile with:

```powershell
cd "C:\Users\91706\OneDrive\Desktop\Project 1\Machine-learning-in-CPP"
g++ -std=c++17 -I"include" src\data.cpp src\data_handler.cpp -o app.exe
```

## Run

```powershell
.\app.exe ".\train-images.idx3-ubyte" ".\train-labels.idx1-ubyte"
```

The exact command used for this project is:

```powershell
cd "C:\Users\91706\OneDrive\Desktop\Project 1\Machine-learning-in-CPP"; g++ -std=c++17 -I"include" src\data.cpp src\data_handler.cpp -o app.exe
```

## Notes

This is still an early-stage ML project. The current code is primarily focused on dataset representation and preprocessing foundations, with the intent to extend it into model training and evaluation logic in future stages.

## Verified Status

The project currently builds successfully with the command above using the C++17 compiler configuration.
