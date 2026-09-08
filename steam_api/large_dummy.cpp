// Large function to increase .text section size
// This function is called from SteamAPI_Init to prevent optimization

extern "C" __declspec(noinline) void LargeDummyFunction() {
    // Create a large buffer on the stack
    volatile char buffer[4096];
    
    // Fill it with pattern to prevent optimization
    for (int i = 0; i < 4096; i++) {
        buffer[i] = (char)(i & 0xFF);
    }
    
    // Do some arithmetic to generate more code
    volatile int sum = 0;
    for (int i = 0; i < 1000; i++) {
        sum += i * i;
    }
    
    // Use sum to prevent optimization
    buffer[0] = (char)(sum & 0xFF);
}
