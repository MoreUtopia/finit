#include <sys/syscall.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

#ifndef INIT_PATH
#define INIT_PATH "/init2"
#endif

void print_error(uintptr_t errcode) {
    uintptr_t index = errcode * (-1);

    char* error_table[] = {
        [1] = "Not implemented",
        [2] = "Invalid argument",
        [3] = "No such file or directory",
        [4] = "Filesystem node type mismatch",
        [5] = "Permission denied",
        [6] = "Buffer too small",
        [7] = "Message too large",
        [8] = "Bad executable",
        [9] = "No memory"
    };

    if (index > (sizeof(error_table) / sizeof(char*)) || !error_table[index]) {
        return puts("Unknown error");
    }

    return puts(error_table[index]);
}

int main() {
    puts(
        "finit - historically first init system for the Utopia kernel\n"
        "MIT-licensed, source code at https://github.com/MoreUtopia/finit\n"
    );

    char* init_path = INIT_PATH;
    puts("Becoming another init executable: " INIT_PATH);

    intptr_t res = __libc_syscall4(2002, (uintptr_t)init_path, 1, (uintptr_t)NULL, (uintptr_t)NULL);

    if (res < 0) {
        print_error(res);
        puts(
            "It looks like becoming another executable is not supported in the kernel.\n"
            "Falling back to spawning an executable."
        );
        
        intptr_t spawn_res = __libc_syscall4(2001, (uintptr_t)init_path, 1, (uintptr_t)NULL, (uintptr_t)NULL);
        
        if (spawn_res < 0) {
            print_error(spawn_res);
            puts("Terminate.");
            return -1;
        }
    }

    for (;;) continue;
} 
