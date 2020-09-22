#!/bin/sh 
rm -rf ./build
rm -rf ./bin
mkdir build
mkdir bin

cd build
cmake -G "Xcode" ..
#结束
echo  "\033[31m configure endl! you need cd build && cmake .. && make && cd ../bin/ && ls  \033[0m "
