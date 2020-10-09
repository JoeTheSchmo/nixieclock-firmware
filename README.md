# Nixie Clock Firmware

## Requirements for Building

Install packages required for building:

### Debian / Ubuntu

```
apt-get update
apt-get install cmake make gcc-arm-none-eabi gdb-multiarch
```

## Building the Firmware

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j4
```
