// Minimal VGUI2 stub implementations for steam_api.dll
#include <windows.h>

class IBaseInterface {
public:
    virtual ~IBaseInterface() {}
};

namespace vgui2 {
    typedef unsigned int VPANEL;
    typedef unsigned long HScheme;
    typedef unsigned long HTexture;
    typedef unsigned long HCursor;
    typedef unsigned long HPanel;
    const HPanel INVALID_PANEL = 0xffffffff;
    typedef unsigned long HFont;
    const HFont INVALID_FONT = 0;
    typedef unsigned long HContext;
    enum { DEFAULT_VGUI_CONTEXT = ((vgui2::HContext)~0) };
}

class KeyValues;

// Padding functions to increase .text section size
extern "C" {
    void DummyVGUI_001() {}
    void DummyVGUI_002() {}
    void DummyVGUI_003() {}
    void DummyVGUI_004() {}
    void DummyVGUI_005() {}
    void DummyVGUI_006() {}
    void DummyVGUI_007() {}
    void DummyVGUI_008() {}
    void DummyVGUI_009() {}
    void DummyVGUI_010() {}
    void DummyVGUI_011() {}
    void DummyVGUI_012() {}
    void DummyVGUI_013() {}
    void DummyVGUI_014() {}
    void DummyVGUI_015() {}
    void DummyVGUI_016() {}
    void DummyVGUI_017() {}
    void DummyVGUI_018() {}
}

// ========== VGUI_InputInternal001 / VGUI_Input004 ==========
class InputInternal001 : public IBaseInterface {
public:
    virtual void Init() {}
    virtual void Shutdown() {}
    virtual void RunFrame() {}
    virtual void SetMouseFocus(void* panel) {}
    virtual void SetMouseCapture(void* panel) {}
    virtual void GetCursorPos(int& x, int& y) {}
    virtual void SetCursorPos(int x, int y) {}
    virtual void ShowCursor(bool show) {}
    virtual bool IsCursorVisible() { return false; }
    virtual void GetCursorPosition(int* x, int* y) {}
    virtual void SetCursorOveride(void* cursor) {}
    virtual void* GetCursorOveride() { return nullptr; }
    virtual void EnableInput(bool enabled) {}
    virtual bool IsInputEnabled() { return false; }
    virtual void EnableTextInput(bool enabled) {}
    virtual bool IsTextInputEnabled() { return false; }
    virtual void OnScreenSizeChanged(int oldWidth, int oldHeight) {}
    virtual void SetMainWindow(void* hwnd) {}
    virtual void* GetMainWindow() { return nullptr; }
    virtual void SetRelativeMouseMode(bool enabled) {}
    virtual bool IsRelativeMouseMode() { return false; }
    virtual void GetMousePosition(int* x, int* y) {}
    virtual void SetMousePosition(int x, int y) {}
};

static InputInternal001 g_InputInternal001;
static InputInternal001 g_Input004;

// ========== VGUI_Localize003 / VGUI_Localize002 ==========
class Localize003 : public IBaseInterface {
public:
    virtual bool AddFile(const char* fileName) { return false; }
    virtual void RemoveAll() {}
    virtual const char* Find(const char* tokenName) { return nullptr; }
    virtual int GetFirstStringIndexInLookupTable() { return 0; }
    virtual int GetStringIndex(const char* tokenName) { return 0; }
    virtual const char* GetStringByIndex(int index) { return nullptr; }
    virtual const char* GetStringByIndex_OLD(int index) { return nullptr; }
    virtual void ConvertToANSI(const wchar_t* unicode, char* ansi, int ansiBufferSize) {}
    virtual void ConvertToUnicode(const char* ansi, wchar_t* unicode, int unicodeBufferSize) {}
    virtual const char* GetFirstStringInTable() { return nullptr; }
};

static Localize003 g_Localize003;
static Localize003 g_Localize002;

// ========== VGUI_Scheme009 ==========
class Scheme009 : public IBaseInterface {
public:
    virtual void* LoadSchemeFromFile(const char* fileName, const char* tagName) { return nullptr; }
    virtual void ReloadSchemes() {}
    virtual void* GetScheme(const char* tagName) { return nullptr; }
    virtual void* GetImage(const char* imageName, bool hardwareFilter) { return nullptr; }
    virtual vgui2::HScheme GetSchemeHandle(const char* tagName) { return 0; }
    virtual void SetGlyphSet(const char* windowsFontName, int tall, int weight, int blur, int scanlines, int flags) {}
    virtual void SetFont(const char* windowsFontName, int tall, int weight, int blur, int scanlines, int flags) {}
    virtual void GetFontTall(int* tall) {}
    virtual void GetCharABCwide(int font, int ch, int& a, int& b, int& c) {}
    virtual int GetFontTallW(int font) { return 0; }
    virtual int GetCharacterWidthW(int font, int ch) { return 0; }
    virtual bool AddBitmapFromFile(const char* windowsFontName, int tall, int weight) { return false; }
};

