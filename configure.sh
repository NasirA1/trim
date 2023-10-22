#! /bin/sh

rm -rf out/build/*
cmake -DEMULATION=ON -S . -B out/build
