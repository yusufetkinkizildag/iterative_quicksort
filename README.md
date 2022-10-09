# iterative_quicksort
My iterative quicksort algorithm implementation based on the [std::partition](https://en.cppreference.com/w/cpp/algorithm/partition) example on the [cppreference](https://en.cppreference.com/w/)


## Requirements
gcc 9.4.0
More info on [compiler](#compiler)

## How to compile
```console
root@docker-desktop:/# cd /path/to/iterative_quicksort
root@docker-desktop:/iterative_quicksort# bash clean_build.sh
```

## How to run
```console
root@docker-desktop:/# cd /path/to/iterative_quicksort
root@docker-desktop:/iterative_quicksort# ./build/iterative_quicksort
```

## clean_build.sh
A trivial shell script that checks and deletes if `build` folder exists.
Calls the cmake and make to build and compile the source code

## CMakeLists.txt
A basic cmake file to specify C++ standard, build type and compile options

## iterative_quicksort.cpp
```cpp
RandomNumberGenerator(int const min, int const max) noexcept;
```
A wrapper class on [std::uniform_int_distribution](https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution) and [std::mt19937](https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine) to generate a random integer between `min` and `max`. [std::random_device](https://en.cppreference.com/w/cpp/numeric/random/random_device) is used as a random seed generator.

```cpp
constexpr static auto print_vector = [](auto const &v) noexcept
```
A constexpr lambda used to print a vector.
The vector's `value_type` must be printable.
To acquire the `value_type`; [decltype](https://en.cppreference.com/w/cpp/language/decltype), [std::remove_reference](https://en.cppreference.com/w/cpp/types/remove_reference) and [std::remove_const](https://en.cppreference.com/w/cpp/types/remove_cv) is used.

## TODO
- More detailed explanations on the `using` statements
- More detailed explanations on the algotrithm itself
- More detailed explanations on printing with the std::copy
- More detailed explanations CMakeLists.txt file
- More detailed explanations clean_build.sh file


## Compiler
```console
root@docker-desktop:/iterative_quicksort$ g++ -v
Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/9/lto-wrapper
OFFLOAD_TARGET_NAMES=nvptx-none:hsa
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 9.4.0-1ubuntu1~20.04.1' --with-bugurl=file:///usr/share/doc/gcc-9/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++,gm2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-9 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none=/build/gcc-9-Av3uEd/gcc-9-9.4.0/debian/tmp-nvptx/usr,hsa --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04.1)
```

```console
root@docker-desktop:/iterative_quicksort$ gcc -v
Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/9/lto-wrapper
OFFLOAD_TARGET_NAMES=nvptx-none:hsa
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 9.4.0-1ubuntu1~20.04.1' --with-bugurl=file:///usr/share/doc/gcc-9/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++,gm2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-9 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none=/build/gcc-9-Av3uEd/gcc-9-9.4.0/debian/tmp-nvptx/usr,hsa --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04.1)
```
