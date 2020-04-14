/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.1 */

#ifndef PB_GOOGLE_PROTOBUF_GOOGLE_PROTOBUF_API_PB_H_INCLUDED
#define PB_GOOGLE_PROTOBUF_GOOGLE_PROTOBUF_API_PB_H_INCLUDED
#include <pb.h>
#include "google/protobuf/source_context.pb.h"
#include "google/protobuf/type.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _google_protobuf_Mixin {
    pb_callback_t name;
    pb_callback_t root;
} google_protobuf_Mixin;

typedef struct _google_protobuf_Api {
    pb_callback_t name;
    pb_callback_t methods;
    pb_callback_t options;
    pb_callback_t version;
    bool has_source_context;
    google_protobuf_SourceContext source_context;
    pb_callback_t mixins;
    google_protobuf_Syntax syntax;
} google_protobuf_Api;

typedef struct _google_protobuf_Method {
    pb_callback_t name;
    pb_callback_t request_type_url;
    bool request_streaming;
    pb_callback_t response_type_url;
    bool response_streaming;
    pb_callback_t options;
    google_protobuf_Syntax syntax;
} google_protobuf_Method;


/* Initializer values for message structs */
#define google_protobuf_Api_init_default         {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false, google_protobuf_SourceContext_init_default, {{NULL}, NULL}, _google_protobuf_Syntax_MIN}
#define google_protobuf_Method_init_default      {{{NULL}, NULL}, {{NULL}, NULL}, 0, {{NULL}, NULL}, 0, {{NULL}, NULL}, _google_protobuf_Syntax_MIN}
#define google_protobuf_Mixin_init_default       {{{NULL}, NULL}, {{NULL}, NULL}}
#define google_protobuf_Api_init_zero            {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false, google_protobuf_SourceContext_init_zero, {{NULL}, NULL}, _google_protobuf_Syntax_MIN}
#define google_protobuf_Method_init_zero         {{{NULL}, NULL}, {{NULL}, NULL}, 0, {{NULL}, NULL}, 0, {{NULL}, NULL}, _google_protobuf_Syntax_MIN}
#define google_protobuf_Mixin_init_zero          {{{NULL}, NULL}, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define google_protobuf_Mixin_name_tag           1
#define google_protobuf_Mixin_root_tag           2
#define google_protobuf_Api_name_tag             1
#define google_protobuf_Api_methods_tag          2
#define google_protobuf_Api_options_tag          3
#define google_protobuf_Api_version_tag          4
#define google_protobuf_Api_source_context_tag   5
#define google_protobuf_Api_mixins_tag           6
#define google_protobuf_Api_syntax_tag           7
#define google_protobuf_Method_name_tag          1
#define google_protobuf_Method_request_type_url_tag 2
#define google_protobuf_Method_request_streaming_tag 3
#define google_protobuf_Method_response_type_url_tag 4
#define google_protobuf_Method_response_streaming_tag 5
#define google_protobuf_Method_options_tag       6
#define google_protobuf_Method_syntax_tag        7

/* Struct field encoding specification for nanopb */
#define google_protobuf_Api_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   name,              1) \
X(a, CALLBACK, REPEATED, MESSAGE,  methods,           2) \
X(a, CALLBACK, REPEATED, MESSAGE,  options,           3) \
X(a, CALLBACK, SINGULAR, STRING,   version,           4) \
X(a, STATIC,   OPTIONAL, MESSAGE,  source_context,    5) \
X(a, CALLBACK, REPEATED, MESSAGE,  mixins,            6) \
X(a, STATIC,   SINGULAR, UENUM,    syntax,            7)
#define google_protobuf_Api_CALLBACK pb_default_field_callback
#define google_protobuf_Api_DEFAULT NULL
#define google_protobuf_Api_methods_MSGTYPE google_protobuf_Method
#define google_protobuf_Api_options_MSGTYPE google_protobuf_Option
#define google_protobuf_Api_source_context_MSGTYPE google_protobuf_SourceContext
#define google_protobuf_Api_mixins_MSGTYPE google_protobuf_Mixin

#define google_protobuf_Method_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   name,              1) \
X(a, CALLBACK, SINGULAR, STRING,   request_type_url,   2) \
X(a, STATIC,   SINGULAR, BOOL,     request_streaming,   3) \
X(a, CALLBACK, SINGULAR, STRING,   response_type_url,   4) \
X(a, STATIC,   SINGULAR, BOOL,     response_streaming,   5) \
X(a, CALLBACK, REPEATED, MESSAGE,  options,           6) \
X(a, STATIC,   SINGULAR, UENUM,    syntax,            7)
#define google_protobuf_Method_CALLBACK pb_default_field_callback
#define google_protobuf_Method_DEFAULT NULL
#define google_protobuf_Method_options_MSGTYPE google_protobuf_Option

#define google_protobuf_Mixin_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   name,              1) \
X(a, CALLBACK, SINGULAR, STRING,   root,              2)
#define google_protobuf_Mixin_CALLBACK pb_default_field_callback
#define google_protobuf_Mixin_DEFAULT NULL

extern const pb_msgdesc_t google_protobuf_Api_msg;
extern const pb_msgdesc_t google_protobuf_Method_msg;
extern const pb_msgdesc_t google_protobuf_Mixin_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define google_protobuf_Api_fields &google_protobuf_Api_msg
#define google_protobuf_Method_fields &google_protobuf_Method_msg
#define google_protobuf_Mixin_fields &google_protobuf_Mixin_msg

/* Maximum encoded size of messages (where known) */
/* google_protobuf_Api_size depends on runtime parameters */
/* google_protobuf_Method_size depends on runtime parameters */
/* google_protobuf_Mixin_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
