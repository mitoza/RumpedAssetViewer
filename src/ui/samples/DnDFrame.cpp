//
// Created by Dmitry Velychko on 25.06.2024.
//

#include "../../../include/ui/samples/DnDFrame.h"

wxBEGIN_EVENT_TABLE(DnDFrame, wxFrame)
                EVT_MENU(Menu_Quit, DnDFrame::OnQuit)
                EVT_MENU(Menu_About, DnDFrame::OnAbout)
                EVT_MENU(Menu_Drag, DnDFrame::OnDrag)
                EVT_MENU(Menu_DragMoveDef, DnDFrame::OnDragMoveByDefault)
                EVT_MENU(Menu_DragMoveAllow, DnDFrame::OnDragMoveAllow)
                EVT_MENU(Menu_NewFrame, DnDFrame::OnNewFrame)
                EVT_MENU(Menu_Help, DnDFrame::OnHelp)
                EVT_MENU(Menu_Clear, DnDFrame::OnLogClear)
                EVT_MENU(Menu_Copy, DnDFrame::OnCopy)
                EVT_MENU(Menu_Paste, DnDFrame::OnPaste)
                EVT_MENU(Menu_CopyBitmap, DnDFrame::OnCopyBitmap)
                EVT_MENU(Menu_PasteBitmap, DnDFrame::OnPasteBitmap)
                EVT_MENU(Menu_PasteMFile, DnDFrame::OnPasteMetafile)
                EVT_MENU(Menu_CopyFiles, DnDFrame::OnCopyFiles)
                EVT_MENU(Menu_CopyURL, DnDFrame::OnCopyURL)
                EVT_MENU(Menu_UsePrimary, DnDFrame::OnUsePrimary)

                EVT_UPDATE_UI(Menu_DragMoveDef, DnDFrame::OnUpdateUIMoveByDefault)

                EVT_UPDATE_UI(Menu_Paste, DnDFrame::OnUpdateUIPasteText)
                EVT_UPDATE_UI(Menu_PasteBitmap, DnDFrame::OnUpdateUIPasteBitmap)

                EVT_LEFT_DOWN(DnDFrame::OnLeftDown)
                EVT_RIGHT_DOWN(DnDFrame::OnRightDown)
                EVT_PAINT(DnDFrame::OnPaint)
                EVT_SIZE(DnDFrame::OnSize)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(DnDCanvasBitmap, wxScrolledWindow)
                EVT_PAINT(DnDCanvasBitmap::OnPaint)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(DnDCanvasMetafile, wxScrolledWindow)
                EVT_PAINT(DnDCanvasMetafile::OnPaint)
wxEND_EVENT_TABLE()


bool DnDText::OnDropText(wxCoord, wxCoord, const wxString &text) {
    m_pOwner->Append(text);

    return true;
}

bool DnDFile::OnDropFiles(wxCoord, wxCoord, const wxArrayString &filenames) {
    size_t nFiles = filenames.GetCount();
    wxString str;
    str.Printf("%d files dropped", (int) nFiles);

    if (m_pOwner != nullptr) {
        m_pOwner->Append(str);
        for (size_t n = 0; n < nFiles; n++)
            m_pOwner->Append(filenames[n]);
    }

    return true;
}

