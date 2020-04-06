cmake_minimum_required(VERSION 3.14)
project(Assignment5_static_GUI)

set(CMAKE_CXX_STANDARD 11)

# Request the required wxWidget Packets
find_package(wxWidgets 3.0 COMPONENTS core base REQUIRED)
# Include the wxWidget use file to initialize settings
include(${wxWidgets_USE_FILE})

set(SRC_FILES
        MainApp.cpp
        DemoFrame.cpp
        Choice.cpp Choice.h HumanChoicePanel.cpp HumanChoicePanel.h RoundNumber.cpp RoundNumber.h ComputerChoicePanel.cpp ComputerChoicePanel.h WinnerPanel.cpp WinnerPanel.h StatisticsPanel.cpp StatisticsPanel.h)


add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
            RESOURCE "../../src/osx/carbon/wxmac.icns"
            MACOSX_BUNDLE_ICON_FILE wxmac.icns
            MACOSX_BUNDLE_COPYRIGHT "Copyright wxWidgets"
            MACOSX_BUNDLE_GUI_IDENTIFIER "org.wxwidgets.wxTest"
            )
endif()