# Assignment_1 RT2 Marco Limone

This first assignment is basically divided into 3 parts:
- 1) compilation of a documentation related to the third assignment of the RT1 course through the use of Doxygen or Sphinx
- 2) creation of a user interface in jupyter, which can replace the user interface of the third assignment of the RT1 course
- 3) statistical analysis made by comparing the rabot made by me for the first assignment of the RT1 course and a robot given by the professor

## First part

Personally I had to change a lot in the third assignment because I didn't have a real user interface separate from the core of the program, so I create a python script that is only a user interface. This user interface communicates with the main core through services (the main core would be the same script I already had previously where I removed the user interactions and added the communication with the services in their place).
Having said that, to do the documentation I used Sphinx, in particular for the core of the program which is written in C ++ I used the JAVADOC style, while for the user interface written in python I used Google Docstrings.

## Second part

For the second part I created a user interface in jupyter based broadly on the user interface written in python with the addition of some graphs referring to the trajectory of the robot, the number of goals achieved, and the laser display.
In particular, I used a cell for each task to try to make the user interface clearer. The description of the individual cells is sent specifically to the notebook where the functionality of the code cells has been described through markdown cells.

## Third part

As for the third part, in the repository there is a file containing a report relating to the statistical analysis that was carried out, with all the indications
