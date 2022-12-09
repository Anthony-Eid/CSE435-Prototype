//
// Created by Anthony Eid on 12/8/22.
//
#include "pch.h"

#include "MainFrame.h"
#include "PrototypeView.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"Prototype",
           wxDefaultPosition,  wxSize( 1000,800 ));

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxVERTICAL );

    // Create the view class object as a child of MainFrame
    auto prototypeView = new PrototypeView();
    prototypeView->Initialize(this);

    // Add it to the sizer
    sizer->Add(prototypeView, 1, wxEXPAND | wxALL );

    // Set the sizer for this frame
    SetSizer( sizer );

    // Layout (place) the child windows.
    Layout();

}
