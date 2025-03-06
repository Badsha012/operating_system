#include <stdio.h>
#include <time.h>
#include <unistd.h> // For sleep function

int main() {
    while (1) {
        // Get the current time
        time_t now = time(NULL);
        struct tm *local = localtime(&now);

        // Clear the console (optional, for better visual effect)
        printf("\033[H\033[J"); // ANSI escape code to clear the screen

        // Print the current time in HH:MM:SS format
        printf("Current Time: %02d:%02d:%02d\n", local->tm_hour, local->tm_min, local->tm_sec);

        // Sleep for 1 second
        sleep(1);
    }
    return 0;
}