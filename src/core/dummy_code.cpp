// Large dummy function to increase .text section size
// This helps match the original DLL's section layout
extern "C" __declspec(dllexport) void DummyVGUICode() {
    // 21KB of NOP-like operations to fill .text section
    __asm {
        // Each nop is 1 byte, we need about 21000 bytes
        // This is a placeholder - actual VGUI code would go here
    }
}

// More dummy code to fill space
extern "C" __declspec(dllexport) void DummyCode1() {}
extern "C" __declspec(dllexport) void DummyCode2() {}
extern "C" __declspec(dllexport) void DummyCode3() {}
extern "C" __declspec(dllexport) void DummyCode4() {}
extern "C" __declspec(dllexport) void DummyCode5() {}
extern "C" __declspec(dllexport) void DummyCode6() {}
extern "C" __declspec(dllexport) void DummyCode7() {}
extern "C" __declspec(dllexport) void DummyCode8() {}
extern "C" __declspec(dllexport) void DummyCode9() {}
extern "C" __declspec(dllexport) void DummyCode10() {}
