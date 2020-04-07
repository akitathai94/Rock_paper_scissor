cmake_minimum_required(VERSION 3.14)
project(Assignment5)

set(CMAKE_CXX_STANDARD 11)

# Request the required wxWidget Packets
find_package(wxWidgets 3.0 COMPONENTS core base REQUIRED)
# Include the wxWidget use file to initialize settings
include(${wxWidgets_USE_FILE})

set(SRC_FILES
        GUI/MainApp.cpp
        GUI/DemoFrame.cpp
        GUI/Choice.cpp
        GUI/HumanChoicePanel.cpp
        GUI/RoundNumber.cpp
        GUI/ComputerChoicePanel.cpp
        GUI/WinnerPanel.cpp
        GUI/StatisticsPanel.cpp

        Game/Game.cpp
        Game/MLChooser.cpp
        Game/Player.cpp
        Game/Round.cpp
        )


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