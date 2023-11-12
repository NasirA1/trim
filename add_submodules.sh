#! /bin/bash

mkdir external
git submodule add git@github.com:fmtlib/fmt.git external/fmt
git submodule add git@github.com:google/googletest.git external/googletest
