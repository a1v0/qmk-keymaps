# qmk-keymaps

This repo contains keymaps for my Lily58 keyboard, in the format required by [QMK](https://qmk.fm/).

| Folder | Description |
| ------ | ----------- |
| `default` | Contains copies of un-edited keymaps that are shipped with QMK, for reference and as a baseline. |
| `a1v0` | Contains my standard, everyday keymap. |

## Flashing instructions

First, the keymap needs to be compiled via QMK WSL. Run this command:

```bash
qmk compile -kb lily58 -km <keymap_name> -e CONVERT_TO=rp2040_ce
```

This creates a `.uf2` file inside the `qmk_firmware` directory.

Unplug the keyboard, separate the two halves (don't **ever** do this when the keyboard is plugged in!), then connect one half to the computer.

In Windows, open **My Computer** in the file explorer. Press the `RESET` button twice in quick succession on your keyboard half. You should see a new item appear in My Computer.

Paste the `.uf2` file into that item and the device will get flashed.

Disconnect and repeat for the other half of the keyboard.

At the end, disconnect, reinstate the TRRS cable between the halves, and connect back to the computer.

## a1v0

This is my default keymap.

### Layers

- (Lower) Functions and Windows buttons
- (Main) QWERTY

Future functionality/layers, to be added once I gain more experience:

- number pad
- Umlauts and other non-English characters
- right-click, regular click
- Fn-style keys, incl. brightness, volume, play/pause/skip
- Caps lock, num lock
- Home, end, pg up/down
- Windows key (`KC_LGUI`)
- no OLED backlighting (or, perhaps, only by keyboard activation, through a colour combo.) If any, then just white
- clicking shortcuts (e.g. when you tap a certain key X times, it locks in a keyboard layer)
- hash key, backslash, vertical bar
