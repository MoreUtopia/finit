#include <sys/syscall.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#ifndef INIT_PATH
#define INIT_PATH "/init2"
#endif

int main() {
    puts(
        "finit - historically first init system for the Utopia kernel\n"
        "MIT-licensed, source code at https://github.com/MoreUtopia/finit\n"
    );

    char* init_path = INIT_PATH;
    puts("finit: Becoming another init executable: " INIT_PATH);

    intptr_t res = become(init_path, EXEC_ABI_LINUX, NULL, NULL);

    if (res == -1) {
        perror("finit: Error: Becoming " INIT_PATH);
        puts(
            "finit: Falling back to spawning an executable."
        );
        
        intptr_t spawn_res = spawn(init_path, EXEC_ABI_LINUX, NULL, NULL);
        
        if (spawn_res == -1) {
            perror("finit: Error: Spawning " INIT_PATH);
            puts("finit: Terminate.");
            return -1;
        }
    }

    for (;;) continue;
} 
