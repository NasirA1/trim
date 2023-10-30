 #!/bin/bash

set -x #echo on

rm -rf build
mkdir build
cd build
conan install .. -of .
cmake .. && make
