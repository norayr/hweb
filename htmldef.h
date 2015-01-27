#ifndef __HTMLDEF_H__
#define __HTMLDEF_H__
/************************************************************************/
/* 
<HTML>
<TITLE>HTMLDEF_H </TITLE>
<H1> Header:  HTMLDEF_H </H1><UL>
<LI> Purpose:     to define constants for HTML extract tool
<LI> Language/Compiler/O/S:   ANSI C, SCO CC or GNU gcc:  UNIX 
                              BCC 3.0:  DOS/Windows 3.1 
<LI> Author:      Steve Gibson
<LI> Date:        4/29/99
<LI> Revision History [from RCS]
<LI> after htmlextract by Wade Hampton 
<UL><PRE>

 $Log: htmldef.h,v $
 * Revision 1.1  1999/04/26  15:13:02  steveg
 * Initial revision
 *

</PRE>
</UL><H2> Notes: </H1><OL>
<LI>HTML blocks are bounded by &lt;HTML&gt; and &lt;/HTML&gt;
<LI>&lt; and &gt; in HTML comment should be entered as &amp;lt and &amp;gt
<LI>&amp; in HTML comment should be entered as &amp;amp
<LI>This is in the tnote directory, it is both an example and
    the code to the functional program.
</OL></UL>
</HTML> 
 * HTML format notes on <, >, &:
 *   > in HTML comment should be entered as &gt
 *   < in HTML comment should be entered as &lt
 *   & in HTML comment should be entered as &amp
 * pre-formatted text between <PRE> and </PRE>
 * <UL> is bulleted list, <OL> is numbered list (</UL> or </OL> to end)
 * <P> is page break
 * <HR> is hard break (line between text)
 * please see beginners guide to HTML for more details....
 *----------------------------------------------------------------------*/
/* TYPES- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* INCLUDE FILES- - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* CONSTANTS- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* each block of HTML text must start with:  <html> or <HTML> */
#define HTML_START1 "<pre>"
#define HTML_START2 "<PRE>"

/* each block of HTML text must end with:  </html> or </HTML> */
#define HTML_END1 "</pre>"
#define HTML_END2 "</PRE>"

/* LOCAL DATA - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* EXTERNAL PROCEDURES- - - - - - - - - - - - - - - - - - - - - - - - - */
/* EXTERNAL DATA- - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* PROTOTYPES - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*
<HTML> 
<CENTER><HR> Copyright (C) 1999, Steve Gibson (under GPL) </CENTER>
</HTML> 
 */
/************************************************************************/
#endif
