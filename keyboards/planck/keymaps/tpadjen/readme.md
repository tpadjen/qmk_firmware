# tpadjen's planck layout

## Goals
  * Stay as close as possible to a standard ANSI layout
  * Prioritize mac, but stay usable for windows and linux
  * Make cursor movement and text selection/manipulation accessible from the home row

## Layers

<hr>
### QWERTY
```
,-------------------------------------------------------------------------------------------------.
| Tab   |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   | Bksp    |
|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|---------|
| Esc   |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   | Enter   |
|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|---------|
| Shift |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   | '/Shift |
|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|---------|
| Ctrl  | Alt   |  CMD  |  CMD  | Lower | Space | Arrow | Raise |  FN   | CAPS  | Alt   | Ctrl    |
`-------------------------------------------------------------------------------------------------'
```

Standard planck QWERTY, except:

  * [Enter] replaces ['/"]. Gives a closer feel to a standard keyboard, and allows [Enter] to be registered immediately.
  * ['/"] is moved down to [RShift] when tapped.
  * Mods are rearranged in left lower corner.
  * The key to the right of [Space] activates the ARROW layer for convenient cursor movment.
  * Two convenient command mods on the left

<hr>

### LOWER
```
,------------------------------------------------------------------------------------.
|   ~  |   !  |   @  |   #  |   $   |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
|------+------+------+------+-------+------+------+------+------+------+------+------|
|      |      |      |      |   +   |   \  |   =  |   [  |   ]  |   {  |   }  |   |  |
|------+------+------+------+-------+------+------+------+------+------+------+------|
|      |      |      |      |   -   |   *  |   _  |      |      |      |   \  |   `  |
|------+------+------+------+-------+------+------+------+------+------+------+------|
|      |      |      |      |*LOWER*|      |      |      | Next | Vol- | Vol+ | Play |
`------------------------------------------------------------------------------------'
```

Symbols

  * Standard symbol layout on top row.
  * Brackets on home row.
  * Math symbols in center, same as Raise.
  * Backslash and backtick placed on related base keys.

<hr>

### RAISE
```
,------------------------------------------------------------------------------------.
|   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7   |   8  |   9  |   0  | Bksp |
|------+------+------+------+------+------+------+-------+------+------+------+------|
|      |      |   ,  |   .  |   +  |   \  |   =  |   4   |   5  |   6  |   +  |  \   |
|------+------+------+------+------+------+------+-------+------+------+------+------|
|      |      |      |      |   -  |   *  |   _  |   1   |   2  |   3  |   -  |  *   |
|------+------+------+------+------+------+------+-------+------+------+------+------|
|      |      |      |      |      |      |      |*RAISE*|   0  |      |      |      |
`------------------------------------------------------------------------------------'
```

Numbers

  * Standard number layout on top row.
  * Math symbols in center.

<hr>

### ARROW
```
 ,------------------------------------------------------------------------------------------.
 | Cmd+t| Cmd+Shft+t |      |      |      |      | Pg_up | Home |  Up  | End  |      |      |
 |------+------------+------+------+------+------+-------+------+------+------+------+------|
 |      |            |      |      |      |      | Pg_dn | Left | Down |Right |  Alt |      |
 |------+------------+------+------+------+------+-------+------+------+------+------+------|
 |      |            |      |      |      |      |       |      |      |      |      |      |
 |------+------------+------+------+------+------+-------+------+------+------+------+------|
 |      |            |      |      |      |Space |*ARROW*|      |      |      |      |      |
 `------------------------------------------------------------------------------------------'
```

Navigation

  * Inverted T navigation on ijkl.
  * Other navigation keys nearby.
  * Second [ALT] to make word boundary movement easier.
  * Convenient CMD+T for new tabs, and CMD+SHFT+T for re-opening closed tabs.

<hr>

### COMMAND
```
! - Cmd is held for all transparent keys
,-------------------------------------------------------------------------------------------------.
|       |   !   |   @   |         |       |       |       |       |       |   (   |       |  Del  |
|-------+-------+-------+---------+-------+-------+-------+-------+-------+-------+-------|-------|
|  `    |       |       |         |       |       |       |       |       |       |       |       |
|-------+-------+-------+---------+-------+-------+-------+-------+-------+-------+-------|-------|
|       |       |       |         |       |       |   _   |       |       |       |       |       |
|-------+-------+-------+---------+-------+-------+-------+-------+-------+-------+-------|-------|
|       |       |       |*COMMAND*|       |       |       |       |       |       |       |       |
`-------------------------------------------------------------------------------------------------'
```

Command convenience

  * Provides a second command mod for quick access to common shortcuts.
  * Most keys pass through to the underneath layers, but with the command key held.
  * Exceptions:
    * Q, W, P, N, and Backspace are set to the same as the LOWER layer to reduce distracting mistakes, like closing windows or opening files.
    * ` is placed directly underneath tab for switching between open windows of the same app on Mac.

<hr>

### FN
```
,------------------------------------------------------------------------------------.
|      |      |      |      |      |      |      |      |       |      |      |      |
|------+------+------+------+------+------+------+------+-------+------+------+------|
|      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |       |      |      |      |
|------+------+------+------+------+------+------+------+-------+------+------+------|
|      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |AppleFn| Prev | Play | Next |
|------+------+------+------+------+------+------+------+-------+------+------+------|
|      |      |      |      |      |      |      |      | *FN*  | Mute | Vol- | Vol+ |
`------------------------------------------------------------------------------------'
```

Function keys and media actions

<hr>

### ADJUST
```
,-----------------------------------------------------------------------------------------.
|      | Reset|Debug | RGB  |RGBMOD  | HUE+ | HUE- | SAT+   | SAT- |BRGTH+|BRGTH-|  Sleep |
|------+------+------+------+--------+------+------+--------+------+------+------+--------|
|      |      |MUSmod|Aud on|Audoff  |AGnorm|AGswap|Qwerty  |      |      |      |        |
|------+------+------+------+--------+------+------+--------+------+------+------+--------|
|      |Voice-|Voice+|Mus on|Musoff  |MIDIon|MIDIof|TermOn  |TermOf|      |      |        |
|------+------+------+------+--------+------+------+--------+------+------+------+--------|
|      |      |      |      |*ADJUST*|      |      |*ADJUST*|      |      |      |        |
`-----------------------------------------------------------------------------------------'
```

Settings

  * Non-qwerty layouts from default setup removed
  * Sleep button added to top right