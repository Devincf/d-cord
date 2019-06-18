cd bin
./cmake.sh
sudo make install
cd ../autoban
cmake . -DCMAKE_C_COMPILER=clang-8 -DCMAKE_CXX_COMPILER=clang++ 
make
./autoban
cd ..