DnDFrame::DnDFrame(wxWindow *parent)
        : wxFrame(parent, wxID_ANY, "Drag-and-Drop/Clipboard wxWidgets Sample",
                  wxPoint(10, 100)),
          m_strText("wxWidgets drag & drop works :-)") {
    // frame icon and status bar
    //SetIcon(wxICON(sample));

#if wxUSE_STATUSBAR
    CreateStatusBar();
#endif // wxUSE_STATUSBAR

    // construct menu
    wxMenu *file_menu = new wxMenu;
    file_menu->Append(Menu_Drag, "&Test drag...");
    file_menu->AppendCheckItem(Menu_DragMoveDef, "&Move by default");
    file_menu->AppendCheckItem(Menu_DragMoveAllow, "&Allow moving");
    file_menu->AppendSeparator();
    file_menu->Append(Menu_NewFrame, "&New frame\tCtrl-N");
    file_menu->AppendSeparator();
    file_menu->Append(Menu_Quit, "E&xit\tCtrl-Q");

#if wxUSE_LOG
    wxMenu *log_menu = new wxMenu;
    log_menu->Append(Menu_Clear, "Clear\tCtrl-L");
#endif // wxUSE_LOG

    wxMenu *help_menu = new wxMenu;
    help_menu->Append(Menu_Help, "&Help...");
    help_menu->AppendSeparator();
    help_menu->Append(Menu_About, "&About");

    wxMenu *clip_menu = new wxMenu;
    clip_menu->Append(Menu_Copy, "&Copy text\tCtrl-C");
    clip_menu->Append(Menu_Paste, "&Paste text\tCtrl-V");
    clip_menu->AppendSeparator();
    clip_menu->Append(Menu_CopyBitmap, "Copy &bitmap\tCtrl-Shift-C");
    clip_menu->Append(Menu_PasteBitmap, "Paste b&itmap\tCtrl-Shift-V");
#if wxUSE_METAFILE
    clip_menu->AppendSeparator();
    clip_menu->Append(Menu_PasteMFile, "Paste &metafile\tCtrl-M");
#endif // wxUSE_METAFILE
    clip_menu->AppendSeparator();
    clip_menu->Append(Menu_CopyFiles, "Copy &files\tCtrl-F");
    clip_menu->Append(Menu_CopyURL, "Copy &URL\tCtrl-U");
    clip_menu->AppendSeparator();
    clip_menu->AppendCheckItem(Menu_UsePrimary, "Use &primary selection\tCtrl-P");

    wxMenuBar *menu_bar = new wxMenuBar;
    menu_bar->Append(file_menu, "&File");
#if wxUSE_LOG
    menu_bar->Append(log_menu, "&Log");
#endif // wxUSE_LOG
    menu_bar->Append(clip_menu, "&Clipboard");
    menu_bar->Append(help_menu, "&Help");

    SetMenuBar(menu_bar);

    // create the child controls
    SetBackgroundColour(*wxWHITE); // labels read better on this background

    wxString strFile("Drop files here!"), strText("Drop text on me");

    m_ctrlFile = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 1, &strFile,
                               wxLB_HSCROLL | wxLB_ALWAYS_SB);
    m_ctrlText = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 1, &strText,
                               wxLB_HSCROLL | wxLB_ALWAYS_SB);
    m_ctrlDir = new wxGenericDirCtrl(this);

#if wxUSE_LOG
    m_ctrlLog = new wxTextCtrl(this, wxID_ANY, wxEmptyString,
                               wxDefaultPosition, wxDefaultSize,
                               wxTE_MULTILINE | wxTE_READONLY |
                               wxSUNKEN_BORDER);

    // redirect log messages to the text window
    m_pLog = new wxLogTextCtrl(m_ctrlLog);
    m_pLogPrev = wxLog::SetActiveTarget(m_pLog);
#endif // wxUSE_LOG

#if wxUSE_DRAG_AND_DROP
    // associate drop targets with the controls
    m_ctrlFile->SetDropTarget(new DnDFile(m_ctrlFile));
    m_ctrlText->SetDropTarget(new DnDText(m_ctrlText));

#if wxUSE_DRAG_AND_DROP
    m_ctrlDir->Bind(wxEVT_TREE_BEGIN_DRAG, &DnDFrame::OnBeginDrag, this);
#endif // wxUSE_DRAG_AND_DROP

#if wxUSE_LOG
    m_ctrlLog->SetDropTarget(new URLDropTarget);
#endif // wxUSE_LOG
#endif // wxUSE_DRAG_AND_DROP

    wxBoxSizer *sizer_top = new wxBoxSizer(wxHORIZONTAL);
    sizer_top->Add(m_ctrlFile, 1, wxEXPAND);
    sizer_top->Add(m_ctrlText, 1, wxEXPAND);

    wxBoxSizer *sizerDirCtrl = new wxBoxSizer(wxVERTICAL);
    sizerDirCtrl->Add(new wxStaticText(this, wxID_ANY, "Drag files from here"),
                      wxSizerFlags().Centre().Border());
    sizerDirCtrl->Add(m_ctrlDir, wxSizerFlags(1).Expand());
    sizer_top->Add(sizerDirCtrl, 1, wxEXPAND);

    // make all columns of reasonable minimal size
    for (unsigned n = 0; n < sizer_top->GetChildren().size(); n++)
        sizer_top->SetItemMinSize(n, 200, 300);

    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(sizer_top, 1, wxEXPAND);
