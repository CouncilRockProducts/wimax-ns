/*****************************************************************************
 * Automatically generated by Bitman2Base V4.2.5.0 (5.0) Bitman2 (exe) V4.2.5.0 (5.0) - DO NOT EDIT!
 * Generated at 11/19/2009 12:56:05 AM
 *
 * Project : Ofer
 * Module  : Trace Modules Definition
 * Author  : Yakir Green
 * Date    : 19/10/2005
 * Purpose : MOC task over socket descriptor
 *****************************************************************************/

#if !defined(_BITMAN_APPLICATIONMOCTASKDESC_H_)
#define _BITMAN_APPLICATIONMOCTASKDESC_H_


/*lint ++flb */
// Include the Bitman common header file
#include "BitmanCommon.h"

// Include headers generated from XMLs (the source is both XMLs and the command-line)

// Include user C header files

// Include user C header files (supplied in the command-line)


// Bitman version Accessor...
#ifndef BM_BITMAN_VERSION
#define BM_BITMAN_VERSION 	"Bitman2Base V4.2.5.0 (5.0) Bitman2 (exe) V4.2.5.0 (5.0)"
#endif 

// Definitions

typedef UINT8 MocOverSocket[16];

/*lint -save -e806 */ /* Small bit field is signed rather than unsigned*/
#ifdef BMI_ENDIANNESS_LITTLE
#if (!defined __arm && !defined __arc)
#pragma pack( push, 1 )
#endif
#ifdef __arm
typedef __packed struct
#elif defined __arc
typedef _Packed struct
#else
typedef struct
#endif
{
	UINT32 _TaskID; //Task ID
	UINT32 _TaskDataLength; //Task data length
	UINT32 _Param4; //Param 4 of MOC task
	UINT32 _IsParam4ReturnTui; //Is Param4 a Return Tui
} BMS_MocOverSocket;

#if (!defined __arm && !defined __arc)
#pragma pack( pop )
#endif

#else /* BMI_ENDIANNESS_BIG */
#if (!defined __arm && !defined __arc)
#pragma pack( push, 1 )
#endif
#ifdef __arm
typedef __packed struct
#elif defined __arc
typedef _Packed struct
#else
typedef struct
#endif
{
	UINT32 _IsParam4ReturnTui; //Is Param4 a Return Tui
	UINT32 _Param4; //Param 4 of MOC task
	UINT32 _TaskDataLength; //Task data length
	UINT32 _TaskID; //Task ID
} BMS_MocOverSocket;

#if (!defined __arm && !defined __arc)
#pragma pack( pop )
#endif

#endif	/*#ifdef BMI_ENDIANNESS_LITTLE*/
/*lint -restore */

// COMPOSITE: Full name: 'MocOverSocket' Type: 'MocOverSocket', Top-level, Non-instance, No bitoff root
#define BM_MocOverSocket_TaskID_GET_POS( base_ptr, out_ptr, out_bitoff )\
{\
	/*lint --e{*} */\
	out_ptr = base_ptr;\
	out_bitoff = 0;\
}

#define BM_MocOverSocket_TaskID_GET_POS_ALIGNED( base_ptr, out_ptr )\
{\
	/*lint --e{*} */\
	UINT bmlocal0_tmp_bitoff;\
	BM_MocOverSocket_TaskID_GET_POS( base_ptr, out_ptr, bmlocal0_tmp_bitoff );\
	BMI_NORMALIZE_BITOFF(out_ptr, bmlocal0_tmp_bitoff);\
}

#define BM_MocOverSocket_TaskID_POS_ALIGNED 0

// Alignment of MocOverSocket_TaskID: accumulated=(0,0, ABA=4), parent.base=(0,0, ABA=4)
#define BM_MocOverSocket_TaskID_GET_SIZE( base_ptr, out_bytes, out_bits )\
{\
	/*lint --e{*} */\
	out_bytes = 4;\
	out_bits = 0;\
	BMI_UNUSED_VAR( base_ptr );\
}

