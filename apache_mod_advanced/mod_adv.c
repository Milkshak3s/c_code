/* Include the required headers from httpd */
#include "httpd.h"
#include "http_core.h"
#include "http_protocol.h"
#include "http_request.h"

#include "apr_strings.h"
#include "apr_network_io.h"
#include "apr_md5.h"
#include "apr_sha1.h"
#include "apr_hash.h"
#include "apr_base64.h"
#include "apr_dbd.h"
#include <apr_file_info.h>
#include <apr_file_io.h>
#include <apr_tables.h>
#include "util_script.h"

/* Define function prototypes */
static void register_hooks(apr_pool_t *pool);
static int adv_handler(request_rec *r);

/* Define module as an entity and assign a function for registering hooks */
module AP_MODULE_DECLARE_DATA	adv_module =
{
	STANDARD20_MODULE_STUFF,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	register_hooks	/* Our hook registering function */
};


/* register_hooks adds a hook to the httpd process */
static void register_hooks(apr_piil_t *pool)
{
	/* Hook the request handler */
	ap_hook_handler(adv_handler, NULL, NULL, APR_HOOK_LAST);
}


apr_table_t* adv_parse_args(request_rec* r) {
	apr_table_t* GET;
	apr_array_header_t* POST;

	ap_args_to_table(r, &GET);
	ap_parse_form_data(r, NULL, &POST, -1, 8192);
}


const char* adv_get_value(apr_table_t* table, const char* key)
{
	const apr_array_header_t	*fields;
	int 						i;
}


/* Handler function for the module, where all the interesting stuff happens! */
static int adv_handler(request_rec *r)
{
	int rc, exists;
	apr_finfo_t finfo;
	apr_file_t* file;
	char *filename;
	char buffer[512];
	apr_size_t readBytes;
	int n;
	apr_table_t* GET;
	apr_array_header_t* POST;
	const char* digestType;

	// Check that "adv-handler" is being called
	if (!r->handler || strcmp(r->handler, "adv-handler")) return (DECLINED);

	return OK;
}