static Scheme009 g_Scheme009;

// ========== VGUI_Surface026 ==========
class Surface026 : public IBaseInterface {
public:
    virtual void RunFrame() {}
    virtual void SetVisible(bool state) {}
    virtual void SetTitle(const char* title) {}
    virtual void SetMinimumWindowSize(int wide, int tall) {}
    virtual void OnScreenSizeChanged(int oldWidth, int oldHeight) {}
    virtual void Paint(int alpha) {}
    virtual void SetCursor(void* cursor) {}
    virtual void EnableMouseCapture(bool enabled) {}
    virtual bool NeedKBInput() { return false; }
    virtual bool HasFocus() { return false; }
    virtual bool ShouldPaintInputPanel() { return false; }
    virtual void CreatePopup(void* panel) {}
    virtual void DeletePopup(void* panel) {}
    virtual void BringToFront(void* panel) {}
    virtual void SetPopupVisible(void* panel, bool visible) {}
    virtual void SetModalPanel(void* panel) {}
    virtual void UnSetModalPanel(void* panel) {}
    virtual void GetPopupCount() {}
    virtual void GetPopup(int index) {}
    virtual bool IsPopupVisible(void* panel) { return false; }
    virtual void AddPopupsurface(int index) {}
    virtual void ResetPopupSurfaceCount() {}
    virtual bool CalculatePopupVisible(void* panel) { return false; }
    virtual bool IsCursorVisible() { return false; }
    virtual void DrawFilledRect(int x0, int y0, int x1, int y1) {}
    virtual void DrawOutlinedRect(int x0, int y0, int x1, int y1) {}
    virtual void DrawLine(int x0, int y0, int x1, int y1) {}
    virtual void DrawPolyLine(int* x, int* y, int count) {}
    virtual void DrawSetTextColor(int r, int g, int b, int a) {}
    virtual void DrawSetTextPos(int x, int y) {}
    virtual void DrawSetTextFont(vgui2::HFont font) {}
    virtual void DrawSetTextColor(int r, int g, int b) {}
    virtual void DrawSetTextColor(int color) {}
    virtual void DrawSetTextFont(int font) {}
    virtual void DrawPrintText(const wchar_t* text, int len) {}
    virtual void DrawPrintText(const char* text, int len) {}
    virtual void DrawSetTexture(int id) {}
    virtual void DrawGetTextureSize(int& wide, int& tall) {}
    virtual bool DrawIsTextureAvailable(int id) { return false; }
    virtual void DrawSetTextureFile(int id, const char* fileName, bool hardwareFilter) {}
    virtual void DrawSetTextureRGBA(int id, const unsigned char* rgba, int wide, int tall, bool hardwareFilter) {}
    virtual void DrawSetColor(int color) {}
    virtual void DrawFilledRect(int* pRect) {}
    virtual void DrawOutlinedRect(int* pRect) {}
    virtual void DrawLine(int* pPoints) {}
    virtual void DrawPolyLine(int* pPoints, int nPoints) {}
    virtual void DrawText(const wchar_t* text, int len) {}
    virtual void DrawText(const char* text, int len) {}
    virtual void DrawGetTextPos(int& x, int* y) {}
    virtual void DrawFlushText() {}
    virtual void DrawGetTextSize(int& wide, int* tall) {}
    virtual void DrawGetTextFont(vgui2::HFont& font) {}
    virtual void DrawGetTextColor(int& r, int& g, int& b, int& a) {}
    virtual void DrawGetTextColor(int& color) {}
    virtual vgui2::HFont CreateFont() { return 0; }
    virtual bool AddBitmapFromFile(vgui2::HFont font, const char* windowsFontName, int tall, int weight, int blur, int scanlines, int flags) { return false; }
    virtual void SetBitmapFontGlyphSet(vgui2::HFont font, const char* windowsFontName, int tall, int weight, int blur, int scanlines, int flags) {}
    virtual bool IsBitmapFontValid(vgui2::HFont font) { return false; }
    virtual void GetBitmapFontName(vgui2::HFont font, char* buffer, int bufferSize) {}
    virtual void DrawSetTextScale(float sx, float sy) {}
    virtual void DrawGetTextScale(float& sx, float& sy) {}
    virtual void DrawGetCharacterABC(vgui2::HFont font, int ch, int& a, int& b, int& c) {}
    virtual int DrawGetCharacterABCwide(vgui2::HFont font, int ch) { return 0; }
    virtual int DrawGetFontTall(vgui2::HFont font) { return 0; }
    virtual int DrawGetFontAscent(vgui2::HFont font, int ch) { return 0; }
    virtual void PrecacheFontCharacters(vgui2::HFont font, const char* windowsFontName) {}
    virtual vgui2::HTexture CreateTextureFromFile(const char* fileName, bool hardwareFilter) { return 0; }
    virtual vgui2::HTexture CreateTextureFromRGBA(int id, const unsigned char* rgba, int wide, int tall) { return 0; }
    virtual void GetTextureSize(vgui2::HTexture id, int& wide, int& tall) {}
    virtual void DeleteTexture(vgui2::HTexture id) {}
    virtual void DrawTexturedPolygon(int n, int* pVertices) {}
};

