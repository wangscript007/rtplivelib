
#pragma once

#include "../core/config.h"
#include <string>
#include <vector>

namespace rtplivelib {

namespace device_manager{

//用于处理显卡信息
struct GPUInfo{
	/*显卡名字*/
	std::string						name;
	uint32_t						id;
	uint64_t						video_memory;
	uint64_t						system_memory;
	/*该显卡输出的屏幕信息,size为0则是没有屏幕输出,目前只设置显示器名称*/
	std::vector<std::string>		screen_list;
};

/**
 * @brief The GPUIdentify class
 * 该类用于检测显卡和显示器的信息
 * 该类内部使用，外部如果需要知道显卡信息可以通过DesktopCapture来获取
 * 
 */
class RTPLIVELIBSHARED_EXPORT GPUIdentify{
public:
	/**
	 * @brief Get_All_GPU_Info
	 * 获取所有显卡和显示器信息
	 * @return 
	 */
	static std::vector<GPUInfo> Get_All_GPU_Info() noexcept;

};

}	//device_manager

}	//rtplivelib


