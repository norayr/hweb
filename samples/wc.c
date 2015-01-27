/*
<html>
<header>
<title>
</title>
<body>
<pre>
*/

#define OK 0
#define usage_error 1
#define cannot_open_file 2 \

#define size BUFSIZ \

#define print_count(n) printf("%8ld",n)  \

/*2: */


/*3: */


#include <stdio.h>

/*:3 */


/*4: */


     int status = OK;
     char *prog_name;

      /*:4 *//*14: */


     long tot_word_count, tot_line_count, tot_char_count;


/*:14 */


/*20: */


wc_print (which, char_count, word_count, line_count)
     char *which;
     long char_count, word_count, line_count;
{
  while (*which)
    switch (*which++)
      {
      case 'l':
	print_count (line_count);
	break;
      case 'w':
	print_count (word_count);
	break;
      case 'c':
	print_count (char_count);
	break;
      default:
	if ((status & usage_error) == 0)
	  {
	    fprintf (stderr, "\nUsage: %s [-lwc] [filename ...]\n", prog_name);

	    status |= usage_error;
	  }
      }
}

/*:20 */


/*5: */
/*
</pre>
<a name="main">main</a>
<pre>
*/
main (argc, argv)
     int argc;
     char **argv;
{
/*6: */


  int file_count;
  char *which;
  int silent = 0;

  /*:6 *//*9: */


  int fd = 0;

  /*:9 *//*12: */


  char buffer[buf_size];
  register char *ptr;
  register char *buf_end;
  register int c;
  int in_word;
  long word_count, line_count, char_count;


/*:12 */


  prog_name = argv[0];
/*7: */


  which = "lwc";
  if (argc > 1 && *argv[1] == '-')
    {
      argv[1]++;
      if (*argv[1] == 's')
	silent = 1, argv[1]++;
      if (*argv[1])
	which = argv[1];
      argc--;
      argv++;
    }
  file_count = argc - 1;

/*:7 */

  ;
/*8: */


  argc--;
  do
    {
/*10: */


      if (file_count > 0 && (fd = open (*(++argv), READ_ONLY)) < 0)
	{
	  fprintf (stderr, "%s: cannot open file %s\n", prog_name, *argv);

	  status |= cannot_open_file;
	  file_count--;
	  continue;
	}

/*:10 */

      ;
/*13: */

      ptr = buf_end = buffer;
      line_count = word_count = char_count = 0;
      in_word = 0;

/*:13 */

      ;
/*15: */


      while (1)
	{
/*16: */


	  if (ptr >= buf_end)
	    {
	      ptr = buffer;
	      c = read (fd, ptr, buf_size);
	      if (c <= 0)
		break;
	      char_count += c;
	      buf_end = buffer + c;
	    }

/*:16 */

	  ;
	  c = *ptr++;
	  if (c > ' ' && c < 0177)
	    {
	      if (!in_word)
		{
		  word_count++;
		  in_word = 1;
		}
	      continue;
	    }
	  if (c == '\n')
	    line_count++;
	  else if (c != ' ' && c != '\t')
	    continue;
	  in_word = 0;
	}

/*:15 */

      ;
/*17: */


      if (!silent)
	{
	  wc_print (which, char_count, word_count, line_count);
	  if (file_count)
	    printf (" %s\n", *argv);
	  else
	    printf ("\n");
	}

/*:17 */

      ;
/*11: */

      close (fd);

/*:11 */
      ;
/*18: */


      tot_line_count += line_count;
      tot_word_count += word_count;
      tot_char_count += char_count;

/*:18 */

      ;
    }
  while (--argc > 0);

/*:8 */

  ;
/*19: */


  if (file_count > 1 || silent)
    {
      wc_print (which, tot_char_count, tot_word_count, tot_line_count);
      if (!file_count)
	printf ("\n");
      else
	printf (" total in %d file%s\n", file_count, file_count > 1 ? "s" : "");
    }

/*:19 */

  ;
  exit (status);
}

/*:5 */


/*:2 */
/*
</pre>
</body>
</html>
*/