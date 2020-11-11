#ifndef MIREA_C_CYBER_LABS_BASE_MACRO_H
#define MIREA_C_CYBER_LABS_BASE_MACRO_H

#if defined(__cplusplus)
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

#define STRINGIFY(x) #x
#define STR(name)  STRINGIFY(name)
#define CONCAT_IMPL( x, y ) x##y
#define MACRO_CONCAT( x, y ) CONCAT_IMPL( x, y )
#define CALL(name) MACRO_CONCAT( MACRO_CONCAT(v, TASK), MACRO_CONCAT(_, name) )
#define DIRECT_CALL(task, name) MACRO_CONCAT( MACRO_CONCAT(v, task), MACRO_CONCAT(_, name) )

#endif //MIREA_C_CYBER_LABS_BASE_MACRO_H
