# pastel-js

Pastel version compiled with Emscripten.

Repository contains third party libraries for pastel compiled with Emscripten.

Requirements:
```
cmake
emscripten
```

Build commands: 
```
mkdir build
cd build
cmake ..
make
```

Debug version with ```-g2``` emscripten level. Add cmake flag:
```
-DDEBUG=0N
```

Folder test-wasm contain tests for each library of pastel.
To build tests ```.wasm``` and ```.js``` files run ```build.sh``` for specific library.
