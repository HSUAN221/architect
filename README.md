
# What Skills Do You Need to Become a Opensource  Maker for c++???
* C++ STL（Standard Template Library）\
    https://cplusplus.com/reference/stl/
* Git \
    https://git-scm.com/
* Cmake \
    https://cmake.org/
* Conan \
    https://docs.conan.io/en/latest/
* GoogleTest \
    https://google.github.io/googletest/


## What you need to prepare??

### Install conan
```console
$ pip install conan
```


## Let's start your first opensource ^^

### Use `conan install` to download all package
```console
$ conan install conanfile.txt -of build
```

### Build your cmakeFile
```console
$ cmake -S . -B build/ -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
or
$ cmake -S . -B build/ --preset=conan-release
```

### Export env variables for building
```console
$ source build/conanbuild.sh
```

### Build your project
```console
$ cmake --build build/
```

### Export env variables for running executables
```console
$ source build/conanrun.sh
```

### Run test executables
```console
$ cmake --build build/ --target test
```

### Install your open source for other users
```console
$ cmake --install build/ --prefix "build/"
```