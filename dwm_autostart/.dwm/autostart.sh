#!/bin/bash
killall -q dwmblocks | echo "Process was not running."
killall -q volumeicon | echo "Process was not running."
picom &
[ $(xrandr --listmonitors | grep "Monitors" | cut -d" " -f 2) -eq 2 ] && twomons.sh
nitrogen --restore &
dunst &
dwmblocks &
nm-applet &
volumeicon &
xautolock -time 10 -locker slock &
#slock





#killall trayer
#trayer --edge top --align right --distance 4 --widthtype request --padding 6 --SetDockType true --SetPartialStrut true --expand true --monitor 1 --transparent true --alpha 0 --tint 0x282c34  --height 17 &
