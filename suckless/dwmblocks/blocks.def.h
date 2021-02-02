// Modify this file to change what commands output to your statusbar, and
// recompile using the make command.
static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
    {" 🐧 ", "kernel", 360, 2},

    {"", "sb-battery", 5, 3},

    {"", "sb-weather", 18000, 5},

    {" 📦 ", "pacupdate", 360, 9},

    {"", "sb-cpu", 10, 18},

    {" 💻 ", "memory", 6, 1},

    {"", "sb-volume", 0, 10},

    {" 🕑 ", "clock", 5, 0},
};

// sets delimeter between status commands. NULL character ('\0') means no
// delimeter.
static char delim = ' ';
