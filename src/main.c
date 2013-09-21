#include <stdio.h>
#include "hello_world_i18n.h"
int main(int argc, char **argv )
{
	#ifdef ENABLE_NLS
		setlocale (LC_ALL, "");
		bindtextdomain ( GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR );
		bind_textdomain_codeset ( GETTEXT_PACKAGE, "UTF-8" );
		textdomain ( GETTEXT_PACKAGE );
	#endif
	printf("%s-%s : %s", PACKAGE_NAME, PACKAGE_VERSION, _("Hello World\n"));
	return 0;
}
