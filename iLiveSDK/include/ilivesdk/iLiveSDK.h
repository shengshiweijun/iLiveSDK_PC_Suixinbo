#ifndef iLiveSDK_h_
#define iLiveSDK_h_

#include <imsdk/tim.h>
#include <imsdk/tim_comm.h>
#include <avsdk/av_context.h>
#include <ilivesdk/iLiveCommon.h>
using imcore::TIMMessageCallBack;
using imcore::TIMConnCallBack;
using imcore::TIMForceOfflineCallBack;
using imcore::TIMManager;
using tencent::av::AVContext;

namespace ilivesdk
{
	/**
	@brief iLiveSDK���������һ��SDK����ʵ����
	@note ʹ��iLiveSDKǰ���������initSdk()������ʼ��SDK��
	*/
	class iLiveAPI iLiveSDK
	{
	public:
		/**
		@brief ��ȡ��������
		@return ��������
		*/
		static iLiveSDK*	getInstance();

		/**
		@brief �����յ�IM��Ϣʱ�Ļص���
		@details �յ�IM��Ϣʱ������ô˺������õĻص���
		@param [in] cb �ص��ӿڵ�ָ��;
		@note ������initSdk()֮�������ô˻ص�;
		*/
		void				SetMessageCallBack(TIMMessageCallBack *cb);//�յ���Ϣ�Ļص���������initSdk֮�����
		/**
		@brief ����IM���ӺͶϿ��������Ļص���
		@param [in] cb �ص��ӿڵ�ָ��;
		@note ���Ҫ���ô˻ص���������initSdk()֮ǰ���ô˻ص���������Ч;
		*/
		void				SetConnCallBack(TIMConnCallBack* cb);
		/**
		@brief ���ñ������ߵĻص���
		@param [in] cb �ص��ӿڵ�ָ��;
		@note ���Ҫ���ô˻ص���������initSdk()֮ǰ���ô˻ص���������Ч;
		*/
		void				SetForceOfflineCallback(TIMForceOfflineCallBack* cb);
		/**
		@brief ��ʼ��iLiveSDK��
		@note ʹ��iLiveSDKǰ��������ô˺�����ʼ��SDK��
		@param [in] appId ��ѶΪÿ�����뷽������˺�id
		@param [in] accountType ��ѶΪÿ�����뷽������˺�����
		@return ���ز������,�ɹ��򷵻�NO_ERR
		*/
		int					initSdk(const int appId, const int accountType);
		/**
		@brief �ͷ��ڲ���Դ,�����˳�ʱ��Ҫ����
		*/
		void				destroy();
		/**
		@brief ��ȡTIMManager�൥������
		@details �û����Ի�ȡTIMManager���󣬴Ӷ�����һЩ�Զ�������;
		@return ����TIMManager�������������;
		*/
		TIMManager&			getTIMManager();
		/**
		@brief ��ȡAppId��
		@details ��ȡ�ڳ�ʼ�������д����appId
		@return ����appId
		*/
		int					getAppId();
		/**
		@brief ��ȡApp���˺����͡�
		@details ��ȡ�ڳ�ʼ�������д����accountType
		@return ����accountType
		*/
		int					getAccountType();
		/**
		@brief ��ȡAVContext����
		@details ��ȡAVContext����;
		@return ����iLiveSDK�ڲ�������ά����AVContext����ָ��;
		*/
		AVContext*			getAVContext();
		/**
		@brief ��ȡ�汾�š�
		@return ���ذ汾���ַ���;
		*/
		const char*			getVersion();

	private:
		iLiveSDK();
		~iLiveSDK();

	private:
		int					m_appId;
		int					m_accountType;
		AVContext*			m_pAVContext;
		std::string			m_szVersion;

		HMODULE							m_hMoude;
		PROC_AVAPI_GetVersion			m_funcGetVersion;
		PROC_AVAPI_CreateContext		m_funcCreateContext;	
		PROC_AVAPI_EnableCrashReport	m_funcEnableCrashReport;
	};
}

#endif //iLiveSDK_h_