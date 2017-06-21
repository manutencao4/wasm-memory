# wasm-memory
This is a simple WebAssembly module which handles memory allocation in the linear memory.

### Motivation
When I started cross-compiling C++ code to WebAssembly, I realised that exchanging data between JavaScript and WASM-modules 
can get quite tricky when one does not know exactly where the modules place their internal variables inside the memory.
To prevent unwanted overwrites and resulting malfunctions, this module keeps track of the memory in use and exposes functionalities
to savely allocate memory from JavaScript. That way data (strings etc.) can be passed to the module without the fear of messing
something up.

### How to use it
As soon as the module is loaded in JavaScript via the WebAssembly JavaScript API the linear memory needs to be initialised.
```
module.exports.init();
```
From then on the exported functions malloc, realloc, free, memcpy and memset are ready to be used.
```
// allocate 10 bytes in the linear memory
var ptr = module.exports.malloc(10);

// fill the previously allocated bytes with 0xff
module.exports.memset(ptr, 0xff, 10);

// reallocate the 10 bytes in a 20 byte area
ptr = module.exports.realloc(ptr, 20);

// allocate 30 bytes in the linear memory
var ptr2 = module.exports.malloc(30);

// copy the content of ptr to ptr2
module.exports.memcpy(ptr2, ptr, 20);

// free allocated memory space
module.exports.free(ptr);
module.exports.free(ptr2);
```

### Important
This module is not aware of the total amount of memory available, so if one allocates to much this will lead to an error ...