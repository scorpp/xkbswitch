xkbswitch
=========

CLI keyboard layout switcher for X11

### Usage

I wrote this one (using the code of [xxkb](http://sourceforge.net/projects/xxkb/)) to allow switching keyboard layouts with individual hotkeys. For example:

```bash
# assume we have two layouts configured
$ setxkbmap -layout "en, ru"
# switch to Russian first
$ xkbswitch 1
# switch to English back
$ xkbswitch 0
```
    
You could bind these to hotkeys within you window manager and every time you press the hotkey you know which layout is the current one. This also allows to use non-standard hotkeys to switch layouts.

### Examples

#### OpenBox:

```xml
<!-- Ctrl+Shift+1 switches to English -->
<keybind key="C-S-1">
  <action name="Execute">
    <command>xkbswitch 0</command>
  </action>
</keybind>
<!-- Ctrl+Shift+2 switches to Russian -->
<keybind key="C-S-2">
  <action name="Execute">
    <command>xkbswitch 1</command>
  </action>
</keybind>
```

#### Awesome

```
-- {{{ Key bindings
globalkeys = awful.util.table.join(
....
    awful.key({ "Control", "Shift" }, "1", function() os.execute("xkbswitch 0") end),
    awful.key({ "Control", "Shift" }, "2", function() os.execute("xkbswitch 1") end),
....
)
```

Or you could ensure same layout every time you run a certain program. Example for OpenBox again:
```xml
<!-- I want to have input lang set to English when unlocking my screen -->
<keybind key="W-L">
  <action name="Execute">
    <command>sh -c 'xkbswitch 0; slimlock'</command>
  </action>
</keybind>
```

### Installation

The only dependency is libX11.

    $ cc -lX11 xkbswitch.c
