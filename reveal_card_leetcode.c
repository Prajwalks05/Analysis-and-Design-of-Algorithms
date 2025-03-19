/*388. Longest Absolute File Path
Suppose we have a file system that stores both files and directories. An example of one system is represented in the following picture
Here, we have dir as the only directory in the root. dir contains two subdirectories, subdir1 and subdir2. subdir1 contains a file file1.ext and subdirectory subsubdir1. subdir2 contains a subdirectory subsubdir2, which contains a file file2.ext.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATH_LENGTH 10000
int lengthLongestPath(char* input) {
    // An array to store the length of the path at each level (index is the level)
    int len[MAX_PATH_LENGTH] = {0};
    int res = 0;
    char* line = strtok(input, "\n"); // strtok splits input by '\n'
    while (line != NULL) {
        int numTabs = 0;
        // Count the number of '\t' characters at the start of the line
        while (line[numTabs] == '\t') {
            numTabs++;
        } 
        // Calculate the path length up to the current level
        if (numTabs == 0) {
            len[numTabs] = strlen(line); // Root directory
        } else {
            len[numTabs] = len[numTabs - 1] + 1 + strlen(line + numTabs); // Adding 1 for '/'
        }
        // Check if the current line represents a file (contains '.')
        if (strchr(line, '.') != NULL) {
            // Update the maximum path length if this file has a longer path
            res = (res > len[numTabs]) ? res : len[numTabs];
        }
        // Get the next line
        line = strtok(NULL, "\n");
    }
    return res;
}
