#include <iostream>
#include <cstring>

void copyUserInput(const char* input) {
    char buffer[10];
    // Fixed: strncpy checks bounds and prevents overflow
    std::strncpy(buffer, input, 10);
    buffer[9] = '\0'; // Ensure null-termination
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