#if wxUSE_LOG
    sizer->Add(m_ctrlLog, 1, wxEXPAND);
    sizer->SetItemMinSize(m_ctrlLog, 450, 200);
#endif // wxUSE_LOG
    sizer->AddSpacer(50);

    // copy data by default but allow moving it as well
    m_moveByDefault = false;
    m_moveAllow = true;
    menu_bar->Check(Menu_DragMoveAllow, true);

    // set the correct size and show the frame
    SetSizerAndFit(sizer);
    Show();
}

void DnDFrame::OnQuit(wxCommandEvent & WXUNUSED(event)) {
    Close(true);
}

void DnDFrame::OnSize(wxSizeEvent &event) {
    Refresh();

    event.Skip();
}

void DnDFrame::OnPaint(wxPaintEvent & WXUNUSED(event)) {
    int w = 0;
    int h = 0;
    GetClientSize(&w, &h);

    wxPaintDC dc(this);
    dc.SetFont(wxFontInfo(24).Family(wxFONTFAMILY_DECORATIVE).FaceName("charter"));
    dc.DrawText("Drag text from here!", 100, h - 50);
}

void DnDFrame::OnUpdateUIMoveByDefault(wxUpdateUIEvent &event) {
    // only can move by default if moving is allowed at all
    event.Enable(m_moveAllow);
}

void DnDFrame::OnUpdateUIPasteText(wxUpdateUIEvent &event) {
#ifdef __WXDEBUG__
    // too many trace messages if we don't do it - this function is called
    // very often
    wxLogNull nolog;
#endif

    event.Enable(wxTheClipboard->IsSupported(wxDF_TEXT));
}

void DnDFrame::OnUpdateUIPasteBitmap(wxUpdateUIEvent &event) {
#ifdef __WXDEBUG__
    // too many trace messages if we don't do it - this function is called
    // very often
    wxLogNull nolog;
#endif

    event.Enable(wxTheClipboard->IsSupported(wxDF_BITMAP));
}

void DnDFrame::OnNewFrame(wxCommandEvent & WXUNUSED(event)) {
#if wxUSE_DRAG_AND_DROP
    //(new DnDShapeFrame(this))->Show(true);

    wxLogStatus(this, "Double click the new frame to select a shape for it");
#endif // wxUSE_DRAG_AND_DROP
}

void DnDFrame::OnDrag(wxCommandEvent & WXUNUSED(event)) {
#if wxUSE_DRAG_AND_DROP
    wxString strText = wxGetTextFromUser
            (
                    "After you enter text in this dialog, press any mouse\n"
                    "button in the bottom (empty) part of the frame and \n"
                    "drag it anywhere - you will be in fact dragging the\n"
                    "text object containing this text",
                    "Please enter some text", m_strText, this
            );

    m_strText = strText;
#endif // wxUSE_DRAG_AND_DROP
}

void DnDFrame::OnDragMoveByDefault(wxCommandEvent &event) {
    m_moveByDefault = event.IsChecked();
}

void DnDFrame::OnDragMoveAllow(wxCommandEvent &event) {
    m_moveAllow = event.IsChecked();
}

void DnDFrame::OnAbout(wxCommandEvent & WXUNUSED(event)) {
    wxMessageBox("Drag-&-Drop Demo\n"
                 "Please see \"Help|Help...\" for details\n"
                 "Copyright (c) 1998 Vadim Zeitlin",
                 "About wxDnD",
                 wxICON_INFORMATION | wxOK,
                 this);
}

