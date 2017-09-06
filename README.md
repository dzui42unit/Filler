# Filler

Create your player to fight other students on the world famous (or infamous) Filler board.
The concept is simple: two players gain points by placing on a board, one after the other,
the game piece obtained by the game master (in the form of an executable Ruby program).
The game ends when the game piece cannot be placed anymore. Have fun!

hot to compile: gcc *.c -o filler

How to run: ./filler_vm -p1 user1 -p2 user2 -v -f samples/w1.flr

In this game, two players fight each other. They play one after the other.
* The goal is to collect as many points as possible by placing the highest number of
pieces on the the game board.
* The board is defined by X columns and N lines, it will then become X*N cells.
* At the beginning of each turn, you will receive your game piece.
* A game piece is defined by X columns and N lines, so it will be X*N cells. Inside
each game piece, will be included a shape of one or many cells.
* To be able to place a piece on the board, it is mandatory that one, and only one
cell of the shape (in your piece) covers the cell of a shape placed previously (your
territory).
* The shape must not exceed the dimensions of the board
* When the game starts, the board already contains one shape.
* The game stops at the first error: either when a game piece cannot be placed
anymore or it has been wrongly placed.

For this project, you will have to create a filler player. Your goal is to win:
* It will read the board and the game pieces placed on the standard output.
* Each turn the filler rewrites the board map and includes a new piece to be
placed.
* In order to place the game piece on the board, the player will have to write
it’s coordinates on the standard ouput.
* The following format must be used “X Y\n”.
* You will collect points each time you place a piece.

The filler will only send the line that concerns your program. You’ll have to
get your player number.

* If you are Player 1 your program will be represented by “o” and “O”. If you
are Player 2, your program will be represented by “x” and “X”. The first step
will be to get your player number.
* The lowercases (“x” or “o”) will highlight the piece last placed on the board.
At the following turns, that same piece will be represented by the uppercase
letters (“X” or “O”), as it won’t be the piece last placed anymore.
* You will collect points each time you place a piece.

How the game works

* At each turn, the filler will send the updated map and a new token to the
player concerned.
* The player concerned will write on the standard output his or her piece’s
coordinates to place it on the board.
* The filler will send the map and a new piece to the other player.

The example of board:

![board](https://user-images.githubusercontent.com/28359156/30075771-827ecdae-927f-11e7-8905-aa4f049a5a66.png)

The example of tokens:

![token](https://user-images.githubusercontent.com/28359156/30075773-83ab6764-927f-11e7-931f-ab505616bd16.png)

The game rolls example:

![game_ex](https://user-images.githubusercontent.com/28359156/30075777-84c3cea2-927f-11e7-9cc4-498bdce7c317.png)
