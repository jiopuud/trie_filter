/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2010 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:  Lijun Wu    <wulijun01234@gmail.com>                           |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#include <iconv.h>
#include <datrie/trie.h>

#ifndef PHP_TRIE_FILTER_H
#define PHP_TRIE_FILTER_H

extern zend_module_entry trie_filter_module_entry;
#define phpext_trie_filter_ptr &trie_filter_module_entry

#ifdef PHP_WIN32
#define PHP_TRIE_FILTER_API __declspec(dllexport)
#else
#define PHP_TRIE_FILTER_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#define ALPHA_CHARSET	"UCS-4LE"
#define PHP_TRIE_FILTER_RES_NAME "Trie tree filter"

#define ZEND_FETCH_RESOURCE(rsrc, rsrc_type, passed_id, default_id, resource_type_name, resource_type)        \
        (rsrc = (rsrc_type) zend_fetch_resource(Z_RES_P(*passed_id), resource_type_name, resource_type))
#define ZEND_REGISTER_RESOURCE(return_value, result, le_result)  ZVAL_RES(return_value,zend_register_resource(result, le_result))

PHP_MINIT_FUNCTION(trie_filter);
PHP_MSHUTDOWN_FUNCTION(trie_filter);
PHP_RINIT_FUNCTION(trie_filter);
PHP_RSHUTDOWN_FUNCTION(trie_filter);
PHP_MINFO_FUNCTION(trie_filter);

PHP_FUNCTION(trie_filter_load);
PHP_FUNCTION(trie_filter_search);
PHP_FUNCTION(trie_filter_search_all);
PHP_FUNCTION(trie_filter_new);
PHP_FUNCTION(trie_filter_store);
PHP_FUNCTION(trie_filter_save);
PHP_FUNCTION(trie_filter_free);

#ifdef ZTS
#define TRIE_FILTER_G(v) TSRMG(trie_filter_globals_id, zend_trie_filter_globals *, v)
#else
#define TRIE_FILTER_G(v) (trie_filter_globals.v)
#endif

#endif	/* PHP_TRIE_FILTER_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
