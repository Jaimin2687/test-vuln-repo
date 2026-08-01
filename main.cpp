<think>
The user wants to patch a C++ code snippet vulnerable to a Buffer Overflow.
The vulnerability is in the `copyUserInput` function where `std::strcpy` is used to copy `input` into a fixed-size buffer `buffer[10]` without checking the length of `input`.

**Vulnerable Code:**
```cpp
#include <iostream>
#include <cstring>

// Intentional Buffer Overflow vulnerability for testing AEGIS-PATCH LLM SAST
void copyUserInput(const char* input) {
    char buffer[10];
    // Vulnerable: strcpy does not check bounds
    std::strcpy(buffer, input);
    std::cout << "Input copied: " << buffer << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        copyUserInput(argv[1]);
    } else {
        std::cout << "Please provide an input argument." << std::endl;
    }
    return 0;
}
```

**Fix Strategy:**
1.  Replace `std::strcpy` with a safer alternative like `std::strncpy` or `std::snprintf`.
2.  Ensure the destination buffer is null-terminated.
3.  Since the buffer size is fixed at 10, `std::strncpy(buffer, input, sizeof(buffer) - 1)` is a standard fix.
4.  Explicitly set the last byte to `\0` to ensure null termination if the input is longer than the buffer.

**Patched Code Construction:**
```cpp
#include <iostream>
#include <cstring>

// Intentional Buffer Overflow vulnerability for testing AEGIS-PATCH LLM SAST
void copyUserInput(const char* input) {
    char buffer[10];
    // Patched: Use strncpy to prevent buffer overflow
    std::strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // Ensure null termination
    std::cout << "Input copied: " << buffer << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        copyUserInput(argv[1]);
    } else {
        std::cout << "Please provide an input argument." << std::endl;
    }
    return 0;
}
```

**Constraints Check:**
- Preserve API: Yes, `copyUserInput` signature remains the same.
- No new dependencies: Yes, `<cstring>` is already included.
- Return ONLY patched source code: Yes.

**Refinement:**
The prompt asks for "ONLY the patched source code". I will output the full C++ file content.

One detail: `std::strncpy` is often preferred over `strcpy` for fixed buffers in C/C++ when bounds checking is needed, though `std::string` is the modern C++ way. However, given the context of a low-level buffer overflow fix in a C-style snippet, `strncpy` is the direct patch.

Let's verify the code structure.
Headers: `iostream`, `cstring`.
Function: `copyUserInput`.
Main: `main`.

The fix:
`std::strcpy(buffer, input);` -> `std::strncpy(buffer, input, sizeof(buffer) - 1); buffer[sizeof(buffer) - 1] = '\0';`

This looks correct.

Final check of the output format. No markdown, just code.

```cpp
#include <iostream>
#include <cstring>

// Intentional Buffer Overflow vulnerability for testing AEGIS-PATCH LLM SAST
void copyUserInput(const char* input) {
    char buffer[10];
    // Patched: Use strncpy to prevent buffer overflow
    std::strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    std::cout << "Input copied: " << buffer << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        copyUserInput(argv[1]);
    } else {
        std::cout << "Please provide an input argument." << std::endl;
    }
    return 0;
}
```
This looks good. I will provide this.
</think>

#include <iostream>
#include <cstring>

// Intentional Buffer Overflow vulnerability for testing AEGIS-PATCH LLM SAST
void copyUserInput(const char* input) {
    char buffer[10];
    // Patched: Use strncpy to prevent buffer overflow
    std::strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    std::cout << "Input copied: " << buffer << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        copyUserInput(argv[1]);
    } else {
        std::cout << "Please provide an input argument." << std::endl;
    }
    return 0;
}