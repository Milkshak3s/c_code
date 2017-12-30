#include "httpd.h"
#include "http_core.h"
#include "http_protocol.h"
#include "http_request.h"

static void register_hooks(apr_pool_t *pool);
static int test_handler(request_rec *r);

module AP_MODULE_DECLARE_DATA	test_module =
{
	STANDARD20_MODULE_STUFF,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	register_hooks	/* Our hook registering function */
};

static void register_hooks(apr_pool_t *pool)
{
	ap_hook_handler(test_handler, NULL, NULL, APR_HOOK_LAST);
}

static int test_handler(request_rec *r)
{
	if (!r->handler || strcmp(r->handler, "test-handler")) return (DECLINED);

	ap_set_content_type(r, "text/html");
	ap_rprintf(r, "%s", r->filename);

	return OK;
}