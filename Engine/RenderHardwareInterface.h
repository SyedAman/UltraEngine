/**
 * The Render Hardware Interface is the abstraction layer that sits between the game engine and the underlying graphics
 * API. Its responsibility is to provide a unified, __platform-agnostic__ interface for rendering operations, allowing
 * the game engine to work seamlessly across multiple platforms and graphics APIs.
 *
 * This helps us avoid writing rendering code more than once.
 */

#pragma once

#include "IRenderHardwareInterface.h"
#include "IGraphicsAPI.h"


class RenderHardwareInterface : public IRenderHardwareInterface
{
    IGraphicsAPI* m_GraphicsAPI;

public:
    RenderHardwareInterface(IGraphicsAPI* GraphicsAPI) : m_GraphicsAPI(GraphicsAPI) {}

    void* CreateInstance() override;
};