#define BM_MocOverSocket_TaskID_GET( base_ptr, out_val )\
{\
	/*lint --e{*} */\
	PVOID bmlocal1_my_ptr;\
	UINT bmlocal2_my_bitoff;\
	BM_MocOverSocket_TaskID_GET_POS( base_ptr, bmlocal1_my_ptr, bmlocal2_my_bitoff );\
	if( BMI_MACHINE_ARM_LITTLE == BMI_MACHINE_VALUE )\
	{\
		(out_val) = (UINT32)BMI_32BIT_EXTRACT( (BMI_GET_32BIT_PTR_CONTENTS_VOLATILE( BMI_PTR_TO_NUMERIC_CAST(bmlocal1_my_ptr)) ), 0, 32, 0);\
	}\
	else if( BMI_MACHINE_INTEL_LITTLE == BMI_MACHINE_VALUE )\
	{\
		(out_val) = (UINT32)BMI_32BIT_EXTRACT( (BMI_GET_32BIT_PTR_CONTENTS_VOLATILE( BMI_PTR_TO_NUMERIC_CAST(bmlocal1_my_ptr)) ), 0, 32, 0);\
	}\
	else\
	{\
		BMI_GENERIC_32BIT_LITTLE_GET_VOLATILE( bmlocal1_my_ptr, bmlocal2_my_bitoff, 32, UINT32, out_val, 0x00000000 );\
	}\
}

BMI_INLINE UINT32 BM_INLINE_MocOverSocket_TaskID_GET(PVOID base_ptr)
{
	/*lint --e{*} */
	UINT32 bmlocal3_tmp_var;
	BM_MocOverSocket_TaskID_GET( base_ptr, bmlocal3_tmp_var );
	return bmlocal3_tmp_var;
}

#define BM_MocOverSocket_TaskID_SET( base_ptr, in_val )\
{\
	/*lint --e{*} */\
	PVOID bmlocal4_my_ptr;\
	UINT bmlocal5_my_bitoff;\
	BM_MocOverSocket_TaskID_GET_POS( base_ptr, bmlocal4_my_ptr, bmlocal5_my_bitoff );\
	if( BMI_MACHINE_ARM_LITTLE == BMI_MACHINE_VALUE )\
	{\
		BMI_32BIT_CLEAR_ASSIGN_TYPE( BMI_GET_32BIT_PTR_CONTENTS_VOLATILE( BMI_PTR_TO_NUMERIC_CAST(bmlocal4_my_ptr) ), (in_val), 0, 0, 32, UINT32 );\
	}\
	else if( BMI_MACHINE_INTEL_LITTLE == BMI_MACHINE_VALUE )\
	{\
		BMI_32BIT_CLEAR_ASSIGN_TYPE( BMI_GET_32BIT_PTR_CONTENTS_VOLATILE( BMI_PTR_TO_NUMERIC_CAST(bmlocal4_my_ptr) ), (in_val), 0, 0, 32, UINT32 );\
	}\
	else\
	{\
		BMI_GENERIC_32BIT_LITTLE_SET_VOLATILE( bmlocal4_my_ptr, bmlocal5_my_bitoff, 32, in_val, 0x00000000 );\
	}\
}

// MocOverSocket_TaskID: IS_DEFAULT accessor is not defined because no default value was specified.
// MocOverSocket_TaskID: SET_DEFAULT accessor is not defined because no default value was specified.
// MocOverSocket_TaskID: IS_RESET accessor is not defined because no reset value was specified.
// MocOverSocket_TaskID: SET_RESET accessor is not defined because no reset value was specified.
// MocOverSocket_TaskID: CLEAR accessor is not defined because of incompatible access rights. Specified: RW Required: W1C, WO1C.
// MocOverSocket_TaskID: SET(W1S) accessor is not defined because of incompatible access rights. Specified: RW Required: W1S, WO1S.
#define BM_MocOverSocket_TaskID_DUMP_DEPTH( base_ptr, depth )\
{\
	/*lint --e{*} */\
	UINT32 bmlocal6_out_val;\
	BM_MocOverSocket_TaskID_GET( base_ptr, bmlocal6_out_val );\
	/*lint -e(571) */\
	BMI_FORMAT_DUMP(depth, "TaskID", 32, (UINT)(bmlocal6_out_val), "%d", 1);\
}

#define BM_MocOverSocket_TaskID_DUMP( base_ptr )\
{\
	/*lint --e{*} */\
	BM_MocOverSocket_TaskID_DUMP_DEPTH( base_ptr, 0 );\
}

