#ifndef NRF_SVC__
#define NRF_SVC__

#ifdef SVCALL_AS_NORMAL_FUNCTION
#define SVCALL(number, return_type, signature) return_type signature
#else

#ifndef SVCALL
#if defined (__CC_ARM)
#define SVCALL(number, return_type, signature) return_type __svc(number) signature
#elif defined (__GNUC__)
/* The following two macros are needed so that when macro arguments are
 * substituted into the macro body of the SVCALL, they are expanded and
 * stringified. This would otherwise not have happened because argument-expansion
 * doesn't happen if macro-arguments appear with the # or ## preprocessor
 * operators.
 */
#define STRINGIFY(ARG) #ARG
#define EXPAND_AND_STRINGIFY(ARG) STRINGIFY(ARG)

#define SVCALL(number, return_type, signature)                  \
  _Pragma("GCC diagnostic ignored \"-Wreturn-type\"")           \
  _Pragma("GCC diagnostic ignored \"-Wunused-function\"")       \
  __attribute__((naked)) static return_type signature           \
  {                                                             \
    __asm(                                                      \
        "svc " EXPAND_AND_STRINGIFY(number) "\n"                \
        "bx r14" : : : "r0"                                     \
    );                                                          \
  }
#elif defined (__ICCARM__)
#define PRAGMA(x) _Pragma(#x)
#define SVCALL(number, return_type, signature) \
PRAGMA(swi_number = number) \
 __swi return_type signature;
#else
#define SVCALL(number, return_type, signature) return_type signature
#endif
#endif  // SVCALL

#endif  // SVCALL_AS_NORMAL_FUNCTION
#endif  // NRF_SVC__
