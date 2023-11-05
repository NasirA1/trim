#! /bin/bash

rm -r build
mkdir build
cd build
conan install .. -of . --build missing
conan build .. -bf .

