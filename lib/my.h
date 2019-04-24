/*
** EPITECH PROJECT, 2019
** My
** File description:
** header
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <math.h>

/*
**  IO_BUF
*/

#define MY_BUFSIZE (1024)

typedef struct my_iobuf {
    int cnt;
    char *ptr;
    char *base;
    int fd;
} my_FILE;

#define MY_IOB (*my_iob_location())

long long my_atoi(char const *nptr);
float my_atof(char const *nptr);
int my_putnbr(int nb);
char *my_itoa(int nb);
int my_putchar(char c);
int my_putstr(char const *str);
void *my_calloc(size_t nmemb, size_t size);
void *my_realloc(void *ptr, size_t size);
void *my_memset(void *s, int c, size_t n);
void *my_memcpy(void *dest, const void *src);
char *my_strcpy(char *dest, char const *src);
void *my_memncpy(void *dest, const void *src, size_t n);
char *my_strncpy(char *dest, char const *src, size_t n);
int my_memcmp(const void *s1, const void *s2);
int my_memncmp(const void *s1, const void *s2, size_t n);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);
size_t my_memlen(void const *ptr, size_t size);
size_t my_strlen(char const *s);
void *my_memndup(const void *src, size_t n);
char *my_strndup(char const *src, size_t n);
void *my_memdup(const void *src);
char *my_strdup(char const *src);
void *my_memcat(void *dest, void const *src);
char *my_strcat(char *dest, char const *src);
void *my_memchr(const void *str, int c);
char *my_strchr(char const *s, int c);
void *my_memnchr(const void *s, int c, size_t n);
char *my_strnchr(char const *s, int c, size_t n);
void *my_memmem(void const *hay, size_t h_len, void const *nee, size_t n_len);
char *my_strstr(char const *haystack, char const *needle);
char *my_format(char const *format, ...);

my_FILE *my_iob_location(void);
void my_iob_init(int fd);
void my_iob_destroy(void);
void my_iob_putc(char c);
void my_iob_flush(void);
char my_iob_getc(void);

int my_printf(const char *format, ...);
int my_fprintf(FILE *stream, char const *format, ...);
int my_dprintf(int fd, char const *format, ...);
int my_sprintf(char *str, char const *format, ...);
int my_snprintf(char *str, size_t size, char const *format, ...);

int my_vprintf(const char *format, va_list ap);
int my_vfprintf(FILE *stream, char const *format, va_list ap);
int my_vdprintf(int fd, const char *format, va_list ap);
int my_vsprintf(char *str, const char *format, va_list ap);
int my_vsnprintf(char *str, size_t size, char const *format, va_list ap);

int my_sscanf(const char *str, const char *format, ...);

int my_vsscanf(const char *str, const char *format, va_list ap);

#endif /* !MY_H_ */