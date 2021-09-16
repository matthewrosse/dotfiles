# Copyright (c) 2010 Aldo Cortesi
# Copyright (c) 2010, 2014 dequis
# Copyright (c) 2012 Randall Ma
# Copyright (c) 2012-2014 Tycho Andersen
# Copyright (c) 2012 Craig Barnes
# Copyright (c) 2013 horsik
# Copyright (c) 2013 Tao Sauvage
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
import os
import re
import socket
import subprocess
from typing import List  # noqa: F401

from libqtile import bar, hook, layout, widget
from libqtile.config import Click, Drag, Group, KeyChord, Key, Match, Screen
from libqtile.lazy import lazy

mod = "mod4"
terminal = "alacritty"
browser = "brave"

keys = [
    # Switch between windows
    Key([mod], "h", lazy.layout.left(), desc="Move focus to left"),
    Key([mod], "l", lazy.layout.right(), desc="Move focus to right"),
    Key([mod], "j", lazy.layout.down(), desc="Move focus down"),
    Key([mod], "k", lazy.layout.up(), desc="Move focus up"),
    Key([mod],
        "space",
        lazy.layout.next(),
        desc="Move window focus to other window"),

    # Move windows between left/right columns or move up/down in current stack.
    # Moving out of range in Columns layout will create new column.
    Key([mod, "shift"],
        "h",
        lazy.layout.shuffle_left(),
        desc="Move window to the left"),
    Key([mod, "shift"],
        "l",
        lazy.layout.shuffle_right(),
        desc="Move window to the right"),
    Key([mod, "shift"],
        "j",
        lazy.layout.shuffle_down(),
        desc="Move window down"),
    Key([mod, "shift"], "k", lazy.layout.shuffle_up(), desc="Move window up"),

    ### Window controls
    Key([mod],
        "j",
        lazy.layout.down(),
        desc='Move focus down in current stack pane'),
    Key([mod],
        "k",
        lazy.layout.up(),
        desc='Move focus up in current stack pane'),
    Key([mod, "shift"],
        "j",
        lazy.layout.shuffle_down(),
        lazy.layout.section_down(),
        desc='Move windows down in current stack'),
    Key([mod, "shift"],
        "k",
        lazy.layout.shuffle_up(),
        lazy.layout.section_up(),
        desc='Move windows up in current stack'),
    Key([mod],
        "h",
        lazy.layout.shrink(),
        lazy.layout.decrease_nmaster(),
        desc='Shrink window (MonadTall), decrease number in master pane (Tile)'
        ),
    Key([mod],
        "l",
        lazy.layout.grow(),
        lazy.layout.increase_nmaster(),
        desc='Expand window (MonadTall), increase number in master pane (Tile)'
        ),
    Key([mod],
        "n",
        lazy.layout.normalize(),
        desc='normalize window size ratios'),
    Key([mod],
        "m",
        lazy.layout.maximize(),
        desc='toggle window between minimum and maximum sizes'),
    Key([mod, "shift"],
        "f",
        lazy.window.toggle_floating(),
        desc='toggle floating'),
    Key([mod], "f", lazy.window.toggle_fullscreen(), desc='toggle fullscreen'),

    # Toggle between split and unsplit sides of stack.
    # Split = all windows displayed
    # Unsplit = 1 window displayed, like Max layout, but still with
    # multiple stack panes
    Key([mod, "shift"],
        "Return",
        lazy.layout.toggle_split(),
        desc="Toggle between split and unsplit sides of stack"),
    Key([mod], "Return", lazy.spawn(terminal), desc="Launch terminal"),

    # Toggle between different layouts as defined below
    Key([mod], "Tab", lazy.next_layout(), desc="Toggle between layouts"),
    Key([mod, "shift"], "c", lazy.window.kill(), desc="Kill focused window"),
    Key([mod, "control"], "r", lazy.restart(), desc="Restart Qtile"),
    Key([mod, "control"], "q", lazy.shutdown(), desc="Shutdown Qtile"),
    Key([mod],
        "p",
        lazy.spawn("rofi -show drun"),
        desc="Spawn a command using a prompt widget"),
    Key([], "XF86AudioMute", lazy.spawn("pamixer -t")),
    Key([], "XF86AudioLowerVolume", lazy.spawn("pamixer -d 5")),
    Key([], "XF86AudioRaiseVolume", lazy.spawn("pamixer -i 5")),
    Key([mod, "shift"], "a", lazy.spawn("pavucontrol")),
    Key([mod], "w", lazy.spawn(browser)),

    ### Switch focus of monitors
    Key([mod], "period", lazy.next_screen(),
        desc='Move focus to next monitor'),
    Key([mod], "comma", lazy.prev_screen(), desc='Move focus to prev monitor'),

    ### Apps
    Key([mod], "e", lazy.spawn("emacs"), desc="Emacs"),
    Key([mod],
        "c",
        lazy.spawn(terminal +
                   " -e nvim /home/matthewrose/.config/qtile/config.py"),
        desc="Config file"),
    Key([mod],
        "y",
        lazy.spawn(
            "alacritty -e /home/matthewrose/.config/vifm/scripts/vifmrun"),
        desc="Vifm"),
    Key([mod, "shift"], "l", lazy.spawn("slock"), desc="Lock the screen")
]


