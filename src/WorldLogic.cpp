#include "WorldLogic.h"

#include <UnigineConsole.h>
#include <UnigineInput.h>
#include <UnigineWorld.h>
#include <UnigineApp.h>
#include <UnigineControls.h>
#include <Windows.h>

using namespace Unigine;

int MyWorldLogic::init()
{
    Log::message("uep MyWorldLogic::init()\n");
    return 1;
}

int MyWorldLogic::update()
{
    update_my_node();
    check_should_reload_world();
    check_have_focus();
    return 1;
}

void MyWorldLogic::update_my_node()
{
    const NodePtr node = World::getNodeByName("simple_node");
    if (node != nullptr)
    {
        Log::message("Node found\n");
    }
}

void MyWorldLogic::check_should_reload_world()
{
    if (Input::isKeyPressed(Input::KEY_CTRL)
        && Input::isKeyPressed(Input::KEY_SHIFT)
        && Input::isKeyPressed(Input::KEY_R))
    {
        Console::run("world_reload");
    }
    if (Input::isKeyPressed(Input::KEY_R))
    {
        Log::message("Ctrl pressed!\n");
    }
}

void MyWorldLogic::check_have_focus()
{
    const bool current_focused = is_current_app_in_focus();

    if (current_focused == is_last_focused_) return;
    
    if (current_focused)
    {
        is_last_focused_ = true;
        App::setMouseGrab(true);
        ControlsApp::setMouseHandle(Input::MOUSE_HANDLE_GRAB);
        ControlsApp::setMouseEnabled(true);
        Log::message("active\n");
    }
    else
    {
        is_last_focused_ = false;
        App::setMouseGrab(false);
        ControlsApp::setMouseHandle(Input::MOUSE_HANDLE_USER);
        // ControlsApp::setMouseEnabled(false);
        Log::message("is not active\n");
    }
}

bool MyWorldLogic::is_current_app_in_focus()
{
    DWORD activePID;
    GetWindowThreadProcessId(GetForegroundWindow(), &activePID);
    
    return activePID == GetCurrentProcessId();
}


int MyWorldLogic::shutdown()
{
    Log::message("reload_world_plugin MyWorldLogic::shutdown()\n");

    return 1;
}
