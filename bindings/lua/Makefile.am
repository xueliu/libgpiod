

lua_LTLIBRARIES = libgpiodlua.la

libgpiodlua_la_SOURCES = libgpiod.c

libgpiodlua_la_CFLAGS = -I$(top_srcdir)/include/ -I/usr/include/lua5.1
libgpiodlua_la_CFLAGS += -Wall -Wextra -g @LUA_INCLUDE@
libgpiodlua_la_LDFLAGS = -module -avoid-version
libgpiodlua_la_LIBADD = $(top_builddir)/src/lib/libgpiod.la lua5.1 #$(LUA_LIB)