# custom workspace names and initialization
class Groupings:
    def init_group_names(self):
        return [
            ("", {
                "layout": "monadtall"
            }),  # Terminals
            ("", {
                "layout": "monadtall"
            }),  # Web Browser
            ("", {
                "layout": "monadtall"
            }),  # File Manager
            ("", {
                "layout": "monadtall"
            }),  # Text Editor
            ("", {
                "layout": "monadtall"
            }),  # Media
            ("", {
                "layout": "monadtall"
            }),  # Music/Audio
            ("漣", {
                "layout": "monadtall"
            })
        ]  # Settings

    def init_groups(self):
        return [Group(name, **kwargs) for name, kwargs in group_names]


if __name__ in ["config", "__main__"]:
    group_names = Groupings().init_group_names()
    groups = Groupings().init_groups()

for i, (name, kwargs) in enumerate(group_names, 1):
    keys.append(Key([mod], str(i),
                    lazy.group[name].toscreen()))  # Switch to another group
    keys.append(
        Key([mod, "shift"], str(i),
            lazy.window.togroup(name)))  # Send current window to another group

layout_theme = {
    "border_width": 2,
    "margin": 4,
    "border_focus": "e1acff",
    "border_normal": "1d2330"
}

layouts = [
    #layout.Columns(**layout_theme),
    # Try more layouts by unleashing below layouts.
    #layout.Stack(num_stacks=2),
    # layout.Bsp(),
    # layout.Matrix(),
    #layout.MonadWide(**layout_theme),
    # layout.RatioTile(),
    # layout.Tile(),
    layout.MonadTall(**layout_theme, new_client_position='top'),
    layout.Max(**layout_theme),
    layout.Floating(**layout_theme),
    #layout.TreeTab(
    #    font = "Ubuntu",
    #    fontsize = 10,
    #    sections = ["FIRST", "SECOND", "THIRD", "FOURTH"],
    #    section_fontsize = 10,
    #    border_width = 2,
    #    bg_color = "1c1f24",
    #    active_bg = "c678dd",
    #    active_fb = "000000",
    #    inactive_bg = "a9a1e1",
    #    inactive_fb = "1c1f24",
    #    padding_left = 0,
    #    padding_x = 0,
    #    padding_y = 5,
    #    section_top = 10,
    #    section_bottom = 20,
    #    level_shift = 8,
    #    vspace = 3,
    #    panel_width = 200
    #    ),
    # layout.VerticalTile(),
    # layout.Zoomy(),
]

widget_defaults = dict(
    font='Source Code Pro Medium',
    fontsize=12,
    padding=5,
)
extension_defaults = widget_defaults.copy()


#COLORS
def init_colors():
    return [
        ["#3D3250", "#3D3250"],  # color 0
        ["#3D3250", "#3D3250"],  # color 1
        ["#C4C7C5", "#C4C7C5"],  # color 2
        ["#B07190", "#B07190"],  # color 3
        ["#BFBAAC", "#BFBAAC"],  # color 4
        ["#3466C2", "#3466C2"],  # color 5
        ["#E0B742", "#E0B742"],  # color 6
        ["#D56F6E", "#D56F6E"]
    ]  # color 7


colors = init_colors()


