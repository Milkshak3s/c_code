/* Include the required headers from httpd */
#include "httpd.h"
#include "http_core.h"
#include "http_protocol.h"
#include "http_request.h"

/* Define function prototypes */
static void register_hooks(apr_pool_t *pool);
static int hello_handler(request_rec *r);

/* Define module as an entity and assign a function for registering hooks */
module AP_MODULE_DECLARE_DATA	hello_module =
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
	/* Create a hook in the request handler, so we get called when a request arrives */
	ap_hook_handler(hello_handler, NULL, NULL, APR_HOOK_LAST);
}


/* Handler function for the module, where all the interesting stuff happens! */
static int hello_handler(request_rec *r)
{
	/* Check if call is for "hello-handler"
	 * If it is, accept and do stuff
	 * Otherwise return DECLINED and move on
	 */
	if (!r->handler || strcmp(r->handler, "hello-handler")) return (DECLINED);

	/* We are handling the request now! Write "Hello, world!" to client
	 * First we must set correct content type, then send our output
	 */
	ap_set_content_type(r, "text/html");
	ap_rprintf(r, "Hello, world!")

	/* Lastly, we must tell the server that the request was handled
	 * properly. We do so by returning the value OK.
	 */
	return OK;
}