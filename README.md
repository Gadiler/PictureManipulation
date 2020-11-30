# Picture Manipulation and 15-Puzzle
### Gadi Engelsman
### Course: C

## Introduction:
### 15-Puzzle:
	|1   |2   |3   |4  |
	|6   |5   |8   |7  |
	|9   |10  |11  |13 |
	|12  |14  |15  |X  |

The 15-puzzle is a sliding puzzle that consists of a frame of numbered square tiles in random order with one tile missing. 
The puzzle also exists in other sizes, particularly the smaller 8-puzzle. If the size is 3×3 tiles, the puzzle is called the 8-puzzle or 9-puzzle, 
and if 4×4 tiles, the puzzle is called the 15-puzzle or 16-puzzle named, respectively, for the number of tiles and the number of spaces. 
The object of the puzzle is to place the tiles in order by making sliding moves that use the empty space.

### Picture Manipulation:
#### Clockwise exemple:	
		|1|2|3|      |7|4|1|
		|4|5|6|  ->  |8|5|2|
		|7|8|9|      |9|6|3|
The program initializes a 2D matrix as a picture and asks the user what manipulation he wants to do.
there are 4 options: Clockwise, Anticlockwise, Vertically, Horizontally


## Run instructions: (Linux)
1) gcc -o Main arrays.c functions.c PictureManipulation.c NumberGame.c Main.c
2) make
3) ./Main
