# Simple-Base91
C/C++ and Arduino compatible library for encoding &amp; decoding binary data
to base91.

## How to use

See the example for an Arduino C/C++ example.

To encode:
```C
size_t outSize = encodeBase91(inBuffer, inSize, outBuffer);
```

* `inBuffer` is the input data buffer of any type.
* `inSize` is a `size_t` integer of the number of bytes in `inBuffer`
* `outBuffer` is a where the base91 data will be placed. Typically `char[]`
* Returns `outSize`, the number of bytes written to `outBuffer`


To decode:
```C
size_t n2 = decodeBase91(inBuffer, n, outBuffer);
```

* `inBuffer` is the base91 encoded input buffer.
* `inSize` is a `size_t` integer of the number of bytes in `inBuffer`
* `outBuffer` is a where the decoded data will be placed.
* Returns `outSize`, the number of bytes written to `outBuffer`

## What is this?

Some communications systems expect data to be ASCII text, which makes sending
binary data impossible. On those systems, you can encode binary data as ASCII
text. The most common method is Base64 which encodes 6 arbitrary binary bits as
8 ASCII bits. Base91 is slightly more efficient in that it encodes 6.5 bits as
8 ASCII bits.

One implementation is known as [basE91](http://base91.sourceforge.net/) (note
the capital E). This system sqeezes out slightly better than 6.5 bits in to 8
ASCII bits, and works well. This repository takes some of the techniques from
there and makes the following changes

* Changes from little endian to big endian encoding
* Uses a deterministic method for encoding data. n binary bytes will be encoded as
 `ceil((n)*8/6.5)` bytes in base91
* Significantly simplifies the API
* Makes the library C++ compatible and Arduino compatible.
* Use the base91 method and dictionary used in
[APRS](http://www.aprs.org/doc/APRS101.PDF). You can add/change your own as
needed.

