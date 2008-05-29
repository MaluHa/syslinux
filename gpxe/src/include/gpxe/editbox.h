#ifndef _GPXE_EDITBOX_H
#define _GPXE_EDITBOX_H

/** @file
 *
 * Editable text box widget
 *
 */

#include <curses.h>
#include <gpxe/editstring.h>

/** An editable text box widget */
struct edit_box {
	/** Editable string */
	struct edit_string string;
	/** Containing window */
	WINDOW *win;
	/** Row */
	unsigned int row;
	/** Starting column */
	unsigned int col;
	/** Width */
	unsigned int width;
	/** First displayed character */
	unsigned int first;
};

extern void init_editbox ( struct edit_box *box, char *buf, size_t len,
			   WINDOW *win, unsigned int row, unsigned int col,
			   unsigned int width ) 
			   __attribute__ (( nonnull (1, 2) ));
extern void draw_editbox ( struct edit_box *box ) __nonnull;
static inline int __pure edit_editbox ( struct edit_box *box, int key ) __nonnull;

/**
 * Edit text box widget
 *
 * @v box		Editable text box widget
 * @v key		Key pressed by user
 * @ret key		Key returned to application, or zero
 *
 * You must call draw_editbox() to update the display after calling
 * edit_editbox().
 *
 */
static inline int edit_editbox ( struct edit_box *box, int key ) {
	return edit_string ( &box->string, key );
}

#endif /* _GPXE_EDITBOX_H */