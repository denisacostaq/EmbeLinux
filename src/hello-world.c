#include<stdio.h>

#ifdef HAVE_CONFIG_H
	#include<config.h>
#else
	#error No es posible usar el archivo de configuracion de proyecto.
#endif

int main(int argc, char **argv )
{
	printf("%s-%s : Hello world\n" , PACKAGE_NAME, PACKAGE_VERSION) ;
	return 0;
}
