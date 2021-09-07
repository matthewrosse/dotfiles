#!/bin/bash

declare options=("alacritty
zsh
i3
neovim
dwm
dwmblocks
polybar
.xinitrc
.xprofile
.scripts
quit")

permissions=""

choice=$(echo -e "${options[@]}" | dmenu -p 'Edit config file: ')

case "$choice" in
  quit)
    echo "Program terminated." && exit 1
  ;;
  alacritty)
    choice="$HOME/.config/alacritty/alacritty.yml"
  ;;
zsh)
  choice="$HOME/.zshrc"
;;
i3)
  choice="$HOME/.config/i3/config"
;;
neovim)
  choice="$HOME/.config/nvim/general/settings.vim"
;;
polybar)
  choice="$HOME/.config/polybar/config"
;;
dwm)
  choice="$HOME/dwm-matthewrosse/config.def.h"
;;
.xinitrc)
  choice="$HOME/.xinitrc"
  permissions="sudo"
;;
.xprofile)
  choice="$HOME/.xprofile"
  permissions="sudo"
;;
dwmblocks)
  choice="$HOME/Apps/suckless/dwmblocks/dwmblocks-distrotube/blocks.def.h"
;;
.scripts)
  choice="$HOME/.scripts"
;;
*)
  exit 1
;;
esac
alacritty -e $permissions nvim "$choice"
