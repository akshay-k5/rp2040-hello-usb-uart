#include <stdio.h>
#include "pico/stdlib.h"

// Wait up to 5 seconds for USB host before stdio init.
// Prevents the first printf() outputs from being lost over USB CDC.
#ifndef PICO_STDIO_USB_CONNECT_WAIT_TIMEOUT_MS
#define PICO_STDIO_USB_CONNECT_WAIT_TIMEOUT_MS 5000
#endif

int main(void) {
    // Initializes all enabled stdio backends (USB CDC + UART0)
    stdio_init_all();

    // Greeting shown once on startup
    printf("RP2040 echo demo ready. Type something!\n");

    while (true) {
        // Periodic heartbeat message
        printf("Hi Akshay....Hello World from RP2040!\n");

        // --- Optional enhancement: receive data from the computer ---
        // Non-blocking read: returns PICO_ERROR_TIMEOUT if no byte is waiting.
        int ch = getchar_timeout_us(0);
        if (ch != PICO_ERROR_TIMEOUT) {
            printf("Received: '%c' (0x%02X)\n", (char)ch, ch);
        }

        sleep_ms(1000);
    }

    return 0;
}
