
#pragma once

#include "config.h"
#include <string>
#include <string.h>

namespace rtplivelib {

namespace core {

constexpr char MessageString[][128] = {
	"Function not implemented",
	"SwsContext initialization failed",
	"frame packet alloc failed or data alloc failed",
	"data alloc failed(FramePacket)",
	"frame alloc failed(FramePacket)",
	"packet alloc failed(FramePacket)",
	"frame packet copy failed",
	"AVInputFormat not find({})",
	"Close input format context",
	"Open input format context,device:[{}],result:[{}]",
	"Device change Device_change_success,current name:{}",
	"device read frame failed",
	"[{}]Device stop capture",
	"Device information acquisition failed ",
	"create sdl_window failed",
	"create sdl_renderer failed",
	"create sdl_texture failed",
	"New format:[{}]",
	"set show window id",
	"This format[{}] is not supported",
	"crop filter initialization failed",
	"Cropping failed, it may be was not successfully allocated frame when the filter was initialized",
	"encoder({}) not found",
	"decoder({}) not found",
	"encoder({}) was successfully initialized",
	"decoder({}) was successfully initialized",
	"(decoder)parser initialization failed",
	"The parser and codec are not initialized",
	"Codec context alloc failed",
	"Could not open codec",
	"frame rate must more than zero",
	"codec context null",
	"receive packet failed",
	"alloc hardware device context ({}) failed",
	"create hardware device context ({}) failed",
	"create hardware device context ({}) success",
	"create {} frame context failed",
	"create {} frame context success",
	"set AVHWFramesContext failed",
	"invalid format",
	"rtp ( {} session ) listening port({}) success",
	"rtp ( {} session ) listening port({}) failed",
	"rtp ( {} session ) create destination(ip:{}.{}.{}.{},port:{}) success",
	"rtp ( {} session ) create destination(ip:{}.{}.{}.{},port:{}) failed",
	"rtp ( {} session ) set payload type failed",
	"rtp ( {} session ) set mark failed",
	"rtp ( {} session ) set timestamp increment failed",
	"rtp send packet failed",
	"rtp send packet success ( size:{} )",
	"function is abnormal because there is no {} session set up",
	"rtp destroy session(reason:{})",
	"(rtcp)adding users has an unexpected error,new(name[{}],ssrc[{}]),old(name[{}],ssrc1[{}],ssrc2[{}])",
	"(rtcp)unexpected data encountered when removed,user name is [{}]",
	"FEC encode_failed",
	"time setting must be greater than zero"
};

enum struct MessageNum {
	Function_not_implemented = 0x00,
	SwsContext_init_failed,
	FramePacket_alloc_failed,
	FramePacket_data_alloc_failed,
	FramePacket_frame_alloc_failed,
	FramePacket_packet_alloc_failed,
	FramePacket_copy_failed,
	InputFormat_format_not_found,
	InputFormat_context_close,
	InputFormat_context_open,
	Device_change_success,
	Device_read_frame_failed,
	Device_stop_capture,
	Device_info_failed,
	SDL_window_create_failed,
	SDL_renderer_create_failed,
	SDL_texture_create_failed,
	SDL_show_format_update,
	SDL_set_window_id,
	SDL_not_supported_format,
	Crop_filter_init_failed,
	Crop_failed_dst_frame_not_alloc,
	Codec_encoder_not_found,
	Codec_decoder_not_found,
	Codec_encoder_init_success,
	Codec_decoder_init_success,
	Codec_decoder_parser_init_failed,
	Codec_parser_or_codec_not_init,
	Codec_codec_context_alloc_failed,
	Codec_codec_open_failed,
	Codec_frame_rate_must_more_than_zero,
	Codec_packet_ctx_null,
	Codec_receive_packet_failed,
	Codec_hardware_ctx_alloc_failed,
	Codec_hardware_ctx_create_failed,
	Codec_hardware_ctx_create_success,
	Codec_hard_frames_create_failed,
	Codec_hard_frames_create_success,
	Codec_set_hard_frames_ctx_failed,
	Format_invalid_format,
	Rtp_listening_port_base_success,
	Rtp_listening_port_base_failed,
	Rtp_create_destination_success,
	Rtp_create_destination_failed,
	Rtp_set_payload_type_failed,
	Rtp_set_mark_failed,
	Rtp_set_timestamp_increment_failed,
	Rtp_send_packet_failed,
	Rtp_send_packet_success,
	Rtp_not_set_session,
	Rtp_destroy_session,
	Rtcp_insert_user_failed,
	Rtcp_remove_abnormal,
	FEC_encode_failed,
	Timer_time_less_than_zero
};

} // namespace core

} // namespace rtplivelib
