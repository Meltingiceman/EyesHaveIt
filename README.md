# EyesHaveIt
A dice game I made for a Java programming class which I rewrote in C++.

The goal of the game is to get 150 points or higher in the same number of turns before the computer does. You get points by "rolling" a 
pair of dice up to five times and at the end of the turn the points you have accumulated will be added on to the player's score. 
However rolling a snake eyes, a double, or a boxcar (two sixes) will modify the players points in some way.

Boxcar:
  rolling two sixes, or a boxcar, will make the player lose all their points ad end their turn prematurely.

Doubles:
  Rolling a double that is not a snake eyes or a boxcar will make the player lose all the points they have accumulated during their
  turn as well as end their turn prematurely, but will not affect the score that the player currently has.

Snake eyes:
  Rolling a snake eyes will double the amount of points you recieve at the end of your turn. This can be applied several times per turn 
  as long as the player rolls more snake eyes. However if the player rolls a snake eyes and then rolls some other double then the effect
  the snake eyes would have is cancelled.
  
In the even that both the players are over 150 and are tied there will be a tie breaker where each player is given a turn (5 rounds each
by default) to get higher points than the other. This process will repeat until someone has the higher score.
