# GraphicCaptureCSharp

Sample of C# desktop application project using features of [Windows.Graphics.Capture](https://docs.microsoft.com/ja-jp/windows/uwp/audio-video-camera/screen-capture) in WinRT API through a C++/WinRT bridge library.

## Requirements: 
* Windows 10 (1903+)
* Visual Studio 2019

## Introduction

This sample enables us to use features of Windows.Graphics.Capture in WinRT (Windows Runtime) API.
First we prepare a C++/WinRT library project calling WinRT API, and then we call this library from a C# project, since it is very complicated to call this API directly from a C# desktop application project.

Qiita (ja): https://qiita.com/everylittle/items/c80de379e644397ceabc

## Acknowledgment

Most of this code is borrowed from [previous work by opysky](https://github.com/opysky/examples/tree/master/winrt/GraphicsCapture).

Qiita (ja): https://qiita.com/eguo/items/90604787a6098af404d9
