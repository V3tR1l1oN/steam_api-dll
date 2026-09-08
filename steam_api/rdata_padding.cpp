#pragma code_seg(".rdata")
extern "C" {
    __declspec(allocate(".rdata")) const char g_rdata_padding[24576] = {0};
}
#pragma code_seg()
