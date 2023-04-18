#include "terminal.h"
#include <stddef.h>
#include <stdint.h>



// Terminal dimensions
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

// Terminal state variables
static size_t terminal_row;
static size_t terminal_column;
static uint16_t *terminal_buffer;

// Helper function to create a VGA entry with a character and a color
static uint16_t vga_entry(unsigned char uc, uint8_t color) {
	return (uint16_t) uc | (uint16_t) color << 8;
}
// Initialize the terminal buffer and clear the screen
void terminal_initialize(void) {
	terminal_row = 0;
	terminal_column = 0;
	terminal_buffer = (uint16_t *) 0xB8000;
// Clear the screen with spaces and the default color
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', 0x07);
		}
	}
}
// Write a string of characters to the terminal buffer
void terminal_write(const char *data, size_t size) {
	for (size_t i = 0; i < size; i++) {
		terminal_buffer[terminal_row * VGA_WIDTH + terminal_column] = vga_entry(static_cast<unsigned char>(data[i]), 0x07);
		
		// Move to the next column or wrap to the next row if necessary
		if (++terminal_column == VGA_WIDTH) {
			terminal_column = 0;
			if (++terminal_row == VGA_HEIGHT) {
				terminal_row = 0;
			}
		}
	}
}