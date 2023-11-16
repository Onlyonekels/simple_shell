#include "shell.h"

int main(void) {
    while (1) {
        char *command = get_command();
        if (!command) {
            printf("\n");
            break;  /* End of file condition (Ctrl+D) */
        }

        exec_cmd(command);
        free(command);
    }

    return 0;
}

