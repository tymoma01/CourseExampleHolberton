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
    void (*commands[])(void) = {cmd_start, cmd_stop, cmd_status}; // array of function pointers — each slot holds an action
    const char *names[]      = {"start", "stop", "status"};       // paired array for display
    int n = 3;

    for (int i = 0; i < n; i++) {
        printf("> %s: ", names[i]);
        commands[i](); // index into the array and call the function — no if/else needed
    }

    return 0;
}

// An array of function pointers is called a dispatch table.
// Instead of if (cmd == "start") ... else if (cmd == "stop") ...
// you index directly into the array — cleaner and easier to extend.
