//
// Created by Dmitry Velychko on 25.06.2024.
//

#ifndef ASSETVIEWER_DNDFRAME_H
#define ASSETVIEWER_DNDFRAME_H

#include "wx/wx.h"
#include "wx/dnd.h"
#include "wx/dataobj.h"
#include "wx/image.h"
#include "wx/clipbrd.h"
#include "wx/colordlg.h"
#include "wx/metafile.h"
#include "wx/dirctrl.h"

static const char *const dnd_copy_xpm[] = {
/* width height ncolors chars_per_pixel */
        "32 32 6 1",
/* colors */
        "  s None        c None",
        ". c black",
        "X c wheat",
        "o c tan",
        "O c #6699FF",
        "r c red",
/* pixels */
        "    ...................     r   ",
        "    .XXXXXXXXXXXXXXXXX..    r   ",
        "    .XXXXXXXXXXXXXXXXX.o.rrrrrrr",
        "    .XXXXXXXXXXXXXXXXX.oo.  r   ",
        "    .XXXXXXXXXXXXXXXXX.ooo. r   ",
        "    .XXXXXXXXXXXXXXXXX.oooo.    ",
        "    .XXXXXXXXXXXXXXXXX.......   ",
        "    .XXXXXOOOOOOOOOOXXXooooo.   ",
        "    .XXXXXXXXXXXXXXXXXXooooo.   ",
        "    .XXXXXOOOOOOOOOOXXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXXOOOOOOOOOXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXOOOOOOOOOOXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXOOOOOOOOOOXXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXXOOOOOOOOOXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXOOOOOOOOOOXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXOOOOOOOOOOXXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXOOOOOOOOOOXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXOOOOOOOXXXXXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .........................   "};

static const char *const dnd_move_xpm[] = {
/* width height ncolors chars_per_pixel */
        "32 32 5 1",
/* colors */
        "  s None        c None",
        ". c black",
        "X c wheat",
        "o c tan",
        "O c #6699FF",
/* pixels */
        "    ...................         ",
        "    .XXXXXXXXXXXXXXXXX..        ",
        "    .XXXXXXXXXXXXXXXXX.o.       ",
        "    .XXXXXXXXXXXXXXXXX.oo.      ",
        "    .XXXXXXXXXXXXXXXXX.ooo.     ",
        "    .XXXXXXXXXXXXXXXXX.oooo.    ",
        "    .XXXXXXXXXXXXXXXXX.......   ",
        "    .XXXXXOOOOOOOOOOXXXooooo.   ",
        "    .XXXXXXXXXXXXXXXXXXooooo.   ",
        "    .XXXXXOOOOOOOOOOXXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXXOOOOOOOOOXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXOOOOOOOOOOXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXOOOOOOOOOOXXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXXOOOOOOOOOXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXOOOOOOOOOOXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXOOOOOOOOOOXXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXOOOOOOOOOOXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXOOOOOOOXXXXXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .........................   "};

