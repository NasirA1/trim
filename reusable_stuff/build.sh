#! /bin/bash

rm -r build test_package/build
conan create . nasir/wip
