#include "config.h"

#include <stdio.h>
#include <stdlib.h>

int
main()
{
        size_t show_size = sizeof show;
        size_t show_entry_size = sizeof show[0];
        size_t entries = show_size / show_entry_size;

        size_t i;
        for (i = 0; i < entries; i++) {
                const char *name = show[i][0];
                const char *cmd = show[i][1];
                FILE *f = popen(cmd, "r");
                printf("%s", lthing);
                printf("%-*s", label_min_width, name);
                printf("%s%s", sep, fgets((char[1024]) {}, 1024, f));
                fclose(f);
        }
}
