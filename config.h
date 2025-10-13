#define UPTIME "awk '{print int($1/3600) \" hours, \" int(($1%3600)/60) \" minutes\"}' /proc/uptime"
#define PACKAGES "echo \"$(pacman -Q | wc -l) (pacman)\""
#define DISTRO "echo \"$(grep '^NAME=' /etc/os-release | cut -d'=' -f2 | tr -d '\"')\""
#define KERNEL "cat /proc/version | cut -d' ' -f1,3"
#define CPU "grep 'model name' /proc/cpuinfo | uniq | awk -F: '{print $2}' | sed 's/^ *//'"
#define GPU "lspci | grep -i vga | awk -F: '{print $3}' | cut -d' ' -f 2,4-8"

const char *show[][2] = {
        { "host", "echo ${USER}@$(hostname)" },
        { "kernel", KERNEL },
        { "distro", DISTRO },
        { "de", "echo $XDG_CURRENT_DESKTOP" },
        { "wm", "echo $XDG_CURRENT_DESKTOP" },
        { "packages", PACKAGES },
        { "terminal", "echo $TERM" },
        { "shell", "echo $SHELL" },
        { "uptime", UPTIME },
        { "cpu", CPU },
        { "gpu", GPU },
        { "model", "cat /sys/class/dmi/id/product_name" },
        { "vendor", "cat /sys/class/dmi/id/sys_vendor" },
};
