# botan 混合编译

生成混合编译文件：

1. 下载botan源码: [botan github](https://github.com/randombit/botan)
1. 解压后进入源码目录，执行生成混合编译源码命令：
```
./configure.py --amalgamation --single-amalgamation-file --disable-modules=pkcs11 \
--minimized-build --enable-modules=rsa,auto_rng,system_rng,win32_stats,eme_oaep,md5
```
1. 将生成的`botan_all.cpp`、`botan_all.h`、`botan_all_internal.h`三个文件拷贝到工程中
1. 编译时需要预定义宏`BOTAN_DLL=`
