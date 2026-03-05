#include <stdio.h>

void cmd_start(void)
{
    puts("Starting...");
}
void cmd_stop(void)
{
    puts("Stopping...");
}
void cmd_status(void)
{
    puts("Running.");
}

int main(void)
{
    // array of function pointers — each slot holds an action
    void (*commands[])(void) = { cmd_start, cmd_status, cmd_stop };
    const char *names[] = {"start", "status", "stop"}; // paired array for display
    int n = 3;

    for (int i = 0; i < n; i++) {
        printf("> %s: ", names[i]);
        // index into the array and call the function — no if/else needed
        commands[i]();
    }
    return 0;
}

// An array of function pointers is called a dispatch table
// Instead of if (cmd == "start") ... else if (cmd == "stop") ...
// you index directly into the array — cleaner and easier to extend.
