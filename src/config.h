/*
 * Unified config.h for libmodbus (cross-platform)
 * Derived from autotools-generated configs for Linux and Windows
 *
 * This file replaces the generated config.h and is maintained manually
 * in the CMake-based build system.
 */

#pragma once

/* ============================================================
 *  PLATFORM DETECTION
 * ============================================================ */
#if defined(_WIN32) || defined(_WIN64)
#  define LIBMODBUS_PLATFORM_WINDOWS 1
#elif defined(__linux__)
#  define LIBMODBUS_PLATFORM_LINUX 1
#elif defined(__APPLE__)
#  define LIBMODBUS_PLATFORM_MACOS 1
#else
#  define LIBMODBUS_PLATFORM_UNKNOWN 1
#endif

/* ============================================================
 *  COMMON DEFINES
 * ============================================================ */
#define PACKAGE_NAME        "libmodbus"
#define PACKAGE_VERSION     "3.1.11"
#define PACKAGE_STRING      PACKAGE_NAME " " PACKAGE_VERSION
#define PACKAGE_TARNAME     "libmodbus"
#define PACKAGE_BUGREPORT   "https://github.com/freihamer/libmodbus/issues"
#define PACKAGE_URL         "https://libmodbus.org/"
#define VERSION             PACKAGE_VERSION
#define STDC_HEADERS        1

/* ============================================================
 *  LINUX / UNIX CONFIGURATION
 * ============================================================ */
#if LIBMODBUS_PLATFORM_LINUX || LIBMODBUS_PLATFORM_MACOS

#  define HAVE_UNISTD_H          1
#  define HAVE_SYS_TYPES_H       1
#  define HAVE_SYS_STAT_H        1
#  define HAVE_SYS_SOCKET_H      1
#  define HAVE_SYS_IOCTL_H       1
#  define HAVE_SYS_TIME_H        1
#  define HAVE_ARPA_INET_H       1
#  define HAVE_NETDB_H           1
#  define HAVE_NETINET_IN_H      1
#  define HAVE_NETINET_TCP_H     1
#  define HAVE_NETINET_IP_H      1
#  define HAVE_FCNTL_H           1
#  define HAVE_ERRNO_H           1
#  define HAVE_TIME_H            1
#  define HAVE_LIMITS_H          1
#  define HAVE_STRING_H          1
#  define HAVE_STRINGS_H         1
#  define HAVE_STDINT_H          1
#  define HAVE_STDLIB_H          1
#  define HAVE_STDIO_H           1
#  define HAVE_TERMIOS_H         1
#  define HAVE_SELECT            1
#  define HAVE_SOCKET            1
#  define HAVE_GAI_STRERROR      1
#  define HAVE_GETADDRINFO       1
#  define HAVE_GETTIMEOFDAY      1
#  define HAVE_INET_NTOP         1
#  define HAVE_INET_PTON         1
#  define HAVE_DECL_TIOCM_RTS    1
#  define HAVE_DECL_TIOCSRS485   1

/* Extensions normally enabled by autotools */
#  ifndef _GNU_SOURCE
#    define _GNU_SOURCE 1
#  endif
#  ifndef _DEFAULT_SOURCE
#    define _DEFAULT_SOURCE 1
#  endif
#  ifndef _POSIX_C_SOURCE
#    define _POSIX_C_SOURCE 200112L
#  endif

#endif /* UNIX */


/* ============================================================
 *  WINDOWS CONFIGURATION
 * ============================================================ */
#if LIBMODBUS_PLATFORM_WINDOWS

#  define HAVE_ERRNO_H       1
#  define HAVE_FCNTL_H       1
#  define HAVE_INTTYPES_H    1
#  define HAVE_LIMITS_H      1
#  define HAVE_MEMORY_H      1
#  define HAVE_STDINT_H      1
#  define HAVE_STDLIB_H      1
#  define HAVE_STRING_H      1
#  define HAVE_SYS_TYPES_H   1
#  define HAVE_SYS_STAT_H    1
#  define HAVE_TIME_H        1
#  define HAVE_WINSOCK2_H    1
#  define STDC_HEADERS       1
#  define WINVER             0x0501  /* Windows XP and later */
#  define _WIN32_WINNT       0x0501

/* No fork/vfork/select/socket on Windows POSIX */
#  undef  HAVE_UNISTD_H
#  undef  HAVE_SYS_SOCKET_H
#  undef  HAVE_SYS_IOCTL_H
#  undef  HAVE_NETDB_H
#  undef  HAVE_NETINET_TCP_H
#  undef  HAVE_NETINET_IN_H
#  undef  HAVE_ARPA_INET_H
#  undef  HAVE_SELECT
#  undef  HAVE_SOCKET

#endif /* WINDOWS */

/* ============================================================
 *  COMPILER / EXTENSION FLAGS
 * ============================================================ */

/* Enable general POSIX/GNU extensions (needed for IPTOS_LOWDELAY, etc.) */
#ifndef _GNU_SOURCE
#  define _GNU_SOURCE 1
#endif

#ifndef _DEFAULT_SOURCE
#  define _DEFAULT_SOURCE 1
#endif

/* Solaris / HP-UX legacy support (no effect on Linux/Windows) */
#ifndef _POSIX_PTHREAD_SEMANTICS
#  define _POSIX_PTHREAD_SEMANTICS 1
#endif

/* For static linking */
#define LT_OBJDIR ".libs/"

