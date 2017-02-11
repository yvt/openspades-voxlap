Voxlap Plugin for OpenSpades
============================

**WORK IN PROGRESS**

Building
--------

This project is separated into two parts: the server and plugin.

The server must be compiled for x86 (*not* x86_64) because this version of Voxlap hasn't been ported to x86_64 yet. On the other hand, the plugin must be built for the architecture which OpenSpades was built for.

### Linux

TODO

### Windows

TODO

### Mac

```bash
# You have to update nasm to the latest version (2.x) because
# one that comes with macOS is too old (0.x) to build some 12-year-old library
sudo port install nasm

mkdir build-server; cd build-server
cmake -DCMAKE_OSX_ARCHITECTURES=i386 -DCMAKE_ASM_NASM_COMPILER=/opt/local/bin/nasm ../Server
make

cd ..

mkdir build-plugin; cd build-plugin
cmake -DCMAKE_OSX_ARCHITECTURES=x86_64 ../Plugin
make
```

License
-------

### Server

Copyright 2017 YVT, all rights reserved.

License is yet to be determined.

This work is based on [the SDL port of Voxlap by Ericson2314](https://github.com/Ericson2314/Voxlap).

Voxlap Engine non-commercial license:

1. Any derivative works based on Voxlap may be distributed as long as it is
   free of charge and through noncommercial means.

2. You must give me proper credit. This line of text is sufficient:

 > VOXLAP engine by Ken Silverman (http://advsys.net/ken)

 > Make sure it is clearly visible somewhere in your archive.

3. If you wish to release modified source code to your game, please add the
   following line to each source file changed:

   `// This file has been modified from Ken Silverman's original release`

4. I am open to commercial applications based on Voxlap, however you must
   consult with me first to acquire a commercial license. Using Voxlap as a
   test platform or as an advertisement to another commercial game is
   commercial exploitation and prohibited without a commercial license.

### Plugin (Stub)

Copyright 2017 YVT, all rights reserved.

Licensed with GPLv3.

Credits
-------

### Server

- **YVT**: interfacing code
- **Ericson2314**: SDL port of Voxlap engine
- **Ken Silverman** (http://advsys.net/ken): VOXLAP engine core



