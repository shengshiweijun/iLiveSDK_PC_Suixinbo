#ifndef iLive_h_
#define iLive_h_

#include <iLiveCommon.h>
#include <iLiveString.h>
#include <iLiveVector.h>
#include <iLivePair.h>


namespace ilive
{
	/**
	@brief iLiveSDK错误码集合
	*/
	enum E_iLiveError
	{
		INVALID_INTETER_VALUE   = -1,   ///< 无效的整型返回值(通用)
		NO_ERR                  = 0,    ///< 成功
		ERR_IM_NOT_READY        = 8001, ///< IM模块未就绪或未加载
		ERR_AV_NOT_READY        = 8002, ///< AV模块未就绪或未加载
		ERR_NO_ROOM             = 8003, ///< 无有效的房间
		ERR_ALREADY_EXIST       = 8004, ///< 目标已存在
		ERR_NULL_POINTER        = 8005, ///< 空指针错误
		ERR_ENTER_AV_ROOM_FAIL  = 8006, ///< 进入AV房间失败
		ERR_USER_CANCEL         = 8007, ///< 用户取消
		ERR_WRONG_STATE         = 8008, ///< 状态异常
		ERR_NOT_LOGIN			= 8009, ///< 未登录
		ERR_ALREADY_IN_ROOM		= 8010, ///< 已在房间中
		ERR_BUSY_HERE			= 8011,	///< 内部忙(上一请求未完成)
		ERR_NET_UNDEFINE		= 8012, ///< 网络未识别或网络不可达
		ERR_SDK_FAILED          = 8020, ///< iLiveSDK处理失败(通用)
		ERR_INVALID_PARAM       = 8021, ///< 无效的参数
		ERR_NOT_FOUND           = 8022, ///< 无法找到目标
		ERR_NOT_SUPPORT         = 8023, ///< 请求不支持
		ERR_ALREADY_STATE       = 8024, ///< 状态已到位(一般为重复调用引起)
		ERR_KICK_OUT            = 8050, ///< 被踢下线
		ERR_EXPIRE              = 8051, ///< 票据过期(需更新票据userSig)
	};

	/**
	@brief 房间事件
	*/
	enum E_EndpointEventId
	{
		EVENT_ID_NONE = 0,						///< 无
		EVENT_ID_ENDPOINT_ENTER = 1,			///< 进入房间事件
		EVENT_ID_ENDPOINT_EXIT = 2,				///< 退出房间事件
		EVENT_ID_ENDPOINT_HAS_CAMERA_VIDEO = 3, ///< 有发摄像头视频事件
		EVENT_ID_ENDPOINT_NO_CAMERA_VIDEO = 4,	///< 无发摄像头视频事件
		EVENT_ID_ENDPOINT_HAS_AUDIO = 5,		///< 有发音频事件
		EVENT_ID_ENDPOINT_NO_AUDIO = 6,			///< 无发音频事件
		EVENT_ID_ENDPOINT_HAS_SCREEN_VIDEO = 7, ///< 有发屏幕视频事件
		EVENT_ID_ENDPOINT_NO_SCREEN_VIDEO = 8,	///< 无发屏幕视频事件
		EVENT_ID_ENDPOINT_HAS_MEDIA_VIDEO = 9,	///< 有播放视频事件
		EVENT_ID_ENDPOINT_NO_MEDIA_VIDEO = 10,	///< 无播放视频事件
	};

	/**
	@brief 音频场景策略
	*/
	enum E_AudioCategory
	{
		AUDIO_CATEGORY_VOICECHAT = 0,				///< VoIP模式。适合于实时音频通信场景，如实时语音通话
		AUDIO_CATEGORY_MEDIA_PLAY_AND_RECORD = 1,	///< 媒体采集与播放模式。适合于那些对音质要求比较高的直播场景，如主播场景中的主播人员
		AUDIO_CATEGORY_MEDIA_PLAYBACK = 2,			///< 媒体播放模式。适合于那些对音质要求比较高的直播场景，如主播场景中的听众
	};

	/**
	@brief 消息类型。
	*/
	enum E_MessageElemType
	{
		TEXT,
		CUSTOM,
		IMAGE,
		FACE,
	};

	/**
	@brief 图片类型。原图是指用户发送的原始图片，尺寸和大小都保持不变；缩略图是将原图等比压缩，压缩后宽、高中较小的一个等于198像素；大图也是将原图等比压缩，压缩后宽、高中较小的一个等于720像素
	*/
	enum E_ImageType
	{
		THUMB,
		LARGE,
		ORIGINAL,
	};

	/**
	@brief 视频编码格式
	*/
	enum E_iLiveStreamEncode
	{
		HLS = 0x01,			///< 请求FLV编码的视频流URL
		FLV = 0x02,			///< 请求HLS编码的视频流URL
		HLS_AND_FLV = 0x03, ///< 同时请求HLS和FLV编码的视频流URL
		RAW = 0X04,			///< RAW码流
		RTMP = 0X05,		///< RTMP
		HLS_AND_RTMP = 0X06,///< HLS AND RTMP
	};

	/**
	@brief 录制数据类型 
	*/
	enum E_RecordDataType
	{
		E_RecordCamera = 0, ///< 录制摄像头
		E_RecordScreen,		///< 录制辅流(屏幕分享)
	};

	/**
	@brief 录制文件类型(RecordFile_NONE不录制)
	*/
	enum E_RecordFileType
	{
		RecordFile_NONE= 0x00,
		RecordFile_HLS = 0x01,
		RecordFile_FLV = 0x02,
		RecordFile_HLS_FLV = 0x03,
		RecordFile_MP4 = 0x04,
		RecordFile_HLS_MP4 = 0x05,
		RecordFile_FLV_MP4 = 0x06,
		RecordFile_HLS_FLV_MP4 = 0x07,
		RecordFile_MP3 = 0x10,
	};

	/**
	@brief 推流数据类型
	*/
	enum E_PushDataType
	{
		E_PushCamera = 0,///< 摄像头
		E_PushScreen,	 ///< 辅流(屏幕分享)
	};

	/**
	@brief 码率档位
	*/
	enum E_RateType
	{
		RATE_TYPE_ORIGINAL = 0,	///< 原始码率
		RATE_TYPE_550 = 10,		///< 标清码率550K
		RATE_TYPE_900 = 20,		///< 高清码率900K
	};

	/**
	@brief 色彩格式。
	*/
	enum E_ColorFormat
	{
		COLOR_FORMAT_NONE = -1,		///< 无意义
		COLOR_FORMAT_I420 = 0,		///< i420格式
		COLOR_FORMAT_NV21 = 1,
		COLOR_FORMAT_NV12 = 3,
		COLOR_FORMAT_RGB16 = 7,
		COLOR_FORMAT_RGB24 = 8,		///< rgb24格式(实际内存中存放方式是BGR888)
		COLOR_FORMAT_RGB32 = 9,
	};

	/**
	@brief 屏幕共享状态。
	@details 屏幕共享状态。
	*/
	enum E_ScreenShareState
	{
		E_ScreenShareNone,	///< 未开启屏幕分享
		E_ScreenShareWnd,	///< 开启了指定窗口的共享
		E_ScreenShareArea,	///< 开启了指定区域的共享
	};

	/**
	@brief 播片状态。
	*/
	enum E_PlayMediaFileState
	{
		E_PlayMediaFileStop,	///< 停止播放
		E_PlayMediaFilePlaying,	///< 播放中
		E_PlayMediaFilePause,	///< 暂停中
	};

	/**
	@brief 视频数据类型。
	@details 视频数据类型。
	*/
	enum E_VideoSrc
	{
		VIDEO_SRC_TYPE_NONE = 0,	///< 默认值，无意义
		VIDEO_SRC_TYPE_CAMERA = 1,	///< 摄像头
		VIDEO_SRC_TYPE_SCREEN = 2,	///< 屏幕
		VIDEO_SRC_TYPE_MEDIA = 3,	///< 播片
	};

