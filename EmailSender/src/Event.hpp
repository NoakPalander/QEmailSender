#ifndef EVENT_HPP
#define EVENT_HPP

#include <functional>
#include <memory>

namespace logic {
    typedef std::function<void(void)> EventHandle;

    class Event {
        public:
            Event();
            ~Event();

            Event(const EventHandle& event);
            Event(const Event& event);
            Event(Event&& event) noexcept;

            Event& operator=(const Event& event);
            Event& operator=(Event&& event) noexcept;

            void operator=(const EventHandle& event);

            bool Exec();

        private:
            std::shared_ptr<EventHandle> m_Event = nullptr;
    };
}

/* --- Class Alias --- */
namespace event {
    typedef std::shared_ptr<logic::Event> handle;
}


#endif // EVENT_HPP