static const char *const dnd_none_xpm[] = {
/* width height ncolors chars_per_pixel */
        "32 32 6 1",
/* colors */
        "  s None        c None",
        ". c black",
        "X c wheat",
        "o c tan",
        "O c #6699FF",
        "r c red",
/* pixels */
        "    ...................         ",
        "    .XXXXXXXXXXXXXXXXX..        ",
        "    .XXXXXXXXXXXXXXXXX.o.       ",
        "    .XXXXXXXXXXXXXXXXX.oo.      ",
        "    .XXXXXXXXXXXXXXXXX.ooo.     ",
        "    .XXXXXXXXXXXXXXXXX.oooo.    ",
        "    .XXXXXXXXXXXXXXXXX.......   ",
        "    .rXXXXOOOOOOOOOOXXXoooor.   ",
        "    .XrXXXXXXXXXXXXXXXXoooro.   ",
        "    .XXrXXOOOOOOOOOOXXXXXrXX.   ",
        "    .XXXrXXXXXXXXXXXXXXXrXXX.   ",
        "    .XXXXrXXOOOOOOOOOXXrXXXX.   ",
        "    .XXXXXrXXXXXXXXXXXrXXXXX.   ",
        "    .XXXXXXrOOOOOOOOOrXXXXXX.   ",
        "    .XXXXXXXrXXXXXXXrXXXXXXX.   ",
        "    .XXXXXOOOrOOOOOrXXXXXXXX.   ",
        "    .XXXXXXXXXrXXXrXXXXXXXXX.   ",
        "    .XXXXXXXOOOrOrOOOXXXXXXX.   ",
        "    .XXXXXXXXXXXrXXXXXXXXXXX.   ",
        "    .XXXXXXOOOOrOrOOOXXXXXXX.   ",
        "    .XXXXXXXXXrXXXrXXXXXXXXX.   ",
        "    .XXXXXOOOrOOOOOrXXXXXXXX.   ",
        "    .XXXXXXXrXXXXXXXrXXXXXXX.   ",
        "    .XXXXXXrOOOOOOOOOrXXXXXX.   ",
        "    .XXXXXrXXXXXXXXXXXrXXXXX.   ",
        "    .XXXXrOOOOOOOXXXXXXrXXXX.   ",
        "    .XXXrXXXXXXXXXXXXXXXrXXX.   ",
        "    .XXrXXXXXXXXXXXXXXXXXrXX.   ",
        "    .XrXXXXXXXXXXXXXXXXXXXrX.   ",
        "    .rXXXXXXXXXXXXXXXXXXXXXr.   ",
        "    .XXXXXXXXXXXXXXXXXXXXXXX.   ",
        "    .........................   "};


enum {
    Menu_Quit = 1,
    Menu_Drag,
    Menu_DragMoveDef,
    Menu_DragMoveAllow,
    Menu_NewFrame,
    Menu_About = 101,
    Menu_Help,
    Menu_Clear,
    Menu_Copy,
    Menu_Paste,
    Menu_CopyBitmap,
    Menu_PasteBitmap,
    Menu_PasteMFile,
    Menu_CopyFiles,
    Menu_CopyURL,
    Menu_UsePrimary,
    Menu_Shape_New = 500,
    Menu_Shape_Edit,
    Menu_Shape_Clear,
    Menu_ShapeClipboard_Copy,
    Menu_ShapeClipboard_Paste,
    Button_Colour = 1001
};


class DnDText : public wxTextDropTarget {
public:
    DnDText(wxListBox *pOwner) { m_pOwner = pOwner; }

    virtual bool OnDropText(wxCoord x, wxCoord y, const wxString &text) override;

private:
    wxListBox *m_pOwner;
};

class DnDFile : public wxFileDropTarget {
public:
    DnDFile(wxListBox *pOwner = nullptr) { m_pOwner = pOwner; }

    virtual bool OnDropFiles(wxCoord x, wxCoord y,
                             const wxArrayString &filenames) override;

private:
    wxListBox *m_pOwner;
};

class URLDropTarget : public wxDropTarget {
public:
    URLDropTarget() { SetDataObject(new wxURLDataObject); }

    void OnDropURL(wxCoord WXUNUSED(x), wxCoord WXUNUSED(y), const wxString &text) {
        // of course, a real program would do something more useful here...
        wxMessageBox(text, "wxDnD sample: got URL",
                     wxICON_INFORMATION | wxOK);
    }

    // URLs can't be moved, only copied
    virtual wxDragResult OnDragOver(wxCoord WXUNUSED(x), wxCoord WXUNUSED(y),
                                    wxDragResult WXUNUSED(def)) override {
        return wxDragLink;  // At least IE 5.x needs wxDragLink, the
        // other browsers on MSW seem okay with it too.
    }

    // translate this to calls to OnDropURL() just for convenience
    virtual wxDragResult OnData(wxCoord x, wxCoord y, wxDragResult def) override {
        if (!GetData())
            return wxDragNone;

        OnDropURL(x, y, ((wxURLDataObject *) m_dataObject)->GetURL());

        return def;
    }
};

class DnDCanvasBitmap : public wxScrolledWindow {
public:
    DnDCanvasBitmap(wxWindow *parent) : wxScrolledWindow(parent) {}

