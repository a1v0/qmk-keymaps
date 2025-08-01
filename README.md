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

- (Lower) F-keys and left Windows button
- (Main) QWERTY (all keys do what's written on the keycap)
- (Upper) HJKL

Future functionality/layers, to be added once I gain more experience (intermixed with to-dos):

1. separate parts of code into separate files for better readability. See: <https://www.reddit.com/r/olkb/comments/1js7ozb/bloated_keymapc/>
2. improvements to a1v0 logo (it's mostly fine but could perhaps do with a little better image quality)
3. consider adding a key binding for ctrl and shift in the home row on either side, that only activate when you hold one of SDFG or HJKL. This reduces finger movement for shift, and provides and additional ctrl key. Could also be used for alt (would need to set the keys for the HJKL layer, too). This oughtn't affect anything to do with diacritics, because none of the keys I'd use typically get diacritics (though it could impact ß if I use S)
4. number pad (ideally I'd be able to use this with some sort of num-lock key, _and_ with a hold-down layer shift). this could be achieved by double-tapping the right-hand layer shift key, which functions as a type of num lock by locking in the layer (which can be released by tapping the layer shift again, perhaps). Could this also be done in such a way as to enable Alt codes? If so, need to ensure that it doesn't cause peculiar behaviour if the actual num-lock functionality is/isn't enabled.
5. Umlauts and other non-English characters (via [Combos](https://docs.qmk.fm/features/combo))
6. right-click, regular click
7. Fn-style keys, incl. brightness, volume, play/pause/skip, perhaps on their own layer
8. caps lock, num lock
9. home, end, pg up/down
10. perhaps some sort of dedicated F5 key, since this is a fairly common on and the current F5 combination is not so good
11. hash key, backslash, vertical bar, backtick
    - backtick can be some modified version of the apostrophe
    - backlash can be some modified version of the forward slash. Ditto vertical bar?
    - alternatively, keys freed by other ideas could be used for these purposes.
12. find a nice use for other OLED screen (caps lock status, current layer)
13. perhaps create shortcuts to display certain things on screen, e.g. different pixel art
14. tapdances to lock in certain layers, using, perhaps, double-ESC to revert to main layer
15. check out these [layer ideas](https://www.reddit.com/r/MechanicalKeyboards/comments/qootbl/first_keyboard_with_layers_any_inspiration_for/) for inspiration. Here are some [best practices](https://www.reddit.com/r/KeyboardLayouts/comments/rm5ro8/layouts_layers_best_practices_inspirations_etc/)
16. just as an experiment, perhaps make a shortcut that converts some key combination into "ServiceNow", which I find awkward to type
17. potential enhancement to HJKL layer: the problem with the "JKL'" arrow keys concept is that it requires my whole hand to shift a position to the right. That's not that good (though it's also not terrible). As a future enhancement, perhaps the HJKL layer could be reached by holding down the Enter key, rather than the normal down-layer key (double-tap and hold Enter to achieve a sustained carriage return)
