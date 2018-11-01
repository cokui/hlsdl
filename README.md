https://github.com/samsamsam-iptvplayer/hlsdl is fork that is under active development.
-----

hlsdl
=====

This program converts .m3u8 playlists to a .ts video. It supports decryption of both AES-128 and SAMPLE-AES encryption.

Requirements
------------

This program requirers FFmpeg installed in order to decrypt SAMPLE-AES content.

Build
-----

Use `make && make install && make clean` to install.

Usage and Options
-----------------
`./hlsdl url [options]`

---------------------------
```
--best    or -b  ... Automaticly choose the best quality.

--verbose or -v  ... Verbose more information.

--output  or -o  ... Choose name of output file.

--help    or -h  ... Print help.

--force   or -f  ... Force overwriting the output file.

--quiet   or -q  ... Print less to the console.

--dump-dec-cmd   ... Print the Key and IV of each media segment.

--dump-ts-urls   ... Print the links to the .ts files.
```

Ideas
-----

- Multithreading
- Remuxing to other formats
- Local .m3u8 files
- Livestreams
- C++ refactor for fun

License
-------

[MIT License](https://github.com/selsta/hlsdl/blob/master/LICENSE)
