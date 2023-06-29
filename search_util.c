#include "search_util.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


// This function should loop over the vocabulary (which contains num_words
// entries) and return the number of words in which that particular letter
// occurs. So if there are 15 words containing the letter 'x' for the particular
// vocabulary, then this function will return 15.
int score_letter(char letter, char **vocabulary, size_t num_words) {
  int words_with_letter = 0;
  for (int i = 0; i < (int) num_words; i++) {
    bool found_letter = false;
    for (int k = 0; k < 5; k++) {
      if (vocabulary[i] != NULL) {
        if ((vocabulary[i][k] == letter) && (found_letter == false)) {
          words_with_letter += 1;
          found_letter = true;
        }
      }
    }
  }
  return words_with_letter;
}


// Calculate the score for a given word, where the letter_scores array has
// already been filled out for you and is guaranteed to be of length 26. Slot 0
// contains the score for 'a', and slot 25 contains the score for 'z'.
// The score for a word is the sum of all of the letter scores, *for unique
// letters*. So if the letter 'e' occurs three times, it only contributes to the
// score once.
int score_word(char *word, int *letter_scores) {
  int word_score = 0;
  bool visited_letter[26];
  for (int i = 0; i < 26; i++) {
    visited_letter[i] = false;
  }
  if (word != NULL) {
    for (int i = 0; i < 5; i++) {
      switch (word[i]) {
        case 'a':
          if (visited_letter[0] == false) {
            word_score += letter_scores[0]; 
            visited_letter[0] = true;
          }
          break;
        case 'b':
          if (visited_letter[1] == false) {
            word_score += letter_scores[1]; 
            visited_letter[1] = true;
          }
          break;
        case 'c':
          if (visited_letter[2] == false) {
            word_score += letter_scores[2]; 
            visited_letter[2] = true;
          }
          break;
        case 'd':
          if (visited_letter[3] == false) {
            word_score += letter_scores[3]; 
            visited_letter[3] = true;
          }
          break;
        case 'e': 
          if (visited_letter[4] == false) {
            word_score += letter_scores[4]; 
            visited_letter[4] = true;
          }
          break;
        case 'f': 
          if (visited_letter[5] == false) {
            word_score += letter_scores[5]; 
            visited_letter[5] = true;
          }
          break;
        case 'g': 
          if (visited_letter[6] == false) {
            word_score += letter_scores[6]; 
            visited_letter[6] = true;
          }
          break;
        case 'h': 
          if (visited_letter[7] == false) {
            word_score += letter_scores[7]; 
            visited_letter[7] = true;
          }
          break;
        case 'i': 
          if (visited_letter[8] == false) {
            word_score += letter_scores[8]; 
            visited_letter[8] = true;
          }
          break;
        case 'j': 
          if (visited_letter[9] == false) {
            word_score += letter_scores[9]; 
            visited_letter[9] = true;
          }
          break;
        case 'k': 
          if (visited_letter[10] == false) {
            word_score += letter_scores[10]; 
            visited_letter[10] = true;
          }
          break;
        case 'l': 
          if (visited_letter[11] == false) {
            word_score += letter_scores[11]; 
            visited_letter[11] = true;
          }
          break;
        case 'm': 
          if (visited_letter[12] == false) {
            word_score += letter_scores[12]; 
            visited_letter[12] = true;
          }
          break;
        case 'n': 
          if (visited_letter[13] == false) {
            word_score += letter_scores[13]; 
            visited_letter[13] = true;
          }
          break;
        case 'o': 
          if (visited_letter[14] == false) {
            word_score += letter_scores[14]; 
            visited_letter[14] = true;
          }
          break;
        case 'p': 
          if (visited_letter[15] == false) {
            word_score += letter_scores[15]; 
            visited_letter[15] = true;
          }
          break;
        case 'q': 
          if (visited_letter[16] == false) {
            word_score += letter_scores[16]; 
            visited_letter[16] = true;
          }
          break;
        case 'r': 
          if (visited_letter[17] == false) {
            word_score += letter_scores[17]; 
            visited_letter[17] = true;
          }
          break;
        case 's': 
          if (visited_letter[18] == false) {
            word_score += letter_scores[18]; 
            visited_letter[18] = true;
          }
          break;
        case 't': 
          if (visited_letter[19] == false) {
            word_score += letter_scores[19]; 
            visited_letter[19] = true;
          }
          break;
        case 'u': 
          if (visited_letter[20] == false) {
            word_score += letter_scores[20]; 
            visited_letter[20] = true;
          }
          break;
        case 'v': 
          if (visited_letter[21] == false) {
            word_score += letter_scores[21]; 
            visited_letter[21] = true;
          }
          break;
        case 'w': 
          if (visited_letter[22] == false) {
            word_score += letter_scores[22]; 
            visited_letter[22] = true;
          }
          break;
        case 'x': 
          if (visited_letter[23] == false) {
            word_score += letter_scores[23]; 
            visited_letter[23] = true;
          }
          break;
        case 'y': 
          if (visited_letter[24] == false) {
            word_score += letter_scores[24]; 
            visited_letter[24] = true;
          }
          break;
        case 'z': 
          if (visited_letter[25] == false) {
            word_score += letter_scores[25]; 
            visited_letter[25] = true;
          }
          break;
        default: 
          //printf("ERROR can't find letter \"%c\" in letter position\n", word[i]);
          printf("couldnt locate letter\n");
          break;
      }
    }
  }
  return word_score;
}