void DnDFrame::OnHelp(wxCommandEvent & /* event */) {
    wxMessageDialog dialog(this,
                           "This small program demonstrates drag & drop support in wxWidgets. The program window\n"
                           "consists of 3 parts: the bottom pane is for debug messages, so that you can see what's\n"
                           "going on inside. The top part is split into 2 listboxes, the left one accepts files\n"
                           "and the right one accepts text.\n"
                           "\n"
                           "To test wxDropTarget: open wordpad (write.exe), select some text in it and drag it to\n"
                           "the right listbox (you'll notice the usual visual feedback, i.e. the cursor will change).\n"
                           "Also, try dragging some files (you can select several at once) from Windows Explorer (or \n"
                           "File Manager) to the left pane. Hold down Ctrl/Shift keys when you drop text (doesn't \n"
                           "work with files) and see what changes.\n"
                           "\n"
                           "To test wxDropSource: just press any mouse button on the empty zone of the window and drag\n"
                           "it to wordpad or any other droptarget accepting text (and of course you can just drag it\n"
                           "to the right pane). Due to a lot of trace messages, the cursor might take some time to \n"
                           "change, don't release the mouse button until it does. You can change the string being\n"
                           "dragged in \"File|Test drag...\" dialog.\n"
                           "\n"
                           "\n"
                           "Please send all questions/bug reports/suggestions &c to \n"
                           "Vadim Zeitlin <zeitlin@dptmaths.ens-cachan.fr>",
                           "wxDnD Help");

    dialog.ShowModal();
}

#if wxUSE_LOG

void DnDFrame::OnLogClear(wxCommandEvent & /* event */ ) {
    m_ctrlLog->Clear();
    m_ctrlText->Clear();
    m_ctrlFile->Clear();
}

#endif // wxUSE_LOG

#if wxUSE_DRAG_AND_DROP

void DnDFrame::LogDragResult(wxDragResult result) {
#if wxUSE_STATUSBAR
    wxString msg;
    switch (result) {
        case wxDragError:
            msg = "Error!";
            break;
        case wxDragNone:
            msg = "Nothing";
            break;
        case wxDragCopy:
            msg = "Copied";
            break;
        case wxDragMove:
            msg = "Moved";
            break;
        case wxDragCancel:
            msg = "Cancelled";
            break;
        default:
            msg = "Huh?";
            break;
    }

    SetStatusText(wxString("Drag result: ") + msg);
#else
    wxUnusedVar(result);
#endif // wxUSE_STATUSBAR
}

#endif // wxUSE_DRAG_AND_DROP

void DnDFrame::OnLeftDown(wxMouseEvent &WXUNUSED(event)) {
#if wxUSE_DRAG_AND_DROP
    if (!m_strText.empty()) {
        // start drag operation
        wxTextDataObject textData(m_strText);
        wxDropSource source(textData, this,
                            wxDROP_ICON(dnd_copy),
                            wxDROP_ICON(dnd_move),
                            wxDROP_ICON(dnd_none));

        int flags = 0;
        if (m_moveByDefault)
            flags |= wxDrag_DefaultMove;
        else if (m_moveAllow)
            flags |= wxDrag_AllowMove;

        LogDragResult(source.DoDragDrop(flags));
    }
#endif // wxUSE_DRAG_AND_DROP
}

void DnDFrame::OnRightDown(wxMouseEvent &event) {
    wxMenu menu("Dnd sample menu");

    menu.Append(Menu_Drag, "&Test drag...");
    menu.AppendSeparator();
    menu.Append(Menu_About, "&About");

    PopupMenu(&menu, event.GetX(), event.GetY());
}

DnDFrame::~DnDFrame() {
#if wxUSE_LOG
    if (m_pLog != nullptr) {
        if (wxLog::SetActiveTarget(m_pLogPrev) == m_pLog)
            delete m_pLog;
    }
#endif // wxUSE_LOG
}

void DnDFrame::OnUsePrimary(wxCommandEvent &event) {
    const bool usePrimary = event.IsChecked();
    wxTheClipboard->UsePrimarySelection(usePrimary);

    wxLogStatus("Now using %s selection", usePrimary ? "primary"
                                                     : "clipboard");
}

#if wxUSE_DRAG_AND_DROP

void DnDFrame::OnBeginDrag(wxTreeEvent &event) {
    wxFileDataObject data;
    data.AddFile(m_ctrlDir->GetPath(event.GetItem()));

    wxDropSource dragSource(this);
    dragSource.SetData(data);

    LogDragResult(dragSource.DoDragDrop());
}

