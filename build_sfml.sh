#!/usr/bin/env bash

wget https://github.com/SFML/SFML/archive/2.5.0.tar.gz
tar xzf 2.5.0.tar.gz
cd SFML-2.5.0

mkdir build
cd build

cmake -Wno-dev ..
sudo make install