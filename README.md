BSQ (Biggest square)

Objective: Given a rectabgular map, place the largest square possible (top - left priority) avoiding obsticles.

The map(s) can we passed either via arguments or via standard input.

Map format: The first line indicates the number of rows, plane surface, obstacle, char to be placed in the square found.
	Eg: 10.oX
		i.e. 10 rows, (.) indicates place surface, (o) indicates obstacle, and the largest square found must be represented by (X).

If the first line doesn't match the map format, the program should send an error message.

To run the program type "make" in terminal and it will compile the program and the executable file is name "bsq".

map generator program is inside the maps directory along with few sample maps. 

To generate maps, use the following command (where gen_map.pl is downloaded)
	perl gen_map.pl [LEN_LINES] [NBR_LINES] [DENSITY]

Sample map:
10.oX
.....oo.oo
.o....o..o
.ooo..o.oo
.o.o.o...o
o.o.o..ooo
o...o.o.oo
o.oo..oo..
oo..o.oo.o
.o.ooo..o.
.o.ooo..oo