#endif // wxUSE_DRAG_AND_DROP

// ---------------------------------------------------------------------------
// bitmap clipboard
// ---------------------------------------------------------------------------

void DnDFrame::OnCopyBitmap(wxCommandEvent & WXUNUSED(event)) {
    // PNG support is not always compiled in under Windows, so use BMP there
#if wxUSE_LIBPNG
    wxFileDialog dialog(this, "Open a PNG file", wxEmptyString, wxEmptyString, "PNG files (*.png)|*.png", 0);
#else
    wxFileDialog dialog(this, "Open a BMP file", wxEmptyString, wxEmptyString, "BMP files (*.bmp)|*.bmp", 0);
#endif

    if (dialog.ShowModal() != wxID_OK) {
        wxLogMessage("Aborted file open");
        return;
    }

    if (dialog.GetPath().empty()) {
        wxLogMessage("Returned empty string.");
        return;
    }

    if (!wxFileExists(dialog.GetPath())) {
        wxLogMessage("File doesn't exist.");
        return;
    }

    wxImage image;
    image.LoadFile(dialog.GetPath(),
#if wxUSE_LIBPNG
                   wxBITMAP_TYPE_PNG
#else
            wxBITMAP_TYPE_BMP
#endif
    );
    if (!image.IsOk()) {
        wxLogError("Invalid image file...");
        return;
    }

    wxLogStatus("Decoding image file...");
    wxYield();

    wxBitmap bitmap(image);

    if (!wxTheClipboard->Open()) {
        wxLogError("Can't open clipboard.");

        return;
    }

    wxLogMessage("Creating wxBitmapDataObject...");
    wxYield();

    if (!wxTheClipboard->AddData(new wxBitmapDataObject(bitmap))) {
        wxLogError("Can't copy image to the clipboard.");
    } else {
        wxLogMessage("Image has been put on the clipboard.");
        wxLogMessage("You can paste it now and look at it.");
    }

    wxTheClipboard->Close();
}

void DnDFrame::OnPasteBitmap(wxCommandEvent & WXUNUSED(event)) {
    if (!wxTheClipboard->Open()) {
        wxLogError("Can't open clipboard.");

        return;
    }

    if (!wxTheClipboard->IsSupported(wxDF_BITMAP)) {
        wxLogWarning("No bitmap on clipboard");

        wxTheClipboard->Close();
        return;
    }

    wxBitmapDataObject data;
    if (!wxTheClipboard->GetData(data)) {
        wxLogError("Can't paste bitmap from the clipboard");
    } else {
        const wxBitmap &bmp = data.GetBitmap();

        wxLogMessage("Bitmap %dx%d pasted from the clipboard",
                     bmp.GetWidth(), bmp.GetHeight());
        ShowBitmap(bmp);
    }

    wxTheClipboard->Close();
}

#if wxUSE_METAFILE

void DnDFrame::OnPasteMetafile(wxCommandEvent & WXUNUSED(event)) {
    if (!wxTheClipboard->Open()) {
        wxLogError("Can't open clipboard.");

        return;
    }

    if (!wxTheClipboard->IsSupported(wxDF_METAFILE)) {
        wxLogWarning("No metafile on clipboard");
    } else {
        wxMetaFileDataObject data;
        if (!wxTheClipboard->GetData(data)) {
            wxLogError("Can't paste metafile from the clipboard");
        } else {
            const wxMetaFile &mf = data.GetMetafile();

            wxLogMessage("Metafile %dx%d pasted from the clipboard",
                         mf.GetWidth(), mf.GetHeight());

            ShowMetaFile(mf);
        }
    }

    wxTheClipboard->Close();
}

#endif // wxUSE_METAFILE

// ----------------------------------------------------------------------------
// file clipboard
// ----------------------------------------------------------------------------

