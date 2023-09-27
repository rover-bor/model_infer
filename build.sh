if [ ! -d "build" ]; then
    mkdir build && cd build
else
    rm -r build && mkdir build && cd build
fi

cmake ..
make