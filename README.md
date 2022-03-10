# About

Calculator is more one application written in C of a classic calculator. Its goal
is to perform a parsing of a mathematical expression. The user interface(UI) and
application integration use the GTK-3 library, while for the parser only an ISO C99
standard library is required.

## Building

The build system uses meson. For more information about of how to install meson see
[getting meson](https://mesonbuild.com/Getting-meson.html).

## Dependencies

### GTK Library

Refers to [GTK Installations](https://www.gtk.org/docs/installations/).

## Build on Linux

To build Calcular on a Linux distribution run these commands:

```shell
meson setup builddir && cd builddir
meson compile
```

## Build on Windows

TODO

## Build on MacOS

TODO
