#include "winfo.h"
#include <Windows.h>

RECT winfo::Rect()
{
	HWND hwnd = GetForegroundWindow();
	RECT rect;
	GetWindowRect(hwnd, &rect);
	return rect;
}

std::string winfo::Title()
{
	char wnd_title[256];
	HWND hwnd = GetForegroundWindow(); // get handle of currently active window
	GetWindowText(hwnd, wnd_title, sizeof(wnd_title));
	return wnd_title;
}

int winfo::PID()
{
	return 0;
}

Napi::String winfo::TitleWrapped(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();
	Napi::String returnValue = Napi::String::New(env, winfo::Title());

	return returnValue;
}

Napi::Number winfo::TopWrapped(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();
	Napi::Number returnValue = Napi::Number::New(env, winfo::Rect().top);

	return returnValue;
}

Napi::Number winfo::LeftWrapped(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();
	Napi::Number returnValue = Napi::Number::New(env, winfo::Rect().left);

	return returnValue;
}

Napi::Number winfo::HeightWrapped(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();
	Napi::Number returnValue = Napi::Number::New(env, (winfo::Rect().bottom - winfo::Rect().top));

	return returnValue;
}

Napi::Number winfo::WidthWrapped(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();
	Napi::Number returnValue = Napi::Number::New(env, (winfo::Rect().right - winfo::Rect().left));

	return returnValue;
}

Napi::Number winfo::PIDWrapped(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();
	Napi::Number returnValue = Napi::Number::New(env, winfo::PID());

	return returnValue;
}

Napi::Object winfo::Init(Napi::Env env, Napi::Object exports)
{
	exports.Set(
		"y", Napi::Function::New(env, winfo::TopWrapped));
	exports.Set(
		"x", Napi::Function::New(env, winfo::LeftWrapped));
	exports.Set(
		"height", Napi::Function::New(env, winfo::HeightWrapped));
	exports.Set(
		"width", Napi::Function::New(env, winfo::WidthWrapped));
	exports.Set(
		"title", Napi::Function::New(env, winfo::TitleWrapped));
	exports.Set(
		"id", Napi::Function::New(env, winfo::PIDWrapped));

	return exports;
}