def init_widgets_list():
    widgets_list = [
        widget.Spacer(length=2, background=colors[1]),

        # Left Side of the bar

        #widget.Image(
        #    filename = "/usr/share/pixmaps/archlinux-logo.png",
        #    background = colors[1],
        #    margin = 3
        #),
        widget.Image(
            filename="~/.config/qtile/python.png",
            background=colors[1],
            margin=3,
            mouse_callbacks={
                'Button1':
                lambda: subprocess.run('sleep 3 && shutdown now', shell=True),
                'Button3':
                lambda: subprocess.run('sleep 3 && reboot', shell=True)
            },
        ),
        widget.GroupBox(font="Iosevka Nerd Font",
                        fontsize=15,
                        foreground=colors[2],
                        background=colors[1],
                        borderwidth=8,
                        highlight_method="text",
                        this_current_screen_border=colors[5],
                        active=colors[3],
                        inactive=colors[4]),
        #widget.WindowName(
        #    fontsize = 12,
        #    foreground = colors[2],
        #    background = colors[1]
        #),
        widget.Spacer(length=bar.STRETCH, background=colors[1]),

        # Center bar
        widget.Sep(linewidth=3, background=colors[1]),
        widget.TextBox(font="Iosevka Nerd Font",
                       fontsize=15,
                       text=" ",
                       foreground=colors[5],
                       background=colors[1]),
        widget.CurrentLayout(font="Source Code Pro Medium",
                             fontsize=12,
                             foreground=colors[2],
                             background=colors[1]),
        widget.Sep(linewidth=3, background=colors[1]),
        widget.TextBox(font="Iosevka Nerd Font",
                       fontsize=15,
                       text=" ﬙ ",
                       foreground=colors[6],
                       background=colors[1]),
        widget.CPU(font="Source Code Pro Medium",
                   format="{load_percent}%",
                   fontsize=12,
                   foreground=colors[2],
                   background=colors[1],
                   update_interval=2),
        widget.TextBox(font="Iosevka Nerd Font",
                       fontsize=15,
                       text=" ",
                       foreground=colors[5],
                       background=colors[1]),
        widget.Memory(font="Source Code Pro Medium",
                      format="{MemUsed:.0f}{mm}",
                      foreground=colors[2],
                      background=colors[1],
                      update_interval=2),
        widget.TextBox(font="Iosevka Nerd Font",
                       fontsize=15,
                       text=" ",
                       foreground=colors[7],
                       background=colors[1]),
        widget.HDDGraph(type='box', foreground=colors[2],
                        background=colors[1]),

        # Left Side of the bar
        widget.Spacer(length=bar.STRETCH, background=colors[1]),
        widget.Systray(background=colors[1]),
        widget.Spacer(length=10, background=colors[1]),
        widget.TextBox(font="Iosevka Nerd Font",
                       fontsize=18,
                       text="⟳ ",
                       padding=0,
                       foreground=colors[6],
                       background=colors[1]),
        widget.CheckUpdates(
            update_interval=1800,
            distro="Arch",
            display_format="{updates} updates",
            no_update_string='0 updates',
            foreground=colors[2],
            mouse_callbacks={
                'Button1':
                lambda: qtile.cmd_spawn(terminal + ' -e sudo pacman -Syu')
            },
            background=colors[1]),
        widget.TextBox(font="Iosevka Nerd Font",
                       fontsize=15,
                       text=" ",
                       foreground=colors[5],
                       background=colors[1]),
        widget.Net(format="{down}  ↓↑ {up} ",
                   foreground=colors[2],
                   background=colors[1],
                   update_interval=2),
        widget.Sep(size_percent=60, linewidth=3, background=colors[1]),
        widget.TextBox(font="Iosevka Nerd Font",
                       fontsize=15,
                       text="  ",
                       foreground=colors[7],
                       background=colors[1]),
        widget.Clock(font="Source Code Pro Medium",
                     format='%b %d-%Y',
                     fontsize=12,
                     foreground=colors[2],
                     background=colors[1]),
        widget.TextBox(font="Iosevka Nerd Font",
                       fontsize=15,
                       text=" ",
                       foreground=colors[7],
                       background=colors[1]),
        widget.Clock(font="Source Code Pro Medium",
                     format='%I:%M %p',
                     fontsize=12,
                     foreground=colors[2],
                     background=colors[1]),
        widget.Spacer(length=5, background=colors[1])
    ]
    return widgets_list


# screens/bar
def init_screens():
    return [
        Screen(top=bar.Bar(widgets=init_widgets_list(),
                           size=30,
                           opacity=0.9,
                           margin=[5, 10, 0, 10]))
    ]


screens = init_screens()

# Drag floating layouts.
mouse = [
    Drag([mod],
         "Button1",
         lazy.window.set_position_floating(),
         start=lazy.window.get_position()),
    Drag([mod],
         "Button3",
         lazy.window.set_size_floating(),
         start=lazy.window.get_size()),
    Click([mod], "Button2", lazy.window.bring_to_front())
]

dgroups_key_binder = None
dgroups_app_rules = []  # type: List
follow_mouse_focus = False
bring_front_click = False
cursor_warp = False
floating_layout = layout.Floating(float_rules=[
    # Run the utility of `xprop` to see the wm class and name of an X client.
    *layout.Floating.default_float_rules,
    Match(wm_class='confirmreset'),  # gitk
    Match(wm_class='makebranch'),  # gitk
    Match(wm_class='maketag'),  # gitk
    Match(wm_class='ssh-askpass'),  # ssh-askpass
    Match(title='branchdialog'),  # gitk
    Match(title='pinentry'),  # GPG key password entry
    Match(wm_class='pinentry-gtk-2'),
])
auto_fullscreen = True
focus_on_window_activation = "smart"
reconfigure_screens = True

# If things like steam games want to auto-minimize themselves when losing
# focus, should we respect this or not?
auto_minimize = True


@hook.subscribe.startup_once
def autostart():
    home = os.path.expanduser('~/.config/qtile/autostart.sh')
    subprocess.call([home])


# XXX: Gasp! We're lying here. In fact, nobody really uses or cares about this
# string besides java UI toolkits; you can see several discussions on the
# mailing lists, GitHub issues, and other WM documentation that suggest setting
# this string if your java app doesn't work correctly. We may as well just lie
# and say that we're a working one by default.
#
# We choose LG3D to maximize irony: it is a 3D non-reparenting WM written in
# java that happens to be on java's whitelist.
wmname = "LG3D"
