using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace Homework1
{
    public class MainForm : Form
    {
        private List<Label> statics = new List<Label>();
        private Point startPoint;
        private bool isDrawing = false;
        
        public MainForm()
        {
            this.Text = "Создание статиков";
            this.ClientSize = new Size(600, 400);
            
            this.MouseDown += MainForm_MouseDown;
            this.MouseUp += MainForm_MouseUp;
            this.MouseMove += MainForm_MouseMove;
        }
        
        private void MainForm_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                startPoint = e.Location;
                isDrawing = true;
            }
            else if (e.Button == MouseButtons.Right)
            {
                // Поиск статика с наибольшим номером в точке клика
                Label foundStatic = null;
                for (int i = statics.Count - 1; i >= 0; i--)
                {
                    if (statics[i].Bounds.Contains(e.Location))
                    {
                        foundStatic = statics[i];
                        break;
                    }
                }
                
                if (foundStatic != null)
                {
                    int area = foundStatic.Width * foundStatic.Height;
                    this.Text = $"Площадь: {area}, X: {foundStatic.Left}, Y: {foundStatic.Top}";
                }
            }
        }
        
        private void MainForm_MouseUp(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left && isDrawing)
            {
                isDrawing = false;
                
                int width = Math.Abs(e.X - startPoint.X);
                int height = Math.Abs(e.Y - startPoint.Y);
                
                if (width < 10 || height < 10)
                {
                    MessageBox.Show("Минимальный размер статика 10x10!");
                    return;
                }
                
                int x = Math.Min(startPoint.X, e.X);
                int y = Math.Min(startPoint.Y, e.Y);
                
                Label newStatic = new Label();
                newStatic.Text = (statics.Count + 1).ToString();
                newStatic.BorderStyle = BorderStyle.FixedSingle;
                newStatic.BackColor = Color.LightBlue;
                newStatic.Location = new Point(x, y);
                newStatic.Size = new Size(width, height);
                
                // Обработчик двойного клика
                newStatic.MouseDoubleClick += (s, args) => 
                {
                    if (args.Button == MouseButtons.Left)
                    {
                        // Удаляем статик с наименьшим номером
                        for (int i = 0; i < statics.Count; i++)
                        {
                            if (statics[i].Bounds.Contains(e.Location))
                            {
                                this.Controls.Remove(statics[i]);
                                statics.RemoveAt(i);
                                break;
                            }
                        }
                    }
                };
                
                statics.Add(newStatic);
                this.Controls.Add(newStatic);
            }
        }
        
        private void MainForm_MouseMove(object sender, MouseEventArgs e)
        {
            if (isDrawing)
            {
                // Можно добавить отрисовку прямоугольника в реальном времени
            }
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
