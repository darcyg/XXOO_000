/**
* mdb.c -- 表计数据读取
* 
* 作者: zhuzhiqiang
* 创建时间: 2009-5-15
* 最后修改时间: 2009-5-15
*/

//#include <stdio.h>
#include <string.h>

#include "plat_include/debug.h"
#include "plat_include/timeal.h"
#include "app_include/param/capconf.h"
#include "app_include/cenmet/mdbconf.h"
#include "app_include/cenmet/mdbstat.h"
#include "app_include/cenmet/mdbcur.h"
#include "app_include/cenmet/mdbstic.h"
//#include "mdbuene.h"
#include "app_include/cenmet/mdbfrez.h"
//#include "mdbtgrp.h"
//#include "mdbanasig.h"

typedef int (*qrymdb_pf)(unsigned short metpid, unsigned short itemid, unsigned char *buf, int len);

typedef struct {
	unsigned char grpid;
	qrymdb_pf pfunc;
} mdbfunc_t;
static const mdbfunc_t MdbFuncList[] = {
	{0, ReadMdbState},
	{1, ReadMdbState},
//	{2, ReadMdbTGrp},
	{3, ReadMdbCurrent},
	{4, ReadMdbCurrent},
//	{5, ReadMdbUseEne},
	{6, ReadMdbCurrent},
	{7, ReadMdbCurrent},
//	{9, ReadMdbAnaSig},
	{10, ReadMdbFrez},
	{11, ReadMdbFrez},
	{12, ReadMdbFrez},
	{13, ReadMdbFrez},
	{14, ReadMdbFrez},
	{15, ReadMdbFrez},
	{16, ReadMdbCurrent},
	{17, ReadMdbCurrent},
	{18, ReadMdbCurrent},
	{19, ReadMdbCurrent},
	{20, ReadMdbCurrent},
	{22, ReadMdbState},
};

static qrymdb_pf FindMdbFunc(unsigned char grpid)
{
	int i;

	for(i=0; i<sizeof(MdbFuncList)/sizeof(mdbfunc_t); i++) {
		if(grpid == MdbFuncList[i].grpid) return MdbFuncList[i].pfunc;
	}

	return NULL;
}

/**
* @brief 读取1类数据
* @param metpid 测量点号, 1~
* @param itemid 数据标识
* @param buf 输出缓存区指针
* @param len 输出缓存区长度
* @param pactlen 返回实际读取长度变量指针
* @return 成功0, 否则失败
*/
int ReadMdb(unsigned short metpid, unsigned short itemid, unsigned char *buf, int len, int *pactlen)
{
	unsigned char grpid;
	int rtn;
	qrymdb_pf pfunc;

	*pactlen = 0;
	grpid = (unsigned char)(itemid>>8);

	pfunc = FindMdbFunc(grpid);
	if(NULL == pfunc) return 1;

	rtn = (*pfunc)(metpid, itemid, buf, len);
	PrintLog(LOGTYPE_DEBUG,"readmdb rtn(%d)\n",rtn);
	
	if(rtn <= 0) return 1;
	else {
		*pactlen = rtn;
		return 0;
	}
}

extern int DbaseInit(void);
//extern int MdbAnaInit(void);
extern int MdbCurrentInit(void);
extern int MdbSaveInit(void);
//extern int SndTimeInit(void);

/**
* @brief MDB表计数据模块初始化
* @return 成功0, 否则失败
*/
int MdbInit(void)
{
	//PrintLog(LOGTYPE_DEBUG,"  mdb init...\n");

	DbaseInit();
//	MdbAnaInit();
	MdbCurrentInit();
	MdbSaveInit();
	//SndTimeInit();

	return 0;
}

