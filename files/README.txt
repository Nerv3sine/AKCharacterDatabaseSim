don't include the .o files
include anything that was included and wasn't mentioned before

CMPT 135 Assignment 5
=====================

Names of Team Members
---------------------

Jason Cai, jason_cai_4@sfu.ca


Instructions for Compiling and Running
--------------------------------------

just type "make" in the shell and the program should build
"./a5" to run


Limitations
-----------

all substring searching features(mentioned)
program does not ask for re input but waits for another input
not 100% sure if all lines are < 100 characters
ncurses was not used

Side feature (that I wanted but forgot to implement)
instead of storing character stats as different Members
I wanted to store them as vectors, which would've made everything much more efficient


Known Bugs
----------

None


Extra Features
--------------

I combined the search and removal features into 1
Created a page interface rather than listing all the operators in the database
- to help with this I added a jump to page feature for ease of use

A random operator generation program called "OpGen.cpp" is also available for use in testing
 - "make OpGen" will build the program
 - "./OpGen" will run the program
 - The OpGen program runs seperately from the main a5.cpp program
OpGen is a program used for generating random operators, useful in testing large quantities of operators
 - the program will print randomly generated names and stats that are copy and paste ready
    - which can be directly inserted into the database.txt file
 - the name generation sources from the names.txt file which was sourced from challenge 9


Program Side Info
---------------

Based on the mobile tower defense game: "Arknights"
There are a few operators that were taken from the game itself
About 60% of the other operators are randomly generated using OpGen.cppreference
 - this program is included in the folder


Side Notes
----------

https://en.cppreference.com/w/cpp/algorithm/sort
I used the lambda expression to solve a sorting error within the class
 - this was used in the database.cpp to solve sorting bugs within the sorting methods
example:
    sort(begin(allInfo), end(allInfo), [](ROperator a, ROperator b){
        return(a.sortByRarity(a, b));
    });


Test programs weren't created due to limited time

All libraries used are standard libraries

I used binary searching for a lot of the database add/removal
standard searching for fields that have ranges

exceptions were used to handle potentials errors that the user may cause

planned to do an overwrite method in which if the database.txt does not exist
- the program will create its own pre-set database.txt file


I apologize to anyone that will be reading my code
 - due to the lack of efficiency with vectors, the code is extremely long and inefficient sometimes
 - given more time, there would've definetly been optimizations to make the code more efficient
thanks for bearing with me