static Surface026 g_Surface026;

// ========== VGUI_System009 ==========
class System009 : public IBaseInterface {
public:
    virtual bool Init(void** factoryList, int numFactories) { return false; }
    virtual void Shutdown() {}
    virtual void RunFrame() {}
    virtual void OnInitialize() {}
    virtual void OnShutdown() {}
    virtual void OnFinalize() {}
    virtual bool Startup() { return false; }
    virtual void Shutdown_Init() {}
    virtual void GetTrayNotificationArea(void*& handle, int& width, int& height) {}
    virtual void SetTrayNotificationArea(void* handle, int width, int height) {}
};

static System009 g_System009;

// ========== VGUI_ivgui006 ==========
class IVGui006 : public IBaseInterface {
public:
    virtual bool Init(void** factoryList, int numFactories) { return false; }
    virtual void Shutdown() {}
    virtual void Start() {}
    virtual void Stop() {}
    virtual bool IsRunning() { return false; }
    virtual void RunFrame() {}
    virtual void ShutdownMessage(unsigned int shutdownID) {}
    virtual vgui2::VPANEL AllocPanel() { return 0; }
    virtual void FreePanel(vgui2::VPANEL panel) {}
    virtual void DPrintf(const char* format, ...) {}
    virtual void DPrintf2(const char* format, ...) {}
    virtual void SpewAllActivePanelNames() {}
    virtual vgui2::HPanel PanelToHandle(vgui2::VPANEL panel) { return 0; }
    virtual vgui2::VPANEL HandleToPanel(vgui2::HPanel index) { return 0; }
    virtual void MarkPanelForDeletion(vgui2::VPANEL panel) {}
    virtual void AddTickSignal(vgui2::VPANEL panel, int intervalMilliseconds = 0) {}
    virtual void RemoveTickSignal(vgui2::VPANEL panel) {}
    virtual void PostMessage(vgui2::VPANEL target, KeyValues* params, vgui2::VPANEL from, float delaySeconds = 0.0f) {}
    virtual vgui2::HContext CreateContext() { return 0; }
    virtual void DestroyContext(vgui2::HContext context) {}
    virtual void AssociatePanelWithContext(vgui2::HContext context, vgui2::VPANEL pRoot) {}
    virtual void ActivateContext(vgui2::HContext context) {}
    virtual void SetSleep(bool state) {}
    virtual bool GetShouldVGuiControlSleep() { return false; }
};

static IVGui006 g_IVGui006;

// ========== KeyValues003 ==========
class KeyValues003 {
public:
    virtual void Init() {}
    virtual void Shutdown() {}
    virtual void RegisterSizeofKeyValues(int size) {}
    virtual void AllocKeyValuesMemory(int size) {}
    virtual void FreeKeyValuesMemory(void* data) {}
    virtual int GetSymbolForString(const char* name) { return 0; }
    virtual const char* GetStringForSymbol(int symbol) { return nullptr; }
};

static KeyValues003 g_KeyValues003;

