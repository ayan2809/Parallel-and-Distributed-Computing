#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "smith_waterman_helpers.h"

/* Scoring constants */
int MATCH = 2;
int MISMATCH = -1;
int SPACE = -1;

/* Function Prototypes */
void smith_waterman_forward(char* x, char* y, int x_len, int y_len, int score[x_len+1][y_len+1], int pred[x_len+1][y_len+1], int* max_row, int* max_col);
void smith_waterman_backward(char* x, char* y, int x_len, int y_len, int score[x_len+1][y_len+1], int pred[x_len+1][y_len+1], int* max_row, int* max_col);

/*
 * Function: smith_waterman_forward
 * --------------------
 *  Completes the forward phase of the Smith Waterman by completing
 *  the score matrix and predecessor matrix.
 *
 *  x: first string
 *  y: second string
 *  x_len: first string length
 *  y_len: second string length
 *  score: score matrix
 *  pred: predecessor matrix (0 = no pred, 1 = diagonal, 2 = left, 3 = up)
 *  max_row: index of row with max score
 *  max_col: index of column with max score
 */
void smith_waterman_forward(
  char* x,
  char* y,
  int x_len,
  int y_len,
  int score[x_len+1][y_len+1],
  int pred[x_len+1][y_len+1],
  int* max_row,
  int* max_col
) {
  int i,j;
  int diagonal, left, up;
  int max_score = 0;
  *max_row = 0;
  *max_col = 0;
  // Initialize the first row and first column of matrix to 0
  for (i=0; i<=x_len; i++) {
    for (j=0; j<=y_len; j++) {
      score[i][j]=0;
      pred[i][j]=0;
    }
  }

  // Fill out matrices
  for (i=1; i<=x_len; i++) {
    for (j=1; j<=y_len; j++) {
      // Calculate diagonal, up, and left
      if (x[i-1] == y[j-1]) {
        diagonal = score[i-1][j-1] + MATCH;
      } else {
        diagonal = score[i-1][j-1] + MISMATCH;
      }
      up = score[i-1][j] + SPACE;
      left = score[i][j-1] + SPACE;
      // Set score & predecessor for current subproblem
      if ((max(0,max(diagonal,max(up,left)))) == 0) {
        score[i][j] = 0;
        pred[i][j] = 0;
      } else if (diagonal >= up && diagonal >= left) {
        score[i][j] = diagonal;
        pred[i][j] = 1;
      } else if (left >= diagonal && left >= up) {
        score[i][j] = left;
        pred[i][j] = 2;
      } else {
        score[i][j] = up;
        pred[i][j] = 3;
      }

      // Update max if needed
      if (score[i][j] > max_score) {
        max_score = score[i][j];
        *max_row = i;
        *max_col = j;
      }
    }
  }
}

/*
 * Function: smith_waterman_backward
 * --------------------
 *  Traces back pred matrix to get the best local alignment for x and y.
 *
 *  x: first string
 *  y: second string
 *  x_len: first string length
 *  y_len: second string length
 *  score: score matrix
 *  pred: predecessor matrix (0 = no pred, 1 = diagonal, 2 = left, 3 = up)
 *  max_row: index of row with max score
 *  max_col: index of column with max score
 */
void smith_waterman_backward(
  char* x,
  char* y,
  int x_len,
  int y_len,
  int score[x_len+1][y_len+1],
  int pred[x_len+1][y_len+1],
  int* max_row,
  int* max_col
) {
  int alignment_len = 0;
  int i = *max_row;
  int j = *max_col;
  char result_x_alignment[x_len+y_len+1];
  char result_y_alignment[x_len+y_len+1];
  // Keep tracing back from element with max_score until we hit a 0
  while (pred[i][j] != 0) {
    switch(pred[i][j]) {
      case 1: // diagonal
        result_x_alignment[alignment_len] = x[i-1];
        result_y_alignment[alignment_len] = y[j-1];
        i--;
        j--;
        break;
      case 2: // left
        result_x_alignment[alignment_len] ='-';
        result_y_alignment[alignment_len] = y[j-1];
        j--;
        break;
      case 3: // up
        result_x_alignment[alignment_len] = x[i-1];
        result_y_alignment[alignment_len] = '-';
        i--;
        break;
    }
    alignment_len++;

  }
  printf("Local alignment for reference: ");
  print_reverse(result_x_alignment,alignment_len);
  printf("Local alignment for query: ");
  print_reverse(result_y_alignment,alignment_len);
}

int main(int argc, const char* argv[]) {
  srand(time(NULL));
  int ref_len,query_len;
  printf("===========================================================\n"
         "SMITH WATERMAN SERIAL ALGORITHM\n");
  printf("Computing the local alignment for two random DNA sequences.\n");
  printf("===========================================================\n");
  printf("Enter the string size for the reference string: ");
  scanf("%d",&ref_len);
  printf("Enter the string size for the query string: ");
  scanf("%d",&query_len);
  char* ref = generate_sequence(ref_len);
  char* query = generate_sequence(query_len);
  printf("Reference string: %s\nQuery string: %s\n",ref,query);
  int score[ref_len+1][query_len+1];
  int pred[ref_len+1][query_len+1];
  int max_row;
  int max_col;
  smith_waterman_forward(ref, query, ref_len, query_len, score, pred, &max_row, &max_col);
  printf("===========================================================\n"
         "RESULTS\n"
         "===========================================================\n");
  smith_waterman_backward(ref, query, ref_len, query_len, score, pred, &max_row, &max_col);
  return 0;
}
