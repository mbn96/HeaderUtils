#pragma once

#define HUTL_RESULT(v_type_name, e_type_name)                                  \
  hutl_result_##v_type_name##_##e_type_name##_t

#define HUTL_RESULT_DECEL(v_type_name, v_type, e_type_name, e_type)            \
  typedef struct {                                                             \
    bool is_ok;                                                                \
    union {                                                                    \
      e_type error;                                                            \
      v_type value;                                                            \
    };                                                                         \
  } HUTL_RESULT(v_type_name, e_type_name)

#define HUTL_RESULT_IS_OK(r) r.is_ok
#define HUTL_RESULT_ERROR(r) r.error
#define HUTL_RESULT_VALUE(r) r.value
#define HUTL_RESULT_CLEAR(r) r.is_ok = false
