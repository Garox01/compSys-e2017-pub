//
// Author:  Michael Kirkedal Thomsen
//
// Some very basic file operations
//
// Made for CompSys, e2017
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
  (void) argc;
  (void) argv;
  char input[16];

  // We have several standard file streams available though stdio.h:
  // the most important are: stdin, stdout, stderr

  // stdin ...
  printf ("Give me a string:\n");
  fgets(input, sizeof(input), stdin);

  // stdout
  fprintf (stdout, "You wrote: %s\n", input);
  // identical to printf(...., ...)

  // stderr
  fprintf (stderr, "Our exit code is: %d\n", EXIT_SUCCESS);

  // First, try running the program normally,
  //  > ./prog filename
  // then run the program by piping output to a file
  // > ./prog filename > output.txt
  // See the difference

  // Opening a filename

  FILE* fp;
  fp = fopen(argv[1], "r");

  if (errno == 0) {
    printf("File: %s was found, status: %d\n", argv[1], errno);

    // Get the position relative to the start of the file.
    // We will use this later
    fpos_t fp_start;
    fgetpos(fp, &fp_start);

    // Read a char from the file (moves file pointer).
    char c = fgetc(fp);
    printf("I read the char: '%c'\n", c);

    // Look at the difference in position:
    fpos_t fp_now;
    fgetpos(fp, &fp_now);
    printf("Start of file:                 0x%llx\n", fp_start);
    printf("Position after reading a char: 0x%llx\n", fp_now);

    // Read a string
    fgets(input, sizeof(input), fp);
    printf("I read the string: \"%s\"\n", input);

    // Reset to position of file
    fsetpos(fp, &fp_start);

    // Using feof(1) -- careful!!!
    char last;
    // NB, This is not an efficient implementation of last
    while (!feof(fp)) {
      last = fgetc(fp);
    }
    printf("The _not_ last char was: %c\n", last);
    // If you look at the output, then this is not he last char.

    // The issue is that feof(1) checks if the position of the file
    // pointer is currently at the end of file. In the above case
    // I will not be at the end position until after I read the
    // character that moves the position to end-of-file. At this
    // point I have passed the last character.

    // A solution to this could be the store the previous.
    rewind(fp); // Back to the beginning
    char cur;
    while (!feof(fp)) {
      last = cur;
      cur = fgetc(fp);
    }
    printf("The last char was: %c\n", last);

    // Always remember to close your file.
    fclose(fp);
  }
  else {
    printf("Reading %s resulted in error %d\n", argv[1], errno);
    // This should be handled better!!!
  }

  exit(EXIT_SUCCESS);
}