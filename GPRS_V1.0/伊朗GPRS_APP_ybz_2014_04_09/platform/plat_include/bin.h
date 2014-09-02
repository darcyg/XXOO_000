/**
* bin.h -- 二进制文件储存头文件
* 
* 作者: zhuzhiqiang
* 创建时间: 2009-5-6
* 最后修改时间: 2009-5-6
*/

#ifndef _STORAGE_BIN_H
#define _STORAGE_BIN_H

/**
* @brief 保存一个BIN文件
* @param file 文件名
* @param magic 文件标识字
* @param buffer 缓存区指针
* @param len 缓存区长度
* @return 成功返回0, 否则失败
*/
int SaveBinFile(const char *file, unsigned long magic, const unsigned char *buffer, int len);
int SaveBinFileUnlock(const char *file, unsigned long magic, const unsigned char *buffer, int len);

/**
* @brief 读取一个BIN文件
* @param file 文件名
* @param magic 文件标识字
* @param buffer 缓存区指针
* @param len 缓存区长度
* @return 成功返回实际读取长度,失败返回-1
*/
int ReadBinFile(const char *file, unsigned long magic, unsigned char *buffer, int len);

/**
* @brief 读取一个BIN文件
*    与ReadBinFile不同的是,buffer内容在读取失败的情况下也有可能修改
*    因此需要应用程序分配专门的buffer
*    一般用来读取数据文件
*    操作比ReadBinFile少了内存分配操作, 但增加了数据不安全性, 使用时要小心
* @param file 文件名
* @param magic 文件标识字
* @param buffer Cache缓存区指针
* @param len 缓存区长度
* @return 成功返回实际读取长度,失败返回-1
*/
int ReadBinFileCache(const char *file, unsigned long magic, unsigned char *buffer, int len);

struct bin_buflist {
	struct bin_buflist *next;  //下一条指针
	unsigned char *buffer;  //缓存区地址
	int buflen;  //缓存区长度
};
#define INIT_BINLIST(list, pbuf, len)		{ \
	(list).buffer = pbuf; \
	(list).buflen = len; \
	(list).next = NULL; \
}

#define APPEND_BINLIST(list, list2) { (list).next = &(list2); }

/**
* @brief 保存一个BIN文件
* @param file 文件名
* @param magic 文件标识字
* @param buffer 缓存区指针
* @param len 缓存区长度
* @return 成功返回0, 否则失败
*/
int SaveBinFileList(const char *file, unsigned long magic, const struct bin_buflist *plist);
int SaveBinFileListUnlock(const char *file, unsigned long magic, const struct bin_buflist *plist);

/**
* @brief 读取一个BIN文件
* @param file 文件名
* @param magic 文件标识字
* @param plist 缓存区链表指针
* @return 成功返回实际读取长度,失败返回-1
*/
int ReadBinFileList(const char *file, unsigned long magic, const struct bin_buflist *plist);



#endif /*_STORAGE_BIN_H*/

