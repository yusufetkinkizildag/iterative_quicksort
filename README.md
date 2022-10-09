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
The whole typename could have been written as a one-liner but instead, arbitrarily chosen names were used to increase readability.
These names (A, B and C) have no special meaning. 
Also, using copy with an output stream iterator is a common pattern that can be easily find on the internet.
Example links:
- [How to use std::copy for printing a user defined type](https://stackoverflow.com/questions/42106614/how-to-use-stdcopy-for-printing-a-user-defined-type)
- [std::copy, std::copy_if](https://en.cppreference.com/w/cpp/algorithm/copy)
- [output formatting with std::copy](https://mariusbancila.ro/blog/2008/04/10/output-formatting-with-stdcopy/)

```cpp
constexpr static auto quick_sort = [](auto &v) noexcept
```
The implementation is directly based on the example given in the example usage of [std::partition](https://en.cppreference.com/w/cpp/algorithm/partition) algorithm of [cppreference](https://en.cppreference.com/w) page. An iterator based stack has been used to simulate the function call stack in where the algortihm were implemented recursively. Same technique and `std` functions has been used to get the type of the iterator of the input vector as in the print_vector lambda but its a one-liner expression.

Pivot element selection is done by choosing the middle of the two iterators. The position of the pivot element's iterator is calculated by adding the half distance between two iterators to the lower iterator.
The distance between iterators returned by [std::distance](https://en.cppreference.com/w/cpp/iterator/distance) function. The [std::next](https://en.cppreference.com/w/cpp/iterator/next) function is used to properly add the calculated distance to the lower iterator.
Possible iterators to be used in the next iteration is returned from two succesive calls to [std::partition](https://en.cppreference.com/w/cpp/algorithm/partition) function. These calls partitions the array into two halves where elements that are smaller than grouped in between `low` and `middle1` iterators and the elements greater or equal than pivot elements are located between `middle2` and `high`. If iterators are not overlapping, they are pushed onto the stack to be used as new `high` and `low` iterators.

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
