#pragma once
#include "esphome.h"

enum class InputAction {
    CW,
    CCW,
    PRESS
};

struct PageRoute {
    esphome::lvgl::LvPageType* page;
    esphome::script::Script<>* on_cw;
    esphome::script::Script<>* on_ccw;
    esphome::script::Script<>* on_press;
};

inline void dispatch_page_action(InputAction action, std::initializer_list<PageRoute> routes) {
    for (const auto& route : routes) {
        if (route.page != nullptr && route.page->is_showing()) {
            switch (action) {
                case InputAction::CW:
                    if (route.on_cw != nullptr) {
                        route.on_cw->execute();
                    }
                    break;
                case InputAction::CCW:
                    if (route.on_ccw != nullptr) {
                        route.on_ccw->execute();
                    }
                    break;
                case InputAction::PRESS:
                    if (route.on_press != nullptr) {
                        route.on_press->execute();
                    }
                    break;
            }
            break;  // Exit the loop after handling the first visible page
        }
    }
}