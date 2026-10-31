# Bongo Cat frames

One set of three frames per layer variant: `<variant>_idle.png`, `<variant>_left.png` and
`<variant>_right.png` (left/right = keyboard half of the pressed key).

Each PNG is the 144x92 band of the nice!view between the batteries and the layer name
(screen rows 30 to 121). Light pixels are lit, dark pixels are off: no grey on this screen,
use a checkerboard for shades.

After editing a PNG, regenerate the firmware images:

```sh
python3 boards/shields/nice_view_gem/assets/bongo_cat/generate.py
```

It rewrites `../bongo_cat.c`. Which layer shows which variant is set in
`layer_variants` in `widgets/bongo_cat.c`; a new variant also needs its name added to
`VARIANTS` in `generate.py` and an `extern` declaration in `widgets/bongo_cat.c`.
