
# What you need prepare??

### Install conan
```console
$ pip install conan
```


# Let's start your first open source >///<

### Use `conan install` to download all package
```console
$ conan install conanfile.txt -if build -pr conan-profile/Linux-X64-GCC9-Release
```

### Build your cmakeFile
```console
$ cmake -S . -B build/ -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
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