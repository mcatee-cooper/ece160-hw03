#include <stdio.h>
#include <stdlib.h>

/*** padraic mcatee | hw03 | ece-160 ***/

typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  char *major;
  int year;
} Student;

void print_student(Mode m, Student s) {
  switch (m) {
  case NAME_ONLY:
    printf("%s %s\n", s.first_name, s.last_name);
    break;
  case MAJOR_AND_NAME:
    printf("%s %s %s\n", s.major, s.first_name, s.last_name);
    break;
  case YEAR_AND_NAME:
    printf("%d %s %s\n", s.year, s.first_name, s.last_name);
    break;
  }
}

int main(int argc, char* argv[]) {
  /* declarations */
  int idx = 0;
  Mode mode_name = (Mode)atoi(argv[1]);
  Student s[argc-2];
  /* loop over argv in 4's, */
  /* append to s, and print */
  for (int i = 2;i<argc;i+=4) { 
    s[idx].first_name = argv[i];
    s[idx].last_name = argv[i+1];
    s[idx].major = argv[i+2];
    s[idx].year = atoi(argv[i+3]);
    print_student(mode_name,s[idx]);
    idx++;
  }
  return 0;
}
