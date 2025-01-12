cmake_minimum_required(VERSION 3.5)

project(kiwi_ui VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        signin.cpp
        signin.h
        signin.ui
        ../customer/customer.cpp
        ../dev/dev.cpp
        ../devices/devices.cpp
        ../devices/comp_parts/comp_parts_parent.cpp
        ../devices/comp_parts/storage/storage.cpp
        ../devices/comp_parts/storage/hdd.cpp
        ../devices/comp_parts/storage/ssd.cpp
        ../devices/comp_parts/cooling_u.cpp
        ../devices/comp_parts/cpu.cpp
        ../devices/comp_parts/gpu.cpp
        ../devices/comp_parts/memory.cpp
        ../devices/comp_parts/motherboard.cpp
        ../devices/comp_parts/pc_case.cpp
        ../devices/comp_parts/psu.cpp
        ../devices/console/console.cpp
        ../devices/console/handheld.cpp
        ../devices/console/stationed.cpp
        ../devices/desktop/desktop.cpp
        ../devices/laptop/laptop.cpp
        ../devices/peripherals/peripherals.cpp
        ../devices/peripherals/audio/earbuds.cpp
        ../devices/peripherals/audio/earphones.cpp
        ../devices/peripherals/audio/headphones.cpp
        ../devices/peripherals/audio/headset.cpp
        ../devices/peripherals/audio/microphone.cpp
        ../devices/peripherals/audio/speakers.cpp
        ../devices/peripherals/display.cpp
        ../devices/peripherals/keyboard.cpp
        ../devices/peripherals/mouse.cpp
        ../devices/peripherals/portable_hdd.cpp
        ../devices/peripherals/printer.cpp
        ../devices/peripherals/sd_card.cpp
        ../devices/peripherals/touchpad.cpp
        ../devices/peripherals/usb_drive.cpp
        ../devices/peripherals/webcam.cpp
        ../devices/peripherals/wire.cpp
        ../devices/smartphones/smartphones.cpp
        ../devices/smartwatch/smartwatch.cpp
        ../devices/tablet/tablet.cpp
        ../devices/vr/vr.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(kiwi_ui
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        develop_page.h develop_page.cpp develop_page.ui
        customer_page.h customer_page.cpp customer_page.ui


        dev_ima_button.qrc

        all_list.h all_list.cpp all_list.ui

        edit_device_vr.h edit_device_vr.cpp edit_device_vr.ui
        edit_main.h edit_main.cpp edit_main.ui
        edit_device_tablet.h edit_device_tablet.cpp edit_device_tablet.ui
        add_device_vr.h add_device_vr.cpp add_device_vr.ui
        remove_vr.h remove_vr.cpp remove_vr.ui
        add_device_phone.h add_device_phone.cpp add_device_phone.ui
        edit_device_phones.h edit_device_phones.cpp edit_device_phones.ui

        add_device_tablet.h add_device_tablet.cpp add_device_tablet.ui
        add_device_desktop.h add_device_desktop.cpp add_device_desktop.ui
        edit_device_desktop.h edit_device_desktop.cpp edit_device_desktop.ui
        edit_device_laptop.h edit_device_laptop.cpp edit_device_laptop.ui
        add_device_laptop.h add_device_laptop.cpp add_device_laptop.ui
        add_device_watch.h add_device_watch.cpp add_device_watch.ui
        edit_device_watch.h edit_device_watch.cpp edit_device_watch.ui
        add_device_console.h add_device_console.cpp add_device_console.ui
        edit_device_console.h edit_device_console.cpp edit_device_console.ui
        add_device_handheld.h add_device_handheld.cpp add_device_handheld.ui
        add_device_stationed.h add_device_stationed.cpp add_device_stationed.ui
        edit_device_handheld.h edit_device_handheld.cpp edit_device_handheld.ui
        edit_device_stationed.h edit_device_stationed.cpp edit_device_stationed.ui
        show_info.h show_info.cpp show_info.ui
        add_to_cart.h add_to_cart.cpp add_to_cart.ui
        show_info_vr.h show_info_vr.cpp show_info_vr.ui
        show_info_phone.h show_info_phone.cpp show_info_phone.ui
        show_info_tablet.h show_info_tablet.cpp show_info_tablet.ui
        show_info_destop.h show_info_destop.cpp show_info_destop.ui
        show_info_laptop.h show_info_laptop.cpp show_info_laptop.ui
        show_info_watch.h show_info_watch.cpp show_info_watch.ui
        show_info_handheld.h show_info_handheld.cpp show_info_handheld.ui
        show_info_stationed.h show_info_stationed.cpp show_info_stationed.ui
        cart.h cart.cpp cart.ui
        delete_thing_incart.h delete_thing_incart.cpp delete_thing_incart.ui








    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET kiwi_ui APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(kiwi_ui SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(kiwi_ui
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(kiwi_ui PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.kiwi_ui)
endif()
set_target_properties(kiwi_ui PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS kiwi_ui
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(kiwi_ui)
endif()