#define BM_MocOverSocket_TaskID_INCREMENT( base_ptr )\
{\
	/*lint --e{*} */\
	PVOID bmlocal7_my_ptr;\
	UINT bmlocal8_my_bitoff;\
	BM_MocOverSocket_TaskID_GET_POS( base_ptr, bmlocal7_my_ptr, bmlocal8_my_bitoff );\
	(*((UINT32*)bmlocal7_my_ptr))++;\
	BMI_UNUSED_VAR( bmlocal8_my_bitoff );\
}

// MocOverSocket_TaskID: Validation accessors are not defined because validation condition was not specified.
#define BM_MocOverSocket_TaskID_GET_BYTES_SIZE( base_ptr, out_bytes )\
{\
	/*lint --e{*} */\
	UINT bmlocal9_tmp_bits;\
	BM_MocOverSocket_TaskID_GET_SIZE( base_ptr, out_bytes, bmlocal9_tmp_bits );\
	BMI_ROUND_UP_1BYTES( out_bytes, bmlocal9_tmp_bits );\
}

#define BM_MocOverSocket_TaskID_BYTES_SIZE 4

#define BM_MocOverSocket_TaskDataLength_GET_POS( base_ptr, out_ptr, out_bitoff )\
{\
	/*lint --e{*} */\
	UINT bmlocal12_acc_bytes;\
	UINT bmlocal13_acc_bits;\
	out_ptr = base_ptr;\
	out_bitoff = 0;\
	bmlocal12_acc_bytes = 4;\
	bmlocal13_acc_bits = 0;\
	BMI_ADD_ASSIGN_PTR( out_ptr, bmlocal12_acc_bytes );\
	out_bitoff += bmlocal13_acc_bits;\
}

#define BM_MocOverSocket_TaskDataLength_GET_POS_ALIGNED( base_ptr, out_ptr )\
{\
	/*lint --e{*} */\
	UINT bmlocal14_tmp_bitoff;\
	BM_MocOverSocket_TaskDataLength_GET_POS( base_ptr, out_ptr, bmlocal14_tmp_bitoff );\
	BMI_NORMALIZE_BITOFF(out_ptr, bmlocal14_tmp_bitoff);\
}

#define BM_MocOverSocket_TaskDataLength_POS_ALIGNED 4

// Alignment of MocOverSocket_TaskDataLength: accumulated=(0,0, ABA=4), parent.base=(0,0, ABA=4)
#define BM_MocOverSocket_TaskDataLength_GET_SIZE( base_ptr, out_bytes, out_bits )\
{\
	/*lint --e{*} */\
	out_bytes = 4;\
	out_bits = 0;\
	BMI_UNUSED_VAR( base_ptr );\
}

#define BM_MocOverSocket_TaskDataLength_GET( base_ptr, out_val )\
{\
	/*lint --e{*} */\
	PVOID bmlocal15_my_ptr;\
	UINT bmlocal16_my_bitoff;\
	BM_MocOverSocket_TaskDataLength_GET_POS( base_ptr, bmlocal15_my_ptr, bmlocal16_my_bitoff );\
	if( BMI_MACHINE_ARM_LITTLE == BMI_MACHINE_VALUE )\
	{\
		(out_val) = (UINT32)BMI_32BIT_EXTRACT( (BMI_GET_32BIT_PTR_CONTENTS_VOLATILE( BMI_PTR_TO_NUMERIC_CAST(bmlocal15_my_ptr)) ), 0, 32, 0);\
	}\
	else if( BMI_MACHINE_INTEL_LITTLE == BMI_MACHINE_VALUE )\
	{\
		(out_val) = (UINT32)BMI_32BIT_EXTRACT( (BMI_GET_32BIT_PTR_CONTENTS_VOLATILE( BMI_PTR_TO_NUMERIC_CAST(bmlocal15_my_ptr)) ), 0, 32, 0);\
	}\
	else\
	{\
		BMI_GENERIC_32BIT_LITTLE_GET_VOLATILE( bmlocal15_my_ptr, bmlocal16_my_bitoff, 32, UINT32, out_val, 0x00000000 );\
	}\
}

