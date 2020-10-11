# Nixie Clock Firmware

## Requirements

Install packages required for building and debugging.

This firmware needs a ```gcc``` and ```g++``` compiler for the
```arm-none-eabi-``` target triplet. A compatible ```gdb``` is also
required for debugging.

### Debian / Ubuntu

```
apt-get update
apt-get install cmake make gcc-arm-none-eabi gdb-multiarch
```

### J-Link

Install software for J-Link so that ```JLinkExe``` is available in ```$PATH```.

https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack

## Building the Firmware

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j4
```

## Debugging the Firmware

In a separate terminal window, start ```JLinkGDBServer```:

```
JLinkGDBServer -device AT91SAM3U4E
```

Then from the ```build``` directory, start debugging:

```
make debug
```
