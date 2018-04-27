#!/bin/bash

echo $config_shell

cd /tmp
wget https://hyperrealm.github.io/libconfig/dist/libconfig-1.7.2.tar.gz

tar xvf libconfig-1.7.2.tar.gz
cd libconfig-1.7.2
./configure
make
sudo make install
