#ifndef PAUSESTATE_HPP
#define PAUSESTATE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Container.hpp"
#include "Button.hpp"

class PauseState : public State {
    private:
        sf::Sprite mBackgroundSprite;
        sf::Text mPausedText;
        GUI::Container mGUIContainer;
        
    public:
        PauseState(StateStack& stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);
};

#endif // PAUSESTATE_HPP