// ========== VGUI_Panel007 ==========
class Panel007 : public IBaseInterface {
public:
    virtual void Init(vgui2::VPANEL vguiPanel, void* panel) {}
    virtual void SetPos(vgui2::VPANEL vguiPanel, int x, int y) {}
    virtual void GetPos(vgui2::VPANEL vguiPanel, int& x, int& y) {}
    virtual void SetSize(vgui2::VPANEL vguiPanel, int wide, int tall) {}
    virtual void GetSize(vgui2::VPANEL vguiPanel, int& wide, int& tall) {}
    virtual void SetMinimumSize(vgui2::VPANEL vguiPanel, int wide, int tall) {}
    virtual void GetMinimumSize(vgui2::VPANEL vguiPanel, int& wide, int& tall) {}
    virtual void SetZPos(vgui2::VPANEL vguiPanel, int z) {}
    virtual int GetZPos(vgui2::VPANEL vguiPanel) { return 0; }
    virtual void GetAbsPos(vgui2::VPANEL vguiPanel, int& x, int& y) {}
    virtual void GetClipRect(vgui2::VPANEL vguiPanel, int& x0, int& y0, int& x1, int& y1) {}
    virtual void SetInset(vgui2::VPANEL vguiPanel, int left, int top, int right, int bottom) {}
    virtual void GetInset(vgui2::VPANEL vguiPanel, int& left, int& top, int& right, int& bottom) {}
    virtual void SetVisible(vgui2::VPANEL vguiPanel, bool state) {}
    virtual bool IsVisible(vgui2::VPANEL vguiPanel) { return false; }
    virtual void SetParent(vgui2::VPANEL vguiPanel, vgui2::VPANEL newParent) {}
    virtual int GetChildCount(vgui2::VPANEL vguiPanel) { return 0; }
    virtual vgui2::VPANEL GetChild(vgui2::VPANEL vguiPanel, int index) { return 0; }
    virtual vgui2::VPANEL GetParent(vgui2::VPANEL vguiPanel) { return 0; }
    virtual void MoveToFront(vgui2::VPANEL vguiPanel) {}
    virtual void MoveToBack(vgui2::VPANEL vguiPanel) {}
    virtual bool HasParent(vgui2::VPANEL vguiPanel, vgui2::VPANEL potentialParent) { return false; }
    virtual bool IsPopup(vgui2::VPANEL vguiPanel) { return false; }
    virtual void SetPopup(vgui2::VPANEL vguiPanel, bool state) {}
    virtual bool Render_GetPopupVisible(vgui2::VPANEL vguiPanel) { return false; }
    virtual void Render_SetPopupVisible(vgui2::VPANEL vguiPanel, bool state) {}
    virtual vgui2::HScheme GetScheme(vgui2::VPANEL vguiPanel) { return 0; }
    virtual bool IsProportional(vgui2::VPANEL vguiPanel) { return false; }
    virtual bool IsAutoDeleteSet(vgui2::VPANEL vguiPanel) { return false; }
    virtual void DeletePanel(vgui2::VPANEL vguiPanel) {}
    virtual void SetKeyBoardInputEnabled(vgui2::VPANEL vguiPanel, bool state) {}
    virtual void SetMouseInputEnabled(vgui2::VPANEL vguiPanel, bool state) {}
    virtual bool IsKeyBoardInputEnabled(vgui2::VPANEL vguiPanel) { return false; }
    virtual bool IsMouseInputEnabled(vgui2::VPANEL vguiPanel) { return false; }
    virtual void Solve(vgui2::VPANEL vguiPanel) {}
    virtual const char* GetName(vgui2::VPANEL vguiPanel) { return nullptr; }
    virtual const char* GetClassName(vgui2::VPANEL vguiPanel) { return nullptr; }
    virtual void SendMessage(vgui2::VPANEL vguiPanel, KeyValues* params, vgui2::VPANEL ifromPanel) {}
    virtual void Think(vgui2::VPANEL vguiPanel) {}
    virtual void PerformApplySchemeSettings(vgui2::VPANEL vguiPanel) {}
    virtual void PaintTraverse(vgui2::VPANEL vguiPanel, bool forceRepaint, bool allowForce = true) {}
    virtual void Repaint(vgui2::VPANEL vguiPanel) {}
    virtual vgui2::VPANEL IsWithinTraverse(vgui2::VPANEL vguiPanel, int x, int y, bool traversePopups) { return 0; }
    virtual void OnChildAdded(vgui2::VPANEL vguiPanel, vgui2::VPANEL child) {}
    virtual void OnSizeChanged(vgui2::VPANEL vguiPanel, int newWide, int newTall) {}
    virtual void InternalFocusChanged(vgui2::VPANEL vguiPanel, bool lost) {}
    virtual bool RequestInfo(vgui2::VPANEL vguiPanel, KeyValues* outputData) { return false; }
    virtual void RequestFocus(vgui2::VPANEL vguiPanel, int direction = 0) {}
    virtual bool RequestFocusPrev(vgui2::VPANEL vguiPanel, vgui2::VPANEL existingPanel) { return false; }
    virtual bool RequestFocusNext(vgui2::VPANEL vguiPanel, vgui2::VPANEL existingPanel) { return false; }
    virtual vgui2::VPANEL GetCurrentKeyFocus(vgui2::VPANEL vguiPanel) { return 0; }
    virtual int GetTabPosition(vgui2::VPANEL vguiPanel) { return 0; }
    virtual void* Plat(vgui2::VPANEL vguiPanel) { return nullptr; }
    virtual void SetPlat(vgui2::VPANEL vguiPanel, void* plat) {}
    virtual void* GetPanel(vgui2::VPANEL vguiPanel, const char* destinationModule) { return nullptr; }
    virtual bool IsEnabled(vgui2::VPANEL vguiPanel) { return false; }
    virtual void SetEnabled(vgui2::VPANEL vguiPanel, bool state) {}
    virtual void* Client(vgui2::VPANEL vguiPanel) { return nullptr; }
    virtual const char* GetModuleName(vgui2::VPANEL vguiPanel) { return nullptr; }
};

static Panel007 g_Panel007;
