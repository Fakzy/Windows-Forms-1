using System;
using System.Drawing;
using System.Windows.Forms;

namespace Homework1
{
    public class MainForm : Form
    {
        private Rectangle rectangle;
        
        public MainForm()
        {
            this.Text = "Обработка событий мыши";
            this.ClientSize = new Size(400, 300);
            
            // Прямоугольник с отступом 10 пикселей от границ
            rectangle = new Rectangle(
                10, 10, 
                this.ClientSize.Width - 20, 
                this.ClientSize.Height - 20);
            
            // Обработчик нажатия левой кнопки мыши
            this.MouseDown += (sender, e) => 
            {
                if (e.Button == MouseButtons.Left)
                {
                    if (Control.ModifierKeys == Keys.Control)
                    {
                        this.Close();
                        return;
                    }
                    
                    if (rectangle.Contains(e.Location))
                    {
                        if (IsOnBorder(e.Location))
                        {
                            MessageBox.Show("Точка на границе прямоугольника");
                        }
                        else
                        {
                            MessageBox.Show("Точка внутри прямоугольника");
                        }
                    }
                    else
                    {
                        MessageBox.Show("Точка снаружи прямоугольника");
                    }
                }
                else if (e.Button == MouseButtons.Right)
                {
                    this.Text = $"Ширина = {this.ClientSize.Width}, Высота = {this.ClientSize.Height}";
                }
            };
            
            // Обработчик перемещения мыши
            this.MouseMove += (sender, e) => 
            {
                this.Text = $"X = {e.X}, Y = {e.Y}";
            };
        }
        
        private bool IsOnBorder(Point point)
        {
            return point.X == rectangle.Left || point.X == rectangle.Right ||
                   point.Y == rectangle.Top || point.Y == rectangle.Bottom;
        }
        
        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            e.Graphics.DrawRectangle(Pens.Black, rectangle);
        }
    }
    
    class Program
    {
        static void Main()
        {
            Application.Run(new MainForm());
        }
    }
}
