<div align=center>

# so_long

### 42 Common Core / circle #2
<i>This project is a small 2D game with MiniLibX. As one of the first graphic projects at 42, its objective is to familiarize students with MiniLibX, the graphical library of 42.</i>

##

### Final grade
[![abrisse's 42 so_long Score](https://badge.nimon.fr/api/v2/clw51aj8x026501rzp5ef4x2f/project/2754296)](https://github.com/Nimon77/badge42)

### Subject
English version [here](https://github.com/abrisse16/42-subjects/blob/7385a594afd19b06ab40ed62b5e8c818d2d8bd21/so_long-subject-v2.en.pdf)
<br>
French version [here](https://github.com/abrisse16/42-subjects/blob/7385a594afd19b06ab40ed62b5e8c818d2d8bd21/so_long-subject-v2.fr.pdf)

</div>

---

## The project

In this project, we have to create our own 2D game. Using the `MiniLibX` library, we will be able to create a window, display images inside it, and handle events from the keyboard to make a playable game.

### Game rules

The player's goal is to collect every collectible present on the map, and then escape through the exit. The exit is only accessible once every collectible has been collected.

Controls are the following :
- `W` : move up
- `A` : move left
- `S` : move down
- `D` : move right

Press `ESC` or click on the cross to quit the game.

### Map rules

The program must take as a first argument a map description file with the `.ber` extension.

The map must be rectangular, surrounded by walls and composed of only 5 possible characters :
- `0` : empty space
- `1` : wall
- `C` : collectible (at least one)
- `E` : exit (only one)
- `P` : player starting position (only one)

The map must contain an valid path. In my implementation, a valid path is a path that allows the player to reach the exit after collecting every collectible.

## Requirements

The following dependencies are required to compile and run the project:

- gcc
- make
- X11 include files (package xorg)
- XShm extension (package libxext-dev)
- BSD utility functions (package libbsd-dev)

On Debian or Ubuntu:

```sh
sudo apt-get update && sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

### macOS

This project uses the Linux (X11) version of MiniLibX, not the native macOS one, so X11 is provided by **XQuartz**:

```sh
xcode-select --install
brew install --cask xquartz
```

Log out and back in after installing XQuartz so that the `DISPLAY` variable is set. The Makefile detects macOS and automatically adds XQuartz's headers and libraries (`/opt/X11`). If X11 is installed elsewhere, pass its prefix with `make X11_PATH=/path/to/x11`.

Two errors point here: `'X11/Xlib.h' file not found` means the X11 headers were not found (check `X11_PATH`), and `Can't open display` means XQuartz is not running or `DISPLAY` is not set.

### MiniLibX

`mlx_linux/` is not part of this project. It is a vendored copy of [42paris/minilibx-linux](https://github.com/42paris/minilibx-linux), commit [`f07d00f`](https://github.com/42paris/minilibx-linux/commit/f07d00f07c5c652223f505b526f84dab73cf2598) (2 June 2026), used **unmodified**.

It is vendored rather than pulled in as a submodule so that `git clone && make` works from a plain clone and from a downloaded archive, with no `--recursive` to remember. To update it, replace the directory with a fresh checkout of the upstream repository and change the commit referenced above.

## Usage

Clone this repository :

```sh
git clone https://github.com/abrisse16/42-so_long.git path/to/repository
```

In your local repository, run `make`

To run `so_long`, use the following command :

```sh
./so_long <map_file.ber>
```


---
<div align=center>
	<a href="mailto:abrisse@student.42.fr">abrisse@student.42.fr</a>
</div>