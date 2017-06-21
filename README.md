# wasm-memory
This is a simple WebAssembly module which handles memory allocation in the linear memory.

## How to use it
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
