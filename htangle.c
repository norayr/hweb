/************************************************************************/
/* 
<HTML>
<HEADER>
<TITLE>HTANGLE</TITLE>
</HEADER>
<BODY>
<a name="includes">includes</a>
<pre>
 *----------------------------------------------------------------------*/
/* TYPES - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - */
/* INCLUDE FILES - - - - - - - - - - - - - - - - - -  - - - - - - - - - */
#include <stdio.h>
#include <string.h>
#include "htmldef.h"

#include <sys/types.h>
#include <time.h>

/* CONSTANTS- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *
</pre>
<P>RCS ID String:  $Id: htangle.c,v 1.4 1999/04/26 15:43:43 steveg Exp $<P>
<a name="defines">defines</a>
<pre>
*/
static char rcsid[] = "$Id: htangle.c,v 1.4 1999/04/26 15:43:43 steveg Exp $";   

#define TRUE (1==1)
#define FALSE (1==0)
/* #define INFILE    stdin */
#define OUTFILE   stdout
#define PROG_NAME "htangle"

/* LOCAL DATA - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

FILE *INFILE = stdin;  /* input file -- typ. stdin */

/* EXTERNAL PROCEDURES- - - - - - - - - - - - - - - - - - - - - - - - - */
/* EXTERNAL DATA- - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* PROTOTYPES - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*
</pre>
<CENTER><HR>  Copyright (C) 1999 Steve Gibson (under GPL) </CENTER>
<a name="PrintHelp">PrintHelp</a>
<pre> 
 ************************************************************************/
void PrintHelp()
{
  fprintf (stderr, PROG_NAME ":  Program to remove HTML from .c or .h\n");
  fprintf (stderr, "  Usage:  htangle -h  -- this help\n");
  fprintf (stderr, "          -iifile >ofile  -- specifiy input file\n");
  fprintf (stderr, "          <ifile >ofile   -- stdin for input\n");
  fprintf (stderr, "  Version:  %s\n", rcsid);
}
/************************************************************************
</pre>
<a name="PrintVersion">PrintVersion</a>
<pre> 
 ************************************************************************/
void PrintVersion ()
{
  fprintf (stderr, PROG_NAME ":  version:  %s\n", rcsid);
}

/************************************************************************
</pre>
<a name="Main">Main</a>
<pre>
 ************************************************************************/

int main (argc, argv)
int argc;
char *argv[];
{

char caLineIn[1024];
int  iHtmlFlag  = FALSE;
char *pszInFile = "stdin";
int  iVerbose   = TRUE;
int  iLine      = 0;
int  iHLines    = 0;
time_t lTime;   
char   *pszAsciiTime;
int    ii;

  /* get current time into a string */
  time (&lTime);
  pszAsciiTime = ctime(&lTime);

  /* check cmd line args */
  if (argc > 1)
  {
    for (ii=1; ii<argc; ii++)
    {
      if (argv[ii][0] == '-')
      {
	switch (argv[ii][1])
	{
	case 'h':
	case 'H':
	case '?':
	  PrintHelp();
	  exit(0);
	  break;
	case 'V':
	  PrintVersion();
	  exit(0);
	  break;
	case 'i':
	  pszInFile = &argv[ii][2];
	  break;
	default:
	  PrintHelp();
	  exit(1);
	  break;
	}
      }
    }
  }

  /* try to open input file if not stdin */
  if (strcmp (pszInFile, "stdin") != 0)
  {
    INFILE = fopen (pszInFile, "r");
    if (INFILE == NULL)
    {
      fprintf (stderr, "Error opening %s, exiting\n", pszInFile);
      exit(1);
    }
  }
	  
  /* print HTML header info */
  printf ("/* htangle output \n");
/*   printf ("<BODY>\n"); -- let user do this */
  printf ("<!code:  extracted from %s by %s>\n", pszInFile, PROG_NAME);
  printf ("<!        on date %s> \n", pszAsciiTime);
  iHtmlFlag = FALSE;
  while (fgets(caLineIn, sizeof(caLineIn)-2, INFILE) != NULL)
  {
    iLine++;
    /* if HTML off, check for start of HTML and if so, set flag */
    if (iHtmlFlag == FALSE)
    {
      if ((strncmp(HTML_START1, caLineIn, sizeof(HTML_START1)-1) == 0) ||
          (strncmp(HTML_START2, caLineIn, sizeof(HTML_START2)-1) == 0))
      {
        iHtmlFlag = TRUE;
        if (iVerbose == TRUE)
          fprintf (stderr, "%05d pre ON\n", iLine);
      }
    } 
    /* if HTML on, check for end of HTML and if so, reset flag */
    else 
    {
      if ((strncmp(HTML_END1, caLineIn, sizeof(HTML_END1)-1) == 0) ||
          (strncmp(HTML_END2, caLineIn, sizeof(HTML_END2)-1) == 0))
      {
        iHtmlFlag = FALSE;
        if (iVerbose == TRUE)
          fprintf (stderr, "%05d pre OFF\n", iLine);
      }
      if (iHtmlFlag == TRUE)
      {
        fputs (caLineIn, OUTFILE);
	iHLines++;
      }
    } 
  } 
/*  printf ("</BODY>\n"); -- let user do this */
  printf (" end of htangle output */");
  if (iVerbose == TRUE)
  {
    fprintf (stderr, "Total lines:  %d, CODE lines:  %d\n", iLine, iHLines);
  }

  exit(0);

}


/*
</pre>
<HTML> 
</BODY>
</HTML> 
*/
