/*
 * wpa_supplicant/hostapd / common helper functions, etc.
 * Copyright (c) 2002-2006, Jouni Malinen <jkmaline@cc.hut.fi>
 * Copyright (c) 2004-2005, Devicescape Software, Inc.
 * All Rights Reserved.
 */

#ifndef COMMON_H
#define COMMON_H

#include "os.h"

#ifndef _WIN32_WCE
/* WinCE Platform Builder may not always define _WIN32_WCE, so try to figure
 * out whether this is a WinCE build based on couple of other commonly used
 * defines. */
#ifdef _WIN32_CE
#define _WIN32_WCE _WIN32_CE
#else /* _WIN32_CE */
#ifdef UNDER_CE
#define _WIN32_WCE UNDER_CE
#endif /* UNDER_CE */
#endif /* _WIN32_CE */
#endif /* _WIN32_WCE */

#ifdef _WIN32_WCE
#ifndef _WIN32
/* Make sure _WIN32 is defined for WinCE builds if for some reason it is not
 * automatically defined by the toolchain. */
#define _WIN32
#endif /* _WIN32 */
#endif /* _WIN32_WCE */

#ifdef _WIN32
#include <windows.h>
#include "cfgdefs.h"
#define NO_SYS_TYPES_H
#ifndef __MINGW32_VERSION
/* disable warnings about type mismatches to make build listing less
 * voluminuous */
#pragma warning( disable: 4018 ) 
#endif /* __MINGW32_VERSION */
#endif /* _WIN32 */

#ifdef __linux__
#include <endian.h>
#include <byteswap.h>
#endif /* __linux__ */

#if defined(__FreeBSD__) || defined(__NetBSD__)
#include <sys/types.h>
#include <sys/endian.h>
#define __BYTE_ORDER	_BYTE_ORDER
#define	__LITTLE_ENDIAN	_LITTLE_ENDIAN
#define	__BIG_ENDIAN	_BIG_ENDIAN
#define bswap_16 bswap16
#define bswap_32 bswap32
#define bswap_64 bswap64
#endif /* defined(__FreeBSD__) || defined(__NetBSD__) */

#ifdef _WIN32
/* substitution macros -- done to minimize code changes, */
#define strcasecmp _stricmp
#define strncasecmp _strnicmp
#ifndef _WIN64
typedef unsigned int size_t;
#endif
#endif /* _WIN32 */

#ifdef _WIN32_WCE
char *strncpy(char *dest, const char *src, size_t n);
#endif

#ifndef __vxworks
#ifdef CONFIG_NATIVE_WINDOWS
#ifdef _WIN32_WCE
#include <winsock2.h>
#else /* _WIN32_WCE */
#include <winsock.h>
#endif /* _WIN32_WCE */

void wpa_printf_syserr(int level, UINT32 err, char *fmt, ...);


void unicodeToAscii(char *asciiDst, WCHAR *unicodeSrc);

void unicode2Ascii(char *asciiDst, WCHAR *unicodeSrc, int len);

typedef int gid_t;
typedef int socklen_t;

#ifndef MSG_DONTWAIT
#define MSG_DONTWAIT 0 /* not supported */
#endif

#endif /* CONFIG_NATIVE_WINDOWS */

#if defined(__CYGWIN__) || defined(CONFIG_NATIVE_WINDOWS)

#ifdef _MSC_VER
#define inline __inline
#endif /* _MSC_VER */

static inline unsigned short wpa_swap_16(unsigned short v)
{
	return ((v & 0xff) << 8) | (v >> 8);
}

static inline unsigned int wpa_swap_32(unsigned int v)
{
	return ((v & 0xff) << 24) | ((v & 0xff00) << 8) |
		((v & 0xff0000) >> 8) | (v >> 24);
}

#define le_to_host16(n) (n)
#define host_to_le16(n) (n)
#define be_to_host16(n) wpa_swap_16(n)
#define host_to_be16(n) wpa_swap_16(n)
#define le_to_host32(n) (n)
#define be_to_host32(n) wpa_swap_32(n)
#define host_to_be32(n) wpa_swap_32(n)

#else /* __CYGWIN__ */

