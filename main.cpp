#include <iostream>
#include <cstring>
#include <cstdio> // Required for snprintf

// Intentional Buffer Overflow vulnerability for testing AEGIS-PATCH LLM SAST
void copyUserInput(const char* input) {
    char buffer[10];
    // Patched: Use snprintf to prevent buffer overflow and ensure null termination
    std::snprintf(buffer, sizeof(buffer), "%s", input);
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