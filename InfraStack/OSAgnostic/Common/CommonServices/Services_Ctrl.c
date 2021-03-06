/**************************************************************************
Copyright (c) 2007-2009, Intel Corporation. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

 3. Neither the name of the Intel Corporation nor the names of its
    contributors may be used to endorse or promote products derived from
    this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

***************************************************************************/
#include "Services_Ctrl.h"

#include "CommonServices.h"
#include "L4ConfigurationManager.h"
#include "wimax_osal_event_logger.h"
#include "Messenger.h"
#include "TraceModule.h"
#include "L3L4CommonDefines.h"

char *L4Opcodes[] = {
	"L4_L3_OPCODE_CMD_INIT",
	"L4_L3_OPCODE_CMD_TERMINATE",
	"L4_L3_OPCODE_CMD_MODE_OF_OPERATION",
	"L4_L3_OPCODE_CMD_RESET_DEVICE",
	"L4_L3_OPCODE_CMD_MONITOR_CONTROL",
	"L4_L3_OPCODE_GET_LM_VERSION",
	"L4_L3_OPCODE_GET_DEVICE_INFO",
	"L4_L3_OPCODE_GET_LINK_STATUS",
	"L4_L3_OPCODE_GET_STATISTICS",
	"L4_L3_OPCODE_GET_STATE",	
	"L4_L3_OPCODE_GET_MEDIA_STATUS",
	"L4_L3_OPCODE_GET_TRACE_SEVERITY_TABLE",
	"L4_L3_OPCODE_GET_MONITOR_FILTER_TABLE",
	"L4_L3_OPCODE_GET_COEX_MODE",
	"L4_L3_OPCODE_SET_TRACE_SEVERITY_TABLE",
	"L4_L3_OPCODE_SET_MONITOR_FILTER_TABLE",
	"L4_L3_OPCODE_CMD_RF_CONTROL",
	"L4_L3_OPCODE_CMD_SCAN",
	"L4_L3_OPCODE_CMD_CONNECT",
	"L4_L3_OPCODE_CMD_DISCONNECT",
	"L4_L3_OPCODE_SET_SCAN_PARAM",	
	"L4_L3_OPCODE_GET_SCAN_RESULT",
	"L4_L3_OPCODE_CMD_SEND_EAP_RESPONSE",
	"L4_L3_OPCODE_SET_EAP_SUCCESS",
	"L4_L3_OPCODE_SET_EAP_FAIL",	
	"L4_L3_OPCODE_SET_EAP_KEY",		
	"L4_PRODUCTION_OPCODE_CMD_START_PHY_RXTX_TEST",
	"L4_PRODUCTION_OPCODE_CMD_STOP_PHY_TEST",			
	"L4_PRODUCTION_OPCODE_CMD_PHY_METRICS_CONFIG",
	"L4_PRODUCTION_OPCODE_CMD_START_PHY_INIT_CALIBRATION_TEST",
	"L4_PRODUCTION_OPCODE_CMD_START_PHY_MAIN_CALIBRATION_TEST",
	"L4_PRODUCTION_OPCODE_CMD_PHY_COUNTERS_RESET_ORDER",
	"L4_PRODUCTION_OPCODE_CMD_NVM_WRITE",		
	"L4_PRODUCTION_OPCODE_CMD_NVM_READ",					
	"L4_PRODUCTION_OPCODE_SET_GPIO",					
	"L4_PRODUCTION_OPCODE_GET_PHY_METRICS",
	"L4_PRODUCTION_OPCODE_GET_PHY_TEMPRATURE",
	"L4_PRODUCTION_OPCODE_GET_PHY_DIUC_CONFIGURATION",
	"L4_PRODUCTION_OPCODE_GET_PHY_UIUC_CONFIGURATION",	
	"L4_PRODUCTION_OPCODE_GET_GPIO",
	"L4_PRODUCTION_OPCODE_SET_PHY_TPC_CONFIG",
	"L4_L3_OPCODE_CMD_MOC_REQUEST",
	"L4_L3_OPCODE_CMD_CHECK_INTERFACE",
	"L4_L3_OPCODE_GET_DEBUG_LOOPBACK",
	"L4_L3_OPCODE_GET_CHECK_INTERFACE",
	"L4_L3_OPCODE_SET_CHECK_INTERFACE"
};

