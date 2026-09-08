#pragma code_seg(".text")
extern "C" {
    __declspec(allocate(".text")) const char g_text_padding[4096] = {0xCC};
}
#pragma code_seg()