BMI_INLINE UINT32 BM_INLINE_MocOverSocket_TaskDataLength_GET(PVOID base_ptr)
{
	/*lint --e{*} */
	UINT32 bmlocal17_tmp_var;
	BM_MocOverSocket_TaskDataLength_GET( base_ptr, bmlocal17_tmp_var );
	return bmlocal17_tmp_var;
}

#define BM_MocOverSocket_TaskDataLength_SET( base_ptr, in_val )\
{\
	/*lint --e{*} */\
	PVOID bmlocal18_my_ptr;\
	UINT bmlocal19_my_bitoff;\
	BM_MocOverSocket_TaskDataLength_GET_POS( base_ptr, bmlocal18_my_ptr, bmlocal19_my_bitoff );\
	if( BMI_MACHINE_ARM_LITTLE == BMI_MACHINE_VALUE )\
	{\
		BMI_32BIT_CLEAR_ASSIGN_TYPE( BMI_GET_32BIT_PTR_CONTENTS_VOLATILE( BMI_PTR_TO_NUMERIC_CAST(bmlocal18_my_ptr) ), (in_val), 0, 0, 32, UINT32 );\
	}\
	else if( BMI_MACHINE_INTEL_LITTLE == BMI_MACHINE_VALUE )\
	{\
		BMI_32BIT_CLEAR_ASSIGN_TYPE( BMI_GET_32BIT_PTR_CONTENTS_VOLATILE( BMI_PTR_TO_NUMERIC_CAST(bmlocal18_my_ptr) ), (in_val), 0, 0, 32, UINT32 );\
	}\
	else\
	{\
		BMI_GENERIC_32BIT_LITTLE_SET_VOLATILE( bmlocal18_my_ptr, bmlocal19_my_bitoff, 32, in_val, 0x00000000 );\
	}\
}

// MocOverSocket_TaskDataLength: IS_DEFAULT accessor is not defined because no default value was specified.
// MocOverSocket_TaskDataLength: SET_DEFAULT accessor is not defined because no default value was specified.
// MocOverSocket_TaskDataLength: IS_RESET accessor is not defined because no reset value was specified.
// MocOverSocket_TaskDataLength: SET_RESET accessor is not defined because no reset value was specified.
// MocOverSocket_TaskDataLength: CLEAR accessor is not defined because of incompatible access rights. Specified: RW Required: W1C, WO1C.
// MocOverSocket_TaskDataLength: SET(W1S) accessor is not defined because of incompatible access rights. Specified: RW Required: W1S, WO1S.
#define BM_MocOverSocket_TaskDataLength_DUMP_DEPTH( base_ptr, depth )\
{\
	/*lint --e{*} */\
	UINT32 bmlocal20_out_val;\
	BM_MocOverSocket_TaskDataLength_GET( base_ptr, bmlocal20_out_val );\
	/*lint -e(571) */\
	BMI_FORMAT_DUMP(depth, "TaskDataLength", 32, (UINT)(bmlocal20_out_val), "%d", 1);\
}

#define BM_MocOverSocket_TaskDataLength_DUMP( base_ptr )\
{\
	/*lint --e{*} */\
	BM_MocOverSocket_TaskDataLength_DUMP_DEPTH( base_ptr, 0 );\
}

#define BM_MocOverSocket_TaskDataLength_INCREMENT( base_ptr )\
{\
	/*lint --e{*} */\
	PVOID bmlocal21_my_ptr;\
	UINT bmlocal22_my_bitoff;\
	BM_MocOverSocket_TaskDataLength_GET_POS( base_ptr, bmlocal21_my_ptr, bmlocal22_my_bitoff );\
	(*((UINT32*)bmlocal21_my_ptr))++;\
	BMI_UNUSED_VAR( bmlocal22_my_bitoff );\
}

// MocOverSocket_TaskDataLength: Validation accessors are not defined because validation condition was not specified.
#define BM_MocOverSocket_TaskDataLength_GET_BYTES_SIZE( base_ptr, out_bytes )\
{\
	/*lint --e{*} */\
	UINT bmlocal23_tmp_bits;\
	BM_MocOverSocket_TaskDataLength_GET_SIZE( base_ptr, out_bytes, bmlocal23_tmp_bits );\
	BMI_ROUND_UP_1BYTES( out_bytes, bmlocal23_tmp_bits );\
}

