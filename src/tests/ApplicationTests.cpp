#include <memory>

#include <gtest/gtest.h>

#include "Mocks.hpp"

TEST(ApplicationTests, testApplicationCreated) { 
    std::unique_ptr<Application> app(new Application());
    ASSERT_NE(nullptr, &app);    
}

TEST(ApplicationTests, testRunningApplication){
    //std::unique_ptr<Application> app(new Application());
}
