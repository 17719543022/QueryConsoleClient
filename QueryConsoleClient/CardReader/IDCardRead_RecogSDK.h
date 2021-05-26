//////////////////////////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE  
/// Copyright(c)2019,中科院重庆研究院智能安全技术研究中心  （版权声明）  
/// All rights reserved.  
/// \file IDCardRead_RecogSDK.h 
/// \brief 身份证、护照、港澳通行证阅读器 SDK封装
/// \detail 为兼容各个厂家的阅读器，将各个厂家的SDK进行封装，形成统一的出口供上层应用调用
///         目前支持 中安未来KR220 证件OCR识别、身份证读取；精伦idr210 身份证读取.支持设备掉电后自动重连设备
/// \author plusone_chen 
/// \version V1.0(main.min，主版本.分版本格式)  
/// \date 2019/12/20 
//////////////////////////////////////////////////////////////////////////////////////////////

#ifndef IDCardRead_RecogSDK_H
#define IDCardRead_RecogSDK_H

#include "DataStructDefine.h"

#ifdef _WIN32  //Windows平台下
	//#define DLL_CALL __cdecl  //定义函数调用方式
	#ifdef __cplusplus  //C++文件
		#define DLL_EXPORT_C_DECL extern "C" __declspec(dllexport)  //将C++按照C的方式导出dll
		#define DLL_IMPORT_C_DECL extern "C" __declspec(dllimport)  //将C++按照C的方式导入dll
		#define DLL_EXPORT_DECL extern __declspec(dllexport)  //将C++按照C++的方式导出dll
		#define DLL_IMPORT_DECL extern __declspec(dllimport)  //将C++按照C++的方式导入dll
		#define DLL_EXPORT_CLASS_DECL __declspec(dllexport)  //将C++按照C++的方式导出dll
		#define DLL_IMPORT_CLASS_DECL __declspec(dllimport)  //将C++按照C++的方式导入dll
	#else  
		#define DLL_EXPORT_DECL __declspec(dllexport)  //C语言导出
		#define DLL_IMPORT_DECL __declspec(dllimport)  //C语言导入
	#endif  
#else  //其他平台  如：Linux,Arm
	//#define DLL_CALL  //定义函数调用方式 
	#ifdef __cplusplus  
		#define DLL_EXPORT_C_DECL extern "C"  //将C++按照C的方式导出dll
		#define DLL_IMPORT_C_DECL extern "C"  //将C++按照C的方式导入dll
		#define DLL_EXPORT_DECL extern  
		#define DLL_IMPORT_DECL extern  
		#define DLL_EXPORT_CLASS_DECL  
		#define DLL_IMPORT_CLASS_DECL  
	#else  
		#define DLL_EXPORT_DECL extern  //C语言导出
		#define DLL_IMPORT_DECL extern  //C语言导入
	#endif  
#endif 


	/// \breif 初始化设备
	///
	///初始化设备;加载设备核心，设备初始化所需参数，选择设备种类等
	///
	/// \param deviceType[in]-设备类型，0 中安未来 1 精伦
	/// \param deviceParam[in]-传入设备参数，如有多个参数用","区分 。
	/// device=0时,deviceParam="0,1",0-表示识别端口核心编号,1-循环读卡时间间隔;
    /// device=1时,deviceParam = "0",0-表示身份证循环读卡时间间隔;
	/// \return  0:成功  其他:异常.
	/// \note 
	/// \warning 

	DLL_EXPORT_C_DECL int DLL_CALL IDCardSDKInit(DeviceType deviceType,const char* deviceParam);

	/// \breif 设置身份证读卡回调函数
	DLL_EXPORT_C_DECL void DLL_CALL SetIDCardReadCB(IDCardReadCB idCardReadCB,void *userPtr,IDCardReadOnlineCB idCardReadOnlineCB,IDCardReadOfflineCB idCardReadOfflineCB);

	/// \breif 设置护照识别回调函数
	DLL_EXPORT_C_DECL void DLL_CALL SetIDCardRecogCB(IDCardRecogCB idCardRecogCB,void *userPtr,IDCardRecogOnlineCB idCardRecogOnlineCB,IDCardRecogOfflineCB idCardRecogOfflineCB);

	/// \breif 释放对象身份证阅读器内存
	DLL_EXPORT_C_DECL void DLL_CALL IDCardSDKRelease();


#endif










