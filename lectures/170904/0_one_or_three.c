#include <stdlib.h>

int main(int argc, char* argv[]) {
  (void)argv;
  if (argc == 2) { // 1 argument
    exit(EXIT_SUCCESS);
  }
  else if (argc == 4) { // 3 arguments
    exit(EXIT_SUCCESS);
  }
  else {
    exit(EXIT_FAILURE);
  }
}