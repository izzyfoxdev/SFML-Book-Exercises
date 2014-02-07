#include <typeinfo>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <gtest/gtest.h>

#include "../ResourceHolder.hpp"
#include "../Aircraft.hpp"
#include "../Animation.hpp"


class AnimationTests: public testing::Test {
    public:
        typedef std::unique_ptr<Animation> AnimationPtr;
        TextureHolder mTextures;
    
    protected:
        virtual void SetUp() {
            mTextures.load(Textures::Explosion, "./gfx/textures/Explosion.png");
        }

        virtual void TearDown() { }
};

TEST_F(AnimationTests, testAnimationCreated) {         
    AnimationPtr explosion(new Animation(mTextures.get(Textures::Explosion)));
    ASSERT_NE(nullptr, explosion); 
}

TEST_F(AnimationTests, testGetAndSetTexture){ 
    TextureHolder textures;
    textures.load(Textures::Explosion, "./gfx/textures/Explosion.png");
        
    AnimationPtr explosion(new Animation(mTextures.get(Textures::Explosion)));
    
    auto result = explosion->getTexture();
    ASSERT_NE(nullptr, result);
}

TEST_F(AnimationTests, testGetAndSetFrameSize){    
    TextureHolder textures;
    textures.load(Textures::Explosion, "./gfx/textures/Explosion.png");
        
    AnimationPtr explosion(new Animation(mTextures.get(Textures::Explosion)));
    explosion->setFrameSize(sf::Vector2i(256, 256));   
    
    auto result = explosion->getFrameSize();
    
    //ASSERT_EQ(nullptr, result); 
}

TEST_F(AnimationTests, testGetAndSetNumFrames){          
    AnimationPtr explosion(new Animation(mTextures.get(Textures::Explosion)));
    explosion->setFrameSize(sf::Vector2i(256, 256));
    
    auto result = explosion->getNumFrames();
    
    ASSERT_EQ(0, result);    
    
    explosion->setNumFrames(2);
    
    result = explosion->getNumFrames();
    
    ASSERT_EQ(2, result);  
}

TEST_F(AnimationTests, testGetAndSetDuration){         
    AnimationPtr explosion(new Animation(mTextures.get(Textures::Explosion)));
    explosion->setDuration(sf::seconds(1));
    
    auto result = explosion->getDuration();
    
    //EXPECT_EQ(nullptr, result);    
    
    explosion->setDuration(sf::seconds(2));
    
    result = explosion->getDuration();
    
    //EXPECT_EQ(nullptr, result);   
}

TEST_F(AnimationTests, testRepeating){}

TEST_F(AnimationTests, testRestart){}

TEST_F(AnimationTests, testIfIsFinished){
    sf::Clock clock;
    sf::Time deltaTime = clock.restart();
    
    auto explosion = new Animation();     
    explosion->setNumFrames(2);   
    explosion->setDuration(sf::seconds(1));
    
    ASSERT_NE(true, explosion->isFinished());
    
    //explosion->update(deltaTime);
    
    //ASSERT_NE(true, explosion->isFinished());
}

TEST_F(AnimationTests, testGetLocalBounds){        
    AnimationPtr explosion(new Animation(mTextures.get(Textures::Explosion)));
    explosion->setNumFrames(2);   
    
   // auto bounds = getLocalBounds();
}

TEST_F(AnimationTests, testGetGlobalBounds){}

TEST_F(AnimationTests, testUpdate){} 