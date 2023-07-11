#include <stdlib.h>
#include <stdio.h>
#include "elk.h"

// C function that adds two numbers. Will be called from JS
jsval_t sum(struct js *js, jsval_t *args, int nargs) {
  if (nargs != 2) return js_mknum(2);
  double a = js_getnum(args[0]);  // Fetch 1st arg
  double b = js_getnum(args[1]);  // Fetch 2nd arg
  return js_mknum(a + b);
}

int main(void) {
  char mem[200];
  struct js *js = js_create(mem, sizeof(mem));  // Create JS instance
    js_set(js, js_glob(js), "sum", js_mkfun(sum));   // Import sum()
  jsval_t v = js_eval(js, "sum(2,3);", ~0U);     // Execute JS code
  printf("result: %s\n", js_str(js, v));        // result: 7
  return 0;
}