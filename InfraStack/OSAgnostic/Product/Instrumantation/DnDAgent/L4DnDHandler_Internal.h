/**************************************************************************
 Copyright (c) 2007-2008, Intel Corporation. All rights reserved.

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
#ifndef _L4_DND_HANDLER_INTERNAL
#define _L4_DND_HANDLER_INTERNAL

void L4DnDHndlr_Init();
void L4DnDHandlr_Finalize();

//	buff - [IN]The monitor buffer to set
//  length - [IN]The length of the buffer
BOOL L4DnDHandlr_SetMonitorFilter(UINT8* buff, UINT32 length);

//	buff - [OUT]The buffer of the current monitor filter. Memory allocated by user
//  length - [IN,OUT]The size of the buffer allocated. Returns the actual size returned
BOOL L4DnDHandlr_GetMonitorFilter(UINT8* buff, UINT32* length);
void L4DnDHandlr_SetMonitorControl(BOOL setToOn);

void UpdateHeader(UINT8* header, UINT16 type, UINT16 length);
void UpdateTraceHeader(UINT16 type, UINT16 length);

#endif //_L4_DND_HANDLER_INTERNAL