#if __BYTE_ORDER == __LITTLE_ENDIAN
#define le_to_host16(n) (n)
#define host_to_le16(n) (n)
#define be_to_host16(n) bswap_16(n)
#define host_to_be16(n) bswap_16(n)
#define le_to_host32(n) (n)
#define be_to_host32(n) bswap_32(n)
#define host_to_be32(n) bswap_32(n)
#elif __BYTE_ORDER == __BIG_ENDIAN
#define le_to_host16(n) bswap_16(n)
#define host_to_le16(n) bswap_16(n)
#define be_to_host16(n) (n)
#define host_to_be16(n) (n)
#define le_to_host32(n) bswap_32(n)
#define be_to_host32(n) (n)
#define host_to_be32(n) (n)
#ifndef WORDS_BIGENDIAN
#define WORDS_BIGENDIAN
#endif
#else
#error Could not determine CPU byte order
#endif

#endif /* __CYGWIN__ */

/* Macros for handling unaligned 16-bit variables */
#define WPA_GET_BE16(a) ((u16) (((a)[0] << 8) | (a)[1]))
#define WPA_PUT_BE16(a, val)			\
	do {					\
		(a)[0] = ((u16) (val)) >> 8;	\
		(a)[1] = ((u16) (val)) & 0xff;	\
	} while (0)

#define WPA_GET_BE64(a) ((((u64) (a)[0]) << 56) | (((u64) (a)[1]) << 48) | \
			 (((u64) (a)[2]) << 40) | (((u64) (a)[3]) << 32) | \
			 (((u64) (a)[4]) << 24) | (((u64) (a)[5]) << 16) | \
			 (((u64) (a)[6]) << 8) | ((u64) (a)[7]))

#define WPA_GET_LE16(a) ((u16) (((a)[1] << 8) | (a)[0]))
#define WPA_PUT_LE16(a, val)			\
	do {					\
		(a)[1] = ((u16) (val)) >> 8;	\
		(a)[0] = ((u16) (val)) & 0xff;	\
	} while (0)

#define WPA_GET_BE24(a) ((((u32) (a)[0]) << 16) | (((u32) (a)[1]) << 8) | \
			 ((u32) (a)[2]))
#define WPA_PUT_BE24(a, val)				\
	do {						\
		(a)[0] = (u8) (((u32) (val)) >> 16);	\
		(a)[1] = (u8) (((u32) (val)) >> 8);	\
		(a)[2] = (u8) (((u32) (val)) & 0xff);	\
	} while (0)

#define WPA_GET_BE32(a) ((((u32) (a)[0]) << 24) | (((u32) (a)[1]) << 16) | \
			 (((u32) (a)[2]) << 8) | ((u32) (a)[3]))
#define WPA_PUT_BE32(a, val)				\
	do {						\
		(a)[0] = (u8) (((u32) (val)) >> 24);	\
		(a)[1] = (u8) (((u32) (val)) >> 16);	\
		(a)[2] = (u8) (((u32) (val)) >> 8);	\
		(a)[3] = (u8) (((u32) (val)) & 0xff);	\
	} while (0)

#define WPA_GET_LE32(a) ((((u32) (a)[3]) << 24) | (((u32) (a)[2]) << 16) | \
			 (((u32) (a)[1]) << 8) | ((u32) (a)[0]))
#define WPA_PUT_LE32(a, val)			\
	do {					\
		(a)[3] = ((u32) (val)) >> 24;	\
		(a)[2] = ((u32) (val)) >> 16;	\
		(a)[1] = ((u32) (val)) >> 8;	\
		(a)[0] = ((u32) (val)) & 0xff;	\
	} while (0)

#define WPA_GET_LE64(a) ((((u64) (a)[7]) << 56) | (((u64) (a)[6]) << 48) | \
			 (((u64) (a)[5]) << 40) | (((u64) (a)[4]) << 32) | \
			 (((u64) (a)[3]) << 24) | (((u64) (a)[2]) << 16) | \
			 (((u64) (a)[1]) << 8) | ((u64) (a)[0]))
