# Ultra Engine - Architecture

# Runtime Engine Architecture

Ultra Engine, like all software systems and game engines, is built in layers. In order to avoid circular dependencies
which negatively impact testability, platform independence, and re-usability/modularity, the lower layers do not depend
on upper layers.

From top to bottom, the layers are:

* Game-Specific Subsystems
* Gameplay Foundations, Rendering, Profiling & Debugging, Scene Graph / Culling, Visual Effects, Front End, Skeletal
  Animation Collision & Physics, Animation, AI, HID Audio, Input
* Resources (Resource Manager)
* Core Systems
* Platform Independence Layer (Networking, File System)
* 3rd Party SDKs (DirectX, OpenGL, PhysX)
* OS
* Drivers
* Hardware

To keep the project modular, many features within these layers (e.g. Replication Graph, Gameplay Ability System) are
separated out into optional Plugins.

## Target Hardware Layer

This layer is platform-specific. Generally, the engine is platform-agnostic, but there are some platform-specific
code and optimizations for different computer or console systems.
The Quake 2 engine, for example, had
significant [optimizations made for the Intel's Pentium processor and its pre-fetching cache](https://fabiensanglard.net/quake2/quake2_software_renderer.php)
due to their popularity at the time.

### Apple

### Xbox

### Playstation

### Nintendo

### Mobile

### Web

### VR

## Drivers Layer

Drivers manage hardware resources and provide an interface (abstraction) for the operating system to interact with the
myriad variants of hardware devices.

## Operating System Layer

This part of the engine handles the various operating systems which share hardware resources between multiple
applications, one being your game. Unlike consoles of old
where a game could "own" the entire device and assume full control of memory
and compute resources, modern consoles can have multiple applications running alongside your game (e.g. Xbox Live,
Netflix, Voice Chat, store downloads) that take over certain system resources or
pause the game entirely (Xbox Dashboard). At that time, a layer like this was nonexistent or at most limited to a
library that directly access hardware resources.

Some reasons why this layer exists:

* Implement memory access and tracking for each platform.
* Obtain platform properties regarding features that are supported (e.g. Texture Streaming, High Quality Light Maps,
  Audio Streaming)
* Access (and wrap functions for) platform native APIs (e.g. Atomics, File I/O, Time)
* Execute general platform commands (e.g. get orientation of screen, get network type)
* Provide platform-specific implementations of OS functions

### Windows

#### The Window

The engine starts with a window. The operating system provides the fundamental functionality, such as the APIs (e.g. Windows API) and the graphical subsystem
for creating and managing a windows. The graphical subsystem refers to a stack of software and hardware components responsible for rendering the graphics on
your screen. The window manager handles the drawing, positioning, resizing, and user interactions with the window. The Graphics Device Interface (GDI) is what creates
the graphical content by communicating with the graphics drivers by sending commands. The graphics drivers translate the commands from the GDI into instructions
the graphics hardware can understand. And finally, the the graphics hardware is the physical component that renders the graphics on the screen by creating a
frame buffer, applying algorithms to each pixel on the frame buffer, and display the final image.

#### Entry Point

### MacOS & iOS

### Linux

## 3rd Party SDKs Layer

### Graphics

#### DirectX

Microsoft's 3D graphics API. SDKs for DirectX 9, 11, and 12 are found under `ThirdParty/Windows/DX9`
, `ThirdParty/Windows/DX11`, and `ThirdParty/Windows/DX12`.

These SDKs are primarily used for DirectX RHI implementations, some others include shader compilation. Compared to OpenGL,
it provides a higher level of abstraction and leverages Microsoft hardware optimizations.

#### Vulkan

Khronos Group's Vulkan provides a lower-level API compared to DirectX and OpenGL, enabling more efficient use of the GPU. In addition, it allows sending GPGPU (General Purpose GPU) commands to the GPU.

#### OpenGL

Portable 3D graphics SDK.

### Physics & Collision

#### Nvidia PhysX

## Platform Independence Layer

### Platform Detection

### Primitive Data Types

### Collections & Iterators

### File System

### Networking

### Hi-Res Timer

### Threading Library

#### Thread

A thread is a theoretical concept representing a component of a process. A process is a unit of resources, while a
thread is a unit of scheduling and execution. You can analogize it to a cotton thread, a long thin strand of cotton
fibers used for sewing, except the
cotton fibers are sequential instructions. This thread includes the scheduling and execution of these instructions by
the CPU. You can consider the execution of the functions in your game as a thread.

##### Usage

##### Program Stack

### Graphics Wrappers

### Physics & Collision Wrappers

## Core Systems Layer

### Data Structures & Algorithms

All software systems require containers that allow for the storage and manipulation of data and algorithms that use
these data structures to solve problems. Many projects use standard and
third-party libraries that provide implementations of these data structure and algorithms.

#### Data Structures

##### Container Table

#### Algorithms

##### Algorithm Table

### Module Start-Up and Shut-Down

### Assertions

### Automation

#### Unit Testing

#### Gauntlet

### Memory Allocation

### Math Library

### Strings and Hashed String Ids

#### FName

### Debug Printing and Logging

### Localization Services

### Movie Player

### Parsers

### Profiling / Stats Gathering

### Engine Config

### Random Number Generator

### Curves & Surfaces Library

### RTTI / Reflection & Serialization

### Object Handles / Unique Ids

### Asynchronous File I/O

## Resources (Game Assets) Layer

### Resource Manager (UnrealEd)

### 3D Model Resource

### Texture Resource

### Material Resource

### Font Resource

### Skeleton Resource

### Collision Resource

### Physics Parameters

### Game World/Map

## Collision & Physics Layer

This layer of the engine handles collision detection and rigid body dynamics (which is where it gets "physics" from).
Calling it physics is a bit of a
misnomer, as the engine is primarily concerned about forces and torques acting on rigid bodies, and not much of anything
else.

Typically, game engines do not implement their own physics engine. Instead, they use SDKs from a third-party physics &
collision engine.

### Forces & Constraints

### Ray/Shape Casting (Queries)

### Rigid Bodies

### Phantoms

### Shapes / Collidables

### Physics/Collision World

## Human Interface Devices (HID) Layer

### Game-Specific Interface

### Physical Device I/O

## Profiling & Debugging Layer

### Recording & Playback

### Memory & Performance Stats

### In-Game Menus or Console

## Low-Level Renderer Layer

### Graphics Device Interface

#### DirectX RHI

#### Vulkan RHI

#### OpenGL RHI

### Materials & Shaders

### Static & Dynamic Lighting

### Cameras

### Text & Fonts

### Primitive Submission

### Viewports & Virtual Screens

### Texture & Surface Management

### Debug Drawing (Lines etc.)

## Scene Graph / Culling Optimizations Layer

### Spatial Hash (BSP, Tree, kd-Tree, ...)

### Occlusion & PVS

### LOD System

## Visual Effects Layer

### Light Mapping & Dynamic Shadows

### HDR Lighting

### PRT Lighting, Subsurface Scatter

### Particle & Decal Systems

### Post Effects

### Environment Mapping

## Front End Layer

### Heads-Up Display (HUD)

### Full-Motion Video (FMV)

### In-Game Cinematics (IGC)

### In-Game GUI

### In-Game Menus

### Wrappers / Attract Mode

## Skeletal Animation layer

### Animation State Tree & Layers

### Inverse Kinematics (IK)

### Hierarchical Object Attachment (+Gameplay Foundations Layer)

### Game-Specific Post-Processing

### LERP and Additive Blending

### Animation Playback

### Sub-skeletal Animation

### Animation Decompression

### Skeletal Mesh Rendering (+Low-Level Renderer Layer)

### Ragdoll Physics (+Collision & Physics Layer)

## Audio Layer

### DSP/Effects

### 3D Audio Model

### Audio Playback / Management

## Online Multiplayer Layer

### Matchmaking & Game Management

### Object Authority Policy

### Game State Replication

## Gameplay Foundations Layer

### High-Level Game Flow System/FSM

### Scripting System

### Static World Elements

### Dynamic Game Object Model

##### Automatic Property Initialization

##### Factory Methods

##### Automatic Updating of References

##### Serialization

#### Composition OOP Design Pattern - Components

### Real-Time Agent-Based Simulation

### Event/Messaging System

### World Loading / Streaming

## Game-Specific Subsystems Layer

### Game Specific Rendering

#### Terrain Rendering

#### Water Simulation & Rendering

### Player Mechanics

#### State Machine & Animation

##### Gameplay Ability System

#### Camera-Relative Controls (HID) (+Game Cameras)

#### Collision Manifold

#### Movement

### Game Cameras

#### Fixed Cameras

#### Scripted/Animated Cameras

#### Player-Follow Camera

#### Debug Fly-Through Cam

### AI

#### Goals & Decision-Making

#### Actions (Engine Interface)

#### Sight Traces & Perception

#### Pathfinding (A*)

## Game Layer (Game Code)

### RTS & TBS

#### Fog of War

### FPS, TPS, & RPG

### Weapons

### Abilities

# Editor Architecture

### Skeletons and Animation

#### Skeleton Editor

#### Skeletal Mesh Editor

#### Animation Editor

#### Animation Blueprint Editor

#### Physics editor
