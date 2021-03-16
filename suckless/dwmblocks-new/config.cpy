// Modify this file to change what commands output to your statusbar, and
// recompile using the make command.
static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
    {" 🐧 ", "kernel", 360, 2},
    {"", "sb-weather", 18000, 5},
    {" 📦 ", "pacupdate", 360, 9},
    {" 💻 ", "memory", 6, 1},
    //{"", "sb-volume", 0, 10},
    {" 🕑 ", "clock", 5, 0},
};

// Sets delimiter between status commands. NULL character ('\0') means no
// delimiter.
static char *delim = " ";

// Have dwmblocks automatically recompile and run when you edit this file in
// vim with the following line in your vimrc/init.vim:

// autocmd BufWritePost ~/.local/src/dwmblocks/config.h !cd
// ~/.local/src/dwmblocks/; sudo make install && { killall -q dwmblocks;setsid
// dwmblocks & }
