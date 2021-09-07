#!/bin/sh
lxsession &
picom --experimental-backends &
nitrogen --restore &
xset r rate 250 40
pa-applet &
#nm-applet &
