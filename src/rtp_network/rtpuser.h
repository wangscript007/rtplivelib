
#pragma once 

#include "../core/config.h"
#include "../codec/videodecoder.h"
#include "../codec/audiodecoder.h"
#include "../codec/hardwaredevice.h"
#include "../player/videoplayer.h"
#include "rtpsession.h"
#include "rtppacket.h"
#include "fec/fecdecoder.h"
#include <string>

namespace rtplivelib{

namespace rtp_network {

class RTPUserManager;
/**
 * @brief The RTPUser struct
 * 该结构体用于描述正在房间的用户的信息
 */
struct RTPLIVELIBSHARED_EXPORT RTPUser
{
	/**
	 * @brief The UserType enum
	 * 用户类型
	 * only pull的话是只拉流，不推流，所以应该是观众
	 * pull and push的话就是又推又拉了
	 */
	enum UserType {
		ONLY_PULL,
		PULL_AND_PUSH
	};
	
	/*自己的会话ssrc*/
	uint32_t ssrc{0};
	/*与自己配套(音频和视频)的另一个会话ssrc*/
	uint32_t another_ssrc{0};
	/*用户名,唯一标识*/
	std::string name;
	/*用户类型,用于判断是否有流接收*/
	/*如果是PULL_AND_PUSH的话，则需要处理媒体数据*/
	/*如果是ONLY_PULL的话，只拉流*/
	/*目前该字段没有使用*/
	UserType ut{UserType::ONLY_PULL};
	
	RTPUser();
	
	~RTPUser();
	
	RTPUser(const RTPUser&) = delete;
	
	RTPUser& operator = (const RTPUser&) = delete;
	
protected:
	
	/**
	 * @brief deal_with_packet
	 * 重载函数，处理媒体数据
	 * 注意:使用该接口将会获得rtp_packet指针的所有权
	 * 不需要外部释放指针
	 */
	void deal_with_packet(RTPPacket::SharedRTPPacket rtp_packet) noexcept;
	
	/**
	 * @brief set_win_id
	 * 设置需要显示的窗口id
	 * @param id
	 */
	void set_win_id(void *id) noexcept;
	
	/**
	 * @brief set_hwd_type
	 * 设置视频解码硬件加速类型，默认设置为Auto，加速方案启动失败则会设置为None
	 */
	void set_video_hwd_type(codec::HardwareDevice::HWDType type) noexcept;
	
	/**
	 * @brief get_video_hwd_type
	 * 获取视频解码器的实际使用的硬解加速方案，而不是预设方案
	 * 如果没有使用加速方案，则是返回None
	 * @return 
	 */
	codec::HardwareDevice::HWDType get_video_hwd_type() noexcept;
	
	void set_display_screen_size(const int &win_w,const int & win_h,
								 const int & frame_w,const int & frame_h) noexcept;
private:
	codec::VideoDecoder			_vdecoder;
	codec::AudioDecoder			_adecoder;
	player::VideoPlayer			_vplay;
	fec::FECDecoder				_afecdecoder;
	fec::FECDecoder				_vfecdecoder;
	
	friend class RTPUserManager;
};

} // rtp_network

} // rtplivelib