	/**
	@brief 设备操作类型
	*/
	enum E_DeviceOperationType
	{
		E_DeviceOperationNone,		///< 默认值，无意义
		E_OpenCamera,				///< 打开摄像头
		E_CloseCamera,				///< 关闭摄像头
		E_OpenExternalCapture,		///< 打开自定义采集
		E_CloseExternalCapture,		///< 关闭自定义采集
		E_OpenMic,					///< 打开麦克风
		E_CloseMic,					///< 关闭麦克风
		E_OpenPlayer,				///< 打开扬声器
		E_ClosePlayer,				///< 关闭扬声器
		E_OpenScreenShare,			///< 打开屏幕分享
		E_CloseScreenShare,			///< 关闭屏幕分享
		E_OpenSystemVoiceInput,		///< 打开系统声音采集
		E_CloseSystemVoiceInput,	///< 关闭系统声音采集
		E_OpenPlayMediaFile,		///< 打开文件播放
		E_ClosePlayMediaFile,		///< 关闭文件播放
	};

	/**
	@brief 水印类型。
	@details 水印类型,就是针对哪种编码分辨率的视频设置水印。
	*/
	enum E_WaterMarkType
	{
		WATER_MARK_TYPE_NONE        = 0,
		WATER_MARK_TYPE_320_240     = 1, //针对编码分辨率为320*240的视频设置水印。
		WATER_MARK_TYPE_480_360     = 2, //针对编码分辨率为480*360的视频设置水印。
		WATER_MARK_TYPE_640_480     = 3, //针对编码分辨率为640*480的视频设置水印。
		WATER_MARK_TYPE_640_368     = 4, //针对编码分辨率为640*368的视频设置水印。
		WATER_MARK_TYPE_960_540     = 5, //针对编码分辨率为960*540的视频设置水印。
		WATER_MARK_TYPE_1280_720    = 6, //针对编码分辨率为1280*720的视频设置水印。
		WATER_MARK_TYPE_192_144     = 7, //针对编码分辨率为192*144的视频设置水印。
		WATER_MARK_TYPE_320_180     = 8, //针对编码分辨率为192*144的视频设置水印。
		WATER_MARK_TYPE_MAX,
	};

	/// 音视频通话的通话能力权限位。
	const uint64 AUTH_BITS_DEFAULT              = -1;			///< 所有权限。
	const uint64 AUTH_BITS_CREATE_ROOM          = 0x00000001;	///< 创建房间权限。
	const uint64 AUTH_BITS_JOIN_ROOM            = 0x00000002;	///< 加入房间的权限。
	const uint64 AUTH_BITS_SEND_AUDIO           = 0x00000004;	///< 发送音频的权限。
	const uint64 AUTH_BITS_RECV_AUDIO           = 0x00000008;	///< 接收音频的权限。
	const uint64 AUTH_BITS_SEND_CAMERA_VIDEO    = 0x00000010;	///< 发送摄像头视频的权限。
	const uint64 AUTH_BITS_RECV_CAMERA_VIDEO    = 0x00000020;	///< 接收摄像头视频的权限。
	const uint64 AUTH_BITS_SEND_SCREEN_VIDEO    = 0x00000040;	///< 发送屏幕视频的权限。
	const uint64 AUTH_BITS_RECV_SCREEN_VIDEO    = 0x00000080;	///< 接收屏幕视频的权限。

	/**
	@brief 被挤下线回调函数指针类型;
	*/
	typedef void (*ForceOfflineCallback)();

	/**
	@brief 连接网络成功函数指针类型;
	*/
	typedef void (*onNetworkCallback)();


	
	/**
	@brief 成功带值回调函数指针类型的封装
	*/
	template <typename T>
	struct Type
	{
		/**
		@brief 通用的成功带值回调函数指针类型;
		@param [in] value 操作成功，SDK返回给业务侧响应类型的值;
		@param [in] data SDK传回业务侧自定义的数据指针;
		*/
		typedef void (*iLiveValueSuccCallback)(T value, void* data);
	};

	/**
	@brief 收到消息的回调函数指针类型。
	@param [in] msg 收到的群消息
	*/
	typedef void (*iLiveMessageCallback)( const struct Message &msg, void* data );

	/**
    @brief 视频帧预处理回调
    @param video_frame 视频帧对象。
    @param data 自定义指针
    */
	typedef void (*iLivePreTreatmentCallback)( struct LiveVideoFrame* video_frame, void* data );
	/**
    @brief 视频帧回调
    @param video_frame 视频帧对象。
    @param data 自定义指针
    */
    typedef void (*iLivePreviewCallback)( const struct LiveVideoFrame* video_frame, void* data );

	/**
	@brief 设备操作回调
	@param [in] oper 设备操作类型;
	@param [in] retCode 错误码，NO_ERR表示成功;
	@param [in] data 自定义指针;
	*/
	typedef void (*iLiveDeviceOperationCallback)(E_DeviceOperationType oper, int retCode, void* data);
	
	/**
	@brief 通用失败回调
	@param [in] code 错误码
	@param [in] desc 错误描述
	@param [in] data 自定义指针
	*/
	typedef void (*iLiveErrCallback)(const int code, const char *desc, void* data);
	/**
	@brief 通用成功回调
	@param [in] data 自定义指针
	*/
	typedef void (*iLiveSucCallback)(void* data);

	/**
	@brief SDK主动退出房间监听函数指针
	@details SDK内部会因为30s心跳包超时等原因主动退出房间，APP需要监听此退出房间事件并对该事件进行相应处理
	@param [in] reason 退出原因错误码
	@param [in] errorinfo 退出原因描述
	@param [in] data 用户自定数据指针，回调函数中原封不动传回给业务侧
	*/
	typedef void (*iLiveRoomDisconnectListener)(int reason, const char *errorInfo, void* data);
	/**
	@brief 房间内成员变化监听函数指针
	@details 当房间成员发生状态变化(如是否发音频、是否发视频等)时，会通过该函数指针通知业务侧
	@param [in] event_id 状态变化id，详见EndpointEventId的定义
	@param [in] identifier_list 发生状态变化的成员id列表
	@param [in] data 用户自定数据类型，回调函数中原封不动传回给业务侧
	*/
	typedef void (*iLiveMemStatusListener)(E_EndpointEventId eventId, const Vector<String> &ids, void* data);
	/**
	@brief 设备插拔监听函数指针
	@param [in] data 用户自定数据类型，回调函数中原封不动传回给业务侧
	*/
	typedef void (*iLiveDeviceDetectListener)(void* data);
	/**
	@brief 房间内质量报告的回调函数指针类型
	@details 在iLiveRoomOption中的参数
	@param [in] param 房间内质量参数.
	@param [in] data 用户自定数据类型，回调函数中原封不动传回给业务侧
	*/
	typedef void (*iLiveQualityParamCallback)(const struct iLiveRoomStatParam& param, void* data);

	/**
	@brief 消息中的图片
	*/
	struct Image
	{
		/**
		@brief 图片构造方法
		@param [in] _type 图片类型
		@param [in] _size 图片文件大小
		@param [in] _width 图片宽度
		@param [in] _height 图片高度
		@param [in] _url 图片下载地址
		*/
		Image(E_ImageType _type, unsigned _size, unsigned _width, unsigned _height, String _url) : type(_type), size(_size), width(_width), height(_height), url(_url)
		{

		}
		E_ImageType type;
		unsigned size;
		unsigned height;
		unsigned width;
		String url;
	};

	/**
	@brief 消息元素基类
	*/
	struct MessageElem
	{
		E_MessageElemType type;
		MessageElem(){}
		MessageElem(const MessageElem& oth):type(oth.type){}
		virtual ~MessageElem() {}
	};

	/**
	@brief 文本消息元素
	*/
	struct MessageTextElem : public MessageElem
	{
		MessageTextElem(const String& _content)
		:content(_content)
		{
			type = TEXT;
		}
		String content;
	};

