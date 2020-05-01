#pragma once
#include <UniginePlugin.h>

#include "WorldLogic.h"

using namespace Unigine;

class uep : public Unigine::Plugin
{
public:
    uep()
    {
        Log::message("MyPlugin::MyPlugin(): called\n");
    }

    virtual ~uep()
    {
        Log::message("MyPlugin::~MyPlugin(): called\n");
    }

    // uep data
    void* get_data() override
    {
        return this;
    }

    // initialize uep
    int init() override;

    // shutdown uep
    int shutdown() override;

    // destroy uep
    void destroyRenderResources() override;

private:
    MyWorldLogic world_logic;
};
