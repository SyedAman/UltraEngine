#include <vulkan/vulkan_core.h>

class IRenderHardwareInterface
{
public:
    virtual ~IRenderHardwareInterface() = default;
    virtual VkInstance CreateVulkanInstance() = 0;
};