#define BM_MocOverSocket_TaskDataLength_BYTES_SIZE 4

#define BM_MocOverSocket_Param4_GET_POS( base_ptr, out_ptr, out_bitoff )\
{\
	/*lint --e{*} */\
	UINT bmlocal26_acc_bytes;\
	UINT bmlocal27_acc_bits;\
	out_ptr = base_ptr;\
	out_bitoff = 0;\
	bmlocal26_acc_bytes = 8;\
	bmlocal27_acc_bits = 0;\
	BMI_ADD_ASSIGN_PTR( out_ptr, bmlocal26_acc_bytes );\
	out_bitoff += bmlocal27_acc_bits;\
}

#define BM_MocOverSocket_Param4_GET_POS_ALIGNED( base_ptr, out_ptr )\
{\
	/*lint --e{*} */\
	UINT bmlocal28_tmp_bitoff;\
	BM_MocOverSocket_Param4_GET_POS( base_ptr, out_ptr, bmlocal28_tmp_bitoff );\
	BMI_NORMALIZE_BITOFF(out_ptr, bmlocal28_tmp_bitoff);\
}

#define BM_MocOverSocket_Param4_POS_ALIGNED 8

// Alignment of MocOverSocket_Param4: accumulated=(0,0, ABA=4), parent.base=(0,0, ABA=4)
#define BM_MocOverSocket_Param4_GET_SIZE( base_ptr, out_bytes, out_bits )\
{\
	/*lint --e{*} */\
	out_bytes = 4;\
	out_bits = 0;\
	BMI_UNUSED_VAR( base_ptr );\
}

#define BM_MocOverSocket_Param4_GET( base_ptr, out_val )\
{\
	/*lint --e{*} */\
	PVOID bmlocal29_my_ptr;\
	UINT bmlocal30_my_bitoff;\
	BM_MocOverSocket_Param4_GET_POS( base_ptr, bmlocal29_my_ptr, bmlocal30_my_bitoff );\
	if( BMI_MACHINE_ARM_LITTLE == BMI_MACHINE_VALUE )\
	{\
		(out_val) = (UINT32)BMI_32BIT_EXTRACT( (BMI_GET_32BIT_PTR_CONTENTS_VOLATILE( BMI_PTR_TO_NUMERIC_CAST(bmlocal29_my_ptr)) ), 0, 32, 0);\
	}\
	else if( BMI_MACHINE_INTEL_LITTLE == BMI_MACHINE_VALUE )\
	{\
		(out_val) = (UINT32)BMI_32BIT_EXTRACT( (BMI_GET_32BIT_PTR_CONTENTS_VOLATILE( BMI_PTR_TO_NUMERIC_CAST(bmlocal29_my_ptr)) ), 0, 32, 0);\
	}\
	else\
	{\
		BMI_GENERIC_32BIT_LITTLE_GET_VOLATILE( bmlocal29_my_ptr, bmlocal30_my_bitoff, 32, UINT32, out_val, 0x00000000 );\
	}\
}

BMI_INLINE UINT32 BM_INLINE_MocOverSocket_Param4_GET(PVOID base_ptr)
{
	/*lint --e{*} */
	UINT32 bmlocal31_tmp_var;
	BM_MocOverSocket_Param4_GET( base_ptr, bmlocal31_tmp_var );
	return bmlocal31_tmp_var;
}

#define BM_MocOverSocket_Param4_SET( base_ptr, in_val )\
{\
	/*lint --e{*} */\
	PVOID bmlocal32_my_ptr;\
	UINT bmlocal33_my_bitoff;\
	BM_MocOverSocket_Param4_GET_POS( base_ptr, bmlocal32_my_ptr, bmlocal33_my_bitoff );\
	if( BMI_MACHINE_ARM_LITTLE == BMI_MACHINE_VALUE )\
	{\
		BMI_32BIT_CLEAR_ASSIGN_TYPE( BMI_GET_32BIT_PTR_CONTENTS_VOLATILE( BMI_PTR_TO_NUMERIC_CAST(bmlocal32_my_ptr) ), (in_val), 0, 0, 32, UINT32 );\
	}\
	else if( BMI_MACHINE_INTEL_LITTLE == BMI_MACHINE_VALUE )\
	{\
		BMI_32BIT_CLEAR_ASSIGN_TYPE( BMI_GET_32BIT_PTR_CONTENTS_VOLATILE( BMI_PTR_TO_NUMERIC_CAST(bmlocal32_my_ptr) ), (in_val), 0, 0, 32, UINT32 );\
	}\
	else\
	{\
		BMI_GENERIC_32BIT_LITTLE_SET_VOLATILE( bmlocal32_my_ptr, bmlocal33_my_bitoff, 32, in_val, 0x00000000 );\
	}\
}

