/*
* Botan 2.8.0 Amalgamation
* (C) 1999-2018 The Botan Authors
*
* Botan is released under the Simplified BSD License (see license.txt)
*/

#ifndef BOTAN_AMALGAMATION_H_
#define BOTAN_AMALGAMATION_H_

#include <algorithm>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <deque>
#include <exception>
#include <functional>
#include <iosfwd>
#include <istream>
#include <map>
#include <memory>
#include <mutex>
#include <set>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

/*
* This file was automatically generated running
* 'configure.py --amalgamation --single-amalgamation-file --disable-modules=pkcs11 --minimized-build --enable-modules=rsa,auto_rng,system_rng,win32_stats,eme_oaep,md5'
*
* Target
*  - Compiler: cl /MD /bigobj /EHs /GR /D_ENABLE_EXTENDED_ALIGNED_STORAGE /O2 /Oi
*  - Arch: x86_64
*  - OS: windows
*/

#define BOTAN_VERSION_MAJOR 2
#define BOTAN_VERSION_MINOR 8
#define BOTAN_VERSION_PATCH 0
#define BOTAN_VERSION_DATESTAMP 0

#define BOTAN_VERSION_RELEASE_TYPE "unreleased"

#define BOTAN_VERSION_VC_REVISION "unknown"

#define BOTAN_DISTRIBUTION_INFO "unspecified"

/* How many bits per limb in a BigInt */
#define BOTAN_MP_WORD_BITS 64


#define BOTAN_INSTALL_PREFIX R"(c:\Botan)"
#define BOTAN_INSTALL_HEADER_DIR "include/botan-2"
#define BOTAN_INSTALL_LIB_DIR "lib"
#define BOTAN_LIB_LINK "user32.lib"
#define BOTAN_LINK_FLAGS "/MD /bigobj"

#ifndef BOTAN_DLL
  #define BOTAN_DLL __declspec(dllimport)
#endif

/* Target identification and feature test macros */

#define BOTAN_TARGET_OS_IS_WINDOWS

#define BOTAN_TARGET_OS_HAS_FILESYSTEM
#define BOTAN_TARGET_OS_HAS_RTLGENRANDOM
#define BOTAN_TARGET_OS_HAS_RTLSECUREZEROMEMORY
#define BOTAN_TARGET_OS_HAS_STL_FILESYSTEM_MSVC
#define BOTAN_TARGET_OS_HAS_THREADS
#define BOTAN_TARGET_OS_HAS_VIRTUAL_LOCK
#define BOTAN_TARGET_OS_HAS_WIN32
#define BOTAN_TARGET_OS_HAS_WINSOCK2


#define BOTAN_BUILD_COMPILER_IS_MSVC




#define BOTAN_TARGET_ARCH_IS_X86_64
#define BOTAN_TARGET_CPU_IS_LITTLE_ENDIAN
#define BOTAN_TARGET_CPU_IS_X86_FAMILY
#define BOTAN_TARGET_CPU_HAS_NATIVE_64BIT

#define BOTAN_TARGET_SUPPORTS_AESNI
#define BOTAN_TARGET_SUPPORTS_AVX2
#define BOTAN_TARGET_SUPPORTS_BMI2
#define BOTAN_TARGET_SUPPORTS_RDRAND
#define BOTAN_TARGET_SUPPORTS_RDSEED
#define BOTAN_TARGET_SUPPORTS_SHA
#define BOTAN_TARGET_SUPPORTS_SSE2
#define BOTAN_TARGET_SUPPORTS_SSE41
#define BOTAN_TARGET_SUPPORTS_SSE42
#define BOTAN_TARGET_SUPPORTS_SSSE3






/*
* Module availability definitions
*/
#define BOTAN_HAS_ASN1 20171109
#define BOTAN_HAS_AUTO_RNG 20161126
#define BOTAN_HAS_AUTO_SEEDING_RNG 20160821
#define BOTAN_HAS_BASE64_CODEC 20131128
#define BOTAN_HAS_BIGINT 20131128
#define BOTAN_HAS_BIGINT_MP 20151225
#define BOTAN_HAS_CPUID 20170917
#define BOTAN_HAS_DYNAMIC_LOADER 20160310
#define BOTAN_HAS_EME_OAEP 20180305
#define BOTAN_HAS_EMSA_PSSR 20131128
#define BOTAN_HAS_ENTROPY_SOURCE 20151120
#define BOTAN_HAS_ENTROPY_SRC_WIN32 20131128
#define BOTAN_HAS_HASH 20180112
#define BOTAN_HAS_HEX_CODEC 20131128
#define BOTAN_HAS_HMAC 20131128
#define BOTAN_HAS_HMAC_DRBG 20140319
#define BOTAN_HAS_KDF_BASE 20131128
#define BOTAN_HAS_KEYPAIR_TESTING 20131128
#define BOTAN_HAS_MAC 20150626
#define BOTAN_HAS_MD5 20131128
#define BOTAN_HAS_MDX_HASH_FUNCTION 20131128
#define BOTAN_HAS_MGF1 20140118
#define BOTAN_HAS_NUMBERTHEORY 20131128
#define BOTAN_HAS_PEM_CODEC 20131128
#define BOTAN_HAS_PK_PADDING 20131128
#define BOTAN_HAS_PUBLIC_KEY_CRYPTO 20131128
#define BOTAN_HAS_RSA 20160730
#define BOTAN_HAS_SHA2_32 20131128
#define BOTAN_HAS_STATEFUL_RNG 20160819
#define BOTAN_HAS_SYSTEM_RNG 20141202
#define BOTAN_HAS_UTIL_FUNCTIONS 20180903


/*
* Local/misc configuration options (if any) follow
*/


/*
* Things you can edit (but probably shouldn't)
*/

#if !defined(BOTAN_DEPRECATED_PUBLIC_MEMBER_VARIABLES)

  #if defined(BOTAN_NO_DEPRECATED)
     #define BOTAN_DEPRECATED_PUBLIC_MEMBER_VARIABLES private
  #else
     #define BOTAN_DEPRECATED_PUBLIC_MEMBER_VARIABLES public
  #endif

#endif

/* How much to allocate for a buffer of no particular size */
#define BOTAN_DEFAULT_BUFFER_SIZE 1024

/* Minimum and maximum sizes to allocate out of the mlock pool (bytes)
   Default min is 16 as smaller values are easily bruteforceable and thus
   likely not cryptographic keys.
*/
#define BOTAN_MLOCK_ALLOCATOR_MIN_ALLOCATION 16
#define BOTAN_MLOCK_ALLOCATOR_MAX_ALLOCATION 128

/*
* Total maximum amount of RAM (in KiB) we will lock into memory, even
* if the OS would let us lock more
*/
#define BOTAN_MLOCK_ALLOCATOR_MAX_LOCKED_KB 512

/*
* If enabled uses memset via volatile function pointer to zero memory,
* otherwise does a byte at a time write via a volatile pointer.
*/
#define BOTAN_USE_VOLATILE_MEMSET_FOR_ZERO 1

/*
* Normally blinding is performed by choosing a random starting point (plus
* its inverse, of a form appropriate to the algorithm being blinded), and
* then choosing new blinding operands by successive squaring of both
* values. This is much faster than computing a new starting point but
* introduces some possible corelation
*
* To avoid possible leakage problems in long-running processes, the blinder
* periodically reinitializes the sequence. This value specifies how often
* a new sequence should be started.
*/
#define BOTAN_BLINDING_REINIT_INTERVAL 64

/*
* Userspace RNGs like HMAC_DRBG will reseed after a specified number
* of outputs are generated. Set to zero to disable automatic reseeding.
*/
#define BOTAN_RNG_DEFAULT_RESEED_INTERVAL 1024
#define BOTAN_RNG_RESEED_POLL_BITS 256

#define BOTAN_RNG_AUTO_RESEED_TIMEOUT std::chrono::milliseconds(10)
#define BOTAN_RNG_RESEED_DEFAULT_TIMEOUT std::chrono::milliseconds(50)

/*
* Specifies (in order) the list of entropy sources that will be used
* to seed an in-memory RNG. The first in the default list: "rdseed"
* and "rdrand" do not count as contributing any entropy but are
* included as they are fast and help protect against a seriously
* broken system RNG.
*/
#define BOTAN_ENTROPY_DEFAULT_SOURCES \
   { "rdseed", "rdrand", "getentropy", "dev_random", \
     "system_rng", "proc_walk", "system_stats" }

/* Multiplier on a block cipher's native parallelism */
#define BOTAN_BLOCK_CIPHER_PAR_MULT 4

/*
* These control the RNG used by the system RNG interface
*/
#define BOTAN_SYSTEM_RNG_DEVICE "/dev/urandom"
#define BOTAN_SYSTEM_RNG_POLL_DEVICES { "/dev/urandom", "/dev/random" }

/*
* This directory will be monitored by ProcWalking_EntropySource and
* the contents provided as entropy inputs to the RNG. May also be
* usefully set to something like "/sys", depending on the system being
* deployed to. Set to an empty string to disable.
*/
#define BOTAN_ENTROPY_PROC_FS_PATH "/proc"

/*
* These paramaters control how many bytes to read from the system
* PRNG, and how long to block if applicable. The timeout only applies
* to reading /dev/urandom and company.
*/
#define BOTAN_SYSTEM_RNG_POLL_REQUEST 64
#define BOTAN_SYSTEM_RNG_POLL_TIMEOUT_MS 20

/*
How many times to read from the RDRAND/RDSEED RNGs.
Each read generates 32 bits of output
*/
#define BOTAN_ENTROPY_INTEL_RNG_POLLS 32

// According to Intel, RDRAND is guaranteed to generate a random number within 10 retries on a working CPU
#define BOTAN_ENTROPY_RDRAND_RETRIES 10

/*
* RdSeed is not guaranteed to generate a random number within a specific number of retries
* Define the number of retries here
*/
#define BOTAN_ENTROPY_RDSEED_RETRIES 20

/*
* If no way of dynamically determining the cache line size for the
* system exists, this value is used as the default. Used by the side
* channel countermeasures rather than for alignment purposes, so it is
* better to be on the smaller side if the exact value cannot be
* determined. Typically 32 or 64 bytes on modern CPUs.
*/
#if !defined(BOTAN_TARGET_CPU_DEFAULT_CACHE_LINE_SIZE)
  #define BOTAN_TARGET_CPU_DEFAULT_CACHE_LINE_SIZE 32
#endif

/**
* Controls how AutoSeeded_RNG is instantiated
*/
#if !defined(BOTAN_AUTO_RNG_HMAC)

  #if defined(BOTAN_HAS_SHA2_64)
    #define BOTAN_AUTO_RNG_HMAC "HMAC(SHA-384)"
  #elif defined(BOTAN_HAS_SHA2_32)
    #define BOTAN_AUTO_RNG_HMAC "HMAC(SHA-256)"
  #elif defined(BOTAN_HAS_SHA3)
    #define BOTAN_AUTO_RNG_HMAC "HMAC(SHA-3(256))"
  #elif defined(BOTAN_HAS_SHA1)
    #define BOTAN_AUTO_RNG_HMAC "HMAC(SHA-1)"
  #endif
  // Otherwise, no hash found: leave BOTAN_AUTO_RNG_HMAC undefined

#endif

// Check for a common build problem:

#if defined(BOTAN_TARGET_ARCH_IS_X86_64) && ((defined(_MSC_VER) && !defined(_WIN64)) || \
                                             (defined(__clang__) && !defined(__x86_64__)) || \
                                             (defined(__GNUG__) && !defined(__x86_64__)))
    #error "Trying to compile Botan configured as x86_64 with non-x86_64 compiler."
#endif

#if defined(BOTAN_TARGET_ARCH_IS_X86_32) && ((defined(_MSC_VER) && defined(_WIN64)) || \
                                             (defined(__clang__) && !defined(__i386__)) || \
                                             (defined(__GNUG__) && !defined(__i386__)))

    #error "Trying to compile Botan configured as x86_32 with non-x86_32 compiler."
#endif

/* Should we use GCC-style inline assembler? */
#if !defined(BOTAN_USE_GCC_INLINE_ASM) && (defined(__GNUC__) || defined(__xlc__) || defined(__SUNPRO_CC))
  #define BOTAN_USE_GCC_INLINE_ASM 1
#endif

/**
* Used to annotate API exports which are public and supported.
* These APIs will not be broken/removed unless strictly required for
* functionality or security, and only in new major versions.
* @param maj The major version this public API was released in
* @param min The minor version this public API was released in
*/
#define BOTAN_PUBLIC_API(maj,min) BOTAN_DLL

/**
* Used to annotate API exports which are public and can be used by
* applications if needed, but which are intentionally not documented,
* and which may change incompatibly in a future major version.
*/
#define BOTAN_UNSTABLE_API BOTAN_DLL

/**
* Used to annotate API exports which are exported but only for the
* purposes of testing. They should not be used by applications and
* may be removed or changed without notice.
*/
#define BOTAN_TEST_API BOTAN_DLL

/*
* Define BOTAN_GCC_VERSION
*/
#ifdef __GNUC__
  #define BOTAN_GCC_VERSION (__GNUC__ * 100 + __GNUC_MINOR__ * 10 + __GNUC_PATCHLEVEL__)
#else
  #define BOTAN_GCC_VERSION 0
#endif

/*
* Define BOTAN_CLANG_VERSION
*/
#ifdef __clang__
  #define BOTAN_CLANG_VERSION (__clang_major__ * 10 + __clang_minor__)
#else
  #define BOTAN_CLANG_VERSION 0
#endif

/*
* Define special macro when building under MSVC 2013 since there are
* many compiler workarounds required for that version.
*/
#if defined(_MSC_VER) && (_MSC_VER < 1900)
  #define BOTAN_BUILD_COMPILER_IS_MSVC_2013
#endif

/*
* Define BOTAN_FUNC_ISA
*/
#if (defined(__GNUG__) && !defined(__clang__)) || (BOTAN_CLANG_VERSION > 38)
  #define BOTAN_FUNC_ISA(isa) __attribute__ ((target(isa)))
#else
  #define BOTAN_FUNC_ISA(isa)
#endif

/*
* Define BOTAN_WARN_UNUSED_RESULT
*/
#if defined(__GNUG__) || defined(__clang__)
  #define BOTAN_WARN_UNUSED_RESULT __attribute__ ((warn_unused_result))
#else
  #define BOTAN_WARN_UNUSED_RESULT
#endif

/*
* Define BOTAN_MALLOC_FN
*/
#if defined(__GNUG__) || defined(__clang__)
  #define BOTAN_MALLOC_FN __attribute__ ((malloc))
#elif defined(_MSC_VER)
  #define BOTAN_MALLOC_FN __declspec(restrict)
#else
  #define BOTAN_MALLOC_FN
#endif

/*
* Define BOTAN_DEPRECATED
*/
#if !defined(BOTAN_NO_DEPRECATED_WARNINGS)

  #if defined(__clang__)
    #define BOTAN_DEPRECATED(msg) __attribute__ ((deprecated))

  #elif defined(_MSC_VER)
    #define BOTAN_DEPRECATED(msg) __declspec(deprecated(msg))

  #elif defined(__GNUG__)
    // msg supported since GCC 4.5, earliest we support is 4.8
    #define BOTAN_DEPRECATED(msg) __attribute__ ((deprecated(msg)))
  #endif

#endif

#if !defined(BOTAN_DEPRECATED)
  #define BOTAN_DEPRECATED(msg)
#endif

/*
* Define BOTAN_NORETURN
*/
#if !defined(BOTAN_NORETURN)

  #if defined (__clang__) || defined (__GNUG__)
    #define BOTAN_NORETURN __attribute__ ((__noreturn__))

  #elif defined (_MSC_VER)
    #define BOTAN_NORETURN __declspec(noreturn)

  #else
    #define BOTAN_NORETURN
  #endif

#endif

/*
* Define BOTAN_CURRENT_FUNCTION
*/
#if defined(BOTAN_BUILD_COMPILER_IS_MSVC_2013)
  #define BOTAN_CURRENT_FUNCTION __FUNCTION__
#else
  #define BOTAN_CURRENT_FUNCTION __func__
#endif

/*
* Define BOTAN_NOEXCEPT (for MSVC 2013)
*/
#if defined(BOTAN_BUILD_COMPILER_IS_MSVC_2013)
  // noexcept is not supported in VS 2013
  #include <yvals.h>
  #define BOTAN_NOEXCEPT _NOEXCEPT
#else
  #define BOTAN_NOEXCEPT noexcept
#endif

/*
* Define BOTAN_CONSTEXPR (for MSVC 2013)
*/
#if defined(BOTAN_BUILD_COMPILER_IS_MSVC_2013)
  #define BOTAN_CONSTEXPR /**/
#else
  #define BOTAN_CONSTEXPR constexpr
#endif

/*
* Define BOTAN_ALIGNAS (for MSVC 2013)
*/
#if defined(BOTAN_BUILD_COMPILER_IS_MSVC_2013)
  #define BOTAN_ALIGNAS(n) /**/
#else
  #define BOTAN_ALIGNAS(n) alignas(n)
#endif

/*
* Define BOTAN_PARALLEL_FOR
*/
#if !defined(BOTAN_PARALLEL_FOR)

#if defined(BOTAN_TARGET_HAS_OPENMP)
  #define BOTAN_PARALLEL_FOR _Pragma("omp parallel for") for
#else
  #define BOTAN_PARALLEL_FOR for
#endif

#endif

/*
* Define BOTAN_PARALLEL_SIMD_FOR
*/
#if !defined(BOTAN_PARALLEL_SIMD_FOR)

#if defined(BOTAN_TARGET_HAS_OPENMP)
  #define BOTAN_PARALLEL_SIMD_FOR _Pragma("omp simd") for
#elif defined(BOTAN_BUILD_COMPILER_IS_GCC) && (BOTAN_GCC_VERSION >= 490)
  #define BOTAN_PARALLEL_SIMD_FOR _Pragma("GCC ivdep") for
#else
  #define BOTAN_PARALLEL_SIMD_FOR for
#endif

#endif

namespace Botan {

/**
* Called when an assertion fails
* Throws an Exception object
*/
BOTAN_NORETURN void BOTAN_PUBLIC_API(2,0)
   assertion_failure(const char* expr_str,
                     const char* assertion_made,
                     const char* func,
                     const char* file,
                     int line);

/**
* Called when an invalid argument is used
* Throws Invalid_Argument
*/
BOTAN_NORETURN void BOTAN_UNSTABLE_API throw_invalid_argument(const char* message,
                                                              const char* func,
                                                              const char* file);


#define BOTAN_ARG_CHECK(expr, msg)                                      \
   do { if(!(expr)) Botan::throw_invalid_argument(msg, BOTAN_CURRENT_FUNCTION, __FILE__); } while(0)

/**
* Called when an invalid state is encountered
* Throws Invalid_State
*/
BOTAN_NORETURN void BOTAN_UNSTABLE_API throw_invalid_state(const char* message,
                                                           const char* func,
                                                           const char* file);


#define BOTAN_STATE_CHECK(expr)                                     \
   do { if(!(expr)) Botan::throw_invalid_state(#expr, BOTAN_CURRENT_FUNCTION, __FILE__); } while(0)

/**
* Make an assertion
*/
#define BOTAN_ASSERT(expr, assertion_made)                \
   do {                                                   \
      if(!(expr))                                         \
         Botan::assertion_failure(#expr,                  \
                                  assertion_made,         \
                                  BOTAN_CURRENT_FUNCTION, \
                                  __FILE__,               \
                                  __LINE__);              \
   } while(0)

/**
* Make an assertion
*/
#define BOTAN_ASSERT_NOMSG(expr)                          \
   do {                                                   \
      if(!(expr))                                         \
         Botan::assertion_failure(#expr,                  \
                                  "",                     \
                                  BOTAN_CURRENT_FUNCTION, \
                                  __FILE__,               \
                                  __LINE__);              \
   } while(0)

/**
* Assert that value1 == value2
*/
#define BOTAN_ASSERT_EQUAL(expr1, expr2, assertion_made)   \
   do {                                                    \
     if((expr1) != (expr2))                                \
       Botan::assertion_failure(#expr1 " == " #expr2,      \
                                  assertion_made,          \
                                  BOTAN_CURRENT_FUNCTION,  \
                                  __FILE__,                \
                                  __LINE__);               \
   } while(0)

/**
* Assert that expr1 (if true) implies expr2 is also true
*/
#define BOTAN_ASSERT_IMPLICATION(expr1, expr2, msg)        \
   do {                                                    \
     if((expr1) && !(expr2))                               \
       Botan::assertion_failure(#expr1 " implies " #expr2, \
                                msg,                       \
                                  BOTAN_CURRENT_FUNCTION,  \
                                  __FILE__,                \
                                  __LINE__);               \
   } while(0)

/**
* Assert that a pointer is not null
*/
#define BOTAN_ASSERT_NONNULL(ptr)                          \
   do {                                                    \
     if((ptr) == nullptr)                                  \
         Botan::assertion_failure(#ptr " is not null",     \
                                  "",                      \
                                  BOTAN_CURRENT_FUNCTION,  \
                                  __FILE__,                \
                                  __LINE__);               \
   } while(0)

#if defined(BOTAN_ENABLE_DEBUG_ASSERTS)

#define BOTAN_DEBUG_ASSERT(expr) BOTAN_ASSERT_NOMSG(expr)

#else

#define BOTAN_DEBUG_ASSERT(expr) do {} while(0)

#endif

/**
* Mark variable as unused. Takes between 1 and 9 arguments and marks all as unused,
* e.g. BOTAN_UNUSED(a); or BOTAN_UNUSED(x, y, z);
*/
#define _BOTAN_UNUSED_IMPL1(a)                         static_cast<void>(a)
#define _BOTAN_UNUSED_IMPL2(a, b)                      static_cast<void>(a); _BOTAN_UNUSED_IMPL1(b)
#define _BOTAN_UNUSED_IMPL3(a, b, c)                   static_cast<void>(a); _BOTAN_UNUSED_IMPL2(b, c)
#define _BOTAN_UNUSED_IMPL4(a, b, c, d)                static_cast<void>(a); _BOTAN_UNUSED_IMPL3(b, c, d)
#define _BOTAN_UNUSED_IMPL5(a, b, c, d, e)             static_cast<void>(a); _BOTAN_UNUSED_IMPL4(b, c, d, e)
#define _BOTAN_UNUSED_IMPL6(a, b, c, d, e, f)          static_cast<void>(a); _BOTAN_UNUSED_IMPL5(b, c, d, e, f)
#define _BOTAN_UNUSED_IMPL7(a, b, c, d, e, f, g)       static_cast<void>(a); _BOTAN_UNUSED_IMPL6(b, c, d, e, f, g)
#define _BOTAN_UNUSED_IMPL8(a, b, c, d, e, f, g, h)    static_cast<void>(a); _BOTAN_UNUSED_IMPL7(b, c, d, e, f, g, h)
#define _BOTAN_UNUSED_IMPL9(a, b, c, d, e, f, g, h, i) static_cast<void>(a); _BOTAN_UNUSED_IMPL8(b, c, d, e, f, g, h, i)
#define _BOTAN_UNUSED_GET_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, IMPL_NAME, ...) IMPL_NAME

#define BOTAN_UNUSED(...) _BOTAN_UNUSED_GET_IMPL(__VA_ARGS__,                      \
                                                 _BOTAN_UNUSED_IMPL9,              \
                                                 _BOTAN_UNUSED_IMPL8,              \
                                                 _BOTAN_UNUSED_IMPL7,              \
                                                 _BOTAN_UNUSED_IMPL6,              \
                                                 _BOTAN_UNUSED_IMPL5,              \
                                                 _BOTAN_UNUSED_IMPL4,              \
                                                 _BOTAN_UNUSED_IMPL3,              \
                                                 _BOTAN_UNUSED_IMPL2,              \
                                                 _BOTAN_UNUSED_IMPL1,              \
                                                 unused dummy rest value           \
                          ) /* we got an one of _BOTAN_UNUSED_IMPL*, now call it */ (__VA_ARGS__)

}

namespace Botan {

/**
* @mainpage Botan Crypto Library API Reference
*
* <dl>
* <dt>Abstract Base Classes<dd>
*        BlockCipher, HashFunction, KDF, MessageAuthenticationCode, RandomNumberGenerator,
*        StreamCipher, SymmetricAlgorithm, AEAD_Mode, Cipher_Mode
* <dt>Public Key Interface Classes<dd>
*        PK_Key_Agreement, PK_Signer, PK_Verifier, PK_Encryptor, PK_Decryptor
* <dt>Authenticated Encryption Modes<dd>
*        @ref CCM_Mode "CCM", @ref ChaCha20Poly1305_Mode "ChaCha20Poly1305", @ref EAX_Mode "EAX",
*        @ref GCM_Mode "GCM", @ref OCB_Mode "OCB", @ref SIV_Mode "SIV"
* <dt>Block Ciphers<dd>
*        @ref aria.h "ARIA", @ref aes.h "AES", @ref Blowfish, @ref camellia.h "Camellia", @ref Cascade_Cipher "Cascade",
*        @ref CAST_128 "CAST-128", @ref CAST_128 "CAST-256", DES, @ref DESX "DES-X", @ref TripleDES "3DES",
*        @ref GOST_28147_89 "GOST 28147-89", IDEA, KASUMI, Lion, MISTY1, Noekeon, SEED, Serpent, SHACAL2, SM4,
*        @ref Threefish_512 "Threefish", Twofish, XTEA
* <dt>Stream Ciphers<dd>
*        ChaCha, @ref CTR_BE "CTR", OFB, RC4, Salsa20
* <dt>Hash Functions<dd>
*        Blake2b, @ref GOST_34_11 "GOST 34.11", @ref Keccak_1600 "Keccak", MD4, MD5, @ref RIPEMD_160 "RIPEMD-160",
*        @ref SHA_160 "SHA-1", @ref SHA_224 "SHA-224", @ref SHA_256 "SHA-256", @ref SHA_384 "SHA-384",
*        @ref SHA_512 "SHA-512", @ref Skein_512 "Skein-512", SM3, Streebog, Tiger, Whirlpool
* <dt>Non-Cryptographic Checksums<dd>
*        Adler32, CRC24, CRC32
* <dt>Message Authentication Codes<dd>
*        @ref CBC_MAC "CBC-MAC", CMAC, HMAC, Poly1305, SipHash, ANSI_X919_MAC
* <dt>Random Number Generators<dd>
*        AutoSeeded_RNG, HMAC_DRBG, RDRAND_RNG, System_RNG
* <dt>Key Derivation<dd>
*        HKDF, @ref KDF1 "KDF1 (IEEE 1363)", @ref KDF1_18033 "KDF1 (ISO 18033-2)", @ref KDF2 "KDF2 (IEEE 1363)",
*        @ref sp800_108.h "SP800-108", @ref SP800_56C "SP800-56C", @ref PKCS5_PBKDF1 "PBKDF1 (PKCS#5),
*        @ref PKCS5_PBKDF2 "PBKDF2 (PKCS#5)"
* <dt>Password Hashing<dd>
*        @ref bcrypt.h "bcrypt", @ref passhash9.h "passhash9"
* <dt>Public Key Cryptosystems<dd>
*        @ref dlies.h "DLIES", @ref ecies.h "ECIES", @ref elgamal.h "ElGamal"
*        @ref rsa.h "RSA", @ref newhope.h "NewHope", @ref mceliece.h "McEliece" and @ref mceies.h "MCEIES",
*        @ref sm2.h "SM2"
* <dt>Public Key Signature Schemes<dd>
*        @ref dsa.h "DSA", @ref ecdsa.h "ECDSA", @ref ecgdsa.h "ECGDSA", @ref eckcdsa.h "ECKCDSA",
*        @ref gost_3410.h "GOST 34.10-2001", @ref sm2.h "SM2", @ref xmss.h "XMSS"
* <dt>Key Agreement<dd>
*        @ref dh.h "DH", @ref ecdh.h "ECDH"
* <dt>Compression<dd>
*        @ref bzip2.h "bzip2", @ref lzma.h "lzma", @ref zlib.h "zlib"
* <dt>TLS<dd>
*        TLS::Client, TLS::Server, TLS::Policy, TLS::Protocol_Version, TLS::Callbacks, TLS::Ciphersuite,
*        TLS::Session, TLS::Session_Manager, Credentials_Manager
* <dt>X.509<dd>
*        X509_Certificate, X509_CRL, X509_CA, Certificate_Extension, PKCS10_Request, X509_Cert_Options,
*        Certificate_Store, Certificate_Store_In_SQL, Certificate_Store_In_SQLite
* </dl>
*/

using std::uint8_t;
using std::uint16_t;
using std::uint32_t;
using std::uint64_t;
using std::int32_t;
using std::int64_t;
using std::size_t;

/*
* These typedefs are no longer used within the library headers
* or code. They are kept only for compatability with software
* written against older versions.
*/
using byte   = std::uint8_t;
using u16bit = std::uint16_t;
using u32bit = std::uint32_t;
using u64bit = std::uint64_t;
using s32bit = std::int32_t;

#if (BOTAN_MP_WORD_BITS == 32)
  typedef uint32_t word;
#elif (BOTAN_MP_WORD_BITS == 64)
  typedef uint64_t word;
#else
  #error BOTAN_MP_WORD_BITS must be 32 or 64
#endif

}

namespace Botan {

/**
* Allocate a memory buffer by some method. This should only be used for
* primitive types (uint8_t, uint32_t, etc).
*
* @param elems the number of elements
* @param elem_size the size of each element
* @return pointer to allocated and zeroed memory, or throw std::bad_alloc on failure
*/
BOTAN_PUBLIC_API(2,3) BOTAN_MALLOC_FN void* allocate_memory(size_t elems, size_t elem_size);

/**
* Free a pointer returned by allocate_memory
* @param p the pointer returned by allocate_memory
* @param elems the number of elements, as passed to allocate_memory
* @param elem_size the size of each element, as passed to allocate_memory
*/
BOTAN_PUBLIC_API(2,3) void deallocate_memory(void* p, size_t elems, size_t elem_size);

/**
* Ensure the allocator is initialized
*/
void initialize_allocator();

class Allocator_Initializer
   {
   public:
      Allocator_Initializer() { initialize_allocator(); }
   };

/**
* Scrub memory contents in a way that a compiler should not elide,
* using some system specific technique. Note that this function might
* not zero the memory (for example, in some hypothetical
* implementation it might combine the memory contents with the output
* of a system PRNG), but if you can detect any difference in behavior
* at runtime then the clearing is side-effecting and you can just
* use `clear_mem`.
*
* Use this function to scrub memory just before deallocating it, or on
* a stack buffer before returning from the function.
*
* @param ptr a pointer to memory to scrub
* @param n the number of bytes pointed to by ptr
*/
BOTAN_PUBLIC_API(2,0) void secure_scrub_memory(void* ptr, size_t n);

/**
* Memory comparison, input insensitive
* @param x a pointer to an array
* @param y a pointer to another array
* @param len the number of Ts in x and y
* @return true iff x[i] == y[i] forall i in [0...n)
*/
BOTAN_PUBLIC_API(2,3) bool constant_time_compare(const uint8_t x[],
                                     const uint8_t y[],
                                     size_t len);

/**
* Zero out some bytes
* @param ptr a pointer to memory to zero
* @param bytes the number of bytes to zero in ptr
*/
inline void clear_bytes(void* ptr, size_t bytes)
   {
   if(bytes > 0)
      {
      std::memset(ptr, 0, bytes);
      }
   }

/**
* Zero memory before use. This simply calls memset and should not be
* used in cases where the compiler cannot see the call as a
* side-effecting operation (for example, if calling clear_mem before
* deallocating memory, the compiler would be allowed to omit the call
* to memset entirely under the as-if rule.)
*
* @param ptr a pointer to an array of Ts to zero
* @param n the number of Ts pointed to by ptr
*/
template<typename T> inline void clear_mem(T* ptr, size_t n)
   {
   clear_bytes(ptr, sizeof(T)*n);
   }

/**
* Copy memory
* @param out the destination array
* @param in the source array
* @param n the number of elements of in/out
*/
template<typename T> inline void copy_mem(T* out, const T* in, size_t n)
   {
   if(n > 0)
      {
      std::memmove(out, in, sizeof(T)*n);
      }
   }

/**
* Set memory to a fixed value
* @param ptr a pointer to an array
* @param n the number of Ts pointed to by ptr
* @param val the value to set each byte to
*/
template<typename T>
inline void set_mem(T* ptr, size_t n, uint8_t val)
   {
   if(n > 0)
      {
      std::memset(ptr, val, sizeof(T)*n);
      }
   }

inline const uint8_t* cast_char_ptr_to_uint8(const char* s)
   {
   return reinterpret_cast<const uint8_t*>(s);
   }

inline const char* cast_uint8_ptr_to_char(const uint8_t* b)
   {
   return reinterpret_cast<const char*>(b);
   }

inline uint8_t* cast_char_ptr_to_uint8(char* s)
   {
   return reinterpret_cast<uint8_t*>(s);
   }

inline char* cast_uint8_ptr_to_char(uint8_t* b)
   {
   return reinterpret_cast<char*>(b);
   }

/**
* Memory comparison, input insensitive
* @param p1 a pointer to an array
* @param p2 a pointer to another array
* @param n the number of Ts in p1 and p2
* @return true iff p1[i] == p2[i] forall i in [0...n)
*/
template<typename T> inline bool same_mem(const T* p1, const T* p2, size_t n)
   {
   volatile T difference = 0;

   for(size_t i = 0; i != n; ++i)
      difference |= (p1[i] ^ p2[i]);

   return difference == 0;
   }

/**
* XOR arrays. Postcondition out[i] = in[i] ^ out[i] forall i = 0...length
* @param out the input/output buffer
* @param in the read-only input buffer
* @param length the length of the buffers
*/
inline void xor_buf(uint8_t out[],
                    const uint8_t in[],
                    size_t length)
   {
   while(length >= 16)
      {
      uint64_t x0, x1, y0, y1;
      std::memcpy(&x0, in, 8);
      std::memcpy(&x1, in + 8, 8);
      std::memcpy(&y0, out, 8);
      std::memcpy(&y1, out + 8, 8);

      y0 ^= x0;
      y1 ^= x1;
      std::memcpy(out, &y0, 8);
      std::memcpy(out + 8, &y1, 8);
      out += 16; in += 16; length -= 16;
      }

   while(length > 0)
      {
      out[0] ^= in[0];
      out += 1;
      in += 1;
      length -= 1;
      }
   }

/**
* XOR arrays. Postcondition out[i] = in[i] ^ in2[i] forall i = 0...length
* @param out the output buffer
* @param in the first input buffer
* @param in2 the second output buffer
* @param length the length of the three buffers
*/
inline void xor_buf(uint8_t out[],
                    const uint8_t in[],
                    const uint8_t in2[],
                    size_t length)
   {
   while(length >= 16)
      {
      uint64_t x0, x1, y0, y1;
      std::memcpy(&x0, in, 8);
      std::memcpy(&x1, in + 8, 8);
      std::memcpy(&y0, in2, 8);
      std::memcpy(&y1, in2 + 8, 8);

      x0 ^= y0;
      x1 ^= y1;
      std::memcpy(out, &x0, 8);
      std::memcpy(out + 8, &x1, 8);
      out += 16; in += 16; in2 += 16; length -= 16;
      }

   for(size_t i = 0; i != length; ++i)
      out[i] = in[i] ^ in2[i];
   }

template<typename Alloc, typename Alloc2>
void xor_buf(std::vector<uint8_t, Alloc>& out,
             const std::vector<uint8_t, Alloc2>& in,
             size_t n)
   {
   xor_buf(out.data(), in.data(), n);
   }

template<typename Alloc>
void xor_buf(std::vector<uint8_t, Alloc>& out,
             const uint8_t* in,
             size_t n)
   {
   xor_buf(out.data(), in, n);
   }

template<typename Alloc, typename Alloc2>
void xor_buf(std::vector<uint8_t, Alloc>& out,
             const uint8_t* in,
             const std::vector<uint8_t, Alloc2>& in2,
             size_t n)
   {
   xor_buf(out.data(), in, in2.data(), n);
   }

template<typename Alloc, typename Alloc2>
std::vector<uint8_t, Alloc>&
operator^=(std::vector<uint8_t, Alloc>& out,
           const std::vector<uint8_t, Alloc2>& in)
   {
   if(out.size() < in.size())
      out.resize(in.size());

   xor_buf(out.data(), in.data(), in.size());
   return out;
   }

}

namespace Botan {

template<typename T>
class secure_allocator
   {
   public:
      /*
      * Assert exists to prevent someone from doing something that will
      * probably crash anyway (like secure_vector<non_POD_t> where ~non_POD_t
      * deletes a member pointer which was zeroed before it ran).
      * MSVC in debug mode uses non-integral proxy types in container types
      * like std::vector, thus we disable the check there.
      */
#if !defined(_ITERATOR_DEBUG_LEVEL) || _ITERATOR_DEBUG_LEVEL == 0
      static_assert(std::is_integral<T>::value, "secure_allocator supports only integer types");
#endif

      typedef T          value_type;
      typedef std::size_t size_type;

#ifdef BOTAN_BUILD_COMPILER_IS_MSVC_2013
      secure_allocator() = default;
      secure_allocator(const secure_allocator&) = default;
      secure_allocator& operator=(const secure_allocator&) = default;
      ~secure_allocator() = default;

      template <typename U>
      struct rebind
         {
         typedef secure_allocator<U> other;
         };

      void construct(value_type* mem, const value_type& value)
         {
         std::_Construct(mem, value);
         }

      void destroy(value_type* mem)
         {
         std::_Destroy(mem);
         }
#else
      secure_allocator() BOTAN_NOEXCEPT = default;
      secure_allocator(const secure_allocator&) BOTAN_NOEXCEPT = default;
      secure_allocator& operator=(const secure_allocator&) BOTAN_NOEXCEPT = default;
      ~secure_allocator() BOTAN_NOEXCEPT = default;
#endif

      template<typename U>
      secure_allocator(const secure_allocator<U>&) BOTAN_NOEXCEPT {}

      T* allocate(std::size_t n)
         {
         return static_cast<T*>(allocate_memory(n, sizeof(T)));
         }

      void deallocate(T* p, std::size_t n)
         {
         deallocate_memory(p, n, sizeof(T));
         }
   };

template<typename T, typename U> inline bool
operator==(const secure_allocator<T>&, const secure_allocator<U>&)
   { return true; }

template<typename T, typename U> inline bool
operator!=(const secure_allocator<T>&, const secure_allocator<U>&)
   { return false; }

template<typename T> using secure_vector = std::vector<T, secure_allocator<T>>;
template<typename T> using secure_deque = std::deque<T, secure_allocator<T>>;

// For better compatibility with 1.10 API
template<typename T> using SecureVector = secure_vector<T>;

template<typename T>
std::vector<T> unlock(const secure_vector<T>& in)
   {
   std::vector<T> out(in.size());
   copy_mem(out.data(), in.data(), in.size());
   return out;
   }

template<typename T, typename Alloc>
size_t buffer_insert(std::vector<T, Alloc>& buf,
                     size_t buf_offset,
                     const T input[],
                     size_t input_length)
   {
   BOTAN_ASSERT_NOMSG(buf_offset <= buf.size());
   const size_t to_copy = std::min(input_length, buf.size() - buf_offset);
   if(to_copy > 0)
      {
      copy_mem(&buf[buf_offset], input, to_copy);
      }
   return to_copy;
   }

template<typename T, typename Alloc, typename Alloc2>
size_t buffer_insert(std::vector<T, Alloc>& buf,
                     size_t buf_offset,
                     const std::vector<T, Alloc2>& input)
   {
   BOTAN_ASSERT_NOMSG(buf_offset <= buf.size());
   const size_t to_copy = std::min(input.size(), buf.size() - buf_offset);
   if(to_copy > 0)
      {
      copy_mem(&buf[buf_offset], input.data(), to_copy);
      }
   return to_copy;
   }

template<typename T, typename Alloc, typename Alloc2>
std::vector<T, Alloc>&
operator+=(std::vector<T, Alloc>& out,
           const std::vector<T, Alloc2>& in)
   {
   const size_t copy_offset = out.size();
   out.resize(out.size() + in.size());
   if(in.size() > 0)
      {
      copy_mem(&out[copy_offset], in.data(), in.size());
      }
   return out;
   }

template<typename T, typename Alloc>
std::vector<T, Alloc>& operator+=(std::vector<T, Alloc>& out, T in)
   {
   out.push_back(in);
   return out;
   }

template<typename T, typename Alloc, typename L>
std::vector<T, Alloc>& operator+=(std::vector<T, Alloc>& out,
                                  const std::pair<const T*, L>& in)
   {
   const size_t copy_offset = out.size();
   out.resize(out.size() + in.second);
   if(in.second > 0)
      {
      copy_mem(&out[copy_offset], in.first, in.second);
      }
   return out;
   }

template<typename T, typename Alloc, typename L>
std::vector<T, Alloc>& operator+=(std::vector<T, Alloc>& out,
                                  const std::pair<T*, L>& in)
   {
   const size_t copy_offset = out.size();
   out.resize(out.size() + in.second);
   if(in.second > 0)
      {
      copy_mem(&out[copy_offset], in.first, in.second);
      }
   return out;
   }

/**
* Zeroise the values; length remains unchanged
* @param vec the vector to zeroise
*/
template<typename T, typename Alloc>
void zeroise(std::vector<T, Alloc>& vec)
   {
   clear_mem(vec.data(), vec.size());
   }

/**
* Zeroise the values then free the memory
* @param vec the vector to zeroise and free
*/
template<typename T, typename Alloc>
void zap(std::vector<T, Alloc>& vec)
   {
   zeroise(vec);
   vec.clear();
   vec.shrink_to_fit();
   }

}

namespace Botan {

/**
* Base class for all exceptions thrown by the library
*/
class BOTAN_PUBLIC_API(2,0) Exception : public std::exception
   {
   public:
      Exception(const char* prefix, const std::string& msg);
      explicit Exception(const std::string& msg);
      const char* what() const BOTAN_NOEXCEPT override { return m_msg.c_str(); }
   protected:
      Exception(const std::string& msg, const std::exception& e);
   private:
      std::string m_msg;
   };

/**
* An invalid argument
*/
class BOTAN_PUBLIC_API(2,0) Invalid_Argument : public Exception
   {
   public:
      explicit Invalid_Argument(const std::string& msg);

      explicit Invalid_Argument(const std::string& msg, const std::string& where);

      Invalid_Argument(const std::string& msg, const std::exception& e);
   };

/**
* Unsupported_Argument Exception
*
* An argument that is invalid because it is not supported by Botan.
* It might or might not be valid in another context like a standard.
*/
class BOTAN_PUBLIC_API(2,0) Unsupported_Argument final : public Invalid_Argument
   {
   public:
      explicit Unsupported_Argument(const std::string& msg) : Invalid_Argument(msg) {}
   };

/**
* Invalid_State Exception
*/
class BOTAN_PUBLIC_API(2,0) Invalid_State : public Exception
   {
   public:
      explicit Invalid_State(const std::string& err) : Exception(err) {}
   };

class BOTAN_PUBLIC_API(2,4) Key_Not_Set : public Invalid_State
   {
   public:
      explicit Key_Not_Set(const std::string& algo);
   };

/**
* Lookup_Error Exception
*/
class BOTAN_PUBLIC_API(2,0) Lookup_Error : public Exception
   {
   public:
      explicit Lookup_Error(const std::string& err) : Exception(err) {}

      Lookup_Error(const std::string& type,
                   const std::string& algo,
                   const std::string& provider);
   };

/**
* Internal_Error Exception
*/
class BOTAN_PUBLIC_API(2,0) Internal_Error : public Exception
   {
   public:
      explicit Internal_Error(const std::string& err);
   };

/**
* Invalid_Key_Length Exception
*/
class BOTAN_PUBLIC_API(2,0) Invalid_Key_Length final : public Invalid_Argument
   {
   public:
      Invalid_Key_Length(const std::string& name, size_t length);
   };

/**
* Invalid_IV_Length Exception
*/
class BOTAN_PUBLIC_API(2,0) Invalid_IV_Length final : public Invalid_Argument
   {
   public:
      Invalid_IV_Length(const std::string& mode, size_t bad_len);
   };

/**
* PRNG_Unseeded Exception
*/
class BOTAN_PUBLIC_API(2,0) PRNG_Unseeded final : public Invalid_State
   {
   public:
      explicit PRNG_Unseeded(const std::string& algo);
   };

/**
* Policy_Violation Exception
*/
class BOTAN_PUBLIC_API(2,0) Policy_Violation final : public Invalid_State
   {
   public:
      BOTAN_DEPRECATED("deprecated") explicit Policy_Violation(const std::string& err);
   };

/**
* Algorithm_Not_Found Exception
*/
class BOTAN_PUBLIC_API(2,0) Algorithm_Not_Found final : public Lookup_Error
   {
   public:
      explicit Algorithm_Not_Found(const std::string& name);
   };

/**
* No_Provider_Found Exception
*/
class BOTAN_PUBLIC_API(2,0) No_Provider_Found final : public Exception
   {
   public:
      BOTAN_DEPRECATED("deprecated") explicit No_Provider_Found(const std::string& name);
   };

/**
* Provider_Not_Found is thrown when a specific provider was requested
* but that provider is not available.
*/
class BOTAN_PUBLIC_API(2,0) Provider_Not_Found final : public Lookup_Error
   {
   public:
      Provider_Not_Found(const std::string& algo, const std::string& provider);
   };

/**
* Invalid_Algorithm_Name Exception
*/
class BOTAN_PUBLIC_API(2,0) Invalid_Algorithm_Name final : public Invalid_Argument
   {
   public:
      explicit Invalid_Algorithm_Name(const std::string& name);
   };

/**
* Encoding_Error Exception
*/
class BOTAN_PUBLIC_API(2,0) Encoding_Error final : public Invalid_Argument
   {
   public:
      explicit Encoding_Error(const std::string& name);
   };

/**
* Decoding_Error Exception
*/
class BOTAN_PUBLIC_API(2,0) Decoding_Error : public Invalid_Argument
   {
   public:
      explicit Decoding_Error(const std::string& name);

      Decoding_Error(const std::string& name, const char* exception_message);

      Decoding_Error(const std::string& msg, const std::exception& e);
   };

/**
* Integrity_Failure Exception
*/
class BOTAN_PUBLIC_API(2,0) Integrity_Failure final : public Exception
   {
   public:
      explicit Integrity_Failure(const std::string& msg);
   };

/**
* Invalid_OID Exception
*/
class BOTAN_PUBLIC_API(2,0) Invalid_OID final : public Decoding_Error
   {
   public:
      explicit Invalid_OID(const std::string& oid);
   };

/**
* Stream_IO_Error Exception
*/
class BOTAN_PUBLIC_API(2,0) Stream_IO_Error final : public Exception
   {
   public:
      explicit Stream_IO_Error(const std::string& err);
   };

/**
* Self Test Failure Exception
*/
class BOTAN_PUBLIC_API(2,0) Self_Test_Failure final : public Internal_Error
   {
   public:
      BOTAN_DEPRECATED("deprecated") explicit Self_Test_Failure(const std::string& err);
   };

/**
* Not Implemented Exception
*/
class BOTAN_PUBLIC_API(2,0) Not_Implemented final : public Exception
   {
   public:
      explicit Not_Implemented(const std::string& err);
   };

}

namespace Botan {

class BER_Decoder;
class DER_Encoder;

/**
* ASN.1 Type and Class Tags
*/
enum ASN1_Tag : uint32_t {
   UNIVERSAL        = 0x00,
   APPLICATION      = 0x40,
   CONTEXT_SPECIFIC = 0x80,

   CONSTRUCTED      = 0x20,

   PRIVATE          = CONSTRUCTED | CONTEXT_SPECIFIC,

   EOC              = 0x00,
   BOOLEAN          = 0x01,
   INTEGER          = 0x02,
   BIT_STRING       = 0x03,
   OCTET_STRING     = 0x04,
   NULL_TAG         = 0x05,
   OBJECT_ID        = 0x06,
   ENUMERATED       = 0x0A,
   SEQUENCE         = 0x10,
   SET              = 0x11,

   UTF8_STRING      = 0x0C,
   NUMERIC_STRING   = 0x12,
   PRINTABLE_STRING = 0x13,
   T61_STRING       = 0x14,
   IA5_STRING       = 0x16,
   VISIBLE_STRING   = 0x1A,
   UNIVERSAL_STRING = 0x1C,
   BMP_STRING       = 0x1E,

   UTC_TIME                = 0x17,
   GENERALIZED_TIME        = 0x18,
   UTC_OR_GENERALIZED_TIME = 0x19,

   NO_OBJECT        = 0xFF00,
   DIRECTORY_STRING = 0xFF01
};

std::string BOTAN_UNSTABLE_API asn1_tag_to_string(ASN1_Tag type);
std::string BOTAN_UNSTABLE_API asn1_class_to_string(ASN1_Tag type);

/**
* Basic ASN.1 Object Interface
*/
class BOTAN_PUBLIC_API(2,0) ASN1_Object
   {
   public:
      /**
      * Encode whatever this object is into to
      * @param to the DER_Encoder that will be written to
      */
      virtual void encode_into(DER_Encoder& to) const = 0;

      /**
      * Decode whatever this object is from from
      * @param from the BER_Decoder that will be read from
      */
      virtual void decode_from(BER_Decoder& from) = 0;

      /**
      * Return the encoding of this object. This is a convenience
      * method when just one object needs to be serialized. Use
      * DER_Encoder for complicated encodings.
      */
      std::vector<uint8_t> BER_encode() const;

      ASN1_Object() = default;
      ASN1_Object(const ASN1_Object&) = default;
      ASN1_Object & operator=(const ASN1_Object&) = default;
      virtual ~ASN1_Object() = default;
   };

/**
* BER Encoded Object
*/
class BOTAN_PUBLIC_API(2,0) BER_Object final
   {
   public:
      BER_Object() : type_tag(NO_OBJECT), class_tag(UNIVERSAL) {}

      BER_Object(const BER_Object& other) = default;

      BER_Object& operator=(const BER_Object& other) = default;

#if !defined(BOTAN_BUILD_COMPILER_IS_MSVC_2013)
      BER_Object(BER_Object&& other) = default;

      BER_Object& operator=(BER_Object&& other) = default;
#endif

      bool is_set() const { return type_tag != NO_OBJECT; }

      ASN1_Tag tagging() const { return ASN1_Tag(type() | get_class()); }

      ASN1_Tag type() const { return type_tag; }
      ASN1_Tag get_class() const { return class_tag; }

      const uint8_t* bits() const { return value.data(); }

      size_t length() const { return value.size(); }

      void assert_is_a(ASN1_Tag type_tag, ASN1_Tag class_tag,
                       const std::string& descr = "object") const;

      bool is_a(ASN1_Tag type_tag, ASN1_Tag class_tag) const;

      bool is_a(int type_tag, ASN1_Tag class_tag) const;

   BOTAN_DEPRECATED_PUBLIC_MEMBER_VARIABLES:
      /*
      * The following member variables are public for historical reasons, but
      * will be made private in a future major release. Use the accessor
      * functions above.
      */
      ASN1_Tag type_tag, class_tag;
      secure_vector<uint8_t> value;

   private:

      friend class BER_Decoder;

      void set_tagging(ASN1_Tag type_tag, ASN1_Tag class_tag);

      uint8_t* mutable_bits(size_t length)
         {
         value.resize(length);
         return value.data();
         }
   };

/*
* ASN.1 Utility Functions
*/
class DataSource;

namespace ASN1 {

std::vector<uint8_t> put_in_sequence(const std::vector<uint8_t>& val);
std::vector<uint8_t> put_in_sequence(const uint8_t bits[], size_t len);
std::string to_string(const BER_Object& obj);

/**
* Heuristics tests; is this object possibly BER?
* @param src a data source that will be peeked at but not modified
*/
bool maybe_BER(DataSource& src);

}

/**
* General BER Decoding Error Exception
*/
class BOTAN_PUBLIC_API(2,0) BER_Decoding_Error : public Decoding_Error
   {
   public:
      explicit BER_Decoding_Error(const std::string&);
   };

/**
* Exception For Incorrect BER Taggings
*/
class BOTAN_PUBLIC_API(2,0) BER_Bad_Tag final : public BER_Decoding_Error
   {
   public:
      BER_Bad_Tag(const std::string& msg, ASN1_Tag tag);
      BER_Bad_Tag(const std::string& msg, ASN1_Tag tag1, ASN1_Tag tag2);
   };

}

namespace Botan {

/**
* This class represents ASN.1 object identifiers.
*/
class BOTAN_PUBLIC_API(2,0) OID final : public ASN1_Object
   {
   public:
      void encode_into(class DER_Encoder&) const override;
      void decode_from(class BER_Decoder&) override;

      /**
      * Find out whether this OID is empty
      * @return true is no OID value is set
      */
      bool empty() const { return m_id.empty(); }

      /**
      * Find out whether this OID has a value
      * @return true is this OID has a value
      */
      bool has_value() const { return (m_id.empty() == false); }

      /**
      * Get this OID as list (vector) of its components.
      * @return vector representing this OID
      */
      const std::vector<uint32_t>& get_id() const { return m_id; }

      /**
      * Get this OID as a string
      * @return string representing this OID
      */
      std::string as_string() const { return this->to_string(); }

      /**
      * Get this OID as a string
      * @return string representing this OID
      */
      std::string to_string() const;

      /**
      * Compare two OIDs.
      * @return true if they are equal, false otherwise
      */
      bool operator==(const OID&) const;

      /**
      * Reset this instance to an empty OID.
      */
      void clear();

      /**
      * Add a component to this OID.
      * @param new_comp the new component to add to the end of this OID
      * @return reference to *this
      */
      OID& operator+=(uint32_t new_comp);

      /**
      * Construct an OID from a string.
      * @param str a string in the form "a.b.c" etc., where a,b,c are numbers
      */
      OID(const std::string& str = "");

      explicit OID(std::initializer_list<uint32_t> init) : m_id(init) {}
   private:
      std::vector<uint32_t> m_id;
   };

/**
* Append another component onto the OID.
* @param oid the OID to add the new component to
* @param new_comp the new component to add
*/
OID BOTAN_PUBLIC_API(2,0) operator+(const OID& oid, uint32_t new_comp);

/**
* Compare two OIDs.
* @param a the first OID
* @param b the second OID
* @return true if a is not equal to b
*/
bool BOTAN_PUBLIC_API(2,0) operator!=(const OID& a, const OID& b);

/**
* Compare two OIDs.
* @param a the first OID
* @param b the second OID
* @return true if a is lexicographically smaller than b
*/
bool BOTAN_PUBLIC_API(2,0) operator<(const OID& a, const OID& b);

}

namespace Botan {

/**
* Algorithm Identifier
*/
class BOTAN_PUBLIC_API(2,0) AlgorithmIdentifier final : public ASN1_Object
   {
   public:
      enum Encoding_Option { USE_NULL_PARAM, USE_EMPTY_PARAM };

      void encode_into(class DER_Encoder&) const override;
      void decode_from(class BER_Decoder&) override;

      AlgorithmIdentifier() = default;

      AlgorithmIdentifier(const OID& oid, Encoding_Option enc);
      AlgorithmIdentifier(const std::string& oid_name, Encoding_Option enc);

      AlgorithmIdentifier(const OID& oid, const std::vector<uint8_t>& params);
      AlgorithmIdentifier(const std::string& oid_name, const std::vector<uint8_t>& params);

      const OID& get_oid() const { return oid; }
      const std::vector<uint8_t>& get_parameters() const { return parameters; }

   BOTAN_DEPRECATED_PUBLIC_MEMBER_VARIABLES:
      /*
      * These values are public for historical reasons, but in a future release
      * they will be made private. Do not access them.
      */
      OID oid;
      std::vector<uint8_t> parameters;
   };

/*
* Comparison Operations
*/
bool BOTAN_PUBLIC_API(2,0) operator==(const AlgorithmIdentifier&,
                                      const AlgorithmIdentifier&);
bool BOTAN_PUBLIC_API(2,0) operator!=(const AlgorithmIdentifier&,
                                      const AlgorithmIdentifier&);

}

namespace Botan {

/**
* Attribute
*/
class BOTAN_PUBLIC_API(2,0) Attribute final : public ASN1_Object
   {
   public:
      void encode_into(class DER_Encoder& to) const override;
      void decode_from(class BER_Decoder& from) override;

      Attribute() = default;
      Attribute(const OID&, const std::vector<uint8_t>&);
      Attribute(const std::string&, const std::vector<uint8_t>&);

      const OID& get_oid() const { return oid; }

      const std::vector<uint8_t>& get_parameters() const { return parameters; }

   BOTAN_DEPRECATED_PUBLIC_MEMBER_VARIABLES:
      /*
      * These values are public for historical reasons, but in a future release
      * they will be made private. Do not access them.
      */
      OID oid;
      std::vector<uint8_t> parameters;
   };

}

namespace Botan {

class BER_Decoder;

/**
* Format ASN.1 data and call a virtual to format
*/
class BOTAN_PUBLIC_API(2,4) ASN1_Formatter
   {
   public:
      virtual ~ASN1_Formatter() = default;

      /**
      * @param print_context_specific if true, try to parse nested context specific data.
      * @param max_depth do not recurse more than this many times. If zero, recursion
      *        is unbounded.
      */
      ASN1_Formatter(bool print_context_specific, size_t max_depth) :
         m_print_context_specific(print_context_specific),
         m_max_depth(max_depth)
         {}

      void print_to_stream(std::ostream& out,
                           const uint8_t in[],
                           size_t len) const;

      std::string print(const uint8_t in[], size_t len) const;

      template<typename Alloc>
      std::string print(const std::vector<uint8_t, Alloc>& vec) const
         {
         return print(vec.data(), vec.size());
         }

   protected:
      /**
      * This is called for each element
      */
      virtual std::string format(ASN1_Tag type_tag,
                                 ASN1_Tag class_tag,
                                 size_t level,
                                 size_t length,
                                 const std::string& value) const = 0;

      /**
      * This is called to format binary elements that we don't know how to
      * convert to a string The result will be passed as value to format; the
      * tags are included as a hint to aid decoding.
      */
      virtual std::string format_bin(ASN1_Tag type_tag,
                                     ASN1_Tag class_tag,
                                     const std::vector<uint8_t>& vec) const = 0;

   private:
      void decode(std::ostream& output,
                  BER_Decoder& decoder,
                  size_t level) const;

      const bool m_print_context_specific;
      const size_t m_max_depth;
   };

/**
* Format ASN.1 data into human readable output. The exact form of the output for
* any particular input is not guaranteed and may change from release to release.
*/
class BOTAN_PUBLIC_API(2,4) ASN1_Pretty_Printer final : public ASN1_Formatter
   {
   public:
      /**
      * @param print_limit strings larger than this are not printed
      * @param print_binary_limit binary strings larger than this are not printed
      * @param print_context_specific if true, try to parse nested context specific data.
      * @param initial_level the initial depth (0 or 1 are the only reasonable values)
      * @param value_column ASN.1 values are lined up at this column in output
      * @param max_depth do not recurse more than this many times. If zero, recursion
      *        is unbounded.
      */
      ASN1_Pretty_Printer(size_t print_limit = 4096,
                          size_t print_binary_limit = 2048,
                          bool print_context_specific = true,
                          size_t initial_level = 0,
                          size_t value_column = 60,
                          size_t max_depth = 64) :
         ASN1_Formatter(print_context_specific, max_depth),
         m_print_limit(print_limit),
         m_print_binary_limit(print_binary_limit),
         m_initial_level(initial_level),
         m_value_column(value_column)
         {}

   private:
      std::string format(ASN1_Tag type_tag,
                         ASN1_Tag class_tag,
                         size_t level,
                         size_t length,
                         const std::string& value) const override;

      std::string format_bin(ASN1_Tag type_tag,
                             ASN1_Tag class_tag,
                             const std::vector<uint8_t>& vec) const override;

      const size_t m_print_limit;
      const size_t m_print_binary_limit;
      const size_t m_initial_level;
      const size_t m_value_column;
   };

}

namespace Botan {

/**
* ASN.1 string type
* This class normalizes all inputs to a UTF-8 std::string
*/
class BOTAN_PUBLIC_API(2,0) ASN1_String final : public ASN1_Object
   {
   public:
      void encode_into(class DER_Encoder&) const override;
      void decode_from(class BER_Decoder&) override;

      ASN1_Tag tagging() const { return m_tag; }

      const std::string& value() const { return m_utf8_str; }

      size_t size() const { return value().size(); }

      bool empty() const { return m_utf8_str.empty(); }

      std::string BOTAN_DEPRECATED("Use value() to get UTF-8 string instead")
         iso_8859() const;

      /**
      * Return true iff this is a tag for a known string type we can handle.
      * This ignores string types that are not supported, eg teletexString
      */
      static bool is_string_type(ASN1_Tag tag);

      bool operator==(const ASN1_String& other) const
         { return value() == other.value(); }

      explicit ASN1_String(const std::string& utf8 = "");
      ASN1_String(const std::string& utf8, ASN1_Tag tag);
   private:
      std::vector<uint8_t> m_data;
      std::string m_utf8_str;
      ASN1_Tag m_tag;
   };

}

namespace Botan {

/**
* X.509 Time
*/
class BOTAN_PUBLIC_API(2,0) X509_Time final : public ASN1_Object
   {
   public:
      /// DER encode a X509_Time
      void encode_into(DER_Encoder&) const override;

      // Decode a BER encoded X509_Time
      void decode_from(BER_Decoder&) override;

      /// Return an internal string representation of the time
      std::string to_string() const;

      /// Returns a human friendly string replesentation of no particular formatting
      std::string readable_string() const;

      /// Return if the time has been set somehow
      bool time_is_set() const;

      ///  Compare this time against another
      int32_t cmp(const X509_Time& other) const;

      /// Create an invalid X509_Time
      X509_Time() = default;

      /// Create a X509_Time from a time point
      explicit X509_Time(const std::chrono::system_clock::time_point& time);

      /// Create an X509_Time from string
      X509_Time(const std::string& t_spec, ASN1_Tag tag);

      /// Returns a STL timepoint object
      std::chrono::system_clock::time_point to_std_timepoint() const;

      /// Return time since epoch
      uint64_t time_since_epoch() const;

   private:
      void set_to(const std::string& t_spec, ASN1_Tag);
      bool passes_sanity_check() const;

      uint32_t m_year = 0;
      uint32_t m_month = 0;
      uint32_t m_day = 0;
      uint32_t m_hour = 0;
      uint32_t m_minute = 0;
      uint32_t m_second = 0;
      ASN1_Tag m_tag = NO_OBJECT;
   };

/*
* Comparison Operations
*/
bool BOTAN_PUBLIC_API(2,0) operator==(const X509_Time&, const X509_Time&);
bool BOTAN_PUBLIC_API(2,0) operator!=(const X509_Time&, const X509_Time&);
bool BOTAN_PUBLIC_API(2,0) operator<=(const X509_Time&, const X509_Time&);
bool BOTAN_PUBLIC_API(2,0) operator>=(const X509_Time&, const X509_Time&);
bool BOTAN_PUBLIC_API(2,0) operator<(const X509_Time&, const X509_Time&);
bool BOTAN_PUBLIC_API(2,0) operator>(const X509_Time&, const X509_Time&);

typedef X509_Time ASN1_Time;

}

#if defined(BOTAN_TARGET_OS_HAS_THREADS)


namespace Botan {

template<typename T> using lock_guard_type = std::lock_guard<T>;
typedef std::mutex mutex_type;

}

#else

// No threads

namespace Botan {

template<typename Mutex>
class lock_guard final
   {
   public:
      explicit lock_guard(Mutex& m) : m_mutex(m)
         { m_mutex.lock(); }

      ~lock_guard() { m_mutex.unlock(); }

      lock_guard(const lock_guard& other) = delete;
      lock_guard& operator=(const lock_guard& other) = delete;
   private:
      Mutex& m_mutex;
   };

class noop_mutex final
   {
   public:
      void lock() {}
      void unlock() {}
   };

typedef noop_mutex mutex_type;
template<typename T> using lock_guard_type = lock_guard<T>;

}

#endif

namespace Botan {

class Entropy_Sources;

/**
* An interface to a cryptographic random number generator
*/
class BOTAN_PUBLIC_API(2,0) RandomNumberGenerator
   {
   public:
      virtual ~RandomNumberGenerator() = default;

      RandomNumberGenerator() = default;

      /*
      * Never copy a RNG, create a new one
      */
      RandomNumberGenerator(const RandomNumberGenerator& rng) = delete;
      RandomNumberGenerator& operator=(const RandomNumberGenerator& rng) = delete;

      /**
      * Randomize a byte array.
      * @param output the byte array to hold the random output.
      * @param length the length of the byte array output in bytes.
      */
      virtual void randomize(uint8_t output[], size_t length) = 0;

      /**
      * Returns false if it is known that this RNG object is not able to accept
      * externally provided inputs (via add_entropy, randomize_with_input, etc).
      * In this case, any such provided inputs are ignored.
      *
      * If this function returns true, then inputs may or may not be accepted.
      */
      virtual bool accepts_input() const = 0;

      /**
      * Incorporate some additional data into the RNG state. For
      * example adding nonces or timestamps from a peer's protocol
      * message can help hedge against VM state rollback attacks.
      * A few RNG types do not accept any externally provided input,
      * in which case this function is a no-op.
      *
      * @param input a byte array containg the entropy to be added
      * @param length the length of the byte array in
      */
      virtual void add_entropy(const uint8_t input[], size_t length) = 0;

      /**
      * Incorporate some additional data into the RNG state.
      */
      template<typename T> void add_entropy_T(const T& t)
         {
         this->add_entropy(reinterpret_cast<const uint8_t*>(&t), sizeof(T));
         }

      /**
      * Incorporate entropy into the RNG state then produce output.
      * Some RNG types implement this using a single operation, default
      * calls add_entropy + randomize in sequence.
      *
      * Use this to further bind the outputs to your current
      * process/protocol state. For instance if generating a new key
      * for use in a session, include a session ID or other such
      * value. See NIST SP 800-90 A, B, C series for more ideas.
      *
      * @param output buffer to hold the random output
      * @param output_len size of the output buffer in bytes
      * @param input entropy buffer to incorporate
      * @param input_len size of the input buffer in bytes
      */
      virtual void randomize_with_input(uint8_t output[], size_t output_len,
                                        const uint8_t input[], size_t input_len);

      /**
      * This calls `randomize_with_input` using some timestamps as extra input.
      *
      * For a stateful RNG using non-random but potentially unique data the
      * extra input can help protect against problems with fork, VM state
      * rollback, or other cases where somehow an RNG state is duplicated. If
      * both of the duplicated RNG states later incorporate a timestamp (and the
      * timestamps don't themselves repeat), their outputs will diverge.
      */
      virtual void randomize_with_ts_input(uint8_t output[], size_t output_len);

      /**
      * @return the name of this RNG type
      */
      virtual std::string name() const = 0;

      /**
      * Clear all internally held values of this RNG
      * @post is_seeded() == false
      */
      virtual void clear() = 0;

      /**
      * Check whether this RNG is seeded.
      * @return true if this RNG was already seeded, false otherwise.
      */
      virtual bool is_seeded() const = 0;

      /**
      * Poll provided sources for up to poll_bits bits of entropy
      * or until the timeout expires. Returns estimate of the number
      * of bits collected.
      */
      virtual size_t reseed(Entropy_Sources& srcs,
                            size_t poll_bits = BOTAN_RNG_RESEED_POLL_BITS,
                            std::chrono::milliseconds poll_timeout = BOTAN_RNG_RESEED_DEFAULT_TIMEOUT);

      /**
      * Reseed by reading specified bits from the RNG
      */
      virtual void reseed_from_rng(RandomNumberGenerator& rng,
                                   size_t poll_bits = BOTAN_RNG_RESEED_POLL_BITS);

      // Some utility functions built on the interface above:

      /**
      * Return a random vector
      * @param bytes number of bytes in the result
      * @return randomized vector of length bytes
      */
      secure_vector<uint8_t> random_vec(size_t bytes)
         {
         secure_vector<uint8_t> output(bytes);
         this->randomize(output.data(), output.size());
         return output;
         }

      /**
      * Return a random byte
      * @return random byte
      */
      uint8_t next_byte()
         {
         uint8_t b;
         this->randomize(&b, 1);
         return b;
         }

      /**
      * @return a random byte that is greater than zero
      */
      uint8_t next_nonzero_byte()
         {
         uint8_t b = this->next_byte();
         while(b == 0)
            b = this->next_byte();
         return b;
         }

      /**
      * Create a seeded and active RNG object for general application use
      * Added in 1.8.0
      * Use AutoSeeded_RNG instead
      */
      BOTAN_DEPRECATED("Use AutoSeeded_RNG")
      static RandomNumberGenerator* make_rng();
   };

/**
* Convenience typedef
*/
typedef RandomNumberGenerator RNG;

/**
* Hardware_RNG exists to tag hardware RNG types (PKCS11_RNG, TPM_RNG, RDRAND_RNG)
*/
class BOTAN_PUBLIC_API(2,0) Hardware_RNG : public RandomNumberGenerator
   {
   public:
      virtual void clear() final override { /* no way to clear state of hardware RNG */ }
   };

/**
* Null/stub RNG - fails if you try to use it for anything
* This is not generally useful except for in certain tests
*/
class BOTAN_PUBLIC_API(2,0) Null_RNG final : public RandomNumberGenerator
   {
   public:
      bool is_seeded() const override { return false; }

      bool accepts_input() const override { return false; }

      void clear() override {}

      void randomize(uint8_t[], size_t) override
         {
         throw PRNG_Unseeded("Null_RNG called");
         }

      void add_entropy(const uint8_t[], size_t) override {}

      std::string name() const override { return "Null_RNG"; }
   };

#if defined(BOTAN_TARGET_OS_HAS_THREADS)
/**
* Wraps access to a RNG in a mutex
* Note that most of the time it's much better to use a RNG per thread
* otherwise the RNG will act as an unnecessary contention point
*/
class BOTAN_PUBLIC_API(2,0) Serialized_RNG final : public RandomNumberGenerator
   {
   public:
      void randomize(uint8_t out[], size_t len) override
         {
         lock_guard_type<mutex_type> lock(m_mutex);
         m_rng->randomize(out, len);
         }

      bool accepts_input() const override
         {
         lock_guard_type<mutex_type> lock(m_mutex);
         return m_rng->accepts_input();
         }

      bool is_seeded() const override
         {
         lock_guard_type<mutex_type> lock(m_mutex);
         return m_rng->is_seeded();
         }

      void clear() override
         {
         lock_guard_type<mutex_type> lock(m_mutex);
         m_rng->clear();
         }

      std::string name() const override
         {
         lock_guard_type<mutex_type> lock(m_mutex);
         return m_rng->name();
         }

      size_t reseed(Entropy_Sources& src,
                    size_t poll_bits = BOTAN_RNG_RESEED_POLL_BITS,
                    std::chrono::milliseconds poll_timeout = BOTAN_RNG_RESEED_DEFAULT_TIMEOUT) override
         {
         lock_guard_type<mutex_type> lock(m_mutex);
         return m_rng->reseed(src, poll_bits, poll_timeout);
         }

      void add_entropy(const uint8_t in[], size_t len) override
         {
         lock_guard_type<mutex_type> lock(m_mutex);
         m_rng->add_entropy(in, len);
         }

      BOTAN_DEPRECATED("Use Serialized_RNG(new AutoSeeded_RNG)") Serialized_RNG();

      explicit Serialized_RNG(RandomNumberGenerator* rng) : m_rng(rng) {}
   private:
      mutable mutex_type m_mutex;
      std::unique_ptr<RandomNumberGenerator> m_rng;
   };
#endif

}

namespace Botan {

class Stateful_RNG;

/**
* A userspace PRNG
*/
class BOTAN_PUBLIC_API(2,0) AutoSeeded_RNG final : public RandomNumberGenerator
   {
   public:
      void randomize(uint8_t out[], size_t len) override;

      void randomize_with_input(uint8_t output[], size_t output_len,
                                const uint8_t input[], size_t input_len) override;

      bool is_seeded() const override;

      bool accepts_input() const override { return true; }

      /**
      * Mark state as requiring a reseed on next use
      */
      void force_reseed();

      size_t reseed(Entropy_Sources& srcs,
                    size_t poll_bits = BOTAN_RNG_RESEED_POLL_BITS,
                    std::chrono::milliseconds poll_timeout = BOTAN_RNG_RESEED_DEFAULT_TIMEOUT) override;

      void add_entropy(const uint8_t in[], size_t len) override;

      std::string name() const override;

      void clear() override;

      /**
      * Uses the system RNG (if available) or else a default group of
      * entropy sources (all other systems) to gather seed material.
      *
      * @param reseed_interval specifies a limit of how many times
      * the RNG will be called before automatic reseeding is performed
      */
      AutoSeeded_RNG(size_t reseed_interval = BOTAN_RNG_DEFAULT_RESEED_INTERVAL);

      /**
      * Create an AutoSeeded_RNG which will get seed material from some other
      * RNG instance. For example you could provide a reference to the system
      * RNG or a hardware RNG.
      *
      * @param underlying_rng is a reference to some RNG which will be used
      * to perform the periodic reseeding
      * @param reseed_interval specifies a limit of how many times
      * the RNG will be called before automatic reseeding is performed
      */
      AutoSeeded_RNG(RandomNumberGenerator& underlying_rng,
                     size_t reseed_interval = BOTAN_RNG_DEFAULT_RESEED_INTERVAL);

      /**
      * Create an AutoSeeded_RNG which will get seed material from a set of
      * entropy sources.
      *
      * @param entropy_sources will be polled to perform reseeding periodically
      * @param reseed_interval specifies a limit of how many times
      * the RNG will be called before automatic reseeding is performed
      */
      AutoSeeded_RNG(Entropy_Sources& entropy_sources,
                     size_t reseed_interval = BOTAN_RNG_DEFAULT_RESEED_INTERVAL);

      /**
      * Create an AutoSeeded_RNG which will get seed material from both an
      * underlying RNG and a set of entropy sources.
      *
      * @param underlying_rng is a reference to some RNG which will be used
      * to perform the periodic reseeding
      * @param entropy_sources will be polled to perform reseeding periodically
      * @param reseed_interval specifies a limit of how many times
      * the RNG will be called before automatic reseeding is performed
      */
      AutoSeeded_RNG(RandomNumberGenerator& underlying_rng,
                     Entropy_Sources& entropy_sources,
                     size_t reseed_interval = BOTAN_RNG_DEFAULT_RESEED_INTERVAL);

      ~AutoSeeded_RNG();

   private:
      std::unique_ptr<Stateful_RNG> m_rng;
   };

}

namespace Botan {

/**
* Perform base64 encoding
* @param output an array of at least base64_encode_max_output bytes
* @param input is some binary data
* @param input_length length of input in bytes
* @param input_consumed is an output parameter which says how many
*        bytes of input were actually consumed. If less than
*        input_length, then the range input[consumed:length]
*        should be passed in later along with more input.
* @param final_inputs true iff this is the last input, in which case
         padding chars will be applied if needed
* @return number of bytes written to output
*/
size_t BOTAN_PUBLIC_API(2,0) base64_encode(char output[],
                               const uint8_t input[],
                               size_t input_length,
                               size_t& input_consumed,
                               bool final_inputs);

/**
* Perform base64 encoding
* @param input some input
* @param input_length length of input in bytes
* @return base64adecimal representation of input
*/
std::string BOTAN_PUBLIC_API(2,0) base64_encode(const uint8_t input[],
                                    size_t input_length);

/**
* Perform base64 encoding
* @param input some input
* @return base64adecimal representation of input
*/
template<typename Alloc>
std::string base64_encode(const std::vector<uint8_t, Alloc>& input)
   {
   return base64_encode(input.data(), input.size());
   }

/**
* Perform base64 decoding
* @param output an array of at least base64_decode_max_output bytes
* @param input some base64 input
* @param input_length length of input in bytes
* @param input_consumed is an output parameter which says how many
*        bytes of input were actually consumed. If less than
*        input_length, then the range input[consumed:length]
*        should be passed in later along with more input.
* @param final_inputs true iff this is the last input, in which case
         padding is allowed
* @param ignore_ws ignore whitespace on input; if false, throw an
                   exception if whitespace is encountered
* @return number of bytes written to output
*/
size_t BOTAN_PUBLIC_API(2,0) base64_decode(uint8_t output[],
                               const char input[],
                               size_t input_length,
                               size_t& input_consumed,
                               bool final_inputs,
                               bool ignore_ws = true);

/**
* Perform base64 decoding
* @param output an array of at least base64_decode_max_output bytes
* @param input some base64 input
* @param input_length length of input in bytes
* @param ignore_ws ignore whitespace on input; if false, throw an
                   exception if whitespace is encountered
* @return number of bytes written to output
*/
size_t BOTAN_PUBLIC_API(2,0) base64_decode(uint8_t output[],
                               const char input[],
                               size_t input_length,
                               bool ignore_ws = true);

/**
* Perform base64 decoding
* @param output an array of at least base64_decode_max_output bytes
* @param input some base64 input
* @param ignore_ws ignore whitespace on input; if false, throw an
                   exception if whitespace is encountered
* @return number of bytes written to output
*/
size_t BOTAN_PUBLIC_API(2,0) base64_decode(uint8_t output[],
                               const std::string& input,
                               bool ignore_ws = true);

/**
* Perform base64 decoding
* @param input some base64 input
* @param input_length the length of input in bytes
* @param ignore_ws ignore whitespace on input; if false, throw an
                   exception if whitespace is encountered
* @return decoded base64 output
*/
secure_vector<uint8_t> BOTAN_PUBLIC_API(2,0) base64_decode(const char input[],
                                           size_t input_length,
                                           bool ignore_ws = true);

/**
* Perform base64 decoding
* @param input some base64 input
* @param ignore_ws ignore whitespace on input; if false, throw an
                   exception if whitespace is encountered
* @return decoded base64 output
*/
secure_vector<uint8_t> BOTAN_PUBLIC_API(2,0) base64_decode(const std::string& input,
                                           bool ignore_ws = true);

/**
* Calculate the size of output buffer for base64_encode
* @param input_length the length of input in bytes
* @return the size of output buffer in bytes
*/
size_t BOTAN_PUBLIC_API(2,1) base64_encode_max_output(size_t input_length);

/**
* Calculate the size of output buffer for base64_decode
* @param input_length the length of input in bytes
* @return the size of output buffer in bytes
*/
size_t BOTAN_PUBLIC_API(2,1) base64_decode_max_output(size_t input_length);

}

namespace Botan {

/**
* This class represents an abstract data source object.
*/
class BOTAN_PUBLIC_API(2,0) DataSource
   {
   public:
      /**
      * Read from the source. Moves the internal offset so that every
      * call to read will return a new portion of the source.
      *
      * @param out the byte array to write the result to
      * @param length the length of the byte array out
      * @return length in bytes that was actually read and put
      * into out
      */
      virtual size_t read(uint8_t out[], size_t length) BOTAN_WARN_UNUSED_RESULT = 0;

      virtual bool check_available(size_t n) = 0;

      /**
      * Read from the source but do not modify the internal
      * offset. Consecutive calls to peek() will return portions of
      * the source starting at the same position.
      *
      * @param out the byte array to write the output to
      * @param length the length of the byte array out
      * @param peek_offset the offset into the stream to read at
      * @return length in bytes that was actually read and put
      * into out
      */
      virtual size_t peek(uint8_t out[], size_t length, size_t peek_offset) const BOTAN_WARN_UNUSED_RESULT = 0;

      /**
      * Test whether the source still has data that can be read.
      * @return true if there is no more data to read, false otherwise
      */
      virtual bool end_of_data() const = 0;
      /**
      * return the id of this data source
      * @return std::string representing the id of this data source
      */
      virtual std::string id() const { return ""; }

      /**
      * Read one byte.
      * @param out the byte to read to
      * @return length in bytes that was actually read and put
      * into out
      */
      size_t read_byte(uint8_t& out);

      /**
      * Peek at one byte.
      * @param out an output byte
      * @return length in bytes that was actually read and put
      * into out
      */
      size_t peek_byte(uint8_t& out) const;

      /**
      * Discard the next N bytes of the data
      * @param N the number of bytes to discard
      * @return number of bytes actually discarded
      */
      size_t discard_next(size_t N);

      /**
      * @return number of bytes read so far.
      */
      virtual size_t get_bytes_read() const = 0;

      DataSource() = default;
      virtual ~DataSource() = default;
      DataSource& operator=(const DataSource&) = delete;
      DataSource(const DataSource&) = delete;
   };

/**
* This class represents a Memory-Based DataSource
*/
class BOTAN_PUBLIC_API(2,0) DataSource_Memory final : public DataSource
   {
   public:
      size_t read(uint8_t[], size_t) override;
      size_t peek(uint8_t[], size_t, size_t) const override;
      bool check_available(size_t n) override;
      bool end_of_data() const override;

      /**
      * Construct a memory source that reads from a string
      * @param in the string to read from
      */
      explicit DataSource_Memory(const std::string& in);

      /**
      * Construct a memory source that reads from a byte array
      * @param in the byte array to read from
      * @param length the length of the byte array
      */
      DataSource_Memory(const uint8_t in[], size_t length) :
         m_source(in, in + length), m_offset(0) {}

      /**
      * Construct a memory source that reads from a secure_vector
      * @param in the MemoryRegion to read from
      */
      explicit DataSource_Memory(const secure_vector<uint8_t>& in) :
         m_source(in), m_offset(0) {}

      /**
      * Construct a memory source that reads from a std::vector
      * @param in the MemoryRegion to read from
      */
      explicit DataSource_Memory(const std::vector<uint8_t>& in) :
         m_source(in.begin(), in.end()), m_offset(0) {}

      size_t get_bytes_read() const override { return m_offset; }
   private:
      secure_vector<uint8_t> m_source;
      size_t m_offset;
   };

/**
* This class represents a Stream-Based DataSource.
*/
class BOTAN_PUBLIC_API(2,0) DataSource_Stream final : public DataSource
   {
   public:
      size_t read(uint8_t[], size_t) override;
      size_t peek(uint8_t[], size_t, size_t) const override;
      bool check_available(size_t n) override;
      bool end_of_data() const override;
      std::string id() const override;

      DataSource_Stream(std::istream&,
                        const std::string& id = "<std::istream>");

#if defined(BOTAN_TARGET_OS_HAS_FILESYSTEM)
      /**
      * Construct a Stream-Based DataSource from filesystem path
      * @param file the path to the file
      * @param use_binary whether to treat the file as binary or not
      */
      DataSource_Stream(const std::string& file, bool use_binary = false);
#endif

      DataSource_Stream(const DataSource_Stream&) = delete;

      DataSource_Stream& operator=(const DataSource_Stream&) = delete;

      ~DataSource_Stream();

      size_t get_bytes_read() const override { return m_total_read; }
   private:
      const std::string m_identifier;

      std::unique_ptr<std::istream> m_source_memory;
      std::istream& m_source;
      size_t m_total_read;
   };

}

namespace Botan {

class BigInt;

/**
* BER Decoding Object
*/
class BOTAN_PUBLIC_API(2,0) BER_Decoder final
   {
   public:
      /**
      * Set up to BER decode the data in buf of length len
      */
      BER_Decoder(const uint8_t buf[], size_t len);

      /**
      * Set up to BER decode the data in vec
      */
      explicit BER_Decoder(const secure_vector<uint8_t>& vec);

      /**
      * Set up to BER decode the data in vec
      */
      explicit BER_Decoder(const std::vector<uint8_t>& vec);

      /**
      * Set up to BER decode the data in src
      */
      explicit BER_Decoder(DataSource& src);

      /**
      * Set up to BER decode the data in obj
      */
      BER_Decoder(const BER_Object& obj) :
         BER_Decoder(obj.bits(), obj.length()) {}

      /**
      * Set up to BER decode the data in obj
      */
      BER_Decoder(BER_Object&& obj) :
         BER_Decoder(std::move(obj), nullptr) {}

      BER_Decoder(const BER_Decoder& other);

      BER_Decoder& operator=(const BER_Decoder&) = delete;

      /**
      * Get the next object in the data stream.
      * If EOF, returns an object with type NO_OBJECT.
      */
      BER_Object get_next_object();

      BER_Decoder& get_next(BER_Object& ber)
         {
         ber = get_next_object();
         return (*this);
         }

      /**
      * Push an object back onto the stream. Throws if another
      * object was previously pushed and has not been subsequently
      * read out.
      */
      void push_back(const BER_Object& obj);

      /**
      * Push an object back onto the stream. Throws if another
      * object was previously pushed and has not been subsequently
      * read out.
      */
      void push_back(BER_Object&& obj);

      /**
      * Return true if there is at least one more item remaining
      */
      bool more_items() const;

      /**
      * Verify the stream is concluded, throws otherwise.
      * Returns (*this)
      */
      BER_Decoder& verify_end();

      /**
      * Verify the stream is concluded, throws otherwise.
      * Returns (*this)
      */
      BER_Decoder& verify_end(const std::string& err_msg);

      /**
      * Discard any data that remains unread
      * Returns (*this)
      */
      BER_Decoder& discard_remaining();

      /**
      * Start decoding a constructed data (sequence or set)
      */
      BER_Decoder start_cons(ASN1_Tag type_tag, ASN1_Tag class_tag = UNIVERSAL);

      /**
      * Finish decoding a constructed data, throws if any data remains.
      * Returns the parent of *this (ie the object on which start_cons was called).
      */
      BER_Decoder& end_cons();

      /**
      * Get next object and copy value to POD type
      * Asserts value length is equal to POD type sizeof.
      * Asserts Type tag and optional Class tag according to parameters.
      * Copy value to POD type (struct, union, C-style array, std::array, etc.).
      * @param out POD type reference where to copy object value
      * @param type_tag ASN1_Tag enum to assert type on object read
      * @param class_tag ASN1_Tag enum to assert class on object read (default: CONTEXT_SPECIFIC)
      * @return this reference  
      */
      template <typename T>
         BER_Decoder& get_next_value(T &out,
                                     ASN1_Tag type_tag,
                                     ASN1_Tag class_tag = CONTEXT_SPECIFIC)
         {
         static_assert(std::is_pod<T>::value, "Type must be POD");

         BER_Object obj = get_next_object();
         obj.assert_is_a(type_tag, class_tag);

         if (obj.length() != sizeof(T))
            throw BER_Decoding_Error(
                    "Size mismatch. Object value size is " +
                    std::to_string(obj.length()) +
                    "; Output type size is " +
                    std::to_string(sizeof(T)));

         copy_mem(reinterpret_cast<uint8_t*>(&out), obj.bits(), obj.length());

         return (*this);
         }

      /*
      * Save all the bytes remaining in the source
      */
      template<typename Alloc>
      BER_Decoder& raw_bytes(std::vector<uint8_t, Alloc>& out)
         {
         out.clear();
         uint8_t buf;
         while(m_source->read_byte(buf))
            out.push_back(buf);
         return (*this);
         }

      BER_Decoder& decode_null();

      /**
      * Decode a BER encoded BOOLEAN
      */
      BER_Decoder& decode(bool& out)
         {
         return decode(out, BOOLEAN, UNIVERSAL);
         }

      /*
      * Decode a small BER encoded INTEGER
      */
      BER_Decoder& decode(size_t& out)
         {
         return decode(out, INTEGER, UNIVERSAL);
         }

      /*
      * Decode a BER encoded INTEGER
      */
      BER_Decoder& decode(BigInt& out)
         {
         return decode(out, INTEGER, UNIVERSAL);
         }

      std::vector<uint8_t> get_next_octet_string()
         {
         std::vector<uint8_t> out_vec;
         decode(out_vec, OCTET_STRING);
         return out_vec;
         }

      /*
      * BER decode a BIT STRING or OCTET STRING
      */
      template<typename Alloc>
      BER_Decoder& decode(std::vector<uint8_t, Alloc>& out, ASN1_Tag real_type)
         {
         return decode(out, real_type, real_type, UNIVERSAL);
         }

      BER_Decoder& decode(bool& v,
                          ASN1_Tag type_tag,
                          ASN1_Tag class_tag = CONTEXT_SPECIFIC);

      BER_Decoder& decode(size_t& v,
                          ASN1_Tag type_tag,
                          ASN1_Tag class_tag = CONTEXT_SPECIFIC);

      BER_Decoder& decode(BigInt& v,
                          ASN1_Tag type_tag,
                          ASN1_Tag class_tag = CONTEXT_SPECIFIC);

      BER_Decoder& decode(std::vector<uint8_t>& v,
                          ASN1_Tag real_type,
                          ASN1_Tag type_tag,
                          ASN1_Tag class_tag = CONTEXT_SPECIFIC);

      BER_Decoder& decode(secure_vector<uint8_t>& v,
                          ASN1_Tag real_type,
                          ASN1_Tag type_tag,
                          ASN1_Tag class_tag = CONTEXT_SPECIFIC);

      BER_Decoder& decode(class ASN1_Object& obj,
                          ASN1_Tag type_tag = NO_OBJECT,
                          ASN1_Tag class_tag = NO_OBJECT);

      /**
      * Decode an integer value which is typed as an octet string
      */
      BER_Decoder& decode_octet_string_bigint(BigInt& b);

      uint64_t decode_constrained_integer(ASN1_Tag type_tag,
                                          ASN1_Tag class_tag,
                                          size_t T_bytes);

      template<typename T> BER_Decoder& decode_integer_type(T& out)
         {
         return decode_integer_type<T>(out, INTEGER, UNIVERSAL);
         }

      template<typename T>
         BER_Decoder& decode_integer_type(T& out,
                                          ASN1_Tag type_tag,
                                          ASN1_Tag class_tag = CONTEXT_SPECIFIC)
         {
         out = static_cast<T>(decode_constrained_integer(type_tag, class_tag, sizeof(out)));
         return (*this);
         }

      template<typename T>
         BER_Decoder& decode_optional(T& out,
                                      ASN1_Tag type_tag,
                                      ASN1_Tag class_tag,
                                      const T& default_value = T());

      template<typename T>
         BER_Decoder& decode_optional_implicit(
            T& out,
            ASN1_Tag type_tag,
            ASN1_Tag class_tag,
            ASN1_Tag real_type,
            ASN1_Tag real_class,
            const T& default_value = T());

      template<typename T>
         BER_Decoder& decode_list(std::vector<T>& out,
                                  ASN1_Tag type_tag = SEQUENCE,
                                  ASN1_Tag class_tag = UNIVERSAL);

      template<typename T>
         BER_Decoder& decode_and_check(const T& expected,
                                       const std::string& error_msg)
         {
         T actual;
         decode(actual);

         if(actual != expected)
            throw Decoding_Error(error_msg);

         return (*this);
         }

      /*
      * Decode an OPTIONAL string type
      */
      template<typename Alloc>
      BER_Decoder& decode_optional_string(std::vector<uint8_t, Alloc>& out,
                                          ASN1_Tag real_type,
                                          uint16_t type_no,
                                          ASN1_Tag class_tag = CONTEXT_SPECIFIC)
         {
         BER_Object obj = get_next_object();

         ASN1_Tag type_tag = static_cast<ASN1_Tag>(type_no);

         if(obj.is_a(type_tag, class_tag))
            {
            if((class_tag & CONSTRUCTED) && (class_tag & CONTEXT_SPECIFIC))
               {
               BER_Decoder(std::move(obj)).decode(out, real_type).verify_end();
               }
            else
               {
               push_back(std::move(obj));
               decode(out, real_type, type_tag, class_tag);
               }
            }
         else
            {
            out.clear();
            push_back(std::move(obj));
            }

         return (*this);
         }

   private:
      BER_Decoder(BER_Object&& obj, BER_Decoder* parent);

      BER_Decoder* m_parent = nullptr;
      BER_Object m_pushed;
      // either m_data_src.get() or an unowned pointer
      DataSource* m_source;
      mutable std::unique_ptr<DataSource> m_data_src;
   };

/*
* Decode an OPTIONAL or DEFAULT element
*/
template<typename T>
BER_Decoder& BER_Decoder::decode_optional(T& out,
                                          ASN1_Tag type_tag,
                                          ASN1_Tag class_tag,
                                          const T& default_value)
   {
   BER_Object obj = get_next_object();

   if(obj.is_a(type_tag, class_tag))
      {
      if((class_tag & CONSTRUCTED) && (class_tag & CONTEXT_SPECIFIC))
         {
         BER_Decoder(std::move(obj)).decode(out).verify_end();
         }
      else
         {
         push_back(std::move(obj));
         decode(out, type_tag, class_tag);
         }
      }
   else
      {
      out = default_value;
      push_back(std::move(obj));
      }

   return (*this);
   }

/*
* Decode an OPTIONAL or DEFAULT element
*/
template<typename T>
BER_Decoder& BER_Decoder::decode_optional_implicit(
   T& out,
   ASN1_Tag type_tag,
   ASN1_Tag class_tag,
   ASN1_Tag real_type,
   ASN1_Tag real_class,
   const T& default_value)
   {
   BER_Object obj = get_next_object();

   if(obj.is_a(type_tag, class_tag))
      {
      obj.set_tagging(real_type, real_class);
      push_back(std::move(obj));
      decode(out, real_type, real_class);
      }
   else
      {
      // Not what we wanted, push it back on the stream
      out = default_value;
      push_back(std::move(obj));
      }

   return (*this);
   }
/*
* Decode a list of homogenously typed values
*/
template<typename T>
BER_Decoder& BER_Decoder::decode_list(std::vector<T>& vec,
                                      ASN1_Tag type_tag,
                                      ASN1_Tag class_tag)
   {
   BER_Decoder list = start_cons(type_tag, class_tag);

   while(list.more_items())
      {
      T value;
      list.decode(value);
      vec.push_back(std::move(value));
      }

   list.end_cons();

   return (*this);
   }

}

namespace Botan {

/**
* Bit rotation left by a compile-time constant amount
* @param input the input word
* @return input rotated left by ROT bits
*/
template<size_t ROT, typename T>
inline T rotl(T input)
   {
   static_assert(ROT > 0 && ROT < 8*sizeof(T), "Invalid rotation constant");
   return static_cast<T>((input << ROT) | (input >> (8*sizeof(T) - ROT)));
   }

/**
* Bit rotation right by a compile-time constant amount
* @param input the input word
* @return input rotated right by ROT bits
*/
template<size_t ROT, typename T>
inline T rotr(T input)
   {
   static_assert(ROT > 0 && ROT < 8*sizeof(T), "Invalid rotation constant");
   return static_cast<T>((input >> ROT) | (input << (8*sizeof(T) - ROT)));
   }

/**
* Bit rotation left, variable rotation amount
* @param input the input word
* @param rot the number of bits to rotate, must be between 0 and sizeof(T)*8-1
* @return input rotated left by rot bits
*/
template<typename T>
inline T rotl_var(T input, size_t rot)
   {
   return rot ? static_cast<T>((input << rot) | (input >> (sizeof(T)*8 - rot))) : input;
   }

/**
* Bit rotation right, variable rotation amount
* @param input the input word
* @param rot the number of bits to rotate, must be between 0 and sizeof(T)*8-1
* @return input rotated right by rot bits
*/
template<typename T>
inline T rotr_var(T input, size_t rot)
   {
   return rot ? static_cast<T>((input >> rot) | (input << (sizeof(T)*8 - rot))) : input;
   }

#if BOTAN_USE_GCC_INLINE_ASM

#if defined(BOTAN_TARGET_ARCH_IS_X86_64) || defined(BOTAN_TARGET_ARCH_IS_X86_32)

template<>
inline uint32_t rotl_var(uint32_t input, size_t rot)
   {
   asm("roll %1,%0" : "+r" (input) : "c" (static_cast<uint8_t>(rot)));
   return input;
   }

template<>
inline uint32_t rotr_var(uint32_t input, size_t rot)
   {
   asm("rorl %1,%0" : "+r" (input) : "c" (static_cast<uint8_t>(rot)));
   return input;
   }

#endif

#endif


template<typename T>
BOTAN_DEPRECATED("Use rotl<N> or rotl_var")
inline T rotate_left(T input, size_t rot)
   {
   // rotl_var does not reduce
   return rotl_var(input, rot % (8 * sizeof(T)));
   }

template<typename T>
BOTAN_DEPRECATED("Use rotr<N> or rotr_var")
inline T rotate_right(T input, size_t rot)
   {
   // rotr_var does not reduce
   return rotr_var(input, rot % (8 * sizeof(T)));
   }

}

#if defined(BOTAN_BUILD_COMPILER_IS_MSVC)
  #include <stdlib.h>
#endif

namespace Botan {

/**
* Swap a 16 bit integer
*/
inline uint16_t reverse_bytes(uint16_t val)
   {
   return rotl<8>(val);
   }

/**
* Swap a 32 bit integer
*/
inline uint32_t reverse_bytes(uint32_t val)
   {
#if defined(BOTAN_BUILD_COMPILER_IS_GCC) || defined(BOTAN_BUILD_COMPILER_IS_CLANG)
   return __builtin_bswap32(val);

#elif defined(BOTAN_BUILD_COMPILER_IS_MSVC)
   return _byteswap_ulong(val);

#elif defined(BOTAN_USE_GCC_INLINE_ASM) && defined(BOTAN_TARGET_CPU_IS_X86_FAMILY)

   // GCC-style inline assembly for x86 or x86-64
   asm("bswapl %0" : "=r" (val) : "0" (val));
   return val;

#else

   // Generic implementation
   return (rotr<8>(val) & 0xFF00FF00) | (rotl<8>(val) & 0x00FF00FF);

#endif
   }

/**
* Swap a 64 bit integer
*/
inline uint64_t reverse_bytes(uint64_t val)
   {
#if defined(BOTAN_BUILD_COMPILER_IS_GCC) || defined(BOTAN_BUILD_COMPILER_IS_CLANG)
   return __builtin_bswap64(val);

#elif defined(BOTAN_BUILD_COMPILER_IS_MSVC)
   return _byteswap_uint64(val);

#elif defined(BOTAN_USE_GCC_INLINE_ASM) && defined(BOTAN_TARGET_ARCH_IS_X86_64)
   // GCC-style inline assembly for x86-64
   asm("bswapq %0" : "=r" (val) : "0" (val));
   return val;

#else
   /* Generic implementation. Defined in terms of 32-bit bswap so any
    * optimizations in that version can help.
    */

   uint32_t hi = static_cast<uint32_t>(val >> 32);
   uint32_t lo = static_cast<uint32_t>(val);

   hi = reverse_bytes(hi);
   lo = reverse_bytes(lo);

   return (static_cast<uint64_t>(lo) << 32) | hi;
#endif
   }

/**
* Swap 4 Ts in an array
*/
template<typename T>
inline void bswap_4(T x[4])
   {
   x[0] = reverse_bytes(x[0]);
   x[1] = reverse_bytes(x[1]);
   x[2] = reverse_bytes(x[2]);
   x[3] = reverse_bytes(x[3]);
   }

}

#if defined(BOTAN_TARGET_CPU_IS_BIG_ENDIAN)
   #define BOTAN_ENDIAN_N2L(x) reverse_bytes(x)
   #define BOTAN_ENDIAN_L2N(x) reverse_bytes(x)
   #define BOTAN_ENDIAN_N2B(x) (x)
   #define BOTAN_ENDIAN_B2N(x) (x)

#elif defined(BOTAN_TARGET_CPU_IS_LITTLE_ENDIAN)
   #define BOTAN_ENDIAN_N2L(x) (x)
   #define BOTAN_ENDIAN_L2N(x) (x)
   #define BOTAN_ENDIAN_N2B(x) reverse_bytes(x)
   #define BOTAN_ENDIAN_B2N(x) reverse_bytes(x)

#endif

namespace Botan {

/**
* Byte extraction
* @param byte_num which byte to extract, 0 == highest byte
* @param input the value to extract from
* @return byte byte_num of input
*/
template<typename T> inline uint8_t get_byte(size_t byte_num, T input)
   {
   return static_cast<uint8_t>(
      input >> (((~byte_num)&(sizeof(T)-1)) << 3)
      );
   }

/**
* Make a uint16_t from two bytes
* @param i0 the first byte
* @param i1 the second byte
* @return i0 || i1
*/
inline uint16_t make_uint16(uint8_t i0, uint8_t i1)
   {
   return static_cast<uint16_t>((static_cast<uint16_t>(i0) << 8) | i1);
   }

/**
* Make a uint32_t from four bytes
* @param i0 the first byte
* @param i1 the second byte
* @param i2 the third byte
* @param i3 the fourth byte
* @return i0 || i1 || i2 || i3
*/
inline uint32_t make_uint32(uint8_t i0, uint8_t i1, uint8_t i2, uint8_t i3)
   {
   return ((static_cast<uint32_t>(i0) << 24) |
           (static_cast<uint32_t>(i1) << 16) |
           (static_cast<uint32_t>(i2) <<  8) |
           (static_cast<uint32_t>(i3)));
   }

/**
* Make a uint32_t from eight bytes
* @param i0 the first byte
* @param i1 the second byte
* @param i2 the third byte
* @param i3 the fourth byte
* @param i4 the fifth byte
* @param i5 the sixth byte
* @param i6 the seventh byte
* @param i7 the eighth byte
* @return i0 || i1 || i2 || i3 || i4 || i5 || i6 || i7
*/
inline uint64_t make_uint64(uint8_t i0, uint8_t i1, uint8_t i2, uint8_t i3,
                          uint8_t i4, uint8_t i5, uint8_t i6, uint8_t i7)
    {
   return ((static_cast<uint64_t>(i0) << 56) |
           (static_cast<uint64_t>(i1) << 48) |
           (static_cast<uint64_t>(i2) << 40) |
           (static_cast<uint64_t>(i3) << 32) |
           (static_cast<uint64_t>(i4) << 24) |
           (static_cast<uint64_t>(i5) << 16) |
           (static_cast<uint64_t>(i6) <<  8) |
           (static_cast<uint64_t>(i7)));
    }

/**
* Load a big-endian word
* @param in a pointer to some bytes
* @param off an offset into the array
* @return off'th T of in, as a big-endian value
*/
template<typename T>
inline T load_be(const uint8_t in[], size_t off)
   {
   in += off * sizeof(T);
   T out = 0;
   for(size_t i = 0; i != sizeof(T); ++i)
      out = static_cast<T>((out << 8) | in[i]);
   return out;
   }

/**
* Load a little-endian word
* @param in a pointer to some bytes
* @param off an offset into the array
* @return off'th T of in, as a litte-endian value
*/
template<typename T>
inline T load_le(const uint8_t in[], size_t off)
   {
   in += off * sizeof(T);
   T out = 0;
   for(size_t i = 0; i != sizeof(T); ++i)
      out = (out << 8) | in[sizeof(T)-1-i];
   return out;
   }

/**
* Load a big-endian uint16_t
* @param in a pointer to some bytes
* @param off an offset into the array
* @return off'th uint16_t of in, as a big-endian value
*/
template<>
inline uint16_t load_be<uint16_t>(const uint8_t in[], size_t off)
   {
   in += off * sizeof(uint16_t);

#if defined(BOTAN_ENDIAN_N2B)
   uint16_t x;
   std::memcpy(&x, in, sizeof(x));
   return BOTAN_ENDIAN_N2B(x);
#else
   return make_uint16(in[0], in[1]);
#endif
   }

/**
* Load a little-endian uint16_t
* @param in a pointer to some bytes
* @param off an offset into the array
* @return off'th uint16_t of in, as a little-endian value
*/
template<>
inline uint16_t load_le<uint16_t>(const uint8_t in[], size_t off)
   {
   in += off * sizeof(uint16_t);

#if defined(BOTAN_ENDIAN_N2L)
   uint16_t x;
   std::memcpy(&x, in, sizeof(x));
   return BOTAN_ENDIAN_N2L(x);
#else
   return make_uint16(in[1], in[0]);
#endif
   }

/**
* Load a big-endian uint32_t
* @param in a pointer to some bytes
* @param off an offset into the array
* @return off'th uint32_t of in, as a big-endian value
*/
template<>
inline uint32_t load_be<uint32_t>(const uint8_t in[], size_t off)
   {
   in += off * sizeof(uint32_t);
#if defined(BOTAN_ENDIAN_N2B)
   uint32_t x;
   std::memcpy(&x, in, sizeof(x));
   return BOTAN_ENDIAN_N2B(x);
#else
   return make_uint32(in[0], in[1], in[2], in[3]);
#endif
   }

/**
* Load a little-endian uint32_t
* @param in a pointer to some bytes
* @param off an offset into the array
* @return off'th uint32_t of in, as a little-endian value
*/
template<>
inline uint32_t load_le<uint32_t>(const uint8_t in[], size_t off)
   {
   in += off * sizeof(uint32_t);
#if defined(BOTAN_ENDIAN_N2L)
   uint32_t x;
   std::memcpy(&x, in, sizeof(x));
   return BOTAN_ENDIAN_N2L(x);
#else
   return make_uint32(in[3], in[2], in[1], in[0]);
#endif
   }

/**
* Load a big-endian uint64_t
* @param in a pointer to some bytes
* @param off an offset into the array
* @return off'th uint64_t of in, as a big-endian value
*/
template<>
inline uint64_t load_be<uint64_t>(const uint8_t in[], size_t off)
   {
   in += off * sizeof(uint64_t);
#if defined(BOTAN_ENDIAN_N2B)
   uint64_t x;
   std::memcpy(&x, in, sizeof(x));
   return BOTAN_ENDIAN_N2B(x);
#else
   return make_uint64(in[0], in[1], in[2], in[3],
                      in[4], in[5], in[6], in[7]);
#endif
   }

/**
* Load a little-endian uint64_t
* @param in a pointer to some bytes
* @param off an offset into the array
* @return off'th uint64_t of in, as a little-endian value
*/
template<>
inline uint64_t load_le<uint64_t>(const uint8_t in[], size_t off)
   {
   in += off * sizeof(uint64_t);
#if defined(BOTAN_ENDIAN_N2L)
   uint64_t x;
   std::memcpy(&x, in, sizeof(x));
   return BOTAN_ENDIAN_N2L(x);
#else
   return make_uint64(in[7], in[6], in[5], in[4],
                      in[3], in[2], in[1], in[0]);
#endif
   }

/**
* Load two little-endian words
* @param in a pointer to some bytes
* @param x0 where the first word will be written
* @param x1 where the second word will be written
*/
template<typename T>
inline void load_le(const uint8_t in[], T& x0, T& x1)
   {
   x0 = load_le<T>(in, 0);
   x1 = load_le<T>(in, 1);
   }

/**
* Load four little-endian words
* @param in a pointer to some bytes
* @param x0 where the first word will be written
* @param x1 where the second word will be written
* @param x2 where the third word will be written
* @param x3 where the fourth word will be written
*/
template<typename T>
inline void load_le(const uint8_t in[],
                    T& x0, T& x1, T& x2, T& x3)
   {
   x0 = load_le<T>(in, 0);
   x1 = load_le<T>(in, 1);
   x2 = load_le<T>(in, 2);
   x3 = load_le<T>(in, 3);
   }

/**
* Load eight little-endian words
* @param in a pointer to some bytes
* @param x0 where the first word will be written
* @param x1 where the second word will be written
* @param x2 where the third word will be written
* @param x3 where the fourth word will be written
* @param x4 where the fifth word will be written
* @param x5 where the sixth word will be written
* @param x6 where the seventh word will be written
* @param x7 where the eighth word will be written
*/
template<typename T>
inline void load_le(const uint8_t in[],
                    T& x0, T& x1, T& x2, T& x3,
                    T& x4, T& x5, T& x6, T& x7)
   {
   x0 = load_le<T>(in, 0);
   x1 = load_le<T>(in, 1);
   x2 = load_le<T>(in, 2);
   x3 = load_le<T>(in, 3);
   x4 = load_le<T>(in, 4);
   x5 = load_le<T>(in, 5);
   x6 = load_le<T>(in, 6);
   x7 = load_le<T>(in, 7);
   }

/**
* Load a variable number of little-endian words
* @param out the output array of words
* @param in the input array of bytes
* @param count how many words are in in
*/
template<typename T>
inline void load_le(T out[],
                    const uint8_t in[],
                    size_t count)
   {
   if(count > 0)
      {
#if defined(BOTAN_TARGET_CPU_IS_LITTLE_ENDIAN)
      std::memcpy(out, in, sizeof(T)*count);
#elif defined(BOTAN_TARGET_CPU_IS_BIG_ENDIAN)
      std::memcpy(out, in, sizeof(T)*count);
      const size_t blocks = count - (count % 4);
      const size_t left = count - blocks;

      for(size_t i = 0; i != blocks; i += 4)
         bswap_4(out + i);

      for(size_t i = 0; i != left; ++i)
         out[blocks+i] = reverse_bytes(out[blocks+i]);
#else
      for(size_t i = 0; i != count; ++i)
         out[i] = load_le<T>(in, i);
#endif
      }
   }

/**
* Load two big-endian words
* @param in a pointer to some bytes
* @param x0 where the first word will be written
* @param x1 where the second word will be written
*/
template<typename T>
inline void load_be(const uint8_t in[], T& x0, T& x1)
   {
   x0 = load_be<T>(in, 0);
   x1 = load_be<T>(in, 1);
   }

/**
* Load four big-endian words
* @param in a pointer to some bytes
* @param x0 where the first word will be written
* @param x1 where the second word will be written
* @param x2 where the third word will be written
* @param x3 where the fourth word will be written
*/
template<typename T>
inline void load_be(const uint8_t in[],
                    T& x0, T& x1, T& x2, T& x3)
   {
   x0 = load_be<T>(in, 0);
   x1 = load_be<T>(in, 1);
   x2 = load_be<T>(in, 2);
   x3 = load_be<T>(in, 3);
   }

/**
* Load eight big-endian words
* @param in a pointer to some bytes
* @param x0 where the first word will be written
* @param x1 where the second word will be written
* @param x2 where the third word will be written
* @param x3 where the fourth word will be written
* @param x4 where the fifth word will be written
* @param x5 where the sixth word will be written
* @param x6 where the seventh word will be written
* @param x7 where the eighth word will be written
*/
template<typename T>
inline void load_be(const uint8_t in[],
                    T& x0, T& x1, T& x2, T& x3,
                    T& x4, T& x5, T& x6, T& x7)
   {
   x0 = load_be<T>(in, 0);
   x1 = load_be<T>(in, 1);
   x2 = load_be<T>(in, 2);
   x3 = load_be<T>(in, 3);
   x4 = load_be<T>(in, 4);
   x5 = load_be<T>(in, 5);
   x6 = load_be<T>(in, 6);
   x7 = load_be<T>(in, 7);
   }

/**
* Load a variable number of big-endian words
* @param out the output array of words
* @param in the input array of bytes
* @param count how many words are in in
*/
template<typename T>
inline void load_be(T out[],
                    const uint8_t in[],
                    size_t count)
   {
   if(count > 0)
      {
#if defined(BOTAN_TARGET_CPU_IS_BIG_ENDIAN)
      std::memcpy(out, in, sizeof(T)*count);

#elif defined(BOTAN_TARGET_CPU_IS_LITTLE_ENDIAN)
      std::memcpy(out, in, sizeof(T)*count);
      const size_t blocks = count - (count % 4);
      const size_t left = count - blocks;

      for(size_t i = 0; i != blocks; i += 4)
         bswap_4(out + i);

      for(size_t i = 0; i != left; ++i)
         out[blocks+i] = reverse_bytes(out[blocks+i]);
#else
      for(size_t i = 0; i != count; ++i)
         out[i] = load_be<T>(in, i);
#endif
      }
   }

/**
* Store a big-endian uint16_t
* @param in the input uint16_t
* @param out the byte array to write to
*/
inline void store_be(uint16_t in, uint8_t out[2])
   {
#if defined(BOTAN_ENDIAN_N2B)
   uint16_t o = BOTAN_ENDIAN_N2B(in);
   std::memcpy(out, &o, sizeof(o));
#else
   out[0] = get_byte(0, in);
   out[1] = get_byte(1, in);
#endif
   }

/**
* Store a little-endian uint16_t
* @param in the input uint16_t
* @param out the byte array to write to
*/
inline void store_le(uint16_t in, uint8_t out[2])
   {
#if defined(BOTAN_ENDIAN_N2L)
   uint16_t o = BOTAN_ENDIAN_N2L(in);
   std::memcpy(out, &o, sizeof(o));
#else
   out[0] = get_byte(1, in);
   out[1] = get_byte(0, in);
#endif
   }

/**
* Store a big-endian uint32_t
* @param in the input uint32_t
* @param out the byte array to write to
*/
inline void store_be(uint32_t in, uint8_t out[4])
   {
#if defined(BOTAN_ENDIAN_B2N)
   uint32_t o = BOTAN_ENDIAN_B2N(in);
   std::memcpy(out, &o, sizeof(o));
#else
   out[0] = get_byte(0, in);
   out[1] = get_byte(1, in);
   out[2] = get_byte(2, in);
   out[3] = get_byte(3, in);
#endif
   }

/**
* Store a little-endian uint32_t
* @param in the input uint32_t
* @param out the byte array to write to
*/
inline void store_le(uint32_t in, uint8_t out[4])
   {
#if defined(BOTAN_ENDIAN_L2N)
   uint32_t o = BOTAN_ENDIAN_L2N(in);
   std::memcpy(out, &o, sizeof(o));
#else
   out[0] = get_byte(3, in);
   out[1] = get_byte(2, in);
   out[2] = get_byte(1, in);
   out[3] = get_byte(0, in);
#endif
   }

/**
* Store a big-endian uint64_t
* @param in the input uint64_t
* @param out the byte array to write to
*/
inline void store_be(uint64_t in, uint8_t out[8])
   {
#if defined(BOTAN_ENDIAN_B2N)
   uint64_t o = BOTAN_ENDIAN_B2N(in);
   std::memcpy(out, &o, sizeof(o));
#else
   out[0] = get_byte(0, in);
   out[1] = get_byte(1, in);
   out[2] = get_byte(2, in);
   out[3] = get_byte(3, in);
   out[4] = get_byte(4, in);
   out[5] = get_byte(5, in);
   out[6] = get_byte(6, in);
   out[7] = get_byte(7, in);
#endif
   }

/**
* Store a little-endian uint64_t
* @param in the input uint64_t
* @param out the byte array to write to
*/
inline void store_le(uint64_t in, uint8_t out[8])
   {
#if defined(BOTAN_ENDIAN_L2N)
   uint64_t o = BOTAN_ENDIAN_L2N(in);
   std::memcpy(out, &o, sizeof(o));
#else
   out[0] = get_byte(7, in);
   out[1] = get_byte(6, in);
   out[2] = get_byte(5, in);
   out[3] = get_byte(4, in);
   out[4] = get_byte(3, in);
   out[5] = get_byte(2, in);
   out[6] = get_byte(1, in);
   out[7] = get_byte(0, in);
#endif
   }

/**
* Store two little-endian words
* @param out the output byte array
* @param x0 the first word
* @param x1 the second word
*/
template<typename T>
inline void store_le(uint8_t out[], T x0, T x1)
   {
   store_le(x0, out + (0 * sizeof(T)));
   store_le(x1, out + (1 * sizeof(T)));
   }

/**
* Store two big-endian words
* @param out the output byte array
* @param x0 the first word
* @param x1 the second word
*/
template<typename T>
inline void store_be(uint8_t out[], T x0, T x1)
   {
   store_be(x0, out + (0 * sizeof(T)));
   store_be(x1, out + (1 * sizeof(T)));
   }

/**
* Store four little-endian words
* @param out the output byte array
* @param x0 the first word
* @param x1 the second word
* @param x2 the third word
* @param x3 the fourth word
*/
template<typename T>
inline void store_le(uint8_t out[], T x0, T x1, T x2, T x3)
   {
   store_le(x0, out + (0 * sizeof(T)));
   store_le(x1, out + (1 * sizeof(T)));
   store_le(x2, out + (2 * sizeof(T)));
   store_le(x3, out + (3 * sizeof(T)));
   }

/**
* Store four big-endian words
* @param out the output byte array
* @param x0 the first word
* @param x1 the second word
* @param x2 the third word
* @param x3 the fourth word
*/
template<typename T>
inline void store_be(uint8_t out[], T x0, T x1, T x2, T x3)
   {
   store_be(x0, out + (0 * sizeof(T)));
   store_be(x1, out + (1 * sizeof(T)));
   store_be(x2, out + (2 * sizeof(T)));
   store_be(x3, out + (3 * sizeof(T)));
   }

/**
* Store eight little-endian words
* @param out the output byte array
* @param x0 the first word
* @param x1 the second word
* @param x2 the third word
* @param x3 the fourth word
* @param x4 the fifth word
* @param x5 the sixth word
* @param x6 the seventh word
* @param x7 the eighth word
*/
template<typename T>
inline void store_le(uint8_t out[], T x0, T x1, T x2, T x3,
                                 T x4, T x5, T x6, T x7)
   {
   store_le(x0, out + (0 * sizeof(T)));
   store_le(x1, out + (1 * sizeof(T)));
   store_le(x2, out + (2 * sizeof(T)));
   store_le(x3, out + (3 * sizeof(T)));
   store_le(x4, out + (4 * sizeof(T)));
   store_le(x5, out + (5 * sizeof(T)));
   store_le(x6, out + (6 * sizeof(T)));
   store_le(x7, out + (7 * sizeof(T)));
   }

/**
* Store eight big-endian words
* @param out the output byte array
* @param x0 the first word
* @param x1 the second word
* @param x2 the third word
* @param x3 the fourth word
* @param x4 the fifth word
* @param x5 the sixth word
* @param x6 the seventh word
* @param x7 the eighth word
*/
template<typename T>
inline void store_be(uint8_t out[], T x0, T x1, T x2, T x3,
                                 T x4, T x5, T x6, T x7)
   {
   store_be(x0, out + (0 * sizeof(T)));
   store_be(x1, out + (1 * sizeof(T)));
   store_be(x2, out + (2 * sizeof(T)));
   store_be(x3, out + (3 * sizeof(T)));
   store_be(x4, out + (4 * sizeof(T)));
   store_be(x5, out + (5 * sizeof(T)));
   store_be(x6, out + (6 * sizeof(T)));
   store_be(x7, out + (7 * sizeof(T)));
   }

template<typename T>
void copy_out_be(uint8_t out[], size_t out_bytes, const T in[])
   {
   while(out_bytes >= sizeof(T))
      {
      store_be(in[0], out);
      out += sizeof(T);
      out_bytes -= sizeof(T);
      in += 1;
   }

   for(size_t i = 0; i != out_bytes; ++i)
      out[i] = get_byte(i%8, in[0]);
   }

template<typename T, typename Alloc>
void copy_out_vec_be(uint8_t out[], size_t out_bytes, const std::vector<T, Alloc>& in)
   {
   copy_out_be(out, out_bytes, in.data());
   }

template<typename T>
void copy_out_le(uint8_t out[], size_t out_bytes, const T in[])
   {
   while(out_bytes >= sizeof(T))
      {
      store_le(in[0], out);
      out += sizeof(T);
      out_bytes -= sizeof(T);
      in += 1;
   }

   for(size_t i = 0; i != out_bytes; ++i)
      out[i] = get_byte(sizeof(T) - 1 - (i % 8), in[0]);
   }

template<typename T, typename Alloc>
void copy_out_vec_le(uint8_t out[], size_t out_bytes, const std::vector<T, Alloc>& in)
   {
   copy_out_le(out, out_bytes, in.data());
   }

}

namespace Botan {

class RandomNumberGenerator;

/**
* Arbitrary precision integer
*/
class BOTAN_PUBLIC_API(2,0) BigInt final
   {
   public:
     /**
     * Base enumerator for encoding and decoding
     */
     enum Base { Decimal = 10, Hexadecimal = 16, Binary = 256 };

     /**
     * Sign symbol definitions for positive and negative numbers
     */
     enum Sign { Negative = 0, Positive = 1 };

     /**
     * DivideByZero Exception
     */
     class BOTAN_PUBLIC_API(2,0) DivideByZero final : public Exception
        {
        public:
           DivideByZero() : Exception("BigInt divide by zero") {}
        };

     /**
     * Create empty BigInt
     */
     BigInt() = default;

     /**
     * Create BigInt from 64 bit integer
     * @param n initial value of this BigInt
     */
     BigInt(uint64_t n);

     /**
     * Copy Constructor
     * @param other the BigInt to copy
     */
     BigInt(const BigInt& other);

     /**
     * Create BigInt from a string. If the string starts with 0x the
     * rest of the string will be interpreted as hexadecimal digits.
     * Otherwise, it will be interpreted as a decimal number.
     *
     * @param str the string to parse for an integer value
     */
     explicit BigInt(const std::string& str);

     /**
     * Create a BigInt from an integer in a byte array
     * @param buf the byte array holding the value
     * @param length size of buf
     */
     BigInt(const uint8_t buf[], size_t length);

     /**
     * Create a BigInt from an integer in a byte array
     * @param vec the byte vector holding the value
     */
     template<typename Alloc>
     explicit BigInt(const std::vector<uint8_t, Alloc>& vec) : BigInt(vec.data(), vec.size()) {}

     /**
     * Create a BigInt from an integer in a byte array
     * @param buf the byte array holding the value
     * @param length size of buf
     * @param base is the number base of the integer in buf
     */
     BigInt(const uint8_t buf[], size_t length, Base base);

     /**
     * Create a BigInt from an integer in a byte array
     * @param buf the byte array holding the value
     * @param length size of buf
     * @param max_bits if the resulting integer is more than max_bits,
     *        it will be shifted so it is at most max_bits in length.
     */
     BigInt(const uint8_t buf[], size_t length, size_t max_bits);

     /**
     * Create a BigInt from an array of words
     * @param words the words
     * @param length number of words
     */
     BigInt(const word words[], size_t length);

     /**
     * \brief Create a random BigInt of the specified size
     *
     * @param rng random number generator
     * @param bits size in bits
     * @param set_high_bit if true, the highest bit is always set
     *
     * @see randomize
     */
     BigInt(RandomNumberGenerator& rng, size_t bits, bool set_high_bit = true);

     /**
     * Create BigInt of specified size, all zeros
     * @param sign the sign
     * @param n size of the internal register in words
     */
     BigInt(Sign sign, size_t n);

     /**
     * Move constructor
     */
     BigInt(BigInt&& other)
        {
        this->swap(other);
        }

     /**
     * Move assignment
     */
     BigInt& operator=(BigInt&& other)
        {
        if(this != &other)
           this->swap(other);

        return (*this);
        }

     /**
     * Copy assignment
     */
     BigInt& operator=(const BigInt&) = default;

     /**
     * Swap this value with another
     * @param other BigInt to swap values with
     */
     void swap(BigInt& other)
        {
        m_reg.swap(other.m_reg);
        std::swap(m_signedness, other.m_signedness);
        }

     void swap_reg(secure_vector<word>& reg)
        {
        m_reg.swap(reg);
        }

     /**
     * += operator
     * @param y the BigInt to add to this
     */
     BigInt& operator+=(const BigInt& y);

     /**
     * += operator
     * @param y the word to add to this
     */
     BigInt& operator+=(word y);

     /**
     * -= operator
     * @param y the BigInt to subtract from this
     */
     BigInt& operator-=(const BigInt& y);

     /**
     * -= operator
     * @param y the word to subtract from this
     */
     BigInt& operator-=(word y);

     /**
     * *= operator
     * @param y the BigInt to multiply with this
     */
     BigInt& operator*=(const BigInt& y);

     /**
     * *= operator
     * @param y the word to multiply with this
     */
     BigInt& operator*=(word y);

     /**
     * /= operator
     * @param y the BigInt to divide this by
     */
     BigInt& operator/=(const BigInt& y);

     /**
     * Modulo operator
     * @param y the modulus to reduce this by
     */
     BigInt& operator%=(const BigInt& y);

     /**
     * Modulo operator
     * @param y the modulus (word) to reduce this by
     */
     word    operator%=(word y);

     /**
     * Left shift operator
     * @param shift the number of bits to shift this left by
     */
     BigInt& operator<<=(size_t shift);

     /**
     * Right shift operator
     * @param shift the number of bits to shift this right by
     */
     BigInt& operator>>=(size_t shift);

     /**
     * Increment operator
     */
     BigInt& operator++() { return (*this += 1); }

     /**
     * Decrement operator
     */
     BigInt& operator--() { return (*this -= 1); }

     /**
     * Postfix increment operator
     */
     BigInt  operator++(int) { BigInt x = (*this); ++(*this); return x; }

     /**
     * Postfix decrement operator
     */
     BigInt  operator--(int) { BigInt x = (*this); --(*this); return x; }

     /**
     * Unary negation operator
     * @return negative this
     */
     BigInt operator-() const;

     /**
     * ! operator
     * @return true iff this is zero, otherwise false
     */
     bool operator !() const { return (!is_nonzero()); }

     BigInt& add(const word y[], size_t y_words, Sign sign);
     BigInt& sub(const word y[], size_t y_words, Sign sign);

     /**
     * Multiply this with y
     * @param y the BigInt to multiply with this
     * @param ws a temp workspace
     */
     BigInt& mul(const BigInt& y, secure_vector<word>& ws);

     /**
     * Square value of *this
     * @param ws a temp workspace
     */
     BigInt& square(secure_vector<word>& ws);

     /**
     * Set *this to y - *this
     * @param y the BigInt to subtract from as a sequence of words
     * @param y_size length of y in words
     * @param ws a temp workspace
     */
     BigInt& rev_sub(const word y[], size_t y_size, secure_vector<word>& ws);

     /**
     * Set *this to (*this + y) % mod
     * This function assumes *this is >= 0 && < mod
     * @param y the BigInt to add - assumed y >= 0 and y < mod
     * @param mod the positive modulus
     * @param ws a temp workspace
     */
     BigInt& mod_add(const BigInt& y, const BigInt& mod, secure_vector<word>& ws);

     /**
     * Set *this to (*this - y) % mod
     * This function assumes *this is >= 0 && < mod
     * @param y the BigInt to subtract - assumed y >= 0 and y < mod
     * @param mod the positive modulus
     * @param ws a temp workspace
     */
     BigInt& mod_sub(const BigInt& y, const BigInt& mod, secure_vector<word>& ws);

     /**
     * Return *this below mod
     *
     * Assumes that *this is (if anything) only slightly larger than
     * mod and performs repeated subtractions. It should not be used if
     * *this is much larger than mod, instead of modulo operator.
     */
     void reduce_below(const BigInt& mod, secure_vector<word> &ws);

     /**
     * Zeroize the BigInt. The size of the underlying register is not
     * modified.
     */
     void clear() { zeroise(m_reg); }

     /**
     * Compare this to another BigInt
     * @param n the BigInt value to compare with
     * @param check_signs include sign in comparison?
     * @result if (this<n) return -1, if (this>n) return 1, if both
     * values are identical return 0 [like Perl's <=> operator]
     */
     int32_t cmp(const BigInt& n, bool check_signs = true) const;

     /**
     * Compare this to an integer
     * @param n the value to compare with
     * @result if (this<n) return -1, if (this>n) return 1, if both
     * values are identical return 0 [like Perl's <=> operator]
     */
     int32_t cmp_word(word n) const;

     /**
     * Test if the integer has an even value
     * @result true if the integer is even, false otherwise
     */
     bool is_even() const { return (get_bit(0) == 0); }

     /**
     * Test if the integer has an odd value
     * @result true if the integer is odd, false otherwise
     */
     bool is_odd()  const { return (get_bit(0) == 1); }

     /**
     * Test if the integer is not zero
     * @result true if the integer is non-zero, false otherwise
     */
     bool is_nonzero() const { return (!is_zero()); }

     /**
     * Test if the integer is zero
     * @result true if the integer is zero, false otherwise
     */
     bool is_zero() const
        {
        const size_t sw = sig_words();

        for(size_t i = 0; i != sw; ++i)
           if(m_reg[i])
              return false;
        return true;
        }

     /**
     * Set bit at specified position
     * @param n bit position to set
     */
     void set_bit(size_t n);

     /**
     * Clear bit at specified position
     * @param n bit position to clear
     */
     void clear_bit(size_t n);

     /**
     * Clear all but the lowest n bits
     * @param n amount of bits to keep
     */
     void mask_bits(size_t n)
        {
        if(n == 0) { clear(); return; }

        const size_t top_word = n / BOTAN_MP_WORD_BITS;
        const word mask = (static_cast<word>(1) << (n % BOTAN_MP_WORD_BITS)) - 1;

        if(top_word < size())
           {
           const size_t len = size() - (top_word + 1);
           if (len > 0)
              {
              clear_mem(&m_reg[top_word+1], len);
              }
           m_reg[top_word] &= mask;
           }
        }

     /**
     * Return bit value at specified position
     * @param n the bit offset to test
     * @result true, if the bit at position n is set, false otherwise
     */
     bool get_bit(size_t n) const
        {
        return ((word_at(n / BOTAN_MP_WORD_BITS) >> (n % BOTAN_MP_WORD_BITS)) & 1);
        }

     /**
     * Return (a maximum of) 32 bits of the complete value
     * @param offset the offset to start extracting
     * @param length amount of bits to extract (starting at offset)
     * @result the integer extracted from the register starting at
     * offset with specified length
     */
     uint32_t get_substring(size_t offset, size_t length) const;

     /**
     * Convert this value into a uint32_t, if it is in the range
     * [0 ... 2**32-1], or otherwise throw an exception.
     * @result the value as a uint32_t if conversion is possible
     */
     uint32_t to_u32bit() const;

     /**
     * Convert this value to a decimal string.
     * Warning: decimal conversions are relatively slow
     */
     std::string to_dec_string() const;

     /**
     * Convert this value to a hexadecimal string.
     */
     std::string to_hex_string() const;

     /**
     * @param n the offset to get a byte from
     * @result byte at offset n
     */
     uint8_t byte_at(size_t n) const
        {
        return get_byte(sizeof(word) - (n % sizeof(word)) - 1,
                        word_at(n / sizeof(word)));
        }

     /**
     * Return the word at a specified position of the internal register
     * @param n position in the register
     * @return value at position n
     */
     word word_at(size_t n) const
        { return ((n < size()) ? m_reg[n] : 0); }

     void set_word_at(size_t i, word w)
        {
        if(i >= m_reg.size())
           grow_to(i + 1);
        m_reg[i] = w;
        }

     void set_words(const word w[], size_t len)
        {
        m_reg.resize(len);
        copy_mem(mutable_data(), w, len);
        }

     /**
     * Tests if the sign of the integer is negative
     * @result true, iff the integer has a negative sign
     */
     bool is_negative() const { return (sign() == Negative); }

     /**
     * Tests if the sign of the integer is positive
     * @result true, iff the integer has a positive sign
     */
     bool is_positive() const { return (sign() == Positive); }

     /**
     * Return the sign of the integer
     * @result the sign of the integer
     */
     Sign sign() const { return (m_signedness); }

     /**
     * @result the opposite sign of the represented integer value
     */
     Sign reverse_sign() const
        {
        if(sign() == Positive)
           return Negative;
        return Positive;
        }

     /**
     * Flip the sign of this BigInt
     */
     void flip_sign()
        {
        set_sign(reverse_sign());
        }

     /**
     * Set sign of the integer
     * @param sign new Sign to set
     */
     void set_sign(Sign sign)
        {
        if(is_zero())
           m_signedness = Positive;
        else
           m_signedness = sign;
        }

     /**
     * @result absolute (positive) value of this
     */
     BigInt abs() const;

     /**
     * Give size of internal register
     * @result size of internal register in words
     */
     size_t size() const { return m_reg.size(); }

     /**
     * Return how many words we need to hold this value
     * @result significant words of the represented integer value
     */
     size_t sig_words() const
        {
        const word* x = m_reg.data();
        size_t sig = m_reg.size();

        while(sig && (x[sig-1] == 0))
           sig--;
        return sig;
        }

     /**
     * Give byte length of the integer
     * @result byte length of the represented integer value
     */
     size_t bytes() const;

     /**
     * Get the bit length of the integer
     * @result bit length of the represented integer value
     */
     size_t bits() const;

     /**
     * Return a mutable pointer to the register
     * @result a pointer to the start of the internal register
     */
     word* mutable_data() { return m_reg.data(); }

     /**
     * Return a const pointer to the register
     * @result a pointer to the start of the internal register
     */
     const word* data() const { return m_reg.data(); }

     secure_vector<word>& get_word_vector() { return m_reg; }
     const secure_vector<word>& get_word_vector() const { return m_reg; }

     /**
     * Increase internal register buffer to at least n words
     * @param n new size of register
     */
     void grow_to(size_t n);

     /**
     * Resize the vector to the minimum word size to hold the integer, or
     * min_size words, whichever is larger
     */
     void shrink_to_fit(size_t min_size = 0)
        {
        const size_t words = std::max(min_size, sig_words());
        m_reg.resize(words);
        }

     /**
     * Fill BigInt with a random number with size of bitsize
     *
     * If \p set_high_bit is true, the highest bit will be set, which causes
     * the entropy to be \a bits-1. Otherwise the highest bit is randomly chosen
     * by the rng, causing the entropy to be \a bits.
     *
     * @param rng the random number generator to use
     * @param bitsize number of bits the created random value should have
     * @param set_high_bit if true, the highest bit is always set
     */
     void randomize(RandomNumberGenerator& rng, size_t bitsize, bool set_high_bit = true);

     /**
     * Store BigInt-value in a given byte array
     * @param buf destination byte array for the integer value
     */
     void binary_encode(uint8_t buf[]) const;

     /**
     * Read integer value from a byte array with given size
     * @param buf byte array buffer containing the integer
     * @param length size of buf
     */
     void binary_decode(const uint8_t buf[], size_t length);

     /**
     * Read integer value from a byte array (secure_vector<uint8_t>)
     * @param buf the array to load from
     */
     void binary_decode(const secure_vector<uint8_t>& buf)
        {
        binary_decode(buf.data(), buf.size());
        }

     /**
     * @param base the base to measure the size for
     * @return size of this integer in base base
     */
     size_t encoded_size(Base base = Binary) const;

     /**
     * Place the value into out, zero-padding up to size words
     * Throw if *this cannot be represented in size words
     */
     void encode_words(word out[], size_t size) const;

     /**
     * If predicate is true assign other to *this
     * Uses a masked operation to avoid side channels
     */
     void ct_cond_assign(bool predicate, BigInt& other);

#if defined(BOTAN_HAS_VALGRIND)
     void const_time_poison() const;
     void const_time_unpoison() const;
#else
     void const_time_poison() const {}
     void const_time_unpoison() const {}
#endif

     /**
     * @param rng a random number generator
     * @param min the minimum value (must be non-negative)
     * @param max the maximum value (must be non-negative and > min)
     * @return random integer in [min,max)
     */
     static BigInt random_integer(RandomNumberGenerator& rng,
                                  const BigInt& min,
                                  const BigInt& max);

     /**
     * Create a power of two
     * @param n the power of two to create
     * @return bigint representing 2^n
     */
     static BigInt power_of_2(size_t n)
        {
        BigInt b;
        b.set_bit(n);
        return b;
        }

     /**
     * Encode the integer value from a BigInt to a std::vector of bytes
     * @param n the BigInt to use as integer source
     * @result secure_vector of bytes containing the bytes of the integer
     */
     static std::vector<uint8_t> encode(const BigInt& n)
        {
        std::vector<uint8_t> output(n.bytes());
        n.binary_encode(output.data());
        return output;
        }

     /**
     * Encode the integer value from a BigInt to a secure_vector of bytes
     * @param n the BigInt to use as integer source
     * @result secure_vector of bytes containing the bytes of the integer
     */
     static secure_vector<uint8_t> encode_locked(const BigInt& n)
        {
        secure_vector<uint8_t> output(n.bytes());
        n.binary_encode(output.data());
        return output;
        }

     /**
     * Encode the integer value from a BigInt to a byte array
     * @param buf destination byte array for the encoded integer
     * @param n the BigInt to use as integer source
     */
     static void encode(uint8_t buf[], const BigInt& n)
        {
        n.binary_encode(buf);
        }

     /**
     * Create a BigInt from an integer in a byte array
     * @param buf the binary value to load
     * @param length size of buf
     * @result BigInt representing the integer in the byte array
     */
     static BigInt decode(const uint8_t buf[], size_t length)
        {
        return BigInt(buf, length);
        }

     /**
     * Create a BigInt from an integer in a byte array
     * @param buf the binary value to load
     * @result BigInt representing the integer in the byte array
     */
     static BigInt decode(const secure_vector<uint8_t>& buf)
        {
        return BigInt(buf);
        }

     /**
     * Create a BigInt from an integer in a byte array
     * @param buf the binary value to load
     * @result BigInt representing the integer in the byte array
     */
     static BigInt decode(const std::vector<uint8_t>& buf)
        {
        return BigInt(buf);
        }

     /**
     * Encode the integer value from a BigInt to a std::vector of bytes
     * @param n the BigInt to use as integer source
     * @param base number-base of resulting byte array representation
     * @result secure_vector of bytes containing the integer with given base
     */
     static std::vector<uint8_t> encode(const BigInt& n, Base base);

     /**
     * Encode the integer value from a BigInt to a secure_vector of bytes
     * @param n the BigInt to use as integer source
     * @param base number-base of resulting byte array representation
     * @result secure_vector of bytes containing the integer with given base
     */
     static secure_vector<uint8_t> encode_locked(const BigInt& n,
                                                 Base base);

     /**
     * Encode the integer value from a BigInt to a byte array
     * @param buf destination byte array for the encoded integer
     * value with given base
     * @param n the BigInt to use as integer source
     * @param base number-base of resulting byte array representation
     */
     static void encode(uint8_t buf[], const BigInt& n, Base base);

     /**
     * Create a BigInt from an integer in a byte array
     * @param buf the binary value to load
     * @param length size of buf
     * @param base number-base of the integer in buf
     * @result BigInt representing the integer in the byte array
     */
     static BigInt decode(const uint8_t buf[], size_t length,
                          Base base);

     /**
     * Create a BigInt from an integer in a byte array
     * @param buf the binary value to load
     * @param base number-base of the integer in buf
     * @result BigInt representing the integer in the byte array
     */
     static BigInt decode(const secure_vector<uint8_t>& buf,
                          Base base)
        {
        if(base == Binary)
           return BigInt(buf);
        return BigInt::decode(buf.data(), buf.size(), base);
        }

     /**
     * Create a BigInt from an integer in a byte array
     * @param buf the binary value to load
     * @param base number-base of the integer in buf
     * @result BigInt representing the integer in the byte array
     */
     static BigInt decode(const std::vector<uint8_t>& buf, Base base)
        {
        if(base == Binary)
           return BigInt(buf);
        return BigInt::decode(buf.data(), buf.size(), base);
        }

     /**
     * Encode a BigInt to a byte array according to IEEE 1363
     * @param n the BigInt to encode
     * @param bytes the length of the resulting secure_vector<uint8_t>
     * @result a secure_vector<uint8_t> containing the encoded BigInt
     */
     static secure_vector<uint8_t> encode_1363(const BigInt& n, size_t bytes);

     static void encode_1363(uint8_t out[], size_t bytes, const BigInt& n);

     /**
     * Encode two BigInt to a byte array according to IEEE 1363
     * @param n1 the first BigInt to encode
     * @param n2 the second BigInt to encode
     * @param bytes the length of the encoding of each single BigInt
     * @result a secure_vector<uint8_t> containing the concatenation of the two encoded BigInt
     */
     static secure_vector<uint8_t> encode_fixed_length_int_pair(const BigInt& n1, const BigInt& n2, size_t bytes);

     /**
     * Set output = vec[idx].m_reg in constant time
     * All words of vec must have the same size
     */
     static void const_time_lookup(
        secure_vector<word>& output,
        const std::vector<BigInt>& vec,
        size_t idx);

   private:
      secure_vector<word> m_reg;
      Sign m_signedness = Positive;
   };

/*
* Arithmetic Operators
*/
BigInt BOTAN_PUBLIC_API(2,0) operator+(const BigInt& x, const BigInt& y);
BigInt BOTAN_PUBLIC_API(2,7) operator+(const BigInt& x, word y);
inline BigInt operator+(word x, const BigInt& y) { return y + x; }

BigInt BOTAN_PUBLIC_API(2,0) operator-(const BigInt& x, const BigInt& y);
BigInt BOTAN_PUBLIC_API(2,7) operator-(const BigInt& x, word y);

BigInt BOTAN_PUBLIC_API(2,0) operator*(const BigInt& x, const BigInt& y);
BigInt BOTAN_PUBLIC_API(2,8) operator*(const BigInt& x, word y);
inline BigInt operator*(word x, const BigInt& y) { return y*x; }

BigInt BOTAN_PUBLIC_API(2,0) operator/(const BigInt& x, const BigInt& d);
BigInt BOTAN_PUBLIC_API(2,0) operator%(const BigInt& x, const BigInt& m);
word   BOTAN_PUBLIC_API(2,0) operator%(const BigInt& x, word m);
BigInt BOTAN_PUBLIC_API(2,0) operator<<(const BigInt& x, size_t n);
BigInt BOTAN_PUBLIC_API(2,0) operator>>(const BigInt& x, size_t n);

/*
* Comparison Operators
*/
inline bool operator==(const BigInt& a, const BigInt& b)
   { return (a.cmp(b) == 0); }
inline bool operator!=(const BigInt& a, const BigInt& b)
   { return (a.cmp(b) != 0); }
inline bool operator<=(const BigInt& a, const BigInt& b)
   { return (a.cmp(b) <= 0); }
inline bool operator>=(const BigInt& a, const BigInt& b)
   { return (a.cmp(b) >= 0); }
inline bool operator<(const BigInt& a, const BigInt& b)
   { return (a.cmp(b) < 0); }
inline bool operator>(const BigInt& a, const BigInt& b)
   { return (a.cmp(b) > 0); }

inline bool operator==(const BigInt& a, word b)
   { return (a.cmp_word(b) == 0); }
inline bool operator!=(const BigInt& a, word b)
   { return (a.cmp_word(b) != 0); }
inline bool operator<=(const BigInt& a, word b)
   { return (a.cmp_word(b) <= 0); }
inline bool operator>=(const BigInt& a, word b)
   { return (a.cmp_word(b) >= 0); }
inline bool operator<(const BigInt& a, word b)
   { return (a.cmp_word(b) < 0); }
inline bool operator>(const BigInt& a, word b)
   { return (a.cmp_word(b) > 0); }

/*
* I/O Operators
*/
BOTAN_PUBLIC_API(2,0) std::ostream& operator<<(std::ostream&, const BigInt&);
BOTAN_PUBLIC_API(2,0) std::istream& operator>>(std::istream&, BigInt&);

}

namespace std {

template<>
inline void swap<Botan::BigInt>(Botan::BigInt& x, Botan::BigInt& y)
   {
   x.swap(y);
   }

}

namespace Botan {

class RandomNumberGenerator;

/**
* Fused multiply-add
* @param a an integer
* @param b an integer
* @param c an integer
* @return (a*b)+c
*/
BigInt BOTAN_PUBLIC_API(2,0) mul_add(const BigInt& a,
                                     const BigInt& b,
                                     const BigInt& c);

/**
* Fused subtract-multiply
* @param a an integer
* @param b an integer
* @param c an integer
* @return (a-b)*c
*/
BigInt BOTAN_PUBLIC_API(2,0) sub_mul(const BigInt& a,
                                     const BigInt& b,
                                     const BigInt& c);

/**
* Fused multiply-subtract
* @param a an integer
* @param b an integer
* @param c an integer
* @return (a*b)-c
*/
BigInt BOTAN_PUBLIC_API(2,0) mul_sub(const BigInt& a,
                                     const BigInt& b,
                                     const BigInt& c);

/**
* Return the absolute value
* @param n an integer
* @return absolute value of n
*/
inline BigInt abs(const BigInt& n) { return n.abs(); }

/**
* Compute the greatest common divisor
* @param x a positive integer
* @param y a positive integer
* @return gcd(x,y)
*/
BigInt BOTAN_PUBLIC_API(2,0) gcd(const BigInt& x, const BigInt& y);

/**
* Least common multiple
* @param x a positive integer
* @param y a positive integer
* @return z, smallest integer such that z % x == 0 and z % y == 0
*/
BigInt BOTAN_PUBLIC_API(2,0) lcm(const BigInt& x, const BigInt& y);

/**
* @param x an integer
* @return (x*x)
*/
BigInt BOTAN_PUBLIC_API(2,0) square(const BigInt& x);

/**
* Modular inversion
* @param x a positive integer
* @param modulus a positive integer
* @return y st (x*y) % modulus == 1 or 0 if no such value
* Not const time
*/
BigInt BOTAN_PUBLIC_API(2,0) inverse_mod(const BigInt& x,
                                         const BigInt& modulus);

/**
* Modular inversion using extended binary Euclidian algorithm
* @param x a positive integer
* @param modulus a positive integer
* @return y st (x*y) % modulus == 1 or 0 if no such value
* Not const time
*/
BigInt BOTAN_PUBLIC_API(2,5) inverse_euclid(const BigInt& x,
                                            const BigInt& modulus);

/**
* Const time modular inversion
* Requires the modulus be odd
*/
BigInt BOTAN_PUBLIC_API(2,0) ct_inverse_mod_odd_modulus(const BigInt& n, const BigInt& mod);

/**
* Return a^-1 * 2^k mod b
* Returns k, between n and 2n
* Not const time
*/
size_t BOTAN_PUBLIC_API(2,0) almost_montgomery_inverse(BigInt& result,
                                                       const BigInt& a,
                                                       const BigInt& b);

/**
* Call almost_montgomery_inverse and correct the result to a^-1 mod b
*/
BigInt BOTAN_PUBLIC_API(2,0) normalized_montgomery_inverse(const BigInt& a, const BigInt& b);


/**
* Compute the Jacobi symbol. If n is prime, this is equivalent
* to the Legendre symbol.
* @see http://mathworld.wolfram.com/JacobiSymbol.html
*
* @param a is a non-negative integer
* @param n is an odd integer > 1
* @return (n / m)
*/
int32_t BOTAN_PUBLIC_API(2,0) jacobi(const BigInt& a, const BigInt& n);

/**
* Modular exponentation
* @param b an integer base
* @param x a positive exponent
* @param m a positive modulus
* @return (b^x) % m
*/
BigInt BOTAN_PUBLIC_API(2,0) power_mod(const BigInt& b,
                                       const BigInt& x,
                                       const BigInt& m);

/**
* Compute the square root of x modulo a prime using the
* Shanks-Tonnelli algorithm
*
* @param x the input
* @param p the prime
* @return y such that (y*y)%p == x, or -1 if no such integer
*/
BigInt BOTAN_PUBLIC_API(2,0) ressol(const BigInt& x, const BigInt& p);

/*
* Compute -input^-1 mod 2^MP_WORD_BITS. Returns zero if input
* is even. If input is odd, input and 2^n are relatively prime
* and an inverse exists.
*/
word BOTAN_PUBLIC_API(2,0) monty_inverse(word input);

/**
* @param x a positive integer
* @return count of the zero bits in x, or, equivalently, the largest
*         value of n such that 2^n divides x evenly. Returns zero if
*         n is less than or equal to zero.
*/
size_t BOTAN_PUBLIC_API(2,0) low_zero_bits(const BigInt& x);

/**
* Check for primality
* @param n a positive integer to test for primality
* @param rng a random number generator
* @param prob chance of false positive is bounded by 1/2**prob
* @param is_random true if n was randomly chosen by us
* @return true if all primality tests passed, otherwise false
*/
bool BOTAN_PUBLIC_API(2,0) is_prime(const BigInt& n,
                                    RandomNumberGenerator& rng,
                                    size_t prob = 64,
                                    bool is_random = false);

/**
* Test if the positive integer x is a perfect square ie if there
* exists some positive integer y st y*y == x
* See FIPS 186-4 sec C.4
* @return 0 if the integer is not a perfect square, otherwise
*         returns the positive y st y*y == x
*/
BigInt BOTAN_PUBLIC_API(2,8) is_perfect_square(const BigInt& x);

inline bool quick_check_prime(const BigInt& n, RandomNumberGenerator& rng)
   { return is_prime(n, rng, 32); }

inline bool check_prime(const BigInt& n, RandomNumberGenerator& rng)
   { return is_prime(n, rng, 56); }

inline bool verify_prime(const BigInt& n, RandomNumberGenerator& rng)
   { return is_prime(n, rng, 80); }

/**
* Randomly generate a prime suitable for discrete logarithm parameters
* @param rng a random number generator
* @param bits how large the resulting prime should be in bits
* @param coprime a positive integer that (prime - 1) should be coprime to
* @param equiv a non-negative number that the result should be
               equivalent to modulo equiv_mod
* @param equiv_mod the modulus equiv should be checked against
* @param prob use test so false positive is bounded by 1/2**prob
* @return random prime with the specified criteria
*/
BigInt BOTAN_PUBLIC_API(2,0) random_prime(RandomNumberGenerator& rng,
                                          size_t bits,
                                          const BigInt& coprime = 0,
                                          size_t equiv = 1,
                                          size_t equiv_mod = 2,
                                          size_t prob = 128);

/**
* Generate a prime suitable for RSA p/q
* @param keygen_rng a random number generator
* @param prime_test_rng a random number generator
* @param bits how large the resulting prime should be in bits (must be >= 512)
* @param coprime a positive integer that (prime - 1) should be coprime to
* @param prob use test so false positive is bounded by 1/2**prob
* @return random prime with the specified criteria
*/
BigInt BOTAN_PUBLIC_API(2,7) generate_rsa_prime(RandomNumberGenerator& keygen_rng,
                                                RandomNumberGenerator& prime_test_rng,
                                                size_t bits,
                                                const BigInt& coprime,
                                                size_t prob = 128);

/**
* Return a 'safe' prime, of the form p=2*q+1 with q prime
* @param rng a random number generator
* @param bits is how long the resulting prime should be
* @return prime randomly chosen from safe primes of length bits
*/
BigInt BOTAN_PUBLIC_API(2,0) random_safe_prime(RandomNumberGenerator& rng,
                                               size_t bits);

/**
* Generate DSA parameters using the FIPS 186 kosherizer
* @param rng a random number generator
* @param p_out where the prime p will be stored
* @param q_out where the prime q will be stored
* @param pbits how long p will be in bits
* @param qbits how long q will be in bits
* @return random seed used to generate this parameter set
*/
std::vector<uint8_t> BOTAN_PUBLIC_API(2,0)
generate_dsa_primes(RandomNumberGenerator& rng,
                    BigInt& p_out, BigInt& q_out,
                    size_t pbits, size_t qbits);

/**
* Generate DSA parameters using the FIPS 186 kosherizer
* @param rng a random number generator
* @param p_out where the prime p will be stored
* @param q_out where the prime q will be stored
* @param pbits how long p will be in bits
* @param qbits how long q will be in bits
* @param seed the seed used to generate the parameters
* @param offset optional offset from seed to start searching at
* @return true if seed generated a valid DSA parameter set, otherwise
          false. p_out and q_out are only valid if true was returned.
*/
bool BOTAN_PUBLIC_API(2,0)
generate_dsa_primes(RandomNumberGenerator& rng,
                    BigInt& p_out, BigInt& q_out,
                    size_t pbits, size_t qbits,
                    const std::vector<uint8_t>& seed,
                    size_t offset = 0);

/**
* The size of the PRIMES[] array
*/
const size_t PRIME_TABLE_SIZE = 6541;

/**
* A const array of all primes less than 65535
*/
extern const uint16_t BOTAN_PUBLIC_API(2,0) PRIMES[];

}

namespace Botan {

/**
* Modular Reducer (using Barrett's technique)
*/
class BOTAN_PUBLIC_API(2,0) Modular_Reducer
   {
   public:
      const BigInt& get_modulus() const { return m_modulus; }

      BigInt reduce(const BigInt& x) const;

      /**
      * Multiply mod p
      * @param x the first operand
      * @param y the second operand
      * @return (x * y) % p
      */
      BigInt multiply(const BigInt& x, const BigInt& y) const
         { return reduce(x * y); }

      /**
      * Square mod p
      * @param x the value to square
      * @return (x * x) % p
      */
      BigInt square(const BigInt& x) const
         { return reduce(Botan::square(x)); }

      /**
      * Cube mod p
      * @param x the value to cube
      * @return (x * x * x) % p
      */
      BigInt cube(const BigInt& x) const
         { return multiply(x, this->square(x)); }

      void reduce(BigInt& out, const BigInt& x, secure_vector<word>& ws) const;

      bool initialized() const { return (m_mod_words != 0); }

      Modular_Reducer() { m_mod_words = 0; }
      explicit Modular_Reducer(const BigInt& mod);
   private:
      BigInt m_modulus, m_modulus_2, m_mu;
      size_t m_mod_words;
   };

}

namespace Botan {

class RandomNumberGenerator;

/**
* Blinding Function Object.
*/
class BOTAN_PUBLIC_API(2,0) Blinder final
   {
   public:
      /**
      * Blind a value.
      * The blinding nonce k is freshly generated after
      * BOTAN_BLINDING_REINIT_INTERVAL calls to blind().
      * BOTAN_BLINDING_REINIT_INTERVAL = 0 means a fresh
      * nonce is only generated once. On every other call,
      * an updated nonce is used for blinding: k' = k*k mod n.
      * @param x value to blind
      * @return blinded value
      */
      BigInt blind(const BigInt& x) const;

      /**
      * Unblind a value.
      * @param x value to unblind
      * @return unblinded value
      */
      BigInt unblind(const BigInt& x) const;

      /**
      * @param modulus the modulus
      * @param rng the RNG to use for generating the nonce
      * @param fwd_func a function that calculates the modular
      * exponentiation of the public exponent and the given value (the nonce)
      * @param inv_func a function that calculates the modular inverse
      * of the given value (the nonce)
      */
      Blinder(const BigInt& modulus,
              RandomNumberGenerator& rng,
              std::function<BigInt (const BigInt&)> fwd_func,
              std::function<BigInt (const BigInt&)> inv_func);

      Blinder(const Blinder&) = delete;

      Blinder& operator=(const Blinder&) = delete;

      RandomNumberGenerator& rng() const { return m_rng; }

   private:
      BigInt blinding_nonce() const;

      Modular_Reducer m_reducer;
      RandomNumberGenerator& m_rng;
      std::function<BigInt (const BigInt&)> m_fwd_fn;
      std::function<BigInt (const BigInt&)> m_inv_fn;
      size_t m_modulus_bits = 0;

      mutable BigInt m_e, m_d;
      mutable size_t m_counter = 0;
   };

}

namespace Botan {

/**
* This class represents any kind of computation which uses an internal
* state, such as hash functions or MACs
*/
class BOTAN_PUBLIC_API(2,0) Buffered_Computation
   {
   public:
      /**
      * @return length of the output of this function in bytes
      */
      virtual size_t output_length() const = 0;

      /**
      * Add new input to process.
      * @param in the input to process as a byte array
      * @param length of param in in bytes
      */
      void update(const uint8_t in[], size_t length) { add_data(in, length); }

      /**
      * Add new input to process.
      * @param in the input to process as a secure_vector
      */
      void update(const secure_vector<uint8_t>& in)
         {
         add_data(in.data(), in.size());
         }

      /**
      * Add new input to process.
      * @param in the input to process as a std::vector
      */
      void update(const std::vector<uint8_t>& in)
         {
         add_data(in.data(), in.size());
         }

      /**
      * Add an integer in big-endian order
      * @param in the value
      */
      template<typename T> void update_be(const T in)
         {
         for(size_t i = 0; i != sizeof(T); ++i)
            {
            uint8_t b = get_byte(i, in);
            add_data(&b, 1);
            }
         }

      /**
      * Add new input to process.
      * @param str the input to process as a std::string. Will be interpreted
      * as a byte array based on the strings encoding.
      */
      void update(const std::string& str)
         {
         add_data(cast_char_ptr_to_uint8(str.data()), str.size());
         }

      /**
      * Process a single byte.
      * @param in the byte to process
      */
      void update(uint8_t in) { add_data(&in, 1); }

      /**
      * Complete the computation and retrieve the
      * final result.
      * @param out The byte array to be filled with the result.
      * Must be of length output_length()
      */
      void final(uint8_t out[]) { final_result(out); }

      /**
      * Complete the computation and retrieve the
      * final result.
      * @return secure_vector holding the result
      */
      secure_vector<uint8_t> final()
         {
         secure_vector<uint8_t> output(output_length());
         final_result(output.data());
         return output;
         }

      std::vector<uint8_t> final_stdvec()
         {
         std::vector<uint8_t> output(output_length());
         final_result(output.data());
         return output;
         }

      template<typename Alloc>
         void final(std::vector<uint8_t, Alloc>& out)
         {
         out.resize(output_length());
         final_result(out.data());
         }

      /**
      * Update and finalize computation. Does the same as calling update()
      * and final() consecutively.
      * @param in the input to process as a byte array
      * @param length the length of the byte array
      * @result the result of the call to final()
      */
      secure_vector<uint8_t> process(const uint8_t in[], size_t length)
         {
         add_data(in, length);
         return final();
         }

      /**
      * Update and finalize computation. Does the same as calling update()
      * and final() consecutively.
      * @param in the input to process
      * @result the result of the call to final()
      */
      secure_vector<uint8_t> process(const secure_vector<uint8_t>& in)
         {
         add_data(in.data(), in.size());
         return final();
         }

      /**
      * Update and finalize computation. Does the same as calling update()
      * and final() consecutively.
      * @param in the input to process
      * @result the result of the call to final()
      */
      secure_vector<uint8_t> process(const std::vector<uint8_t>& in)
         {
         add_data(in.data(), in.size());
         return final();
         }

      /**
      * Update and finalize computation. Does the same as calling update()
      * and final() consecutively.
      * @param in the input to process as a string
      * @result the result of the call to final()
      */
      secure_vector<uint8_t> process(const std::string& in)
         {
         update(in);
         return final();
         }

      virtual ~Buffered_Computation() = default;
   private:
      /**
      * Add more data to the computation
      * @param input is an input buffer
      * @param length is the length of input in bytes
      */
      virtual void add_data(const uint8_t input[], size_t length) = 0;

      /**
      * Write the final output to out
      * @param out is an output buffer of output_length()
      */
      virtual void final_result(uint8_t out[]) = 0;
   };

}

namespace Botan {

/**
* Struct representing a particular date and time
*/
class BOTAN_PUBLIC_API(2,0) calendar_point
   {
   public:

      /** The year */
      uint32_t get_year() const { return year; }

      /** The month, 1 through 12 for Jan to Dec */
      uint32_t get_month() const { return month; }

      /** The day of the month, 1 through 31 (or 28 or 30 based on month */
      uint32_t get_day() const { return day; }

      /** Hour in 24-hour form, 0 to 23 */
      uint32_t get_hour() const { return hour; }

      /** Minutes in the hour, 0 to 60 */
      uint32_t get_minutes() const { return minutes; }

      /** Seconds in the minute, 0 to 60, but might be slightly
      larger to deal with leap seconds on some systems
      */
      uint32_t get_seconds() const { return seconds; }

      /**
      * Initialize a calendar_point
      * @param y the year
      * @param mon the month
      * @param d the day
      * @param h the hour
      * @param min the minute
      * @param sec the second
      */
      calendar_point(uint32_t y, uint32_t mon, uint32_t d, uint32_t h, uint32_t min, uint32_t sec) :
         year(y), month(mon), day(d), hour(h), minutes(min), seconds(sec) {}

      /**
      * Returns an STL timepoint object
      */
      std::chrono::system_clock::time_point to_std_timepoint() const;

      /**
      * Returns a human readable string of the struct's components.
      * Formatting might change over time. Currently it is RFC339 'iso-date-time'.
      */
      std::string to_string() const;

   BOTAN_DEPRECATED_PUBLIC_MEMBER_VARIABLES:
      /*
      The member variables are public for historical reasons. Use the get_xxx() functions
      defined above. These members will be made private in a future major release.
      */
      uint32_t year;
      uint32_t month;
      uint32_t day;
      uint32_t hour;
      uint32_t minutes;
      uint32_t seconds;
   };

/**
* Convert a time_point to a calendar_point
* @param time_point a time point from the system clock
* @return calendar_point object representing this time point
*/
BOTAN_PUBLIC_API(2,0) calendar_point calendar_value(
   const std::chrono::system_clock::time_point& time_point);

}

namespace Botan {

/**
* Convert a sequence of UCS-2 (big endian) characters to a UTF-8 string
* This is used for ASN.1 BMPString type
* @param ucs2 the sequence of UCS-2 characters
* @param len length of ucs2 in bytes, must be a multiple of 2
*/
std::string BOTAN_UNSTABLE_API ucs2_to_utf8(const uint8_t ucs2[], size_t len);

/**
* Convert a sequence of UCS-4 (big endian) characters to a UTF-8 string
* This is used for ASN.1 UniversalString type
* @param ucs4 the sequence of UCS-4 characters
* @param len length of ucs4 in bytes, must be a multiple of 4
*/
std::string BOTAN_UNSTABLE_API ucs4_to_utf8(const uint8_t ucs4[], size_t len);

/**
* Convert a UTF-8 string to Latin-1
* If a character outside the Latin-1 range is encountered, an exception is thrown.
*/
std::string BOTAN_UNSTABLE_API utf8_to_latin1(const std::string& utf8);

/**
* The different charsets (nominally) supported by Botan.
*/
enum Character_Set {
   LOCAL_CHARSET,
   UCS2_CHARSET,
   UTF8_CHARSET,
   LATIN1_CHARSET
};

namespace Charset {

/*
* Character set conversion - avoid this.
* For specific conversions, use the functions above like
* ucs2_to_utf8 and utf8_to_latin1
*
* If you need something more complex than that, use a real library
* such as iconv, Boost.Locale, or ICU
*/
std::string BOTAN_PUBLIC_API(2,0)
   BOTAN_DEPRECATED("Avoid. See comment in header.")
   transcode(const std::string& str,
             Character_Set to,
             Character_Set from);

/*
* Simple character classifier functions
*/
bool BOTAN_PUBLIC_API(2,0) is_digit(char c);
bool BOTAN_PUBLIC_API(2,0) is_space(char c);
bool BOTAN_PUBLIC_API(2,0) caseless_cmp(char x, char y);

uint8_t BOTAN_PUBLIC_API(2,0) char2digit(char c);
char BOTAN_PUBLIC_API(2,0) digit2char(uint8_t b);

}

}

namespace Botan {

/**
* A class handling runtime CPU feature detection. It is limited to
* just the features necessary to implement CPU specific code in Botan,
* rather than being a general purpose utility.
*
* This class supports:
*
*  - x86 features using CPUID. x86 is also the only processor with
*    accurate cache line detection currently.
*
*  - PowerPC AltiVec detection on Linux, NetBSD, OpenBSD, and Darwin
*
*  - ARM NEON and crypto extensions detection. On Linux and Android
*    systems which support getauxval, that is used to access CPU
*    feature information. Otherwise a relatively portable but
*    thread-unsafe mechanism involving executing probe functions which
*    catching SIGILL signal is used.
*/
class BOTAN_PUBLIC_API(2,1) CPUID final
   {
   public:
      /**
      * Probe the CPU and see what extensions are supported
      */
      static void initialize();

      static bool has_simd_32();

      /**
      * Deprecated equivalent to
      * o << "CPUID flags: " << CPUID::to_string() << "\n";
      */
      BOTAN_DEPRECATED("Use CPUID::to_string")
      static void print(std::ostream& o);

      /**
      * Return a possibly empty string containing list of known CPU
      * extensions. Each name will be seperated by a space, and the ordering
      * will be arbitrary. This list only contains values that are useful to
      * Botan (for example FMA instructions are not checked).
      *
      * Example outputs "sse2 ssse3 rdtsc", "neon arm_aes", "altivec"
      */
      static std::string to_string();

      /**
      * Return a best guess of the cache line size
      */
      static size_t cache_line_size()
         {
         if(g_processor_features == 0)
            {
            initialize();
            }
         return g_cache_line_size;
         }

      static bool is_little_endian()
         {
         return endian_status() == ENDIAN_LITTLE;
         }

      static bool is_big_endian()
         {
         return endian_status() == ENDIAN_BIG;
         }

      enum CPUID_bits : uint64_t {
#if defined(BOTAN_TARGET_CPU_IS_X86_FAMILY)
         // These values have no relation to cpuid bitfields

         // SIMD instruction sets
         CPUID_SSE2_BIT    = (1ULL << 0),
         CPUID_SSSE3_BIT   = (1ULL << 1),
         CPUID_SSE41_BIT   = (1ULL << 2),
         CPUID_SSE42_BIT   = (1ULL << 3),
         CPUID_AVX2_BIT    = (1ULL << 4),
         CPUID_AVX512F_BIT = (1ULL << 5),

         // Misc useful instructions
         CPUID_RDTSC_BIT   = (1ULL << 10),
         CPUID_BMI2_BIT    = (1ULL << 11),
         CPUID_ADX_BIT     = (1ULL << 12),
         CPUID_BMI1_BIT    = (1ULL << 13),

         // Crypto-specific ISAs
         CPUID_AESNI_BIT   = (1ULL << 16),
         CPUID_CLMUL_BIT   = (1ULL << 17),
         CPUID_RDRAND_BIT  = (1ULL << 18),
         CPUID_RDSEED_BIT  = (1ULL << 19),
         CPUID_SHA_BIT     = (1ULL << 20),
#endif

#if defined(BOTAN_TARGET_CPU_IS_PPC_FAMILY)
         CPUID_ALTIVEC_BIT    = (1ULL << 0),
         CPUID_PPC_CRYPTO_BIT = (1ULL << 1),
#endif

#if defined(BOTAN_TARGET_CPU_IS_ARM_FAMILY)
         CPUID_ARM_NEON_BIT      = (1ULL << 0),
         CPUID_ARM_SVE_BIT       = (1ULL << 1),
         CPUID_ARM_AES_BIT       = (1ULL << 16),
         CPUID_ARM_PMULL_BIT     = (1ULL << 17),
         CPUID_ARM_SHA1_BIT      = (1ULL << 18),
         CPUID_ARM_SHA2_BIT      = (1ULL << 19),
         CPUID_ARM_SHA3_BIT      = (1ULL << 20),
         CPUID_ARM_SHA2_512_BIT  = (1ULL << 21),
         CPUID_ARM_SM3_BIT       = (1ULL << 22),
         CPUID_ARM_SM4_BIT       = (1ULL << 23),
#endif

         CPUID_INITIALIZED_BIT = (1ULL << 63)
      };

#if defined(BOTAN_TARGET_CPU_IS_PPC_FAMILY)
      /**
      * Check if the processor supports AltiVec/VMX
      */
      static bool has_altivec()
         { return has_cpuid_bit(CPUID_ALTIVEC_BIT); }

      /**
      * Check if the processor supports POWER8 crypto extensions
      */
      static bool has_ppc_crypto()
         { return has_cpuid_bit(CPUID_PPC_CRYPTO_BIT); }

#endif

#if defined(BOTAN_TARGET_CPU_IS_ARM_FAMILY)
      /**
      * Check if the processor supports NEON SIMD
      */
      static bool has_neon()
         { return has_cpuid_bit(CPUID_ARM_NEON_BIT); }

      /**
      * Check if the processor supports ARMv8 SVE
      */
      static bool has_arm_sve()
         { return has_cpuid_bit(CPUID_ARM_SVE_BIT); }

      /**
      * Check if the processor supports ARMv8 SHA1
      */
      static bool has_arm_sha1()
         { return has_cpuid_bit(CPUID_ARM_SHA1_BIT); }

      /**
      * Check if the processor supports ARMv8 SHA2
      */
      static bool has_arm_sha2()
         { return has_cpuid_bit(CPUID_ARM_SHA2_BIT); }

      /**
      * Check if the processor supports ARMv8 AES
      */
      static bool has_arm_aes()
         { return has_cpuid_bit(CPUID_ARM_AES_BIT); }

      /**
      * Check if the processor supports ARMv8 PMULL
      */
      static bool has_arm_pmull()
         { return has_cpuid_bit(CPUID_ARM_PMULL_BIT); }

      /**
      * Check if the processor supports ARMv8 SHA-512
      */
      static bool has_arm_sha2_512()
         { return has_cpuid_bit(CPUID_ARM_SHA2_512_BIT); }

      /**
      * Check if the processor supports ARMv8 SHA-3
      */
      static bool has_arm_sha3()
         { return has_cpuid_bit(CPUID_ARM_SHA3_BIT); }

      /**
      * Check if the processor supports ARMv8 SM3
      */
      static bool has_arm_sm3()
         { return has_cpuid_bit(CPUID_ARM_SM3_BIT); }

      /**
      * Check if the processor supports ARMv8 SM4
      */
      static bool has_arm_sm4()
         { return has_cpuid_bit(CPUID_ARM_SM4_BIT); }

#endif

#if defined(BOTAN_TARGET_CPU_IS_X86_FAMILY)

      /**
      * Check if the processor supports RDTSC
      */
      static bool has_rdtsc()
         { return has_cpuid_bit(CPUID_RDTSC_BIT); }

      /**
      * Check if the processor supports SSE2
      */
      static bool has_sse2()
         { return has_cpuid_bit(CPUID_SSE2_BIT); }

      /**
      * Check if the processor supports SSSE3
      */
      static bool has_ssse3()
         { return has_cpuid_bit(CPUID_SSSE3_BIT); }

      /**
      * Check if the processor supports SSE4.1
      */
      static bool has_sse41()
         { return has_cpuid_bit(CPUID_SSE41_BIT); }

      /**
      * Check if the processor supports SSE4.2
      */
      static bool has_sse42()
         { return has_cpuid_bit(CPUID_SSE42_BIT); }

      /**
      * Check if the processor supports AVX2
      */
      static bool has_avx2()
         { return has_cpuid_bit(CPUID_AVX2_BIT); }

      /**
      * Check if the processor supports AVX-512F
      */
      static bool has_avx512f()
         { return has_cpuid_bit(CPUID_AVX512F_BIT); }

      /**
      * Check if the processor supports BMI1
      */
      static bool has_bmi1()
         { return has_cpuid_bit(CPUID_BMI1_BIT); }

      /**
      * Check if the processor supports BMI2
      */
      static bool has_bmi2()
         { return has_cpuid_bit(CPUID_BMI2_BIT); }

      /**
      * Check if the processor supports AES-NI
      */
      static bool has_aes_ni()
         { return has_cpuid_bit(CPUID_AESNI_BIT); }

      /**
      * Check if the processor supports CLMUL
      */
      static bool has_clmul()
         { return has_cpuid_bit(CPUID_CLMUL_BIT); }

      /**
      * Check if the processor supports Intel SHA extension
      */
      static bool has_intel_sha()
         { return has_cpuid_bit(CPUID_SHA_BIT); }

      /**
      * Check if the processor supports ADX extension
      */
      static bool has_adx()
         { return has_cpuid_bit(CPUID_ADX_BIT); }

      /**
      * Check if the processor supports RDRAND
      */
      static bool has_rdrand()
         { return has_cpuid_bit(CPUID_RDRAND_BIT); }

      /**
      * Check if the processor supports RDSEED
      */
      static bool has_rdseed()
         { return has_cpuid_bit(CPUID_RDSEED_BIT); }
#endif

      /*
      * Clear a CPUID bit
      * Call CPUID::initialize to reset
      *
      * This is only exposed for testing, don't use unless you know
      * what you are doing.
      */
      static void clear_cpuid_bit(CPUID_bits bit)
         {
         const uint64_t mask = ~(static_cast<uint64_t>(bit));
         g_processor_features &= mask;
         }

      /*
      * Don't call this function, use CPUID::has_xxx above
      * It is only exposed for the tests.
      */
      static bool has_cpuid_bit(CPUID_bits elem)
         {
         if(g_processor_features == 0)
            initialize();

         const uint64_t elem64 = static_cast<uint64_t>(elem);
         return ((g_processor_features & elem64) == elem64);
         }

      static std::vector<CPUID::CPUID_bits> bit_from_string(const std::string& tok);
   private:
      enum Endian_status : uint32_t {
         ENDIAN_UNKNOWN = 0x00000000,
         ENDIAN_BIG     = 0x01234567,
         ENDIAN_LITTLE  = 0x67452301,
      };

#if defined(BOTAN_TARGET_CPU_IS_PPC_FAMILY) || \
    defined(BOTAN_TARGET_CPU_IS_ARM_FAMILY) || \
    defined(BOTAN_TARGET_CPU_IS_X86_FAMILY)

      static uint64_t detect_cpu_features(size_t* cache_line_size);

#endif

      static Endian_status runtime_check_endian();

      static Endian_status endian_status()
         {
         if(g_endian_status == ENDIAN_UNKNOWN)
            {
            g_endian_status = runtime_check_endian();
            }
         return g_endian_status;
         }

      static uint64_t g_processor_features;
      static size_t g_cache_line_size;
      static Endian_status g_endian_status;
   };

}

namespace Botan {

/**
* NIST Prime reduction functions.
*
* Reduces the value in place
*
* ws is a workspace function which is used as a temporary,
* and will be resized as needed.
*/
BOTAN_PUBLIC_API(2,0) const BigInt& prime_p521();
BOTAN_PUBLIC_API(2,0) void redc_p521(BigInt& x, secure_vector<word>& ws);

#define BOTAN_HAS_NIST_PRIME_REDUCERS_W32

BOTAN_PUBLIC_API(2,0) const BigInt& prime_p384();
BOTAN_PUBLIC_API(2,0) void redc_p384(BigInt& x, secure_vector<word>& ws);

BOTAN_PUBLIC_API(2,0) const BigInt& prime_p256();
BOTAN_PUBLIC_API(2,0) void redc_p256(BigInt& x, secure_vector<word>& ws);

BOTAN_PUBLIC_API(2,0) const BigInt& prime_p224();
BOTAN_PUBLIC_API(2,0) void redc_p224(BigInt& x, secure_vector<word>& ws);

BOTAN_PUBLIC_API(2,0) const BigInt& prime_p192();
BOTAN_PUBLIC_API(2,0) void redc_p192(BigInt& x, secure_vector<word>& ws);

}

namespace Botan {

class BOTAN_PUBLIC_API(2,0) SQL_Database
   {
   public:

      class BOTAN_PUBLIC_API(2,0) SQL_DB_Error final : public Exception
         {
         public:
            explicit SQL_DB_Error(const std::string& what) : Exception("SQL database", what) {}
         };

      class BOTAN_PUBLIC_API(2,0) Statement
         {
         public:
            /* Bind statement parameters */
            virtual void bind(int column, const std::string& str) = 0;

            virtual void bind(int column, size_t i) = 0;

            virtual void bind(int column, std::chrono::system_clock::time_point time) = 0;

            virtual void bind(int column, const std::vector<uint8_t>& blob) = 0;

            virtual void bind(int column, const uint8_t* data, size_t len) = 0;

            /* Get output */
            virtual std::pair<const uint8_t*, size_t> get_blob(int column) = 0;

            virtual std::string get_str(int column) = 0;

            virtual size_t get_size_t(int column) = 0;

            /* Run to completion */
            virtual size_t spin() = 0;

            /* Maybe update */
            virtual bool step() = 0;

            virtual ~Statement() = default;
         };

      /*
      * Create a new statement for execution.
      * Use ?1, ?2, ?3, etc for parameters to set later with bind
      */
      virtual std::shared_ptr<Statement> new_statement(const std::string& base_sql) const = 0;

      virtual size_t row_count(const std::string& table_name) = 0;

      virtual void create_table(const std::string& table_schema) = 0;

      virtual ~SQL_Database() = default;
};

}

namespace Botan {

class BigInt;
class ASN1_Object;

/**
* General DER Encoding Object
*/
class BOTAN_PUBLIC_API(2,0) DER_Encoder final
   {
   public:
      typedef std::function<void (const uint8_t[], size_t)> append_fn;

      /**
      * DER encode, writing to an internal buffer
      * Use get_contents or get_contents_unlocked to read the results
      * after all encoding is completed.
      */
      DER_Encoder() = default;

      /**
      * DER encode, writing to @param vec
      * If this constructor is used, get_contents* may not be called.
      */
      DER_Encoder(secure_vector<uint8_t>& vec);

      /**
      * DER encode, writing to @param vec
      * If this constructor is used, get_contents* may not be called.
      */
      DER_Encoder(std::vector<uint8_t>& vec);

      /**
      * DER encode, calling append to write output
      * If this constructor is used, get_contents* may not be called.
      */
      DER_Encoder(append_fn append) : m_append_output(append) {}

      secure_vector<uint8_t> get_contents();

      std::vector<uint8_t> get_contents_unlocked();

      DER_Encoder& start_cons(ASN1_Tag type_tag,
                              ASN1_Tag class_tag = UNIVERSAL);
      DER_Encoder& end_cons();

      DER_Encoder& start_explicit(uint16_t type_tag);
      DER_Encoder& end_explicit();

      /**
      * Insert raw bytes directly into the output stream
      */
      DER_Encoder& raw_bytes(const uint8_t val[], size_t len);

      template<typename Alloc>
      DER_Encoder& raw_bytes(const std::vector<uint8_t, Alloc>& val)
         {
         return raw_bytes(val.data(), val.size());
         }

      DER_Encoder& encode_null();
      DER_Encoder& encode(bool b);
      DER_Encoder& encode(size_t s);
      DER_Encoder& encode(const BigInt& n);
      DER_Encoder& encode(const uint8_t val[], size_t len, ASN1_Tag real_type);

      template<typename Alloc>
      DER_Encoder& encode(const std::vector<uint8_t, Alloc>& vec, ASN1_Tag real_type)
         {
         return encode(vec.data(), vec.size(), real_type);
         }

      DER_Encoder& encode(bool b,
                          ASN1_Tag type_tag,
                          ASN1_Tag class_tag = CONTEXT_SPECIFIC);

      DER_Encoder& encode(size_t s,
                          ASN1_Tag type_tag,
                          ASN1_Tag class_tag = CONTEXT_SPECIFIC);

      DER_Encoder& encode(const BigInt& n,
                          ASN1_Tag type_tag,
                          ASN1_Tag class_tag = CONTEXT_SPECIFIC);

      DER_Encoder& encode(const uint8_t v[], size_t len,
                          ASN1_Tag real_type,
                          ASN1_Tag type_tag,
                          ASN1_Tag class_tag = CONTEXT_SPECIFIC);

      template<typename Alloc>
      DER_Encoder& encode(const std::vector<uint8_t, Alloc>& bytes,
                          ASN1_Tag real_type,
                          ASN1_Tag type_tag, ASN1_Tag class_tag)
         {
         return encode(bytes.data(), bytes.size(),
                       real_type, type_tag, class_tag);
         }

      template<typename T>
      DER_Encoder& encode_optional(const T& value, const T& default_value)
         {
         if(value != default_value)
            encode(value);
         return (*this);
         }

      template<typename T>
      DER_Encoder& encode_list(const std::vector<T>& values)
         {
         for(size_t i = 0; i != values.size(); ++i)
            encode(values[i]);
         return (*this);
         }

      /*
      * Request for an object to encode itself to this stream
      */
      DER_Encoder& encode(const ASN1_Object& obj);

      /*
      * Conditionally write some values to the stream
      */
      DER_Encoder& encode_if(bool pred, DER_Encoder& enc)
         {
         if(pred)
            return raw_bytes(enc.get_contents());
         return (*this);
         }

      DER_Encoder& encode_if(bool pred, const ASN1_Object& obj)
         {
         if(pred)
            encode(obj);
         return (*this);
         }

      DER_Encoder& add_object(ASN1_Tag type_tag, ASN1_Tag class_tag,
                              const uint8_t rep[], size_t length);

      DER_Encoder& add_object(ASN1_Tag type_tag, ASN1_Tag class_tag,
                              const std::vector<uint8_t>& rep)
         {
         return add_object(type_tag, class_tag, rep.data(), rep.size());
         }

      DER_Encoder& add_object(ASN1_Tag type_tag, ASN1_Tag class_tag,
                              const secure_vector<uint8_t>& rep)
         {
         return add_object(type_tag, class_tag, rep.data(), rep.size());
         }

      DER_Encoder& add_object(ASN1_Tag type_tag, ASN1_Tag class_tag,
                              const std::string& str);

      DER_Encoder& add_object(ASN1_Tag type_tag, ASN1_Tag class_tag,
                              uint8_t val);

   private:
      class DER_Sequence final
         {
         public:
            ASN1_Tag tag_of() const;

            void push_contents(DER_Encoder& der);

            void add_bytes(const uint8_t val[], size_t len);

            void add_bytes(const uint8_t hdr[], size_t hdr_len,
                           const uint8_t val[], size_t val_len);

            DER_Sequence(ASN1_Tag, ASN1_Tag);

            DER_Sequence(DER_Sequence&& seq)
               {
               std::swap(m_type_tag, seq.m_type_tag);
               std::swap(m_class_tag, seq.m_class_tag);
               std::swap(m_contents, seq.m_contents);
               std::swap(m_set_contents, seq.m_set_contents);
               }

            DER_Sequence& operator=(DER_Sequence&& seq)
               {
               std::swap(m_type_tag, seq.m_type_tag);
               std::swap(m_class_tag, seq.m_class_tag);
               std::swap(m_contents, seq.m_contents);
               std::swap(m_set_contents, seq.m_set_contents);
               return (*this);
               }

            DER_Sequence(const DER_Sequence& seq) = default;

            DER_Sequence& operator=(const DER_Sequence& seq) = default;

         private:
            ASN1_Tag m_type_tag, m_class_tag;
            secure_vector<uint8_t> m_contents;
            std::vector< secure_vector<uint8_t> > m_set_contents;
         };

      append_fn m_append_output;
      secure_vector<uint8_t> m_default_outbuf;
      std::vector<DER_Sequence> m_subsequences;
   };

}

namespace Botan {

/**
* BigInt Division
* @param x an integer
* @param y a non-zero integer
* @param q will be set to x / y
* @param r will be set to x % y
*/
void BOTAN_PUBLIC_API(2,0) divide(const BigInt& x,
                      const BigInt& y,
                      BigInt& q,
                      BigInt& r);

}

namespace Botan {

/**
* Represents a DLL or shared object
*/
class BOTAN_PUBLIC_API(2,0) Dynamically_Loaded_Library final
   {
   public:
      /**
      * Load a DLL (or fail with an exception)
      * @param lib_name name or path to a library
      *
      * If you don't use a full path, the search order will be defined
      * by whatever the system linker does by default. Always using fully
      * qualified pathnames can help prevent code injection attacks (eg
      * via manipulation of LD_LIBRARY_PATH on Linux)
      */
      Dynamically_Loaded_Library(const std::string& lib_name);

      /**
      * Unload the DLL
      * @warning Any pointers returned by resolve()/resolve_symbol()
      * should not be used after this destructor runs.
      */
      ~Dynamically_Loaded_Library();

      /**
      * Load a symbol (or fail with an exception)
      * @param symbol names the symbol to load
      * @return address of the loaded symbol
      */
      void* resolve_symbol(const std::string& symbol);

      /**
      * Convenience function for casting symbol to the right type
      * @param symbol names the symbol to load
      * @return address of the loaded symbol
      */
      template<typename T>
      T resolve(const std::string& symbol)
         {
         return reinterpret_cast<T>(resolve_symbol(symbol));
         }

   private:
      Dynamically_Loaded_Library(const Dynamically_Loaded_Library&);
      Dynamically_Loaded_Library& operator=(const Dynamically_Loaded_Library&);

      std::string m_lib_name;
      void* m_lib;
   };

}

namespace Botan {

class RandomNumberGenerator;

/**
* Encoding Method for Encryption
*/
class BOTAN_PUBLIC_API(2,0) EME
   {
   public:
      virtual ~EME() = default;

      /**
      * Return the maximum input size in bytes we can support
      * @param keybits the size of the key in bits
      * @return upper bound of input in bytes
      */
      virtual size_t maximum_input_size(size_t keybits) const = 0;

      /**
      * Encode an input
      * @param in the plaintext
      * @param in_length length of plaintext in bytes
      * @param key_length length of the key in bits
      * @param rng a random number generator
      * @return encoded plaintext
      */
      secure_vector<uint8_t> encode(const uint8_t in[],
                                 size_t in_length,
                                 size_t key_length,
                                 RandomNumberGenerator& rng) const;

      /**
      * Encode an input
      * @param in the plaintext
      * @param key_length length of the key in bits
      * @param rng a random number generator
      * @return encoded plaintext
      */
      secure_vector<uint8_t> encode(const secure_vector<uint8_t>& in,
                                 size_t key_length,
                                 RandomNumberGenerator& rng) const;

      /**
      * Decode an input
      * @param valid_mask written to specifies if output is valid
      * @param in the encoded plaintext
      * @param in_len length of encoded plaintext in bytes
      * @return bytes of out[] written to along with
      *         validity mask (0xFF if valid, else 0x00)
      */
      virtual secure_vector<uint8_t> unpad(uint8_t& valid_mask,
                                        const uint8_t in[],
                                        size_t in_len) const = 0;

      /**
      * Encode an input
      * @param in the plaintext
      * @param in_length length of plaintext in bytes
      * @param key_length length of the key in bits
      * @param rng a random number generator
      * @return encoded plaintext
      */
      virtual secure_vector<uint8_t> pad(const uint8_t in[],
                                      size_t in_length,
                                      size_t key_length,
                                      RandomNumberGenerator& rng) const = 0;
   };

/**
* Factory method for EME (message-encoding methods for encryption) objects
* @param algo_spec the name of the EME to create
* @return pointer to newly allocated object of that type
*/
BOTAN_PUBLIC_API(2,0) EME*  get_eme(const std::string& algo_spec);

}

namespace Botan {

class Private_Key;
class RandomNumberGenerator;

/**
* EMSA, from IEEE 1363s Encoding Method for Signatures, Appendix
*
* Any way of encoding/padding signatures
*/
class BOTAN_PUBLIC_API(2,0) EMSA
   {
   public:
      virtual ~EMSA() = default;

      /**
      * Add more data to the signature computation
      * @param input some data
      * @param length length of input in bytes
      */
      virtual void update(const uint8_t input[], size_t length) = 0;

      /**
      * @return raw hash
      */
      virtual secure_vector<uint8_t> raw_data() = 0;

      /**
      * Return the encoding of a message
      * @param msg the result of raw_data()
      * @param output_bits the desired output bit size
      * @param rng a random number generator
      * @return encoded signature
      */
      virtual secure_vector<uint8_t> encoding_of(const secure_vector<uint8_t>& msg,
                                             size_t output_bits,
                                             RandomNumberGenerator& rng) = 0;

      /**
      * Verify the encoding
      * @param coded the received (coded) message representative
      * @param raw the computed (local, uncoded) message representative
      * @param key_bits the size of the key in bits
      * @return true if coded is a valid encoding of raw, otherwise false
      */
      virtual bool verify(const secure_vector<uint8_t>& coded,
                          const secure_vector<uint8_t>& raw,
                          size_t key_bits) = 0;

      /**
      * Prepare sig_algo for use in choose_sig_format for x509 certs
      *
      * @param key used for checking compatibility with the encoding scheme
      * @param cert_hash_name is checked to equal the hash for the encoding
      * @return algorithm identifier to signatures created using this key,
      *         padding method and hash.
      */
      virtual AlgorithmIdentifier config_for_x509(const Private_Key& key,
                                                  const std::string& cert_hash_name) const;

      /**
      * @return a new object representing the same encoding method as *this
      */
      virtual EMSA* clone() = 0;

      /**
      * @return the SCAN name of the encoding/padding scheme
      */
      virtual std::string name() const = 0;
   };

/**
* Factory method for EMSA (message-encoding methods for signatures
* with appendix) objects
* @param algo_spec the name of the EMSA to create
* @return pointer to newly allocated object of that type
*/
BOTAN_PUBLIC_API(2,0) EMSA* get_emsa(const std::string& algo_spec);

/**
* Returns the hash function used in the given EMSA scheme
* If the hash function is not specified or not understood,
* returns "SHA-512"
* @param algo_spec the name of the EMSA
* @return hash function used in the given EMSA scheme
*/
BOTAN_PUBLIC_API(2,0) std::string hash_for_emsa(const std::string& algo_spec);

}

namespace Botan {

class RandomNumberGenerator;

/**
* Abstract interface to a source of entropy
*/
class BOTAN_PUBLIC_API(2,0) Entropy_Source
   {
   public:
      /**
      * Return a new entropy source of a particular type, or null
      * Each entropy source may require substantial resources (eg, a file handle
      * or socket instance), so try to share them among multiple RNGs, or just
      * use the preconfigured global list accessed by Entropy_Sources::global_sources()
      */
      static std::unique_ptr<Entropy_Source> create(const std::string& type);

      /**
      * @return name identifying this entropy source
      */
      virtual std::string name() const = 0;

      /**
      * Perform an entropy gathering poll
      * @param rng will be provided with entropy via calls to add_entropy
      * @return conservative estimate of actual entropy added to rng during poll
      */
      virtual size_t poll(RandomNumberGenerator& rng) = 0;

      Entropy_Source() = default;
      Entropy_Source(const Entropy_Source& other) = delete;
      Entropy_Source(Entropy_Source&& other) = delete;
      Entropy_Source& operator=(const Entropy_Source& other) = delete;

      virtual ~Entropy_Source() = default;
   };

class BOTAN_PUBLIC_API(2,0) Entropy_Sources final
   {
   public:
      static Entropy_Sources& global_sources();

      void add_source(std::unique_ptr<Entropy_Source> src);

      std::vector<std::string> enabled_sources() const;

      size_t poll(RandomNumberGenerator& rng,
                  size_t bits,
                  std::chrono::milliseconds timeout);

      /**
      * Poll just a single named source. Ordinally only used for testing
      */
      size_t poll_just(RandomNumberGenerator& rng, const std::string& src);

      Entropy_Sources() = default;
      explicit Entropy_Sources(const std::vector<std::string>& sources);

      Entropy_Sources(const Entropy_Sources& other) = delete;
      Entropy_Sources(Entropy_Sources&& other) = delete;
      Entropy_Sources& operator=(const Entropy_Sources& other) = delete;

   private:
      std::vector<std::unique_ptr<Entropy_Source>> m_srcs;
   };

}

namespace Botan {

/**
* This class represents hash function (message digest) objects
*/
class BOTAN_PUBLIC_API(2,0) HashFunction : public Buffered_Computation
   {
   public:
      /**
      * Create an instance based on a name, or return null if the
      * algo/provider combination cannot be found. If provider is
      * empty then best available is chosen.
      */
      static std::unique_ptr<HashFunction>
         create(const std::string& algo_spec,
                const std::string& provider = "");

      /**
      * Create an instance based on a name
      * If provider is empty then best available is chosen.
      * @param algo_spec algorithm name
      * @param provider provider implementation to use
      * Throws Lookup_Error if not found.
      */
      static std::unique_ptr<HashFunction>
         create_or_throw(const std::string& algo_spec,
                         const std::string& provider = "");

      /**
      * @return list of available providers for this algorithm, empty if not available
      * @param algo_spec algorithm name
      */
      static std::vector<std::string> providers(const std::string& algo_spec);

      /**
      * @return new object representing the same algorithm as *this
      */
      virtual HashFunction* clone() const = 0;

      /**
      * @return provider information about this implementation. Default is "base",
      * might also return "sse2", "avx2", "openssl", or some other arbitrary string.
      */
      virtual std::string provider() const { return "base"; }

      virtual ~HashFunction() = default;

      /**
      * Reset the state.
      */
      virtual void clear() = 0;

      /**
      * @return the hash function name
      */
      virtual std::string name() const = 0;

      /**
      * @return hash block size as defined for this algorithm
      */
      virtual size_t hash_block_size() const { return 0; }

      /**
      * Return a new hash object with the same state as *this. This
      * allows computing the hash of several messages with a common
      * prefix more efficiently than would otherwise be possible.
      *
      * This function should be called `clone` but that was already
      * used for the case of returning an uninitialized object.
      * @return new hash object
      */
      virtual std::unique_ptr<HashFunction> copy_state() const = 0;
   };

}

namespace Botan {

/**
* Perform hex encoding
* @param output an array of at least input_length*2 bytes
* @param input is some binary data
* @param input_length length of input in bytes
* @param uppercase should output be upper or lower case?
*/
void BOTAN_PUBLIC_API(2,0) hex_encode(char output[],
                          const uint8_t input[],
                          size_t input_length,
                          bool uppercase = true);

/**
* Perform hex encoding
* @param input some input
* @param input_length length of input in bytes
* @param uppercase should output be upper or lower case?
* @return hexadecimal representation of input
*/
std::string BOTAN_PUBLIC_API(2,0) hex_encode(const uint8_t input[],
                                 size_t input_length,
                                 bool uppercase = true);

/**
* Perform hex encoding
* @param input some input
* @param uppercase should output be upper or lower case?
* @return hexadecimal representation of input
*/
template<typename Alloc>
std::string hex_encode(const std::vector<uint8_t, Alloc>& input,
                       bool uppercase = true)
   {
   return hex_encode(input.data(), input.size(), uppercase);
   }

/**
* Perform hex decoding
* @param output an array of at least input_length/2 bytes
* @param input some hex input
* @param input_length length of input in bytes
* @param input_consumed is an output parameter which says how many
*        bytes of input were actually consumed. If less than
*        input_length, then the range input[consumed:length]
*        should be passed in later along with more input.
* @param ignore_ws ignore whitespace on input; if false, throw an
                   exception if whitespace is encountered
* @return number of bytes written to output
*/
size_t BOTAN_PUBLIC_API(2,0) hex_decode(uint8_t output[],
                            const char input[],
                            size_t input_length,
                            size_t& input_consumed,
                            bool ignore_ws = true);

/**
* Perform hex decoding
* @param output an array of at least input_length/2 bytes
* @param input some hex input
* @param input_length length of input in bytes
* @param ignore_ws ignore whitespace on input; if false, throw an
                   exception if whitespace is encountered
* @return number of bytes written to output
*/
size_t BOTAN_PUBLIC_API(2,0) hex_decode(uint8_t output[],
                            const char input[],
                            size_t input_length,
                            bool ignore_ws = true);

/**
* Perform hex decoding
* @param output an array of at least input_length/2 bytes
* @param input some hex input
* @param ignore_ws ignore whitespace on input; if false, throw an
                   exception if whitespace is encountered
* @return number of bytes written to output
*/
size_t BOTAN_PUBLIC_API(2,0) hex_decode(uint8_t output[],
                            const std::string& input,
                            bool ignore_ws = true);

/**
* Perform hex decoding
* @param input some hex input
* @param input_length the length of input in bytes
* @param ignore_ws ignore whitespace on input; if false, throw an
                   exception if whitespace is encountered
* @return decoded hex output
*/
std::vector<uint8_t> BOTAN_PUBLIC_API(2,0)
hex_decode(const char input[],
           size_t input_length,
           bool ignore_ws = true);

/**
* Perform hex decoding
* @param input some hex input
* @param ignore_ws ignore whitespace on input; if false, throw an
                   exception if whitespace is encountered
* @return decoded hex output
*/
std::vector<uint8_t> BOTAN_PUBLIC_API(2,0)
hex_decode(const std::string& input,
           bool ignore_ws = true);


/**
* Perform hex decoding
* @param input some hex input
* @param input_length the length of input in bytes
* @param ignore_ws ignore whitespace on input; if false, throw an
                   exception if whitespace is encountered
* @return decoded hex output
*/
secure_vector<uint8_t> BOTAN_PUBLIC_API(2,0)
hex_decode_locked(const char input[],
                  size_t input_length,
                  bool ignore_ws = true);

/**
* Perform hex decoding
* @param input some hex input
* @param ignore_ws ignore whitespace on input; if false, throw an
                   exception if whitespace is encountered
* @return decoded hex output
*/
secure_vector<uint8_t> BOTAN_PUBLIC_API(2,0)
hex_decode_locked(const std::string& input,
                  bool ignore_ws = true);

}

namespace Botan {

/**
* Represents the length requirements on an algorithm key
*/
class BOTAN_PUBLIC_API(2,0) Key_Length_Specification final
   {
   public:
      /**
      * Constructor for fixed length keys
      * @param keylen the supported key length
      */
      explicit Key_Length_Specification(size_t keylen) :
         m_min_keylen(keylen),
         m_max_keylen(keylen),
         m_keylen_mod(1)
         {
         }

      /**
      * Constructor for variable length keys
      * @param min_k the smallest supported key length
      * @param max_k the largest supported key length
      * @param k_mod the number of bytes the key must be a multiple of
      */
      Key_Length_Specification(size_t min_k,
                               size_t max_k,
                               size_t k_mod = 1) :
         m_min_keylen(min_k),
         m_max_keylen(max_k ? max_k : min_k),
         m_keylen_mod(k_mod)
         {
         }

      /**
      * @param length is a key length in bytes
      * @return true iff this length is a valid length for this algo
      */
      bool valid_keylength(size_t length) const
         {
         return ((length >= m_min_keylen) &&
                 (length <= m_max_keylen) &&
                 (length % m_keylen_mod == 0));
         }

      /**
      * @return minimum key length in bytes
      */
      size_t minimum_keylength() const
         {
         return m_min_keylen;
         }

      /**
      * @return maximum key length in bytes
      */
      size_t maximum_keylength() const
         {
         return m_max_keylen;
         }

      /**
      * @return key length multiple in bytes
      */
      size_t keylength_multiple() const
         {
         return m_keylen_mod;
         }

      /*
      * Multiplies all length requirements with the given factor
      * @param n the multiplication factor
      * @return a key length specification multiplied by the factor
      */
      Key_Length_Specification multiple(size_t n) const
         {
         return Key_Length_Specification(n * m_min_keylen,
                                         n * m_max_keylen,
                                         n * m_keylen_mod);
         }

   private:
      size_t m_min_keylen, m_max_keylen, m_keylen_mod;
   };

}

namespace Botan {

/**
* Octet String
*/
class BOTAN_PUBLIC_API(2,0) OctetString final
   {
   public:
      /**
      * @return size of this octet string in bytes
      */
      size_t length() const { return m_data.size(); }
      size_t size() const { return m_data.size(); }

      /**
      * @return this object as a secure_vector<uint8_t>
      */
      secure_vector<uint8_t> bits_of() const { return m_data; }

      /**
      * @return start of this string
      */
      const uint8_t* begin() const { return m_data.data(); }

      /**
      * @return end of this string
      */
      const uint8_t* end() const   { return begin() + m_data.size(); }

      /**
      * @return this encoded as hex
      */
      std::string as_string() const;

      /**
      * XOR the contents of another octet string into this one
      * @param other octet string
      * @return reference to this
      */
      OctetString& operator^=(const OctetString& other);

      /**
      * Force to have odd parity
      */
      void set_odd_parity();

      /**
      * Create a new OctetString
      * @param str is a hex encoded string
      */
      explicit OctetString(const std::string& str = "");

      /**
      * Create a new random OctetString
      * @param rng is a random number generator
      * @param len is the desired length in bytes
      */
      OctetString(class RandomNumberGenerator& rng, size_t len);

      /**
      * Create a new OctetString
      * @param in is an array
      * @param len is the length of in in bytes
      */
      OctetString(const uint8_t in[], size_t len);

      /**
      * Create a new OctetString
      * @param in a bytestring
      */
      OctetString(const secure_vector<uint8_t>& in) : m_data(in) {}

      /**
      * Create a new OctetString
      * @param in a bytestring
      */
      OctetString(const std::vector<uint8_t>& in) : m_data(in.begin(), in.end()) {}

   private:
      secure_vector<uint8_t> m_data;
   };

/**
* Compare two strings
* @param x an octet string
* @param y an octet string
* @return if x is equal to y
*/
BOTAN_PUBLIC_API(2,0) bool operator==(const OctetString& x,
                          const OctetString& y);

/**
* Compare two strings
* @param x an octet string
* @param y an octet string
* @return if x is not equal to y
*/
BOTAN_PUBLIC_API(2,0) bool operator!=(const OctetString& x,
                          const OctetString& y);

/**
* Concatenate two strings
* @param x an octet string
* @param y an octet string
* @return x concatenated with y
*/
BOTAN_PUBLIC_API(2,0) OctetString operator+(const OctetString& x,
                                const OctetString& y);

/**
* XOR two strings
* @param x an octet string
* @param y an octet string
* @return x XORed with y
*/
BOTAN_PUBLIC_API(2,0) OctetString operator^(const OctetString& x,
                                const OctetString& y);


/**
* Alternate name for octet string showing intent to use as a key
*/
using SymmetricKey = OctetString;

/**
* Alternate name for octet string showing intent to use as an IV
*/
using InitializationVector = OctetString;

}

namespace Botan {

/**
* This class represents a symmetric algorithm object.
*/
class BOTAN_PUBLIC_API(2,0) SymmetricAlgorithm
   {
   public:
      virtual ~SymmetricAlgorithm() = default;

      /**
      * Reset the state.
      */
      virtual void clear() = 0;

      /**
      * @return object describing limits on key size
      */
      virtual Key_Length_Specification key_spec() const = 0;

      /**
      * @return minimum allowed key length
      */
      size_t maximum_keylength() const
         {
         return key_spec().maximum_keylength();
         }

      /**
      * @return maximum allowed key length
      */
      size_t minimum_keylength() const
         {
         return key_spec().minimum_keylength();
         }

      /**
      * Check whether a given key length is valid for this algorithm.
      * @param length the key length to be checked.
      * @return true if the key length is valid.
      */
      bool valid_keylength(size_t length) const
         {
         return key_spec().valid_keylength(length);
         }

      /**
      * Set the symmetric key of this object.
      * @param key the SymmetricKey to be set.
      */
      void set_key(const SymmetricKey& key)
         {
         set_key(key.begin(), key.length());
         }

      template<typename Alloc>
      void set_key(const std::vector<uint8_t, Alloc>& key)
         {
         set_key(key.data(), key.size());
         }

      /**
      * Set the symmetric key of this object.
      * @param key the to be set as a byte array.
      * @param length in bytes of key param
      */
      void set_key(const uint8_t key[], size_t length);

      /**
      * @return the algorithm name
      */
      virtual std::string name() const = 0;

   protected:
      void verify_key_set(bool cond) const
         {
         if(cond == false)
            throw_key_not_set_error();
         }

   private:
      void throw_key_not_set_error() const;

      /**
      * Run the key schedule
      * @param key the key
      * @param length of key
      */
      virtual void key_schedule(const uint8_t key[], size_t length) = 0;
   };

}

namespace Botan {

/**
* This class represents Message Authentication Code (MAC) objects.
*/
class BOTAN_PUBLIC_API(2,0) MessageAuthenticationCode : public Buffered_Computation,
                                            public SymmetricAlgorithm
   {
   public:
      /**
      * Create an instance based on a name
      * If provider is empty then best available is chosen.
      * @param algo_spec algorithm name
      * @param provider provider implementation to use
      * @return a null pointer if the algo/provider combination cannot be found
      */
      static std::unique_ptr<MessageAuthenticationCode>
         create(const std::string& algo_spec,
                const std::string& provider = "");

      /*
      * Create an instance based on a name
      * If provider is empty then best available is chosen.
      * @param algo_spec algorithm name
      * @param provider provider implementation to use
      * Throws a Lookup_Error if algo/provider combination cannot be found
      */
      static std::unique_ptr<MessageAuthenticationCode>
         create_or_throw(const std::string& algo_spec,
                         const std::string& provider = "");

      /**
      * @return list of available providers for this algorithm, empty if not available
      */
      static std::vector<std::string> providers(const std::string& algo_spec);

      virtual ~MessageAuthenticationCode() = default;

      /**
      * Prepare for processing a message under the specified nonce
      *
      * Most MACs neither require nor support a nonce; for these algorithms
      * calling `start_msg` is optional and calling it with anything other than
      * an empty string is an error. One MAC which *requires* a per-message
      * nonce be specified is GMAC.
      *
      * @param nonce the message nonce bytes
      * @param nonce_len the size of len in bytes
      * Default implementation simply rejects all non-empty nonces
      * since most hash/MAC algorithms do not support randomization
      */
      virtual void start_msg(const uint8_t nonce[], size_t nonce_len);

      /**
      * Begin processing a message with a nonce
      *
      * @param nonce the per message nonce
      */
      template<typename Alloc>
      void start(const std::vector<uint8_t, Alloc>& nonce)
         {
         start_msg(nonce.data(), nonce.size());
         }

      /**
      * Begin processing a message.
      * @param nonce the per message nonce
      * @param nonce_len length of nonce
      */
      void start(const uint8_t nonce[], size_t nonce_len)
         {
         start_msg(nonce, nonce_len);
         }

      /**
      * Begin processing a message.
      */
      void start()
         {
         return start_msg(nullptr, 0);
         }

      /**
      * Verify a MAC.
      * @param in the MAC to verify as a byte array
      * @param length the length of param in
      * @return true if the MAC is valid, false otherwise
      */
      virtual bool verify_mac(const uint8_t in[], size_t length);

      /**
      * Verify a MAC.
      * @param in the MAC to verify as a byte array
      * @return true if the MAC is valid, false otherwise
      */
      virtual bool verify_mac(const std::vector<uint8_t>& in)
         {
         return verify_mac(in.data(), in.size());
         }

      /**
      * Verify a MAC.
      * @param in the MAC to verify as a byte array
      * @return true if the MAC is valid, false otherwise
      */
      virtual bool verify_mac(const secure_vector<uint8_t>& in)
         {
         return verify_mac(in.data(), in.size());
         }

      /**
      * Get a new object representing the same algorithm as *this
      */
      virtual MessageAuthenticationCode* clone() const = 0;

      /**
      * @return provider information about this implementation. Default is "base",
      * might also return "sse2", "avx2", "openssl", or some other arbitrary string.
      */
      virtual std::string provider() const { return "base"; }

   };

typedef MessageAuthenticationCode MAC;

}

namespace Botan {

/**
* HMAC
*/
class BOTAN_PUBLIC_API(2,0) HMAC final : public MessageAuthenticationCode
   {
   public:
      void clear() override;
      std::string name() const override;
      MessageAuthenticationCode* clone() const override;

      size_t output_length() const override { return m_hash->output_length(); }

      Key_Length_Specification key_spec() const override;

      /**
      * @param hash the hash to use for HMACing
      */
      explicit HMAC(HashFunction* hash);

      HMAC(const HMAC&) = delete;
      HMAC& operator=(const HMAC&) = delete;
   private:
      void add_data(const uint8_t[], size_t) override;
      void final_result(uint8_t[]) override;
      void key_schedule(const uint8_t[], size_t) override;

      std::unique_ptr<HashFunction> m_hash;
      secure_vector<uint8_t> m_ikey, m_okey;
   };

}

namespace Botan {

/**
* Inherited by RNGs which maintain in-process state, like HMAC_DRBG.
* On Unix these RNGs are vulnerable to problems with fork, where the
* RNG state is duplicated, and the parent and child process RNGs will
* produce identical output until one of them reseeds. Stateful_RNG
* reseeds itself whenever a fork is detected, or after a set number of
* bytes have been output.
*
* Not implemented by RNGs which access an external RNG, such as the
* system PRNG or a hardware RNG.
*/
class BOTAN_PUBLIC_API(2,0) Stateful_RNG : public RandomNumberGenerator
   {
   public:
      /**
      * @param rng is a reference to some RNG which will be used
      * to perform the periodic reseeding
      * @param entropy_sources will be polled to perform reseeding periodically
      * @param reseed_interval specifies a limit of how many times
      * the RNG will be called before automatic reseeding is performed
      */
      Stateful_RNG(RandomNumberGenerator& rng,
                   Entropy_Sources& entropy_sources,
                   size_t reseed_interval) :
         m_underlying_rng(&rng),
         m_entropy_sources(&entropy_sources),
         m_reseed_interval(reseed_interval)
         {}

      /**
      * @param rng is a reference to some RNG which will be used
      * to perform the periodic reseeding
      * @param reseed_interval specifies a limit of how many times
      * the RNG will be called before automatic reseeding is performed
      */
      Stateful_RNG(RandomNumberGenerator& rng, size_t reseed_interval) :
         m_underlying_rng(&rng),
         m_reseed_interval(reseed_interval)
         {}

      /**
      * @param entropy_sources will be polled to perform reseeding periodically
      * @param reseed_interval specifies a limit of how many times
      * the RNG will be called before automatic reseeding is performed
      */
      Stateful_RNG(Entropy_Sources& entropy_sources, size_t reseed_interval) :
         m_entropy_sources(&entropy_sources),
         m_reseed_interval(reseed_interval)
         {}

      /**
      * In this case, automatic reseeding is impossible
      */
      Stateful_RNG() : m_reseed_interval(0) {}

      /**
      * Consume this input and mark the RNG as initialized regardless
      * of the length of the input or the current seeded state of
      * the RNG.
      */
      void initialize_with(const uint8_t input[], size_t length);

      bool is_seeded() const override final;

      bool accepts_input() const override final { return true; }

      /**
      * Mark state as requiring a reseed on next use
      */
      void force_reseed();

      void reseed_from_rng(RandomNumberGenerator& rng,
                           size_t poll_bits = BOTAN_RNG_RESEED_POLL_BITS) override final;

      /**
      * Overrides default implementation and also includes the current
      * process ID and the reseed counter.
      */
      void randomize_with_ts_input(uint8_t output[], size_t output_len) override final;

      /**
      * Poll provided sources for up to poll_bits bits of entropy
      * or until the timeout expires. Returns estimate of the number
      * of bits collected.
      */
      size_t reseed(Entropy_Sources& srcs,
                    size_t poll_bits = BOTAN_RNG_RESEED_POLL_BITS,
                    std::chrono::milliseconds poll_timeout = BOTAN_RNG_RESEED_DEFAULT_TIMEOUT) override;

      /**
      * @return intended security level of this DRBG
      */
      virtual size_t security_level() const = 0;

      /**
      * Some DRBGs have a notion of the maximum number of bytes per
      * request.  Longer requests (to randomize) will be treated as
      * multiple requests, and may initiate reseeding multiple times,
      * depending on the values of max_number_of_bytes_per_request and
      * reseed_interval(). This function returns zero if the RNG in
      * question does not have such a notion.
      *
      * @return max number of bytes per request (or zero)
      */
      virtual size_t max_number_of_bytes_per_request() const = 0;

      size_t reseed_interval() const { return m_reseed_interval; }

      void clear() override;

   protected:
      void reseed_check();

      /**
      * Called by a subclass to notify that a reseed has been
      * successfully performed.
      */
      void reset_reseed_counter() { m_reseed_counter = 1; }

   private:
      // A non-owned and possibly null pointer to shared RNG
      RandomNumberGenerator* m_underlying_rng = nullptr;

      // A non-owned and possibly null pointer to a shared Entropy_Source
      Entropy_Sources* m_entropy_sources = nullptr;

      const size_t m_reseed_interval;
      uint32_t m_last_pid = 0;

      /*
      * Set to 1 after a successful seeding, then incremented.  Reset
      * to 0 by clear() or a fork. This logic is used even if
      * automatic reseeding is disabled (via m_reseed_interval = 0)
      */
      size_t m_reseed_counter = 0;
   };

}

namespace Botan {

class Entropy_Sources;

/**
* HMAC_DRBG from NIST SP800-90A
*/
class BOTAN_PUBLIC_API(2,0) HMAC_DRBG final : public Stateful_RNG
   {
   public:
      /**
      * Initialize an HMAC_DRBG instance with the given MAC as PRF (normally HMAC)
      *
      * Automatic reseeding is disabled completely, as it has no access to
      * any source for seed material.
      *
      * If a fork is detected, the RNG will be unable to reseed itself
      * in response. In this case, an exception will be thrown rather
      * than generating duplicated output.
      */
      explicit HMAC_DRBG(std::unique_ptr<MessageAuthenticationCode> prf);

      /**
      * Initialize an HMAC_DRBG instance with the given MAC as PRF (normally HMAC)
      *
      * Automatic reseeding from @p underlying_rng will take place after
      * @p reseed_interval many requests or after a fork was detected.
      *
      * @param prf MAC to use as a PRF
      * @param underlying_rng is a reference to some RNG which will be used
      * to perform the periodic reseeding
      * @param reseed_interval specifies a limit of how many times
      * the RNG will be called before automatic reseeding is performed
      * @param max_number_of_bytes_per_request requests that are in size higher 
      * than max_number_of_bytes_per_request are treated as if multiple single 
      * requests of max_number_of_bytes_per_request size had been made.
      * In theory SP 800-90A requires that we reject any request for a DRBG
      * output longer than max_number_of_bytes_per_request. To avoid inconveniencing
      * the caller who wants an output larger than max_number_of_bytes_per_request, 
      * instead treat these requests as if multiple requests of 
      * max_number_of_bytes_per_request size had been made. NIST requires for 
      * HMAC_DRBG that every implementation set a value no more than 2**19 bits 
      * (or 64 KiB). Together with @p reseed_interval = 1 you can enforce that for 
      * example every 512 bit automatic reseeding occurs.
      */
      HMAC_DRBG(std::unique_ptr<MessageAuthenticationCode> prf,
                RandomNumberGenerator& underlying_rng,
                size_t reseed_interval = BOTAN_RNG_DEFAULT_RESEED_INTERVAL,
                size_t max_number_of_bytes_per_request = 64 * 1024);

      /**
      * Initialize an HMAC_DRBG instance with the given MAC as PRF (normally HMAC)
      *
      * Automatic reseeding from @p entropy_sources will take place after
      * @p reseed_interval many requests or after a fork was detected.
      *
      * @param prf MAC to use as a PRF
      * @param entropy_sources will be polled to perform reseeding periodically
      * @param reseed_interval specifies a limit of how many times
      * the RNG will be called before automatic reseeding is performed.
      * @param max_number_of_bytes_per_request requests that are in size higher 
      * than max_number_of_bytes_per_request are treated as if multiple single 
      * requests of max_number_of_bytes_per_request size had been made.
      * In theory SP 800-90A requires that we reject any request for a DRBG
      * output longer than max_number_of_bytes_per_request. To avoid inconveniencing
      * the caller who wants an output larger than max_number_of_bytes_per_request, 
      * instead treat these requests as if multiple requests of 
      * max_number_of_bytes_per_request size had been made. NIST requires for 
      * HMAC_DRBG that every implementation set a value no more than 2**19 bits 
      * (or 64 KiB). Together with @p reseed_interval = 1 you can enforce that for 
      * example every 512 bit automatic reseeding occurs.
      */
      HMAC_DRBG(std::unique_ptr<MessageAuthenticationCode> prf,
                Entropy_Sources& entropy_sources,
                size_t reseed_interval = BOTAN_RNG_DEFAULT_RESEED_INTERVAL,
                size_t max_number_of_bytes_per_request = 64 * 1024);

      /**
      * Initialize an HMAC_DRBG instance with the given MAC as PRF (normally HMAC)
      *
      * Automatic reseeding from @p underlying_rng and @p entropy_sources
      * will take place after @p reseed_interval many requests or after
      * a fork was detected.
      *
      * @param prf MAC to use as a PRF
      * @param underlying_rng is a reference to some RNG which will be used
      * to perform the periodic reseeding
      * @param entropy_sources will be polled to perform reseeding periodically
      * @param reseed_interval specifies a limit of how many times
      * the RNG will be called before automatic reseeding is performed.
      * @param max_number_of_bytes_per_request requests that are in size higher 
      * than max_number_of_bytes_per_request are treated as if multiple single 
      * requests of max_number_of_bytes_per_request size had been made.
      * In theory SP 800-90A requires that we reject any request for a DRBG
      * output longer than max_number_of_bytes_per_request. To avoid inconveniencing
      * the caller who wants an output larger than max_number_of_bytes_per_request, 
      * instead treat these requests as if multiple requests of 
      * max_number_of_bytes_per_request size had been made. NIST requires for 
      * HMAC_DRBG that every implementation set a value no more than 2**19 bits 
      * (or 64 KiB). Together with @p reseed_interval = 1 you can enforce that for 
      * example every 512 bit automatic reseeding occurs.
      */
      HMAC_DRBG(std::unique_ptr<MessageAuthenticationCode> prf,
                RandomNumberGenerator& underlying_rng,
                Entropy_Sources& entropy_sources,
                size_t reseed_interval = BOTAN_RNG_DEFAULT_RESEED_INTERVAL,
                size_t max_number_of_bytes_per_request = 64 * 1024);

      /**
      * Constructor taking a string for the hash
      */
      explicit HMAC_DRBG(const std::string& hmac_hash) :
         Stateful_RNG(),
         m_mac(MessageAuthenticationCode::create_or_throw("HMAC(" + hmac_hash + ")")),
         m_max_number_of_bytes_per_request(64 * 1024)
         {
         clear();
         }

      std::string name() const override;

      void clear() override;

      void randomize(uint8_t output[], size_t output_len) override;

      void randomize_with_input(uint8_t output[], size_t output_len,
                                const uint8_t input[], size_t input_len) override;

      void add_entropy(const uint8_t input[], size_t input_len) override;

      size_t security_level() const override;

      size_t max_number_of_bytes_per_request() const override
         { return m_max_number_of_bytes_per_request; }

   private:
      void update(const uint8_t input[], size_t input_len);

      std::unique_ptr<MessageAuthenticationCode> m_mac;
      secure_vector<uint8_t> m_V;
      const size_t m_max_number_of_bytes_per_request;
   };

}

namespace Botan {

/*
* Previously botan had state whose lifetime had to be explicitly
* managed by the application. As of 1.11.14 this is no longer the
* case, and this class is no longer needed and kept only for backwards
* compatibility.
*/
class BOTAN_PUBLIC_API(2,0) BOTAN_DEPRECATED("LibraryInitializer is no longer required") LibraryInitializer final
   {
   public:
      explicit LibraryInitializer(const std::string& /*ignored*/ = "") { }

      static void initialize(const std::string& /*ignored*/ = "") {}
      static void deinitialize() {}
   };

}

namespace Botan {

/**
* Key Derivation Function
*/
class BOTAN_PUBLIC_API(2,0) KDF
   {
   public:
      virtual ~KDF() = default;

      /**
      * Create an instance based on a name
      * If provider is empty then best available is chosen.
      * @param algo_spec algorithm name
      * @param provider provider implementation to choose
      * @return a null pointer if the algo/provider combination cannot be found
      */
      static std::unique_ptr<KDF>
         create(const std::string& algo_spec,
                const std::string& provider = "");

      /**
      * Create an instance based on a name, or throw if the
      * algo/provider combination cannot be found. If provider is
      * empty then best available is chosen.
      */
      static std::unique_ptr<KDF>
         create_or_throw(const std::string& algo_spec,
                         const std::string& provider = "");

      /**
      * @return list of available providers for this algorithm, empty if not available
      */
      static std::vector<std::string> providers(const std::string& algo_spec);

      /**
      * @return KDF name
      */
      virtual std::string name() const = 0;

      /**
      * Derive a key
      * @param key buffer holding the derived key, must be of length key_len
      * @param key_len the desired output length in bytes
      * @param secret the secret input
      * @param secret_len size of secret in bytes
      * @param salt a diversifier
      * @param salt_len size of salt in bytes
      * @param label purpose for the derived keying material
      * @param label_len size of label in bytes
      * @return the derived key
      */
      virtual size_t kdf(uint8_t key[], size_t key_len,
                         const uint8_t secret[], size_t secret_len,
                         const uint8_t salt[], size_t salt_len,
                         const uint8_t label[], size_t label_len) const = 0;

      /**
      * Derive a key
      * @param key_len the desired output length in bytes
      * @param secret the secret input
      * @param secret_len size of secret in bytes
      * @param salt a diversifier
      * @param salt_len size of salt in bytes
      * @param label purpose for the derived keying material
      * @param label_len size of label in bytes
      * @return the derived key
      */
      secure_vector<uint8_t> derive_key(size_t key_len,
                                    const uint8_t secret[],
                                    size_t secret_len,
                                    const uint8_t salt[],
                                    size_t salt_len,
                                    const uint8_t label[] = nullptr,
                                    size_t label_len = 0) const
         {
         secure_vector<uint8_t> key(key_len);
         key.resize(kdf(key.data(), key.size(), secret, secret_len, salt, salt_len, label, label_len));
         return key;
         }

      /**
      * Derive a key
      * @param key_len the desired output length in bytes
      * @param secret the secret input
      * @param salt a diversifier
      * @param label purpose for the derived keying material
      * @return the derived key
      */
      secure_vector<uint8_t> derive_key(size_t key_len,
                                    const secure_vector<uint8_t>& secret,
                                    const std::string& salt = "",
                                    const std::string& label = "") const
         {
         return derive_key(key_len, secret.data(), secret.size(),
                           cast_char_ptr_to_uint8(salt.data()),
                           salt.length(),
                           cast_char_ptr_to_uint8(label.data()),
                           label.length());

         }

      /**
      * Derive a key
      * @param key_len the desired output length in bytes
      * @param secret the secret input
      * @param salt a diversifier
      * @param label purpose for the derived keying material
      * @return the derived key
      */
      template<typename Alloc, typename Alloc2, typename Alloc3>
      secure_vector<uint8_t> derive_key(size_t key_len,
                                     const std::vector<uint8_t, Alloc>& secret,
                                     const std::vector<uint8_t, Alloc2>& salt,
                                     const std::vector<uint8_t, Alloc3>& label) const
         {
         return derive_key(key_len,
                           secret.data(), secret.size(),
                           salt.data(), salt.size(),
                           label.data(), label.size());
         }

      /**
      * Derive a key
      * @param key_len the desired output length in bytes
      * @param secret the secret input
      * @param salt a diversifier
      * @param salt_len size of salt in bytes
      * @param label purpose for the derived keying material
      * @return the derived key
      */
      secure_vector<uint8_t> derive_key(size_t key_len,
                                    const secure_vector<uint8_t>& secret,
                                    const uint8_t salt[],
                                    size_t salt_len,
                                    const std::string& label = "") const
         {
         return derive_key(key_len,
                           secret.data(), secret.size(),
                           salt, salt_len,
                           cast_char_ptr_to_uint8(label.data()),
                           label.size());
         }

      /**
      * Derive a key
      * @param key_len the desired output length in bytes
      * @param secret the secret input
      * @param secret_len size of secret in bytes
      * @param salt a diversifier
      * @param label purpose for the derived keying material
      * @return the derived key
      */
      secure_vector<uint8_t> derive_key(size_t key_len,
                                    const uint8_t secret[],
                                    size_t secret_len,
                                    const std::string& salt = "",
                                    const std::string& label = "") const
         {
         return derive_key(key_len, secret, secret_len,
                           cast_char_ptr_to_uint8(salt.data()),
                           salt.length(),
                           cast_char_ptr_to_uint8(label.data()),
                           label.length());
         }

      /**
      * @return new object representing the same algorithm as *this
      */
      virtual KDF* clone() const = 0;
   };

/**
* Factory method for KDF (key derivation function)
* @param algo_spec the name of the KDF to create
* @return pointer to newly allocated object of that type
*/
BOTAN_PUBLIC_API(2,0) KDF* get_kdf(const std::string& algo_spec);

}
namespace Botan {

namespace PK_Ops {

class Encryption;
class Decryption;
class Verification;
class Signature;
class Key_Agreement;
class KEM_Encryption;
class KEM_Decryption;

}

}

namespace Botan {

class RandomNumberGenerator;

/**
* Public Key Base Class.
*/
class BOTAN_PUBLIC_API(2,0) Public_Key
   {
   public:
      Public_Key() =default;
      Public_Key(const Public_Key& other) = default;
      Public_Key& operator=(const Public_Key& other) = default;
      virtual ~Public_Key() = default;

      /**
      * Get the name of the underlying public key scheme.
      * @return name of the public key scheme
      */
      virtual std::string algo_name() const = 0;

      /**
      * Return the estimated strength of the underlying key against
      * the best currently known attack. Note that this ignores anything
      * but pure attacks against the key itself and do not take into
      * account padding schemes, usage mistakes, etc which might reduce
      * the strength. However it does suffice to provide an upper bound.
      *
      * @return estimated strength in bits
      */
      virtual size_t estimated_strength() const = 0;

      /**
      * Return an integer value best approximating the length of the
      * primary security parameter. For example for RSA this will be
      * the size of the modulus, for ECDSA the size of the ECC group,
      * and for McEliece the size of the code will be returned.
      */
      virtual size_t key_length() const = 0;

      /**
      * Get the OID of the underlying public key scheme.
      * @return OID of the public key scheme
      */
      virtual OID get_oid() const;

      /**
      * Test the key values for consistency.
      * @param rng rng to use
      * @param strong whether to perform strong and lengthy version
      * of the test
      * @return true if the test is passed
      */
      virtual bool check_key(RandomNumberGenerator& rng,
                             bool strong) const = 0;


      /**
      * @return X.509 AlgorithmIdentifier for this key
      */
      virtual AlgorithmIdentifier algorithm_identifier() const = 0;

      /**
      * @return BER encoded public key bits
      */
      virtual std::vector<uint8_t> public_key_bits() const = 0;

      /**
      * @return X.509 subject key encoding for this key object
      */
      std::vector<uint8_t> subject_public_key() const;

      /**
       * @return Hash of the subject public key
       */
      std::string fingerprint_public(const std::string& alg = "SHA-256") const;

      // Internal or non-public declarations follow

      /**
      * Returns more than 1 if the output of this algorithm
      * (ciphertext, signature) should be treated as more than one
      * value. This is used for algorithms like DSA and ECDSA, where
      * the (r,s) output pair can be encoded as either a plain binary
      * list or a TLV tagged DER encoding depending on the protocol.
      *
      * This function is public but applications should have few
      * reasons to ever call this.
      *
      * @return number of message parts
      */
      virtual size_t message_parts() const { return 1; }

      /**
      * Returns how large each of the message parts refered to
      * by message_parts() is
      *
      * This function is public but applications should have few
      * reasons to ever call this.
      *
      * @return size of the message parts in bits
      */
      virtual size_t message_part_size() const { return 0; }

      /**
      * This is an internal library function exposed on key types.
      * In almost all cases applications should use wrappers in pubkey.h
      *
      * Return an encryption operation for this key/params or throw
      *
      * @param rng a random number generator. The PK_Op may maintain a
      * reference to the RNG and use it many times. The rng must outlive
      * any operations which reference it.
      * @param params additional parameters
      * @param provider the provider to use
      */
      virtual std::unique_ptr<PK_Ops::Encryption>
         create_encryption_op(RandomNumberGenerator& rng,
                              const std::string& params,
                              const std::string& provider) const;

      /**
      * This is an internal library function exposed on key types.
      * In almost all cases applications should use wrappers in pubkey.h
      *
      * Return a KEM encryption operation for this key/params or throw
      *
      * @param rng a random number generator. The PK_Op may maintain a
      * reference to the RNG and use it many times. The rng must outlive
      * any operations which reference it.
      * @param params additional parameters
      * @param provider the provider to use
      */
      virtual std::unique_ptr<PK_Ops::KEM_Encryption>
         create_kem_encryption_op(RandomNumberGenerator& rng,
                                  const std::string& params,
                                  const std::string& provider) const;

      /**
      * This is an internal library function exposed on key types.
      * In almost all cases applications should use wrappers in pubkey.h
      *
      * Return a verification operation for this key/params or throw
      * @param params additional parameters
      * @param provider the provider to use
      */
      virtual std::unique_ptr<PK_Ops::Verification>
         create_verification_op(const std::string& params,
                                const std::string& provider) const;
   };

/**
* Private Key Base Class
*/
class BOTAN_PUBLIC_API(2,0) Private_Key : public virtual Public_Key
   {
   public:
      Private_Key() = default;
      Private_Key(const Private_Key& other) = default;
      Private_Key& operator=(const Private_Key& other) = default;
      virtual ~Private_Key() = default;

      /**
      * @return BER encoded private key bits
      */
      virtual secure_vector<uint8_t> private_key_bits() const = 0;

      /**
      * @return PKCS #8 private key encoding for this key object
      */
      secure_vector<uint8_t> private_key_info() const;

      /**
      * @return PKCS #8 AlgorithmIdentifier for this key
      * Might be different from the X.509 identifier, but normally is not
      */
      virtual AlgorithmIdentifier pkcs8_algorithm_identifier() const
         { return algorithm_identifier(); }

      // Internal or non-public declarations follow

      /**
       * @return Hash of the PKCS #8 encoding for this key object
       */
      std::string fingerprint_private(const std::string& alg) const;

      BOTAN_DEPRECATED("Use fingerprint_private or fingerprint_public")
         inline std::string fingerprint(const std::string& alg) const
         {
         return fingerprint_private(alg); // match behavior in previous versions
         }

      /**
      * This is an internal library function exposed on key types.
      * In almost all cases applications should use wrappers in pubkey.h
      *
      * Return an decryption operation for this key/params or throw
      *
      * @param rng a random number generator. The PK_Op may maintain a
      * reference to the RNG and use it many times. The rng must outlive
      * any operations which reference it.
      * @param params additional parameters
      * @param provider the provider to use
      *
      */
      virtual std::unique_ptr<PK_Ops::Decryption>
         create_decryption_op(RandomNumberGenerator& rng,
                              const std::string& params,
                              const std::string& provider) const;

      /**
      * This is an internal library function exposed on key types.
      * In almost all cases applications should use wrappers in pubkey.h
      *
      * Return a KEM decryption operation for this key/params or throw
      *
      * @param rng a random number generator. The PK_Op may maintain a
      * reference to the RNG and use it many times. The rng must outlive
      * any operations which reference it.
      * @param params additional parameters
      * @param provider the provider to use
      */
      virtual std::unique_ptr<PK_Ops::KEM_Decryption>
         create_kem_decryption_op(RandomNumberGenerator& rng,
                                  const std::string& params,
                                  const std::string& provider) const;

      /**
      * This is an internal library function exposed on key types.
      * In almost all cases applications should use wrappers in pubkey.h
      *
      * Return a signature operation for this key/params or throw
      *
      * @param rng a random number generator. The PK_Op may maintain a
      * reference to the RNG and use it many times. The rng must outlive
      * any operations which reference it.
      * @param params additional parameters
      * @param provider the provider to use
      */
      virtual std::unique_ptr<PK_Ops::Signature>
         create_signature_op(RandomNumberGenerator& rng,
                             const std::string& params,
                             const std::string& provider) const;

      /**
      * This is an internal library function exposed on key types.
      * In almost all cases applications should use wrappers in pubkey.h
      *
      * Return a key agreement operation for this key/params or throw
      *
      * @param rng a random number generator. The PK_Op may maintain a
      * reference to the RNG and use it many times. The rng must outlive
      * any operations which reference it.
      * @param params additional parameters
      * @param provider the provider to use
      */
      virtual std::unique_ptr<PK_Ops::Key_Agreement>
         create_key_agreement_op(RandomNumberGenerator& rng,
                                 const std::string& params,
                                 const std::string& provider) const;
   };

/**
* PK Secret Value Derivation Key
*/
class BOTAN_PUBLIC_API(2,0) PK_Key_Agreement_Key : public virtual Private_Key
   {
   public:
      /*
      * @return public component of this key
      */
      virtual std::vector<uint8_t> public_value() const = 0;

      PK_Key_Agreement_Key() = default;
      PK_Key_Agreement_Key(const PK_Key_Agreement_Key&) = default;
      PK_Key_Agreement_Key& operator=(const PK_Key_Agreement_Key&) = default;
      virtual ~PK_Key_Agreement_Key() = default;
   };

/*
* Old compat typedefs
* TODO: remove these?
*/
typedef PK_Key_Agreement_Key PK_KA_Key;
typedef Public_Key X509_PublicKey;
typedef Private_Key PKCS8_PrivateKey;

std::string BOTAN_PUBLIC_API(2,4)
   create_hex_fingerprint(const uint8_t bits[], size_t len,
                          const std::string& hash_name);

template<typename Alloc>
std::string create_hex_fingerprint(const std::vector<uint8_t, Alloc>& vec,
                                   const std::string& hash_name)
   {
   return create_hex_fingerprint(vec.data(), vec.size(), hash_name);
   }


}

namespace Botan {

namespace KeyPair {

/**
* Tests whether the key is consistent for encryption; whether
* encrypting and then decrypting gives to the original plaintext.
* @param rng the rng to use
* @param private_key the key to test
* @param public_key the key to test
* @param padding the encryption padding method to use
* @return true if consistent otherwise false
*/
BOTAN_PUBLIC_API(2,0) bool
encryption_consistency_check(RandomNumberGenerator& rng,
                             const Private_Key& private_key,
                             const Public_Key& public_key,
                             const std::string& padding);

/**
* Tests whether the key is consistent for signatures; whether a
* signature can be created and then verified
* @param rng the rng to use
* @param private_key the key to test
* @param public_key the key to test
* @param padding the signature padding method to use
* @return true if consistent otherwise false
*/
BOTAN_PUBLIC_API(2,0) bool
signature_consistency_check(RandomNumberGenerator& rng,
                            const Private_Key& private_key,
                            const Public_Key& public_key,
                            const std::string& padding);

/**
* Tests whether the key is consistent for encryption; whether
* encrypting and then decrypting gives to the original plaintext.
* @param rng the rng to use
* @param key the key to test
* @param padding the encryption padding method to use
* @return true if consistent otherwise false
*/
inline bool
encryption_consistency_check(RandomNumberGenerator& rng,
                             const Private_Key& key,
                             const std::string& padding)
   {
   return encryption_consistency_check(rng, key, key, padding);
   }

/**
* Tests whether the key is consistent for signatures; whether a
* signature can be created and then verified
* @param rng the rng to use
* @param key the key to test
* @param padding the signature padding method to use
* @return true if consistent otherwise false
*/
inline bool
signature_consistency_check(RandomNumberGenerator& rng,
                            const Private_Key& key,
                            const std::string& padding)
   {
   return signature_consistency_check(rng, key, key, padding);
   }

}

}

#if defined(BOTAN_HAS_BLOCK_CIPHER)
#endif

#if defined(BOTAN_HAS_STREAM_CIPHER)
#endif

#if defined(BOTAN_HAS_HASH)
#endif

#if defined(BOTAN_HAS_MAC)
#endif

namespace Botan {

/*
* As of 1.11.26 this header is deprecated. Instead use the calls T::create and
* T::providers (as demonstrated in the implementation below).
*/

/*
* Get an algorithm object
*  NOTE: these functions create and return new objects, letting the
* caller assume ownership of them
*/

#if defined(BOTAN_HAS_BLOCK_CIPHER)

/**
* Block cipher factory method.
*
* @param algo_spec the name of the desired block cipher
* @param provider the provider to use
* @return pointer to the block cipher object
*/
BOTAN_DEPRECATED("Use BlockCipher::create")
inline BlockCipher* get_block_cipher(const std::string& algo_spec,
                                     const std::string& provider = "")
   {
   return BlockCipher::create(algo_spec, provider).release();
   }

BOTAN_DEPRECATED("Use BlockCipher::create_or_throw")
inline std::unique_ptr<BlockCipher> make_block_cipher(const std::string& algo_spec,
                                                      const std::string& provider = "")
   {
   return BlockCipher::create_or_throw(algo_spec, provider);
   }

BOTAN_DEPRECATED("Use BlockCipher::providers")
inline std::vector<std::string> get_block_cipher_providers(const std::string& algo_spec)
   {
   return BlockCipher::providers(algo_spec);
   }

#endif

#if defined(BOTAN_HAS_STREAM_CIPHER)

/**
* Stream cipher factory method.
*
* @param algo_spec the name of the desired stream cipher
* @param provider the provider to use
* @return pointer to the stream cipher object
*/
BOTAN_DEPRECATED("Use StreamCipher::create")
inline StreamCipher* get_stream_cipher(const std::string& algo_spec,
                                       const std::string& provider = "")
   {
   return StreamCipher::create(algo_spec, provider).release();
   }

BOTAN_DEPRECATED("Use StreamCipher::create_or_throw")
inline std::unique_ptr<StreamCipher> make_stream_cipher(const std::string& algo_spec,
                                                        const std::string& provider = "")
   {
   return StreamCipher::create_or_throw(algo_spec, provider);
   }

BOTAN_DEPRECATED("Use StreamCipher::providers")
inline std::vector<std::string> get_stream_cipher_providers(const std::string& algo_spec)
   {
   return StreamCipher::providers(algo_spec);
   }

#endif

#if defined(BOTAN_HAS_HASH)

/**
* Hash function factory method.
*
* @param algo_spec the name of the desired hash function
* @param provider the provider to use
* @return pointer to the hash function object
*/
BOTAN_DEPRECATED("Use HashFunction::create")
inline HashFunction* get_hash_function(const std::string& algo_spec,
                                       const std::string& provider = "")
   {
   return HashFunction::create(algo_spec, provider).release();
   }

BOTAN_DEPRECATED("Use HashFunction::create_or_throw")
inline std::unique_ptr<HashFunction> make_hash_function(const std::string& algo_spec,
                                                        const std::string& provider = "")
   {
   return HashFunction::create_or_throw(algo_spec, provider);
   }

BOTAN_DEPRECATED("Use HashFunction::create")
inline HashFunction* get_hash(const std::string& algo_spec,
                              const std::string& provider = "")
   {
   return HashFunction::create(algo_spec, provider).release();
   }

BOTAN_DEPRECATED("Use HashFunction::providers")
inline std::vector<std::string> get_hash_function_providers(const std::string& algo_spec)
   {
   return HashFunction::providers(algo_spec);
   }

#endif

#if defined(BOTAN_HAS_MAC)
/**
* MAC factory method.
*
* @param algo_spec the name of the desired MAC
* @param provider the provider to use
* @return pointer to the MAC object
*/
BOTAN_DEPRECATED("MessageAuthenticationCode::create")
inline MessageAuthenticationCode* get_mac(const std::string& algo_spec,
                                             const std::string& provider = "")
   {
   return MessageAuthenticationCode::create(algo_spec, provider).release();
   }

BOTAN_DEPRECATED("MessageAuthenticationCode::create_or_throw")
inline std::unique_ptr<MessageAuthenticationCode> make_message_auth(const std::string& algo_spec,
                                                                       const std::string& provider = "")
   {
   return MessageAuthenticationCode::create(algo_spec, provider);
   }

BOTAN_DEPRECATED("MessageAuthenticationCode::providers")
inline std::vector<std::string> get_mac_providers(const std::string& algo_spec)
   {
   return MessageAuthenticationCode::providers(algo_spec);
   }
#endif

}

namespace Botan {

/**
* MDx Hash Function Base Class
*/
class BOTAN_PUBLIC_API(2,0) MDx_HashFunction : public HashFunction
   {
   public:
      /**
      * @param block_length is the number of bytes per block
      * @param big_byte_endian specifies if the hash uses big-endian bytes
      * @param big_bit_endian specifies if the hash uses big-endian bits
      * @param counter_size specifies the size of the counter var in bytes
      */
      MDx_HashFunction(size_t block_length,
                       bool big_byte_endian,
                       bool big_bit_endian,
                       size_t counter_size = 8);

      size_t hash_block_size() const override final { return m_buffer.size(); }
   protected:
      void add_data(const uint8_t input[], size_t length) override final;
      void final_result(uint8_t output[]) override final;

      /**
      * Run the hash's compression function over a set of blocks
      * @param blocks the input
      * @param block_n the number of blocks
      */
      virtual void compress_n(const uint8_t blocks[], size_t block_n) = 0;

      void clear() override;

      /**
      * Copy the output to the buffer
      * @param buffer to put the output into
      */
      virtual void copy_out(uint8_t buffer[]) = 0;

      /**
      * Write the count, if used, to this spot
      * @param out where to write the counter to
      */
      virtual void write_count(uint8_t out[]);
   private:
      secure_vector<uint8_t> m_buffer;
      uint64_t m_count;
      size_t m_position;

      const bool BIG_BYTE_ENDIAN, BIG_BIT_ENDIAN;
      const size_t COUNT_SIZE;
   };

}

namespace Botan {

/**
* MD5
*/
class BOTAN_PUBLIC_API(2,0) MD5 final : public MDx_HashFunction
   {
   public:
      std::string name() const override { return "MD5"; }
      size_t output_length() const override { return 16; }
      HashFunction* clone() const override { return new MD5; }
      std::unique_ptr<HashFunction> copy_state() const override;

      void clear() override;

      MD5() : MDx_HashFunction(64, false, true), m_M(16), m_digest(4)
         { clear(); }

   private:
      void compress_n(const uint8_t[], size_t blocks) override;
      void copy_out(uint8_t[]) override;

      /**
      * The message buffer
      */
      secure_vector<uint32_t> m_M;

      /**
      * The digest value
      */
      secure_vector<uint32_t> m_digest;
   };

}

namespace Botan {

class HashFunction;

/**
* MGF1 from PKCS #1 v2.0
* @param hash hash function to use
* @param in input buffer
* @param in_len size of the input buffer in bytes
* @param out output buffer
* @param out_len size of the output buffer in bytes
*/
void BOTAN_PUBLIC_API(2,0) mgf1_mask(HashFunction& hash,
                         const uint8_t in[], size_t in_len,
                         uint8_t out[], size_t out_len);

}

namespace Botan {

class Modular_Reducer;

class Montgomery_Params;

/**
* The Montgomery representation of an integer
*/
class BOTAN_UNSTABLE_API Montgomery_Int final
   {
   public:
      /**
      * Create a zero-initialized Montgomery_Int
      */
      Montgomery_Int(std::shared_ptr<const Montgomery_Params> params) : m_params(params) {}

      /**
      * Create a Montgomery_Int
      */
      Montgomery_Int(std::shared_ptr<const Montgomery_Params> params,
                     const BigInt& v,
                     bool redc_needed = true);

      /**
      * Create a Montgomery_Int
      */
      Montgomery_Int(std::shared_ptr<const Montgomery_Params> params,
                     const uint8_t bits[], size_t len,
                     bool redc_needed = true);

      /**
      * Create a Montgomery_Int
      */
      Montgomery_Int(std::shared_ptr<const Montgomery_Params> params,
                     const word words[], size_t len,
                     bool redc_needed = true);

      bool operator==(const Montgomery_Int& other) const;
      bool operator!=(const Montgomery_Int& other) const { return (m_v != other.m_v); }

      std::vector<uint8_t> serialize() const;

      size_t size() const;
      bool is_one() const;
      bool is_zero() const;

      void fix_size();

      /**
      * Return the value to normal mod-p space
      */
      BigInt value() const;

      /**
      * Return the Montgomery representation
      */
      const BigInt& repr() const { return m_v; }

      Montgomery_Int operator+(const Montgomery_Int& other) const;

      Montgomery_Int operator-(const Montgomery_Int& other) const;

      Montgomery_Int& operator+=(const Montgomery_Int& other);

      Montgomery_Int& operator-=(const Montgomery_Int& other);

      Montgomery_Int operator*(const Montgomery_Int& other) const;

      Montgomery_Int& operator*=(const Montgomery_Int& other);

      Montgomery_Int& operator*=(const secure_vector<word>& other);

      Montgomery_Int& add(const Montgomery_Int& other,
                          secure_vector<word>& ws);

      Montgomery_Int& sub(const Montgomery_Int& other,
                          secure_vector<word>& ws);

      Montgomery_Int mul(const Montgomery_Int& other,
                         secure_vector<word>& ws) const;

      Montgomery_Int& mul_by(const Montgomery_Int& other,
                             secure_vector<word>& ws);

      Montgomery_Int& mul_by(const secure_vector<word>& other,
                             secure_vector<word>& ws);

      Montgomery_Int square(secure_vector<word>& ws) const;

      Montgomery_Int& square_this(secure_vector<word>& ws);

      Montgomery_Int& square_this_n_times(secure_vector<word>& ws, size_t n);

      Montgomery_Int multiplicative_inverse() const;

      Montgomery_Int additive_inverse() const;

      Montgomery_Int& mul_by_2(secure_vector<word>& ws);

      Montgomery_Int& mul_by_3(secure_vector<word>& ws);

      Montgomery_Int& mul_by_4(secure_vector<word>& ws);

      Montgomery_Int& mul_by_8(secure_vector<word>& ws);

      void const_time_poison() const { m_v.const_time_poison(); }
      void const_time_unpoison() const { return m_v.const_time_unpoison(); }

   private:
      std::shared_ptr<const Montgomery_Params> m_params;
      BigInt m_v;
   };

/**
* Parameters for Montgomery Reduction
*/
class BOTAN_UNSTABLE_API Montgomery_Params final
   {
   public:
      /**
      * Initialize a set of Montgomery reduction parameters. These values
      * can be shared by all values in a specific Montgomery domain.
      */
      Montgomery_Params(const BigInt& p, const Modular_Reducer& mod_p);

      /**
      * Initialize a set of Montgomery reduction parameters. These values
      * can be shared by all values in a specific Montgomery domain.
      */
      Montgomery_Params(const BigInt& p);

      const BigInt& p() const { return m_p; }
      const BigInt& R1() const { return m_r1; }
      const BigInt& R2() const { return m_r2; }
      const BigInt& R3() const { return m_r3; }

      word p_dash() const { return m_p_dash; }

      size_t p_words() const { return m_p_words; }

      BigInt redc(const BigInt& x,
                  secure_vector<word>& ws) const;

      BigInt mul(const BigInt& x,
                 const BigInt& y,
                 secure_vector<word>& ws) const;

      BigInt mul(const BigInt& x,
                 const secure_vector<word>& y,
                 secure_vector<word>& ws) const;

      void mul_by(BigInt& x,
                  const secure_vector<word>& y,
                  secure_vector<word>& ws) const;

      void mul_by(BigInt& x, const BigInt& y,
                  secure_vector<word>& ws) const;

      BigInt sqr(const BigInt& x,
                 secure_vector<word>& ws) const;

      void square_this(BigInt& x,
                       secure_vector<word>& ws) const;

      BigInt inv_mod_p(const BigInt& x) const;

   private:
      BigInt m_p;
      BigInt m_r1;
      BigInt m_r2;
      BigInt m_r3;
      word m_p_dash;
      size_t m_p_words;
   };

}

namespace Botan {

#if defined(__SIZEOF_INT128__) && defined(BOTAN_TARGET_CPU_HAS_NATIVE_64BIT) && !defined(__xlc__)
   #define BOTAN_TARGET_HAS_NATIVE_UINT128

   // Prefer TI mode over __int128 as GCC rejects the latter in pendantic mode
   #if defined(__GNUG__)
     typedef unsigned int uint128_t __attribute__((mode(TI)));
   #else
     typedef unsigned __int128 uint128_t;
   #endif
#endif

}

#if defined(BOTAN_TARGET_HAS_NATIVE_UINT128)

#define BOTAN_FAST_64X64_MUL(a,b,lo,hi)      \
   do {                                      \
      const uint128_t r = static_cast<uint128_t>(a) * b;   \
      *hi = (r >> 64) & 0xFFFFFFFFFFFFFFFF;  \
      *lo = (r      ) & 0xFFFFFFFFFFFFFFFF;  \
   } while(0)

#elif defined(BOTAN_BUILD_COMPILER_IS_MSVC) && defined(BOTAN_TARGET_CPU_HAS_NATIVE_64BIT)

#include <intrin.h>
#pragma intrinsic(_umul128)

#define BOTAN_FAST_64X64_MUL(a,b,lo,hi) \
   do { *lo = _umul128(a, b, hi); } while(0)

#elif defined(BOTAN_USE_GCC_INLINE_ASM)

#if defined(BOTAN_TARGET_ARCH_IS_X86_64)

#define BOTAN_FAST_64X64_MUL(a,b,lo,hi) do {                           \
   asm("mulq %3" : "=d" (*hi), "=a" (*lo) : "a" (a), "rm" (b) : "cc"); \
   } while(0)

#elif defined(BOTAN_TARGET_ARCH_IS_ALPHA)

#define BOTAN_FAST_64X64_MUL(a,b,lo,hi) do {              \
   asm("umulh %1,%2,%0" : "=r" (*hi) : "r" (a), "r" (b)); \
   *lo = a * b;                                           \
} while(0)

#elif defined(BOTAN_TARGET_ARCH_IS_IA64)

#define BOTAN_FAST_64X64_MUL(a,b,lo,hi) do {                \
   asm("xmpy.hu %0=%1,%2" : "=f" (*hi) : "f" (a), "f" (b)); \
   *lo = a * b;                                             \
} while(0)

#elif defined(BOTAN_TARGET_ARCH_IS_PPC64)

#define BOTAN_FAST_64X64_MUL(a,b,lo,hi) do {                      \
   asm("mulhdu %0,%1,%2" : "=r" (*hi) : "r" (a), "r" (b) : "cc"); \
   *lo = a * b;                                                   \
} while(0)

#endif

#endif

namespace Botan {

/**
* Perform a 64x64->128 bit multiplication
*/
inline void mul64x64_128(uint64_t a, uint64_t b, uint64_t* lo, uint64_t* hi)
   {
#if defined(BOTAN_FAST_64X64_MUL)
   BOTAN_FAST_64X64_MUL(a, b, lo, hi);
#else

   /*
   * Do a 64x64->128 multiply using four 32x32->64 multiplies plus
   * some adds and shifts. Last resort for CPUs like UltraSPARC (with
   * 64-bit registers/ALU, but no 64x64->128 multiply) or 32-bit CPUs.
   */
   const size_t HWORD_BITS = 32;
   const uint32_t HWORD_MASK = 0xFFFFFFFF;

   const uint32_t a_hi = (a >> HWORD_BITS);
   const uint32_t a_lo = (a  & HWORD_MASK);
   const uint32_t b_hi = (b >> HWORD_BITS);
   const uint32_t b_lo = (b  & HWORD_MASK);

   uint64_t x0 = static_cast<uint64_t>(a_hi) * b_hi;
   uint64_t x1 = static_cast<uint64_t>(a_lo) * b_hi;
   uint64_t x2 = static_cast<uint64_t>(a_hi) * b_lo;
   uint64_t x3 = static_cast<uint64_t>(a_lo) * b_lo;

   // this cannot overflow as (2^32-1)^2 + 2^32-1 < 2^64-1
   x2 += x3 >> HWORD_BITS;

   // this one can overflow
   x2 += x1;

   // propagate the carry if any
   x0 += static_cast<uint64_t>(static_cast<bool>(x2 < x1)) << HWORD_BITS;

   *hi = x0 + (x2 >> HWORD_BITS);
   *lo  = ((x2 & HWORD_MASK) << HWORD_BITS) + (x3 & HWORD_MASK);
#endif
   }

}

namespace Botan {

/**
* OAEP (called EME1 in IEEE 1363 and in earlier versions of the library)
* as specified in PKCS#1 v2.0 (RFC 2437)
*/
class BOTAN_PUBLIC_API(2,0) OAEP final : public EME
   {
   public:
      size_t maximum_input_size(size_t) const override;

      /**
      * @param hash function to use for hashing (takes ownership)
      * @param P an optional label. Normally empty.
      */
      OAEP(HashFunction* hash, const std::string& P = "");

      /**
      * @param hash function to use for hashing (takes ownership)
      * @param mgf1_hash function to use for MGF1 (takes ownership)
      * @param P an optional label. Normally empty.
      */
      OAEP(HashFunction* hash,
           HashFunction* mgf1_hash,
           const std::string& P = "");
   private:
      secure_vector<uint8_t> pad(const uint8_t in[],
                              size_t in_length,
                              size_t key_length,
                              RandomNumberGenerator& rng) const override;

      secure_vector<uint8_t> unpad(uint8_t& valid_mask,
                                const uint8_t in[],
                                size_t in_len) const override;

      secure_vector<uint8_t> m_Phash;
      std::unique_ptr<HashFunction> m_mgf1_hash;
   };

secure_vector<uint8_t>
BOTAN_TEST_API oaep_find_delim(uint8_t& valid_mask,
                               const uint8_t input[], size_t input_len,
                               const secure_vector<uint8_t>& Phash);

}

namespace Botan {

namespace OIDS {

/**
* Register an OID to string mapping.
* @param oid the oid to register
* @param name the name to be associated with the oid
*/
BOTAN_UNSTABLE_API void add_oid(const OID& oid, const std::string& name);

BOTAN_UNSTABLE_API void add_oid2str(const OID& oid, const std::string& name);
BOTAN_UNSTABLE_API void add_str2oid(const OID& oid, const std::string& name);

BOTAN_UNSTABLE_API void add_oidstr(const char* oidstr, const char* name);

std::unordered_map<std::string, std::string> load_oid2str_map();
std::unordered_map<std::string, OID> load_str2oid_map();

/**
* Resolve an OID
* @param oid the OID to look up
* @return name associated with this OID
*/
BOTAN_PUBLIC_API(2,0) std::string lookup(const OID& oid);

/**
* Find the OID to a name. The lookup will be performed in the
* general OID section of the configuration.
* @param name the name to resolve
* @return OID associated with the specified name
*/
BOTAN_PUBLIC_API(2,0) OID lookup(const std::string& name);

inline std::string oid2str(const OID& oid)
   {
   return lookup(oid);
   }

inline OID str2oid(const std::string& name)
   {
   return lookup(name);
   }

/**
* See if an OID exists in the internal table.
* @param oid the oid to check for
* @return true if the oid is registered
*/
BOTAN_UNSTABLE_API bool have_oid(const std::string& oid);

/**
* Tests whether the specified OID stands for the specified name.
* @param oid the OID to check
* @param name the name to check
* @return true if the specified OID stands for the specified name
*/
BOTAN_UNSTABLE_API bool name_of(const OID& oid, const std::string& name);
}

}


namespace Botan {

/**
* Parse a SCAN-style algorithm name
* @param scan_name the name
* @return the name components
*/
BOTAN_PUBLIC_API(2,0) std::vector<std::string>
parse_algorithm_name(const std::string& scan_name);

/**
* Split a string
* @param str the input string
* @param delim the delimitor
* @return string split by delim
*/
BOTAN_PUBLIC_API(2,0) std::vector<std::string> split_on(
   const std::string& str, char delim);

/**
* Split a string on a character predicate
* @param str the input string
* @param pred the predicate
*
* This function will likely be removed in a future release
*/
BOTAN_PUBLIC_API(2,0) std::vector<std::string>
split_on_pred(const std::string& str,
              std::function<bool (char)> pred);

/**
* Erase characters from a string
*/
BOTAN_PUBLIC_API(2,0)
BOTAN_DEPRECATED("Unused")
std::string erase_chars(const std::string& str, const std::set<char>& chars);

/**
* Replace a character in a string
* @param str the input string
* @param from_char the character to replace
* @param to_char the character to replace it with
* @return str with all instances of from_char replaced by to_char
*/
BOTAN_PUBLIC_API(2,0)
BOTAN_DEPRECATED("Unused")
std::string replace_char(const std::string& str,
                         char from_char,
                         char to_char);

/**
* Replace a character in a string
* @param str the input string
* @param from_chars the characters to replace
* @param to_char the character to replace it with
* @return str with all instances of from_chars replaced by to_char
*/
BOTAN_PUBLIC_API(2,0)
BOTAN_DEPRECATED("Unused")
std::string replace_chars(const std::string& str,
                          const std::set<char>& from_chars,
                          char to_char);

/**
* Join a string
* @param strs strings to join
* @param delim the delimitor
* @return string joined by delim
*/
BOTAN_PUBLIC_API(2,0)
std::string string_join(const std::vector<std::string>& strs,
                        char delim);

/**
* Parse an ASN.1 OID
* @param oid the OID in string form
* @return OID components
*/
BOTAN_PUBLIC_API(2,0) std::vector<uint32_t> parse_asn1_oid(const std::string& oid);

/**
* Compare two names using the X.509 comparison algorithm
* @param name1 the first name
* @param name2 the second name
* @return true if name1 is the same as name2 by the X.509 comparison rules
*/
BOTAN_PUBLIC_API(2,0)
bool x500_name_cmp(const std::string& name1,
                   const std::string& name2);

/**
* Convert a string to a number
* @param str the string to convert
* @return number value of the string
*/
BOTAN_PUBLIC_API(2,0) uint32_t to_u32bit(const std::string& str);

/**
* Convert a string to a number
* @param str the string to convert
* @return number value of the string
*/
BOTAN_PUBLIC_API(2,3) uint16_t to_uint16(const std::string& str);

/**
* Convert a time specification to a number
* @param timespec the time specification
* @return number of seconds represented by timespec
*/
BOTAN_PUBLIC_API(2,0) uint32_t BOTAN_DEPRECATED("Not used anymore")
timespec_to_u32bit(const std::string& timespec);

/**
* Convert a string representation of an IPv4 address to a number
* @param ip_str the string representation
* @return integer IPv4 address
*/
BOTAN_PUBLIC_API(2,0) uint32_t string_to_ipv4(const std::string& ip_str);

/**
* Convert an IPv4 address to a string
* @param ip_addr the IPv4 address to convert
* @return string representation of the IPv4 address
*/
BOTAN_PUBLIC_API(2,0) std::string ipv4_to_string(uint32_t ip_addr);

std::map<std::string, std::string> BOTAN_PUBLIC_API(2,0) read_cfg(std::istream& is);

/**
* Accepts key value pairs deliminated by commas:
*
* "" (returns empty map)
* "K=V" (returns map {'K': 'V'})
* "K1=V1,K2=V2"
* "K1=V1,K2=V2,K3=V3"
* "K1=V1,K2=V2,K3=a_value\,with\,commas_and_\=equals"
*
* Values may be empty, keys must be non-empty and unique. Duplicate
* keys cause an exception.
*
* Within both key and value, comma and equals can be escaped with
* backslash. Backslash can also be escaped.
*/
std::map<std::string, std::string> BOTAN_PUBLIC_API(2,8) read_kv(const std::string& kv);

std::string BOTAN_PUBLIC_API(2,0) clean_ws(const std::string& s);

/**
* Check if the given hostname is a match for the specified wildcard
*/
bool BOTAN_PUBLIC_API(2,0) host_wildcard_match(const std::string& wildcard,
                                               const std::string& host);


}

namespace Botan {

class DataSource;

namespace PEM_Code {

/**
* Encode some binary data in PEM format
* @param data binary data to encode
* @param data_len length of binary data in bytes
* @param label PEM label put after BEGIN and END
* @param line_width after this many characters, a new line is inserted
*/
BOTAN_PUBLIC_API(2,0) std::string encode(const uint8_t data[],
                                         size_t data_len,
                                         const std::string& label,
                                         size_t line_width = 64);

/**
* Encode some binary data in PEM format
* @param data binary data to encode
* @param label PEM label
* @param line_width after this many characters, a new line is inserted
*/
template<typename Alloc>
std::string encode(const std::vector<uint8_t, Alloc>& data,
                   const std::string& label,
                   size_t line_width = 64)
   {
   return encode(data.data(), data.size(), label, line_width);
   }

/**
* Decode PEM data
* @param pem a datasource containing PEM encoded data
* @param label is set to the PEM label found for later inspection
*/
BOTAN_PUBLIC_API(2,0) secure_vector<uint8_t> decode(DataSource& pem,
                                                    std::string& label);

/**
* Decode PEM data
* @param pem a string containing PEM encoded data
* @param label is set to the PEM label found for later inspection
*/
BOTAN_PUBLIC_API(2,0) secure_vector<uint8_t> decode(const std::string& pem,
                                                    std::string& label);

/**
* Decode PEM data
* @param pem a datasource containing PEM encoded data
* @param label is what we expect the label to be
*/
BOTAN_PUBLIC_API(2,0)
secure_vector<uint8_t> decode_check_label(DataSource& pem,
                                          const std::string& label);

/**
* Decode PEM data
* @param pem a string containing PEM encoded data
* @param label is what we expect the label to be
*/
BOTAN_PUBLIC_API(2,0)
secure_vector<uint8_t> decode_check_label(const std::string& pem,
                                          const std::string& label);

/**
* Heuristic test for PEM data.
*/
BOTAN_PUBLIC_API(2,0) bool matches(DataSource& source,
                                   const std::string& extra = "",
                                   size_t search_range = 4096);

}

}

namespace Botan {

BOTAN_PUBLIC_API(2,0) std::unique_ptr<Public_Key>
load_public_key(const AlgorithmIdentifier& alg_id,
                const std::vector<uint8_t>& key_bits);

BOTAN_PUBLIC_API(2,0) std::unique_ptr<Private_Key>
load_private_key(const AlgorithmIdentifier& alg_id,
                 const secure_vector<uint8_t>& key_bits);

/**
* Create a new key
* For ECC keys, algo_params specifies EC group (eg, "secp256r1")
* For DH/DSA/ElGamal keys, algo_params is DL group (eg, "modp/ietf/2048")
* For RSA, algo_params is integer keylength
* For McEliece, algo_params is n,t
* If algo_params is left empty, suitable default parameters are chosen.
*/
BOTAN_PUBLIC_API(2,0) std::unique_ptr<Private_Key>
create_private_key(const std::string& algo_name,
                   RandomNumberGenerator& rng,
                   const std::string& algo_params = "",
                   const std::string& provider = "");

BOTAN_PUBLIC_API(2,2)
std::vector<std::string>
probe_provider_private_key(const std::string& algo_name,
                           const std::vector<std::string> possible);

}
/**
* Ordinary applications should never need to include or use this
* header. It is exposed only for specialized applications which want
* to implement new versions of public key crypto without merging them
* as changes to the library. One actual example of such usage is an
* application which creates RSA signatures using a custom TPM library.
* Unless you're doing something like that, you don't need anything
* here. Instead use pubkey.h which wraps these types safely and
* provides a stable application-oriented API.
*/


namespace Botan {

class RandomNumberGenerator;
class EME;
class KDF;
class EMSA;

namespace PK_Ops {

/**
* Public key encryption interface
*/
class BOTAN_PUBLIC_API(2,0) Encryption
   {
   public:
      virtual secure_vector<uint8_t> encrypt(const uint8_t msg[],
                                          size_t msg_len,
                                          RandomNumberGenerator& rng) = 0;

      virtual size_t max_input_bits() const = 0;

      virtual size_t ciphertext_length(size_t ptext_len) const = 0;

      virtual ~Encryption() = default;
   };

/**
* Public key decryption interface
*/
class BOTAN_PUBLIC_API(2,0) Decryption
   {
   public:
      virtual secure_vector<uint8_t> decrypt(uint8_t& valid_mask,
                                          const uint8_t ciphertext[],
                                          size_t ciphertext_len) = 0;

      virtual size_t plaintext_length(size_t ctext_len) const = 0;

      virtual ~Decryption() = default;
   };

/**
* Public key signature verification interface
*/
class BOTAN_PUBLIC_API(2,0) Verification
   {
   public:
      /*
      * Add more data to the message currently being signed
      * @param msg the message
      * @param msg_len the length of msg in bytes
      */
      virtual void update(const uint8_t msg[], size_t msg_len) = 0;

      /*
      * Perform a verification operation
      * @param rng a random number generator
      */
      virtual bool is_valid_signature(const uint8_t sig[], size_t sig_len) = 0;

      virtual ~Verification() = default;
   };

/**
* Public key signature creation interface
*/
class BOTAN_PUBLIC_API(2,0) Signature
   {
   public:
      /*
      * Add more data to the message currently being signed
      * @param msg the message
      * @param msg_len the length of msg in bytes
      */
      virtual void update(const uint8_t msg[], size_t msg_len) = 0;

      /*
      * Perform a signature operation
      * @param rng a random number generator
      */
      virtual secure_vector<uint8_t> sign(RandomNumberGenerator& rng) = 0;

      /*
      * Return an upper bound on the length of the output signature
      */
      virtual size_t signature_length() const = 0;

      virtual ~Signature() = default;
   };

/**
* A generic key agreement operation (eg DH or ECDH)
*/
class BOTAN_PUBLIC_API(2,0) Key_Agreement
   {
   public:
      virtual secure_vector<uint8_t> agree(size_t key_len,
                                           const uint8_t other_key[], size_t other_key_len,
                                           const uint8_t salt[], size_t salt_len) = 0;

      virtual size_t agreed_value_size() const = 0;

      virtual ~Key_Agreement() = default;
   };

/**
* KEM (key encapsulation)
*/
class BOTAN_PUBLIC_API(2,0) KEM_Encryption
   {
   public:
      virtual void kem_encrypt(secure_vector<uint8_t>& out_encapsulated_key,
                               secure_vector<uint8_t>& out_shared_key,
                               size_t desired_shared_key_len,
                               Botan::RandomNumberGenerator& rng,
                               const uint8_t salt[],
                               size_t salt_len) = 0;

      virtual ~KEM_Encryption() = default;
   };

class BOTAN_PUBLIC_API(2,0) KEM_Decryption
   {
   public:
      virtual secure_vector<uint8_t> kem_decrypt(const uint8_t encap_key[],
                                              size_t len,
                                              size_t desired_shared_key_len,
                                              const uint8_t salt[],
                                              size_t salt_len) = 0;

      virtual ~KEM_Decryption() = default;
   };

}

}

namespace Botan {

class DataSource;
class RandomNumberGenerator;

/**
* PKCS #8 General Exception
*/
class BOTAN_PUBLIC_API(2,0) PKCS8_Exception final : public Decoding_Error
   {
   public:
      explicit PKCS8_Exception(const std::string& error) :
         Decoding_Error("PKCS #8: " + error) {}
   };

/**
* This namespace contains functions for handling PKCS #8 private keys
*/
namespace PKCS8 {

/**
* BER encode a private key
* @param key the private key to encode
* @return BER encoded key
*/
BOTAN_PUBLIC_API(2,0) secure_vector<uint8_t> BER_encode(const Private_Key& key);

/**
* Get a string containing a PEM encoded private key.
* @param key the key to encode
* @return encoded key
*/
BOTAN_PUBLIC_API(2,0) std::string PEM_encode(const Private_Key& key);

/**
* Encrypt a key using PKCS #8 encryption
* @param key the key to encode
* @param rng the rng to use
* @param pass the password to use for encryption
* @param msec number of milliseconds to run the password derivation
* @param pbe_algo the name of the desired password-based encryption
*        algorithm; if empty ("") a reasonable (portable/secure)
*        default will be chosen.
* @return encrypted key in binary BER form
*/
BOTAN_PUBLIC_API(2,0) std::vector<uint8_t>
BER_encode(const Private_Key& key,
           RandomNumberGenerator& rng,
           const std::string& pass,
           std::chrono::milliseconds msec = std::chrono::milliseconds(300),
           const std::string& pbe_algo = "");

/**
* Get a string containing a PEM encoded private key, encrypting it with a
* password.
* @param key the key to encode
* @param rng the rng to use
* @param pass the password to use for encryption
* @param msec number of milliseconds to run the password derivation
* @param pbe_algo the name of the desired password-based encryption
*        algorithm; if empty ("") a reasonable (portable/secure)
*        default will be chosen.
* @return encrypted key in PEM form
*/
BOTAN_PUBLIC_API(2,0) std::string
PEM_encode(const Private_Key& key,
           RandomNumberGenerator& rng,
           const std::string& pass,
           std::chrono::milliseconds msec = std::chrono::milliseconds(300),
           const std::string& pbe_algo = "");

/**
* Encrypt a key using PKCS #8 encryption and a fixed iteration count
* @param key the key to encode
* @param rng the rng to use
* @param pass the password to use for encryption
* @param pbkdf_iter number of interations to run PBKDF2
* @param cipher if non-empty specifies the cipher to use. CBC and GCM modes
*   are supported, for example "AES-128/CBC", "AES-256/GCM", "Serpent/CBC".
*   If empty a suitable default is chosen.
* @param pbkdf_hash if non-empty specifies the PBKDF hash function to use.
*   For example "SHA-256" or "SHA-384". If empty a suitable default is chosen.
* @return encrypted key in binary BER form
*/
BOTAN_PUBLIC_API(2,1) std::vector<uint8_t>
BER_encode_encrypted_pbkdf_iter(const Private_Key& key,
                                RandomNumberGenerator& rng,
                                const std::string& pass,
                                size_t pbkdf_iter,
                                const std::string& cipher = "",
                                const std::string& pbkdf_hash = "");

/**
* Get a string containing a PEM encoded private key, encrypting it with a
* password.
* @param key the key to encode
* @param rng the rng to use
* @param pass the password to use for encryption
* @param pbkdf_iter number of iterations to run PBKDF
* @param cipher if non-empty specifies the cipher to use. CBC and GCM modes
*   are supported, for example "AES-128/CBC", "AES-256/GCM", "Serpent/CBC".
*   If empty a suitable default is chosen.
* @param pbkdf_hash if non-empty specifies the PBKDF hash function to use.
*   For example "SHA-256" or "SHA-384". If empty a suitable default is chosen.
* @return encrypted key in PEM form
*/
BOTAN_PUBLIC_API(2,1) std::string
PEM_encode_encrypted_pbkdf_iter(const Private_Key& key,
                                RandomNumberGenerator& rng,
                                const std::string& pass,
                                size_t pbkdf_iter,
                                const std::string& cipher = "",
                                const std::string& pbkdf_hash = "");

/**
* Encrypt a key using PKCS #8 encryption and a variable iteration count
* @param key the key to encode
* @param rng the rng to use
* @param pass the password to use for encryption
* @param pbkdf_msec how long to run PBKDF2
* @param pbkdf_iterations if non-null, set to the number of iterations used
* @param cipher if non-empty specifies the cipher to use. CBC and GCM modes
*   are supported, for example "AES-128/CBC", "AES-256/GCM", "Serpent/CBC".
*   If empty a suitable default is chosen.
* @param pbkdf_hash if non-empty specifies the PBKDF hash function to use.
*   For example "SHA-256" or "SHA-384". If empty a suitable default is chosen.
* @return encrypted key in binary BER form
*/
BOTAN_PUBLIC_API(2,1) std::vector<uint8_t>
BER_encode_encrypted_pbkdf_msec(const Private_Key& key,
                                RandomNumberGenerator& rng,
                                const std::string& pass,
                                std::chrono::milliseconds pbkdf_msec,
                                size_t* pbkdf_iterations,
                                const std::string& cipher = "",
                                const std::string& pbkdf_hash = "");

/**
* Get a string containing a PEM encoded private key, encrypting it with a
* password.
* @param key the key to encode
* @param rng the rng to use
* @param pass the password to use for encryption
* @param pbkdf_msec how long in milliseconds to run PBKDF2
* @param pbkdf_iterations (output argument) number of iterations of PBKDF
*  that ended up being used
* @param cipher if non-empty specifies the cipher to use. CBC and GCM modes
*   are supported, for example "AES-128/CBC", "AES-256/GCM", "Serpent/CBC".
*   If empty a suitable default is chosen.
* @param pbkdf_hash if non-empty specifies the PBKDF hash function to use.
*   For example "SHA-256" or "SHA-384". If empty a suitable default is chosen.
* @return encrypted key in PEM form
*/
BOTAN_PUBLIC_API(2,1) std::string
PEM_encode_encrypted_pbkdf_msec(const Private_Key& key,
                                RandomNumberGenerator& rng,
                                const std::string& pass,
                                std::chrono::milliseconds pbkdf_msec,
                                size_t* pbkdf_iterations,
                                const std::string& cipher = "",
                                const std::string& pbkdf_hash = "");

/**
* Load an encrypted key from a data source.
* @param source the data source providing the encoded key
* @param rng ignored for compatibility
* @param get_passphrase a function that returns passphrases
* @return loaded private key object
*/
BOTAN_PUBLIC_API(2,0) Private_Key* load_key(DataSource& source,
                                            RandomNumberGenerator& rng,
                                            std::function<std::string ()> get_passphrase);

/** Load an encrypted key from a data source.
* @param source the data source providing the encoded key
* @param rng ignored for compatibility
* @param pass the passphrase to decrypt the key
* @return loaded private key object
*/
BOTAN_PUBLIC_API(2,0) Private_Key* load_key(DataSource& source,
                                            RandomNumberGenerator& rng,
                                            const std::string& pass);

/** Load an unencrypted key from a data source.
* @param source the data source providing the encoded key
* @param rng ignored for compatibility
* @return loaded private key object
*/
BOTAN_PUBLIC_API(2,0) Private_Key* load_key(DataSource& source,
                                            RandomNumberGenerator& rng);

#if defined(BOTAN_TARGET_OS_HAS_FILESYSTEM)
/**
* Load an encrypted key from a file.
* @param filename the path to the file containing the encoded key
* @param rng ignored for compatibility
* @param get_passphrase a function that returns passphrases
* @return loaded private key object
*/
BOTAN_PUBLIC_API(2,0) Private_Key* load_key(const std::string& filename,
                                            RandomNumberGenerator& rng,
                                            std::function<std::string ()> get_passphrase);

/** Load an encrypted key from a file.
* @param filename the path to the file containing the encoded key
* @param rng ignored for compatibility
* @param pass the passphrase to decrypt the key
* @return loaded private key object
*/
BOTAN_PUBLIC_API(2,0) Private_Key* load_key(const std::string& filename,
                                            RandomNumberGenerator& rng,
                                            const std::string& pass);

/** Load an unencrypted key from a file.
* @param filename the path to the file containing the encoded key
* @param rng ignored for compatibility
* @return loaded private key object
*/
BOTAN_PUBLIC_API(2,0) Private_Key* load_key(const std::string& filename,
                                            RandomNumberGenerator& rng);
#endif

/**
* Copy an existing encoded key object.
* @param key the key to copy
* @param rng ignored for compatibility
* @return new copy of the key
*/
BOTAN_PUBLIC_API(2,0) Private_Key* copy_key(const Private_Key& key,
                                            RandomNumberGenerator& rng);


/**
* Load an encrypted key from a data source.
* @param source the data source providing the encoded key
* @param get_passphrase a function that returns passphrases
* @return loaded private key object
*/
BOTAN_PUBLIC_API(2,3)
std::unique_ptr<Private_Key> load_key(DataSource& source,
                                      std::function<std::string ()> get_passphrase);

/** Load an encrypted key from a data source.
* @param source the data source providing the encoded key
* @param pass the passphrase to decrypt the key
* @return loaded private key object
*/
BOTAN_PUBLIC_API(2,3)
std::unique_ptr<Private_Key> load_key(DataSource& source,
                                      const std::string& pass);

/** Load an unencrypted key from a data source.
* @param source the data source providing the encoded key
* @return loaded private key object
*/
BOTAN_PUBLIC_API(2,3)
std::unique_ptr<Private_Key> load_key(DataSource& source);

/**
* Copy an existing encoded key object.
* @param key the key to copy
* @return new copy of the key
*/
BOTAN_PUBLIC_API(2,3)
std::unique_ptr<Private_Key> copy_key(const Private_Key& key);

}

}

namespace Botan {

/**
* Modular Exponentiator Interface
*/
class BOTAN_PUBLIC_API(2,0) Modular_Exponentiator
   {
   public:
      virtual void set_base(const BigInt&) = 0;
      virtual void set_exponent(const BigInt&) = 0;
      virtual BigInt execute() const = 0;
      virtual Modular_Exponentiator* copy() const = 0;

      Modular_Exponentiator() = default;
      Modular_Exponentiator(const Modular_Exponentiator&) = default;
      Modular_Exponentiator & operator=(const Modular_Exponentiator&) = default;
      virtual ~Modular_Exponentiator() = default;
   };

/**
* Modular Exponentiator Proxy
*/
class BOTAN_PUBLIC_API(2,0) Power_Mod
   {
   public:

      enum Usage_Hints {
         NO_HINTS        = 0x0000,

         BASE_IS_FIXED   = 0x0001,
         BASE_IS_SMALL   = 0x0002,
         BASE_IS_LARGE   = 0x0004,
         BASE_IS_2       = 0x0008,

         EXP_IS_FIXED    = 0x0100,
         EXP_IS_SMALL    = 0x0200,
         EXP_IS_LARGE    = 0x0400
      };

      /*
      * Try to choose a good window size
      */
      static size_t window_bits(size_t exp_bits, size_t base_bits,
                                Power_Mod::Usage_Hints hints);

      /**
      * @param modulus the modulus
      * @param hints Passed to set_modulus if modulus > 0
      * @param disable_montgomery_arith Disables use of Montgomery
      * representation. Likely only useful for testing.
      */
      void set_modulus(const BigInt& modulus,
                       Usage_Hints hints = NO_HINTS,
                       bool disable_montgomery_arith = false) const;

      /**
      * Set the base
      */
      void set_base(const BigInt& base) const;

      /**
      * Set the exponent
      */
      void set_exponent(const BigInt& exponent) const;

      /**
      * All three of the above functions must have already been called.
      * @return result of g^x%p
      */
      BigInt execute() const;

      Power_Mod& operator=(const Power_Mod&);

      /**
      * @param modulus Optionally call set_modulus
      * @param hints Passed to set_modulus if modulus > 0
      * @param disable_montgomery_arith Disables use of Montgomery
      * representation. Likely only useful for testing.
      */
      Power_Mod(const BigInt& modulus = 0,
                Usage_Hints hints = NO_HINTS,
                bool disable_montgomery_arith = false);
      Power_Mod(const Power_Mod&);
      virtual ~Power_Mod() = default;
   private:
      mutable std::unique_ptr<Modular_Exponentiator> m_core;
   };

/**
* Fixed Exponent Modular Exponentiator Proxy
*/
class BOTAN_PUBLIC_API(2,0) Fixed_Exponent_Power_Mod final : public Power_Mod
   {
   public:
      BigInt operator()(const BigInt& b) const
         { set_base(b); return execute(); }

      Fixed_Exponent_Power_Mod() = default;

      Fixed_Exponent_Power_Mod(const BigInt& exponent,
                               const BigInt& modulus,
                               Usage_Hints hints = NO_HINTS);
   };

/**
* Fixed Base Modular Exponentiator Proxy
*/
class BOTAN_PUBLIC_API(2,0) Fixed_Base_Power_Mod final : public Power_Mod
   {
   public:
      BigInt operator()(const BigInt& e) const
         { set_exponent(e); return execute(); }

      Fixed_Base_Power_Mod() = default;

      Fixed_Base_Power_Mod(const BigInt& base,
                           const BigInt& modulus,
                           Usage_Hints hints = NO_HINTS);
   };

}

namespace Botan {

/**
* PSSR (called EMSA4 in IEEE 1363 and in old versions of the library)
*/
class BOTAN_PUBLIC_API(2,0) PSSR final : public EMSA
   {
   public:

      /**
      * @param hash the hash function to use
      */
      explicit PSSR(HashFunction* hash);

      /**
      * @param hash the hash function to use
      * @param salt_size the size of the salt to use in bytes
      */
      PSSR(HashFunction* hash, size_t salt_size);

      EMSA* clone() override;

      std::string name() const override;

      AlgorithmIdentifier config_for_x509(const Private_Key& key,
                                          const std::string& cert_hash_name) const override;
   private:
      void update(const uint8_t input[], size_t length) override;

      secure_vector<uint8_t> raw_data() override;

      secure_vector<uint8_t> encoding_of(const secure_vector<uint8_t>& msg,
                                      size_t output_bits,
                                      RandomNumberGenerator& rng) override;

      bool verify(const secure_vector<uint8_t>& coded,
                  const secure_vector<uint8_t>& raw,
                  size_t key_bits) override;

      std::unique_ptr<HashFunction> m_hash;
      size_t m_salt_size;
      bool m_required_salt_len;
   };

/**
* PSSR_Raw
* This accepts a pre-hashed buffer
*/
class BOTAN_PUBLIC_API(2,3) PSSR_Raw final : public EMSA
   {
   public:

      /**
      * @param hash the hash function to use
      */
      explicit PSSR_Raw(HashFunction* hash);

      /**
      * @param hash the hash function to use
      * @param salt_size the size of the salt to use in bytes
      */
      PSSR_Raw(HashFunction* hash, size_t salt_size);

      EMSA* clone() override;

      std::string name() const override;
   private:
      void update(const uint8_t input[], size_t length) override;

      secure_vector<uint8_t> raw_data() override;

      secure_vector<uint8_t> encoding_of(const secure_vector<uint8_t>& msg,
                                         size_t output_bits,
                                         RandomNumberGenerator& rng) override;

      bool verify(const secure_vector<uint8_t>& coded,
                  const secure_vector<uint8_t>& raw,
                  size_t key_bits) override;

      std::unique_ptr<HashFunction> m_hash;
      secure_vector<uint8_t> m_msg;
      size_t m_salt_size;
      bool m_required_salt_len;
   };

}

#if defined(BOTAN_HAS_SYSTEM_RNG)

namespace Botan {

/**
* Return a shared reference to a global PRNG instance provided by the
* operating system. For instance might be instantiated by /dev/urandom
* or CryptGenRandom.
*/
BOTAN_PUBLIC_API(2,0) RandomNumberGenerator& system_rng();

/*
* Instantiable reference to the system RNG.
*/
class BOTAN_PUBLIC_API(2,0) System_RNG final : public RandomNumberGenerator
   {
   public:
      std::string name() const override { return system_rng().name(); }

      void randomize(uint8_t out[], size_t len) override { system_rng().randomize(out, len); }

      void add_entropy(const uint8_t in[], size_t length) override { system_rng().add_entropy(in, length); }

      bool is_seeded() const override { return system_rng().is_seeded(); }

      bool accepts_input() const override { return system_rng().accepts_input(); }

      void clear() override { system_rng().clear(); }
   };

}
  #define BOTAN_PUBKEY_INCLUDE_DEPRECATED_CONSTRUCTORS
#endif

namespace Botan {

class RandomNumberGenerator;

/**
* The two types of signature format supported by Botan.
*/
enum Signature_Format { IEEE_1363, DER_SEQUENCE };

/**
* Public Key Encryptor
* This is the primary interface for public key encryption
*/
class BOTAN_PUBLIC_API(2,0) PK_Encryptor
   {
   public:

      /**
      * Encrypt a message.
      * @param in the message as a byte array
      * @param length the length of the above byte array
      * @param rng the random number source to use
      * @return encrypted message
      */
      std::vector<uint8_t> encrypt(const uint8_t in[], size_t length,
                                 RandomNumberGenerator& rng) const
         {
         return enc(in, length, rng);
         }

      /**
      * Encrypt a message.
      * @param in the message
      * @param rng the random number source to use
      * @return encrypted message
      */
      template<typename Alloc>
      std::vector<uint8_t> encrypt(const std::vector<uint8_t, Alloc>& in,
                                RandomNumberGenerator& rng) const
         {
         return enc(in.data(), in.size(), rng);
         }

      /**
      * Return the maximum allowed message size in bytes.
      * @return maximum message size in bytes
      */
      virtual size_t maximum_input_size() const = 0;

      /**
      * Return an upper bound on the ciphertext length
      */
      virtual size_t ciphertext_length(size_t ctext_len) const = 0;

      PK_Encryptor() = default;
      virtual ~PK_Encryptor() = default;

      PK_Encryptor(const PK_Encryptor&) = delete;
      PK_Encryptor& operator=(const PK_Encryptor&) = delete;

   private:
      virtual std::vector<uint8_t> enc(const uint8_t[], size_t,
                                    RandomNumberGenerator&) const = 0;
   };

/**
* Public Key Decryptor
*/
class BOTAN_PUBLIC_API(2,0) PK_Decryptor
   {
   public:
      /**
      * Decrypt a ciphertext, throwing an exception if the input
      * seems to be invalid (eg due to an accidental or malicious
      * error in the ciphertext).
      *
      * @param in the ciphertext as a byte array
      * @param length the length of the above byte array
      * @return decrypted message
      */
      secure_vector<uint8_t> decrypt(const uint8_t in[], size_t length) const;

      /**
      * Same as above, but taking a vector
      * @param in the ciphertext
      * @return decrypted message
      */
      template<typename Alloc>
      secure_vector<uint8_t> decrypt(const std::vector<uint8_t, Alloc>& in) const
         {
         return decrypt(in.data(), in.size());
         }

      /**
      * Decrypt a ciphertext. If the ciphertext is invalid (eg due to
      * invalid padding) or is not the expected length, instead
      * returns a random string of the expected length. Use to avoid
      * oracle attacks, especially against PKCS #1 v1.5 decryption.
      */
      secure_vector<uint8_t>
      decrypt_or_random(const uint8_t in[],
                        size_t length,
                        size_t expected_pt_len,
                        RandomNumberGenerator& rng) const;

      /**
      * Decrypt a ciphertext. If the ciphertext is invalid (eg due to
      * invalid padding) or is not the expected length, instead
      * returns a random string of the expected length. Use to avoid
      * oracle attacks, especially against PKCS #1 v1.5 decryption.
      *
      * Additionally checks (also in const time) that:
      *    contents[required_content_offsets[i]] == required_content_bytes[i]
      * for 0 <= i < required_contents
      *
      * Used for example in TLS, which encodes the client version in
      * the content bytes: if there is any timing variation the version
      * check can be used as an oracle to recover the key.
      */
      secure_vector<uint8_t>
      decrypt_or_random(const uint8_t in[],
                        size_t length,
                        size_t expected_pt_len,
                        RandomNumberGenerator& rng,
                        const uint8_t required_content_bytes[],
                        const uint8_t required_content_offsets[],
                        size_t required_contents) const;

      /**
      * Return an upper bound on the plaintext length for a particular
      * ciphertext input length
      */
      virtual size_t plaintext_length(size_t ctext_len) const = 0;

      PK_Decryptor() = default;
      virtual ~PK_Decryptor() = default;

      PK_Decryptor(const PK_Decryptor&) = delete;
      PK_Decryptor& operator=(const PK_Decryptor&) = delete;

   private:
      virtual secure_vector<uint8_t> do_decrypt(uint8_t& valid_mask,
                                             const uint8_t in[], size_t in_len) const = 0;
   };

/**
* Public Key Signer. Use the sign_message() functions for small
* messages. Use multiple calls update() to process large messages and
* generate the signature by finally calling signature().
*/
class BOTAN_PUBLIC_API(2,0) PK_Signer final
   {
   public:

      /**
      * Construct a PK Signer.
      * @param key the key to use inside this signer
      * @param rng the random generator to use
      * @param emsa the EMSA to use
      * An example would be "EMSA1(SHA-224)".
      * @param format the signature format to use
      * @param provider the provider to use
      */
      PK_Signer(const Private_Key& key,
                RandomNumberGenerator& rng,
                const std::string& emsa,
                Signature_Format format = IEEE_1363,
                const std::string& provider = "");

#if defined(BOTAN_PUBKEY_INCLUDE_DEPRECATED_CONSTRUCTORS)
      /**
      * Construct a PK Signer.
      * @param key the key to use inside this signer
      * @param emsa the EMSA to use
      * An example would be "EMSA1(SHA-224)".
      * @param format the signature format to use
      */
      BOTAN_DEPRECATED("Use constructor taking a RNG object")
      PK_Signer(const Private_Key& key,
                const std::string& emsa,
                Signature_Format format = IEEE_1363,
                const std::string& provider = "") :
         PK_Signer(key, system_rng(), emsa, format, provider)
         {}
#endif

      ~PK_Signer();

      PK_Signer(const PK_Signer&) = delete;
      PK_Signer& operator=(const PK_Signer&) = delete;

      /**
      * Sign a message all in one go
      * @param in the message to sign as a byte array
      * @param length the length of the above byte array
      * @param rng the rng to use
      * @return signature
      */
      std::vector<uint8_t> sign_message(const uint8_t in[], size_t length,
                                     RandomNumberGenerator& rng)
         {
         this->update(in, length);
         return this->signature(rng);
         }

      /**
      * Sign a message.
      * @param in the message to sign
      * @param rng the rng to use
      * @return signature
      */
      template<typename Alloc>
         std::vector<uint8_t> sign_message(const std::vector<uint8_t, Alloc>& in,
                                           RandomNumberGenerator& rng)
         {
         return sign_message(in.data(), in.size(), rng);
         }

      /**
      * Add a message part (single byte).
      * @param in the byte to add
      */
      void update(uint8_t in) { update(&in, 1); }

      /**
      * Add a message part.
      * @param in the message part to add as a byte array
      * @param length the length of the above byte array
      */
      void update(const uint8_t in[], size_t length);

      /**
      * Add a message part.
      * @param in the message part to add
      */
      template<typename Alloc>
      void update(const std::vector<uint8_t, Alloc>& in)
         {
         update(in.data(), in.size());
         }

      /**
      * Add a message part.
      * @param in the message part to add
      */
      void update(const std::string& in)
         {
         update(cast_char_ptr_to_uint8(in.data()), in.size());
         }

      /**
      * Get the signature of the so far processed message (provided by the
      * calls to update()).
      * @param rng the rng to use
      * @return signature of the total message
      */
      std::vector<uint8_t> signature(RandomNumberGenerator& rng);


      /**
      * Set the output format of the signature.
      * @param format the signature format to use
      */
      void set_output_format(Signature_Format format) { m_sig_format = format; }

      /**
      * Return an upper bound on the length of the signatures this
      * PK_Signer will produce
      */
      size_t signature_length() const;

   private:
      std::unique_ptr<PK_Ops::Signature> m_op;
      Signature_Format m_sig_format;
      size_t m_parts, m_part_size;
   };

/**
* Public Key Verifier. Use the verify_message() functions for small
* messages. Use multiple calls update() to process large messages and
* verify the signature by finally calling check_signature().
*/
class BOTAN_PUBLIC_API(2,0) PK_Verifier final
   {
   public:
      /**
      * Construct a PK Verifier.
      * @param pub_key the public key to verify against
      * @param emsa the EMSA to use (eg "EMSA3(SHA-1)")
      * @param format the signature format to use
      * @param provider the provider to use
      */
      PK_Verifier(const Public_Key& pub_key,
                  const std::string& emsa,
                  Signature_Format format = IEEE_1363,
                  const std::string& provider = "");

      ~PK_Verifier();

      PK_Verifier& operator=(const PK_Verifier&) = delete;
      PK_Verifier(const PK_Verifier&) = delete;

      /**
      * Verify a signature.
      * @param msg the message that the signature belongs to, as a byte array
      * @param msg_length the length of the above byte array msg
      * @param sig the signature as a byte array
      * @param sig_length the length of the above byte array sig
      * @return true if the signature is valid
      */
      bool verify_message(const uint8_t msg[], size_t msg_length,
                          const uint8_t sig[], size_t sig_length);
      /**
      * Verify a signature.
      * @param msg the message that the signature belongs to
      * @param sig the signature
      * @return true if the signature is valid
      */
      template<typename Alloc, typename Alloc2>
      bool verify_message(const std::vector<uint8_t, Alloc>& msg,
                          const std::vector<uint8_t, Alloc2>& sig)
         {
         return verify_message(msg.data(), msg.size(),
                               sig.data(), sig.size());
         }

      /**
      * Add a message part (single byte) of the message corresponding to the
      * signature to be verified.
      * @param in the byte to add
      */
      void update(uint8_t in) { update(&in, 1); }

      /**
      * Add a message part of the message corresponding to the
      * signature to be verified.
      * @param msg_part the new message part as a byte array
      * @param length the length of the above byte array
      */
      void update(const uint8_t msg_part[], size_t length);

      /**
      * Add a message part of the message corresponding to the
      * signature to be verified.
      * @param in the new message part
      */
      template<typename Alloc>
         void update(const std::vector<uint8_t, Alloc>& in)
         {
         update(in.data(), in.size());
         }

      /**
      * Add a message part of the message corresponding to the
      * signature to be verified.
      */
      void update(const std::string& in)
         {
         update(cast_char_ptr_to_uint8(in.data()), in.size());
         }

      /**
      * Check the signature of the buffered message, i.e. the one build
      * by successive calls to update.
      * @param sig the signature to be verified as a byte array
      * @param length the length of the above byte array
      * @return true if the signature is valid, false otherwise
      */
      bool check_signature(const uint8_t sig[], size_t length);

      /**
      * Check the signature of the buffered message, i.e. the one build
      * by successive calls to update.
      * @param sig the signature to be verified
      * @return true if the signature is valid, false otherwise
      */
      template<typename Alloc>
      bool check_signature(const std::vector<uint8_t, Alloc>& sig)
         {
         return check_signature(sig.data(), sig.size());
         }

      /**
      * Set the format of the signatures fed to this verifier.
      * @param format the signature format to use
      */
      void set_input_format(Signature_Format format);

   private:
      std::unique_ptr<PK_Ops::Verification> m_op;
      Signature_Format m_sig_format;
      size_t m_parts, m_part_size;
   };

/**
* Object used for key agreement
*/
class BOTAN_PUBLIC_API(2,0) PK_Key_Agreement final
   {
   public:

      /**
      * Construct a PK Key Agreement.
      * @param key the key to use
      * @param rng the random generator to use
      * @param kdf name of the KDF to use (or 'Raw' for no KDF)
      * @param provider the algo provider to use (or empty for default)
      */
      PK_Key_Agreement(const Private_Key& key,
                       RandomNumberGenerator& rng,
                       const std::string& kdf,
                       const std::string& provider = "");

#if defined(BOTAN_PUBKEY_INCLUDE_DEPRECATED_CONSTRUCTORS)
      /**
      * Construct a PK Key Agreement.
      * @param key the key to use
      * @param kdf name of the KDF to use (or 'Raw' for no KDF)
      * @param provider the algo provider to use (or empty for default)
      */
      BOTAN_DEPRECATED("Use constructor taking a RNG object")
      PK_Key_Agreement(const Private_Key& key,
                       const std::string& kdf,
                       const std::string& provider = "") :
         PK_Key_Agreement(key, system_rng(), kdf, provider)
         {}
#endif

      ~PK_Key_Agreement();

      // For ECIES
      PK_Key_Agreement& operator=(PK_Key_Agreement&&);
      PK_Key_Agreement(PK_Key_Agreement&&);

      PK_Key_Agreement& operator=(const PK_Key_Agreement&) = delete;
      PK_Key_Agreement(const PK_Key_Agreement&) = delete;

      /**
      * Perform Key Agreement Operation
      * @param key_len the desired key output size
      * @param in the other parties key
      * @param in_len the length of in in bytes
      * @param params extra derivation params
      * @param params_len the length of params in bytes
      */
      SymmetricKey derive_key(size_t key_len,
                              const uint8_t in[],
                              size_t in_len,
                              const uint8_t params[],
                              size_t params_len) const;

      /**
      * Perform Key Agreement Operation
      * @param key_len the desired key output size
      * @param in the other parties key
      * @param params extra derivation params
      * @param params_len the length of params in bytes
      */
      SymmetricKey derive_key(size_t key_len,
                              const std::vector<uint8_t>& in,
                              const uint8_t params[],
                              size_t params_len) const
         {
         return derive_key(key_len, in.data(), in.size(),
                           params, params_len);
         }

      /**
      * Perform Key Agreement Operation
      * @param key_len the desired key output size
      * @param in the other parties key
      * @param in_len the length of in in bytes
      * @param params extra derivation params
      */
      SymmetricKey derive_key(size_t key_len,
                              const uint8_t in[], size_t in_len,
                              const std::string& params = "") const
         {
         return derive_key(key_len, in, in_len,
                           cast_char_ptr_to_uint8(params.data()),
                           params.length());
         }

      /**
      * Perform Key Agreement Operation
      * @param key_len the desired key output size
      * @param in the other parties key
      * @param params extra derivation params
      */
      SymmetricKey derive_key(size_t key_len,
                              const std::vector<uint8_t>& in,
                              const std::string& params = "") const
         {
         return derive_key(key_len, in.data(), in.size(),
                           cast_char_ptr_to_uint8(params.data()),
                           params.length());
         }

      /**
      * Return the underlying size of the value that is agreed.
      * If derive_key is called with a length of 0 with a "Raw"
      * KDF, it will return a value of this size.
      */
      size_t agreed_value_size() const;

   private:
      std::unique_ptr<PK_Ops::Key_Agreement> m_op;
   };

/**
* Encryption using a standard message recovery algorithm like RSA or
* ElGamal, paired with an encoding scheme like OAEP.
*/
class BOTAN_PUBLIC_API(2,0) PK_Encryptor_EME final : public PK_Encryptor
   {
   public:
      size_t maximum_input_size() const override;

      /**
      * Construct an instance.
      * @param key the key to use inside the encryptor
      * @param rng the RNG to use
      * @param padding the message encoding scheme to use (eg "OAEP(SHA-256)")
      * @param provider the provider to use
      */
      PK_Encryptor_EME(const Public_Key& key,
                       RandomNumberGenerator& rng,
                       const std::string& padding,
                       const std::string& provider = "");

#if defined(BOTAN_PUBKEY_INCLUDE_DEPRECATED_CONSTRUCTORS)
      /**
      * Construct an instance.
      * @param key the key to use inside the encryptor
      * @param padding the message encoding scheme to use (eg "OAEP(SHA-256)")
      */
      BOTAN_DEPRECATED("Use constructor taking a RNG object")
      PK_Encryptor_EME(const Public_Key& key,
                       const std::string& padding,
                       const std::string& provider = "") :
         PK_Encryptor_EME(key, system_rng(), padding, provider) {}
#endif

      ~PK_Encryptor_EME();

      PK_Encryptor_EME& operator=(const PK_Encryptor_EME&) = delete;
      PK_Encryptor_EME(const PK_Encryptor_EME&) = delete;

      /**
      * Return an upper bound on the ciphertext length for a particular
      * plaintext input length
      */
      size_t ciphertext_length(size_t ptext_len) const override;
   private:
      std::vector<uint8_t> enc(const uint8_t[], size_t,
                             RandomNumberGenerator& rng) const override;

      std::unique_ptr<PK_Ops::Encryption> m_op;
   };

/**
* Decryption with an MR algorithm and an EME.
*/
class BOTAN_PUBLIC_API(2,0) PK_Decryptor_EME final : public PK_Decryptor
   {
   public:
     /**
      * Construct an instance.
      * @param key the key to use inside the decryptor
      * @param rng the random generator to use
      * @param eme the EME to use
      * @param provider the provider to use
      */
      PK_Decryptor_EME(const Private_Key& key,
                       RandomNumberGenerator& rng,
                       const std::string& eme,
                       const std::string& provider = "");


#if defined(BOTAN_PUBKEY_INCLUDE_DEPRECATED_CONSTRUCTORS)
      /**
      * Construct an instance.
      * @param key the key to use inside the decryptor
      * @param eme the message encoding scheme to use (eg "OAEP(SHA-256)")
      */
      BOTAN_DEPRECATED("Use constructor taking a RNG object")
      PK_Decryptor_EME(const Private_Key& key,
                       const std::string& eme,
                       const std::string& provider = "") :
         PK_Decryptor_EME(key, system_rng(), eme, provider) {}
#endif

      size_t plaintext_length(size_t ptext_len) const override;

      ~PK_Decryptor_EME();
      PK_Decryptor_EME& operator=(const PK_Decryptor_EME&) = delete;
      PK_Decryptor_EME(const PK_Decryptor_EME&) = delete;
   private:
      secure_vector<uint8_t> do_decrypt(uint8_t& valid_mask,
                                     const uint8_t in[],
                                     size_t in_len) const override;

      std::unique_ptr<PK_Ops::Decryption> m_op;
   };

/**
* Public Key Key Encapsulation Mechanism Encryption.
*/
class BOTAN_PUBLIC_API(2,0) PK_KEM_Encryptor final
   {
   public:
      /**
      * Construct an instance.
      * @param key the key to use inside the encryptor
      * @param rng the RNG to use
      * @param kem_param additional KEM parameters
      * @param provider the provider to use
      */
      PK_KEM_Encryptor(const Public_Key& key,
                       RandomNumberGenerator& rng,
                       const std::string& kem_param = "",
                       const std::string& provider = "");

#if defined(BOTAN_PUBKEY_INCLUDE_DEPRECATED_CONSTRUCTORS)
      BOTAN_DEPRECATED("Use constructor taking a RNG object")
      PK_KEM_Encryptor(const Public_Key& key,
                       const std::string& kem_param = "",
                       const std::string& provider = "") :
         PK_KEM_Encryptor(key, system_rng(), kem_param, provider) {}
#endif

      ~PK_KEM_Encryptor();

      PK_KEM_Encryptor& operator=(const PK_KEM_Encryptor&) = delete;
      PK_KEM_Encryptor(const PK_KEM_Encryptor&) = delete;

      /**
      * Generate a shared key for data encryption.
      * @param out_encapsulated_key the generated encapsulated key
      * @param out_shared_key the generated shared key
      * @param desired_shared_key_len desired size of the shared key in bytes
      * @param rng the RNG to use
      * @param salt a salt value used in the KDF
      * @param salt_len size of the salt value in bytes
      */
      void encrypt(secure_vector<uint8_t>& out_encapsulated_key,
                   secure_vector<uint8_t>& out_shared_key,
                   size_t desired_shared_key_len,
                   Botan::RandomNumberGenerator& rng,
                   const uint8_t salt[],
                   size_t salt_len);

      /**
      * Generate a shared key for data encryption.
      * @param out_encapsulated_key the generated encapsulated key
      * @param out_shared_key the generated shared key
      * @param desired_shared_key_len desired size of the shared key in bytes
      * @param rng the RNG to use
      * @param salt a salt value used in the KDF
      */
      template<typename Alloc>
         void encrypt(secure_vector<uint8_t>& out_encapsulated_key,
                      secure_vector<uint8_t>& out_shared_key,
                      size_t desired_shared_key_len,
                      Botan::RandomNumberGenerator& rng,
                      const std::vector<uint8_t, Alloc>& salt)
         {
         this->encrypt(out_encapsulated_key,
                       out_shared_key,
                       desired_shared_key_len,
                       rng,
                       salt.data(), salt.size());
         }


      /**
      * Generate a shared key for data encryption.
      * @param out_encapsulated_key the generated encapsulated key
      * @param out_shared_key the generated shared key
      * @param desired_shared_key_len desired size of the shared key in bytes
      * @param rng the RNG to use
      */
      void encrypt(secure_vector<uint8_t>& out_encapsulated_key,
                   secure_vector<uint8_t>& out_shared_key,
                   size_t desired_shared_key_len,
                   Botan::RandomNumberGenerator& rng)
         {
         this->encrypt(out_encapsulated_key,
                       out_shared_key,
                       desired_shared_key_len,
                       rng,
                       nullptr,
                       0);
         }

   private:
      std::unique_ptr<PK_Ops::KEM_Encryption> m_op;
   };

/**
* Public Key Key Encapsulation Mechanism Decryption.
*/
class BOTAN_PUBLIC_API(2,0) PK_KEM_Decryptor final
   {
   public:
      /**
      * Construct an instance.
      * @param key the key to use inside the decryptor
      * @param rng the RNG to use
      * @param kem_param additional KEM parameters
      * @param provider the provider to use
      */
      PK_KEM_Decryptor(const Private_Key& key,
                       RandomNumberGenerator& rng,
                       const std::string& kem_param = "",
                       const std::string& provider = "");

#if defined(BOTAN_PUBKEY_INCLUDE_DEPRECATED_CONSTRUCTORS)
      BOTAN_DEPRECATED("Use constructor taking a RNG object")
      PK_KEM_Decryptor(const Private_Key& key,
                       const std::string& kem_param = "",
                       const std::string& provider = "") :
         PK_KEM_Decryptor(key, system_rng(), kem_param, provider)
         {}
#endif

      ~PK_KEM_Decryptor();
      PK_KEM_Decryptor& operator=(const PK_KEM_Decryptor&) = delete;
      PK_KEM_Decryptor(const PK_KEM_Decryptor&) = delete;

      /**
      * Decrypts the shared key for data encryption.
      * @param encap_key the encapsulated key
      * @param encap_key_len size of the encapsulated key in bytes
      * @param desired_shared_key_len desired size of the shared key in bytes
      * @param salt a salt value used in the KDF
      * @param salt_len size of the salt value in bytes
      * @return the shared data encryption key
      */
      secure_vector<uint8_t> decrypt(const uint8_t encap_key[],
                                  size_t encap_key_len,
                                  size_t desired_shared_key_len,
                                  const uint8_t salt[],
                                  size_t salt_len);

      /**
      * Decrypts the shared key for data encryption.
      * @param encap_key the encapsulated key
      * @param encap_key_len size of the encapsulated key in bytes
      * @param desired_shared_key_len desired size of the shared key in bytes
      * @return the shared data encryption key
      */
      secure_vector<uint8_t> decrypt(const uint8_t encap_key[],
                                  size_t encap_key_len,
                                  size_t desired_shared_key_len)
         {
         return this->decrypt(encap_key, encap_key_len,
                              desired_shared_key_len,
                              nullptr, 0);
         }

      /**
      * Decrypts the shared key for data encryption.
      * @param encap_key the encapsulated key
      * @param desired_shared_key_len desired size of the shared key in bytes
      * @param salt a salt value used in the KDF
      * @return the shared data encryption key
      */
      template<typename Alloc1, typename Alloc2>
         secure_vector<uint8_t> decrypt(const std::vector<uint8_t, Alloc1>& encap_key,
                                     size_t desired_shared_key_len,
                                     const std::vector<uint8_t, Alloc2>& salt)
         {
         return this->decrypt(encap_key.data(), encap_key.size(),
                              desired_shared_key_len,
                              salt.data(), salt.size());
         }

   private:
      std::unique_ptr<PK_Ops::KEM_Decryption> m_op;
   };

}

namespace Botan {

/**
* RSA Public Key
*/
class BOTAN_PUBLIC_API(2,0) RSA_PublicKey : public virtual Public_Key
   {
   public:
      /**
      * Load a public key.
      * @param alg_id the X.509 algorithm identifier
      * @param key_bits DER encoded public key bits
      */
      RSA_PublicKey(const AlgorithmIdentifier& alg_id,
                    const std::vector<uint8_t>& key_bits);

      /**
      * Create a public key.
      * @arg n the modulus
      * @arg e the exponent
      */
      RSA_PublicKey(const BigInt& n, const BigInt& e) :
         m_n(n), m_e(e) {}

      std::string algo_name() const override { return "RSA"; }

      bool check_key(RandomNumberGenerator& rng, bool) const override;

      AlgorithmIdentifier algorithm_identifier() const override;

      std::vector<uint8_t> public_key_bits() const override;

      /**
      * @return public modulus
      */
      const BigInt& get_n() const { return m_n; }

      /**
      * @return public exponent
      */
      const BigInt& get_e() const { return m_e; }

      size_t key_length() const override;
      size_t estimated_strength() const override;

      std::unique_ptr<PK_Ops::Encryption>
         create_encryption_op(RandomNumberGenerator& rng,
                              const std::string& params,
                              const std::string& provider) const override;

      std::unique_ptr<PK_Ops::KEM_Encryption>
         create_kem_encryption_op(RandomNumberGenerator& rng,
                                  const std::string& params,
                                  const std::string& provider) const override;

      std::unique_ptr<PK_Ops::Verification>
         create_verification_op(const std::string& params,
                                const std::string& provider) const override;

   protected:
      RSA_PublicKey() = default;

      BigInt m_n, m_e;
   };

/**
* RSA Private Key
*/
class BOTAN_PUBLIC_API(2,0) RSA_PrivateKey final : public Private_Key, public RSA_PublicKey
   {
   public:
      /**
      * Load a private key.
      * @param alg_id the X.509 algorithm identifier
      * @param key_bits PKCS#1 RSAPrivateKey bits
      */
      RSA_PrivateKey(const AlgorithmIdentifier& alg_id,
                     const secure_vector<uint8_t>& key_bits);

      /**
      * Construct a private key from the specified parameters.
      * @param p the first prime
      * @param q the second prime
      * @param e the exponent
      * @param d if specified, this has to be d with
      * exp * d = 1 mod (p - 1, q - 1). Leave it as 0 if you wish to
      * the constructor to calculate it.
      * @param n if specified, this must be n = p * q. Leave it as 0
      * if you wish to the constructor to calculate it.
      */
      RSA_PrivateKey(const BigInt& p, const BigInt& q,
                     const BigInt& e, const BigInt& d = 0,
                     const BigInt& n = 0);

      /**
      * Create a new private key with the specified bit length
      * @param rng the random number generator to use
      * @param bits the desired bit length of the private key
      * @param exp the public exponent to be used
      */
      RSA_PrivateKey(RandomNumberGenerator& rng,
                     size_t bits, size_t exp = 65537);

      bool check_key(RandomNumberGenerator& rng, bool) const override;

      /**
      * Get the first prime p.
      * @return prime p
      */
      const BigInt& get_p() const { return m_p; }

      /**
      * Get the second prime q.
      * @return prime q
      */
      const BigInt& get_q() const { return m_q; }

      /**
      * Get d with exp * d = 1 mod (p - 1, q - 1).
      * @return d
      */
      const BigInt& get_d() const { return m_d; }

      const BigInt& get_c() const { return m_c; }
      const BigInt& get_d1() const { return m_d1; }
      const BigInt& get_d2() const { return m_d2; }

      secure_vector<uint8_t> private_key_bits() const override;

      std::unique_ptr<PK_Ops::Decryption>
         create_decryption_op(RandomNumberGenerator& rng,
                              const std::string& params,
                              const std::string& provider) const override;

      std::unique_ptr<PK_Ops::KEM_Decryption>
         create_kem_decryption_op(RandomNumberGenerator& rng,
                                  const std::string& params,
                                  const std::string& provider) const override;

      std::unique_ptr<PK_Ops::Signature>
         create_signature_op(RandomNumberGenerator& rng,
                             const std::string& params,
                             const std::string& provider) const override;

   private:
      BigInt m_d, m_p, m_q, m_d1, m_d2, m_c;
   };

}

namespace Botan {

/**
A class encapsulating a SCAN name (similar to JCE conventions)
http://www.users.zetnet.co.uk/hopwood/crypto/scan/
*/
class BOTAN_PUBLIC_API(2,0) SCAN_Name final
   {
   public:
      /**
      * Create a SCAN_Name
      * @param algo_spec A SCAN-format name
      */
      explicit SCAN_Name(const char* algo_spec);

      /**
      * Create a SCAN_Name
      * @param algo_spec A SCAN-format name
      */
      explicit SCAN_Name(std::string algo_spec);

      /**
      * @return original input string
      */
      const std::string& as_string() const { return m_orig_algo_spec; }

      /**
      * @return algorithm name
      */
      const std::string& algo_name() const { return m_alg_name; }

      /**
      * @return number of arguments
      */
      size_t arg_count() const { return m_args.size(); }

      /**
      * @param lower is the lower bound
      * @param upper is the upper bound
      * @return if the number of arguments is between lower and upper
      */
      bool arg_count_between(size_t lower, size_t upper) const
         { return ((arg_count() >= lower) && (arg_count() <= upper)); }

      /**
      * @param i which argument
      * @return ith argument
      */
      std::string arg(size_t i) const;

      /**
      * @param i which argument
      * @param def_value the default value
      * @return ith argument or the default value
      */
      std::string arg(size_t i, const std::string& def_value) const;

      /**
      * @param i which argument
      * @param def_value the default value
      * @return ith argument as an integer, or the default value
      */
      size_t arg_as_integer(size_t i, size_t def_value) const;

      /**
      * @return cipher mode (if any)
      */
      std::string cipher_mode() const
         { return (m_mode_info.size() >= 1) ? m_mode_info[0] : ""; }

      /**
      * @return cipher mode padding (if any)
      */
      std::string cipher_mode_pad() const
         { return (m_mode_info.size() >= 2) ? m_mode_info[1] : ""; }

   private:
      std::string m_orig_algo_spec;
      std::string m_alg_name;
      std::vector<std::string> m_args;
      std::vector<std::string> m_mode_info;
   };

// This is unrelated but it is convenient to stash it here
template<typename T>
std::vector<std::string> probe_providers_of(const std::string& algo_spec,
                                            const std::vector<std::string>& possible)
   {
   std::vector<std::string> providers;
   for(auto&& prov : possible)
      {
      std::unique_ptr<T> o(T::create(algo_spec, prov));
      if(o)
         {
         providers.push_back(prov); // available
         }
      }
   return providers;
   }

}

namespace Botan {

/**
* SHA-224
*/
class BOTAN_PUBLIC_API(2,0) SHA_224 final : public MDx_HashFunction
   {
   public:
      std::string name() const override { return "SHA-224"; }
      size_t output_length() const override { return 28; }
      HashFunction* clone() const override { return new SHA_224; }
      std::unique_ptr<HashFunction> copy_state() const override;

      void clear() override;

      SHA_224() : MDx_HashFunction(64, true, true), m_digest(8)
         { clear(); }
   private:
      void compress_n(const uint8_t[], size_t blocks) override;
      void copy_out(uint8_t[]) override;

      secure_vector<uint32_t> m_digest;
   };

/**
* SHA-256
*/
class BOTAN_PUBLIC_API(2,0) SHA_256 final : public MDx_HashFunction
   {
   public:
      std::string name() const override { return "SHA-256"; }
      size_t output_length() const override { return 32; }
      HashFunction* clone() const override { return new SHA_256; }
      std::unique_ptr<HashFunction> copy_state() const override;

      void clear() override;

      SHA_256() : MDx_HashFunction(64, true, true), m_digest(8)
         { clear(); }

      /*
      * Perform a SHA-256 compression. For internal use
      */
      static void compress_digest(secure_vector<uint32_t>& digest,
                                  const uint8_t input[],
                                  size_t blocks);

   private:

#if defined(BOTAN_HAS_SHA2_32_ARMV8)
      static void compress_digest_armv8(secure_vector<uint32_t>& digest,
                                        const uint8_t input[],
                                        size_t blocks);
#endif

#if defined(BOTAN_HAS_SHA2_32_X86_BMI2)
      static void compress_digest_x86_bmi2(secure_vector<uint32_t>& digest,
                                           const uint8_t input[],
                                           size_t blocks);
#endif

#if defined(BOTAN_HAS_SHA2_32_X86)
      static void compress_digest_x86(secure_vector<uint32_t>& digest,
                                      const uint8_t input[],
                                      size_t blocks);
#endif

      void compress_n(const uint8_t[], size_t blocks) override;
      void copy_out(uint8_t[]) override;

      secure_vector<uint32_t> m_digest;
   };

}

#if __cplusplus < 201402L
#endif

namespace Botan
{
/*
* std::make_unique functionality similar as we have in C++14.
* C++11 version based on proposal for C++14 implemenatation by Stephan T. Lavavej
* source: https://isocpp.org/files/papers/N3656.txt
*/
#if __cplusplus >= 201402L
template <typename T, typename ... Args>
constexpr auto make_unique(Args&&... args)
   {
   return std::make_unique<T>(std::forward<Args>(args)...);
   }

template<class T>
constexpr auto make_unique(std::size_t size)
   {
   return std::make_unique<T>(size);
   }

#else
namespace stlCompatibilityDetails
{
template<class T> struct _Unique_if
   {
   typedef std::unique_ptr<T> _Single_object;
   };

template<class T> struct _Unique_if<T[]>
   {
   typedef std::unique_ptr<T[]> _Unknown_bound;
   };

template<class T, size_t N> struct _Unique_if<T[N]>
   {
   typedef void _Known_bound;
   };
}  // namespace stlCompatibilityDetails

template<class T, class... Args>
typename stlCompatibilityDetails::_Unique_if<T>::_Single_object make_unique(Args&&... args)
   {
   return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
   }

template<class T>
typename stlCompatibilityDetails::_Unique_if<T>::_Unknown_bound make_unique(size_t n)
   {
   typedef typename std::remove_extent<T>::type U;
   return std::unique_ptr<T>(new U[n]());
   }

template<class T, class... Args>
typename stlCompatibilityDetails::_Unique_if<T>::_Known_bound make_unique(Args&&...) = delete;

#endif

}  // namespace Botan

namespace Botan {

/*
* Get information describing the version
*/

/**
* Get a human-readable string identifying the version of Botan.
* No particular format should be assumed.
* @return version string
*/
BOTAN_PUBLIC_API(2,0) std::string version_string();

/**
* Same as version_string() except returning a pointer to a statically
* allocated string.
* @return version string
*/
BOTAN_PUBLIC_API(2,0) const char* version_cstr();

/**
* Return a version string of the form "MAJOR.MINOR.PATCH" where
* each of the values is an integer.
*/
BOTAN_PUBLIC_API(2,4) std::string short_version_string();

/**
* Same as version_short_string except returning a pointer to the string.
*/
BOTAN_PUBLIC_API(2,4) const char* short_version_cstr();

/**
* Return the date this version of botan was released, in an integer of
* the form YYYYMMDD. For instance a version released on May 21, 2013
* would return the integer 20130521. If the currently running version
* is not an official release, this function will return 0 instead.
*
* @return release date, or zero if unreleased
*/
BOTAN_PUBLIC_API(2,0) uint32_t version_datestamp();

/**
* Get the major version number.
* @return major version number
*/
BOTAN_PUBLIC_API(2,0) uint32_t version_major();

/**
* Get the minor version number.
* @return minor version number
*/
BOTAN_PUBLIC_API(2,0) uint32_t version_minor();

/**
* Get the patch number.
* @return patch number
*/
BOTAN_PUBLIC_API(2,0) uint32_t version_patch();

/**
* Usable for checking that the DLL version loaded at runtime exactly
* matches the compile-time version. Call using BOTAN_VERSION_* macro
* values. Returns the empty string if an exact match, otherwise an
* appropriate message. Added with 1.11.26.
*/
BOTAN_PUBLIC_API(2,0) std::string
runtime_version_check(uint32_t major,
                      uint32_t minor,
                      uint32_t patch);

/*
* Macros for compile-time version checks
*/
#define BOTAN_VERSION_CODE_FOR(a,b,c) ((a << 16) | (b << 8) | (c))

/**
* Compare using BOTAN_VERSION_CODE_FOR, as in
*  # if BOTAN_VERSION_CODE < BOTAN_VERSION_CODE_FOR(1,8,0)
*  #    error "Botan version too old"
*  # endif
*/
#define BOTAN_VERSION_CODE BOTAN_VERSION_CODE_FOR(BOTAN_VERSION_MAJOR, \
                                                  BOTAN_VERSION_MINOR, \
                                                  BOTAN_VERSION_PATCH)

}

namespace Botan {

/**
* Estimate work factor for discrete logarithm
* @param prime_group_size size of the group in bits
* @return estimated security level for this group
*/
BOTAN_PUBLIC_API(2,0) size_t dl_work_factor(size_t prime_group_size);

/**
* Return the appropriate exponent size to use for a particular prime
* group. This is twice the size of the estimated cost of breaking the
* key using an index calculus attack; the assumption is that if an
* arbitrary discrete log on a group of size bits would take about 2^n
* effort, and thus using an exponent of size 2^(2*n) implies that all
* available attacks are about as easy (as e.g Pollard's kangaroo
* algorithm can compute the DL in sqrt(x) operations) while minimizing
* the exponent size for performance reasons.
*/
BOTAN_PUBLIC_API(2,0) size_t dl_exponent_size(size_t prime_group_size);

/**
* Estimate work factor for integer factorization
* @param n_bits size of modulus in bits
* @return estimated security level for this modulus
*/
BOTAN_PUBLIC_API(2,0) size_t if_work_factor(size_t n_bits);

/**
* Estimate work factor for EC discrete logarithm
* @param prime_group_size size of the group in bits
* @return estimated security level for this group
*/
BOTAN_PUBLIC_API(2,0) size_t ecp_work_factor(size_t prime_group_size);

}

namespace Botan {

class RandomNumberGenerator;
class DataSource;

/**
* The two types of X509 encoding supported by Botan.
* This enum is not used anymore, and will be removed in a future major release.
*/
enum X509_Encoding { RAW_BER, PEM };

/**
* This namespace contains functions for handling X.509 public keys
*/
namespace X509 {

/**
* BER encode a key
* @param key the public key to encode
* @return BER encoding of this key
*/
BOTAN_PUBLIC_API(2,0) std::vector<uint8_t> BER_encode(const Public_Key& key);

/**
* PEM encode a public key into a string.
* @param key the key to encode
* @return PEM encoded key
*/
BOTAN_PUBLIC_API(2,0) std::string PEM_encode(const Public_Key& key);

/**
* Create a public key from a data source.
* @param source the source providing the DER or PEM encoded key
* @return new public key object
*/
BOTAN_PUBLIC_API(2,0) Public_Key* load_key(DataSource& source);

#if defined(BOTAN_TARGET_OS_HAS_FILESYSTEM)
/**
* Create a public key from a file
* @param filename pathname to the file to load
* @return new public key object
*/
BOTAN_PUBLIC_API(2,0) Public_Key* load_key(const std::string& filename);
#endif

/**
* Create a public key from a memory region.
* @param enc the memory region containing the DER or PEM encoded key
* @return new public key object
*/
BOTAN_PUBLIC_API(2,0) Public_Key* load_key(const std::vector<uint8_t>& enc);

/**
* Copy a key.
* @param key the public key to copy
* @return new public key object
*/
BOTAN_PUBLIC_API(2,0) Public_Key* copy_key(const Public_Key& key);

}

}

#endif // BOTAN_AMALGAMATION_H_
