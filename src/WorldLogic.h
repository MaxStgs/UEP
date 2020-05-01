#pragma once
#include <UnigineLogic.h>

class MyWorldLogic : public Unigine::WorldLogic
{

    bool is_last_focused_ = true;

    bool debug = false;
    
public:
    // initialize world
    int init() override;

    int update() override;
    static void update_my_node();

    static void check_should_reload_world();
    void takeFocus();
    void unfocus();
    void check_have_focus();
    static bool isAppInFocus();

    // shutdown world
    int shutdown() override;
};