    void SetBitmap(const wxBitmap &bitmap) {
        m_bitmap = bitmap;

        SetScrollbars(10, 10,
                      m_bitmap.GetWidth() / 10, m_bitmap.GetHeight() / 10);

        Refresh();
    }

    void OnPaint(wxPaintEvent & WXUNUSED(event)) {
        wxPaintDC dc(this);

        if (m_bitmap.IsOk()) {
            PrepareDC(dc);

            dc.DrawBitmap(m_bitmap, 0, 0);
        }
    }

private:
    wxBitmap m_bitmap;

wxDECLARE_EVENT_TABLE();
};

class DnDCanvasMetafile : public wxScrolledWindow {
public:
    DnDCanvasMetafile(wxWindow *parent) : wxScrolledWindow(parent) {}

    void SetMetafile(const wxMetafile &metafile) {
        m_metafile = metafile;

        SetScrollbars(10, 10,
                      m_metafile.GetWidth() / 10, m_metafile.GetHeight() / 10);

        Refresh();
    }

    void OnPaint(wxPaintEvent &) {
        wxPaintDC dc(this);

        if (m_metafile.IsOk()) {
            PrepareDC(dc);

            m_metafile.Play(&dc);
        }
    }

private:
    wxMetafile m_metafile;

wxDECLARE_EVENT_TABLE();
};

class DnDFrame : public wxFrame {
public:
    DnDFrame(wxWindow *parent);

    virtual ~DnDFrame();

    void OnPaint(wxPaintEvent &event);

    void OnSize(wxSizeEvent &event);

    void OnQuit(wxCommandEvent &event);

    void OnAbout(wxCommandEvent &event);

    void OnDrag(wxCommandEvent &event);

    void OnDragMoveByDefault(wxCommandEvent &event);

    void OnDragMoveAllow(wxCommandEvent &event);

    void OnNewFrame(wxCommandEvent &event);

    void OnHelp(wxCommandEvent &event);

#if wxUSE_LOG

    void OnLogClear(wxCommandEvent &event);

#endif // wxUSE_LOG

    void OnCopy(wxCommandEvent &event);

    void OnPaste(wxCommandEvent &event);

    void OnCopyBitmap(wxCommandEvent &event);

    void OnPasteBitmap(wxCommandEvent &event);

#if wxUSE_METAFILE

    void OnPasteMetafile(wxCommandEvent &event);

#endif // wxUSE_METAFILE

    void OnCopyFiles(wxCommandEvent &event);

    void OnCopyURL(wxCommandEvent &event);

    void OnUsePrimary(wxCommandEvent &event);

    void OnLeftDown(wxMouseEvent &event);

    void OnRightDown(wxMouseEvent &event);

#if wxUSE_DRAG_AND_DROP

    void OnBeginDrag(wxTreeEvent &event);

#endif // wxUSE_DRAG_AND_DROP

    void OnUpdateUIMoveByDefault(wxUpdateUIEvent &event);

    void OnUpdateUIPasteText(wxUpdateUIEvent &event);

    void OnUpdateUIPasteBitmap(wxUpdateUIEvent &event);

private:
#if wxUSE_DRAG_AND_DROP

    // show the result of a dnd operation in the status bar
    void LogDragResult(wxDragResult result);

#endif // wxUSE_DRAG_AND_DROP

    // GUI controls
    wxListBox *m_ctrlFile;
    wxListBox *m_ctrlText;
    wxGenericDirCtrl *m_ctrlDir;

#if wxUSE_LOG
    wxTextCtrl *m_ctrlLog;

    wxLog *m_pLog,
            *m_pLogPrev;
#endif // wxUSE_LOG

    // move the text by default (or copy)?
    bool m_moveByDefault;

    // allow moving the text at all?
    bool m_moveAllow;

    // the text we drag
    wxString m_strText;


    wxDECLARE_EVENT_TABLE();
};

static void ShowBitmap(const wxBitmap &bitmap);

static void ShowMetaFile(const wxMetaFile &metafile);


#endif //ASSETVIEWER_DNDFRAME_H