// Returns the optimum guess, based on our heuristic.
// This one works, you don't have to change it.
// Note that this function allocates a new string every time it runs, and those
// strings will need to be freed!
char *get_guess(char **vocabulary, size_t num_words) {
  int letter_scores[26];

  for (int i = 0; i < 26; i++) {
    letter_scores[i] = score_letter('a' + i, vocabulary, num_words);
  }

  char *best_guess = NULL;
  int best_score = 0;
  int score = 0;
  for (size_t i = 0; i < num_words; i++) {
    if (vocabulary[i] == NULL) {
      continue;
    }
    score = score_word(vocabulary[i], letter_scores);
    if (score > best_score) {
      best_guess = vocabulary[i];
      best_score = score;
    }
  }
  return best_guess ? strdup(best_guess) : NULL;
}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter *does not occur* in the secret word. So for any of the words
// in the vocabulary that do contain that letter, free their pointers and set
// the corresponding slot to NULL.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_gray(char letter, char **vocabulary, size_t num_words) {
  size_t freed_words = 0;
  bool letter_in_word = false;
  for (int i = 0; i < (int) num_words; i++) {
    for (int k = 0; k < 5; k++) {
      if (vocabulary[i] != NULL) {
        if ((vocabulary[i][k] == letter) && (letter_in_word == false)) {
          //printf("freeing : %s\n", vocabulary[i]);
          letter_in_word = true;
          free(vocabulary[i]);
          vocabulary[i] = NULL;
          freed_words += 1;
          break;
        }
        if (letter_in_word) {
          break;
        }
      }
    }
    letter_in_word = false;
  }
  return freed_words;
}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter occurs in the word, *but not at this particular position*.
// So remove any words that either don't contain the letter at all, or do
// contain it, but at the specified position.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_yellow(char letter, int position, char **vocabulary, size_t num_words) {
  size_t freed_words = 0;
  bool letter_in_word = false;
  for (int i = 0; i < (int) num_words; i++) {
    for (int k = 0; k < 5; k++) {
      if (vocabulary[i] != NULL) {
        if ((vocabulary[i][k] == letter) && (position != k)) {
          letter_in_word = true;
        }
        if ((k == 4) && (letter_in_word == false)) {
          //printf("freeing : %s\n", vocabulary[i]);
          free(vocabulary[i]);
          vocabulary[i] = NULL;
          freed_words += 1;
          break;
        }
      }
    }
    letter_in_word = false;
  }
  return freed_words;
}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter *definitely* occurs as the specified position. So remove any
// word that does not contain, for the specified position, the specified letter.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_green(char letter, int position, char **vocabulary, size_t num_words) {
  size_t freed_words = 0;
  bool letter_in_word = false;
  for (int i = 0; i < (int) num_words; i++) {
    for (int k = 0; k < 5; k++) {
      if (vocabulary[i] != NULL) {
        if ((vocabulary[i][k] == letter) && (position == k)) {
          letter_in_word = true;
        }
        if ((k == 4) && (letter_in_word == false)) {
          //printf("freeing : %s\n", vocabulary[i]);
          free(vocabulary[i]);
          vocabulary[i] = NULL;
          freed_words += 1;
          break;
        }
      }
    }
    letter_in_word = false;
  }
  return freed_words;
}

// Free each of the strings in the vocabulary, as well as the pointer vocabulary
// itself (which points to an array of char *).
void free_vocabulary(char **vocabulary, size_t num_words) {
  for (size_t i = 0; i < num_words; i++) {
    free(vocabulary[i]);
  }
  free(vocabulary);
}
