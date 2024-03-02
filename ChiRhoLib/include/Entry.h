#pragma once
#include "Base.h"
#include "Application.h"

extern ChiRho::Application* ChiRho::CreateApplication();

int main(int argc, char** argv)
{
    ChiRho::Logger::Init();
    auto app = ChiRho::CreateApplication();
    app->Run();
    delete app;
    return 0;
}