char *L4Indications[] = {
	"L3_L4_OPCODE_REPORT_STATE",
	"L3_L4_OPCODE_REPORT_TRACE_EVACUATE",
	"L3_L4_OPCODE_REPORT_MONITOR_EVACUATE",
	"L3_L4_OPCODE_REPORT_SCAN_RESULT",	
	"L3_L4_OPCODE_REPORT_EAP_REQUEST",
	"L3_L4_OPCODE_REPORT_EAP_RESTART",
	"L3_L4_OPCODE_REPORT_ALT_ACCEPT",
	"L3_L4_OPCODE_REPORT_KEY_REQUEST",
	"PRODUCTION_L4_OPCODE_REPORT_PRODUCTION_STATE_STATUS",
	"PRODUCTION_L4_OPCODE_REPORT_PHY_METRICS",
	"PRODUCTION_L4_OPCODE_REPORT_PHY_INIT_CALIBRATION_RESULTS",
	"PRODUCTION_L4_OPCODE_REPORT_PHY_MAIN_CALIBRATION_RESULTS",
	"PRODUCTION_L4_OPCODE_REPORT_NVM_WRITE_STATUS",
	"PRODUCTION_L4_OPCODE_REPORT_NVM_READ_STATUS",			
	"L3_L4_OPCODE_REPORT_MOC_RESPONSE",
	"L3_L4_OPCODE_REPORT_MOC_BROADCAST",
	"L3_L4_OPCODE_REPORT_CHECK_INTERFACE"	
};

void Services_Fini()
{
}


BOOL Services_Init()
{
	L4Configurations_init();
	return TRUE;
}

char* GetL4Indication(UINT16 indCode)
{
	switch(indCode)
	{
		case L3_L4_OPCODE_REPORT_STATE:
			return L4Indications[0];
		case L3_L4_OPCODE_REPORT_TRACE_EVACUATE:
			return L4Indications[1];
		case L3_L4_OPCODE_REPORT_MONITOR_EVACUATE:
			return L4Indications[2];
		case L3_L4_OPCODE_REPORT_SCAN_RESULT:	
			return L4Indications[3];
		case L3_L4_OPCODE_REPORT_EAP_REQUEST:
			return L4Indications[4];
		case L3_L4_OPCODE_REPORT_EAP_RESTART:
			return L4Indications[5];
		case L3_L4_OPCODE_REPORT_ALT_ACCEPT:
			return L4Indications[6];
		case L3_L4_OPCODE_REPORT_KEY_REQUEST:
			return L4Indications[7];
		case PRODUCTION_L4_OPCODE_REPORT_PRODUCTION_STATE_STATUS:
			return L4Indications[8];
		case PRODUCTION_L4_OPCODE_REPORT_PHY_METRICS:
			return L4Indications[9];
		case PRODUCTION_L4_OPCODE_REPORT_PHY_INIT_CALIBRATION_RESULTS:
			return L4Indications[10];
		case PRODUCTION_L4_OPCODE_REPORT_PHY_MAIN_CALIBRATION_RESULTS:
			return L4Indications[11];
		case PRODUCTION_L4_OPCODE_REPORT_NVM_WRITE_STATUS:
			return L4Indications[12];
		case PRODUCTION_L4_OPCODE_REPORT_NVM_READ_STATUS:			
			return L4Indications[13];
		case L3_L4_OPCODE_REPORT_MOC_RESPONSE:
			return L4Indications[14];
		case L3_L4_OPCODE_REPORT_MOC_BROADCAST:
			return L4Indications[15];
		case L3_L4_OPCODE_REPORT_CHECK_INTERFACE:	
			return L4Indications[16];
	}

	return NULL;
}

