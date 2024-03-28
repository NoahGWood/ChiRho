#include <ChiRho.h>
#include <Core/Entry.h>
#include <imgui.h>

class ChiRhoTest : public ChiRho::Application
{
    public:
        ChiRhoTest()
        {
            // do nothign
            //ImGui::Button("Test");
        }
        ~ChiRhoTest()
        {
            // do nothign
        }
};

ChiRho::Application *ChiRho::CreateApplication()
{
    return new ChiRhoTest();
}