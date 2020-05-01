#pragma once
#include <UnigineLogic.h>

class MyWorldLogic : public Unigine::WorldLogic
{

    bool is_last_focused_ = true;
    
public:
    // initialize world
    int init() override;

    int update() override;
    static void update_my_node();

    static void check_should_reload_world();
    void check_have_focus();
    static bool is_current_app_in_focus();

    // shutdown world
    int shutdown() override;
};
