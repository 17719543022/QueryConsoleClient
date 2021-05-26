//////////////////////////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE  
/// Copyright(c)2019,中科院重庆研究院智能安全技术研究中心  （版权声明）  
/// All rights reserved.  
/// \file DataStructDefine.h 
/// \brief 数据结构
/// \detail 为了调用更加方便，设计回调函数，当阅读器检测合法证件后自动调用回调函数返回对应证件的结构体数据
/// \author plusone_chen 
/// \version V1.0(main.min，主版本.分版本格式)  
/// \date 2019/12/27
//////////////////////////////////////////////////////////////////////////////////////////////

#ifndef DataStructDefine_H
#define DataStructDefine_H

#ifdef _WIN32  //Windows平台下
	#define DLL_CALL __cdecl  //定义函数调用方式
#else
	#define DLL_CALL
#endif

	/// \breif 设备种类  0 中安未来设备  1 精伦设备
	typedef enum DeviceType
	{
		ChinaSafe = 0,  //中安未来
		JingLun = 1     //精伦
	}DeviceType;

	/// \breif 身份证信息
	typedef struct IDCardReadInfos
	{
		int idType;///<breif 身份证类型 0-国人身份证 1-外国人身份证 2-港澳台居住证
		char *name;///< brief 姓名
		char *gender;///< brief 性别 
		char *folk;///< brief 名族
		char *birthDay;///< brief 出生日期
		char *code;///< brief 身份证号
		char *address;///< brief 地址
		char *agency;///< brief 发证机关
		char *expireStart;///< brief 有效期起
		char *expireEnd;///< brief 有效期止

		char *eName;///<breif 英文姓名
		char *prCode;///<breif 永久居住代码
		char *nation;///<breif 国籍或所在地区代码
		char *idVersion;///<breif 证件版本号
		char *agencyCode;///<breif 受理机关代码
	
		IDCardReadInfos()  //数据初始化
		{
			idType = 0;
			name = 0;
			eName = 0;
			gender = 0;
			folk = 0;
			birthDay = 0;
			code = 0;
			address = 0;
			agency = 0;
			expireStart = 0;
			expireEnd = 0;
			prCode = 0;
			nation = 0;
			idVersion = 0;
			agencyCode = 0;

		}
	}IDCardReadInfos;

	///<breif 往来港澳通行证 2014版  分类号：22
	typedef struct HK_MPassPermitInfos
	{
		char *retainedFiele;///<breif 保留字段
		char *code; ///<breif 证件号码
		char *name;///<breif 中文姓名
		char *eName;///<breif 英文姓名
		char *birthDay;///<breif 出生日期
		char *gender;///<breif 性别
		char *expireDate;///< brief 有效期限
		char *issuePlace;///<breif 签发地点
		char *MRZ1;///<breif 第一行MRZ
		char *MRZ2;///<breif 第二行MRZ
		char *MRZ3;///<breif 第三行MRZ
		char *issueDate;///<breif 签发日期
		char *expireEnd;///<breif 有效期至
		HK_MPassPermitInfos()
		{
			retainedFiele = 0;///<breif 保留字段
			code = 0; ///<breif 证件号码
			name = 0;///<breif 中文姓名
			eName = 0;///<breif 英文姓名
			birthDay = 0;///<breif 出生日期
			gender = 0;///<breif 性别
			expireDate = 0;///< brief 有效期限
			issuePlace = 0;///<breif 签发地点
			MRZ1 = 0;///<breif 第一行MRZ
			MRZ2 = 0;///<breif 第二行MRZ
			MRZ3 = 0;///<breif 第三行MRZ
			issueDate = 0;///<breif 签发日期
			expireEnd = 0;///<breif 有效期至
		}

	}HK_MPassPermitInfos;

	///<breif 往来台湾通行证 2017 版-照片页 分类号：29
	typedef struct TaiWanPassPermitInfos
	{
		char *retainedFiele;///<breif 保留字段
		char *code; ///<breif 证件号码
		char *name;///<breif 中文姓名
		char *eName;///<breif 英文姓名
		char *birthDay;///<breif 出生日期
		char *gender;///<breif 性别
		char *expireDate;///< brief 有效期限
		char *issuePlace;///<breif 签发地点
		char *MRZ1;///<breif 第一行MRZ
		char *MRZ2;///<breif 第二行MRZ
		char *MRZ3;///<breif 第三行MRZ
		char *agency;///< brief 发证机关
		TaiWanPassPermitInfos()
		{
			retainedFiele = 0;///<breif 保留字段
			code = 0; ///<breif 证件号码
			name = 0;///<breif 中文姓名
			eName = 0;///<breif 英文姓名
			birthDay = 0;///<breif 出生日期
			gender = 0;///<breif 性别
			expireDate = 0;///< brief 有效期限
			issuePlace = 0;///<breif 签发地点
			MRZ1 = 0;///<breif 第一行MRZ
			MRZ2 = 0;///<breif 第二行MRZ
			MRZ3 = 0;///<breif 第三行MRZ
			agency = 0;///< brief 发证机关
		}
	}TanWanPassPermitInfos;

	///<breif 港澳居民来往内地通 行证-照片页  分类号：14
	typedef struct HK_MToMotherLandPassPermitInfos
	{
		char *retainedFiele;///<breif 保留字段
		char *code; ///<breif 证件号码
		char *name;///<breif 中文姓名
		char *eName;///<breif 英文姓名
		char *gender;///<breif 性别
		char *birthDay;///<breif 出生日期
		char *expireEnd;///<breif 有效期至
		char *eName_F; ///<breif 英文姓
		char *eName_S;///<breif 英文名
		char *HK_Mcode;///<breif 港澳证件号码
		char *issueDate;///<breif 签发日期
		char *expireDate;///< brief 有效期限
		char *agency;///< brief 发证机关
		char *changeCardNum;///<breif 换证次数
		char *otherName;///<breif 其他姓名

		HK_MToMotherLandPassPermitInfos()
		{
			retainedFiele = 0;///<breif 保留字段
			code = 0; ///<breif 证件号码
			name = 0;///<breif 中文姓名
			eName = 0;///<breif 英文姓名
			gender = 0;///<breif 性别
			birthDay = 0;///<breif 出生日期
			expireEnd = 0;///<breif 有效期至
			eName_F = 0; ///<breif 英文姓
			eName_S = 0;///<breif 英文名
			HK_Mcode = 0;///<breif 港澳证件号码
			issueDate = 0;///<breif 签发日期
			expireDate = 0;///< brief 有效期限
			agency = 0;///< brief 发证机关
			changeCardNum = 0;///<breif 换证次数
			otherName = 0;///<breif 其他姓名
		}
	}HK_MToMotherLandPassPermitInfos;

	///<breif 台湾居民来往大陆通 行证 2015 版-照片页  分类号：25
	typedef struct TaiWanToMotherLandPassPermitInfos
	{
		char *retainedFiele;///<breif 保留字段
		char *name;///<breif 中文姓名
		char *eName;///<breif 英文姓名
		char *birthDay;///<breif 出生日期
		char *gender;///<breif 性别
		char *expireDate;///< brief 有效期限
		char *issuePlace;///<breif 签发地点
		char *code; ///<breif 证件号码
		char *issueNum;///<breif 签发次数
		char *agency;///< brief 发证机关

		TaiWanToMotherLandPassPermitInfos()
		{
			retainedFiele = 0;///<breif 保留字段
			name = 0;///<breif 中文姓名
			eName = 0;///<breif 英文姓名
			birthDay = 0;///<breif 出生日期
			gender = 0;///<breif 性别
			expireDate = 0;///< brief 有效期限
			issuePlace = 0;///<breif 签发地点
			code = 0; ///<breif 证件号码
			issueNum = 0;///<breif 签发次数
			agency = 0;///< brief 发证机关
		}
	}TaiWanToMotherLandPassPermitInfos;



	///<breif 护照信息  分类号：13
	typedef struct PassPortInfos
	{
		char *passPortType;///<breif 护照类型  PO:中华人民共和国护照
		char *code; ///<breif 护照号码 MRZ识别
		char *nationName;///<breif 本国姓名
		char *eName;///<breif 英文姓名
		char *gender;///<breif 性别
		char *birthDay;///<breif 出生日期
		char *expireEnd;///< brief 有效期止
		char *countryCode;///<breif 签发国代码
		char *eName_F;///<breif 英文姓
		char *eName_S;///<breif 英文名
		char *MRZ1;///<breif 第一行MRZ
		char *MRZ2;///<breif 第二行MRZ
		char *nationalityCode;///<breif 国籍代码
		char *codeOCR;///<breif 护照号码
		char *birthAddress;//<breif 出生地点 （仅限中国护 照）
		char *issuePlace;///<breif 签发地点
		char *issueDate;///<breif 签发日期
		char *rfidMRZ;///<breif RFID MRZ
		char *ocrMRZ;///<breif OCR MRZ
		char *birthAddressPinYin;///<breif 出生地点拼音
		char *issuePlacePinYin;///<breif 签发地点拼音
		char *idcardCode;///<breif 身份证号码 仅仅限于台湾及韩国护照
		char *nationNamePinYinOCR;///<breif 本国姓名拼音 OCR
		char *genderOCR;///<breif 性别OCR
		char *nationalityCodeOCR;///<breif 持证人国籍代码OCR
		char *idcardCodeOCR;///<breif 身份证号码OCR
		char *birthDayOCR;///<breif 出生日期OCR
		char *expireEndOCR;///< brief 有效期止OCR
		char *countryCodeOCR;///<breif 签发机关OCR
		char *nation_F;///<breif 本国姓
		char *nation_S;///<breif 本国名
		PassPortInfos() //数据初始化
		{
			passPortType = 0;///<breif 护照类型  PO:中华人民共和国护照
			code = 0; ///<breif 护照号码 MRZ识别
			nationName = 0;///<breif 本国姓名
			eName = 0;///<breif 英文姓名
			gender = 0;///<breif 性别
			birthDay = 0;///<breif 出生日期
			expireEnd = 0;///< brief 有效期止
			countryCode = 0;///<breif 签发国代码
			eName_F = 0;///<breif 英文姓
			eName_S = 0;///<breif 英文名
			MRZ1 = 0;///<breif 第一行MRZ
			MRZ2 = 0;///<breif 第二行MRZ
			nationalityCode = 0;///<breif 国籍代码
			codeOCR = 0;///<breif 护照号码
			birthAddress = 0;//<breif 出生地点 （仅限中国护 照）
			issuePlace = 0;///<breif 签发地点
			issueDate = 0;///<breif 签发日期
			rfidMRZ = 0;///<breif RFID MRZ
			ocrMRZ = 0;///<breif OCR MRZ
			birthAddressPinYin = 0;///<breif 出生地点拼音
			issuePlacePinYin = 0;///<breif 签发地点拼音
			idcardCode = 0;///<breif 身份证号码 仅仅限于台湾及韩国护照
			nationNamePinYinOCR = 0;///<breif 本国姓名拼音 OCR
			genderOCR = 0;///<breif 性别OCR
			nationalityCodeOCR = 0;///<breif 持证人国籍代码OCR
			idcardCodeOCR = 0;///<breif 身份证号码OCR
			birthDayOCR = 0;///<breif 出生日期OCR
			expireEndOCR = 0;///< brief 有效期止OCR
			countryCodeOCR = 0;///<breif 签发机关OCR
			nation_F = 0;///<breif 本国姓
			nation_S = 0;///<breif 本国名
		}

	}PassPortInfos;

	/// \breif 读卡器响应后回调函数
	///
	/// 读卡器响应回调，设置该回调函数后身份证读卡器读取数据后自动响应，返回证件信息
	///
	/// \param idCardReadInfos[out]-身份证信息
	/// \param userData[out]-用户信息
	typedef void (DLL_CALL *IDCardReadCB)(IDCardReadInfos *idCardReadInfos ,void *userData);

	/// \brief 读卡器上线事件
	/// \param userData[out]-用户信息
	typedef void (DLL_CALL *IDCardReadOnlineCB)(void *userData);
	/// \brief 读卡器下线事件
	/// \param userData[out]-用户信息
	typedef void (DLL_CALL *IDCardReadOfflineCB)(void *userData);


	/// \breif 护照识别设备响应后回调函数
	///
	/// 护照识别设备响应，设置该回调函数后护照识别设备自动响应，返回证件信息
	///
	/// \param passportInfos[out]-护照信息，如识别的不是该类型返回NULL
	/// \param hk_mPassPermitInfos[out]-往返港澳证件信息，如识别的不是该类型返回NULL
	/// \param taiwanPassPermitInfos[out]-往返台湾证件信息，如识别的不是该类型返回NULL
	/// \param hk_mToMotherLandPassPermitInfos[out]-港澳往返大陆证件信息，如识别的不是该类型返回NULL
	/// \param TaiWanToMotherLandPassPermitInfos[out]-台湾往返大陆证件信息，如识别的不是该类型返回NULL
	/// \param userData[out]-用户信息
	typedef void (DLL_CALL *IDCardRecogCB)(PassPortInfos *passportInfos,
											HK_MPassPermitInfos *hk_mPassPermitInfos,
											TaiWanPassPermitInfos *taiwanPassPermitInfos,
											HK_MToMotherLandPassPermitInfos *hk_mToMotherLandPassPermitInfos,
											TaiWanToMotherLandPassPermitInfos *TaiWanToMotherLandPassPermitInfos,
											void *userData);
	/// \brief 读卡器上线事件
	/// \param userData[out]-用户信息
	typedef void (DLL_CALL *IDCardRecogOnlineCB)(void *userData);
	/// \brief 读卡器下线事件
	/// \param userData[out]-用户信息
	typedef void (DLL_CALL *IDCardRecogOfflineCB)(void *userData);

#endif