	/**
	@brief 自定义消息元素
	*/
	struct MessageCustomElem : public MessageElem
	{
		MessageCustomElem(const String& _data, const String& _ext) : data(_data), ext(_ext)
		{
			type = CUSTOM;
		}
		String data;
		String ext;
	};

	/**
	@brief 表情消息元素
	*/
	struct MessageFaceElem : public MessageElem
	{
		MessageFaceElem(int _index, const String &_data) : data(_data), index(_index)
		{
			type = FACE;
		}
		int index;
		String data;
	};

	/**
	@brief 图片消息元素
	*/
	struct MessageImageElem : public MessageElem
	{
		MessageImageElem(const String& _path) : path(_path)
		{
			type = IMAGE;
		}
		MessageImageElem(const MessageImageElem& other)
			:MessageElem(other)
		{
			path = other.path;
			for (int i = 0; i < other.images.size(); ++i)
			{
				Image *otherImg = other.images[i];
				Image *img = new Image(otherImg->type, otherImg->size, otherImg->width, otherImg->height, otherImg->url);
				images.push_back(img);
			}
		}
		~MessageImageElem()
		{
			while(images.size() > 0)
			{
				delete images.back();
				images.pop_back();
			}
		}

		String path;///< 发送图片的本地地址，仅发送有效
		Vector<Image*> images;///< 接收的图片，仅接收有效

	};

	/**
	@brief 消息
	@details 一个消息内可以包含多个消息元素，按照顺序存放在vector中
	*/
	struct Message
	{
		String sender;
		uint32 time;
		Vector<MessageElem*> elems;
		
		Message()
		{
		}

		Message(const Message& other)
		{
			sender = other.sender;
			time = other.time;
			for (int i = 0; i < other.elems.size(); ++i)
			{
				const MessageElem* elem = other.elems[i];
				switch(elem->type)
				{
				case TEXT:
					{
						const MessageTextElem *otherElem = static_cast<const MessageTextElem*>(other.elems[i]);
						MessageTextElem *e = new MessageTextElem(otherElem->content);
						elems.push_back(e);
						break;
					}
				case CUSTOM:
					{
						const MessageCustomElem *otherElem = static_cast<const MessageCustomElem*>(other.elems[i]);
						MessageCustomElem *e = new MessageCustomElem(otherElem->data, otherElem->ext);
						elems.push_back(e);
						break;
					}
				case IMAGE:
					{
						const MessageImageElem *otherElem = static_cast<const MessageImageElem*>(other.elems[i]);
						MessageImageElem *e = new MessageImageElem(*otherElem);
						elems.push_back(e);
						break;
					}
				case FACE:
					{
						const MessageFaceElem *otherElem = static_cast<const MessageFaceElem*>(other.elems[i]);
						MessageFaceElem *e = new MessageFaceElem(otherElem->index, otherElem->data);
						elems.push_back(e);
						break;
					}
				}
			
			}
		}

		Message& Message::operator=(const Message& other)
		{
			if (&other == this) return *this;
			sender = other.sender;
			time = other.time;
			for (int i = 0; i < other.elems.size(); ++i)
			{
				const MessageElem* elem = other.elems[i];
				switch(elem->type)
				{
				case TEXT:
					{
						const MessageTextElem *otherElem = static_cast<const MessageTextElem*>(other.elems[i]);
						MessageTextElem *e = new MessageTextElem(otherElem->content);
						elems.push_back(e);
						break;
					}
				case CUSTOM:
					{
						const MessageCustomElem *otherElem = static_cast<const MessageCustomElem*>(other.elems[i]);
						MessageCustomElem *e = new MessageCustomElem(otherElem->data, otherElem->ext);
						elems.push_back(e);
						break;
					}
				case IMAGE:
					{
						const MessageImageElem *otherElem = static_cast<const MessageImageElem*>(other.elems[i]);
						MessageImageElem *e = new MessageImageElem(*otherElem);
						elems.push_back(e);
						break;
					}
				case FACE:
					{
						const MessageFaceElem *otherElem = static_cast<const MessageFaceElem*>(other.elems[i]);
						MessageFaceElem *e = new MessageFaceElem(otherElem->index, otherElem->data);
						elems.push_back(e);
						break;
					}
				}
			}
			return *this;
		}

		~Message()
		{
			while(elems.size()>0)
			{
				delete elems.back();
				elems.pop_back();
			}
		}
	};
	
	/**
	@brief iLiveRoom配置项。
	@details 在创建或者加入房间时，需要先填写此结构作为参数传入;
	*/
	struct iLiveRoomOption
	{
		/**
		@brief 构造函数，初始化成员变量值。
		*/
		iLiveRoomOption()
			:audioCategory(AUDIO_CATEGORY_MEDIA_PLAY_AND_RECORD)//互动直播场景
			,roomId(0)
			,authBits(AUTH_BITS_DEFAULT)
			,autoRequestCamera(true)
			,autoRequestScreen(true)
			,autoRequestMediaFile(true)
			,timeElapse(1000)
			,roomDisconnectListener(NULL)
			,memberStatusListener(NULL)
			,deviceDetectListener(NULL)
			,qualityParamCallback(NULL)
			,data(NULL)
		{
		}

		E_AudioCategory			audioCategory;			///< 音视场景策略,详细信息见E_AudioCategory的定义.
		uint32					roomId;					///< 房间ID,由业务侧创建并维护的房间ID
		uint64					authBits;				///< 通话能力权限位;主播应当设置为AUTH_BITS_DEFAULT,连麦观众设置为AUTH_BITS_DEFAULT & (~AUTH_BITS_CREATE_ROOM),观众设置为AUTH_BITS_JOIN_ROOM|AUTH_BITS_RECV_AUDIO|AUTH_BITS_RECV_CAMERA_VIDEO|AUTH_BITS_RECV_SCREEN_VIDEO
		String					controlRole;			///< 角色名，web端音视频参数配置工具所设置的角色名
		String					authBuffer;				///< 通话能力权限位的加密串
		bool					autoRequestCamera;		///< 房间内有成员打开摄像头时，是否自动请求画面;
		bool					autoRequestScreen;		///< 房间内有成员打开屏幕分享时，是否自动请求画面;
		bool					autoRequestMediaFile;	///< 房间内有成员打开播片时，是否自动请求画面;
		uint32					timeElapse;				///< sdk执行qualityParamCallback回调的时间间隔,单位毫秒(SDK内部1秒更新一次，所以,timeElapse小于1000将会被修正到1000)。

		/**
		@brief SDK主动退出房间回调;
		@details 在网络断开30秒后,会收到此回调,此时已被sdk强制退出房间,所以,不要调用退出房间接口;网络重连后,需要重新创建\进入房间,参见iLiveRoomDisconnectListener定义。
		*/
		iLiveRoomDisconnectListener	roomDisconnectListener;
		/**
		@brief 房间成员事件通知，参见iLiveMemStatusListener定义。
		*/
		iLiveMemStatusListener		memberStatusListener;
		/**
		@brief 设备插拔监听回调;
		@details 当摄像头、麦克风、扬声器等设备的接入及拔出时，sdk会通过此回调通知给业务侧，收到此回调需要更新设备列表;参见iLiveDeviceDetectListener定义。
		@note 当摄像头、麦克风、扬声器等正在使用中时,收到此回调前，还会收到相应设备关闭的回调;
		@todo 此字段即将废弃，请用户使用iLive::setDeviceDetectCallback()接口设置此此回调
		*/
		Deprecated
		iLiveDeviceDetectListener	deviceDetectListener;
		/**
		@brief 质量报告的回调;
		@details 如果用户需要监听房间内直播质量,可以设置此回调，并设置timeElapse的值。参见iLiveQualityParamCallback定义。
		*/
		iLiveQualityParamCallback	qualityParamCallback;
		/**
		@brief 用户自定义数据类型，在iLiveRoomOption中指定的各个回调中原封不动返回。
		*/
		void*						data;
	};

	/**
	@brief 录制配置项。
	@details 录制操作需要传入此类型的参数。
	*/
	struct RecordOption
	{
		/**
		@brief 构造函数，初始化成员变量值。
		*/
		RecordOption()
			:recordDataType(E_RecordCamera)
			,fileName("")
			,classId(0)
		{
		}

		E_RecordDataType	recordDataType; ///< 录制的数据类型,参见E_RecordDataType定义。
		String				fileName;		///< 录制后的文件名。
		int					classId;		///< 视频分类ID(暂无效)。
	};

	/**
	@brief 推流配置项。
	@details 推流操作需要传入此类型的参数。
	*/
	struct PushStreamOption
	{
		/**
		@brief 构造函数，初始化成员变量。
		*/
		PushStreamOption()
			:pushDataType(E_PushCamera)
			,encode(HLS)
			,recordFileType(RecordFile_NONE)
			,bOnlyPushAudio(false)
		{
		}

		E_PushDataType				pushDataType;		///< 推送数据类型，参见E_PushDataType定义.
		E_iLiveStreamEncode			encode;				///< 推流数据编码方式，参见E_TIMStreamEncode定义.
		E_RecordFileType			recordFileType;		///< 推流时自动录制的文件类型，参见E_RecordFileType定义.
		/**
		@brief 是否纯音频推流
		@remark 
		1、要使用纯音频推流，需注意:<br/>
			(1)需要联系腾讯开启白名单放可使用此功能;<br/>
			(2)不能在后台开启自动推流配置项;<br/>
			(3)在开启推流前，不能有视频流(打开摄像头、屏幕分享等);<br/>
		2、 使用纯音频推流时，其他相关参数说明:<br/>
			(1)如果需要推流时自动录制文件，recordFileType需要设置为RecordFile_MP3;<br/>
			(2)使用纯音频推流时，pushDataType设置为E_PushCamera和E_PushScreen，效果一样，建议使用默认值E_PushCamera;
		*/
		bool						bOnlyPushAudio;		///< 纯音频推流,纯音频推流时，如果要录制文件，需要将recordFileType指定为RecordFile_MP3
	};

	/**
	@brief 推流返回url类型
	*/
	struct LiveUrl
	{
		E_iLiveStreamEncode			encodeType;	///< 视频流编码类型
		String						url;		///< 视频流播放URL
		E_RateType					rateType;	///< 码率档位信息
	};
	
	/**
	@brief 推流返回数据类型
	*/
	struct PushStreamRsp
	{
		PushStreamRsp()
			:channelId(0)
		{
		}

		Vector<LiveUrl>		urls;		///< Url列表
		uint64				channelId;	///< 频道ID
		uint32				tapeTaskId; ///< 录制标记为录制的时候带回录制task_id有效
	};

	/**
	@brief 视频帧描述。
	@details 视频帧描述。
	*/
	struct VideoFrameDesc
	{
		VideoFrameDesc()
		: colorFormat(COLOR_FORMAT_RGB24)
		, width(0)
		, height(0)
		, externalData(false)
		, rotate(0)
		, srcType(VIDEO_SRC_TYPE_CAMERA)
		{
		}

		E_ColorFormat	colorFormat;	///< 色彩格式，详情见ColorFormat的定义。
		uint32			width;			///< 宽度，单位：像素。
		uint32			height;			///< 高度，单位：像素。
		bool			externalData;	///< 数据是否来自外部摄像头。
		E_VideoSrc		srcType;		///< 视频源类型，详情见VideoSrcType的定义。
		/**
		画面旋转的角度：
		- source_type为VIDEO_SRC_TYPE_CAMERA时，表示视频源为摄像头。
		  在终端上，摄像头画面是支持旋转的，App需要根据旋转角度调整渲染层的处理，以保证画面的正常显示。
		- source_type为其他值时，rotate恒为0。
		*/
		uint32			rotate;
	};

	/**
	@brief 视频帧。
	*/
	struct LiveVideoFrame
	{
		LiveVideoFrame()
		: dataSize(0)
		, data(NULL)
		, timeStamp(0)
		{
		}

		String			identifier;	///< 视频帧所属的房间成员id。
		VideoFrameDesc	desc;		///< 视频帧描述。
		uint32			dataSize;	///< 视频帧的数据缓冲区大小，单位：字节。
		uint8*			data;		///< 视频帧的数据缓冲区，SDK内部会管理缓冲区的分配和释放。
		uint64			timeStamp;  ///< 视频帧的时间戳，SDK内部会自动填写好，utc时间，0为无效值。
	};

	/**
	@brief 直播流信息
	*/
	struct AVStream
	{
		AVStream(String id, E_VideoSrc type): id(id), srcType(type) {};
		String		id;
		E_VideoSrc	srcType;
	};

	/**
	@brief 视频编码相关参数
	*/
	struct iLiveVideoEncodeParam
	{
		iLiveVideoEncodeParam():viewType(0),width(0),height(0),fps(0),bitrate(0),angle(0){}

		/**
		@brief 将此参数结果转换为String，方便打印输出
		@param [in] pre 输出每行的前缀;
		@return 输出的String
		*/
		String getInfoString(const String& pre) const
		{
			String szRet;
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(viewType), viewType);
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(width), width);
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(height), height);
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(fps), fps);
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(bitrate), bitrate);
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(angle), angle);
			return szRet;
		}

		uint32 viewType;	///< 画面类型，作为编码信息索引：0-主路画面 2-辅路
		uint32 width;       ///< 视频编码宽
		uint32 height;      ///< 视频编码高
		uint32 fps;         ///< 视频编码实时帧率×10
		uint32 bitrate;     ///< 视频编码码率(无包头)
		uint32 angle;       ///< 角度
	};

	/**
	@brief 视频解码相关参数
	*/
	struct iLiveVideoDecodeParam
	{
		iLiveVideoDecodeParam():viewType(0),width(0),height(0),fps(0),bitrate(0){}

		/**
		@brief 将此参数结果转换为String，方便打印输出
		@param [in] pre 输出每行的前缀;
		@return 输出的String
		*/
		String getInfoString(const String& pre) const
		{
			String szRet;
			szRet += String::Format("%s%s: %s\n", pre.c_str(), NAME(userId), userId.c_str());
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(viewType), viewType);
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(width), width);
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(height), height);
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(fps), fps);
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(bitrate), bitrate);
			return szRet;
		}

		String userId;		///< 解码用户
		uint32 viewType;	///< 画面类型，作为编码信息索引：0-主路画面 2-辅路
		uint32 width;		///< 视频解码宽
		uint32 height;		///< 视频解码高
		uint32 fps;			///< 视频解码出的帧率×10
		uint32 bitrate;		///< 视频解码出的码率(无包头)
	};

	/**
	@brief 视频下发调控参数,与在后台Spear上配置的参数相关
	*/
	struct iLiveVideoQosParam
	{
		iLiveVideoQosParam():width(0),height(0),fps(0),bitrate(0){}
		
		/**
		@brief 将此参数结果转换为String，方便打印输出
		@param [in] pre 输出每行的前缀;
		@return 输出的String
		*/
		String getInfoString(const String& pre) const
		{
			String szRet;
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(width), width);
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(height), height);
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(fps), fps);
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(bitrate), bitrate);
			return szRet;
		}

		uint32 width;    ///< 视频宽
		uint32 height;   ///< 视频高
		uint32 fps;      ///< 帧率
		uint32 bitrate;  ///< 码率
	};

	/**
	@brief 音频编码相关参数
	*/
	struct iLiveAudioEncodeParam
	{
		iLiveAudioEncodeParam():encodeBitrate(0){}

		/**
		@brief 将此参数结果转换为String，方便打印输出
		@param [in] pre 输出每行的前缀;
		@return 输出的String
		*/
		String getInfoString(const String& pre) const
		{
			String szRet;
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(encodeBitrate), encodeBitrate);
			return szRet;
		}

		uint32	encodeBitrate;	///< 音频编码码率
	};

	/**
	@brief 音频解码相关参数
	*/
	struct iLiveAudioDecodeParam
	{
		iLiveAudioDecodeParam():sampleRate(0),channelCount(0){}

		/**
		@brief 将此参数结果转换为String，方便打印输出
		@param [in] pre 输出每行的前缀;
		@return 输出的String
		*/
		String getInfoString(const String& pre) const
		{
			String szRet;
			szRet += String::Format("%s%s: %s\n", pre.c_str(), NAME(userId), userId.c_str());
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(sampleRate), sampleRate);
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(channelCount), channelCount);
			return szRet;
		}

		String userId;       ///< 音频解码用户
		uint32 sampleRate;   ///< 音频编码采样率
		uint32 channelCount; ///< 通道数，1表示单声道(mono)，2表示立体声(stereo)
	};
	
	/**
	@brief 音频下发调控参数,与在后台Spear上配置的参数相关
	*/
	struct iLiveAudioQosParam
	{
		iLiveAudioQosParam():sampleRate(0),channelCount(0),bitrate(0),aecEnable(0),agcEnable(0){}
		
		/**
		@brief 将此参数结果转换为String，方便打印输出
		@param [in] pre 输出每行的前缀;
		@return 输出的String
		*/
		String getInfoString(const String& pre) const
		{
			String szRet;
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(sampleRate), sampleRate);
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(channelCount), channelCount);
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(bitrate), bitrate);
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(aecEnable), aecEnable);
			szRet += String::Format("%s%s: %u\n", pre.c_str(), NAME(agcEnable), agcEnable);
			return szRet;
		}

		uint32 sampleRate;             ///< 采样率
		uint32 channelCount;           ///< 通道数，1表示单声道(mono)，2表示立体声(stereo)
		uint32 bitrate;                ///< 码率
		uint8  aecEnable;              ///< AEC功能是否开启
		uint8  agcEnable;              ///< AGC功能是否开启
	};

	/**
	@brief 房间直播质量相关的参数
	*/
	struct iLiveRoomStatParam
	{
		iLiveRoomStatParam():exeCpuRate(0),sysCpuRate(0),rtt(0){}

		/**
		@brief 将此参数结果转换为String，方便打印输出
		@return 输出的String
		*/
		String getInfoString() const
		{
			String szRet;

			szRet += String::Format("%s: %.02f%%\n", NAME(exeCpuRate), exeCpuRate/100.f);
			szRet += String::Format("%s: %.02f%%\n", NAME(sysCpuRate), sysCpuRate/100.f);

			szRet += String::Format("%s: %ums\n", NAME(rtt), rtt);
			
			szRet += String::Format( "%s: %d\n", NAME(videoEncodeParams.size), videoEncodeParams.size() );
			for (int i=0; i<videoEncodeParams.size(); ++i)
			{
				szRet += String::Format("videoEncodeParams[%d]:\n", i);
				szRet += videoEncodeParams[i].getInfoString("   ");
			}

			szRet += String::Format( "%s: %d\n", NAME(videoDecodeParams.size), videoDecodeParams.size() );
			for (int i=0; i<videoDecodeParams.size(); ++i)
			{
				szRet += String::Format("videoDecodeParams[%d]:\n", i);
				szRet += videoDecodeParams[i].getInfoString("   ");
			}

			szRet += "videoMainQosParam:\n";
			szRet += videoMainQosParam.getInfoString("   ");

			szRet += "videoAuxQosParam:\n";
			szRet += videoAuxQosParam.getInfoString("   ");

			szRet += "audioEncodeParams:\n";
			szRet += audioEncodeParams.getInfoString("   ");

			szRet += String::Format( "%s: %d\n", NAME(audioDecodeParams.size), audioDecodeParams.size() );
			for (int i=0; i<audioDecodeParams.size(); ++i)
			{
				szRet += String::Format("audioDecodeParams[%d]:\n", i);
				szRet += audioDecodeParams[i].getInfoString("   ");
			}

			szRet += "audioQosParam:\n";
			szRet += audioQosParam.getInfoString("   ");
			
			return szRet;
		}

		uint16 exeCpuRate;	///< 应用CPU使用率×10000(例如：3456对应于34.56%)
		uint16 sysCpuRate;	///< 系统CPU使用率×10000(例如：3456对应于34.56%)
		
		uint32 rtt;         ///< 往返时延（Round-Trip Time），单位毫秒;

		Vector<iLiveVideoEncodeParam> videoEncodeParams;	///< 视频编码参数
		Vector<iLiveVideoDecodeParam> videoDecodeParams;	///< 视频解码参数
		iLiveVideoQosParam videoMainQosParam;				///< 主路视频流控下发参数
		iLiveVideoQosParam videoAuxQosParam;				///< 辅路视频流控下发参数

		iLiveAudioEncodeParam		  audioEncodeParams;	///< 音频编码参数(此参数暂时为0，后续会矫正)
		Vector<iLiveAudioDecodeParam> audioDecodeParams;	///< 音频解码参数(此参数暂时为0，后续会矫正)
		iLiveAudioQosParam			  audioQosParam;        ///< 音频流控下发参数
	};

	/**
	@brief 接口封装抽象接口
	*/
	struct iLive
	{
		/**
		@brief 获取版本号
		@return 版本号
		*/
		virtual const char *getVersion() = 0;
		/**
		@brief 初始化
		@details 使用ilive各项功能前必须先初始化
		@param [in] appId 在腾讯云申请的sdkappid
		@param [in] accountType 在腾讯云申请的accountType
		@param [in] imSupport 是否需要聊天等即时通讯功能
		@return 返回操作结果,成功则返回NO_ERR
		*/
		virtual int init(const int appId, const int accountType, bool imSupport = true) = 0;
		/**
		@brief 释放
		@details 使用完ilive后需要释放资源。
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针);
		@remark 此函数会清理7天前的所有日志文件(iLiveSDK、AVSDK、IMSDK)。
		*/
		virtual void release(iLiveSucCallback suc = NULL, iLiveErrCallback err = NULL, void* data = NULL) = 0;
		/**
		@brief 设置被踢下线监听
		@details 每个账号不能同时登录多台设备，当其他设备登录相同账号时会收到这个通知
		@param [in] cb 回调函数
		*/
		virtual void setForceOfflineCallback(ForceOfflineCallback cb) = 0;
		/**
		@brief 设置消息监听
		@param [in] cb 回调函数
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针);
		@note 当前房间之外的群消息会被sdk过滤掉;
		*/
		virtual void setMessageCallBack( iLiveMessageCallback cb, void* data ) = 0;
		/**
		@brief 设置网络连接监听
		@param [in] onConn 联网成功回调
		@param [in] onDisconn 断连回调
		@note 建议成功联网回调后再进行登录等其他业务逻辑
		*/
		virtual void setConnListener( onNetworkCallback onConn, onNetworkCallback onDisconn ) = 0;

		/**
		@brief 设置预处理函数指针。
		@details 在视频被传输出去前，用户可以在此回调函数中做预处理;
		@param [in] pPreTreatmentFun 预处理函数指针。
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针);
		@remark 预处理函数耗时不要过久，最好控制在10ms内; 同时不能改变图像大小和图像颜色格式。
		@note SDK将在子线程中执行此回调.
		*/
		virtual void setPreTreatmentFun( iLivePreTreatmentCallback pPreTreatmentFun, void* data ) = 0;
		/**
		@brief 设置本地视频回调函数指针。
		@param [in] pLocalVideoCB 本地视频回调函数指针
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针);
		@remark 业务侧实现该回调函数，SDK向该回调函数传入本地视频相关数据，业务侧拿到数据后进行渲染显示
		*/
		virtual void setLocalVideoCallBack( iLivePreviewCallback pLocalVideoCB, void* data ) = 0;
		/**
		@brief 设置远程视频回调函数指针。
		@param [in] pRemoteVideoCB 远程视频回调函数指针
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针);
		@remark 业务侧实现该回调函数，SDK向该回调函数传入远程视频相关数据，业务侧拿到数据后进行渲染显示
		*/
		virtual void setRemoteVideoCallBack( iLivePreviewCallback pRemoteVideoCB, void* data ) = 0;
		/**
		@brief 设置设备操作回调函数指针。
		@details 摄像头、自定义采集、麦克风、扬声器、屏幕分享、系统声音采集、文件播放等设备操作结果，会通过此回调通知给业务层。
		@param [in] cb 设备操作的回调函数指针.
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针);
		*/
		virtual	void setDeviceOperationCallback( iLiveDeviceOperationCallback cb, void* data ) = 0;
		/**
		@brief 设置设备插拔监听函数;
		@details 当摄像头、麦克风、扬声器设备的接入及拔出时，sdk会通过此回调通知给业务侧，收到此回调需要更新设备列表;参见iLiveDeviceDetectListener定义。
		@note 当摄像头、麦克风、扬声器等正在使用中时,设备被拔出，收到此回调前，还会收到相应设备关闭的回调;注意: 只有在房间中或设备测试中，才会收到此回调;
		*/
		virtual void setDeviceDetectCallback( iLiveDeviceDetectListener cb, void* data ) = 0;

		/**
		@brief 登录
		@param [in] userId 用户id
		@param [in] userSig 用户签名
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针);
		*/
		virtual void login(const char *userId, const char *userSig, iLiveSucCallback suc, iLiveErrCallback err, void* data) = 0;
		/**
		@brief 登出
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针);
		*/
		virtual void logout(iLiveSucCallback suc, iLiveErrCallback err, void* data) = 0;

		/**
		@brief 开始设备测试
		@details 开始设备测试后，可以在登录之后，进入房间之前，对打开摄像头、麦克风、扬声器，进行设备测试;
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针);
		@param [in] preWidth 设置打开摄像头测试时,视频帧的宽度;
		@param [in] preHeight 设置打开摄像头测试时,视频帧的高度;
		@remark 设备测试时，美颜、美白功能可用;
		*/
		virtual void startDeviceTest(iLiveSucCallback suc, iLiveErrCallback err, void* data, int preWidth = 640, int preHeight = 480) = 0;
		/**
		@brief 停止设备测试
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针);
		@remark 在开始设备测试后，需要停止设备测试，才能进入房间，否则会返回相应错误码;
		*/
		virtual void stopDeviceTest(iLiveSucCallback suc, iLiveErrCallback err, void* data) = 0;
		
		/**
		@brief 创建直播房间
		@param [in] roomOption 房间配置
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针);
		*/
		virtual void createRoom(const iLiveRoomOption &roomOption, iLiveSucCallback suc, iLiveErrCallback err, void* data) = 0;
		/**
		@brief 加入直播房间
		@param [in] roomOption 房间配置
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针);
		*/
		virtual void joinRoom(const iLiveRoomOption& roomOption, iLiveSucCallback suc, iLiveErrCallback err, void* data) = 0;
		/**
		@brief 退出直播房间
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针);
		*/
		virtual void quitRoom(iLiveSucCallback suc, iLiveErrCallback err, void* data) = 0;
		/**
		@brief 请求一个或多个成员的视频画面
		@param [in] streams 请求的流
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针)
		@note 
		1、requestStream操作必须等待异步回调函数执行结束后，才能进行新的requestStream操作;<br/>
		2、requestStream、cancelStream和cancelAllStream不能并发执行，即同一时刻只能进行一种操作;
		*/
		virtual void requestStream(const Vector<AVStream> &streams, iLiveSucCallback suc, iLiveErrCallback err, void* data) = 0;
		/**
		@brief  取消指定用户的画面。
		@param [in] streams 取消的流
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针)
		@note 
		1、cancelStream操作必须等待异步回调函数执行结束后，才能进行新的cancelStream操作;<br/>
		2、requestStream、cancelStream和cancelAllStream不能并发执行，即同一时刻只能进行一种操作;
		*/
		virtual void cancelStream(const Vector<AVStream> &streams, iLiveSucCallback suc, iLiveErrCallback err, void* data) = 0;
		/**
		@brief 取消所有请求的视频画面。
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针)
		@note requestStream、cancelStream和cancelAllStream不能并发执行，即同一时刻只能进行一种操作;
		*/
		virtual void cancelAllStream(iLiveSucCallback suc, iLiveErrCallback err, void* data) = 0;
		/**
		@brief 发C2C消息
		@param [in] dstUser 接收方id
		@param [in] message 要发送的消息
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针)
		*/
 		virtual void sendC2CMessage( const char *dstUser, const Message	&message, iLiveSucCallback suc, iLiveErrCallback err, void* data ) = 0;
 		/**
		@brief 发群消息
		@param [in] message 要发送的消息
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针)
		@note 此处发送群消息，仅限于在当前直播间中发送群消息。
		*/
		virtual void sendGroupMessage( const Message &message, iLiveSucCallback suc, iLiveErrCallback err, void* data ) = 0;

		/**
		@brief 获取本地消息
		@param [in] count 要获取的消息条数
		@param [in] user 会话的对象id
		@param [in] fromStart 从头开始拉取
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针)
		*/
		virtual void getLocalC2CMessage( int count, const char *user, bool fromStart, Type<Vector<Message>>::iLiveValueSuccCallback suc, iLiveErrCallback err, void* data ) = 0;

		/**
		@brief 开始推流
		@param [in] pushOption 推流参数
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针)
		*/
		virtual void startPushStream( const PushStreamOption& pushOption, Type<PushStreamRsp&>::iLiveValueSuccCallback suc, iLiveErrCallback err, void* data ) = 0;
		/**
		@brief 结束推流
		@param [in] channelId 频道id(在推流成功的的回调中返回的频道id)
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针)
		*/
		virtual void stopPushStream( uint64 channelId, iLiveSucCallback suc, iLiveErrCallback err, void* data ) = 0;

		/**
		@brief 开始录制。
		@param [in] recordOption 录制配置选项。
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针)
		*/
		virtual void startRecord(const RecordOption& recordOption, iLiveSucCallback suc, iLiveErrCallback err, void* data) = 0;

		/**
		@brief 停止录制。
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针)
		@remark 停止录制成功回调，返回录制视频文件的ID列表; 业务侧开起自动录制时，将返回空列表，用户可直接到后台查询。
		*/
		virtual void stopRecord(Type<Vector<String>&>::iLiveValueSuccCallback suc, iLiveErrCallback err, void* data) = 0;

		/**
		@brief 结束推流
		@param [in] role 角色
		@param [in] suc 成功回调
		@param [in] err 失败回调
		@param [in] data 用户自定义数据的指针，回调函数中原封不动地传回(通常为调用类的指针)
		*/
		virtual void changeRole( const char *role, iLiveSucCallback suc, iLiveErrCallback err, void* data ) = 0;		 
		/**
		@brief 设置美颜程度
		@param [in] grade 美颜程度参数。grade取值范围在0-9之间，0表示美颜关闭
		@return 返回值为NO_ERR时表示成功，否则表示失败
		@note 美颜、美白功能只对本地摄像画面有效，SDK不会对自定义采集画面美颜、美白处理;
		*/
		virtual int setSkinSmoothGrade(int grade) = 0;
		/**
		@brief 设置美白程度
		@param [in] grade 美白程度参数。grade取值范围在0-9之间，0表示美白关闭
		@return 返回值为NO_ERR时表示成功，否则表示失败
		@note 美颜、美白功能只对本地摄像画面有效，SDK不会对自定义采集画面美颜、美白处理;
		*/
		virtual int setSkinWhitenessGrade(int grade) = 0;
		/**
		@brief 获取可用摄像头列表
		@param [out] cameraList 传回获取到的摄像头列表,第一个(索引0)为系统默认设备;
		@return 操作结果,NO_ERR表示无错误;如果没有可用摄像头,返回AV_ERR_DEVICE_NOT_EXIST错误码(错误码见github上的错误码表);
		*/
		virtual int getCameraList( Vector< Pair<String/*id*/, String/*name*/> >& cameraList ) = 0;
		/**
		@brief 获取可用麦克风列表
		@param [out] micList 传回获取到的麦克风列表,第一个(索引0)为系统默认设备;
		@return 操作结果,NO_ERR表示无错误;如果没有可用麦克风,返回AV_ERR_DEVICE_NOT_EXIST错误码(错误码见github上的错误码表);
		*/
		virtual int getMicList( Vector< Pair<String/*id*/, String/*name*/> >& micList ) = 0;
		/**
		@brief 获取可用的扬声器列表
		@param [out] playerList 传回获取到的扬声器列表,第一个(索引0)为系统默认设备;
		@return 操作结果,NO_ERR表示无错误;如果没有可用扬声器,返回AV_ERR_DEVICE_NOT_EXIST错误码(错误码见github上的错误码表);
		*/
		virtual int getPlayerList( Vector< Pair<String/*id*/, String/*name*/> >& playerList ) = 0;
		/**
		@brief 获取任务栏打开的所有主窗口。
		@param [out] wndList 传回获取到的窗口列表(会过滤掉不可见窗口\无标题窗口\最小化窗状态的窗口)。
		@return 操作结果,NO_ERR表示无错误;如果没有可分享窗口,返回AV_ERR_DEVICE_NOT_EXIST错误码(错误码见github上的错误码表);
		@remark 用户可以调用此接口获取可以进行屏幕分享的窗口句柄列表,也可以自己获取;
		*/
		virtual int getWndList( Vector< Pair<HWND/*id*/, String/*name*/> >& wndList ) = 0;
		/**
		@brief 打开摄像头
		@param [in] szCameraId 通过getCameraList()函数获取的摄像头列表中的某个摄像头id
		@note 
		1、打开摄像头成功，如果用户有上传视频权限，便会自动开始上传摄像头视频;<br/>
		2、打开摄像头操作和打开自定义采集是互斥的操作;如果同时打开，会返回错误AV_ERR_EXCLUSIVE_OPERATION(错误码见github上的错误码表)
		*/
		virtual void openCamera(const String& szCameraId) = 0;
		/**
		@brief 关闭当前打开的摄像头
		*/
		virtual void closeCamera() = 0;
		/**
		@brief 打开自定义采集
		@note 
		1、打开自定义采集成功，如果用户有上传视频权限，用户通过fillExternalCaptureFrame()填入的每一帧画面将会通过sdk上传;<br/>
		2、打开摄像头操作和打开自定义采集是互斥的操作;如果同时打开，会返回错误AV_ERR_EXCLUSIVE_OPERATION(错误码见github上的错误码表);
		*/
		virtual void openExternalCapture() = 0;
		/**
		@brief 关闭自定义采集
		*/
		virtual void closeExternalCapture() = 0;
		/**
		@brief 外部输入视频数据接口。
		@return 操作结果，NO_ERR表示无错误;
		@note 
		1、目前sdk支持的VideoFrame格式只有COLOR_FORMAT_RGB24和COLOR_FORMAT_I420,如果传入的视频帧不是此两种格式，将返回ERR_NOT_SUPPORT;<br/>
		2、视频帧只能是这些辨率(176*144、192*144、320*240、480*360、640*368、640*480、960*540、1280*720、144*176、144*192、240*320、360*480、368*640、480*640、540*960、720*1280),否则返回AV_ERR_INVALID_ARGUMENT(错误码见github上的错误码表);<br/>
		3、视频帧率最好在10-15帧左右;
		4、传入的视频帧分辨率如果大于控制台SPEAR引擎配置的值，视频将会被裁剪到SPEAR配置的分辨率(主播端预览画面和观众端画面大小将会不一致);<br/>
		   如果小于控制台配置的值，将会按照传入的视频帧大小传入到观众端(即不会被放大到控制台配置的值);
		*/
		virtual int fillExternalCaptureFrame( const LiveVideoFrame &frame ) = 0;
		/**
		@brief 打开麦克风。
		@param [in] szMicId 通过getMicList()函数获取的麦克风列表中的某个麦克风id。
		@note 打开麦克风成功，如果用户有上传语音权限，便会自动开始上传麦克风音频。
		*/
		virtual void openMic(const String &szMicId) = 0;
		/**
		@brief 设置麦克风增强。
		@param [in] value 设置麦克风增强,取值范围[0,100].
		@return 操作结果，NO_ERR表示无错误;
		@note 
		1、这里是麦克风增强，不是指麦克风音量,即设置为0，还是会有音频输入;
		2、只有打开了麦克风才能进行设置,否则返回ERR_WRONG_STATE;<br/>
		3、如果后台SPEAR引擎配置打开了agc(麦克风自动增益),设置值太小时，会被自动调整回来;
		*/
		virtual int	setMicVolume(int value) = 0;
		/**
		@brief 获取麦克风增强。
		@return 返回麦克风增强,未打开麦克风则返回0;
		*/
		virtual uint32 getMicVolume() = 0;
		/**
		@brief 关闭当前打开的麦克风。
		*/
		virtual void closeMic() = 0;
		/**
		@brief 打开扬声器。
		@param [in] szPlayerId 通过getPlayerList()函数获取的扬声器列表中的某个扬声器id。
		@note 打开扬声器成功，如果用户有接收音频权限，便会自动开始播放远端音频。
		*/
		virtual void openPlayer(const String& szPlayerId) = 0;
		/**
		@brief 设置扬声器音量。
		@param [in] value 设置扬声器的目标音量,取值范围[0,100].
		@return 操作结果，NO_ERR表示无错误;
		@note 只有打开了扬声器才能进行设置,否则返回ERR_WRONG_STATE;
		*/
		virtual int setPlayerVolume( uint32 value ) = 0;
		/**
		@brief 获取扬声器音量。
		@return 返回扬声器音量,未打开扬声器则返回0;
		*/
		virtual uint32 getPlayerVolume() = 0;
		/**
		@brief 关闭当前打开的扬声器。
		*/
		virtual void closePlayer() = 0;
		/**
		@brief 打开屏幕分享(指定窗口)。
		@param [in] hWnd 所要捕获的窗口句柄(NULL表示全屏)。如果传入的hWnd不是有效窗口句柄\窗口不可见\窗口处于最小化状态，将会返回ERR_INVALID_PARAM;
		@param [in] fps 捕获帧率,取值范围[1,10]。
		@remark 传入的参数(fps)可能会经过sdk内部调整，并通过引用方式传回给调用者，实际分享使用的fps以传回值为准;
		@note
		屏幕分享和播片功能都是通过辅路流传输，所以屏幕分享和播片互斥使用;
		辅路流被自己占用，设备操作回调中，返回错误码AV_ERR_EXCLUSIVE_OPERATION(错误码见github上的错误码表);
		被房间内其他成员占用，设备操作回调中，返回错误码AV_ERR_RESOURCE_IS_OCCUPIED(错误码见github上的错误码表);
		*/
		virtual void openScreenShare( HWND hWnd, uint32& fps ) = 0;
		/**
		@brief 打开屏幕共享(指定区域)。
		@param [in] left/top/right/bottom 所要捕获屏幕画面的区域的左上角坐标(left, top)和右下角坐标(right, bottom)，它们是以屏幕的左上角坐标为原点的。
		@param [in] fps 捕获帧率，取值范围[1,10];
		@remark 传入的参数可能会经过sdk内部细微的调整，并通过引用方式传回给调用者，实际的分享区域以传回的值为准;
		@note
		屏幕分享和播片功能都是通过辅路流传输，所以屏幕分享和播片互斥使用;
		辅路流被自己占用，设备操作回调中，返回错误码AV_ERR_EXCLUSIVE_OPERATION(错误码见github上的错误码表);
		被房间内其他成员占用，设备操作回调中，返回错误码AV_ERR_RESOURCE_IS_OCCUPIED(错误码见github上的错误码表);
		*/
		virtual void openScreenShare( int32& left, int32& top, int32& right, int32& bottom, uint32& fps ) = 0;
		/**
		@brief 屏幕分享过程中,动态修改屏幕分享的区域。
		@param [in] left/top/right/bottom 所要捕获屏幕画面的区域的左上角坐标(left, top)和右下角坐标(right, bottom)，坐标以屏幕的左上角为原点。
		@return 操作结果，NO_ERR表示无错误。
		@remark 传入的参数可能会经过sdk内部细微的调整，并通过引用方式传回给调用者，实际的分享区域以传回的值为准;
		@note 此接口只有在打开了指定区域的屏幕共享时才有效,其他状态下将会返回ERR_WRONG_STATE错误;
		*/
		virtual int changeScreenShareSize( int32& left, int32& top, int32& right, int32& bottom ) = 0;
		/**
		@brief 关闭屏幕共享。
		@return 操作结果，NO_ERR表示无错误。
		@remark 指定窗口的屏幕分享和指定区域的屏幕分享都调用此接口来关闭.
		*/
		virtual void closeScreenShare() = 0;

		/**
		@brief 打开系统声音采集。
		@details 采集系统声音。
		@remark 文件播放和系统声音采集不应该同时打开，否则文件播放的声音又会被系统声音采集到，出现重音现象;
		*/
		virtual void openSystemVoiceInput() = 0;
		/**
		@brief 关闭系统声音采集。
		*/
		virtual void closeSystemVoiceInput() = 0;
		/**
		@brief 设置系统声音采集的音量。
		@param [in] value 设置目标音量,取值范围[0,100].
		@return 操作结果，NO_ERR表示无错误;
		@note 只有打开了系统声音采集才能进行设置,否则返回ERR_WRONG_STATE;
		*/
		virtual int	setSystemVoiceInputVolume( uint32 value ) = 0;
		/**
		@brief 获取系统声音采集音量。
		@return 返回系统声音采集音量,未打开则返回0;
		*/
		virtual uint32 getSystemVoiceInputVolume() = 0;

		/**
		@brief 打开文件播放。
		@details 开始播放本地音频\视频文件，播放文件前，最好先调用isValidMediaFile()检查文件的可用性。
		@param [in] szMediaFile 文件路径(可以是本地文件路径，也可以是一个网络文件的url);
		@remark
		1、支持的文件类型:<br/>
		*.aac,*.ac3,*.amr,*.ape,*.mp3,*.flac,*.midi,*.wav,*.wma,*.ogg,*.amv,
		*.mkv,*.mod,*.mts,*.ogm,*.f4v,*.flv,*.hlv,*.asf,*.avi,*.wm,*.wmp,*.wmv,
		*.ram,*.rm,*.rmvb,*.rpm,*.rt,*.smi,*.dat,*.m1v,*.m2p,*.m2t,*.m2ts,*.m2v,
		*.mp2v, *.tp,*.tpr,*.ts,*.m4b,*.m4p,*.m4v,*.mp4,*.mpeg4,*.3g2,*.3gp,*.3gp2,
		*.3gpp,*.mov,*.pva,*.dat,*.m1v,*.m2p,*.m2t,*.m2ts,*.m2v,*.mp2v,*.pss,*.pva,
		*.ifo,*.vob,*.divx,*.evo,*.ivm,*.mkv,*.mod,*.mts,*.ogm,*.scm,*.tod,*.vp6,*.webm,*.xlmv。<br/>
		2、目前sdk会对大于640*480的视频裁剪到640*480;<br/>
		3、文件播放和系统声音采集不应该同时打开，否则文件播放的声音又会被系统声音采集到，出现重音现象;
		@note
		屏幕分享和播片功能都是通过辅路流传输，所以屏幕分享和播片互斥使用;
		辅路流被自己占用，设备操作回调中，返回错误码AV_ERR_EXCLUSIVE_OPERATION(错误码见github上的错误码表);
		被房间内其他成员占用，设备操作回调中，返回错误码AV_ERR_RESOURCE_IS_OCCUPIED(错误码见github上的错误码表);
		*/
		virtual void openPlayMediaFile( const String& szMediaFile ) = 0;
		/**
		@brief 关闭文件播放。
		*/
		virtual void closePlayMediaFile() = 0;
		/**
		@brief 从头播放文件。
		@return 操作结果，NO_ERR表示无错误。
		@note 只有在处于播放状态下(E_PlayMediaFilePlaying)，此接口才有效，否则返回ERR_WRONG_STATE;
		*/
		virtual int restartMediaFile() = 0;
		/**
		@brief 暂停播放文件。
		@return 操作结果，NO_ERR表示无错误。
		*/
		virtual int pausePlayMediaFile() = 0;
		/**
		@brief 恢复播放文件。
		@return 操作结果，NO_ERR表示无错误。
		*/
		virtual int	resumePlayMediaFile() = 0;
		/**
		@brief 设置播放文件进度。
		@param [in] n64Pos 播放位置(单位: 秒)
		@return 操作结果，NO_ERR表示无错误。
		*/
		virtual int setPlayMediaFilePos(const int64& n64Pos) = 0;
		/**
		@brief 获取播放文件进度。
		@param [out] n64Pos 当前播放位置(单位: 秒)
		@param [out] n64MaxPos 当前所播放文件的总长度(单位: 秒)
		@return 操作结果，NO_ERR表示无错误。
		*/
		virtual int getPlayMediaFilePos(int64& n64Pos, int64& n64MaxPos) = 0;
		/**
		@brief 判断文件是否可用于播放。
		@param [in] szMediaFile 要检查的视频文件.
		@return 是否可用;如果文件不存在，也会返回false;
		*/
		virtual bool isValidMediaFile(const String& szMediaFile) = 0;

		/**
		@brief 设置音视频SDK画面的水印.
		@param [in] waterMarkType 水印类型，参考E_WaterMarkType说明;
		@param [in] argbData 水印的argb格式数据;
		@param [in] width 水印宽度;
		@param [in] height 水印高度;
		@return 操作结果，NO_ERR表示无错误。
		@remark 
		1、只能在登录成功，打开主路视频(摄像头\自定义采集)之前调用此接口。<br/>
		2、为了所有画面都有水印效果，用户Spear上配置的各个分辨率都应该设置相应水印;<br/>
		3、为了性能考虑，设置了水印后，主播自己的预览画面不会显示水印，观众端才会显示水印。<br/>
		4、水印大小限制规则为: 水印宽度不大于画面宽度的1/4,高度不能大于1/6,且水印宽高都必须为2的倍数;<br/>
		5、sdk暂时只支持对主路视频设置水印,不支持对辅路设置水印;
		*/
		virtual int addWaterMark(E_WaterMarkType waterMarkType, uint8* argbData, uint32 width, uint32 height) = 0;

		/**
		@brief 设置sdk的日志路径
		@return 操作结果，true成功，false失败
		@remark 为避免调用此接口前后日志打印到不同目录下,限制只能在sdk任何接口调用之前调用此接口，否则返回false;
		*/
		virtual bool setLogPath(const String& szLogPath) = 0;

		/**
		@brief 获取当前摄像头状态
		@return true:打开 false：关闭
		*/
		virtual bool getCurCameraState() = 0;
		/**
		@brief 获取自定义采集状态。
		@return true:打开 false：关闭
		*/
		virtual bool getExternalCaptureState() = 0;
		/**
		@brief 获取当前麦克风状态
		@return true:打开 false：关闭
		*/
		virtual bool getCurMicState() = 0;
		/**
		@brief 获取当前扬声器状态
		@return true:打开 false：关闭
		*/
		virtual bool getCurPlayerState() = 0;
		/**
		@brief 获取当前屏幕分享状态
		@return 当前屏幕分享状态
		*/
		virtual E_ScreenShareState getScreenShareState() = 0;
		/**
		@brief 获取当前文件播放状态。
		@return 当前文件播放状态.
		*/
		virtual E_PlayMediaFileState getPlayMediaFileState() = 0;
		/**
		@brief 获取当前系统声音采集状态
		@return true:打开 false：关闭
		*/
		virtual bool getCurSystemVoiceInputState() = 0;

	};

	/**
	@brief 获取iLive的指针
	@return iLive的指针
	*/
	extern "C" iLiveAPI iLive* GetILive();


}
#endif //iLive_h_