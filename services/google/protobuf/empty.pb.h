/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.1 */

#ifndef PB_GOOGLE_PROTOBUF_GOOGLE_PROTOBUF_EMPTY_PB_H_INCLUDED
#define PB_GOOGLE_PROTOBUF_GOOGLE_PROTOBUF_EMPTY_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _google_protobuf_Empty {
    char dummy_field;
} google_protobuf_Empty;


/* Initializer values for message structs */
#define google_protobuf_Empty_init_default       {0}
#define google_protobuf_Empty_init_zero          {0}

/* Field tags (for use in manual encoding/decoding) */

/* Struct field encoding specification for nanopb */
#define google_protobuf_Empty_FIELDLIST(X, a) \

#define google_protobuf_Empty_CALLBACK NULL
#define google_protobuf_Empty_DEFAULT NULL

extern const pb_msgdesc_t google_protobuf_Empty_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define google_protobuf_Empty_fields &google_protobuf_Empty_msg

/* Maximum encoded size of messages (where known) */
#define google_protobuf_Empty_size               0

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif