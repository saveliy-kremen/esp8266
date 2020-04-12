/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.1 */

#ifndef PB_V1_USER_PB_H_INCLUDED
#define PB_V1_USER_PB_H_INCLUDED
#include <pb.h>
#include "google/protobuf/empty.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _v1_UsersResponse {
    pb_callback_t user;
} v1_UsersResponse;

typedef struct _v1_User {
    uint32_t id;
    pb_callback_t fullname;
    pb_callback_t phone;
    pb_callback_t email;
    pb_callback_t photo;
    uint32_t role;
    pb_callback_t trademark;
    uint32_t tariff;
    float amount;
    pb_callback_t about;
} v1_User;

typedef struct _v1_UserResponse {
    bool has_user;
    v1_User user;
} v1_UserResponse;


/* Initializer values for message structs */
#define v1_User_init_default                     {0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, 0, {{NULL}, NULL}, 0, 0, {{NULL}, NULL}}
#define v1_UserResponse_init_default             {false, v1_User_init_default}
#define v1_UsersResponse_init_default            {{{NULL}, NULL}}
#define v1_User_init_zero                        {0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, 0, {{NULL}, NULL}, 0, 0, {{NULL}, NULL}}
#define v1_UserResponse_init_zero                {false, v1_User_init_zero}
#define v1_UsersResponse_init_zero               {{{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define v1_UsersResponse_user_tag                1
#define v1_User_id_tag                           1
#define v1_User_fullname_tag                     2
#define v1_User_phone_tag                        3
#define v1_User_email_tag                        4
#define v1_User_photo_tag                        5
#define v1_User_role_tag                         6
#define v1_User_trademark_tag                    7
#define v1_User_tariff_tag                       8
#define v1_User_amount_tag                       9
#define v1_User_about_tag                        10
#define v1_UserResponse_user_tag                 1

/* Struct field encoding specification for nanopb */
#define v1_User_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   id,                1) \
X(a, CALLBACK, SINGULAR, STRING,   fullname,          2) \
X(a, CALLBACK, SINGULAR, STRING,   phone,             3) \
X(a, CALLBACK, SINGULAR, STRING,   email,             4) \
X(a, CALLBACK, SINGULAR, STRING,   photo,             5) \
X(a, STATIC,   SINGULAR, UINT32,   role,              6) \
X(a, CALLBACK, SINGULAR, STRING,   trademark,         7) \
X(a, STATIC,   SINGULAR, UINT32,   tariff,            8) \
X(a, STATIC,   SINGULAR, FLOAT,    amount,            9) \
X(a, CALLBACK, SINGULAR, STRING,   about,            10)
#define v1_User_CALLBACK pb_default_field_callback
#define v1_User_DEFAULT NULL

#define v1_UserResponse_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  user,              1)
#define v1_UserResponse_CALLBACK NULL
#define v1_UserResponse_DEFAULT NULL
#define v1_UserResponse_user_MSGTYPE v1_User

#define v1_UsersResponse_FIELDLIST(X, a) \
X(a, CALLBACK, REPEATED, MESSAGE,  user,              1)
#define v1_UsersResponse_CALLBACK pb_default_field_callback
#define v1_UsersResponse_DEFAULT NULL
#define v1_UsersResponse_user_MSGTYPE v1_User

extern const pb_msgdesc_t v1_User_msg;
extern const pb_msgdesc_t v1_UserResponse_msg;
extern const pb_msgdesc_t v1_UsersResponse_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define v1_User_fields &v1_User_msg
#define v1_UserResponse_fields &v1_UserResponse_msg
#define v1_UsersResponse_fields &v1_UsersResponse_msg

/* Maximum encoded size of messages (where known) */
/* v1_User_size depends on runtime parameters */
/* v1_UserResponse_size depends on runtime parameters */
/* v1_UsersResponse_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif