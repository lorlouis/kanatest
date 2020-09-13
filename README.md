# Kanatest
### A simple katagana and hiragana practice program

## Usage
./kanatest [--help | [-ahkmsytrnw] [--dakuten] [--combined] [--hiragana]]

launching this program without arguments is the same as --base

### Parameters:
option | equivalent group
-------|-----------------
-a | a e i u o
-h | ha he hi fu ho
-k | ka ke ki ku ko
-m | ma me mi mu mo
-s | sa se shi su so
-y | ya yu yo
-t | ta te chi tu to
-r | ra re ri ru ro
-n | na ne ni nu no
-w | wa wu wo

flag | behaviour
-----|----------
--base | is the same as -ahkmsytrnw
--dakuten | adds each specified group's dakuten
--combined | adds eache specified group's combo katagana
--hiragana | will load hiraganas instead of kataganas

if --dakuten or --combined are the only
groups specified all the dakuten and/or combo
katagana will be added whithout adding the base katagana
