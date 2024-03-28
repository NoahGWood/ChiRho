#pragma once

namespace ChiRho {
    class ImGuiLayer
    {
        public:
            ImGuiLayer();
            ~ImGuiLayer();

            virtual void OnAttach();
            virtual void OnDetach();
            virtual void OnImGuiRender();
            virtual void OnEvent(Event& e);
            inline void BlockEvents(bool block) {m_blockEvents=block;}
            void Begin();
            void End();

        private:
            bool m_blockEvents = true;
            float m_Time = 0.0f;
    };
} // namespace ChiRho