char* GetL4Opcode(void *buffer)
{
	UINT16 opcode = *(UINT16*)buffer;

	switch(opcode)
	{
		case L4_L3_OPCODE_CMD_INIT:
			return L4Opcodes[0];
		case L4_L3_OPCODE_CMD_TERMINATE:
			return L4Opcodes[1];
		case L4_L3_OPCODE_CMD_MODE_OF_OPERATION:
			return L4Opcodes[2];
		case L4_L3_OPCODE_CMD_RESET_DEVICE:
			return L4Opcodes[3];
		case L4_L3_OPCODE_CMD_MONITOR_CONTROL:
			return L4Opcodes[4];
		case L4_L3_OPCODE_GET_LM_VERSION:
			return L4Opcodes[5];
		case L4_L3_OPCODE_GET_DEVICE_INFO:
			return L4Opcodes[6];
		case L4_L3_OPCODE_GET_LINK_STATUS:
			return L4Opcodes[7];
		case L4_L3_OPCODE_GET_STATISTICS:
			return L4Opcodes[8];
		case L4_L3_OPCODE_GET_STATE:
			return L4Opcodes[9];
		case L4_L3_OPCODE_GET_MEDIA_STATUS:
			return L4Opcodes[10];
		case L4_L3_OPCODE_GET_TRACE_SEVERITY_TABLE:
			return L4Opcodes[11];
		case L4_L3_OPCODE_GET_MONITOR_FILTER_TABLE:
			return L4Opcodes[12];
		case L4_L3_OPCODE_SET_TRACE_SEVERITY_TABLE:
			return L4Opcodes[14];
		case L4_L3_OPCODE_SET_MONITOR_FILTER_TABLE:
			return L4Opcodes[15];
		case L4_L3_OPCODE_CMD_RF_CONTROL:
			return L4Opcodes[16];
		case L4_L3_OPCODE_CMD_SCAN:
			return L4Opcodes[17];
		case L4_L3_OPCODE_CMD_CONNECT:
			return L4Opcodes[18];
		case L4_L3_OPCODE_CMD_DISCONNECT:
			return L4Opcodes[19];
		case L4_L3_OPCODE_SET_SCAN_PARAM:	
			return L4Opcodes[20];
		case L4_L3_OPCODE_GET_SCAN_RESULT:
			return L4Opcodes[21];
		case L4_L3_OPCODE_CMD_SEND_EAP_RESPONSE:
			return L4Opcodes[22];
		case L4_L3_OPCODE_SET_EAP_SUCCESS:
			return L4Opcodes[23];
		case L4_L3_OPCODE_SET_EAP_FAIL:	
			return L4Opcodes[24];
		case L4_L3_OPCODE_SET_EAP_KEY:		
			return L4Opcodes[25];
		case L4_PRODUCTION_OPCODE_CMD_START_PHY_RXTX_TEST:
			return L4Opcodes[26];
		case L4_PRODUCTION_OPCODE_CMD_STOP_PHY_TEST:			
			return L4Opcodes[27];
		case L4_PRODUCTION_OPCODE_CMD_PHY_METRICS_CONFIG:
			return L4Opcodes[28];
		case L4_PRODUCTION_OPCODE_CMD_START_PHY_INIT_CALIBRATION_TEST:
			return L4Opcodes[29];
		case L4_PRODUCTION_OPCODE_CMD_START_PHY_MAIN_CALIBRATION_TEST:
			return L4Opcodes[30];
		case L4_PRODUCTION_OPCODE_CMD_PHY_COUNTERS_RESET_ORDER:
			return L4Opcodes[31];
		case L4_PRODUCTION_OPCODE_CMD_NVM_WRITE:		
			return L4Opcodes[32];
		case L4_PRODUCTION_OPCODE_CMD_NVM_READ:			
			return L4Opcodes[33];
		case L4_PRODUCTION_OPCODE_SET_GPIO:			
			return L4Opcodes[34];
		case L4_PRODUCTION_OPCODE_GET_PHY_METRICS:
			return L4Opcodes[35];
		case L4_PRODUCTION_OPCODE_GET_PHY_TEMPRATURE:
			return L4Opcodes[36];
		case L4_PRODUCTION_OPCODE_GET_PHY_DIUC_CONFIGURATION:
			return L4Opcodes[37];
		case L4_PRODUCTION_OPCODE_GET_PHY_UIUC_CONFIGURATION:	
			return L4Opcodes[38];
		case L4_PRODUCTION_OPCODE_GET_GPIO:
			return L4Opcodes[39];
		case L4_PRODUCTION_OPCODE_SET_PHY_TPC_CONFIG:
			return L4Opcodes[40];
		case L4_L3_OPCODE_CMD_MOC_REQUEST:
			return L4Opcodes[41];
		case L4_L3_OPCODE_CMD_CHECK_INTERFACE:
			return L4Opcodes[42];
		case L4_L3_OPCODE_GET_DEBUG_LOOPBACK:
			return L4Opcodes[43];
		case L4_L3_OPCODE_GET_CHECK_INTERFACE:
			return L4Opcodes[44];
		case L4_L3_OPCODE_SET_CHECK_INTERFACE:
			return L4Opcodes[45];
			
	}

	return "L4_L3_UNKNOWN";
}
