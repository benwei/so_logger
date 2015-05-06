# so_logger
simple log library written in c, feature with limit size for embedded linux

# build with cross_compile
```
  cd src; make CROSS_COMIPLE=arm-linux-gnueabihf-
```
  or

```
  export CROSS_COMIPLE=arm-linux-gnueabihf-
  cd src; make
```

# build host
force ignore CROSS_COMIPLE for testing
```
  cd src ; make HOST=1
```

# test on HOSTS
```
  cd tests; make HOST=1
```
