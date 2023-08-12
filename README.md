<div align=center>

# so_long

### 42 Common Core / circle #2
<i>This project is a small 2D game with MiniLibX. As one of the first graphic projects at 42, its objective is to familiarize students with MiniLibX, the graphical library of 42.</i>

##

### Final grade
[![abrisse's 42 so_long Score](https://badge42.vercel.app/api/v2/cl1rqvecz002109l7rv0oprry/project/2754296)](https://github.com/JaeSeoKim/badge42)

### Subject
English version [here](https://cdn.intra.42.fr/pdf/pdf/90125/en.subject.pdf)
<br>
French version [here](https://cdn.intra.42.fr/pdf/pdf/90126/fr.subject.pdf)

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