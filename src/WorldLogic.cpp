#include "WorldLogic.h"

#include <UnigineConsole.h>
#include <UnigineInput.h>
#include <UnigineWorld.h>
#include <UnigineApp.h>
#include <UnigineControls.h>
#include <UnigineEditor.h>
#include <Windows.h>

using namespace Unigine;

int MyWorldLogic::init()
{
    takeFocus();
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

void MyWorldLogic::takeFocus()
{
    App::setMouseGrab(true);
    ControlsApp::setMouseHandle(Input::MOUSE_HANDLE_GRAB);
    ControlsApp::setMouseEnabled(true);
    if (debug)
    {
        Log::message("active\n");
    }
}

void MyWorldLogic::unfocus()
{
    App::setMouseGrab(false);
    ControlsApp::setMouseHandle(Input::MOUSE_HANDLE_USER);
    // ControlsApp::setMouseEnabled(false);
    if (debug)
    {
        Log::message("is not active\n");
    }
}

void MyWorldLogic::check_have_focus()
{
    if (Editor::isLoaded()) return;
    
    const bool is_in_focus = isAppInFocus();

    if (is_in_focus == is_last_focused_) return;
    
    if (is_in_focus)
    {
        is_last_focused_ = true;
        takeFocus();
    }
    else
    {
        is_last_focused_ = false;
        unfocus();
    }
}

bool MyWorldLogic::isAppInFocus()
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
