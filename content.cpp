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
      // Header section
      vbox({
        text("Keshav Anand") | color(Color::LightGreen) | bold | center,
        text("ML Researcher, FTC Programmer, & CS/Maths Enthusiast") | hacker_text_style | center,
      }) | hacker_border_style,

      separator(),


      // Current status
      vbox({
        text("Current Status:") | color(Color::LightGreen) | bold,
        text("Junior at Plano East (1/1264)") | hacker_text_style,
        text("Lead SW for FTC 23344 Technical Turbulence") | hacker_text_style,
        text("Vice President, Science Fair") | hacker_text_style,
        text("President, Cricket Club") | hacker_text_style,
      }) | hacker_border_style,

      separator(),

      // Location and contact
      vbox({
        text("DFW Metroplex, Texas") | hacker_text_style | center,
        text("keshavanandofficial.gmail.com") | hacker_link_style | center,
      }) | hacker_border_style,

    }) | flex;
  });
}

Component MakeProjectsPage() {
  const std::vector<Project> projects = {
    {"🗃️ Matrix FS — L2 distributed storage over IPFS", "Rust + Tauri + Svelte, AES-256-CBC/ChaCha20-Poly1305 encryption"},
    {"🎓 Bon Voyage — AI MOOC content generator", "Java + Stanford CoreNLP, MLH Hackathon winner"},
    {"🏥 EHR System — Secure health records platform", "Java client-server, TCP/IP sockets, Swing GUI, SMB integration"},
    {"🧮 Rule-based Tensor Mutations for LLMs", "Novel LLaMA 3B enhancement, published on TechRxiv"},
    {"🏠 Home Infrastructure — 50-user self-hosted platform", "40+ Docker containers, WireGuard mesh, 150TB ZFS NAS"},
    {"🤖 SLAM Guide for Autonomous Robotics", "Probabilistic mapping algorithms, F1Tenth platform experience"},
    {"⚔️ CyberPatriot Automation Suite", "Rust/PowerShell scripts, 30+ points per round, licensed to other teams"}
  };

  Component container = Container::Vertical({});

  for (const Project& project : projects) {
    Component card = Renderer([project]() -> Element {
      Element title = text(project.title) | hacker_text_style | bold;
      Element desc = text(project.link) | color(Color::GreenYellow);

      return vbox({
        title,
        desc
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
      // School section
      vbox({
        text("🏫 Plano East Senior High School (2022–2026)") | color(Color::LightGreen) | bold,
        text("STEM & Multi-disciplinary Endorsement") | hacker_text_style,
        text("Computer Science & Mathematics concentrations") | hacker_text_style | dim,
      }) | hacker_border_style,

      separator(),

      // Coursework section
      vbox({
        text("📚 Relevant Coursework:") | color(Color::LightGreen) | bold,
        text("• Data Structures & Algorithms") | hacker_text_style,
        text("• Object-Oriented Programming") | hacker_text_style,
        text("• Calculus & Differential Equations") | hacker_text_style,
        text("• Probability & Statistics") | hacker_text_style,
        text("• Newtonian Physics") | hacker_text_style,
      }) | hacker_border_style,

      separator(),

      // Research section
      vbox({
        text("🔬 Research Experience:") | color(Color::LightGreen) | bold,
        text("Research Assistant to Dr. Madan M. T. Ayyalasomayajula (2022–Present)") | hacker_text_style,
        text("• Literature review and concept summarization") | hacker_text_style | dim,
        text("• Technical framework evaluation and benchmarking") | hacker_text_style | dim,
        text("• Research direction discussions and workflow analysis") | hacker_text_style | dim,
      }) | hacker_border_style,

    }) | flex;
  });
}

Component MakeWorkPage() {
  struct WorkEntry {
    std::string title;
    std::string description;
  };

  const std::vector<WorkEntry> jobs = {
    {"👑 President, Cybersecurity Club at PESH (2023–2026)", 
     "Ethical hacking workshops, CTF prep, digital forensics mentoring"},
    {"💻 Officer, Computer Science Club at PESH (2023–2026)", 
     "Data structures instruction, Java sessions, Git workflows"},
    {"🔍 Trace Labs OSINT Search Party (2023–2024)", 
     "Missing person investigations, OSINT pivoting, geolocation analysis"},
    {"🇺🇦 IT Army of Ukraine (Dec 2023–Feb 2024)", 
     "Offensive squad leader, DDoS campaigns, persistent takedowns"},
    {"🎯 Active Red Team Practitioner", 
     "Hack The Box (Rank 564), TryHackMe KoTH Top 5, 15+ HTB machines"}
  };

  Component container = Container::Vertical({});

  for (const WorkEntry& job : jobs) {
    Component card = Renderer([job]() -> Element {
      return vbox({
        text(job.title) | color(Color::LightGreen) | bold,
        text(job.description) | hacker_text_style | dim,
      }) | hacker_border_style;
    });
    container->Add(card);
  }

  return Renderer(container, [container]() -> Element {
    return vbox(container->Render()) | vscroll_indicator | yframe | flex;
  });
}

Component MakeAwardsPage() {
  const std::vector<std::string> awards = {
    "🥈 Lockheed Martin Cyber Quest — 2nd Place (2025)",
    "DFW metroplex, reverse engineering & low-level security",
    "🥇 CyberPatriot — State Level Gold Tier (2025)",
    "Offensive security analysis in blue-team environment",
    "🏆 Battle of the Brains — 5th Place Spring 2024, 10th Place Spring 2025",
    "Regional algorithms competitions at UTD",
    "🔓 NSA Codebreaker Challenge (Nov 2024)", 
    "5 advanced tasks: protocol exploitation, reverse engineering",
    "👑 TryHackMe King of the Hill — Top 5 (2024)",
    "2 consecutive days, live red team capabilities",
    "💀 Hack The Box — Peak Rank 564",
    "15+ Medium machines, 90% progress toward 'Hacker' rank"
  };

  Component container = Container::Vertical({});

  // Process awards in pairs (title + description)
  for (size_t i = 0; i < awards.size(); i += 2) {
    const std::string& title = awards[i];
    const std::string& desc = (i + 1 < awards.size()) ? awards[i + 1] : "";

    Component card = Renderer([title, desc]() -> Element {
      return vbox({
        text(title) | color(Color::LightGreen) | bold,
        text(desc) | hacker_text_style | dim,
      }) | hacker_border_style;
    });

    container->Add(card);
  }

  return Renderer(container, [container]() -> Element {
    return vbox(container->Render()) | vscroll_indicator | yframe | flex;
  });
}

Component MakeSkillsPage() {
  const std::string skills_content =
      "🦀 Languages: Rust (5/5), Async Rust, Python, Java, C/C++, TypeScript, Solidity\n\n"
      "🌐 Networking: WireGuard, Tailscale, Tor, I2P, DNS, DHCP, TLS, gRPC, QUIC\n\n"
      "⚔️ Red Team Arsenal:\n"
      "  • Recon: amass, subfinder, shodan, nuclei, ffuf\n"
      "  • Web: sqlmap, Burp Suite Pro, OWASP ZAP, nikto\n"
      "  • Post-Exploit: Empire, Covenant, Metasploit, Cobalt Strike\n"
      "  • AD: BloodHound, Rubeus, mimikatz, impacket\n"
      "  • PrivEsc: linPEAS, winPEAS, JuicyPotato\n\n"
      "🔐 Crypto: ChaCha20Poly1305, Ed25519, Kyber1024, Dilithium5, TLS 1.3\n\n"
      "🐧 Systems: Arch Linux, kernel patching, BPF/eBPF, QEMU/KVM, systemd\n\n"
      "☁️ Cloud: AWS (EC2, S3, Lambda), Terraform, Docker, Kubernetes";

  return Renderer([skills_content]() -> Element {
    return paragraph(skills_content) | hacker_text_style | flex;
  });
}

Component MakeContactPage() {
  const std::string contact_info =
      "📫 Email: krishna@ayyalasomayajula.net\n"
      "🌐 Website: https://krishna.ayyalasomayajula.net\n"
      "📞 Phone: (214) 293-5743\n"
      "📍 Based in DFW Metroplex, Texas\n"
      "💳 US Green Card Holder\n"
      "📄 Resume: https://git.cyber.ayyalasomayajula.net/marsultor/resume-cv/raw/branch/master/resume.pdf\n\n"
      "🔗 Connect with me for:\n"
      "  • Cybersecurity research collaboration\n"
      "  • Red team consulting\n"
      "  • Distributed systems projects\n"
      "  • AI/ML security research";

  return Renderer([contact_info]() -> Element {
    return paragraph(contact_info) | hacker_text_style | flex;
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

    // Create navigation sidebar with green styling
    std::vector<std::string> labels = {"About", "Projects", "Education", "Work", "Awards", "Skills", "Contact"};

    std::vector<Component> buttons;
    for (int i = 0; i < (int)labels.size(); ++i) {
      Component button = Button(labels[i], [&, i] { SwitchPage(i); }) 
                         | (i == current_page_ ? hacker_button_active_style : hacker_button_style);

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
        navigation_->Render() | hacker_border_style,
        separator(),
        pages_[current_page_]->Render() | hacker_border_style | flex
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