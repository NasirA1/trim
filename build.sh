 #!/bin/bash

rm -rf build
mkdir build
cd build
conan install .. -of .
cmake ..
make
