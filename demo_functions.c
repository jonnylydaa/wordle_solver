// A nice place for you to mess with the functions, while you're developing.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "search_util.h"

int main(void) {
  char words[10][6] = {"stalk", "scrap", "shear", "batch", "motif", "tense",
    "ultra", "vital", "ether", "nadir" };

  // make a dynamically-allocated vocabulary that you can mess with, including
  // freeing elements of it when necessary.
  char **vocabulary = calloc(10, sizeof(char *));
  for (int i=0; i < 10; i++) {
    vocabulary[i] = strdup(words[i]);
  }
  size_t num_words = 10;
  int letter_scores[26];

  for (int i = 0; i < 26; i++) {
    letter_scores[i] = score_letter('a' + i, vocabulary, num_words);
  }
  printf("number of 'e' : %d\n", score_letter('e', vocabulary, num_words));
  printf("score: %d\n", score_word("scrap", letter_scores));
  printf("amount of free'd words: %lu\n", filter_vocabulary_gray('e', vocabulary, num_words));
  printf("amount of free'd words: %lu\n", filter_vocabulary_yellow('a', 2, vocabulary, num_words));

  printf("amount of free'd words: %lu\n", filter_vocabulary_green('a', 1, vocabulary, num_words));
  for (int i = 0; i < 10; i++) {
    printf("vocab list element %i is %s\n", i, vocabulary[i]);
  }
  // You don't have to mess with your functions in here, but you might like to
  // do that.

  

  free_vocabulary(vocabulary, num_words);
  
  return 0;
}