// MocOverSocket_Param4: IS_DEFAULT accessor is not defined because no default value was specified.
// MocOverSocket_Param4: SET_DEFAULT accessor is not defined because no default value was specified.
// MocOverSocket_Param4: IS_RESET accessor is not defined because no reset value was specified.
// MocOverSocket_Param4: SET_RESET accessor is not defined because no reset value was specified.
// MocOverSocket_Param4: CLEAR accessor is not defined because of incompatible access rights. Specified: RW Required: W1C, WO1C.
// MocOverSocket_Param4: SET(W1S) accessor is not defined because of incompatible access rights. Specified: RW Required: W1S, WO1S.
#define BM_MocOverSocket_Param4_DUMP_DEPTH( base_ptr, depth )\
{\
	/*lint --e{*} */\
	UINT32 bmlocal34_out_val;\
	BM_MocOverSocket_Param4_GET( base_ptr, bmlocal34_out_val );\
	/*lint -e(571) */\
	BMI_FORMAT_DUMP(depth, "Param4", 32, (UINT)(bmlocal34_out_val), "%d", 1);\
}

#define BM_MocOverSocket_Param4_DUMP( base_ptr )\
{\
	/*lint --e{*} */\
	BM_MocOverSocket_Param4_DUMP_DEPTH( base_ptr, 0 );\
}

#define BM_MocOverSocket_Param4_INCREMENT( base_ptr )\
{\
	/*lint --e{*} */\
	PVOID bmlocal35_my_ptr;\
	UINT bmlocal36_my_bitoff;\
	BM_MocOverSocket_Param4_GET_POS( base_ptr, bmlocal35_my_ptr, bmlocal36_my_bitoff );\
	(*((UINT32*)bmlocal35_my_ptr))++;\
	BMI_UNUSED_VAR( bmlocal36_my_bitoff );\
}

// MocOverSocket_Param4: Validation accessors are not defined because validation condition was not specified.
#define BM_MocOverSocket_Param4_GET_BYTES_SIZE( base_ptr, out_bytes )\
{\
	/*lint --e{*} */\
	UINT bmlocal37_tmp_bits;\
	BM_MocOverSocket_Param4_GET_SIZE( base_ptr, out_bytes, bmlocal37_tmp_bits );\
	BMI_ROUND_UP_1BYTES( out_bytes, bmlocal37_tmp_bits );\
}

#define BM_MocOverSocket_Param4_BYTES_SIZE 4

#define BM_MocOverSocket_IsParam4ReturnTui_GET_POS( base_ptr, out_ptr, out_bitoff )\
{\
	/*lint --e{*} */\
	UINT bmlocal40_acc_bytes;\
	UINT bmlocal41_acc_bits;\
	out_ptr = base_ptr;\
	out_bitoff = 0;\
	bmlocal40_acc_bytes = 12;\
	bmlocal41_acc_bits = 0;\
	BMI_ADD_ASSIGN_PTR( out_ptr, bmlocal40_acc_bytes );\
	out_bitoff += bmlocal41_acc_bits;\
}

#define BM_MocOverSocket_IsParam4ReturnTui_GET_POS_ALIGNED( base_ptr, out_ptr )\
{\
	/*lint --e{*} */\
	UINT bmlocal42_tmp_bitoff;\
	BM_MocOverSocket_IsParam4ReturnTui_GET_POS( base_ptr, out_ptr, bmlocal42_tmp_bitoff );\
	BMI_NORMALIZE_BITOFF(out_ptr, bmlocal42_tmp_bitoff);\
}

