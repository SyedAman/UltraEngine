#include <vulkan/vulkan.h>


class IRenderHardwareInterface {
public:
    virtual ~IRenderHardwareInterface() = default;
    virtual VkInstance CreateVulkanInstance() = 0;
};

class RenderHardwareInterface : public IRenderHardwareInterface {
    VkApplicationInfo FillOutApplicationInfo();
    VkInstanceCreateInfo CreateInstanceCreateInfo(VkApplicationInfo appInfo);

public:
    VkInstance CreateVulkanInstance() override;
};