#define WPA_PUT_LE64(a, val)			\
	do {					\
		(a)[7] = (u8) (((u64) (val)) >> 56);	\
		(a)[6] = (u8) (((u64) (val)) >> 48);	\
		(a)[5] = (u8) (((u64) (val)) >> 40);	\
		(a)[4] = (u8) (((u64) (val)) >> 32);	\
		(a)[3] = (u8) (((u64) (val)) >> 24);	\
		(a)[2] = (u8) (((u64) (val)) >> 16);	\
		(a)[1] = (u8) (((u64) (val)) >> 8);	\
		(a)[0] = (u8) (((u64) (val)) & 0xff);	\
	} while (0)

#define WPA_GET_BE32(a) ((((u32) (a)[0]) << 24) | (((u32) (a)[1]) << 16) | \
			 (((u32) (a)[2]) << 8) | ((u32) (a)[3]))
#define WPA_PUT_BE32(a, val)				\
	do {						\
		(a)[0] = (u8) (((u32) (val)) >> 24);	\
		(a)[1] = (u8) (((u32) (val)) >> 16);	\
		(a)[2] = (u8) (((u32) (val)) >> 8);	\
		(a)[3] = (u8) (((u32) (val)) & 0xff);	\
	} while (0)


#ifndef ETH_ALEN
#define ETH_ALEN 6
#endif

#ifdef _MSC_VER
typedef UINT64 u64;
typedef UINT32 u32;
typedef UINT16 u16;
typedef UINT8 u8;
typedef INT64 s64;
typedef INT32 s32;
typedef INT16 s16;
typedef INT8 s8;
#define WPA_TYPES_DEFINED
#endif /* _MSC_VER */

#ifdef __vxworks
typedef unsigned long long u64;
typedef UINT32 u32;
typedef UINT16 u16;
typedef UINT8 u8;
typedef long long s64;
typedef INT32 s32;
typedef INT16 s16;
typedef INT8 s8;
#define WPA_TYPES_DEFINED
#endif /* __vxworks */

#ifndef WPA_TYPES_DEFINED
#ifdef CONFIG_USE_INTTYPES_H
#include <inttypes.h>
#else
#include <stdint.h>
#endif
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef int64_t s64;
typedef int32_t s32;
typedef int16_t s16;
typedef int8_t s8;
#define WPA_TYPES_DEFINED
#endif /* !WPA_TYPES_DEFINED */

#else /* __vxworks */

#include <vxWorks.h>
#include <sys/times.h>

#include "portability.h"

#define SWAP16(n)	((((n) & 0xff00) >> 8) | (((n) & 0x00ff) << 8))

static inline unsigned int wpa_swap_32(unsigned int v)
{
	return ((v & 0xff) << 24) | ((v & 0xff00) << 8) |
		((v & 0xff0000) >> 8) | (v >> 24);
}

#if _BYTE_ORDER == _LITTLE_ENDIAN
#define le_to_host16(n) (n)
#define host_to_le16(n) (n)
#define be_to_host16(n) SWAP16(n)
#define host_to_be16(n) SWAP16(n)
#define le_to_host32(n) (n)
#define be_to_host32(n) wpa_swap_32(n)
#define host_to_be32(n) wpa_swap_32(n)
#else
#define le_to_host16(n) SWAP16(n)
#define host_to_le16(n) SWAP16(n)
#define be_to_host16(n) (n)
#define host_to_be16(n) (n)
#define le_to_host32(n) wpa_swap_32(n)
#define be_to_host32(n) (n)
#define host_to_be32(n) (n)
#endif

typedef unsigned long long u64;
typedef UINT32 u32;
typedef UINT16 u16;
typedef UINT8 u8;
typedef long long s64;
typedef INT32 s32;
typedef INT16 s16;
typedef INT8 s8;

#endif /* __vxworks */
#define hostapd_get_rand os_get_random
int hwaddr_aton(const char *txt, u8 *addr);
int hexstr2bin(const char *hex, u8 *buf, size_t len);
void inc_byte_array(u8 *counter, size_t len);
void wpa_get_ntp_timestamp(u8 *buf);


#ifdef __GNUC__
#define PRINTF_FORMAT(a,b) __attribute__ ((format (printf, (a), (b))))
#define STRUCT_PACKED __attribute__ ((packed))
#else
#define PRINTF_FORMAT(a,b)
#define STRUCT_PACKED
#endif


/* Debugging function - conditional printf and hex dump. Driver wrappers can
 *  use these for debugging purposes. */

