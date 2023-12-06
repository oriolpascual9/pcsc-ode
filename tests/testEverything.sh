mkdir build 
cd build
cmake ..
make
for f in bin/*; do [ -x "$f" ] && "$f"; done

