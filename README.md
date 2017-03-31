# stanDB
A relational database management system.    

This program currently only supports *nix systems. You will need to download and compile the Boost C++ source libraries.
Because of dynamic library linking, the compiler needs to know where to locate the appropriate files.
```
Inside your .bashrc, add the following

export LD_LIBRARY_PATH=<path-to-boost-lib>/stage/lib/
~~~