#define BM_MocOverSocket_IsParam4ReturnTui_POS_ALIGNED 12

// Alignment of MocOverSocket_IsParam4ReturnTui: accumulated=(0,0, ABA=4), parent.base=(0,0, ABA=4)
#define BM_MocOverSocket_IsParam4ReturnTui_GET_SIZE( base_ptr, out_bytes, out_bits )\
{\
	/*lint --e{*} */\
	out_bytes = 4;\
	out_bits = 0;\
	BMI_UNUSED_VAR( base_ptr );\
}

#define BM_MocOverSocket_IsParam4ReturnTui_GET( base_ptr, out_val )\
{\
	/*lint --e{*} */\
	PVOID bmlocal43_my_ptr;\
	UINT bmlocal44_my_bitoff;\
	BM_MocOverSocket_IsParam4ReturnTui_GET_POS( base_ptr, bmlocal43_my_ptr, bmlocal44_my_bitoff );\
	if( BMI_MACHINE_ARM_LITTLE == BMI_MACHINE_VALUE )\
	{\
		(out_val) = (UINT32)BMI_32BIT_EXTRACT( (BMI_GET_32BIT_PTR_CONTENTS_VOLATILE( BMI_PTR_TO_NUMERIC_CAST(bmlocal43_my_ptr)) ), 0, 32, 0);\
	}\
	else if( BMI_MACHINE_INTEL_LITTLE == BMI_MACHINE_VALUE )\
	{\
		(out_val) = (UINT32)BMI_32BIT_EXTRACT( (BMI_GET_32BIT_PTR_CONTENTS_VOLATILE( BMI_PTR_TO_NUMERIC_CAST(bmlocal43_my_ptr)) ), 0, 32, 0);\
	}\
	else\
	{\
		BMI_GENERIC_32BIT_LITTLE_GET_VOLATILE( bmlocal43_my_ptr, bmlocal44_my_bitoff, 32, UINT32, out_val, 0x00000000 );\
	}\
}

BMI_INLINE UINT32 BM_INLINE_MocOverSocket_IsParam4ReturnTui_GET(PVOID base_ptr)
{
	/*lint --e{*} */
	UINT32 bmlocal45_tmp_var;
	BM_MocOverSocket_IsParam4ReturnTui_GET( base_ptr, bmlocal45_tmp_var );
	return bmlocal45_tmp_var;
}

#define BM_MocOverSocket_IsParam4ReturnTui_SET( base_ptr, in_val )\
{\
	/*lint --e{*} */\
	PVOID bmlocal46_my_ptr;\
	UINT bmlocal47_my_bitoff;\
	BM_MocOverSocket_IsParam4ReturnTui_GET_POS( base_ptr, bmlocal46_my_ptr, bmlocal47_my_bitoff );\
	if( BMI_MACHINE_ARM_LITTLE == BMI_MACHINE_VALUE )\
	{\
		BMI_32BIT_CLEAR_ASSIGN_TYPE( BMI_GET_32BIT_PTR_CONTENTS_VOLATILE( BMI_PTR_TO_NUMERIC_CAST(bmlocal46_my_ptr) ), (in_val), 0, 0, 32, UINT32 );\
	}\
	else if( BMI_MACHINE_INTEL_LITTLE == BMI_MACHINE_VALUE )\
	{\
		BMI_32BIT_CLEAR_ASSIGN_TYPE( BMI_GET_32BIT_PTR_CONTENTS_VOLATILE( BMI_PTR_TO_NUMERIC_CAST(bmlocal46_my_ptr) ), (in_val), 0, 0, 32, UINT32 );\
	}\
	else\
	{\
		BMI_GENERIC_32BIT_LITTLE_SET_VOLATILE( bmlocal46_my_ptr, bmlocal47_my_bitoff, 32, in_val, 0x00000000 );\
	}\
}

