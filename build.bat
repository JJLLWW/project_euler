rem Does vcpkg already set some similar environment variable?
set VCPKG_ROOT=C:\Users\jack\git\vcpkg

if not exist build cmake -B build . "-DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake"
cd build
cmake --build .