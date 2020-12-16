# Kanatest

A simple katakana and hiragana practice program

## Usage

    ./kanatest [--help | [-ahkmsytrnw] [--dakuten] [--combined] [--hiragana]]

launching this program without arguments is the same as --base

### Parameters

option | equivalent group
-------|-----------------
-a | ア エ イ ウ オ
-h | ハ ヘ ヒ フ ホ
-k | カ ケ キ ク コ
-m | マ メ ム ミ モ
-s | サ セ シ ス ソ
-y | ヤ ユ ヨ
-t | タ テ チ ツ ト
-r | ラ レ リ ル ロ
-n | ナ ネ ニ ヌ ノ
-w | ワ ヲ ン

flag | behaviour
-----|----------
--base | is the same as -ahkmsytrnw
--dakuten | adds each specified group's dakuten
--combined | adds each specified group's combo katakana
--hiragana | will load hiraganas instead of katakanas

if --dakuten or --combined are the only
groups specified all the dakuten and/or combo
katakana will be added whithout adding the base katakana
