# Testing C++ Code using GoogleTest Framework

Knowing how to write proper unittest is crucial in writing good code. C++ Testing might look overwhelming to some people especially people who are new to coding. This code snippet will help those people start writing unittests for their applications.

For an in-depth sample code and examples you can check [Google Test Sample Code](googletest/+/refs/tags/release-1.8.0/googletest/docs/Samples.md)

# Installation

**Linux/Ubuntu/Debian based**

Install dependencies
```bash
sudo apt-get install libgtest-dev
sudo apt-get install cmake
```


Build googletest
```bash
cd /usr/src/googletest/googletest
sudo mkdir build
cd build
sudo cmake ..
sudo make
sudo cp lib/libgtest* /usr/lib
cd ..
sudo rm -rf build
```

Make symlinks
```bash
sudo mkdir /usr/local/lib/googletest
sudo ln -s /usr/lib/libgtest.a /usr/local/lib/googletest
sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/googletest
```

# Execute
```bash
mkdir build
cd build
cmake ..
make
./runTests
```

**For explanation of testing refer the code**

## Visual Studio Code Extension
If you use vscode you may use this extension which shows test in vscode itself.

|  |C++ TestMate |
| ------| ------------|
| Id | matepek.vscode-catch2-test-adapter|
|Publisher | Mate Pek|

# Links
[GoogleTest github](https://github.com/google/googletest)

[Google Test Primer](https://github.com/google/googletest/blob/master/googletest/docs/primer.md)

[Setup and Install](https://gist.github.com/Cartexius/4c437c084d6e388288201aadf9c8cdd5)

[Google Test intro by IBM](https://developer.ibm.com/technologies/systems/articles/au-googletestingframework/)

[Getting started on ubuntu](https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/)

[Google Mock (I'll cover this in the future))](https://github.com/google/googletest/blob/master/googlemock/README.md)
