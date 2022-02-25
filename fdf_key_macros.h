#ifndef FDF_KEY_MACROS_H
# define FDF_KEY_MACROS_H

# ifdef __linux__
#  define P 0x0070
#  define I 0x0069
#  define ESC 0xff1b
#  define LFT 0xff51
#  define RT 0xff53
#  define UP 0xff52
#  define DWN 0xff54
#  define A 0x0061
#  define S 0x0073
#  define D 0x0064
#  define F 0x0066
#  define J 0x006a
#  define K 0x006b
#  define L 0x006c 
#  define COL 0x003b
#  define PLS 0x003d
#  define MNS 0x002d
# else
#  define P 35
#  define I 34
#  define ESC 53
#  define LFT 123 
#  define RT 124
#  define UP 126
#  define DWN 125
#  define A 0
#  define S 1
#  define D 2
#  define F 3
#  define J 38
#  define K 40
#  define L 37
#  define COL 41
#  define PLS 24
#  define MNS 27

# endif
#endif
