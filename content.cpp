#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>
#include <vector>
#include "content.hpp"

using namespace ftxui;

// Hacker-style reusable styles
const auto hacker_text_style = color(Color::Green) | bold | dim;
const auto hacker_border_style = border | color(Color::Green);
const auto hacker_link_style = color(Color::LightGreen) | underlined;
const auto hacker_button_style = color(Color::Green) | bold;
const auto hacker_button_active_style = color(Color::LightGreen) | bold;

// ------------------
// Pages
// ------------------

Component MakeAboutPage() {
  return Renderer([]() -> Element {
    return vbox({
      vbox({
        text("Keshav Anand") | color(Color::LightGreen) | bold | center,
        text("Student Researcher | ML + Robotics Developer | CS + Math Enthusiast") | hacker_text_style | center,
      }) | hacker_border_style,

    }) | flex;
  });
}

Component MakeProjectsPage() {
  const std::vector<std::pair<std::string, std::string>> projects = {
    {"🧠 GaitGuardian: IMU Processing for Parkinson’s Disease (2024–Present)",
     "• Hybrid biLSTM + CNN model for Freezing of Gait prediction\n"
     "• Signal segmentation reduces subject dependence\n"
     "• State-of-the-art accuracy, end-to-end functionality"},
    {"🔥 TEG-Powered Self-Stirring Device (2023–2024)",
     "• Built thermal energy harvesting prototype for self-stirring cookware\n"
     "• Developed mechanical + electrical integration\n"
     "• Won 1st at Dallas Fair, ISEF Finalist"},
    {"🤖 FTC Technical Turbulence (23344) — Lead Software Developer (2023–Present)",
     "• Custom inverse kinematics, pathing, and Computer Vision autonomy\n"
     "• Top-30 globally for software performance, FTC State Finalist"},
  };

  Component container = Container::Vertical({});
  for (auto& p : projects) {
    Component card = Renderer([p]() -> Element {
      return vbox({
        text(p.first) | color(Color::LightGreen) | bold,
        paragraph(p.second) | hacker_text_style | dim,
      }) | hacker_border_style;
    });
    container->Add(card);
  }

  return Renderer(container, [container]() -> Element {
    return vbox(container->Render()) | vscroll_indicator | yframe | flex;
  });
}

Component MakeEducationPage() {
  return Renderer([]() -> Element {
    return vbox({
      vbox({
        text("🏫 Plano East Senior High School (2023–2027)") | color(Color::LightGreen) | bold,
        text("STEM & Multidisciplinary Endorsement") | hacker_text_style,
        text("GPA: 4.73 | Rank: 1/1273 | SAT: 1550") | hacker_text_style,
      }) | hacker_border_style,

      separator(),

      vbox({
        text("📚 Current Coursework:") | color(Color::LightGreen) | bold,
        text("• AP Chemistry") | hacker_text_style,
        text("• AP Physics I") | hacker_text_style,
        text("• Digital Electronics") | hacker_text_style,
        text("• American Studies (AP US History + AP English Language)") | hacker_text_style,
        text("• Calculus III (via Collin College)") | hacker_text_style,
      }) | hacker_border_style,
    }) | flex;
  });
}

Component MakeWorkPage() {
  const std::vector<std::pair<std::string, std::string>> activities = {
    {"🧪 Vice President, LASER (Science Fair Organization)",
     "Guiding and mentoring 120+ students in research and experimentation"},
    {"💻 Technology Officer, National Honor Society",
     "Developed and maintained React-based management portal for 1000+ members"},
    {"🏏 Founder & Captain, Plano East Cricket Club",
     "Established first school tapeball cricket team; coached and led events"},
    {"🎶 Indian Film Music Performer",
     "Bass guitar & keyboard player in charity concerts; arrangement and production"},
  };

  Component container = Container::Vertical({});
  for (auto& a : activities) {
    Component card = Renderer([a]() -> Element {
      return vbox({
        text(a.first) | color(Color::LightGreen) | bold,
        text(a.second) | hacker_text_style | dim,
      }) | hacker_border_style;
    });
    container->Add(card);
  }

  return Renderer(container, [container]() -> Element {
    return vbox(container->Render()) | vscroll_indicator | yframe | flex;
  });
}

