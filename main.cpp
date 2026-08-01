#include <iostream>
#include <cstring>

void copyUserInput(const char* input) {
    char buffer[10];
    // Use strncpy to prevent buffer overflow
    std::strncpy(buffer, input, sizeof(buffer));
    // Ensure null-termination
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