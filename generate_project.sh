if [ ! -d "cmake-3.25.3-linux-x86_64" ]; then
	echo "Downloading cmake software"
    wget -c https://github.com/Kitware/CMake/releases/download/v3.25.3/cmake-3.25.3-linux-x86_64.tar.gz -O - | tar -xz
fi

export PATH=$PWD/cmake-3.25.3-linux-x86_64/bin:$PATH

if [ -d "$PWD/bld" ]; then
	echo "Removing old build data"
	rm -r $PWD/bld
fi

mkdir $PWD/bld

cd $PWD/bld

cmake -G "Unix Makefiles" -DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=./install -DCMAKE_BUILD_TYPE=Release ../

make -j4

make install