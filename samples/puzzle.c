/*
<html>
<header>
<title>
</title>
<body>
<pre>
*/

#define has_been_visited(m,n) prison[m]


/*5: */
#line 77 "puzzle.w"

#include <stdio.h>

/*:5 */
#line 29 "puzzle.w"

/*3: */
#line 50 "puzzle.w"

int prison[6][6] =
{
  {-1, -1, -1, -1, -1, -1},
  {-1, 0, 0, 0, 0, -1},
  {-1, 0, 0, 0, 0, -1},
  {-1, 0, 0, 0, 0, -1},
  {-1, 0, 0, 0, 0, -1},
  {-1, -1, -1, -1, -1, -1}
};

      /*:3 *//*10: */
#line 136 "puzzle.w"
int number_of_cells_visited = 0;
/*:10 */
#line 30 "puzzle.w"

/*6: */
#line 82 "puzzle.w"

void 
print_prison (void)
{
  register int i, j;
  for (i = 1; i <= 4; i++)
    for (j = 1; j <= 4; j++)
      printf ("%2d%c", prison[i][j], j == 4 ? '\n' : '\t');
  putc ('\n', stdout);
}

      /*:6 *//*7: */
#line 111 "puzzle.w"

int
solve (register int m, register int n)
{
  if (has_been_visited (m, n))
    fail;
/*8: */
#line 125 "puzzle.w"

  if (m == 4 && n == 4)
    {
      if (number_of_cells_visited == 15)
	succeed;
      else
	fail;
    }

/*:8 */
#line 117 "puzzle.w"
  ;
  prison[m][n] = ++number_of_cells_visited;
  if (solve (m + 1, n) || solve (m, n + 1) || solve (m - 1, n) || solve (m, n - 1))
    succeed;
/*9: */
#line 132 "puzzle.w"

  --number_of_cells_visited;
  prison[m][n] = 0;

/*:9 */
#line 121 "puzzle.w"
  ;
  fail;
}

/*:7 */
#line 31 "puzzle.w"

/*4: */
#line 68 "puzzle.w"

void
main (void)
{
  if (solve (1, 1))
    print_prison ();
  else
    fprintf (stderr, "Impossible\n");
}

/*:4 */
#line 32 "puzzle.w"


/*:2 */
/*
</pre>
</body>
</html>