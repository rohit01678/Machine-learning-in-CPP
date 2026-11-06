# Machine Learning in C++

A small C++ project for loading MNIST-style IDX binary data and preparing a train, test, and validation split.

## Overview

This project provides the foundations of an MNIST classifier in C++:

- a `Data` class for storing pixel features and labels
- IDX binary-file reading for images and labels
- conversion of big-endian IDX headers to integer values
- random, non-overlapping train/test/validation splits
- an extensible `Knn` class declaration for future classification work

The executable currently loads the dataset and creates the splits. KNN prediction and accuracy evaluation are not implemented yet.

## Dataset Format

The default MNIST files included in the project are:

- `train-images.idx3-ubyte`
- `train-labels.idx1-ubyte`
- `t10k-images.idx3-ubyte`
- `t10k-labels.idx1-ubyte`

Pass custom file paths as command-line arguments when running the program.

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
├── KNN/
│   ├── include/
│   │   └── knn.hpp
│   └── src/
│       └── knn.cpp
├── train-images.idx3-ubyte
├── train-labels.idx1-ubyte
├── t10k-images.idx3-ubyte
└── t10k-labels.idx1-ubyte
```

## Set Up Your Own System

### Requirements

- A C++17-compatible compiler, such as GCC, Clang, or MSVC
- One of PowerShell, Bash, or another terminal
- The C++ source files in this repository
- Four MNIST IDX files placed in the project root if you want to run the loader

The application does not require external C++ libraries. Standard C++ headers and the compiler's runtime library are enough.

### Windows

The recommended setup is MSYS2 with the UCRT64 toolchain:

1. Install MSYS2 from `https://www.msys2.org/`.
2. Open the **MSYS2 UCRT64** terminal.
3. Install the compiler and build tools:

```powershell
pacman -Syu
pacman -S --needed mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-make
```

4. Add `C:\msys64\ucrt64\bin` to your Windows `PATH`.
5. Close and reopen VS Code so the new `PATH` is available.
6. Verify the tools in PowerShell:

```powershell
g++ --version
make --version
```

MSYS2 provides the compiler configured by the existing VS Code build task, but an existing MinGW-w64 installation can also be used if `g++` and `make` are on `PATH`.

### Linux

Install the build tools with your distribution's package manager. For Debian or Ubuntu:

```bash
sudo apt update
sudo apt install build-essential
```

Verify the installation:

```bash
g++ --version
make --version
```

### macOS

Install Apple Command Line Tools:

```bash
xcode-select --install
```

Apple Clang supports the C++17 features used by this project. Verify it with:

```bash
g++ --version
make --version
```

### Open the Project

Clone or download the repository, then open its root folder in VS Code:

```powershell
cd "C:\path\to\Machine-learning-in-CPP"
code .
```

On Linux or macOS, use the corresponding local project path. Make sure the IDX files remain in the project root or pass their full paths to the program.

## Build

Compile all source files used by the main program from the project root.

### PowerShell on Windows

```powershell
g++ -std=c++17 -Wall -Wextra -Iinclude src\main.cpp src\data.cpp src\data_handler.cpp -o app.exe
```

The VS Code build task writes the executable to `app.exe` using these sources and the `include` directory.

### Linux or macOS

```bash
g++ -std=c++17 -Wall -Wextra -Iinclude src/main.cpp src/data.cpp src/data_handler.cpp -o app
```

### Build with Make

The Makefile builds every `.cpp` file directly under `src/` and places the executable in `build/ml_app`:

```bash
make
make run
make clean
```

The Makefile does not currently compile files under `KNN/`; add those sources to the Makefile when implementing the KNN module.

## Run

Run with the default training files:

```powershell
.\app.exe
```

Or provide custom feature and label paths:

```powershell
.\app.exe ".\t10k-images.idx3-ubyte" ".\t10k-labels.idx1-ubyte"
```

The program prints the number of loaded feature vectors and labels, then reports the generated data split sizes.
## Data Split

`data_handler::split_data()` creates an approximately random split using these percentages:

- Training: 75%
- Test: 20%
- Validation: 5%

Each split uses an index set to avoid assigning the same sample more than once. The split routine currently uses `rand()` without an explicitly seeded random generator, so results may vary or remain consistent depending on runtime behavior.

## Expected Output

A successful run prints messages similar to:

```text
Done getting Input file Header!
Successfully read and stored 60000 feature vectors.
Done getting LABEL file header!
Successfully read and stored 60000 labels.
Training Data Size: 45000.
Test Data Size: 12000.
Validation Data Size: 3000.
```

The exact split sizes depend on `data_array.size()` and integer conversion in `split_data()`.

## Troubleshooting

### `g++` is not recognized

Confirm that the compiler's `bin` directory is on `PATH`, reopen the terminal, and test with:

```powershell
g++ --version
```

In VS Code, open a new terminal after changing `PATH` because existing terminals keep their old environment.

### The IDX file cannot be found

Place the files in the project root, or pass their full paths. Paths containing spaces should be quoted:

```powershell
.\app.exe "C:\Data\MNIST\train-images.idx3-ubyte" "C:\Data\MNIST\train-labels.idx1-ubyte"
```

### The executable has no output

Verify that the build command completed successfully and that `app.exe` or `app` exists in the project root. Run the executable from a terminal instead of double-clicking it so error messages remain visible.

### The Makefile output cannot be run

Run `make` first, then start `build/ml_app` on Linux or macOS. Windows Make users may use the command-line executable or configure the Makefile for their shell before using `make run`.

## Implementing KNN

The next implementation step is to connect the `Knn` class in `KNN/include/knn.hpp` to the split data.

1. In `knn.cpp`, implement constructor, destructor, training-data assignment, and prediction methods.
2. Store training, test, and validation vectors using pointers returned by `get_training_data()`, `get_test_data()`, and `get_validation_data()`.
3. Calculate Euclidean or Manhattan distance between each test feature vector and every training feature vector.
4. Sort training samples by their distance and select the nearest `k` samples.
5. Use the most common label among those neighbors as the prediction.
6. Compare predictions with actual labels across the test set and calculate accuracy.
7. Add source files under `KNN/` to the compiler command or Makefile.
8. Test small `k` values first, such as 1, 3, 5, and 7, before measuring larger values.

A basic accuracy calculation is:

```cpp
correct_predictions * 100.0 / test_data->size()
```

Before implementing, fix the current data lifecycle and use seeded random generation if reproducible splits are needed. Each split vector contains pointers to objects owned by `data_array`; the handler destructor must not delete the same objects twice.

## Current Limitations

- KNN classification has not been implemented.
- `count_classes()` is empty.
- The destructor does not free the dynamically allocated `Data` objects.
- The split uses `rand()` without a visible seed.
- No model training or accuracy evaluation is performed by the current entry point.
