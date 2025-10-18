#pragma once
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>
#include <vector>

// ------------------
// Structs
// ------------------
struct Project {
    std::string title;
    std::string link;  // Leave empty if no link
};

// ------------------
// PageFactory Functions
//

// ------------------
/**
 * Creates the About page component
 * @return Component containing personal introduction and focus areas
 */
ftxui::Component MakeAboutPage();

/**
 * Creates the Projects page component
 * @return Component displaying list of projects with links
 */
ftxui::Component MakeProjectsPage();

/**
 * Creates the Education page component
 * @return Component showing educational background and achievements
 */
ftxui::Component MakeEducationPage();

/**
 * Creates the Work page component
 * @return Component displaying work experience and competitions
 */
ftxui::Component MakeWorkPage();

/**
 * Creates the Awards page component
 * @return Component displaying awards, competitions, and achievements
 */
ftxui::Component MakeAwardsPage();

/**
 * Creates the Skills page component
 * @return Component showing technical skills and expertise
 */
ftxui::Component MakeSkillsPage();

/**
 * Creates the Contact page component
 * @return Component with contact information
 */
ftxui::Component MakeContactPage();

// ------------------
// Main Application Class
// ------------------
/**
 * Main portfolio application class that manages navigation and page switching
 * Inherits from ftxui::ComponentBase to provide custom rendering and event handling
 */
class PortfolioApp : public ftxui::ComponentBase {
public:
    /**
     * Constructor - initializes all pages and navigation
     */
    PortfolioApp();

    /**
     * Switch to a specific page by index
     * @param index The page index to switch to (0-6)
     */
    void SwitchPage(int index);

    /**
     * Render the current application state
     * @return Element representing the full UI layout
     */
    ftxui::Element Render();

    /**
     * Handle keyboard events for navigation
     * @param event The keyboard event to process
     * @return true if event was handled, false otherwise
     */
    bool OnEvent(ftxui::Event event) override;

private:
    int current_page_ = 0;  // Currently active page index

    // UI Components
    ftxui::Component navigation_;     // Navigation sidebar
    ftxui::Component about_page_;     // About page component
    ftxui::Component projects_page_;  // Projects page component
    ftxui::Component education_page_; // Education page component
    ftxui::Component work_page_;      // Work page component
    ftxui::Component awards_page_;    // Awards page component
    ftxui::Component skills_page_;    // Skills page component
    ftxui::Component contact_page_;   // Contact page component

    std::vector<ftxui::Component> pages_;  // Vector of all page components
};
