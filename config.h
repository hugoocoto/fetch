#define UPTIME "awk '{print int($1/3600) \" hours, \" int(($1%3600)/60) \" minutes\"}' /proc/uptime"
#define PACKAGES "echo \"$(pacman -Q | wc -l) (pacman)\""
#define DISTRO "echo \"$(grep '^NAME=' /etc/os-release | cut -d'=' -f2 | tr -d '\"')\""
#define KERNEL "cat /proc/version | cut -d' ' -f1,3"
#define CPU "grep 'model name' /proc/cpuinfo | uniq | awk -F: '{print $2}' | sed 's/^ *//'"
#define GPU "lspci | grep -i vga | awk -F: '{print $3}' | cut -d' ' -f 2,4-8"
#define COLORS "for C in {40..47}; do echo -en \"[${C}m  \"; done; echo -e \"[0m\";"
#define TERM "echo $TERM | cut -d '-' -f1"

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define DEFAULT "\033[39m"
#define RESET "\033[0m"
#define BOLD "\033[1m"

#include "concat.h"

const int name_min_width = 9;
const int resp_min_width = 51;
const char *const sep = GREEN " >  " RESET;
const char *const tthing = "┏" concat65("━") "┓";
const char *const lthing = "┃ " BOLD;
const char *const rthing = "┃";
const char *const bthing = "┗" concat65("━") "┛";

const char *const show[][3] = {
        { "host", "echo ${USER}@$(hostname)" },
        { "kernel", KERNEL },
        { "distro", DISTRO },
        { "uptime", UPTIME },
        // { "de", "echo $XDG_CURRENT_DESKTOP" },
        { "wm", "echo $XDG_CURRENT_DESKTOP" },
        { "packages", PACKAGES },
        { "terminal", TERM },
        { "shell", "basename $SHELL" },
        { "uptime", UPTIME },
        { "cpu", CPU },
        { "gpu", GPU },
        { "model", "cat /sys/class/dmi/id/product_name" },
        { "vendor", "cat /sys/class/dmi/id/sys_vendor" },
        /* The third argument is the amount of chars that should not be count */
        { "colors", COLORS, (char *) ((strlen("[XXm") * 8) + strlen("[0m")) },
};
