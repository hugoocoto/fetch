#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"


int
main()
{
        size_t show_size = sizeof show;
        size_t show_entry_size = sizeof show[0];
        size_t entries = show_size / show_entry_size;

        size_t i;

        if (tthing) printf("%s\n", tthing);
        for (i = 0; i < entries; i++) {
                const char *name = show[i][0];
                const char *cmd = show[i][1];
                const char *comp = show[i][2];
                char buf[1024] = { 0 };
                char *c;
                FILE *f;

                f = popen(cmd, "r");

                fgets(buf, sizeof buf, f);
                if ((c = strchr(buf, '\n'))) *c = 0;

                printf("%s", lthing);
                printf("%-*s", name_min_width, name);
                printf("%s%-*s", sep, resp_min_width + comp, buf);
                printf("%s\n", rthing);
                fclose(f);
        }
        if (bthing) printf("%s\n", bthing);
}
