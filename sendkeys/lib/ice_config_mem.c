#include "ice_config_mem.h"

// based in OpenBSD reallocarray() function http://man.openbsd.org/reallocarray.3
void *ice_config_xmallocarray (size_t nmemb, size_t size) 
{
	if ((nmemb >= MUL_NO_OVERFLOW || size >= MUL_NO_OVERFLOW) && nmemb > 0 && SIZE_MAX / nmemb < size) 
	{
		ICE_CONFIG_DEBUG("integer overflow block");
		exit(0);
	}

	void *ptr = malloc (nmemb*size);

	if (ptr == NULL)
	{	
		ICE_CONFIG_DEBUG("Size error");
		exit(0);
	}
	return ptr;
}

// based in OpenBSD reallocarray() function http://man.openbsd.org/reallocarray.3
void *ice_config_xreallocarray (void *ptr, size_t nmemb, size_t size) 
{
	if ((nmemb >= MUL_NO_OVERFLOW || size >= MUL_NO_OVERFLOW) && nmemb > 0 && SIZE_MAX / nmemb < size) 
	{
		ICE_CONFIG_DEBUG("integer overflow block");
		exit(0);
	}

	void *p = realloc (ptr, nmemb*size);

	if (p == NULL) 
	{

		ICE_CONFIG_DEBUG("Size error");
		exit(0);
	}

	return p;
}

void *ice_config_xmalloc_fatal(size_t size) 
{

	ICE_CONFIG_DEBUG("\n Memory FAILURE...\n size dbg: %lu\n",size);

	exit(0);
}

void *ice_config_xmalloc (size_t size) 
{
	void *ptr = malloc (size);

	if (ptr == NULL) 
		return ice_config_xmalloc_fatal(size);

	return ptr;
}


void ice_config_xfree(void **ptr) 
{
	assert(ptr);
	if( ptr != NULL )
        {
		free(*ptr);
		*ptr=NULL;	
        }
	
}





