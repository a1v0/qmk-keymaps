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

1. Just as an experiment, perhaps make a shortcut that converts some key combination into "ServiceNow", which I find awkward to type. E.g. "ssnn" turns into ServiceNow. This is probably a case for a macro, I assume
    - Unclear how to achieve this. A combo doesn't allow for repeated key presses, afaik, and macros can't be triggered from specific groups of key presses, either, afaik. Need to review this.
2. Umlauts and other non-English characters (via [Combos](https://docs.qmk.fm/features/combo)). The problem is that, currently, the combos require tapping of both keys in very rapid succession, rather than permitting some sort of press-and-hold logic. Is this what modifier keys are for?
3. add a mod-tap for alt, shift and ctrl on both sides of the home row that only activate when you hold one of SDFG or HJKL. This reduces finger movement for shift, and provides and additional ctrl key. Could also be used for alt (would need to set the keys for the HJKL layer, too). This oughtn't affect anything to do with diacritics, because none of the keys I'd use typically get diacritics (though it could impact ß if I use S)
4. improvements to a1v0 logo (it's mostly fine but could perhaps do with a little better image quality)
    - this is annoying because I no longer have the original images I used to generate the current byte array. Really, I'd just like to tweak a couple of pixels. Solution: figure out how the byte array works and, if straightforward enough, tweak culprit pixels (if I'm unlucky, this'll use some sort of run-length compression that'll be hard to diagnose)
5. separate parts of code into separate files for better readability. See: <https://www.reddit.com/r/olkb/comments/1js7ozb/bloated_keymapc/>
    - This doesn't actually do quite what I want. I don't really need a userspace. I'd simply like to clean up my code. I'd need, I think, to use some combination of `.c` and `.h` files to achieve this, but can't find a good guide. Will probably need to read up on how C works, more generally.
6. number pad (ideally I'd be able to use this with some sort of num-lock key, _and_ with a hold-down layer shift). this could be achieved by double-tapping the right-hand layer shift key, which functions as a type of num lock by locking in the layer (which can be released by tapping the layer shift again, perhaps). Could this also be done in such a way as to enable Alt codes? If so, need to ensure that it doesn't cause peculiar behaviour if the actual num-lock functionality is/isn't enabled.
7. right-click, regular click (while we're at it, keys to move mouse might not go totally amiss)
8. Fn-style keys, incl. brightness, volume, play/pause/skip, perhaps on their own layer
    - How does one access a layer if not for a hold-to-change-layer button? If there's a convenient way, e.g. a combo, to add some such functionality, that'd be very useful
9. caps lock, num lock, plus relevant messages show on the OLED screen
10. home, end, pg up/down
11. perhaps some sort of dedicated F5 key, since this is a fairly common on and the current F5 combination is not so good
    - ditto Alt+F4
12. hash key, backslash, vertical bar, backtick
    - backtick can be some modified version of the apostrophe (can this be done via some sort of mod-tap? Or perhaps layering is the way to go on this)
    - backslash can be some modified version of the forward slash. Ditto vertical bar?
    - alternatively, keys freed by other ideas could be used for these purposes.
13. find a nice use for other OLED screen (caps lock status, current layer)
14. check out these [layer ideas](https://www.reddit.com/r/MechanicalKeyboards/comments/qootbl/first_keyboard_with_layers_any_inspiration_for/) for inspiration. Here are some [best practices](https://www.reddit.com/r/KeyboardLayouts/comments/rm5ro8/layouts_layers_best_practices_inspirations_etc/)
15. perhaps create shortcuts to display certain things on screen, e.g. different pixel art
16. tapdances to lock in certain layers, using, perhaps, double-ESC to revert to main layer (this is only useful when I have layers of interest)
17. Consider that several keys are now obsolete, e.g. the previous layer-shift keys. These can be used for other stuff now
