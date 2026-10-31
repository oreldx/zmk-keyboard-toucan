# ZMK config for beekeeb Toucan Keyboard

[The beekeeb Toucan Keyboard](https://beekeeb.com/toucan-keyboard/) is a wireless split 42-key column‑stagger keyboard that a display and a trackpad, with an aggressive stagger on the pinky columns.

## Keymap

**Legend**

- `▽`: same key as without modifier
- `✕`: no key (`BLANK`)

### BASE

**No modifier**

|       |      |       |       |   |   |     |       |       |      |   |   |         |
|:-----:|:----:|:-----:|:-----:|:-:|:-:|:---:|:-----:|:-----:|:----:|:-:|:-:|:-------:|
| ESC   | a    | z     | e     | r | t |     | y     | u     | i    | o | p | SUPPR   |
| TAB   | q    | s     | d     | f | g |     | h     | j     | k    | l | m | !       |
| SUPER | ALTG | w     | x     | c | v |     | b     | n     | TL_2 | , | ; | :       |
|       |      |       | CTRL  | SHIFT | SPACE |     | DEL   | ENTER | ALTG |   |   |         |

**With SHIFT**

|   |   |   |   |   |   |     |   |   |   |   |   |   |
|:-:|:-:|:-:|:-:|:-:|:-:|:---:|:-:|:-:|:-:|:-:|:-:|:-:|
| ▽ | ▽ | ▽ | ▽ | ▽ | ▽ |     | ▽ | ▽ | ▽ | ▽ | ▽ | ▽ |
| ▽ | ▽ | ▽ | ▽ | ▽ | ▽ |     | ▽ | ▽ | ▽ | ▽ | ▽ | ▽ |
| ▽ | ▽ | ▽ | ▽ | ▽ | ▽ |     | ▽ | ▽ | ▽ | ? | . | / |
|   |   |   | ▽ | ▽ | ▽ |     | ▽ | ▽ | ▽ |   |   |   |

### SPEC

**No modifier**

|   |   |   |   |   |        |     |   |      |      |      |   |   |
|:-:|:-:|:-:|:-:|:-:|:------:|:---:|:-:|:----:|:----:|:----:|:-:|:-:|
| ✕ | ² | é | è | ^ | SCREEN |     | _ | VOL- | MUTE | VOL+ | ✕ | ✕ |
| ✕ | ✕ | & | " | ' | ✕      |     | - | (    | )    | =    | ✕ | ✕ |
| ✕ | ✕ | ù | ç | à | ✕      |     | $ | <    | TL_2 | *    | ✕ | ✕ |

**With SHIFT**

|   |   |   |   |   |   |     |   |   |   |   |   |   |
|:-:|:-:|:-:|:-:|:-:|:-:|:---:|:-:|:-:|:-:|:-:|:-:|:-:|
| ▽ | ▽ | ▽ | ▽ | ▽ | ▽ |     | ▽ | ▽ | ▽ | ▽ | ▽ | ▽ |
| ▽ | ▽ | ▽ | ▽ | ▽ | ▽ |     | ▽ | ▽ | ▽ | + | ▽ | ▽ |
| ▽ | ▽ | % | ▽ | ▽ | ▽ |     | ▽ | > | ▽ | ▽ | ▽ | ▽ |
|   |   |   | ▽ | ▽ | ▽ |     | ▽ | ▽ | ▽ |   |   |   |

**With ALT**

|   |   |   |         |   |   |     |     |   |   |   |   |   |
|:-:|:-:|:-:|:-------:|:-:|:-:|:---:|:---:|:-:|:-:|:-:|:-:|:-:|
| ▽ | ▽ | ▽ | `` ` `` | ▽ | ▽ |     | `\` | ▽ | ▽ | ▽ | ▽ | ▽ |
| ▽ | ▽ | ▽ | #       | { | ▽ |     | \|  | [ | ] | } | ▽ | ▽ |
| ▽ | ▽ | ▽ | ▽       | ▽ | ▽ |     | ▽   | ▽ | ▽ | ▽ | ▽ | ▽ |
|   |   |   | ▽       | ▽ | ▽ |     | ▽   | ▽ | ▽ |   |   |   |

### NUM

|   |   |   |   |   |        |     |     |      |      |       |     |   |
|:-:|:-:|:-:|:-:|:-:|:------:|:---:|:---:|:----:|:----:|:-----:|:---:|:-:|
| ✕ | ✕ | 7 | 8 | 9 | ✕      |     | F4  | HOME | UP   | END   | ✕   | ✕ |
| ✕ | 0 | 4 | 5 | 6 | KP_NUM |     | F5  | LEFT | DOWN | RIGHT | ✕   | ✕ |
| ✕ | ✕ | 1 | 2 | 3 | ✕      |     | F11 | F12  | F1   | F2    | F10 | ✕ |
|   |   |   | ✕ | ✕ | ✕      |     | ✕   | ✕    | ✕    |       |     |   |

## Display

The nice!view display runs a customised `nice_view_gem` shield ([boards/shields/nice_view_gem](boards/shields/nice_view_gem)) that shows:

- **Output status**: USB or Bluetooth, and the active Bluetooth profile
- **Battery level** of both halves (with charging indicator)
- **Bongo Cat**: an animated cat that taps with alternating paws on each key press and goes back to idle after a short pause
- **Active layer name** under the cat; layers whose name ends with `_MAC` are shown with an Apple logo instead of the suffix (e.g. `BASE_MAC` → Apple logo + `BASE`)
- **Sleep screen** when the keyboard goes to sleep

## License

The code in this repo is available under the MIT license.

The included shield nice_view_gem is modified from https://github.com/M165437/nice-view-gem licensed under the MIT License.

ZMK code snippets are taken from the ZMK documentation under the MIT license.

The embedded font QuinqueFive is designed by GGBotNet, licensed under under the SIL Open Font License, Version 1.1.