enum { MSG_MSGDUMP, MSG_DEBUG, MSG_INFO, MSG_WARNING, MSG_ERROR };

#ifdef CONFIG_NO_STDOUT_DEBUG

#define wpa_debug_print_timestamp() do { } while (0)
#define wpa_printf(args...) do { } while (0)
#define wpa_hexdump(l,t,b,le) do { } while (0)
#define wpa_hexdump_key(l,t,b,le) do { } while (0)
#define wpa_hexdump_ascii(l,t,b,le) do { } while (0)
#define wpa_hexdump_ascii_key(l,t,b,le) do { } while (0)

#else /* CONFIG_NO_STDOUT_DEBUG */

/**
 * wpa_debug_printf_timestamp - Print timestamp for debug output
 *
 * This function prints a timestamp in <seconds from 1970>.<microsoconds>
 * format if debug output has been configured to include timestamps in debug
 * messages.
 */
void wpa_debug_print_timestamp(void);

/**
 * wpa_printf - conditional printf
 * @level: priority level (MSG_*) of the message
 * @fmt: printf format string, followed by optional arguments
 *
 * This function is used to print conditional debugging and error messages. The
 * output may be directed to stdout, stderr, and/or syslog based on
 * configuration.
 *
 * Note: New line '\n' is added to the end of the text when printing to stdout.
 */
void wpa_printf(int level, char *fmt, ...)
PRINTF_FORMAT(2, 3);

/**
 * wpa_hexdump - conditional hex dump
 * @level: priority level (MSG_*) of the message
 * @title: title of for the message
 * @buf: data buffer to be dumped
 * @len: length of the buf
 *
 * This function is used to print conditional debugging and error messages. The
 * output may be directed to stdout, stderr, and/or syslog based on
 * configuration. The contents of buf is printed out has hex dump.
 */
void wpa_hexdump(int level, const char *title, const u8 *buf, size_t len);

/**
 * wpa_hexdump_key - conditional hex dump, hide keys
 * @level: priority level (MSG_*) of the message
 * @title: title of for the message
 * @buf: data buffer to be dumped
 * @len: length of the buf
 *
 * This function is used to print conditional debugging and error messages. The
 * output may be directed to stdout, stderr, and/or syslog based on
 * configuration. The contents of buf is printed out has hex dump. This works
 * like wpa_hexdump(), but by default, does not include secret keys (passwords,
 * etc.) in debug output.
 */
void wpa_hexdump_key(int level, const char *title, const u8 *buf, size_t len);

/**
 * wpa_hexdump_ascii - conditional hex dump
 * @level: priority level (MSG_*) of the message
 * @title: title of for the message
 * @buf: data buffer to be dumped
 * @len: length of the buf
 *
 * This function is used to print conditional debugging and error messages. The
 * output may be directed to stdout, stderr, and/or syslog based on
 * configuration. The contents of buf is printed out has hex dump with both
 * the hex numbers and ASCII characters (for printable range) are shown. 16
 * bytes per line will be shown.
 */
void wpa_hexdump_ascii(int level, const char *title, const u8 *buf,
		       size_t len);

/**
 * wpa_hexdump_ascii_key - conditional hex dump, hide keys
 * @level: priority level (MSG_*) of the message
 * @title: title of for the message
 * @buf: data buffer to be dumped
 * @len: length of the buf
 *
 * This function is used to print conditional debugging and error messages. The
 * output may be directed to stdout, stderr, and/or syslog based on
 * configuration. The contents of buf is printed out has hex dump with both
 * the hex numbers and ASCII characters (for printable range) are shown. 16
 * bytes per line will be shown. This works like wpa_hexdump_ascii(), but by
 * default, does not include secret keys (passwords, etc.) in debug output.
 */
void wpa_hexdump_ascii_key(int level, const char *title, const u8 *buf,
			   size_t len);

#endif /* CONFIG_NO_STDOUT_DEBUG */


#ifdef EAPOL_TEST
#define WPA_ASSERT(a)						       \
	do {							       \
		if (!(a)) {					       \
			printf("WPA_ASSERT FAILED '" #a "' "	       \
			       "%s %s:%d\n",			       \
			       __FUNCTION__, __FILE__, __LINE__);      \
			exit(1);				       \
		}						       \
	} while (0)
#else
#define WPA_ASSERT(a) do { } while (0)
#endif


