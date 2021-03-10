# cmdnotes
cmdnotes is a barebones command line notes app, at present it only saves notes until you close the program.
========================================================================================================================================================================================

commands

-list lists all your notes with there numbers, example output:

-see is how you look at specific notes, after running this command it will ask you for a number and then print the note the number corresponds too

-exit exits the program with code 0, will save notes to file in future revisions

-mknote lets you add a note, normally just typing will do nothing

-delete lets you delete your notes

-help explains all the commands and gives licence info

-transaction starts a SQL style transaction

-commit saves the changes made in a transaction to file

-rollback reverts any changes made

-amend allows you to overwrite a previously saved note

to compile this program from source clone the repo into visual studio 2017 or higher and compile
