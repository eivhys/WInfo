#include <napi.h>
#include <Windows.h>

namespace winfo
{
Napi::Object Init(Napi::Env env, Napi::Object exports);
RECT Rect();
std::string Title();
int PID();
Napi::Number PIDWrapped(const Napi::CallbackInfo &info);
Napi::String TitleWrapped(const Napi::CallbackInfo &info);
Napi::Number TopWrapped(const Napi::CallbackInfo &info);
Napi::Number HeightWrapped(const Napi::CallbackInfo &info);
Napi::Number LeftWrapped(const Napi::CallbackInfo &info);
Napi::Number WidthWrapped(const Napi::CallbackInfo &info);
} // namespace wrect