#ifdef _MSC_VER
#undef snprintf
#define snprintf _snprintf
#undef vsnprintf
#define vsnprintf _vsnprintf
#undef close
#define close closesocket
#undef strdup
#define strdup _strdup
#endif /* _MSC_VER */


#ifdef CONFIG_ANSI_C_EXTRA

/*
 * Following non-ANSI C functions may need to be defined either as a macro to
 * native function with identical behavior or as a separate implementation,
 * e.g., in common.c or in a new OS / C library specific file, if needed.
 */

#if 0
/* List of used C library functions */

/* Memory allocation */
void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);

/* Memory/string processing */
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);

char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);
int strcmp(const char *s1, const char *s2);
size_t strlen(const char *s);
char *strncpy(char *dest, const char *src, size_t n);
char *strstr(const char *haystack, const char *needle);
char *strdup(const char *s);

/* printf like functions for writing to memory buffer */
int snprintf(char *str, size_t size, const char *format, ...);
int vsnprintf(char *str, size_t size, const char *format, va_list ap);
/* vsnprintf is only used for wpa_msg(); not needed if ctrl_iface is not used
 * and stdout debugging is disabled
 */
#endif

#ifndef _WIN32
/* strdup - used in number of places - simple example implementation in
 * common.c */
char * strdup(const char *s);

/* strcasecmp - used in couple of places; not critical, so can be defined to
 * use strcmp instead */
#if 0
int strcasecmp(const char *s1, const char *s2);
#else
#define strcasecmp strcmp
#endif

/* strncasecmp - used only in wpa_cli.c; not critical, so can be defined to
 * use strncmp instead */
#if 0
int strncasecmp(const char *s1, const char *s2, size_t n);
#else
#define strncasecmp strncmp
#endif
#endif /* _WIN32 */

#ifndef _WIN32
/* snprintf - used in number of places; sprintf() is _not_ a good replacement
 * due to possible buffer overflow; see, e.g.,
 * http://www.ijs.si/software/snprintf/ for portable implementation of
 * snprintf. */
int snprintf(char *str, size_t size, const char *format, ...);

/* vsnprintf - only used for wpa_msg() in wpa_supplicant.c */
int vsnprintf(char *str, size_t size, const char *format, va_list ap);
#endif /* _WIN32 */

/* getopt - only used in main.c */
int getopt(int argc, char *const argv[], const char *optstring);
extern char *optarg;
extern int optind;

/* gid_t - used in config.h, just typedef it to int here */

#ifndef CONFIG_NO_GID_T_TYPEDEF
#ifdef CONFIG_CTRL_IFACE
#ifndef CONFIG_CTRL_IFACE_UDP
#ifndef __gid_t_defined
#ifndef _GID_T
typedef int gid_t;
#endif
#endif
#endif
#endif
#endif

#ifndef CONFIG_NO_SOCKLEN_T_TYPEDEF
#ifndef __socklen_t_defined
typedef int socklen_t;
#endif
#endif

/* inline - define as __inline or just define it to be empty, if needed */
#ifdef CONFIG_NO_INLINE
#define inline
#else
#define inline __inline
#endif

#ifndef __func__
#define __func__ "__func__ not defined"
#endif

#ifndef bswap_16
#define bswap_16(a) ((((u16) (a) << 8) & 0xff00) | (((u16) (a) >> 8) & 0xff))
#endif

#ifndef bswap_32
#define bswap_16(a) ((((u16) (a) << 8) & 0xff00) | (((u16) (a) >> 8) & 0xff))
#define bswap_16(a) ((((u16) (a) << 8) & 0xff00) | (((u16) (a) >> 8) & 0xff))
#define bswap_32(a) ((((u32) (a) << 24) & 0xff000000) | \
		     (((u32) (a) << 8) & 0xff0000) | \
     		     (((u32) (a) >> 8) & 0xff00) | \
     		     (((u32) (a) >> 24) & 0xff))
#endif

#ifndef MSG_DONTWAIT
#define MSG_DONTWAIT 0
#endif

#ifdef _WIN32_WCE
void perror(const char *s);
#endif /* _WIN32_WCE */

#endif /* CONFIG_ANSI_C_EXTRA */

#endif /* COMMON_H */