// MocOverSocket_IsParam4ReturnTui: IS_DEFAULT accessor is not defined because no default value was specified.
// MocOverSocket_IsParam4ReturnTui: SET_DEFAULT accessor is not defined because no default value was specified.
// MocOverSocket_IsParam4ReturnTui: IS_RESET accessor is not defined because no reset value was specified.
// MocOverSocket_IsParam4ReturnTui: SET_RESET accessor is not defined because no reset value was specified.
// MocOverSocket_IsParam4ReturnTui: CLEAR accessor is not defined because of incompatible access rights. Specified: RW Required: W1C, WO1C.
// MocOverSocket_IsParam4ReturnTui: SET(W1S) accessor is not defined because of incompatible access rights. Specified: RW Required: W1S, WO1S.
#define BM_MocOverSocket_IsParam4ReturnTui_DUMP_DEPTH( base_ptr, depth )\
{\
	/*lint --e{*} */\
	UINT32 bmlocal48_out_val;\
	BM_MocOverSocket_IsParam4ReturnTui_GET( base_ptr, bmlocal48_out_val );\
	/*lint -e(571) */\
	BMI_FORMAT_DUMP(depth, "IsParam4ReturnTui", 32, (UINT)(bmlocal48_out_val), "%d", 1);\
}

#define BM_MocOverSocket_IsParam4ReturnTui_DUMP( base_ptr )\
{\
	/*lint --e{*} */\
	BM_MocOverSocket_IsParam4ReturnTui_DUMP_DEPTH( base_ptr, 0 );\
}

#define BM_MocOverSocket_IsParam4ReturnTui_INCREMENT( base_ptr )\
{\
	/*lint --e{*} */\
	PVOID bmlocal49_my_ptr;\
	UINT bmlocal50_my_bitoff;\
	BM_MocOverSocket_IsParam4ReturnTui_GET_POS( base_ptr, bmlocal49_my_ptr, bmlocal50_my_bitoff );\
	(*((UINT32*)bmlocal49_my_ptr))++;\
	BMI_UNUSED_VAR( bmlocal50_my_bitoff );\
}

// MocOverSocket_IsParam4ReturnTui: Validation accessors are not defined because validation condition was not specified.
#define BM_MocOverSocket_IsParam4ReturnTui_GET_BYTES_SIZE( base_ptr, out_bytes )\
{\
	/*lint --e{*} */\
	UINT bmlocal51_tmp_bits;\
	BM_MocOverSocket_IsParam4ReturnTui_GET_SIZE( base_ptr, out_bytes, bmlocal51_tmp_bits );\
	BMI_ROUND_UP_1BYTES( out_bytes, bmlocal51_tmp_bits );\
}

#define BM_MocOverSocket_IsParam4ReturnTui_BYTES_SIZE 4

#define BM_MocOverSocket_GET_SIZE( base_ptr, out_bytes, out_bits )\
{\
	/*lint --e{*} */\
	out_bytes = 16;\
	out_bits = 0;\
	BMI_UNUSED_VAR( base_ptr );\
}

#define BM_MocOverSocket_GET_BYTES_SIZE( base_ptr, out_bytes )\
{\
	/*lint --e{*} */\
	UINT bmlocal54_tmp_bits;\
	BM_MocOverSocket_GET_SIZE( base_ptr, out_bytes, bmlocal54_tmp_bits );\
	BMI_ROUND_UP_1BYTES( out_bytes, bmlocal54_tmp_bits );\
}

#define BM_MocOverSocket_BYTES_SIZE 16

#define BM_MocOverSocket_DUMP_DEPTH( base_ptr, depth )\
{\
	/*lint --e{*} */\
	BMI_FORMAT_NONVALUE_DUMP(depth, "MocOverSocket", 1);\
	BM_MocOverSocket_TaskID_DUMP_DEPTH( base_ptr, (depth + 1) );\
	BM_MocOverSocket_TaskDataLength_DUMP_DEPTH( base_ptr, (depth + 1) );\
	BM_MocOverSocket_Param4_DUMP_DEPTH( base_ptr, (depth + 1) );\
	BM_MocOverSocket_IsParam4ReturnTui_DUMP_DEPTH( base_ptr, (depth + 1) );\
	BMI_UNUSED_VAR( base_ptr );\
}

#define BM_MocOverSocket_DUMP( base_ptr )\
{\
	/*lint --e{*} */\
	BM_MocOverSocket_DUMP_DEPTH( base_ptr, 0 );\
}


/*lint --flb */

#endif /* _BITMAN_APPLICATIONMOCTASKDESC_H_ */
