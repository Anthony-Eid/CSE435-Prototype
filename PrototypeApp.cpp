/**
 * @file PrototypeApp.cpp
 * @author Anthony Eid
 */
#include "pch.h"

#include <MainFrame.h>

#include "PrototypeApp.h"


/**
 * Initialize the application.
 * @return
 */
bool PrototypeApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    // Add image type handlers
    wxInitAllImageHandlers();

    // Init and show the main frame
    auto frame = new MainFrame();
    frame->Initialize();
    frame->Show(true);

    return true;
}