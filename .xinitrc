#!/bin/sh

userresources=$HOME/.Xresources
usermodmap=$HOME/.Xmodmap
sysresources=/etc/X11/xinit/.Xresources
sysmodmap=/etc/X11/xinit/.Xmodmap

# merge in defaults and keymaps

if [ -f $sysresources ]; then
    xrdb -merge $sysresources
fi

if [ -f $sysmodmap ]; then
    xmodmap $sysmodmap
fi

if [ -f "$userresources" ]; then
    xrdb -merge "$userresources"
fi

if [ -f "$usermodmap" ]; then
    xmodmap "$usermodmap"
fi

# start some nice programs

if [ -d /etc/X11/xinit/xinitrc.d ] ; then
 for f in /etc/X11/xinit/xinitrc.d/?*.sh ; do
  [ -x "$f" ] && . "$f"
 done
 unset f
fi

# nitrogen --restore
[ -f ~/.xprofile ] && source ~/.xprofile
udiskie -f pcmanfm &

#while true; do
#	dwm >/dev/null 2>&1
#done
session=${1:-dwm}

case $session in
    dwm    ) exec dwm;;
    bspwm  ) exec bspwm;;
    xmonad ) exec xmonad;;
    i3     ) exec i3;;
    awesome) exec awesome;;
    *      ) exec $1;;
esac

#exec dwm
#exec i3
