#ifndef TERMINAL_H
#define TERMINAL_H

#include <stddef.h>
// Initializes the terminal, setting up the necessary configurations for displaying text.
void terminal_initialize(void);
// Writes a specified amount of data (text) to the terminal.
void terminal_write(const char* data, size_t size);

#endif 