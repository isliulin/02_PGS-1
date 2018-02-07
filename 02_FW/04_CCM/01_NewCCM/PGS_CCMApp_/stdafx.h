// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.

#pragma once

#pragma comment(linker, "/nodefaultlib:libc.lib")
#pragma comment(linker, "/nodefaultlib:libcd.lib")

// ���� - �� ���� ��� Windows CE OS ������ ������ ������ �����ϴ�.
#define WINVER _WIN32_WCE

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// �Ϻ� CString �����ڴ� ���������� ����˴ϴ�.
#ifdef _CE_DCOM
#define _ATL_APARTMENT_THREADED
#endif

// MFC�� ���� �κа� ���� ������ ��� �޽����� ���� ����⸦ �����մϴ�.
#define _AFX_ALL_WARNINGS

#include <ceconfig.h>
#if defined(WIN32_PLATFORM_PSPC) || defined(WIN32_PLATFORM_WFSP)
#define SHELL_AYGSHELL
#endif

#include <afxwin.h>         // MFC �ٽ� �� ǥ�� ���� ����Դϴ�.
#include <afxext.h>         // MFC Ȯ���Դϴ�.

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>		// Internet Explorer 4 ���� ��Ʈ�ѿ� ���� MFC �����Դϴ�.
#endif



#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// Windows ���� ��Ʈ�ѿ� ���� MFC �����Դϴ�.
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxsock.h>		// MFC ���� Ȯ���Դϴ�.


#if defined(WIN32_PLATFORM_PSPC) || defined(WIN32_PLATFORM_WFSP)
#ifndef _DEVICE_RESOLUTION_AWARE
#define _DEVICE_RESOLUTION_AWARE
#endif
#endif

#ifdef _DEVICE_RESOLUTION_AWARE
#include "DeviceResolutionAware.h"
#endif


#if (_WIN32_WCE < 0x500) && ( defined(WIN32_PLATFORM_PSPC) || defined(WIN32_PLATFORM_WFSP) )
	#pragma comment(lib, "ccrtrtti.lib")
	#ifdef _X86_	
		#if defined(_DEBUG)
			#pragma comment(lib, "libcmtx86d.lib")
		#else
			#pragma comment(lib, "libcmtx86.lib")
		#endif
	#endif
#endif

#include <altcecrt.h>

#include "afxmt.h"
#include "GlobalDef.h"
#include "InfoComm_CCM_Serv.h"
#include "crc16.h"
#include "Comm.h"
#include "Xdefine.h"
#include "ManNetComm.h"
#include "ManSCM_Comm.h"

//#define __PRINT_LOG_DATA__
//#define __ALWAYS_AUTO_INIT_RET_OK__
#define __SHOW_DLG_SETTING_GENERAL__
#define __RST_WHEN_WRITE_DEBUG_DATA__

#define STR_LOG_FILE_PATH				"IGSHARE\\Log_PS_CCM_App_SG.txt"

#define SZ_APP_WND_H				800
#define SZ_APP_WND_V				480

#define STR_MSG_SOCK_INIT_FAIL			_T("CCM ��ġ�� ��Ʈ�� ������ ������ �ֽ��ϴ�.\n���� ��ü�� ������ �ּ���.")

#define STR_INFO_GLOBAL_FILE_PATH		"IGSHARE\\InfoGlobalData.txt"
#define STR_INFO_DEBUG_DATA_FILE_PATH	"IGSHARE\\DebugData.txt"
#define STR_INIT_DEBUG_DATA_FILE_PATH	"IGSHARE\\InitDebugData.txt"
#define STR_INFO_USM_LGM_DATA_PATH	    "IGSHARE\\SystemDataInfo.txt"


#define NUM_EBD_GROUP			100

enum {
	IDX_EBD1_ENTRANCE_01,
//	IDX_EBD1_ENTRANCE_02,

	NUM_EBD1_DEV
};

enum {
	////����
	IDX_EBD1_STAIR_3B_1,
	//IDX_EBD1_STAIR_3B_2,
	//IDX_EBD1_STAIR_3B_3,
	//IDX_EBD1_STAIR_4B_4,
	//IDX_EBD1_STAIR_4B_5,
	//IDX_EBD1_STAIR_4B_6,
	//IDX_EBD1_STAIR_5B_7,
	//IDX_EBD1_STAIR_5B_8,
	//IDX_EBD1_STAIR_5B_9,
	//IDX_EBD1_STAIR_6B_10,
	//IDX_EBD1_STAIR_6B_11,
	//IDX_EBD1_STAIR_6B_12,

	//�Ա�
//	IDX_EBD1_ENTRANCE_01,


	NUM_EBD2_DEV
};

enum {
	IDX_EBD_CLR_BLACK,
	IDX_EBD_CLR_RED,
	IDX_EBD_CLR_GREEN,
	IDX_EBD_CLR_YELLOW,
	IDX_EBD_CLR_PURPLE,
	IDX_EBD_CLR_MARGENTA,
	IDX_EBD_CLR_CYAN,
	IDX_EBD_CLR_WHITE,

	NUM_EBD_TXT_CLR
};
#define MAX_NUM_STR_IN_EBD			32

#define NUM_PORT_B4_RCV_INFO		3
#define NUM_BAUD_RATE_B4_RCV_INFO	2400

void SendTxtToEBoard (int nDST, char *strSndA, char *strSndB, int *bufClrA, int *bufClrB, CComm *pComm);
void SendTxtToEBoard (int nDST, char *strSnd, int *bufClr, CComm *pComm);


struct INFO_GLOBAL {
	wchar_t strServAddr[SZ_STR_SERV_ADDR];
	int nDevID_CCM;

	INFO_SCM_COMM_SETTINGS iSCS;

	int SetAD_nRetrySnsOffCmd;
	int SetAD_nRetryOtherCmd;
	int SetAD_nRetryProc;
	DWORD SetAD_timeWaitAfterCmdFail;
	DWORD SetAD_timeoutCheckNoZeroStat;

	int EBD1Comm_nPort;
	int EBD1Comm_nBaudRate;
	int EBD1Comm_timeSendInterval;
	int EBD1Comm_bufDstID[NUM_EBD1_DEV];

	int EBD2Comm_nPort;
	int EBD2Comm_nBaudRate;
	int EBD2Comm_timeSendInterval;
	int EBD2Comm_bufDstID[NUM_EBD2_DEV];
};

extern INFO_GLOBAL glIGlobal;

BOOL ReadInfoGlobal ();
void WriteInfoGlobal ();

int GetNumUSM (ITEM_RESM_USM_LGM_STAT *pISCMA);
int GetNumLGM (ITEM_RESM_USM_LGM_STAT *pISCMA);

// HANJIN P4793 CRC16[S]
unsigned short HJ_P4793_CRC16_GenCode (const unsigned char* message, unsigned long length);
// HANJIN P4793 CRC16[E]