Component MakeAwardsPage() {
  const std::vector<std::pair<std::string, std::string>> awards = {
    {"🥇 Thermoelectric Generator Research Project (2024)",
     "Dallas Fair: 1st in Engineering | USAF Recognition | USMA Best SI Units\nISEF Finalist"},
    {"🥈 GaitGuardian ML Research (2025)",
     "Dallas Fair: 1st in Systems Software, Grand Prize Runner-Up\nISEF Finalist | 3rd in Robotics & Intelligent Systems"},
    {"🏅 National Speech & Debate (2025)",
     "Impromptu Quarterfinalist at District and State Level"},
  };

  Component container = Container::Vertical({});
  for (auto& a : awards) {
    Component card = Renderer([a]() -> Element {
      return vbox({
        text(a.first) | color(Color::LightGreen) | bold,
        paragraph(a.second) | hacker_text_style | dim,
      }) | hacker_border_style;
    });
    container->Add(card);
  }

  return Renderer(container, [container]() -> Element {
    return vbox(container->Render()) | vscroll_indicator | yframe | flex;
  });
}

Component MakeSkillsPage() {
  const std::string skills =
      "💻 Programming Languages:\n"
      "  Java, Python, Bash, C++ (Arduino), Kotlin (FTC), limited HTML/CSS/JS\n\n"
      "🧠 Applications:\n"
      "  Machine Learning, Signal Processing, TensorFlow, Computer Vision\n\n"
      "⚙️ Miscellaneous:\n"
      "  Public Speaking, CAD, PCB Design, Electrical Systems, Competition Math";

  return Renderer([skills]() -> Element {
    return paragraph(skills) | hacker_text_style | flex;
  });
}

Component MakeContactPage() {
  const std::string contact_info =
      "📫  Email: keshavanandofficial@gmail.com\n"
      "🔗  LinkedIn: linkedin.com/in/keshavganand\n"
      "💻  GitHub: github.com/keshavanandcode\n"
      "🌐  Resume: resume.keshavanand.net\n"
      "📍  DFW Metroplex, Texas\n\n"
      "Updated: November 2025";

  return Renderer([contact_info]() -> Element {
    return paragraph(contact_info) | hacker_text_style | flex;
  });
}

// Constructor implementation
PortfolioApp::PortfolioApp() {
  about_page_ = MakeAboutPage();
  projects_page_ = MakeProjectsPage();
  education_page_ = MakeEducationPage();
  work_page_ = MakeWorkPage();
  awards_page_ = MakeAwardsPage();
  skills_page_ = MakeSkillsPage();
  contact_page_ = MakeContactPage();

  pages_ = {about_page_, projects_page_, education_page_,
            work_page_, awards_page_, skills_page_, contact_page_};

  std::vector<std::string> labels = {"About", "Projects", "Education", "Activities", "Awards", "Skills", "Contact"};

  std::vector<Component> buttons;
  for (int i = 0; i < (int)labels.size(); ++i) {
    Component button = Button(labels[i], [&, i] { SwitchPage(i); })
                         | (i == current_page_ ? hacker_button_active_style : hacker_button_style);
    buttons.push_back(button);
  }

  navigation_ = Container::Vertical(buttons);
  Component separator_component = Renderer([] { return separator(); });

  Add(Container::Horizontal(Components{navigation_, separator_component, pages_[current_page_]}));
}

void PortfolioApp::SwitchPage(int index) {
  current_page_ = index;
  DetachAllChildren();
  Component separator_component = Renderer([] { return separator(); });
  Add(Container::Horizontal(Components{navigation_, separator_component, pages_[current_page_]}));
}

Element PortfolioApp::Render() {
  return hbox({
    navigation_->Render() | hacker_border_style,
    separator(),
    pages_[current_page_]->Render() | hacker_border_style | flex
  });
}

bool PortfolioApp::OnEvent(Event event) {
  if (event == Event::ArrowRight) {
    SwitchPage((current_page_ + 1) % pages_.size());
    return true;
  }
  if (event == Event::ArrowLeft) {
    SwitchPage((current_page_ - 1 + pages_.size()) % pages_.size());
    return true;
  }
  return ComponentBase::OnEvent(event);
}
