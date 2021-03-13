using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CapturePreviewCSharp
{
    public partial class Form1 : Form
    {
        private GraphicsCaptureBridge.Capture capture = null; // この行を追加

        public Form1()
        {
            InitializeComponent();
        }

        private async void button1_Click(object sender, EventArgs e)
        {
            await capture.StartCaptureForPickedWindowAsync().AsTask();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // コンストラクタの段階ではウィンドウハンドルが生成されていないのでダメ
            capture = new GraphicsCaptureBridge.Capture(pictureBox1.Handle.ToInt64());
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            capture?.StopCapture();
        }

        private void pictureBox1_Resize(object sender, EventArgs e)
        {
            capture?.Resize();
        }
    }
}
