/* cppsrc/main.cpp */
#include <napi.h>
#include "winfo.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    return winfo::Init(env, exports);
}

NODE_API_MODULE(testaddon, InitAll)