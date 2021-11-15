#include <stdlib.h>
#include <stdio.h>
#include "adrbook.h"

const char *_bst_todo_format = "TODO [bst]: %s\nhalting\n";

/* Create a bst consisting of one leaf node. */
/* Do not copy the vcard, just point to it. */
/* (This is a shallow-copy constructor.) */
bst *bst_singleton(vcard *c)
{
  bst *res = (bst*)malloc(sizeof(bst));
  if (res == NULL) {
      fprintf(stderr,_bst_todo_format,"bst_singleton");
      exit(1);
  }
  res->c = c;
  res->left = NULL;
  res->right = NULL;
  return res;
}

/* Insert a vcard into a non-empty BST. */
/* Raise an error if given an empty BST. */
/* Use cnet alphabetical order (per strcmp). */
/* If the cnet is already present in the tree, insert nothing. */
/* Do not copy the vcard (this is shallow-copy insert). */
/* Return the number of vcards inserted (either 1 or 0). */
int bst_insert(bst *t, vcard *c)
{
  if (t == NULL) {
      fprintf(stderr,_bst_todo_format,"bst_insert");
      exit(1);
  }
  int i = strcmp(t->c->cnet, c->cnet); 
  if (i == 0) {
      return 0;
  } else if((i > 0) && (t->left)) {
      return bst_insert(t->left, c);
  } else if((i > 0) && (t->left == NULL)) {
      t->left = bst_singleton(c);
      return 1; 
  } else if((i < 0) && (t->right)){
      return bst_insert(t->right, c);
  } else {
      t->right = bst_singleton(c);
      return 1;
  }
}

/* Compute the total number of vcards in the tree. */
unsigned int bst_num_entries(bst *t)
{
  if (t == NULL) {
     return 0;
  }
  return bst_num_entries(t->left) + bst_num_entries(t->right) + 1;
}

/* The empty bst has height 0. */
/* A singleton tree has height 1, etc. */
unsigned int bst_height(bst *t)
{
  if (t == NULL) {
     return 0;
  }
  int l = bst_height(t->left);
  int r = bst_height(t->right);
  if (l < r) {
     return r + 1;
  } else {
     return l + 1;
  }
}

/* Return NULL if nothing is found. */
/* n_comparisons is an out parameter to count the number of */
/* comparisons made during the search. */
/* *n_comparisons is 0 when first called. */
vcard *bst_search(bst *t, char *cnet, int *n_comparisons)
{
  if (t == NULL) {
     return NULL;
  }
  int i = strcmp(t->c->cnet, cnet);
  if (i == 0) {
     (*n_comparisons)++;
     return t->c;
  } else if (i > 0) {
     (*n_comparisons)++;
     return bst_search(t->left, cnet, n_comparisons);
  } else {
     (*n_comparisons)++;
     return bst_search(t->right, cnet, n_comparisons);
  }
}

/* Show all cnets that start with given character. */
/* Show cnets one per line in alphabetical order. */
/* Do not traverse parts of the tree you know to be irrelevant. */
/* Return the number of cnets displayed. */
/* note: f is the destination of the output, e.g. the screen;
 * our code calls this with stdout, which is where printfs are sent;
 * simply use fprintf rather than printf in this function, and pass in f
 * as its first parameter
 */
unsigned int bst_c(FILE *f, bst *t, char c)
{
  if (t == NULL) {
    return 0;
  } 
  char a = t->c->cnet[0];
  if (a == c) {
      fprintf(f, "%s\n", t->c->cnet);
      return bst_c(f, t->left, c) + bst_c(f, t->right, c) + 1;
  } else if (a < c) {
      return bst_c(f, t->right, c);
  } else {
      return bst_c(f, t->left, c);
  }
}

/* Free the bst and all vcards as well. */
void bst_free(bst *t)
{
  if (t) {
     bst_free(t->left);
     bst_free(t->right);
     vcard_free(t->c);
     free(t); 
  }
}
