#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HISTORY_SIZE 5

#ifndef _POSIX_C_SOURCE
char *strdup(const char *s) {
  size_t len = strlen(s) + 1;
  char *new = malloc(len);
  if (new == NULL)
    return NULL;
  return memcpy(new, s, len);
}
#endif

void free_history(char *history[]) {
  for (int i = 0; i < HISTORY_SIZE; i++) {
    free(history[i]);
  }
}

void print_history(char *history[], int start, int count) {
  for (int i = 0; i < count; i++) {
    int idx = (start + i) % HISTORY_SIZE;
    if (history[idx]) {
      printf("%s", history[idx]);
    }
  }
}

int main() {
  char *history[HISTORY_SIZE] = {NULL};
  int curr = 0;
  int count = 0;
  char *line = NULL;
  size_t len = 0;

  while (1) {
    printf("Enter input: ");
    ssize_t read = getline(&line, &len, stdin);
    if (read == -1) {
      break; // EOF or error
    }

    free(history[curr]);
    history[curr] = strdup(line);

    curr = (curr + 1) % HISTORY_SIZE;
    if (count < HISTORY_SIZE)
      count++;

    if (strcmp(line, "print\n") == 0) {
      int start = (curr + HISTORY_SIZE - count) % HISTORY_SIZE;
      print_history(history, start, count);
    }
  }

  free(line);
  free_history(history);
  return 0;
}
