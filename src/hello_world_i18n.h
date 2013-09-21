#ifndef HELLO_WORLD_118N__
	#define HELLO_WORLD_118N__
	#ifdef HAVE_CONFIG_H
		#include <config.h>
	#endif
	#ifdef ENABLE_NLS
		#include <locale.h>
		#define _(str)(const char*)gettext(str)
	#else
		#define _(str)(str)
	#endif
#endif /*HELLO_WORLD_118N__*/

