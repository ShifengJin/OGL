cd ThirdLibrary/assimp

mkdir build
cd build
sudo rm * -rf
cmake .. -DCMAKE_BUILD_TYPE=Release -DASSIMP_INSTALL=OFF -DASSIMP_BUILD_TESTS=OFF -DASSIMP_INJECT_DEBUG_POSTFIX=OFF -DASSIMP_BUILD_ZLIB=OFF
make -j16
cp include/assimp ../../../Assimp -rf
cp ../include/assimp/ ../../../Assimp -rf
cp ../contrib ../../../Assimp -rf
mkdir ../../../Assimp/lib
cp bin/* ../../../Assimp/lib
cd ../../../
mkdir build
cd build
cmake ..
make -j16
