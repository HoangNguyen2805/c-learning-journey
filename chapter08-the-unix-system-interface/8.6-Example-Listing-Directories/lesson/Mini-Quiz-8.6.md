# Mini-Quiz 8.6 - Listing Directories

1. What does a UNIX directory actually contain, and where does the rest of a file's information live?

2. Write the stat call for "notes.txt" including the variable declaration it fills, and its failure indication.

3. Name four members of struct stat and what each records.

4. Show the exact expression that tests whether stbuf describes a directory. Why is a mask (S_IFMT) needed rather than == S_IFDIR directly on st_mode?

5. Sketch the canonical opendir/readdir/closedir loop. What does readdir return when entries run out?

6. Every directory contains "." and "..". What are they, and precisely what disaster does recursing into them cause?

7. fsize and dirwalk call each other. What structural property of the filesystem makes mutual recursion the natural shape? Which Chapter 5 program used the same pattern?

8. dirwalk's second parameter is `void (*fcn)(char *)`. What design win does this give over hardcoding a call to fsize? Give a second callback you might pass.

9. Before sprintf-ing dir + "/" + name into a buffer, dirwalk checks `strlen(dir)+strlen(name)+2 > sizeof(name)`. Account for the exact "+2".

10. (Prediction) fsize is run on: d/ containing f1 (10 bytes) and sub/ containing f2 (20 bytes). List the ORDER of printed lines (sizes+names), given that a directory's own line prints AFTER its contents are walked.
