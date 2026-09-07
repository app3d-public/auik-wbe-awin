#pragma once

#include <acul/event.hpp>
#include <acul/pair.hpp>
#include <acul/scalars.hpp>
#include <auik-wbe-awin/symbol_export.h>
#include <auik/detail/events.hpp>
#include <awin/awin.hpp>

namespace auik
{
    namespace detail
    {
        struct AwinBackend final : WindowContext
        {
            awin::Window &window;
            acul::events::dispatcher &event_dispatcher;
            awin::Cursor cursors[detail::CursorID::max];
            acul::ipoint32 initial_display_size{};

            AwinBackend(awin::Window &window, acul::events::dispatcher &event_dispatcher,
                        acul::ipoint32 initial_display_size = {})
                : window(window), event_dispatcher(event_dispatcher), initial_display_size(initial_display_size)
            {
            }
        };
    } // namespace detail

    AUIK_WBE_AWIN_EXPORT detail::WindowContext *create_awin_backend(awin::Window &window,
                                                                    acul::events::dispatcher &event_dispatcher,
                                                                    acul::ipoint32 initial_display_size = {});

} // namespace auik
