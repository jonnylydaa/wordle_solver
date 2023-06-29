## Homework 6 Design

---

I decided to break this assignment into multiple parts.

- First, I write `score_letter` and to do this I followed this structure:
 
> for (int i = 0; i < (int) num_words; i++) {\
    > for (int k = 0; k < 5; k++) {\
      > if (vocabulary[i][k] == letter) {\
       > words_with_letter += 1; }\
    > }\
  > }

- Second, I will write `score_word`, which involves `score_letter`. This will require the summing of all letter scores into a words score. 

`score_word` will work in the following way:

> look at each letter in the word\
> get that letter's score and add it to the overall word score\
> return word's score

- Next, I will write `filter_vocabulary_gray`. This will have to search through the `**vocabulary` and have to free/set all the  pointers to words with grey letters to NULL. 

> for every word in **vocabulary\
> if word contains any gray letter\
> then free that word and set it to NULL

This effectively slims down the **vocabulary, making the wordle solver more accurate.

- Next, I will write `filter_vocabulary_yellow` which will behave similarly to `filter_vocabulary_gray` in the fact that it will delete words that don't fit the criteria. In this case, if the word does not contain the yellow letter or it has the yellow letter in the wrong place, it will be deleted.

- Next, I will write `filter_vocabulary_green` which behaves similarly to both `filter_vocabulary_yellow` and `filter_vocabulary_gray`. This function will check if the word has the specific green letter in the right place, if it doesn't, the word is deleted (free'd and set to NULL), which decreases `**vocabulary`'s size.

- Lastly, `free_vocabulary` will free all of the memory allocated for this wordle solver. 
