#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>
#include <vector>
#include "content.hpp"

using namespace ftxui;

// New reusable styles (orange/red theme)
const auto theme_text_style        = color(Color::OrangeRed1) | bold | dim;mac o
const auto theme_border_style      = border | color(Color::Red);
const auto theme_link_style        = color(Color::RedLight) | underlined;
const auto theme_button_style      = color(Color::Red) | bold;
const auto theme_button_active_style = color(Color::Yellow1) | bold;

// ------------------x
// Pages
// ------------------

Component MakeAboutPage() {
  return Renderer([]() -> Element {
    return vbox({
      // Header section
      vbox({
        text("Keshav Anand") | color(Color::Blue) | bold | center,
        text("Subtitle") | theme_text_style | center,
      }) | theme_border_style,

      separator(),

      // Tags section
      vbox({
        text("insert_content") | theme_text_style | center,
      }) | theme_border_style,

      separator(),

      // Focus areas
      vbox({
        text("Summ1") | color(Color::LightSkyBlue1) | bold,
    
      }) | theme_border_style,

      separator(),

      // Current status
      vbox({
        text("Summ2") | color(Color::LightSkyBlue1) | bold,
      }) | theme_border_style,

      separator(),

      // Location and contact
      vbox({
        text("Location") | theme_text_style | center,
        text("Email") | theme_text_style | center,
        text("Phone") | theme_link_style | center,
      }) | theme_border_style,

    }) | flex;
  });
}

Component MakeProjectsPage() {
  const std::vector<Project> projects = {
    {"Insert Gibbersish"},

  };

  Component container = Container::Vertical({});

  for (const Project& project : projects) {
    Component card = Renderer([project]() -> Element {
      Element title = text(project.title) | theme_text_style | bold;
      Element desc = text(project.link) | color(Color::GreenYellow);

      return vbox({
        title,
        desc
      }) | theme_border_style;
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
      // School section
      vbox({
        text("Education") | color(Color::LightGreen) | bold,

      }) | theme_border_style,

      separator(),

      // Coursework section
      vbox({
        text("TODO: ADD AP scores, nonsense, etc.") | color(Color::LightGreen) | bold,

      }) | theme_border_style,

      separator(),

      // Research section
      vbox({
        text("Research:") | color(Color::Blue) | bold,
        text("GaitGuardian, LASER, TEG, etc.") | theme_text_style,

      }) | theme_border_style,

    }) | flex;
  });
}

Component MakeWorkPage() {
  struct WorkEntry {
    std::string title;
    std::string description;
  };

  const std::vector<WorkEntry> jobs = {
    {"exp", 
     "desc"},

  };

  Component container = Container::Vertical({});

  for (const WorkEntry& job : jobs) {
    Component card = Renderer([job]() -> Element {
      return vbox({
        text(job.title) | color(Color::LightGreen) | bold,
        text(job.description) | theme_text_style | dim,
      }) | theme_border_style;
    });
    container->Add(card);
  }

  return Renderer(container, [container]() -> Element {
    return vbox(container->Render()) | vscroll_indicator | yframe | flex;
  });
}

Component MakeAwardsPage() {
  const std::vector<std::string> awards = {
    "Award 1", "Description 1",
  };

  Component container = Container::Vertical({});

  // Process awards in pairs (title + description)
  for (size_t i = 0; i < awards.size(); i += 2) {
    const std::string& title = awards[i];
    const std::string& desc = (i + 1 < awards.size()) ? awards[i + 1] : "";

    Component card = Renderer([title, desc]() -> Element {
      return vbox({
        text(title) | color(Color::LightGreen) | bold,
        text(desc) | theme_text_style | dim,
      }) | theme_border_style;
    });

    container->Add(card);
  }

  return Renderer(container, [container]() -> Element {
    return vbox(container->Render()) | vscroll_indicator | yframe | flex;
  });
}

Component MakeSkillsPage() {
  const std::string skills_content =
      "Skills:\n";

  return Renderer([skills_content]() -> Element {
    return paragraph(skills_content) | theme_text_style | flex;
  });
}

Component MakeContactPage() {
  const std::string contact_info =
      "Contact Me:\n";

  return Renderer([contact_info]() -> Element {
    return paragraph(contact_info) | theme_text_style | flex;
  });
}

// Constructor implementation
PortfolioApp::PortfolioApp() {
    // Build individual pages
    about_page_ = MakeAboutPage();
    projects_page_ = MakeProjectsPage();
    education_page_ = MakeEducationPage();
    work_page_ = MakeWorkPage();
    awards_page_ = MakeAwardsPage();
    skills_page_ = MakeSkillsPage();
    contact_page_ = MakeContactPage();

    // Add pages to vector
    pages_.push_back(about_page_);
    pages_.push_back(projects_page_);
    pages_.push_back(education_page_);
    pages_.push_back(work_page_);
    pages_.push_back(awards_page_);
    pages_.push_back(skills_page_);
    pages_.push_back(contact_page_);

    // Create navigation sidebar with orange/red styling
    std::vector<std::string> labels = {"About", "Projects", "Education", "Work", "Awards", "Skills", "Contact"};

    std::vector<Component> buttons;
    for (int i = 0; i < (int)labels.size(); ++i) {
      Component button = Button(labels[i], [&, i] { SwitchPage(i); }) 
                         | (i == current_page_ ? theme_button_active_style : theme_button_style);

      buttons.push_back(button);
    }

    navigation_ = Container::Vertical(buttons);

    // Initial layout
    Component separator_component = Renderer([] { return separator(); });

    Add(Container::Horizontal(Components{
        navigation_,
        separator_component,
        pages_[current_page_]
    }));
}

// SwitchPage method implementation
void PortfolioApp::SwitchPage(int index) {
    current_page_ = index;

    DetachAllChildren();
    
    Component separator_component = Renderer([] { return separator(); });

    Add(Container::Horizontal(Components{
        navigation_,
        separator_component,
        pages_[current_page_]
    }));
}

// Render method implementation
Element PortfolioApp::Render() {
    return hbox({
        navigation_->Render() | theme_border_style,
        separator(),
        pages_[current_page_]->Render() | theme_border_style | flex
    });
}

// OnEvent method implementation
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