#pragma once

#define HUTL_OPTION(v_type_name) hutl_option_##v_type_name##_t

#define HUTL_OPTION_DECEL(v_type_name, v_type)                                 \
  typedef struct {                                                             \
    bool is_set;                                                               \
    v_type value;                                                              \
  } HUTL_OPTION(v_type_name)

#define HUTL_OPTION_SET(o, v)                                                  \
  do {                                                                         \
    o.is_set = true;                                                           \
    o.value = v;                                                               \
  } while (0)

#define HUTL_OPTION_GET(o) o.value
#define HUTL_OPTION_IS_SET(o) o.is_set
#define HUTL_OPTION_CLEAR(o) o.is_set = false
