#include "gdt.h"
#include "terminal.h"
#include "system.h"

// Define entry point in asm to prevent C++ mangling
extern "C"{
    void kernel_main();
}

// The main function of the kernel
void kernel_main()
{
init_gdt(); // Initialize the Global Descriptor Table (GDT)
terminal_initialize(); // Initialize the terminal
terminal_write("Hello World!", 12); // Write the "Hello World!" message to the terminal

}
