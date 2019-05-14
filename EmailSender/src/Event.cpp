#include "Event.hpp"


namespace logic {
    Event::Event() = default;
    Event::~Event() = default;


    Event::Event(const logic::EventHandle& event)
        : m_Event(std::make_shared<EventHandle>(event)) {}


    Event::Event(const Event& event) {
        m_Event = std::make_shared<EventHandle>(*event.m_Event.get());
    }


    Event::Event(Event&& event) noexcept {
        m_Event = std::move(event.m_Event);
    }


    Event& Event::operator=(const Event& event) {
        if (this != &event) {
            m_Event = std::make_shared<EventHandle>(*event.m_Event.get());
        }

        return *this;
    }


    Event& Event::operator=(Event&& event) noexcept {
        if (this != &event) {
           m_Event = std::move(event.m_Event);
        }

        return *this;
    }


    void Event::operator=(const EventHandle& event) {
        m_Event = std::make_shared<EventHandle>(event);
    }


    bool Event::Exec() {
        if (m_Event != nullptr) {
            (*m_Event.get())();
            return true;
        }

        return false;
    }
}
