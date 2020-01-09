# openssl-ecjpake

An implementation of the [J-PAKE](https://en.wikipedia.org/wiki/Password_Authenticated_Key_Exchange_by_Juggling) cryptographic protocol based on elliptic curves.  J-PAKE is a key agreement protocol that allows parties to establish secure communications by means of a shared, low-entropy password/secret.

This implementation is built for use with [OpenSSL](https://www.openssl.org/), and makes use of OpenSSL's public EC crypto APIs.  It can also be with Google's [BoringSSL](https://boringssl.googlesource.com/boringssl/).

## Building

Clone the openssl-ecjpake repo:

         $ git clone https://github.com/openweave/openssl-ecjpake
         $ cd openssl-ecjpake

Build using the supplied automake makefile:

         $ autoreconf -ivf
         $ ./configure
         $ make
