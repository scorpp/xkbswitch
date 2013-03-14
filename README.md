xkbswitch
=========

CLI keyboard layout switcher for X11

### Usage

I wrote this one (using the code of [xxkb] (http://sourceforge.net/projects/xxkb/)) to allow switching keyboard layouts with individual hotkeys. For example:

```bash
# assume we have to layouts configured
$ setxkbmap -layout "en, ru"
# switch to Russian first
$ xkbswitch 1
# switch to English back
$ xkbswitch 0
```
    
You could bind these to hotkeys within you window manager and every time you press the hotkey you know which layout is the current one. This also allows to use non-standard hotkeys to switch layouts.


### Installation

The only dependency is libX11.

    $ cc -lX11 xkbswitch.c
