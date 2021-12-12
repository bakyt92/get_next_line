#ifndef INC_03_GET_NEXT_LINE_GET_NEXT_LINE_H
# define INC_03_GET_NEXT_LINE_GET_NEXT_LINE_H
# include <sys/stat.h>
# include <unistd.h>

#ifdefined BUFFER_SIZE
#if BUFFER_SIZE < 0
# undef BUFFER_SIZE
# define BUFFER_SIZE 0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif



# endif
