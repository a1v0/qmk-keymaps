# qmk-keymaps

This repo contains keymaps for my Lily58 keyboard, in the format required by [QMK](https://qmk.fm/).

| Folder    | Description |
| --------- | ----------- |
| `default` | Contains copies of un-edited keymaps that are shipped with QMK, for reference and as a baseline. |
| `a1v0`    | Contains my standard, everyday keymap. |

## Flashing instructions

First, the keymap needs to be compiled via QMK WSL. Copy the keymap file into the relevant location (e.g. `\\wsl.localhost\QMK\home\qmk\qmk_firmware\keyboards\lily58\keymaps\a1v0`).

Then, in QMK WSL, enter the `qmk_firmware` folder and run this command:

```bash
qmk compile -kb lily58 -km <keymap_name> -e CONVERT_TO=rp2040_ce
```

This creates a `.uf2` file inside the `qmk_firmware` directory.

Unplug the keyboard, separate the two halves (don't **ever** do this when the keyboard is plugged in!), then connect one half to the computer.

In Windows, open **This PC** (aka My Computer) in the file explorer. Press the `RESET` button twice in quick succession on your keyboard half. You should see a new item appear in This PC.

Paste the `.uf2` file into that item and the device will get flashed.

Disconnect and repeat for the other half of the keyboard.

At the end, disconnect, reinstate the TRRS cable between the halves, and connect back to the computer.

## a1v0

This is my default keymap.

### Layers

- (Lower) Functions and Windows buttons
- (Main) QWERTY
- (Upper) HJKL (among other things that I haven't yet customised)

Future functionality/layers, to be added once I gain more experience:

- number pad
- Umlauts and other non-English characters
- right-click, regular click
- Fn-style keys, incl. brightness, volume, play/pause/skip
- Caps lock, num lock
- Home, end, pg up/down
- Windows key (**ths is configured in the Fn layer, but the right-hand version isn't doing anything**)
- clicking shortcuts (e.g. when you tap a certain key X times, it locks in a keyboard layer)
- hash key, backslash, vertical bar, backtick
- ability to do Windows-[direction] for window snapping. This is a little awkward because it requires unusual stretching of fingers. As such, perhaps a tapdance solution might be better here, e.g. double-tapping Windows holds Windows and moves to next layer
- since certain combinations like Shift+B are awkward, experiment with a tapdance where holding Space results in Shift
- a1v0 logo to be displayed instead of Lily58
- find a nice use for other screen
- perhaps create shortcuts to display certain things on screen, e.g. different pixel art
