1. `#include` — includes a file
```c
#include <stdio.h>        // standard library file
#include "my_header.h"    // your own file
```
2. `#define` — defines a constant or macro
```c
#define MAX 100
#define square(x) ((x) * (x))
```
3. `#ifdef` — if defined (conditional)
```c
#ifdef DEBUG
    printf("Debug mode\n");
#endif
4. `#ifndef` — if NOT defined (conditional)
c#ifndef FILE_NAME_H
#define FILE_NAME_H
    // code here
#endif
```
5. `#if` / `#elif` / `#else` — more complex conditionals
```c
#if VERSION == 1
    printf("Version 1\n");
#elif VERSION == 2
    printf("Version 2\n");
#else
    printf("Unknown version\n");
#endif
```
6. `#undef` — removes a definition
```c
#undef MAX     // MAX is no longer defined
```
So the pattern is: `#` + a keyword (`include`, `define`, `ifdef`, etc.) + the rest.