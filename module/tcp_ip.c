//
// Created by 1655664358@qq.com on 2019/5/4.
//

//DM9000EP网卡芯片的驱动原理
//https://blog.csdn.net/b02330224/article/details/7895724

/**
 * 芯片的读写操作通过控制AEN,CMD,IOR,IOW，等实现数据的读写操作
 * 具体按照芯片的读写时序来完成，数据会保存各类寄存器里
 *
**/