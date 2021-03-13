#pragma once

#include "Capture.g.h"

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::System;
using namespace winrt::Windows::Graphics;
using namespace winrt::Windows::Graphics::DirectX;
using namespace winrt::Windows::Graphics::DirectX::Direct3D11;
using namespace winrt::Windows::Graphics::Capture;

namespace winrt::GraphicsCaptureBridge::implementation
{
    struct Capture : CaptureT<Capture>
    {
        Capture(int64_t ownerHwnd);
        IAsyncOperation<bool> StartCaptureForPickedWindowAsync();
        void StopCapture();
        void Resize();
        bool IsCapturing() { return _framePool != nullptr; }
    private:
        HRESULT CreateDevice();
        void StartCapture(winrt::Windows::Graphics::Capture::GraphicsCaptureItem const& item);
        void OnFrameArrived(
            Direct3D11CaptureFramePool const& sender,
            winrt::Windows::Foundation::IInspectable const& args);

        HWND _ownerHwnd;

        winrt::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice _device{ nullptr };
        winrt::com_ptr<ID3D11Device> _d3dDevice;
        winrt::com_ptr<IDXGISwapChain1> _dxgiSwapChain;
        winrt::com_ptr<ID3D11RenderTargetView> _chainedBufferRTV;

        std::unique_ptr<::DirectX::SpriteBatch> _spriteBatch;

        winrt::Windows::Graphics::Capture::Direct3D11CaptureFramePool _framePool{ nullptr };
        winrt::Windows::Graphics::Capture::GraphicsCaptureItem _captureItem{ nullptr };
        winrt::Windows::Graphics::Capture::GraphicsCaptureSession _captureSession{ nullptr };
        winrt::Windows::Graphics::Capture::Direct3D11CaptureFramePool::FrameArrived_revoker _frameArrived;
    };
}

namespace winrt::GraphicsCaptureBridge::factory_implementation
{
    struct Capture : CaptureT<Capture, implementation::Capture>
    {
    };
}
