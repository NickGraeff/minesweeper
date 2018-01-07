# minesweeper
Exactly as the title says. It was the end of summer and I felt hopeless not having built anything real up to that point when I noticed that minesweeper was no longer built into Windows. I figured "I could build that" and I did. Because it uses the SFML library, it's "supposed" to work on all platforms so long as you have that library installed. I've tested it on Windows and Linux but I don't know how else to tell you to build it besides running the Makefile and hoping you have the correct libraries installed. 

<img src="https://i.imgur.com/zkmyLwM.png">

## Flood-fill Algorithm
This was the first application I built right after taking my Data Structures and Algorithms class. I wanted to put my skills to use so I started by building a class and everything that goes along with creating a data structure. Near the completion of the project I realized I wasn't actually completed because in Minesweeper when you click on a tile with no mines around it, it automatically uncovers all surrounding tiles with the same condition. I figured I could handle that. That would just require a depth first search (or breadth, but I liked depth better at the time) to the surrounding blocks to see if they were also not near a mine. That was the final step and suddenly I had a game up and running. Later on I found out this specific usage of DFS was called the flood-fill algorithm.