void DnDFrame::OnCopyFiles(wxCommandEvent & WXUNUSED(event)) {
#ifdef __WXMSW__
    wxFileDialog dialog(this, "Select a file to copy", wxEmptyString, wxEmptyString,
                         "All files (*.*)|*.*", 0);

    wxArrayString filenames;
    while ( dialog.ShowModal() == wxID_OK )
    {
        filenames.Add(dialog.GetPath());
    }

    if ( !filenames.IsEmpty() )
    {
        wxFileDataObject *dobj = new wxFileDataObject;
        size_t count = filenames.GetCount();
        for ( size_t n = 0; n < count; n++ )
        {
            dobj->AddFile(filenames[n]);
        }

        wxClipboardLocker locker;
        if ( !locker )
        {
            wxLogError("Can't open clipboard");
        }
        else
        {
            if ( !wxTheClipboard->AddData(dobj) )
            {
                wxLogError("Can't copy file(s) to the clipboard");
            }
            else
            {
                wxLogStatus(this, "%d file%s copied to the clipboard",
                            count, count == 1 ? wxEmptyString : wxEmptyString);
            }
        }
    }
    else
    {
        wxLogStatus(this, "Aborted");
    }
#else // !MSW
    wxLogError("Sorry, not implemented");
#endif // MSW/!MSW
}

void DnDFrame::OnCopyURL(wxCommandEvent & WXUNUSED(event)) {
    // Just hard code it for now, we could ask the user but the point here is
    // to test copying URLs, it doesn't really matter what it is.
    const wxString url("http://www.wxwidgets.org/");

    wxClipboardLocker locker;
    if (!!locker && wxTheClipboard->AddData(new wxURLDataObject(url))) {
        wxLogStatus(this, "Copied URL \"%s\" to %s.",
                    url,
                    "clipboard");
    } else {
        wxLogError("Failed to copy URL.");
    }
}

// ---------------------------------------------------------------------------
// text clipboard
// ---------------------------------------------------------------------------

void DnDFrame::OnCopy(wxCommandEvent & WXUNUSED(event)) {
    if (!wxTheClipboard->Open()) {
        wxLogError("Can't open clipboard.");

        return;
    }

    if (!wxTheClipboard->AddData(new wxTextDataObject(m_strText))) {
        wxLogError("Can't copy data to the clipboard");
    } else {
        wxLogMessage("Text '%s' put on the clipboard", m_strText);
    }

    wxTheClipboard->Close();
}

void DnDFrame::OnPaste(wxCommandEvent & WXUNUSED(event)) {
    if (!wxTheClipboard->Open()) {
        wxLogError("Can't open clipboard.");

        return;
    }

    if (!wxTheClipboard->IsSupported(wxDF_TEXT)) {
        wxLogWarning("No text data on clipboard");

        wxTheClipboard->Close();
        return;
    }

    wxTextDataObject text;
    if (!wxTheClipboard->GetData(text)) {
        wxLogError("Can't paste data from the clipboard");
    } else {
        wxLogMessage("Text '%s' pasted from the clipboard",
                     text.GetText());
    }

    wxTheClipboard->Close();
}

static void ShowBitmap(const wxBitmap &bitmap) {
    wxFrame *frame = new wxFrame(nullptr, wxID_ANY, "Bitmap view");
#if wxUSE_STATUSBAR
    frame->CreateStatusBar();
#endif // wxUSE_STATUSBAR
    DnDCanvasBitmap *canvas = new DnDCanvasBitmap(frame);
    canvas->SetBitmap(bitmap);

    int w = bitmap.GetWidth(),
            h = bitmap.GetHeight();
#if wxUSE_STATUSBAR
    frame->SetStatusText(wxString::Format("%dx%d", w, h));
#endif // wxUSE_STATUSBAR

    frame->SetClientSize(w > 100 ? 100 : w, h > 100 ? 100 : h);
    frame->Show(true);
}

static void ShowMetaFile(const wxMetaFile &metafile) {
    wxFrame *frame = new wxFrame(nullptr, wxID_ANY, "Metafile view");
    frame->CreateStatusBar();
    DnDCanvasMetafile *canvas = new DnDCanvasMetafile(frame);
    canvas->SetMetafile(metafile);

    wxSize size = metafile.GetSize();
    frame->SetStatusText(wxString::Format("%dx%d", size.x, size.y));

    frame->SetClientSize(size.x > 100 ? 100 : size.x,
                         size.y > 100 ? 100 : size.y);
    frame->Show();
}
